#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
#define delimiter "\n------------------------------------\n"

class String
{
	int size;
	char* str;
   public:
	   int get_size()const
	   {
		   return size;
	   }
	   char* get_str()const
	   {
		   return str;
	   }
	   void set_size(int size)
	   {
		   this->size = size;
	   }
	   void set_str(char* str)
	   {
		   this-> str = str;
	   }
	   // Construktor

	   String(char* str, int size)
	   {

	   }

};










void main()
{
	setlocale(LC_ALL, "");








}