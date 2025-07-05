#include<iostream>
#include<Windows.h>
#include"String.h"
using namespace std;
using std::cin;
using std::cout;
using std::endl;
#define delimiter "\n------------------------------------\n"
#define DEBUG
class String;
String operator+(const String& left, const String& right);
std::ostream& operator<<(std::ostream& os, const String& obj);
std::istream& getline(std::istream& cin, String& obj);
std::istream& operator>>(std::istream& cin, String& obj);
class String

{
	int size;	//Размер строки в Байтах
	char* str;	//Указатель на строку в динамической памяти
public:
	int get_size()const;	 
	const char* get_str()const;
	char* get_str();

	//				Constructors:

	explicit String(int size = 80);
	String(const char str[]);
	String(const String& other);
	String(String&& other);
	~String();

	//				Operators:
	String& operator=(const String& other);
	String& operator=(String&& other);
	String& operator+=(const String& other);	
	char operator[](int i)const;
	char& operator[](int i);

	//				Methods:
	void info()const;
};



    int String:: get_size()const
	{
		return size;
	}	 
	 const char* String ::get_str()const 
	{
		return str;
	}
	 char* String:: get_str()
	{
		return str;
	} 

	//				Constructors:

	 String::String(int size ):size(size),str(new char[this-> size]{})
	{
		cout << "DefaultConstructor:\t" << this << endl;
	}
	
	String::String(const char str[]):String(strlen(str) + 1 )
	{
		for (int i = 0; str[i]; i++)this->str[i] = str[i];
		cout << "Constructor:\t\t" << this << endl;
	}
	String::String(const String& other):String(other.str)
	{
		//Конструктор копирования дожлен выполнять DeepCopy (Побитовое копирование),
		//т.е. выделять динамическую память под объект и побитово (поэлементно)
		//копировать содержимое динамической памяти из существующего объекта в создаваемый.
		//this->size = other.size;
		//this->str = new char[size] {};
		//for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyConstructor:\t" << this << endl;
	}
	String::String(String&& other):size(other.size),str(other.str)
	{
		//this->size = other. size;
		//this->str = other. str;
		other.size = 0;
		other.str = nullptr;
		cout << "MoveConstructor : \t\t" << endl;

	}
	String::~String()
	{
		delete[] str;
		this->str = nullptr;
		this->size = 0;
		cout << "Destructor:\t\t" << this << endl;
	}

	//				Operators:
	String& String:: operator=(const String& other)
	{
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {0};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}
	 String& String:: operator=(String&& other)
	 {
		 delete[] this->str;
		 this->size = other.size;
		 this->str = other.str;
		 other.size = 0;
		 other.str = nullptr;
		 cout << "MoveAssignment :\t" << this << endl;
		 return *this;
	 }
	 char String::operator[](int i)const
	{
		return str[i];
	}
	 char& String::operator[](int i)
	 {
		 return str[i];
	 }


	

	String& String::operator+=(const String& other)
	{
		return *this = *this + other;
	
	}


	//				Methods:
	void String:: info()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
String operator+(const String& left, const String& right)
{
	String result  (left.get_size() + right.get_size() - 1);
	for (int i = 0;  left.get_str()[i]; i++)
	{
		//result.get_str()[i] = left.get_str()[i];
		result[i] = left[i];
	}
	for (int i = 0; right.get_str()[i]; i++)
	{
		//result.get_str()[left.get_size() - 1 + i] = right.get_str()[i];
		result [left.get_size() - 1 + i] = right[i];
	}
	cout << "Operator '+' :" << endl;
	return result;

}


std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}
std::istream& operator>>(std::istream& cin, String& obj)
{
	const int SIZE = 1024 ;
	char buffer[SIZE] = {};
	cin >> buffer;
	obj = buffer;

	return cin;
}
std::istream& getline(std::istream& cin, String& obj)
{
	cin.getline(obj.get_str(), obj.get_size());
	return cin;
}

//#define CONSTRUCTOR_CHECK
#define OPERATOR_PLUS
//#define ISTREAM_OPERATOR
void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTOR_CHECK
	/ String str1(5);	//explicit-конструктор нельзя вызвать оператором '=', но всегда можно вызвать при помощи круглых скобок
	str1.info();
	cout << str1 << endl;

	String str2 = "Hello";
	str2 = str2;
	cout << str2 << endl;

	String str3 = str2;		//CopyConstructor
	cout << str3 << endl;

	String str4;
	str4 = str3;
	cout << str4 << endl;

#endif // CONSTRUCTOR_CHECK
#ifdef OPERATOR_PLUS
	11 - 50; 12 - 50;
	String str1 = "Hello";
	String str2 = "World";
	cout << delimiter << endl;
	String str3 ;
	 str3 = str1 + str2;
	cout << delimiter << endl;
	cout << str3 << endl;
	 String str4 = str3;
	cout << delimiter << endl;
	 cout << str4 << endl;
	cout << delimiter << endl;

#endif // OPERATOR_PLUS

#ifdef ISTREAM_OPERATOR
	String str;
	cout << "Введите строку :";
	SetConsoleCP(1251);
	//cin >> str;*/
	getline(cin, str);
	SetConsoleCP(866);
	//cin.getline(str.get_str(), str.get_size());
	cout << str << endl;

#endif // ISTREAM_OPERATOR
	/*String str1;
	str1.info();
	String str2(8);
	str2.info();
	String str3 = "Hello";
	str3.info();
	cout << typeid("Hello").name() << endl;

	String str4();
	String str5(8);
	String str6{ 8 };
	String str7{};
	String str9 = str3;
	str9.info();*/


}
