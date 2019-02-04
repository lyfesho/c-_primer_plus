#ifndef STRING2_H_
#define STRING2_H_

#include <iostream>
using std::istream;
using std::ostream;

class String{
private:
	char * str;
	int len;
	static int num_strings; //number of objects
	static const int CINLIM = 80; //cin input limit
public:
	//constructors and other methods
	String();
	String(const char * s);
	String(const String & s);
	~String();
	int length() const{return len;}

	//ADD
	String & stringlow(); //converts string to lowercase
	String & stringup(); //converts string to uppercase
	int has(const char c) const;

	//overloaded operator methods
	String & operator=(const String & s);
	String & operator=(const char * s);
	char & operator[](int i);
	const char & operator[](int i) const;

	//ADD
	String operator+(const String & s) const; //String + String 
	String operator+(const char * s) const; //String + char*
	

	//overload operator friends
	friend bool operator<(const String &st, const String &st2);
	friend bool operator>(const String &st1, const String &st2);
	friend bool operator==(const String &st, const String &st2);
	friend ostream & operator<<(ostream &os, const String &st);
	friend istream & operator>>(istream &is, String &st);

	//ADD
	friend String operator+(const char * s1, const String & s2); //char* + String
	
	//static function
	static int HowMany();
};

#endif
