
#include <iostream>

using namespace std;

#define delimiter "\n------------------------------------\n"


//class Matrix;
//Matrix operator+(const Matrix& other);

class Matrix
{
    int rows;
    int cols;
    double** arr;
public:
    int get_rows() const { return rows; }
    int get_cols() const { return cols; }
    double** get_arr() const { return arr; }

    // Конструктор по умолчанию
    Matrix()
    {
        this-> rows = 0;
        this-> cols = 0;
        this-> arr = nullptr;
        cout << "Constructor :\t" << endl;
    }

   
    // Конструктор с заданными размерами
    Matrix(int rows, int cols)
    {
       this-> rows = rows;
       this-> cols = cols;
       this-> arr = new double* [rows];
        for (int i = 0; i < rows; i++)
        {
            this->arr[i] = new double[cols]();
        }
        cout << "DefaultConstructor\t" << this << endl;
    }

    // Конструктор копирования
    Matrix(const Matrix& other)
    {
       this->  rows = other.rows;
       this->  cols = other.cols;
       this->arr = new double* [rows] {};
        for (int i = 0; i < rows; i++)
        {
            this->arr[i] = new double[cols] {};
            for (int j = 0; j < cols; j++)
            {
               this-> arr[i][j] = other.arr[i][j];
            }
        }
        
        cout << "Copy constructor\t" << this << endl;
    }
    // Operator '='
    Matrix& operator = (const Matrix& other)
    {
        if (this == &other)return *this;
        this-> rows = other.rows;
        this-> cols = other.cols;
        this-> arr = new double* [rows];
        for (int i = 0; i < rows; i++)
        {
            this-> arr[i] = new double[cols];
            for (int j = 0; j < cols; j++)
            {
               this-> arr[i][j] = other.arr[i][j];
            }
        }
        return* this;
    cout << "CopyAssignment :\t" << this << endl;
    }

    Matrix(Matrix&& other)
    {
        this->rows = other.rows;
        this->cols = other.cols;
        this->arr = other.arr;
        other.rows = 0;
        other.cols = 0;
        other.arr = nullptr;
        cout << "MoveConstructor : \t" <<  this << endl;

    }

    // Деструктор
    ~Matrix()
    {
        if (arr != nullptr)
        {
            for (int i = 0; i < rows; i++)
            {
                delete[] arr[i];
            }
            delete[] arr;
        }
        cout << "Destructor:\t\t" << this << endl;
    }
Matrix operator+(const Matrix& other)
{
    if (this-> rows == other.rows && cols == other.cols)
    {
        Matrix result(rows, cols);

            for (int i = 0; i < rows ; i++)
            {
                for (int j = 0; j < cols; j++)
                result.arr[i][j] = arr[i][j] + other.arr[i][j];
            }
            return result;
    }
}

Matrix operator-(const Matrix& other)
{
    if (this->rows == other.rows && cols == other.cols)
    {
        Matrix result(rows, cols);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
                result.arr[i][j] = arr[i][j] - other.arr[i][j];
        }
        return result;
    }    
}
    // Оператор вывода
    friend ostream& operator<<(ostream& os, const Matrix& other);

    // Оператор ввода
    friend istream& operator>>(istream& is, Matrix& other);
    
};


void FillRand(Matrix& other)
{
    for (int i = 0; i < other.get_rows(); i++)
    {
        for (int j = 0; j < other.get_cols(); j++)
        {
            other.get_arr()[i][j] = rand() % 100;
        } 
    }   
}

// Реализация оператора <<
std::ostream& operator<<(std::ostream& os, const Matrix& other)
{
    for (int i = 0; i < other.rows; i++)
    {
        for (int j = 0; j < other.cols; j++)
        {
            os << other.arr[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

// Реализация оператора >>
std::istream& operator>>(std::istream& is, Matrix& other)
{
    // Освободить старую память, если есть
    if (other.arr != nullptr)
    {
        for (int i = 0; i < other.rows; i++)
        {
            delete[] other.arr[i];
        }
        delete[] other.arr;
        other.arr = nullptr;
    }

    cout << "Введите число строк: ";
    is >> other.rows;
    cout << "Введите число столбцов: ";
    is >> other.cols;

    // Выделяем память под новую матрицу
    other.arr = new double* [other.rows];
    for (int i = 0; i < other.rows; i++)
    {
        other.arr[i] = new double[other.cols];
    }
    return is;
}

int main()
{
    setlocale(LC_ALL, "");

    
    Matrix A(2,3);
    FillRand(A);
    cout << A << endl;
    Matrix C = A;
    cout << C << endl;
    Matrix D = C + A;
    cout << "Operator '+' : \t" << endl;cout << D << endl;
    Matrix F = D - A;
    cout << "Operator '-' : \t" << endl;
    cout << F << endl;
    cout << delimiter;
   
    cout << "Введите новую матрицу:" << endl;
    Matrix B;
    cin >> B;
    FillRand(B);
    cout << "Введенная матрица:" << endl;
    cout << B;

    
}
   


