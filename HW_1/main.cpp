#pragma warning(disable:4326)
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
	}*/
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
	

}
