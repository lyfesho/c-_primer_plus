#include "port.h"

int main(){
	const char * br1 = "Gallo";
	const char * st1 = "tawny";
	Port port1(br1, st1, 20);
	Port port2 = port1;
	Port port3(port1);

	port1 += 1;
	port2 -= 2;

	port1.Show();
	port2.Show();
	cout << port3;


	const char * nm1 = "Gl";
	VintagePort vp1;
	VintagePort vp2(br1, 20, nm1, 90);
	VintagePort vp3(vp2);
	VintagePort vp4 = vp3;

	vp1.Show();
	vp2.Show();
	cout << vp3 <<endl;
	cout << vp4 <<endl;

	return 0;
}
