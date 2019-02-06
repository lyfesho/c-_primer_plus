#include <iostream>
#include <cstring>
#include "cd.h"
#include "classic.h"

using std::strcpy;
using std::strlen;

//Class Cd

Cd::Cd(char * s1, char * s2, int n, double x){
	strcpy(performers, s1);
	strcpy(label, s2);
	selections = n;
	playtime = x;
}

Cd::Cd(const Cd & d){
	strcpy(performers, d.performers);
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
}

Cd::Cd(){
	performers[0] = '\0';
	label[0] = '\0';
	selections = 0;
	playtime = 0;
}

Cd::~Cd(){}

void Cd::Report() const{
	std::cout << "Performers: " << performers
		<<"\nlabel: " << label
		<<"\nselections: " << selections 
		<<"\nplaytime: " << playtime << std::endl;
}

Cd & Cd::operator=(const Cd & d){
	if(this == &d){
		return *this;
	}
	strcpy(performers, d.performers);
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
	return *this;
}

//Class Classic

Classic::Classic(char * s3, char * s1, char * s2, int n, double x) : Cd(s1, s2, n, x){
	name = new char [strlen(s3) + 1];
	strcpy(name, s3);
}

Classic::Classic(const Classic & d) : Cd(d){
	name = new char [strlen(d.name) + 1];
	strcpy(name, d.name);
}

Classic::Classic() : Cd(){
	name = new char [1];
	name[0] = '\0';
}

//virtual function 

Classic::~Classic(){
	delete [] name;
	name = nullptr;
}

void Classic::Report() const{
	Cd::Report();
	std::cout << "name: " << name << std::endl;
}

Classic & Classic::operator=(const Classic & d){
	if(this == &d){
		return *this;
	}

	Cd::operator=(d);
	delete [] name;
	name = new char [strlen(d.name) + 1];
	strcpy(name, d.name);

	return *this;
}
