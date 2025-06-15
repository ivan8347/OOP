#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
#define delimiter "\n------------------------------------\n"
#define tab "\t"

class Fraction

{
	int integer;
	int numerator;
	int denominator;

public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}

	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}

	//конструктор
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "Constructor:\t\t" << this << endl;
	}
	
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator =1;
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator (denominator);
		cout << "Constructor:\t\t" <<this<< endl;
	}


	Fraction(int integer , int numerator, int denominator)
	{
		set_integer(integer);
		set_numerator(numerator);
		set_denominator(denominator);
		cout << "Constructor : \t\t" << this << endl;

	} Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t" << this << endl;
	}
	//Operators
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}
	//Fraction& operator *=(const Fraction& other)
	//{
	//	return *this = *this * other;
	//}



	//инкремент
	Fraction& operator++()
	{
		integer++;
		return *this;
	}
	Fraction operator++(int)
	{
		Fraction old = *this;
		integer++;
		return old;
	}



	~Fraction()
	{
		cout << "Destructor:\t\t" << this << endl;
	}
	void to_improper()
	{
		numerator += integer * denominator;
		integer = 0;

	}
	void print()const
	{

		if (integer)cout << integer;
		if (numerator)
		{
			if (integer) cout << "(";
			cout << numerator << "/" << denominator;
			if (integer) cout << ")";
		}
		else if (integer == 0)cout << 0;
		cout << endl;
	}

};

//операторы сравнения

//bool operator==(Fraction left, Fraction right)

//Fraction& operator*( Fraction left, Fraction right)
//{
//	
//	left.to_improper();
//	right.to_improper();
//	//Fraction result;
//	//result.set_numerator(left.get_numerator() * right.get_numerator());
//	//result.set_denominator(left.get_denominator() * right.get_denominator());*/
//	//Fraction result
//	//(
//	//left.get_numerator() * right.get_numerator(),
//	//left.get_denominator() * right.get_denominator()
//	//);
//	//return result;
//	return Fraction
//	(
//		left.get_numerator() * right.get_numerator(),
//		left.get_denominator() * right.get_denominator()
//	);
//
//	void to_proper()
//	{
//		integer += numerator * denominator;
//		}
//}
//Fraction operator /(Fraction left, Fraction right)
//{
//	left.to_improper();
//	right.to_improper();
//
//}
std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer()) os << "(";
		os <<obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer()) os << ")";
	}
	else if (obj.get_integer() == 0)os << 0;
	cout << endl;
	return os;


//#define CONSTRUCTOR_CHECK
//#define ASSIGMENT_CHECK
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
#ifdef ASSIGMENT_CHECK
	int a, b, c;
	a = b = c = 0;
	cout << a << "\t" << b << "\t" << c << endl;
	Fraction A, B, C;
	cout << delimiter << endl;
	A = B = C = Fraction(2, 3, 4);
	cout << delimiter << endl;

#endif // ASSIGMENT_CHECK

//	Fraction A(1, 2);
//	Fraction B(2,3, 4);
//	//Fraction C = A / B;
//	A.print();
//	B.print();
//	C.print();
//	A *= B;
//	A.print();
//	B.print();
	//Fraction A(1, 2);
	//Fraction B = A++;
	//A.print();
	//B.print();
	////Fraction A(1, 2);
	//Fraction B = ++A;
	//A.print();
	//B.print();

	Fraction A(1,2,3);
	Fraction B(2,3,4);
	cout << A << endl;
}