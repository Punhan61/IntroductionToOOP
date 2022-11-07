#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
class String;
String operator+(const String& left, const String& right);

class String
{
	size_t size; //размер строки в байтах
	char* str;   //указатель на строки в динамической памяти 
public:
    const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}
	size_t get_size()const
	{
		return size;
	}

	//     Constructor
	explicit String(size_t size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefConstructor:\t" << this << endl;
	}

	String(const char str[])
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
			this->str[i] = str[i];
		cout << "Constructor:\t" << endl;
	}

	String(const String& other)
	{
		//Deep copy - побитовое копирование
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyConstructor:" << this << endl;
	}
	String(String&& other)
	{
		// Shallow copy:
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;
		cout << "MoveConstructor:" << this << endl;
	}

	~String()
	{
		delete[]this->str;
		cout << "Destructor:\t" << this << endl;
	}

	//      Operators

	String& operator=(const String& other)
	{
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	String& operator=(String&& other)
	{
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = other.str;
		other.size = 0;
		other.str = nullptr;
		cout << "MoveAssignment:" << this << endl;
		return *this;
	}

	String& operator+=(const String& other)
	{
		return *this = *this + other;
	}

	char operator[](int i)const// i - index
	{
		return str[i];
	}
	char& operator[](int i)// i - index
	{
		return str[i];
	}

	//       Metods

	void print()const
	{
		cout << "size:\t" << size << endl;
		cout << "str:\t" << str << endl;
	}

};

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
	/*String str3;
	str3 = str1 + str2;
	cout << str3 << endl;*/
	str1 += str2;
	cout << str1 << endl;

#endif // OPERATOR_PLUS_CHEK


}