#include<iostream>
using namespace std;

#define tab "\t"

class Point
{
	double x;
	double y;
public:
	double get_x()const
	{

		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

	//       Constructors
	Point()
	{
		x = y = double();
		//double() - значение по умолчанию для типа double
		cout << "Costructor:\t" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "1ArgConstructor:" << this << endl;
	}
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
		cout << "Costructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}

	      /// МЕТОДЫ ///
	void print()const
	{
		cout << "X = " << x << "\tY = "<< y << endl;
	}
};

//#define STRUCT_POINT
//#define GET_SET_CHECK

void main()
{
	setlocale(LC_ALL, "");
	//cout << "Hello OOP" << endl;

#ifdef STRUCT_POINT
	int a;    //объявление переменной 'a' типа 'int'
	Point A;  //объявление переменной 'A' типа 'Point'
			  //объявления объекта 'A' структуры 'Point'
			  //объявления экземляра 'A' структуры 'Point'

	A.x = 2.2;
	A.y = 3.4;
	cout << A.x << tab << A.y << endl;

	Point* pA = &A;
	cout << pA->x << tab << pA->y << endl;
#endif // STRUCT_POINT

#ifdef GET_SET_CHECK

	Point A;
	A.set_x(2);
	A.set_y(3);
	//cout << A.get_x() << tab << A.get_y() << endl;
	A.print();
#endif // GET_SET_CHECK

	Point A;   // Конструктор по умолчанию
	A.print();

	Point B = 5;//Single-Argument constructor
	B.print();

	Point C(2, 3);
	C.print();
}