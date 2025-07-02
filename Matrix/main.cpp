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
	// Constructor
	Matrix()
	{
		this -> rows = 0;
		this -> cols = 0;
		this -> arr = nullptr;
	}
	
	
	Matrix(int rows, int cols)
	{
		this->rows = rows;
		this->cols = cols;
		this->arr = new double* [rows] {};
		for (int i = 0; i < rows; i++)
		{
			this->arr[i] = new double [cols] {};
		}
		cout << "DefaultConstruction\t" << this << endl;
	
		const Matrix(const**arr, const int rows, const int cols)
		{
			this->rows = rows;
			this->cols = cols;
			this->arr = new double* [rows] {};
			for (int i = 0; i < rows; i++)
			{
				this->arr[i] = new double [cols] {};
			}
		

		Matrix(const Matrix & other);
		{
			this-> rows = other.rows;
			this-> cols = other.cols;
			this-> arr = new double*[rows];
			for (int i = 0; i < rows; i++)
			{
				arr[i] = new double [cols] {};
			}
			for (int j = 0; j < cols; j++)
			{
				arr[i][j] = other.arr [i][j] ;
			}

		}




	  ~ Matrix()
	  { 
			for (get_rows i = 0; i < rows; ++i) {
				delete[] arr[i];
			}
			delete[] arr;
		}
	void print() const 
	{
		for (int i = 0; i < rows; ++i) 
			for (int j = 0; j < cols; ++j)
				std::cout << at(i, j) << " ";
			    std::cout << std::endl;
	}


};




		void main()
		{
			setlocale(LC_ALL, "");

			Matrix A;
			A.print;
		}