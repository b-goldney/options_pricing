#include <iostream>
#include "date.h"
#include "PayOff.h"
#include "XLDate.h"
#include "BinTree.h"

#include <boost/multi_array.hpp>

using std::cout;
using std::endl;
using std::shared_ptr;

void calls() { // Form the book example: James page 81
    // CRR parameters  
    int n = 3;                   // Number of steps  
    double Spot = 100;           // Spot Price  
    double K = 100;              // Strike Price  
    double T = 0.5;              // Years to maturity  
    double q = 0.04;             // div rate
    double r = 0.10;             // Risk Free Rate  
    double v = 0.20;             // Volatility  

    // Create start and end dates
    Dates::XLDate start_date = Dates::XLDate(2020, 01, 01);
    Dates::XLDate end_date = Dates::XLDate(2020, 06, 30);

    //Create pointer for type of call
    shared_ptr<PayOffCall> EurCall(std::make_shared<PayOffCall>(K));;
    Dates::Thirty360 const thirty360;
    //cout << act360.yearFraction(start_date, end_date) << " <<< start_date - end_date" << endl;

    BinTree james_EuropeanCallValue(Spot, r, v, q, start_date, end_date, EurCall, n, thirty360);

};

// Question 2 part a: update parameters to be more relistic 

void euroCall20() { 
    // CRR parameters  
    int n = 20;                   // Number of steps  
    double Spot = 106;           // Spot Price  
    double K = 100;              // Strike Price  
    double T = 0.5;              // Years to maturity  
    double q = 0.057;             // div rate
    double r = 0.01;             // Risk Free Rate  
    double v = 0.25;             // Volatility  

    // Create start and end dates
    Dates::XLDate start_date = Dates::XLDate(2020, 01, 01);
    Dates::XLDate end_date = Dates::XLDate(2020, 06, 30);

    //Create pointer for type of call
    shared_ptr<PayOffCall> EurCall(std::make_shared<PayOffCall>(K));;
    Dates::Thirty360 const thirty360;
    //cout << act360.yearFraction(start_date, end_date) << " <<< start_date - end_date" << endl;

    BinTree goldney_EuropeanCall20(Spot, r, v, q, start_date, end_date, EurCall, n, thirty360);
};

void euroCall21() { 
    // CRR parameters  
    int n = 21;                   // Number of steps  
    double Spot = 106;           // Spot Price  
    double K = 100;              // Strike Price  
    double T = 0.5;              // Years to maturity  
    double q = 0.057;             // div rate
    double r = 0.01;             // Risk Free Rate  
    double v = 0.25;             // Volatility  

    // Create start and end dates
    Dates::XLDate start_date = Dates::XLDate(2020, 01, 01);
    Dates::XLDate end_date = Dates::XLDate(2020, 06, 30);

    //Create pointer for type of call
    shared_ptr<PayOffCall> EurCall(std::make_shared<PayOffCall>(K));;
    Dates::Thirty360 const thirty360;
    //cout << act360.yearFraction(start_date, end_date) << " <<< start_date - end_date" << endl;

    BinTree goldney_EuropeanCall21(Spot, r, v, q, start_date, end_date, EurCall, n, thirty360);
};

void euroCall500() { 
    // CRR parameters  
    int n = 500;                   // Number of steps  
    double Spot = 106;           // Spot Price  
    double K = 100;              // Strike Price  
    double T = 0.5;              // Years to maturity  
    double q = 0.057;             // div rate
    double r = 0.01;             // Risk Free Rate  
    double v = 0.25;             // Volatility  

    // Create start and end dates
    Dates::XLDate start_date = Dates::XLDate(2020, 01, 01);
    Dates::XLDate end_date = Dates::XLDate(2020, 06, 30);

    //Create pointer for type of call
    shared_ptr<PayOffCall> EurCall(std::make_shared<PayOffCall>(K));;
    Dates::Thirty360 const thirty360;
    //cout << act360.yearFraction(start_date, end_date) << " <<< start_date - end_date" << endl;

    BinTree goldney_EuropeanCall500(Spot, r, v, q, start_date, end_date, EurCall, n, thirty360);
};

void euroCall501() { 
    // CRR parameters  
    int n = 501;                   // Number of steps  
    double Spot = 106;           // Spot Price  
    double K = 100;              // Strike Price  
    double T = 0.5;              // Years to maturity  
    double q = 0.057;             // div rate
    double r = 0.01;             // Risk Free Rate  
    double v = 0.25;             // Volatility  

    // Create start and end dates
    Dates::XLDate start_date = Dates::XLDate(2020, 01, 01);
    Dates::XLDate end_date = Dates::XLDate(2020, 06, 30);

    //Create pointer for type of call
    shared_ptr<PayOffCall> EurCall(std::make_shared<PayOffCall>(K));;
    Dates::Thirty360 const thirty360;
    //cout << act360.yearFraction(start_date, end_date) << " <<< start_date - end_date" << endl;

    BinTree goldney_EuropeanCall501(Spot, r, v, q, start_date, end_date, EurCall, n, thirty360);
};

