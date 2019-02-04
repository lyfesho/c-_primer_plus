#include <iostream>
#include <cstring>
#include "stock20.h"

using std::strcpy;
using std::strlen;

Stock::Stock(){
	const char * no_co = "no name";
	company = new char [strlen(no_co) + 1];
	strcpy(company, no_co);
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}

Stock::Stock(const char * co, long n, double pr){
	company = new char [strlen(co) + 1];
	strcpy(company, co);

	if(n < 0){
		std::cout << "Number of shares can't be negative; "
			<< company << "shares set to 0.\n";
		shares = 0;
	}
	else{
		shares = n;
	}
	share_val = pr;
	set_tot();
}

Stock::~Stock(){
	delete [] company;
	company = nullptr;
}

void Stock::buy(long num, double price){
	if (num < 0){
		std::cout << "Number of shares purchased can't be negative. "
			<< "Transaction is aborted.\n";
	}
	else{
		shares += num;
		share_val = price;
		set_tot();
	}
}

void Stock::sell(long num, double price){
	using std::cout;
	if (num < 0){
		cout << "Number of shares sold can't be negative. "
			<< "Transaction is aborted.\n";
	}
	else if (num > shares){
		cout << "You can't sell more than you have! "
			<< "Transaction is aborted.\n";
	}
	else{
		shares -= num;
		share_val = price;
		set_tot();
	}
}

void Stock::update(double price){
	share_val = price;
	set_tot();
}

const Stock & Stock::topval(const Stock & s) const {
	if (s.total_val > total_val){
		return s;
	}
	else{
		return *this;
	}
}

//overload operator << for Stock
ostream & operator<<(ostream & os, const Stock & s){
	os << "Company: " << s.company 
		<<" Shares: " << s.shares << '\n'
		<<" Share Price: $" << s.share_val
		<<" Total Worth: $" << s.total_val << '\n';
	return os;
}

