#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include<string.h>
#include <tuple>

using namespace std;


class Fish {
public:
	virtual Fish* Clone() = 0;
	virtual void Swim() = 0;
	virtual ~Fish() {
		cout << "Destroyed fish" << endl;
	};

};


class Tuna : public Fish {
public:
	Fish* Clone() override {
		return new Tuna(*this);
	}
	void Swim() override final {
		cout << "Tuna swims fast in the sea" << endl;
	}

	void BecomeDinner() {
		cout << "Tuna became dinner" << endl;
	}



};

class BlueFinaTuna final : public Tuna {
public:
	Fish* Clone() override {

		return new BlueFinaTuna(*this);
	}


};


class Carp final: public Fish {
public:
	Fish* Clone() {

		return new Carp(*this);
	}
	void Swim() override final{

		cout << "Carp swims slow in the lake" << endl;
	}

	void Talk() {

		cout << "Carp talk" << endl;
	}


};

void DetectFishType(Fish* objFish) {

	Tuna* objTuna = dynamic_cast<Tuna*>(objFish);
	if (objTuna)
	{
		cout << "Detected Tuna" << endl;
		objTuna->BecomeDinner();

	}

	Carp* objCarp = dynamic_cast<Carp*>(objFish);
	if (objCarp)
	{
		cout << "Detected carp" << endl;
		objCarp->Talk();
	}

	cout << "Verifying type:" << endl;
	objFish->Swim();

}



class Shape {

public:
	virtual double Area() = 0;
	virtual void Print() = 0;

};


class Circle : public Shape {
private:
	double radius;
public:
	Circle(double inputRadius) : radius(inputRadius) {}

	double Area() {

		return 3.1416 * radius * radius;
	}

	void Print() {

		cout << "Circle says hello" << endl;
	}


};

class Triangle : public Shape {
private:
	double base, height;
public:
	Triangle(double inputBase, double inputHeight) : base(inputBase), height(inputHeight){}

	double Area() {
		return 0.5 * base * height;
		
	}

	void Print() {
		cout << "Triangle says hello" << endl;

	}


};

class Animal {

public:
	Animal() {
		cout << "Animal object created" << endl;
	}

	int age;
};

class Reptile : public virtual Animal {

};

class Bird: public virtual Animal{

};

class Mammal : public virtual Animal {

};

class Platypus final : public Mammal, public Bird, public Reptile {
public:
	Platypus() {
		cout << "Platypus constructor" << endl;
	}

};


class Date {
private:
	int day, month, year;
	string dateInString;

public:
	Date(int inDay, int inMonth, int inYear) : day(inDay), month(inMonth), year(inYear) {}

	Date& operator ++() { //prefix operator

		++day;
		return *this;

	}
	Date& operator --() {
		--day;
		return *this;

	}

	Date operator ++(int) {
		Date copy(month, day, year);
		++day;
		return copy;


	}

	Date operator --(int) {
		Date copy(month, day, year);
		--day;
		return copy;
	}

	Date operator +(int daysToAdd) {

		Date newDate(month, day + daysToAdd, year);
		return newDate;
	}

	Date operator -(int daysToSub) {

		Date newDate(month, day - daysToSub, year);
		return newDate;
	}

	void operator +=(int daysToAdd) {

		day += daysToAdd;
	}

	void operator -=(int daysToSub) {

		day -= daysToSub;
	}

	bool operator ==(const Date& compareDate) {
		if (day==compareDate.day)
		{
			if (month==compareDate.month)
			{
				if (year==compareDate.year)
				{
					return true;
				}

			}

		}

		return false;
	}

	bool operator !=(const Date& compareDate) {

		return !(this->operator==(compareDate));

	}

	bool operator <(const Date& compareDate) {

		if (year<compareDate.year)
		{
			return true;
		}
		else if (month<compareDate.month)
		{
			return true;
		}
		else if (day<compareDate.day)
		{
			return true;
		}
		else
		{
			return false;
		}


	}


	bool operator <=(const Date& compareDate) {

		if (this->operator==(compareDate))
		{
			return true;
		}
		else
		{
			return this->operator<(compareDate);
		}

	}

	bool operator >(const Date& compareDate) {

		return !(this->operator<=(compareDate));
	}

	bool operator >=(const Date& compareDate) {

		if (this->operator==(compareDate))
		{
			return true;
		}
		else
		{
			return this->operator>(compareDate);
		}

	}


	void displayDate() {

		cout << month << '.' << day << '.' << year << endl;
	}


};

class MyString {

private:
	char* buffer;

	MyString() : buffer(NULL) {
		cout << "Default constructor called" << endl;
	}


public:
	MyString(const char* input) {

		if (input!=NULL)
		{
			buffer = new char[strlen(input) + 1];
			strcpy(buffer, input);
		}
		else
		{
			buffer = NULL;
		}

	}

	MyString(const MyString& copySource) { //copy constructor


		cout << "Constructor called for " << copySource.buffer << endl;
		buffer = NULL;
		if (copySource.buffer!=NULL)
		{
			buffer = new char[strlen(copySource.buffer) + 1];
			strcpy(buffer, copySource.buffer);
		}
		else
		{
			buffer = NULL;
		}
	}

