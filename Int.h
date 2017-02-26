#pragma once
#include<iostream>
#include <math.h>

using namespace std;

class Int
{
public:
	bool table[32];
protected:
public:
	Int();
	Int(bool tab[32]);
	Int(int);
	~Int();
	void display_binary();
	void display_number();
	int converter();
	void bit_invertion();
	Int& operator+=(Int integer);
	Int& operator+(Int integer);
	Int& operator=(Int integer);
	Int& operator=(int integer);

};

















