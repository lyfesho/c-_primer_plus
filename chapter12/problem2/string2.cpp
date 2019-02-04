#include <cstring>
#include <cctype>
#include "string2.h"

using std::cout;
using std::cin;
using std::strcpy;
using std::strcat;
using std::strlen;
using std::strcmp;

int String::num_strings = 0;

int String::HowMany(){
	return num_strings;
}

String::String(){
	str = new char [1];
	str[0] = '\0';
	len = 4;
	num_strings ++;
}

String::String(const char * s){
	len = strlen(s);
	str = new char [len + 1];
	strcpy(str, s);
	num_strings ++;
}

String::String(const String & s){
	len = s.len;
	str = new char [len + 1];
	strcpy(str, s.str);
	num_strings ++;
}

String::~String(){
	-- num_strings;
	delete [] str;
	str = nullptr;
}

String & String::stringlow(){
	for(int i = 0; i < len; i ++){
		str[i] = tolower(str[i]);
	}
	return *this;
}

String & String::stringup(){
	for(int i = 0; i < len; i ++){
		str[i] = toupper(str[i]);
	}
	return *this;
}

int String::has(const char c) const {
	int cnt = 0;
	for(int i = 0; i < len; i ++){
		if(str[i] == c){
			cnt ++;
		}
	}
	return cnt;
}

//overload operator
String & String::operator=(const String &s){
	if(this == &s){
		return *this;
	} //judge for avoiding wrong deletion below

	delete [] str;
	str = nullptr;
	len = s.len;
	str = new char [s.len + 1];
	strcpy(str, s.str);
	return *this;
}

String & String::operator=(const char * s){
	delete [] str;
	str = nullptr;
	len = strlen(s);
	str = new char [strlen(s) + 1];
	strcpy(str, s);
	return *this;
}

char & String::operator[](int i){
	return str[i];
}

const char & String::operator[](int i) const {
	return str[i];
}


String String::operator+(const String & s) const {
	String s_add;
	s_add.len = len + s.len;
	s_add.str = new char [s_add.len + 1];
	strcpy(s_add.str, str);
	strcat(s_add.str, s.str);
	return s_add;
}

String String::operator+(const char * s) const {
	String temp = s;
	return *this+temp;
}

//overload operator friends

bool operator<(const String &st, const String &st2){
	return(strcmp(st.str, st2.str) < 0);
}

bool operator>(const String &st, const String &st2){
	return(st2 < st);
}

bool operator==(const String &st, const String &st2){
	return (strcmp(st.str, st2.str) == 0);
}

ostream & operator<<(ostream & os, const String & st){
	os << st.str;
	return os;
}

istream & operator>>(istream & is, String & st){
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is){
		st = temp;
	}
	while(is && is.get() != '\n'){
		continue;
	}
	return is;
}

String operator+(const char * s1, const String & s2){
	String temp = s1;
	return temp + s2; //convert to String + char*
}









































