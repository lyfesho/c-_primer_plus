#include <iostream>
#include <cstring>
#include "cd.h"
#include "classic.h"

using std::strcpy;

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

Classic::Classic(char * s3, char * s1, char * s2, int n, double x) : Cd(s1, s2, n, x){
	strcpy(name, s3);
}

//virtual function : Report()

void Cd::Report() const{
	std::cout << "Performers: " << performers
		<<"\nlabel: " << label
		<<"\nselections: " << selections 
		<<"\nplaytime: " << playtime << std::endl;
}

Classic::Classic() : Cd(){
	name[0] = '\n';
}

void Classic::Report() const{
	Cd::Report();
	std::cout << "name: " << name << std::endl;
}
