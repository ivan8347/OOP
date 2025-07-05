#include"String.h"


  
//#define CONSTRUCTOR_CHECK
#define OPERATOR_PLUS
//#define ISTREAM_OPERATOR
void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTOR_CHECK
	/ String str1(5);	//explicit-конструктор нельз€ вызвать оператором '=', но всегда можно вызвать при помощи круглых скобок
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
	cout << "¬ведите строку :";
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
