#include<Fraction_SPU_411.h>

void main()
{
	setlocale(LC_ALL, "");
	Fraction A;
	Fraction B(2, 3, 4);
	cout << "ֲגוהטעו הנמבü קונוח '/' : ";
	cin >> A;
	cout << A << endl;
	cout << (Fraction(1, 2) <= Fraction(5, 11)) << endl;
}