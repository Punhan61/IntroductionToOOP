#pragma once
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
using std::size_t;
//////////////////////////////////////////////////////////////////
/////////     ���������� ������ - CLASS DECLARATION     //////////

class String;
String operator+(const String& left, const String& right);
ostream& operator<<(ostream& os, const String& obj);

class String
{
	size_t size; //������ ������ � ������
	char* str;   //��������� �� ������ � ������������ ������ 
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

///////     ���������� ������ - CLASS DECLARATION END    ///////
////////////////////////////////////////////////////////////////