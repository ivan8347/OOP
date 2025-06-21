#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;
using std::cin;
using std::cout;
using std::endl;
#define delimiter "\n------------------------------------\n"

class Fraction;
Fraction operator * (Fraction left, Fraction right);
Fraction operator / (const Fraction& left, const Fraction& right);
Fraction operator + (Fraction left, Fraction right);
Fraction operator - (Fraction left, Fraction right);

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
	//  "="
	Fraction& operator =(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment :\t" << this << endl;
		return *this;
	}
	//  "*="
	Fraction& operator *=(const Fraction& other)
	{
		return *this = *this * other;
	}
	//  "/="
	Fraction& operator /=(const Fraction& other)
	{
		return *this = *this / other;
	}
	// "+="
	Fraction& operator +=(const Fraction& other)
	{
		return *this = *this + other;
	}
	// "-="
	Fraction& operator -=(const Fraction& other)
	{
		return *this = *this - other;
	}

	~Fraction()
	{
		cout << "Destructor : \t\t" << this << endl;
	}

	//         Increment/Decrement
	//  "++"
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
	//  "--"
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
		numerator %= denominator;
		if (numerator < 0)numerator *= (-1);
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

//  "*"
Fraction operator * (Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}
//  "/"
Fraction operator / (const Fraction& left, const Fraction& right)
{
	return left * right.inverted();
}
//  "+"
Fraction operator + (Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_denominator() +
		right.get_numerator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();

}
//  "-"   ÊÀÊ ÈÇÁÀÂÂÈÒÜÑß ÎÒ ÂÒÎÐÎÃÎ ÌÈÍÓÑÀ?
Fraction operator-(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_denominator() -
		right.get_numerator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}

//        Comparison operàtors
// "=="
bool operator ==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	left.set_numerator(left.get_numerator() * right.get_denominator());
	right.set_numerator(right.get_numerator() * left.get_denominator());
	return left.get_numerator() == right.get_numerator();
}
// "!="     

bool operator!=(const Fraction& left, const Fraction& right)
{
	return!(left == right);
}
//  ">="
bool operator >=( Fraction left,  Fraction right)
{
	left.to_improper();
	right.to_improper();
	return (left.get_numerator() * right.get_denominator() >= right.get_numerator() * left.get_denominator());
}
// ">"
bool operator > (Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return (left.get_numerator() * right.get_denominator() > right.get_numerator() * left.get_denominator());
}
// "<"
bool operator <(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return (left.get_numerator() * right.get_denominator() < right.get_numerator() * left.get_denominator());
}
// "<="
bool operator <=(const Fraction& left, const Fraction& right)
{
	return left < right || left == right;
	/*left.to_improper();
	right.to_improper();
	return (left.get_numerator() * right.get_denominator() <= right.get_numerator() * left.get_denominator());*/
}



// "<<"
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
std::istream& operator >> (std::istream& is, Fraction& obj)
{
	/*int integer, numerator, denominator;
	char a = '/';
	char b = ' ';
	is >> integer >> b >>numerator >> a >> denominator;
	is >> integer>> numerator >> denominator;

	if(is>>integer ) obj.set_integer(integer);
	if(is>> numerator)  obj.set_numerator(numerator);
	if(is>> denominator)obj.set_denominator(denominator);*/
	const int SIZE = 32;
	char sz_input[SIZE] = {};
	is.getline(sz_input, SIZE); //ââîä ñòðîêè ñ ïðîáåëàìè
		// is >> sz_input;
		const char delimetrs[] = { '/',' ','(',')', ',','.',0 };
		int numbers[3] = {};
		int n = 0;
		for (char* pch = strtok(sz_input, delimetrs); pch && n<3; pch = strtok(NULL, delimetrs))
			numbers[n++] = atoi(pch);
		//for (int i = 0; i < n; i++)
		//	cout << numbers[i] << "\t";
		//cout << endl;
		switch (n)
		{
		case 1:obj = numbers[0]; break;
		case 2:obj = Fraction(numbers[0], numbers[1]); break;
        case 3:obj = Fraction(numbers[0], numbers[1], numbers[2]);  break;

		}
	return is;
}

//#define CONSTRUCTOR_CHECK
//#define ASSIGNMENT_CHECK
//#define ARITHMETICAL_OPERATORS
//#define INCREMENT_DECREMENT
//#define COMPARISON_OPERTORS
#define OSTREAM_ISTREAM
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
	cout << "Ââåäèòå äðîáü ÷åðåç '/' : ";
	cin >> A;
	cout << A << endl;

#endif // OSTREAM_ISTREAM

}