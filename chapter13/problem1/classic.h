#ifndef CLASSIC_H_
#define CLASSIC_H_
#include "cd.h"

class Classic : public Cd {
private:
	char name[40];

public:
	Classic(char * s3, char * s1, char * s2, int n, double x);
	Classic();
	virtual void Report() const;
};


#endif
