#include"Double.h"

class Double
{
private:
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

}