#ifndef DMAABC_H_
#define DMAABC_H_

#include <iostream>
using std::ostream;

class DMAabc{
private:
	char * label;
	int rating;
public:
	DMAabc(const char * l = "null", int r = 0);
	DMAabc(const DMAabc & d);
	virtual ~DMAabc(){ delete [] label; };
	DMAabc & operator=(const DMAabc & d);
	friend ostream & operator<<(ostream & os, const DMAabc & d);
	virtual void View() const = 0;
};

class baseDMA : public DMAabc{
public:
	baseDMA(const char * l = "null", int r = 0);
	~baseDMA(){};
	virtual void View() const;
};

class lacksDMA : public DMAabc{
private:
	enum { COL_LEN = 40 };
	char color[COL_LEN];
public:
	lacksDMA(const char * c = "blank", const char * l = "null", int r = 0);
	lacksDMA(const char * c, const DMAabc & d);
	~lacksDMA(){};
	friend ostream & operator<<(ostream & os, const lacksDMA & ld);
	virtual void View() const;
};

class hasDMA : public DMAabc{
private:
	char * style;
public:
	hasDMA(const char * s = "none", const char * l = "null", int r = 0);
	hasDMA(const char * s, const DMAabc & d);
	hasDMA(const hasDMA & hd);
	~hasDMA(){ delete [] style; };
	hasDMA & operator=(const hasDMA & hd);
	friend ostream & operator<<(ostream & os, const hasDMA & hd);
	virtual void View() const;
};

#endif
