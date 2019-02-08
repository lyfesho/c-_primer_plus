#include <iostream>
#include <cstring>
#include "DMAabc.h"

using std::cout;
using std::endl;
using std::strlen;
using std::strcpy;

DMAabc::DMAabc(const char * l, int r){
	label = new char [strlen(l) + 1];
	strcpy(label, l);
	rating = r;
}

DMAabc::DMAabc(const DMAabc & d){
	label = new char [strlen(d.label) + 1];
	strcpy(label, d.label);
	rating = d.rating;
}

DMAabc & DMAabc::operator=(const DMAabc & d){
	if(this == &d){
		return *this;
	}

	delete [] label;
	label = new char [strlen(d.label) + 1];
	strcpy(label, d.label);
	rating = d.rating;
	return *this;
}

ostream & operator<<(ostream & os, const DMAabc & d){
	os << "Label: " << d.label << endl;
	os << "Rating: " << d.rating << endl;
	return os;
}

baseDMA::baseDMA(const char * l, int r) : DMAabc(l, r){}

void baseDMA::View() const{
	cout << (const DMAabc &) *this;
}

lacksDMA::lacksDMA(const char * c, const char * l, int r) : DMAabc(l, r){
	strcpy(color, c);
}

lacksDMA::lacksDMA(const char * c, const DMAabc & d) : DMAabc(d){
	strcpy(color, c);
}

ostream & operator<<(ostream & os, const lacksDMA & ld){
	os << (const DMAabc &) ld 
		<< "Color: " << ld.color << endl;
	return os;
}

void lacksDMA::View() const{
	cout << *this;
}

hasDMA::hasDMA(const char * s, const char * l, int r) : DMAabc(l, r){
	style = new char [strlen(s) + 1];
	strcpy(style, s);
}

hasDMA::hasDMA(const char * s, const DMAabc & d) : DMAabc(d){
	style = new char [strlen(s) + 1];
	strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA & hd) : DMAabc(hd){
	style = new char [strlen(hd.style) + 1];
	strcpy(style, hd.style);
}

hasDMA & hasDMA::operator=(const hasDMA & hd){
	if(this == &hd){
		return *this;
	}

	DMAabc::operator=(hd);
	delete [] style;
	style = new char [strlen(hd.style) + 1];
	strcpy(style, hd.style);
	return * this;
}

ostream & operator<<(ostream & os, const hasDMA & hd){
	os << (const DMAabc &) hd
		<< "Style: " << hd.style << endl;
	return os;
}

void hasDMA::View() const{
	cout << *this;
}
