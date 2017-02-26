#include "Int.h"



//***************************************************************************************
Int::Int()
{
	for (int i = 0; i < 32; i++)
	{
		table[i] = 0;
	}

}
//***************************************************************************************
Int::Int(bool tab[32])
{
	for (int i = 0; i < 32; i++)
	{
		table[i] = tab[i];
	}
}
//***************************************************************************************
Int::Int(int integer)
{
	if (integer >= 0)
	{
		table[0] = 0;

		for (int i = 31; i > 0; i--)
		{
			table[i] = reinterpret_cast<bool*>(integer % 2);
			integer /= 2;
		}
	}

	if (integer < 0) // bit inversion and add 1 (model 2C or ZU2 in polish)
	{
		integer = -integer;
		table[0] = 0;
		for (int i = 31; i > 0; i--)
		{
			table[i] = reinterpret_cast<bool*>(integer % 2);
			integer /= 2;
		}

		this->bit_invertion();
		*this += Int(1);
	}

}
//***************************************************************************************
Int::~Int()
{


}
//***************************************************************************************
void Int::display_binary()
{
	cout << endl;
	for (int i = 0; i < 32; i++)
	{
		cout << "|" << this->table[i];
	}
	cout << "|" << endl;
}
//***************************************************************************************
void Int::display_number()
{
	cout << this->converter() << endl;
}
//***************************************************************************************
int Int::converter()
{
	int result = 0;
	if (table[0] == 0)
	{
		for (int i = 31; i > 0; i--)
		{
			if (table[i] == 1)
			{
				result += (pow(2, (31 - i)));
			}
		}

	}
	if (table[0] == 1)
	{
		result = -pow(2, 31);
		for (int i = 31; i > 0; i--)
		{
			if (table[i] == 1)
			{

				result += (pow(2, (31 - i)));
			}
		}
	}
	return result;
//***************************************************************************************
}
void Int::bit_invertion()
{
	for (int i = 31; i >= 0; i--)
	{
		table[i] = (!table[i]);
	}

}
//***************************************************************************************
Int& Int::operator+=(Int integer)
{
	bool carry = 0;
	//the loop below base on checking if there occur one of free elements
	//processor do not recognised value equal 2 but this is simplification instead of checking nine different condition
	for (int i = 31; i >= 0; i--)
	{
		if (table[i] + integer.table[i] + carry == 0)
		{
			table[i] = 0;
			carry = 0;
		}
		else if (table[i] + integer.table[i] + carry == 1)
		{
			table[i] = 1;
			carry = 0;
		}
		else if (table[i] + integer.table[i] + carry == 2)
		{
			cout << "wartosc rekordu po inwersji jest rowny:" << table[i] << "	";
			table[i] = 0;
			carry = 1;
			//cout << "No mam Cie na pozycji numer:" << i;
		}
	}

	return *this;
}
//***************************************************************************************
Int&  Int::operator+(Int integer)
{
	Int result;
	result = *this;
	result += integer;
	return result;
}
//***************************************************************************************
Int & Int::operator=(Int integer)
{
	for (int i = 0; i < 32; i++)
	{
		this->table[i] = integer.table[i];
	}
	return *this;
}
//***************************************************************************************
Int & Int::operator=(int integer)
{
	*this = Int(integer);
}
//***************************************************************************************
