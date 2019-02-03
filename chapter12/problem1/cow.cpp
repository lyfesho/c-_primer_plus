#include <iostream>
#include <cstring>
#include "cow.h"

using std::cout;
using std::endl;

Cow::Cow(){
	name[0] = '\0';
	hobby = new char [1];
	hobby[0] = '\0';
	weight = 0;
}

Cow::Cow(const char * nm, const char * ho, double wt){
	strcpy(name, nm);
	hobby = new char [strlen(ho) + 1];
	strcpy(hobby, ho);
	weight = wt;
}

Cow::Cow(const Cow & c){
	strcpy(name, c.name);
	hobby = new char [strlen(c.hobby) + 1];
	strcpy(hobby, c.hobby);
	weight = c.weight;
}

Cow::~Cow(){
	delete [] hobby;
	hobby = nullptr;
}

Cow & Cow::operator=(const Cow & c){
	if(this == &c){
		return *this;
	}
	delete [] hobby;
	hobby = nullptr;
	hobby = new char [strlen(c.hobby) + 1];
	strcpy(hobby, c.hobby);
	strcpy(name, c.name);
	weight = c.weight;
	return *this;
}

void Cow::ShowCow() const {
	cout<<"name: "<<name<<endl;
	cout<<"hobby: "<<hobby<<endl;
	cout<<"weight: "<<weight<<endl;
}
