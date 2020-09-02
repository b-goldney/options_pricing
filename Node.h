#pragma once
//Node.h

/* Purpose of a node object is to store the generated underlying asset price 
at each node going out on the tree */
struct Node
{
	double underlying;
	double payoff; //stores the discounted expected value at each node going back
};