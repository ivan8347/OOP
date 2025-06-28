#include<iostream>

using namespace std;
using std::cin;
using std::cout;
using std::endl;


class String
	
{
	int size;	//Размер строки в Байтах
	char* str;	//Указатель на строку в динамической памяти
public:
	int get_size()const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}

	//				Constructors:
	explicit String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefaultConstructor:\t" << this << endl;
	}
	String(const char str[])
	{
		while (str[size++]);
		this->str = new char[size] {};
		for (int i = 0; str[i]; i++)this->str[i] = str[i];
		cout << "Constructor:\t\t" << this << endl;
	}
	String(const String& other)
	{
		//Конструктор копирования дожлен выполнять DeepCopy (Побитовое копирование),
		//т.е. выделять динамическую память под объект и побитово (поэлементно)
		//копировать содержимое динамической памяти из существующего объекта в создаваемый.
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyConstructor:\t" << this << endl;
	}
	~String()
	{
		delete[] str;
		this->str = nullptr;
		this->size = 0;
		cout << "Destructor:\t\t" << this << endl;
	}

	//				Operators:
	String& operator=(const String& other)
	{
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {0};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}
	//как сделать пробел?
 
String operator+(const String& other)
    {
	String str3;
	
	  str3.str = new char [this->size + other.size - 1];
	  cout << "operator '+' " << endl;
	 for (int i = 0; i < this-> size-1; i++)
	     {
	    	  str3.str[i] = this->str[i];
	     }
	 
	     for (int i = 0 ; i < other.size; i++)
	     {
	    	 str3.str[i + this -> size - 1] = other.str[i];
	     }
	  
	 return str3;	
    }

     String& operator+=(const String& other)
     {
     	return *this = *this + other;
     
     }


	//				Methods:
	void info()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
};

/*String operator+(String left, String right)
{

	String str3(left.get_size() + right.get_size() - 1);

	for (int i = 0; i < left.get_size(); i++)
	{
	
	str3.get_str[i] = left[i];
    }
	for (int i = 0; i < right.get_size(); i++)
	
		str3.get_str()[i+ left.get_size()-1] = right [i];
	
	return str3;


}*/


std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}
std::istream& operator>>(std::istream& is, String& obj)
{
	const int SIZE = 32;
	char sz_input[SIZE] = {};
	//char str;
	is.getline(sz_input, SIZE);
	//is >> str;
	return is;
} 


void main()
{
	setlocale(LC_ALL, "");
	/*String str1(5);	//explicit-конструктор нельзя вызвать оператором '=', но всегда можно вызвать при помощи круглых скобок
	str1.info();
	cout << str1 << endl;

	String str2 = "Hello";
	str2 = str2;
	cout << str2 << endl;

	String str3 = str2;		//CopyConstructor
	cout << str3 << endl;

	String str4;
	str4 = str3;
	cout << str4 << endl;*/
	  
	String str1 = "Hello";
	cout << str1 << endl;
	String str2 = "World";
	cout << str2 << endl;
	String str3 = str1  + str2;
	cout << str3 << endl;
	str1 += str2;
	cout << "+=\t" << str1 << endl ;
	String str;
	cout << "Введите строку: "; cin >> str ;
	cout << "Введенная строка : " << str << endl;



}
