#include"Int.h"

using namespace std;

int main()
{
	Int a(5);
	a.display_binary();
	a.display_number();
	Int b;
	b = a;
	b.display_binary();


	system("pause");
}