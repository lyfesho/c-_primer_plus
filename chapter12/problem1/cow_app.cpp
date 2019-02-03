#include "cow.h"

int main(){
	Cow cow1 = Cow();
	
	char nm[20] = "cow2";
	char ho[10] = "milky";
	double wt = 100;
	Cow cow2 = Cow(nm, ho, wt);

	Cow cow3 = cow2;

	cow1.ShowCow();
	cow2.ShowCow();
	cow3.ShowCow();

	return 0;

}
