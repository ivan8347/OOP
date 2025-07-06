
#include"Fraction.h"

//#define CONSTRUCTOR_CHECK
//#define ASSIGNMENT_CHECK
//#define ARITHMETICAL_OPERATORS
//#define INCREMENT_DECREMENT
//#define COMPARISON_OPERTORS
#define OSTREAM_ISTREAM
//#define CONVERSIONS_FROM_OTHER_TO_CLASS
//#define CONVERSIONS_BASICS
void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTOR_CHECK
	Fraction A;
	A.print();
	Fraction B = 5;
	B.print();
	Fraction C(1, 2);
	C.print();
	Fraction D(2, 3, 4);
	D.print();
	Fraction E = D;
	E.print();
	Fraction F;
	F = E;
	F.print();
#endif // CONSTRUCTOR_CHECK
#ifdef ASSIGNMENT_CHECK
	int a, b, c;
	a = b = c = 0;
	cout << a << "\t" << b << "\t" << c << endl;
	Fraction A, B, C;
	cout << delimiter << endl;
	A = B = C = Fraction(2, 3, 4);
	cout << delimiter << endl;

#endif // ASSIGNMENT_CHECK
#ifdef ARITHMETICAL_OPERATORS
	Fraction A(1, 2);
	Fraction B(2, 3, 4);
	Fraction C = A - B;
	A.print();
	B.print();
	C.print();

	//Fraction D = A / B;
	//D.print();
	//cout << delimiter << endl;
	//A -= B;
	//A.print();
	//B.print();
	//cout << delimiter << endl;
	//A /= B;
	//A.print();
	//B.print();

#endif // ARITHMETICAL_OPERATORS
#ifdef INCREMENT_DECREMENT
	Fraction A(1, 2);
	Fraction B = A--;
	A.print();
	B.print();

#endif // INCREMENT_DECREMENT
#ifdef COMPARISON_OPERTORS
	cout << (Fraction(1, 2) <= Fraction(5,11)) << endl;

#endif  COMPARISON_OPERTORS

#ifdef OSTREAM_ISTREAM
	Fraction A;
	Fraction B(2, 3, 4);
	cout << "¬ведите дробь через '/' : ";
	cin >> A;
	cout << A << endl;

#endif // OSTREAM_ISTREAM

#ifdef CONVERSIONS_BASICS
	int a = 2; // No conversions
	double b = 3; // inplicit conversion('int' to 'double')
	int c = b; // без потери данных
	int d = 4.5; // с потерей данных

#endif // CONVERSIONS_BASICS

#ifdef CONVERSIONS_FROM_OTHER_TO_CLASS
	Fraction A = (Fraction)5;
	cout << A << endl;
	Fraction B;
	cout << delimiter << endl;
	B = 8;
	cout << B << endl;

#endif // CONVERSIONS_FROM_OTHER_TO_CLASS

	//operator type()
	
	/*Fraction A(2, 3, 4);
	cout << A << endl;
	int a = (int)A;
	cout << a << endl;
	double b = (double)A;
	cout << b << endl;*/




}