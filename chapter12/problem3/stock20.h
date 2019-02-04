#ifndef STOCK20_H_
#define STOCK20_H_

#include <iostream>
using std::ostream;

class Stock{
	char * company;
	int shares;
	double share_val;
	double total_val;
	void set_tot(){ total_val = shares * share_val; }

public:
	Stock();
	Stock(const char * co, long n = 0, double pr = 0.0);
	~Stock();

	void buy(long num, double price);
	void sell(long num, double price);
	void update(double price);
	const Stock & topval(const Stock & s) const;

	//overload operator << for Stock
	friend ostream & operator<<(ostream & os, const Stock & s);
};

#endif
