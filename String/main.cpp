
#include"String.h"

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