void amerCall20() { 
    // CRR parameters  
    int n = 20;                   // Number of steps  
    double Spot = 106;           // Spot Price  
    double K = 100;              // Strike Price  
    double T = 0.5;              // Years to maturity  
    double q = 0.057;             // div rate
    double r = 0.01;             // Risk Free Rate  
    double v = 0.25;             // Volatility  

    // Create start and end dates
    Dates::XLDate start_date = Dates::XLDate(2020, 01, 01);
    Dates::XLDate end_date = Dates::XLDate(2020, 06, 30);

    //Create pointer for type of call
    shared_ptr<PayOffCall> AmerCall(std::make_shared<PayOffCall>(K));;
    Dates::Thirty360 const thirty360;
    //cout << act360.yearFraction(start_date, end_date) << " <<< start_date - end_date" << endl;

    BinTree goldney_American20(Spot, r, v, q, start_date, end_date, AmerCall, n, thirty360);
};

void amerCall21() {
    // CRR parameters  
    int n = 21;                   // Number of steps  
    double Spot = 106;           // Spot Price  
    double K = 100;              // Strike Price  
    double T = 0.5;              // Years to maturity  
    double q = 0.057;             // div rate
    double r = 0.01;             // Risk Free Rate  
    double v = 0.25;             // Volatility  

    // Create start and end dates
    Dates::XLDate start_date = Dates::XLDate(2020, 01, 01);
    Dates::XLDate end_date = Dates::XLDate(2020, 06, 30);

    //Create pointer for type of call
    shared_ptr<PayOffCall> AmerCall(std::make_shared<PayOffCall>(K));;
    Dates::Thirty360 const thirty360;
    //cout << act360.yearFraction(start_date, end_date) << " <<< start_date - end_date" << endl;

    BinTree goldney_American21(Spot, r, v, q, start_date, end_date, AmerCall, n, thirty360);
};

void amerCall500() {
    // CRR parameters  
    int n = 500;                   // Number of steps  
    double Spot = 106;           // Spot Price  
    double K = 100;              // Strike Price  
    double T = 0.5;              // Years to maturity  
    double q = 0.057;             // div rate
    double r = 0.01;             // Risk Free Rate  
    double v = 0.25;             // Volatility  

    // Create start and end dates
    Dates::XLDate start_date = Dates::XLDate(2020, 01, 01);
    Dates::XLDate end_date = Dates::XLDate(2020, 06, 30);

    //Create pointer for type of call
    shared_ptr<PayOffCall> AmerCall(std::make_shared<PayOffCall>(K));;
    Dates::Thirty360 const thirty360;
    //cout << act360.yearFraction(start_date, end_date) << " <<< start_date - end_date" << endl;

    BinTree goldney_American500(Spot, r, v, q, start_date, end_date, AmerCall, n, thirty360);
};

void amerCall501() {
    // CRR parameters  
    int n = 501;                   // Number of steps  
    double Spot = 106;           // Spot Price  
    double K = 100;              // Strike Price  
    double T = 0.5;              // Years to maturity  
    double q = 0.057;             // div rate
    double r = 0.01;             // Risk Free Rate  
    double v = 0.25;             // Volatility  

    // Create start and end dates
    Dates::XLDate start_date = Dates::XLDate(2020, 01, 01);
    Dates::XLDate end_date = Dates::XLDate(2020, 06, 30);

    //Create pointer for type of call
    shared_ptr<PayOffCall> AmerCall(std::make_shared<PayOffCall>(K));;
    Dates::Thirty360 const thirty360;
    //cout << act360.yearFraction(start_date, end_date) << " <<< start_date - end_date" << endl;

    BinTree goldney_American501(Spot, r, v, q, start_date, end_date, AmerCall, n, thirty360);
};

/*
******************               Question 2B              ***************************
*/

void puts() { // Form the book example: James page 81
    // CRR parameters  
    int n = 3;                   // Number of steps  
    double Spot = 100;           // Spot Price  
    double K = 110;              // Strike Price  
    double T = 0.5;              // Years to maturity  
    double q = 0.04;             // div rate
    double r = 0.10;             // Risk Free Rate  
    double v = 0.20;             // Volatility  

    // Create start and end dates
    Dates::XLDate start_date = Dates::XLDate(2020, 01, 01);
    Dates::XLDate end_date = Dates::XLDate(2020, 06, 30);

    //Create pointer for type of call
    shared_ptr<PayOffPut> EurPut(std::make_shared<PayOffPut>(K));;
    Dates::Act360 const act360;
    //cout << act360.yearFraction(start_date, end_date) << " <<< start_date - end_date" << endl;

    BinTree james_AmerPutValue(Spot, r, v, q, start_date, end_date, EurPut, n, act360);

};


