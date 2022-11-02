﻿#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimitr "\n---------------------------------------------\n"

class Fraction;  //Объявления класса
Fraction operator*(Fraction left, Fraction right);
Fraction operator+(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);

class Fraction
{
	int integer;
	int numerator;
	int denominator;
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}

	//     Constructor
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefConstructor:\t" << this << endl;
	}

	explicit Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "1ArgConstructor:" << this << endl;
	}

	Fraction(double decimal)
	{
		integer = decimal;
		decimal += 1e-10;
		denominator = 1e+9;
		numerator = (decimal - integer) * denominator;
		reduce();
		cout << "Double Constructor" << this << endl;

	}

	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;
	}

	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t" << this << endl;
	}

	// Operators

	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}

	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this * other;
	}

	Fraction& operator+=(const Fraction& other)
	{
		return *this = *this + other;
	}

	Fraction& operator-=(const Fraction& other)
	{
		return *this = *this - other;
	}

	Fraction& operator++()
	{
		integer++;
		return *this;
	}

	Fraction operator++(int)
	{
		Fraction old = *this;
		integer++;
		return old;
	}

	//  Type cast operators

	explicit operator int()const
	{
		return integer + numerator / denominator;
	}
	explicit operator double()const
	{
		return integer + (double)numerator / denominator;
	}


	//        Metods
	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& to_proper()
	{
		integer = numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		/*int buffer = inverted.numerator;
		inverted.numerator = inverted.denominator;
		inverted.denominator = buffer;*/
		swap(inverted.numerator, inverted.denominator);
		return inverted;
	}

	Fraction& reduce()
	{
		if (numerator == 0)return *this;
		int more, less, rest; //rest - остаток
		if (numerator > denominator)more = numerator, less = denominator;
		else less = numerator, more = denominator;
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
		int GCD = more; // GCD-Greatest Common Divider(наибольший общий делитель)
		numerator /= GCD;
		denominator /= GCD;
		return *this;
	}
	
};

//            Operators
ostream& operator<<(ostream& os, const Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())os << ")";
	}
	else if (obj.get_integer() == 0)os << 0;
	return os;
}
Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*Fraction result;
	result.set_numerator(left.get_numerator() * right.get_numerator());
	result.set_denominator(left.get_denominator() * right.get_denominator());*/
	/*Fraction result
	{
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	};	
	return result;*/
	return Fraction
	{
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	}.to_proper();
}

Fraction operator/(const Fraction& left,const Fraction& right)
{
	/*left.to_improper();
	right.to_improper();
	return Fraction
	{
		left.get_numerator() * right.get_denominator(),
		right.get_numerator() * left.get_denominator()
	}.to_proper();	*/
	return left * right.inverted();
}

Fraction operator+(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	{
		left.get_numerator() * right.get_denominator() + right.get_numerator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()
	}.to_proper();
}

Fraction operator-(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	{
		left.get_numerator() * right.get_denominator() - right.get_numerator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()
	}.to_proper();
}
// Comparison operators
bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() ==
		right.get_numerator() * left.get_denominator();
}

bool operator!=(const Fraction& left, const Fraction& right)
{
	return !(left == right);
}

bool operator>(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() >
		right.get_numerator() * left.get_denominator();
}

bool operator<(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() <
		right.get_numerator() * left.get_denominator();
}

bool operator>=(const Fraction& left, const Fraction& right)
{
	return left > right || left == right;
}


//#define CONSTRUCTOR_CHEK
//#define ARITHMETICAL_OPERATOR_CHEK
//#define COMPOUND_ASSIGNMENT_CHECK
//#define COMPARISON_OPERATOR_CHEK
//#define TYPE_CONVERSION_BASSICS
//#define CONVERSION_FROM_OTHER_TO_CLASS
#define CONVERSION_FROM_CLSSS_TO_OTHER_TYPE

void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTOR_CHEK
	Fraction A;
	cout << A << endl;

	double b = 5;
	Fraction B = 5;
	cout << B << endl;

	Fraction C(2, 3);
	cout << C << endl;

	Fraction D(2, 3, 4);
	cout << D << endl;
#endif // CONSTRUCTOR_CHEK

#ifdef ARITHMETICAL_OPERATOR_CHEK
	Fraction A(1, 2, 3);
	Fraction B(3, 4, 5);
	Fraction C = A * B;
	cout << C << endl;
	cout << A / B << endl;
	cout << A + B << endl;
	cout << A - B << endl;
	for (Fraction i(3, 4); i.get_integer() < 10; ++i)
	{
		cout << i << "\t";
	}
	cout << endl;
#endif // ARITHMETICAL_OPERATOR_CHEK

#ifdef COMPOUND_ASSIGNMENT_CHECK
	Fraction A(1, 2, 3);
	Fraction B(3, 4, 5);
	A *= B;
	cout << A << endl;

	A += B;
	cout << A << endl;

	A -= B;
	cout<< A << endl;
#endif // COMPOUND_ASSIGNMENT_CHECK

#ifdef COMPARISON_OPERATOR_CHEK

	cout << (Fraction(1, 2) < Fraction(5, 10)) << endl;

#endif // COMPARISON_OPERATOR_CHEK

#ifdef TYPE_CONVERSION_BASSICS
	int a = 2;      //No conversiont
	double b = 3;   //Conversion from less to more преоб-ие от меньшего к большему
	int c = b;      //Conversion from more to less(with no data loss) преоб-ие от большего к меньшему без потери данных
	int d = 2.5;    //Conversion from more to lass(with data loss) с потерей данных

#endif // TYPE_CONVERSION_BASSICS

#ifdef CONVERSION_FROM_OTHER_TO_CLASS
					/*
	1. From other to Class:
		 Single-Argument constructor;
		 Assignment operator;

	2. From Class to other type;
		 operator type()const
		 {
			.....;
			conversion-algorithm;
			.....;
		 }
	explicit

	*/

	Fraction A = Fraction(5);  //Conversion from int to fraction
	cout << A << endl;
	cout << delimitr << endl;
	Fraction B;      //Default constructor
	cout << delimitr << endl;
	B = (Fraction)8;
	cout << delimitr << endl;
	cout << B << endl;
#endif // CONVERSION_FROM_OTHER_TO_CLASS

#ifdef CONVERSION_FROM_CLSSS_TO_OTHER_TYPE
	Fraction A(2, 3, 4);
	int a = (int)A;
	cout << a << endl;

	double b = (double)A;
	cout << b << endl;

	Fraction B = 2.8;
	cout << B << endl;

#endif // CONVERSION_FROM_CLSSS_TO_OTHER_TYPE


}