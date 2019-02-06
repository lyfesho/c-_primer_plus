#include <iostream>
using namespace std;
#include "classic.h"

void Bravo(const Cd & disk);
int main(){
	Cd c1("Beatles", "Capitol", 14, 35.5);
	Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C", 
			"Alfred Brendel", "Philips", 2, 57.17);
	Cd * pcd = &c1;

	cout << "Using object directly:\n";
	c1.Report(); //Cd::Report()
	c2.Report(); //Classic::Report()

	cout << "Using tupe cd * pointer to objects:\n";
	pcd->Report(); //Cd::Report()
	pcd = &c2;
	pcd->Report(); //Classic::Report()

	cout << "Calling a function with a Cd reference argument:\n";
	Bravo(c1); //Cd::Report
	Bravo(c2); //Classic::Report

	cout << "Testing assignment:\n";
	Classic copy;
	copy = c2;
	copy.Report(); //Classic::Report

	return 0;
}

void Bravo(const Cd & disk){
	disk.Report();
}