void amerPut20() {
    // CRR parameters  
    int n = 20;                   // Number of steps  
    double Spot = 106;           // Spot Price  
    double K = 100;              // Strike Price  
    double T = 0.5;              // Years to maturity  
    double q = 0.0;             // div rate
    double r = 0.01;             // Risk Free Rate  
    double v = 0.25;             // Volatility  

    // Create start and end dates
    Dates::XLDate start_date = Dates::XLDate(2020, 01, 01);
    Dates::XLDate end_date = Dates::XLDate(2020, 06, 30);

    //Create pointer for type of call
    shared_ptr<PayOffPut> AmerPut(std::make_shared<PayOffPut>(K));;
    Dates::Thirty360 const thirty360;
    //cout << act360.yearFraction(start_date, end_date) << " <<< start_date - end_date" << endl;

    BinTree goldney_AmerPut20(Spot, r, v, q, start_date, end_date, AmerPut, n, thirty360);
};

void amerPut21() {
    // CRR parameters  
    int n = 21;                   // Number of steps  
    double Spot = 106;           // Spot Price  
    double K = 100;              // Strike Price  
    double T = 0.5;              // Years to maturity  
    double q = 0.0;             // div rate
    double r = 0.01;             // Risk Free Rate  
    double v = 0.25;             // Volatility  

    // Create start and end dates
    Dates::XLDate start_date = Dates::XLDate(2020, 01, 01);
    Dates::XLDate end_date = Dates::XLDate(2020, 06, 30);

    //Create pointer for type of call
    shared_ptr<PayOffPut> AmerPut(std::make_shared<PayOffPut>(K));;
    Dates::Thirty360 const thirty360;
    //cout << act360.yearFraction(start_date, end_date) << " <<< start_date - end_date" << endl;

    BinTree goldney_AmerPut21(Spot, r, v, q, start_date, end_date, AmerPut, n, thirty360);
};

void amerPut500() {
    // CRR parameters  
    int n = 500;                   // Number of steps  
    double Spot = 106;           // Spot Price  
    double K = 100;              // Strike Price  
    double T = 0.5;              // Years to maturity  
    double q = 0.0;             // div rate
    double r = 0.01;             // Risk Free Rate  
    double v = 0.25;             // Volatility  

    // Create start and end dates
    Dates::XLDate start_date = Dates::XLDate(2020, 01, 01);
    Dates::XLDate end_date = Dates::XLDate(2020, 06, 30);

    //Create pointer for type of call
    shared_ptr<PayOffPut> AmerPut(std::make_shared<PayOffPut>(K));;
    Dates::Thirty360 const thirty360;
    //cout << act360.yearFraction(start_date, end_date) << " <<< start_date - end_date" << endl;

    BinTree goldney_AmerPut500(Spot, r, v, q, start_date, end_date, AmerPut, n, thirty360);
};

void amerPut501() {
    // CRR parameters  
    int n = 501;                   // Number of steps  
    double Spot = 106;           // Spot Price  
    double K = 100;              // Strike Price  
    double T = 0.5;              // Years to maturity  
    double q = 0.0;             // div rate
    double r = 0.01;             // Risk Free Rate  
    double v = 0.25;             // Volatility  

    // Create start and end dates
    Dates::XLDate start_date = Dates::XLDate(2020, 01, 01);
    Dates::XLDate end_date = Dates::XLDate(2020, 06, 30);

    //Create pointer for type of call
    shared_ptr<PayOffPut> AmerPut(std::make_shared<PayOffPut>(K));;
    Dates::Thirty360 const thirty360;
    //cout << act360.yearFraction(start_date, end_date) << " <<< start_date - end_date" << endl;

    BinTree goldney_Put501(Spot, r, v, q, start_date, end_date, AmerPut, n, thirty360);
};


void eurPut20() {
    // CRR parameters  
    int n = 20;                   // Number of steps  
    double Spot = 106;           // Spot Price  
    double K = 100;              // Strike Price  
    double T = 0.5;              // Years to maturity  
    double q = 0.0;             // div rate
    double r = 0.01;             // Risk Free Rate  
    double v = 0.25;             // Volatility  

    // Create start and end dates
    Dates::XLDate start_date = Dates::XLDate(2020, 01, 01);
    Dates::XLDate end_date = Dates::XLDate(2020, 06, 30);

    //Create pointer for type of call
    shared_ptr<PayOffPut> EurPut(std::make_shared<PayOffPut>(K));;
    Dates::Thirty360 const thirty360;
    //cout << act360.yearFraction(start_date, end_date) << " <<< start_date - end_date" << endl;

    BinTree goldney_Put501(Spot, r, v, q, start_date, end_date, EurPut, n, thirty360);
};

