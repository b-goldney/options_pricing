#ifndef BIN_TREE_H
#define BIN_TREE_H

#include <boost/multi_array.hpp>
#include "Node.h"
#include "XlDate.h"
#include "DayCount.h"
#include "PayOff.h"
#include <memory>

class BinTree
{
public:
	BinTree(double mktPrice, double mktRate, double mktVol, double divRate,
		const Dates::XLDate& valueDate, const Dates::XLDate& expireDate, std::shared_ptr<PayOff> po, int numTimePoints,
		const Dates::DayCount& dayCount);


	// Accessors:
	double eurPrice() const;
	double amerPrice() const;
	Node operator()(int i, int j) const;

private:
	// Mkt Data:
	double mktPrice_, mktRate_, mktVol_;		// Market prices for underlying security, risk-free rate, and volatility

	// Product/Contract Data:
	double divRate_;
	Dates::XLDate valueDate_, expireDate_;
	std::shared_ptr<PayOff> po_;

	// Model Settings:
	int numTimePoints_;							// Number of time points for the tree, including the 0,0 terminal
	const Dates::DayCount& dayCount_;			// Stored as reference to handle polymorphic object

	// Calculated member variables:
	boost::multi_array<Node, 2> grid_;
	double dt_, u_, d_, p_;		// delta_t, u, d, and p parameters, a la James book
	double discFctr_;			// Discount factor (fixed for each time step, a la James)
	double eurPrice_;			// Store result as member
	double amerPrice_;			// Store result as member



	// Helper functions:
	void calcPrices_();			// This function refactors the next five into one call

	// Create the grid_ object, a Boost MultiArray with 
	// the number of time points as determined at construction.
	void gridSetup_();

	// Calculate all the deterministic parameters as 
	// described in the James book (see header file for more details).
	void paramInit_();			// Determine delta_t, u, d, and p, a la James book

	// Generate the projected underlying asset prices and 
	// and set them on each node going out on the tree.
	void projectPrices_();

	// Moving back on the tree, calculate the local payoff for each
	// node, which is the discounted expected value of payoffs 
	// in the connecting nodes to the right; when the terminal node
	// is reached, set the European price on the respective member variable,
	void calcEurPayoffs_();


	// Moving back on the tree, calculate the local payoff for each
	// node, which is the discounted expected value of payoffs 
	// in the connecting nodes to the right, but compare with the
	// actual payoff and set the optimal value for the node payoff.
	// When the terminal node is reached, set the American price on the 
	// respective member variable.
	void calcAmerPayoffs_();

};

#endif // !BIN_TREE_H