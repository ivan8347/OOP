
#include<iostream>
#include<Windows.h>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
#define delimiter "\n------------------------------------\n"
class Matrix
{
	int rows;
	int cols;
	double** arr;

public:
	int get_rows()const
	{
		return rows;
	}
	int get_cols()const
	{
		return cols;
	}
	double** get_arr()const
	{
		return arr;
	}
	Matrix()
	{
		
	}
	Matrix(double[] )
	{
        this->rows = 0;
		this->cols = 1;
		this->arr = arr;
	}
		Matrix(int rows, int cols)
		{
			this -> rows = rows;
			this -> cols = cols;
			this ->arr = new double* [cols * rows] {};
		cout << "DefaultConstruction\t" << this << endl;
		}

		Matrix(int size)
		{
			rows = size;
			cols = size;
			arr = new double* [cols * rows] {};
		cout << "Constructor\t" << endl;
		}

		Matrix(const Matrix& other)
		{
			rows = other.rows;
			cols = other.cols;
			arr = new double* [cols * rows] {};
			for (int i = 0; i < rows * cols; i++)
			{
				this->arr[i] = other.arr[i];
			}
			cout << "CopyConstructor:\t" << this << endl;
		}
		~Matrix()
		{
			delete[]arr;
		}

};
std::ostream operator <<(std::ostream& os, const Matrix& other)
{
	for (int i = 0; i < other.get_rows; i++)
	{
		for (int j = 0; j < obj.get_cols; j++)
		{
			os << (obj.get_arr[i * obj.get_cols + j]) << " ";
		}
		os << endl;
	}
	//return os;
}
//std::istream& operator >>(std::istream& cin, Matrix& other)
//{
//	for (int i = 0; i < other.rows * other.cols; i++)
//	{
//		cin >> other.arr[i];
//	}
//	return cin;
//}















void main()
{
	setlocale(LC_ALL, "");

	Matrix A(2,3);
	cout << A << endl;
	Matrix B(3);
	Matrix C = A;



}