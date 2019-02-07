#include <iostream>
#include <cstring>
#include "port.h"

using std::cout;
using std::endl;
using std::strlen;
using std::strcpy;

Port::Port(const char * br, const char * st, int b){
	brand = new char [strlen(br) + 1];
	strcpy(brand, br);
	strcpy(style, st);
	bottles = b;
}

Port::Port(const Port & p){
	brand = new char [strlen(p.brand) + 1];
	strcpy(brand, p.brand);
	strcpy(style, p.style);
	bottles = p.bottles;
}

Port & Port::operator=(const Port & p){
	if(this == &p){
		return *this;
	}

	delete [] brand;
	brand = new char [strlen(p.brand) + 1];
	strcpy(brand, p.brand);
	strcpy(style, p.style);
	bottles = p.bottles;
}

Port & Port::operator+=(int b){
	bottles += b;
	return *this;
}

Port & Port::operator-=(int b){
	bottles -= b;
	return *this;
}

void  Port::Show() const {
	cout << "Brand: " << brand 
		<<"\nKind: " << style
		<<"\nBottles: " << bottles << endl;
}

ostream & operator<<(ostream & os, const Port & p){
	os << p.brand << ", " << p.style << ", " << p.bottles;
	return os;
}

//class vintagerPort

VintagePort::VintagePort(){
	Port();
	nickname = new char [1];
	nickname[0] = '\0';
	year = 0;
}

VintagePort::VintagePort(const char * br, int b, const char * nm, int y) : Port(br, "none", b){
	nickname = new char [strlen(nm) + 1];
	strcpy(nickname, nm);
	year = y;
}

VintagePort::VintagePort(const VintagePort & vp) : Port(vp){
	nickname = new char [strlen(vp.nickname) + 1];
	strcpy(nickname, vp.nickname);
	year = vp.year;
}

VintagePort & VintagePort::operator=(const VintagePort & vp){
	if(this == &vp){
		return * this;
	}

	operator=(vp);
	delete [] nickname;
	nickname  = new char [strlen(vp.nickname) + 1];
	strcpy(nickname, vp.nickname);
	year = vp.year;
	return * this;
}

void VintagePort::Show() const{
	Port::Show();
	cout << "Nickname: " << nickname
		<< "\nYear: " << year << endl;
}

ostream & operator<<(ostream & os, const VintagePort & vp){
	os << (const Port &) vp << ", " << vp.nickname << ", " << vp.year;
}

