#include "BinTree.h"
#include <boost/multi_array.hpp>
#include <vector>  
#include <stdio.h>  
#include <math.h>  
#include <iostream>  
#include <string>  

using std::cout;
using std::endl;


// BinTree constructor
BinTree::BinTree(double mktPrice, double mktRate, double mktVol, double divRate,
	const Dates::XLDate& valueDate, const Dates::XLDate& expireDate, std::shared_ptr<PayOff> po, int numTimePoints,
	const Dates::DayCount& dayCount) : dayCount_{ dayCount },
	grid_(boost::extents[numTimePoints + 1][numTimePoints + 1])
{
	// Move these assignments to the variable intialization section. I've left the assignments 
	// here to show dayCount_ has to be in the variable initliztion section
	mktPrice_ = mktPrice;
	mktRate_ = mktRate;
	mktVol_ = mktVol;
	divRate_ = divRate;
	valueDate_ = valueDate;
	expireDate_ = expireDate;
	po_ = po;
	numTimePoints_ = numTimePoints;
	gridSetup_();
	paramInit_();
	projectPrices_();
	calcEurPayoffs_();
	calcAmerPayoffs_();
};

// Create the grid_ object, a Boost MultiArray with 
// the number of time points as determined at construction.
void BinTree::gridSetup_()
{
	//boost::multi_array<Node, 2> grid_;

};

// Calculate all the deterministic parameters  
// Determine delta_t, u, d, and p, a la James book
// set the private variables: dt_, u_, d_, p_
void BinTree::paramInit_()
{
	dt_ = dayCount_.yearFraction(valueDate_, expireDate_) / numTimePoints_;
	u_ = exp(mktVol_ * sqrt(dt_));
	d_ = exp(-mktVol_ * sqrt(dt_));
	p_ = (exp((mktRate_ - divRate_) * dt_) - d_) / (u_ - d_);
	discFctr_ = exp(-mktRate_ * dt_);
	double Ft = exp((mktRate_ - divRate_) * dt_);
	double p = (Ft - d_) / (u_ - d_);


	/*cout << grid_[0][0].underlying << " <<< grid_[0][0] called from paramInit_" << endl;
	cout << grid_[0][0].payoff << " <<< grid_[0][0] called from paramInit_" << endl << endl;
	cout << grid_.shape()[0] << " <<< grid_.shape()[0] called from paramInit_" << endl;
	cout << grid_.shape()[1] << " <<< grid_.shape()[0] called from paramInit_" << endl << endl;*/
};

// Generate the projected underlying asset prices and 
// and set them on each node going out on the tree.
void BinTree::projectPrices_()
{
	// Build the Tree  
	for (int j = 0; j <= numTimePoints_; j++) {
		for (int i = 0; i <= j; i++) {
			grid_[i][j].underlying = mktPrice_ * pow(u_, j - i) * pow(d_, i);
			//cout << grid_[i][j].underlying << "S[" << i << "][" << j << "]" << " << Build the tree" << endl;
		}
	}
}

void BinTree::calcEurPayoffs_()
{
	//cout << endl << "European option: Backward recursion through the tree" << endl;
	// Calculate option value for the last branch on the tree
	for (int j = numTimePoints_; j > numTimePoints_-1; j--) {
		for (int i = 0; i <= j; i++) {
			grid_[i][j].payoff = po_->operator()(grid_[i][j].underlying);
			//cout << grid_[i][j].underlying << "S[" << i << "][" << j << "]" << " << grid.underlying" << endl;
			//cout << grid_[i][j].payoff << "S[" << i << "][" << j << "]" << " << grid.payoff" << endl;
		}
	}

	for (int j = numTimePoints_-1; j >= 0; j--) {
		for (int i = 0; i <= j; i++) {
			grid_[i][j].payoff = discFctr_ * ((p_ * grid_[i][j+1].payoff) +
				((1 - p_) * grid_[i+1][j+1].payoff));
			//cout << grid_[i][j].underlying << "S[" << i << "][" << j << "]" << " << grid.underlying" << endl;
			
			//cout << grid_[i][j].payoff << "S[" << i << "][" << j << "]" << " << European: grid.payoff" << endl;
		}
	}
	cout << grid_[0][0].payoff << " << European: grid.payoff" << endl;

}

void BinTree::calcAmerPayoffs_()
{
	//cout << endl << "American option: Backward recursion through the tree" << endl;
	// Calculate option value for the last branch on the tree
	for (int j = numTimePoints_; j > numTimePoints_ - 1; j--) {
		for (int i = 0; i <= j; i++) {
			grid_[i][j].payoff = po_->operator()(grid_[i][j].underlying);
			//cout << grid_[i][j].underlying << "S[" << i << "][" << j << "]" << " << grid.underlying" << endl;
			//cout << grid_[i][j].payoff << "S[" << i << "][" << j << "]" << " << Americans: grid.payoff" << endl;
		}
	}

	for (int j = numTimePoints_ - 1; j >= 0; j--) {
		for (int i = 0; i <= j; i++) {
			double future_payoff = discFctr_ * ((p_ * grid_[i][j + 1].payoff) +
				((1 - p_) * grid_[i + 1][j + 1].payoff));
			double current_payoff = po_->operator()(grid_[i][j].underlying);
			if(current_payoff > future_payoff) {
				grid_[i][j].payoff = current_payoff;
		}
			else {
				grid_[i][j].payoff = future_payoff;
			}
			//cout << grid_[i][j].underlying << "S[" << i << "][" << j << "]" << " << grid.underlying" << endl;
			//cout << grid_[i][j].payoff << "S[" << i << "][" << j << "]" << " << American: grid.payoff" << endl;
	}
}
	cout << grid_[0][0].payoff << " << American: grid.payoff" << endl;

}