	MyString(MyString&& moveSrc) {//move constructor

		cout << "Move constuctor moves " << moveSrc.buffer << endl;
		if (moveSrc.buffer!=NULL)
		{
			buffer = moveSrc.buffer;
			moveSrc.buffer = NULL;

		}

	}

	MyString& operator = (MyString&& moveSrc) {

		cout << "Move assigment operator moves: " << moveSrc.buffer << endl;
		if ((moveSrc.buffer!=NULL) && (this!=&moveSrc))
		{
			delete[] buffer;

			buffer = moveSrc.buffer;
			moveSrc.buffer = NULL;

		}

		return *this;
	}


	MyString& operator =(const MyString& copy) {


		if ((this!=&copy) && copy.buffer!=NULL)
		{
			if (buffer!=NULL)
			{
				delete[] buffer;
			}

			buffer = new char[strlen(copy.buffer) + 1];
			strcpy(buffer, copy.buffer);
		}

		return *this;
	}

	operator const char* () {
		return buffer;
	}

	int getLenght() const {

		return strlen(buffer);

	}

	const char operator[](int i) {
		if (i<getLenght())
		{
			return buffer[i];
		}


	}

	MyString operator +(const MyString& addThis) {
		cout << "Operator + called" << endl;
		MyString newStr;

		if (addThis.buffer!=NULL)
		{
			newStr.buffer = new char[getLenght() + strlen(addThis.buffer) + 1];
			strcpy(newStr.buffer, buffer);
			strcat(newStr.buffer, addThis.buffer);

		}

		return newStr;
	}


	~MyString()
	{
		if (buffer!=NULL)
		{
			delete[] buffer;
		}
	}

};


class Display {
public:
	void operator()(string input) const {

		cout << input << endl;
	}



};

struct Temperature
{
	double Kelvin;
	Temperature(long double Kelvin) : Kelvin(Kelvin) {};

};

Temperature operator ""_C(long double celsius) {
	return Temperature(celsius + 273);

}

class DynIntegers {
private:
	int* array;
public:
	DynIntegers(DynIntegers&& moveSrc) {

		array = moveSrc.array;
		moveSrc.array = NULL;

	}

	DynIntegers& operator =(DynIntegers&& moveSrc) {
		if (this!=&moveSrc)
		{
			delete[] array;
			array = moveSrc.array;
			moveSrc.array = NULL;

		}

	}

	~DynIntegers()
	{
		delete[] array;

	}

};


template <typename Type>
const Type& GetMax(const Type& value1, const Type& value2) {

	if (value1>value2)
	{
		return value1;
	}
	else
	{
		return value2;
	}

}


template <typename Type>
void DisplayComparison(const Type& value1, const Type& value2) {

	cout << "Get max( " << value1 << ", " << value2 << ") : ";
	cout << GetMax(value1, value2) << endl;



}


template <typename T1=int,typename T2=double>
class HoldsPair {
private:
	T1 value1;
	T2 value2;
public:
	HoldsPair(const T1& val1, const T2& val2) : value1(val1), value2(val2){}

	const T1& getFirstValue() const {
		return value1;
	}

	const T2& getSecondValue() const {
		return value2;
	}


};

template <> class HoldsPair<int, int> {
private:
	int value1;
	int value2;
	string steFun;
public:
	HoldsPair(const int& val1, const int& val2) : value1(val1), value2(val2){}

	const int& getFirstValue() {
		cout << "Returning integer of value 1: " << value1 << endl;
		return value1;
	}

	const int& getSecondValue() {
		cout << "Returning integer of value 2: " << value2 << endl;
		return value2;
	}

};


template<typename T>
class TestStatic {
public:
	static int StaticVal;

};

template<typename T> int TestStatic<T>::StaticVal;


template<typename Res, typename ValType>
void Sum(Res& result, ValType& val) {

	result += val;
}

template<typename Res, typename First, typename... Rest>
void Sum(Res& result, First val1, Rest ... valN) {

	result += val1;
	return Sum(result, valN...);

}



template <typename tupleType>
void DisplayTupleInfo(tupleType& tup) {

	const int numMembers = tuple_size<tupleType>::value;
	cout << "Number of elements in tuple: " << numMembers << endl;
	cout << "Last element value : " << get<numMembers - 1>(tup) << endl;

}



#define MULTIPLY(a, b) ((a)*(b))
template <typename T1, typename T2>
const T1& multi(const T1& val1, const T2& val2) {
	return val1 * val2;

}
template <typename T>
void Swap(T& x, T& y) {
	T temp = x;
	x = y;
	y = temp;


}

template <typename ArrayType1, typename ArrayType2>
class TwoArrays {

private:
	
public:
	ArrayType1 Array1[3];
	ArrayType2 Array2[3];


	ArrayType1& GetArray1Element(int index) { return Array1[index]; }
	ArrayType2& GetArray2Elemente(int index) { return Array2[index]; }


};




int main() {
	
	TwoArrays<int, double> ar1;
	ar1.Array1[0] = 1;
	ar1.Array1[1] = 2;
	ar1.Array1[2] = 3;

	cout << ar1.GetArray1Element(2) << endl;



	
	return 0;
}
