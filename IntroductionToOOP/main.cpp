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

	      /// МЕТОДЫ 
	double distance(Point other)
	{
		/*double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;*/
		return sqrt(pow(this->x - other.x, 2) + pow(this->y - other.y, 2));
	}

	void print()const
	{
		cout << "X = " << x << "\tY = "<< y << endl;
	}
};

double distanse(Point A, Point B)
{
	/*double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;*/
	return sqrt(pow(A.get_x() - B.get_x(), 2) + pow(A.get_y() - B.get_y(), 2));
}

//#define STRUCT_POINT
//#define GET_SET_CHECK
//#define DISTANCE_CHEK 
#define CONSTRUCTOR_CHEK

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

#ifdef DISTANCE_CHEK
	Point A(2, 3);
	Point B(7, 8);
	A.print();
	B.print();
	cout << "Расстояние от точки 'А' до точки 'В':" << A.distance(B) << endl;
	cout << "Расстояние от точки 'B' до точки 'A':" << B.distance(A) << endl;
	cout << "Расстояние между точками 'А' и 'В':" << distance(A,B) << endl;
	cout << "Расстояние между точками 'В' и 'А':" << distance(B,A) << endl;
	

#endif // DISTANCE_CHEK


#ifdef CONSTRUCTOR_CHEK
	Point A;   // Конструктор по умолчанию
	A.print();

	Point B = 5;//Single-Argument constructor
	B.print();

	Point C(2, 3);
	C.print();
#endif // CONSTRUCTOR_CHEK



}