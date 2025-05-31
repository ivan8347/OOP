#pragma warning(disable:4326)
#include<iostream>
using namespace std;

//struct Point
	//создава€ структуру или класс мы создаем новый тип данных.
	//   !!!!!     класс - это тип данных         !!!
	//   !!!!!     структура - это тип данных     !!!
class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this-> x = x;
	}
	void set_y(double y)
	{
		this-> y = y;
	}
	// —onstructors
	/*Point()
	{
		x = y = 0;
		cout << "DefaultConstructor:" << this << endl;
	}
	Point(int x)
	{
		this ->x = x;
		this ->y = 0;
		cout << "Constructor:" << this << endl;
	}*/
	Point(double x=0, double y=0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:" << this << endl;
	}
	~Point()
	{
		cout << "Distructor:\t\t" << this << endl;
	}

	void print()const
	{
		cout << "X = " << get_x() << "\tY = " << get_y() << endl;
	}
};
//#define STRUCT_POINT
void main() 
{
	setlocale(LC_ALL, "");
#ifdef STRUCT_POINT
	int a;    // объ€вление 'a' типа 'int'
	Point A;  // объ€вление 'A' типа 'Point'
	// создание объекта 'A' структуры Point
	//создание экземпл€ра ј структуры Point
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;
	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;


#endif // STRUCT_POINT


	Point A; //здесь не€вно вызываетс€ конструктор по умолчанию  
	//         //по сколько мы создаем объект по умолчанию
	//A.set_x(2);
	//A.set_y(3);
	//cout << A.get_x() << "\t" << A.get_y() << endl;
	A.print();
	Point B = 5;
	B.print();
	//cout << B.get_x() << "\t" << B.get_y() << endl;
	Point C(7, 8);
	C.print();
}
