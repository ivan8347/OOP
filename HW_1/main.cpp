/*#pragma warning(disable:4326)
#include<iostream>
#include<cmath>
using namespace std;

class Point
{
	double x;
	double y;
public:
	/*double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	double Distance(const Point& Point)
	{
		double dx = x - Point.x;
		double dy = y - Point.y;
		return sqrt(dx * dx + dy * dy);
	}
	Point(double x = 9, double y = 0)
	{
		this->x = x;
		this->y = y;

	}
	~Point()
	{
		cout << "\n";
		cout << "Distructor:\t\t" << this << endl;
	}

	void print()const
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");


	//cout << "x_1"; cin >> x;
	Point A;
	A.print();
	Point B = 8;
	B.print();
	Point C(7, 7);
	C.print(); cout << "\n";
	cout << "Растояние между точкой 'A' и точкой 'B': " << B.Distance(A) << endl; cout << "\n";
	cout << "Растояние между точкой 'B' и точкой 'C': " << C.Distance(B) << endl; cout << "\n";


}*/

/*
Реализовать класс Fraction, описывающий простую дробь.
В классе должны быть все обязательные методы, а так же методы:
	- to_proper();		//Неправильную дробь переводит в правильную: 11/4 => 2(3/4)
	- to_improper();	//Переводит правильную дробь в неправильную: 2(3/4) => 11/4
	- reduce();			//Сокращает дробь: 5/10 => 1/2;
1. Арифметические операторы: +, -, *, /;
2. Составные присваивания: +=, -=, *=, /=;
3. Increment/Decrement (++/--);
4. Операторы сравнения: ==, !=, >, <, >=, <=;
5. Операторы для работы с потоками: <<, >>
*/

#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
#define delimiter "\n------------------------------------\n"

class Fraction;
Fraction operator * (Fraction left, Fraction right);
Fraction operator / (const Fraction& left, const Fraction& right);

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

	// Constructor
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		set_integer(integer);
		set_numerator(numerator);
		set_denominator(denominator);
		cout << "Constructor : \t\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor :\t" << this << endl;
	}
	//       Operators
	Fraction& operator =(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment :\t" << this << endl;
		return *this;
	}
	Fraction& operator *=(const Fraction& other)
	{
		return *this = *this * other;
	}
	Fraction& operator /=(const Fraction& other)
	{
		return *this = *this / other;
	}


	~Fraction()
	{
		cout << "Destructor : \t\t" << this << endl;
	}
	//         Increment/Decrement
	
	Fraction& operator++()
	{
		integer++;
		return *this;
	}
	Fraction operator ++(int)
	{
		Fraction old = *this;
		integer++;
		return old;
	}
	Fraction& operator--()
	{
		integer--;
		return *this;
	}
	Fraction operator --(int)
	{
		Fraction old = *this;
		integer--;
		return old;
	}
	

	//         method
	Fraction to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator%= denominator;
		return *this;
	}
	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		swap(inverted.numerator, inverted.denominator);
		return inverted;
	}
	void print()const
	{
		if (integer)cout << integer;
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		else if (integer == 0)cout << 0;
		cout << endl;
	}
};
Fraction operator * (Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction 
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	). to_proper();
}
Fraction operator / (const Fraction& left, const Fraction& right)
{
	return left * right.inverted();
}
//        Comparison opertors
bool operator ==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() 
		== left.get_numerator() * right.get_denominator();
}
bool operator!=(const Fraction& left, const Fraction& right) //   НЕ РАБОТАЕТ
{
	return!(left == right);
}
std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())os << ")";
	}
	else if (obj.get_integer() == 0)os << 0;
	os << endl;
	return os;
}


//#define COMPARISON_OPERTORS
//#define INCREMENT_DECREMENT
//#define ARITHMETICAL_OPERATORS
//#define CONSTRUCTOR_CHECK
//#define ASSIGNMENT_CHECK
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
	Fraction C = A * B;
	A.print();
	B.print();
	C.print();
	Fraction D = A / B;
	D.print();
	cout << delimiter << endl;
	A *= B;
	A.print();
	B.print();
	cout << delimiter << endl;
	A /= B;
	A.print();
	B.print();

#endif // ARITHMETICAL_OPERATORS
#ifdef INCREMENT_DECREMENT
	Fraction A(1, 2);
	Fraction B = A--;
	A.print();
	B.print();

#endif // INCREMENT_DECREMENT
#ifdef COMPARISON_OPERTORS
	cout << (Fraction(1, 2) != Fraction(5, 10)) << endl;

#endif // COMPARISON_OPERTORS

	Fraction A(1, 2, 3);
	Fraction B(2, 3, 4);
	cout << A ;
}