void eurPut21() {
    // CRR parameters  
    int n = 21;                   // Number of steps  
    double Spot = 106;           // Spot Price  
    double K = 100;              // Strike Price  
    double T = 0.5;              // Years to maturity  
    double q = 0.0;             // div rate
    double r = 0.01;             // Risk Free Rate  
    double v = 0.25;             // Volatility  

    // Create start and end dates
    Dates::XLDate start_date = Dates::XLDate(2020, 01, 01);
    Dates::XLDate end_date = Dates::XLDate(2020, 06, 30);

    //Create pointer for type of call
    shared_ptr<PayOffPut> EurPut(std::make_shared<PayOffPut>(K));;
    Dates::Thirty360 const thirty360;
    //cout << act360.yearFraction(start_date, end_date) << " <<< start_date - end_date" << endl;

    BinTree goldney_Put501(Spot, r, v, q, start_date, end_date, EurPut, n, thirty360);
};

void eurPut500() {
    // CRR parameters  
    int n = 500;                   // Number of steps  
    double Spot = 106;           // Spot Price  
    double K = 100;              // Strike Price  
    double T = 0.5;              // Years to maturity  
    double q = 0.0;             // div rate
    double r = 0.01;             // Risk Free Rate  
    double v = 0.25;             // Volatility  

    // Create start and end dates
    Dates::XLDate start_date = Dates::XLDate(2020, 01, 01);
    Dates::XLDate end_date = Dates::XLDate(2020, 06, 30);

    //Create pointer for type of call
    shared_ptr<PayOffPut> EurPut(std::make_shared<PayOffPut>(K));;
    Dates::Thirty360 const thirty360;
    //cout << act360.yearFraction(start_date, end_date) << " <<< start_date - end_date" << endl;

    BinTree goldney_Put501(Spot, r, v, q, start_date, end_date, EurPut, n, thirty360);
};

void eurPut501() {
    // CRR parameters  
    int n = 501;                   // Number of steps  
    double Spot = 106;           // Spot Price  
    double K = 100;              // Strike Price  
    double T = 0.5;              // Years to maturity  
    double q = 0.0;             // div rate
    double r = 0.01;             // Risk Free Rate  
    double v = 0.25;             // Volatility  

    // Create start and end dates
    Dates::XLDate start_date = Dates::XLDate(2020, 01, 01);
    Dates::XLDate end_date = Dates::XLDate(2020, 06, 30);

    //Create pointer for type of call
    shared_ptr<PayOffPut> EurPut(std::make_shared<PayOffPut>(K));;
    Dates::Thirty360 const thirty360;
    //cout << act360.yearFraction(start_date, end_date) << " <<< start_date - end_date" << endl;

    BinTree goldney_Put501(Spot, r, v, q, start_date, end_date, EurPut, n, thirty360);
};

int main() {
    cout << "James European Call Value (from the book example): " << endl;
    calls();

    cout << endl << "Questino 2a: European Call 20 steps: " << endl;
    euroCall20();
    cout << endl << "Questino 2a: European Call 21 steps: " << endl;
    euroCall21();
    cout << endl << "Questino 2a: European Call 500 steps: " << endl;
    euroCall500();
    cout << endl << "Questino 2a: European Call 501 steps: " << endl;
    euroCall501();

    cout << endl << "Questino 2a: American Call 20 steps: " << endl;
    amerCall20();
    cout << endl << "Questino 2a: American Call 21 steps: " << endl;
    amerCall21();
    cout << endl << "Questino 2a: American Call 500 steps: " << endl;
    amerCall500();
    cout << endl << "Questino 2a: American Call 501 steps: " << endl;
    amerCall501();


    cout << endl << endl << "************ Question 2B *************" << endl << endl;
    
    puts();

    cout << endl << "Questino 2b: American Put 20 steps: " << endl;
    amerPut20();
    cout << endl << "Questino 2b: American Put 21 steps: " << endl;
    amerPut21();
    cout << endl << "Questino 2b: American Put 500 steps: " << endl;
    amerPut500();
    cout << endl << "Questino 2b: American Put 501 steps: " << endl;
    amerPut501();

    cout << endl << "Questino 2b: European Put 20 steps: " << endl;
    eurPut20();
    cout << endl << "Questino 2b: European Put 21 steps: " << endl;
    eurPut21();
    cout << endl << "Questino 2b: European Put 500 steps: " << endl;
    eurPut500();
    cout << endl << "Questino 2b: European Put 501 steps: " << endl;
    eurPut501();

    return 0;
}