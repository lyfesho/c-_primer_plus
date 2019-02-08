#include <iostream>
#include <cstring>
#include "DMAabc.h"

using namespace std;

const int DMAS = 3;

int main(){
	DMAabc * dmas[DMAS];
	string label;
	int rating;
	string color;
	string style;

	char kind;

	for (int i = 0; i < DMAS; i ++){
		cout << "Enter label: ";
		getline(cin, label);
		cout << "Enter rating: ";
		cin >> rating;

		cout << "Enter 1 for baseDMA, 2 for lacksDMA, 3 for hasDMA: ";
		while (cin >> kind && (kind != '1' && kind != '2' && kind != '3'))
			cout << "Enter 1 or 2 or 3: " << endl;
		if ('1' == kind){
			dmas[i] = new baseDMA(label.c_str(), rating); //using c_str() to change string to const char *
		}
		else if ('2' == kind){
			cout << "Enter color: ";
			cin.ignore(); //to ignore '\n' after cin >> rating. otherwise color will be null
			getline(cin, color);
			dmas[i] = new lacksDMA(color.c_str(), label.c_str(), rating);
		}
		else {
			cout << "Enter style: ";
			cin.ignore();
			getline(cin, style);
			dmas[i] = new hasDMA(style.c_str(), label.c_str(), rating);
		}

		while (cin.get() != '\n'){
			continue;
		}
	}

	cout << endl;
	for (int i = 0; i < DMAS; i ++){
		dmas[i]->View();
		cout << endl;
	}

	for(int i = 0; i < DMAS; i ++){
		delete dmas[i];
	}

	return 0;
}
