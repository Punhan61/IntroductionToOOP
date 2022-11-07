#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
using std::size_t;

class String;
String operator+(const String& left, const String& right);

class String
{
	size_t size; //размер строки в байтах
	char* str;   //указатель на строки в динамической памяти 
public:
	const char* get_str()const;
	char* get_str();
	size_t get_size()const;

	//     Constructor

	explicit String(size_t size = 80);
	String(const char str[]);
	String(const String& other);
	String(String&& other);
	~String();

	//      Operators

	String& operator=(const String& other);
	String& operator=(String&& other);
	String& operator+=(const String& other);

	char operator[](int i)const;
	char& operator[](int i);

	//       Metods

	void print()const;
};

const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}
std::size_t String::get_size()const
{
	return size;
}

//     Constructor

String::String(size_t size):size(size), str(new char[size] {})
{
	//this->size = size;
	//this->str = new char[size] {};
	cout << "DefConstructor:\t" << this << endl;
}

String::String(const char str[]) :String(strlen(str) + 1)
{
	//this->size = strlen(str) + 1;
	//this->str = new char[size] {};
	for (int i = 0; i < size; i++)
		this->str[i] = str[i];
	cout << "Constructor:\t" << endl;
}

String::String(const String& other) :String(other.str)
{
	//Deep copy - побитовое копирование
	//this->size = other.size;
	//this->str = new char[size] {};
	//for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	cout << "CopyConstructor:" << this << endl;
}
String::String(String&& other) :size(other.size), str(other.str)
{
	// Shallow copy:
	//this->size = other.size;
	//this->str = other.str;
	other.str = nullptr;
	cout << "MoveConstructor:" << this << endl;
}
String::~String()
{
	delete[]this->str;
	cout << "Destructor:\t" << this << endl;
}

//      Operators

String& String::operator=(const String& other)
{
	if (this == &other)return *this;
	delete[] this->str;
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	cout << "CopyAssignment:\t" << this << endl;
	return *this;
}
String& String::operator=(String&& other)
{
	if (this == &other)return *this;
	delete[] this->str;
	this->size = other.size;
	this->str = other.str;
	other.size = 0;
	other.str = nullptr;
	cout << "MoveAssignment:\t" << this << endl;
	return *this;
}
String& String::operator+=(const String& other)
{
	return *this = *this + other;
}

char String::operator[](int i)const// i - index
{
	return str[i];
}
char& String::operator[](int i)// i - index
{
	return str[i];
}

//       Methods

void String::print()const
{
	cout << "size:\t" << size << endl;
	cout << "str:\t" << str << endl;
}

String operator+(const String& left,const String& right)
{
	String cat(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		cat[i] = left[i];
		//cat.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < left.get_size(); i++)
		cat[i + left.get_size() - 1] = right[i];
		//cat.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	return cat;

}

ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}

//#define CONSTRUCTOR_CHEK
#define OPERATOR_PLUS_CHEK
//#define WAYS_TO_CALL_CONSTRUCTORS

void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTOR_CHEK
	String str1;    //Пустая строка размеров 80 байт
	cout << str1 << endl;
	str1.print();
	cout << str1 << endl;

	String str2(22);
	str2.print();

	String str3 = "Hello";
	str3.print();
	str3 = str3;

	String str4 = str3; //CopyOcnstructor
	cout << str4 << endl;

	String str5;
	str5 = str4;
	cout << str5 << endl;
#endif // CONSTRUCTOR_CHEK

#ifdef OPERATOR_PLUS_CHEK
	String str1 = "Hello";
	String str2 = "World";
	
	String str3;
	str3 = str1 + str2;
	cout << str3 << endl;
	
	str1 += str2;
	cout << str1 << endl;

	String str4 = str1;
	cout << str4 << endl;
#endif // OPERATOR_PLUS_CHEK

#ifdef WAYS_TO_CALL_CONSTRUCTORS
	String str1;		//DefaultConstructor
	str1.print();
	String str2(5);		//Single-argumant type 'int'
	str2.print();
	String str3 = "Hello";//Single-argument type 'const char*'
	str3.print();
	String str4();	//Это выражение НЕ создает объект, а просто объявляет функцию str4(),
					//которая ничего не принимает, и возвращает значение типа 'String'.
	//str4.print();
	//Если нужно явно вызвать конструктор по умолчанию, то это можно сделать так:
	String str5{};	//Явный вызов конструктора по умолчанию
	str5.print();
	String str6{ 7 };
	str6.print();
	String str7{ "Hello" };
	str7.print();
#endif // WAYS_TO_CALL_CONSTRUCTORS

}