#pragma once
#include<iostream>
#include <math.h>

using namespace std;

class Double
{
public:
	bool table[32];
protected:
public:
	Double();
	Double(bool tab[32]);
	Double(double);
	~Double();
	void display_binary();
	void display_number();
	double converter();
	void bit_invertion();
	Double& operator+=(Double value);
	Double& operator+((Double value);
	Double& operator=(Double value);
	Double& operator=(Double value);

};