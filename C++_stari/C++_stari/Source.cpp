#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <bitset>

using namespace std;

class Human {
	//member attributes
private:
	string name;
	int age;
	friend void displayAge(const Human& person);
	friend  class Utility;


public:
	Human(string humanName, int humanAge) {
		name = humanName;
		age = humanAge;

	}
	

};

class Utility {

public:
	void displayHuman(const Human& person) {
		cout << "Human " << person.name << " is " << person.age << " years old" << endl;
	}

};



class MyString {

private: 
	char* buffer;
public:
	MyString(const char* initString) { //default constructor
		buffer = NULL;
		if (initString!=NULL)
		{
			buffer = new char[strlen(initString) + 1];
			strcpy(buffer, initString);

		}


	}

	MyString(const MyString& copySource) { //copy constructor

		buffer = NULL;
		if (copySource.buffer!=NULL)
		{
			buffer = new char[strlen(copySource.buffer) + 1];
			strcpy(copySource.buffer, buffer);


		}

	}

	~MyString()
	{
		delete[] buffer;

	}

	int getLength() {
		return strlen(buffer);
	}

	const char* getString() {
		return buffer;
	}





};




class President {
private:
	President() {};
	President(const President&);
	const President& operator=(const President&);

	string name;

public:
	static President& getInstance() {

		static President onlyInstance;
		return onlyInstance;
	}

	void setName(string newName) {
		name = newName;

	}

	string getName() {

		return name;
	}


};

class MonsterDB {

private:
	~MonsterDB()
	{};

public:

	static void deleteObject(MonsterDB* pObject) {
		cout << "Object is deleted" << endl;
		delete pObject;

	}

	void doSomething() {

		cout << "velika baza podataka se kreira dinamicki" << endl;
	}


};

class Human1 {

private:
	int age;
public:
	explicit Human1(int humanAge) : age(humanAge){}

};

void doSmt(Human1 person) {
	cout << "Human sent did something" << endl;
}

void displayAge(const Human& person) {
	cout << "Human " << person.name << " is " << person.age << " years old" << endl;

}

union simpleUnion
{
	int num;
	char alph;

};

struct ComplexType
{
	enum DataType
	{
	Int,
	Char,

	}Type;

	union Value {
		int num;
		char alph;

		Value() {};
		~Value()
		{};


	}value;


};


void displayComplex(const ComplexType& obj) {
	switch (obj.Type)
	{
	case 0:
		cout << "Union contains int " << obj.value.num << endl;
		break;
	case ComplexType::Char:
		cout << "Union contains char " << obj.value.alph << endl;
		break;

	}


}

class Human2 {

	int age;
public:
	constexpr Human2(int humanAge) : age(humanAge) {
	}

	constexpr int getAge() const { return age; }


};

/*
int fja() {


	cout << "hello\n" << endl;
	cout << "Rezultat izracunavanja 10/5 = " << 10 / 5 << "\n" <<  endl;
	cout << "Pi je jednako " << 22.0 / 7 << '\n' << endl;

	return 0;
}

int mnozenje(int x, int y) {

	n = x * y;
	cout << x << "*" << y << endl;
	cout << "Rezultat je: " << n << endl;


	return n;
}

constexpr double getPi() {

	return 22.0 / 7;
}


enum CardinalDirections {

	Norht = 25,
	East,
	West,
	South
};


constexpr int squarre(int n) {

	return n * n;
}

enum daysOfWeek {

	Monday = 1,
	Tuesday ,
	Wednesday,
	Thursday,
	Friday,
	Saturday, 
	Sunday,

};

const double pi = 3.14159265;

double area(double radius) {
	return pi * radius * radius;
}



auto circ(double radius) {
	return pi * 2 * radius;
}

double area(double radius, double height) {
	return 2 * area(radius) + 2 * pi * radius * height;

}

int getFib(int index) {

	if (index < 2)
	{
		return index;
	}
	else
	{
		return getFib(index - 1) + getFib(index - 2);
	}

}

void query() {

	cout << "Enter radius" << endl;
	double radius;
	cin >> radius;
	char c;

	cout << "Area: " << area(radius) << endl;

	cout << "do you want circ?" << endl;
	cin >> c;
	if (c == 'n')
	{
		cout << "End" << endl;
		return;
	}
	else
	{
		cout << "circ is: " << circ(radius) << endl;
	}

	cout << "End" << endl;

}


void printArray(int niz[], int n) {

	for (int i = 0; i < n; i++)
	{
		cout << niz[i] << ' ';
	}
	cout << endl;
}


void printArray(char niz[], int n) {

	for (int i = 0; i < n; i++)
	{
		cout << niz[i] << ' ';
	}
	cout << endl;
}


void arearadius(double radius, double &result) {

	result = pi * radius * radius;

}


void calcArea(const double* const pi, const double* const radius, double* const area) { //moze da se promeni vrednost podataka ali ne adresa od area

	if (pi && radius && area)
	{
		*area = (*pi) * (*radius) * (*radius);

	}

}
*/


class Aggregate1 {
public:
	int n;
	double pi;

};

struct Aggregate2
{
	char hello[6];
	int years[3];
	string word;

};


class Circle {

private:
	 double pi;
	double radius;
public:

	

	Circle(double InputRadius) : radius(InputRadius), pi(3.1416) {
	}

	double getCirc() {
		return 2 * pi * radius;
	}
	double getArea() {
		return pi * radius * radius;
	}



};

class Fish {

public:

	void Svim() {

		cout << "Fish swims " << endl;
	}

	void Svim(bool isFreshWater) {
		if (isFreshWater)
		{
			cout << "Swims in lake" << endl;
		}
		else
		{
			cout << "Swims in sea" << endl;
		}


	}



};


class Tuna : public Fish { //nasledjivanje iz klase fish

public:
	//nasledjeno je sve iz klase fish
	//funkcija svim() 
	//i mogu se jos dodavati metoda

	using Fish::Svim;

	/*
	void Svim(bool isFreshWater) {
		Fish::Svim(isFreshWater);

	}
	*/

	void Svim() {
		cout << "Tuna swims real fast" << endl;

	}



};

class Carp : public Fish {

public:


	void Svim() {
		cout << "Carp swims real slow" << endl;
		Fish::Svim();


	}


};


class FishDummy {

public:
	FishDummy() {

		cout << "Fish d const" << endl;
	}

	~FishDummy()
	{
		cout << "Fish d dest" << endl;

	}


};


class Fish2 {

protected:
	FishDummy dummy;

public:
	Fish2() {

		cout << "Fish const" << endl;
	}

	~Fish2()
	{
		cout << "Fish dest" << endl;
	}


};

class TunaDummy {

public:
	TunaDummy() {

		cout << "Tuna d const" << endl;
	}
	~TunaDummy()
	{
		cout << "Tuna d dest" << endl;
	}


};


class Tuna2 : public Fish2 {
private:
	TunaDummy dummy;
public:
	Tuna2() {

		cout << "Tuna const" << endl;
	}

	~Tuna2()
	{
		cout << "Tuna dest" << endl;
	}


};


class Motor {

public:
	void Switch() {

		cout << "Motor ON" << endl;
	}
	void fuel() {
		cout << "Fuel in cylinders" << endl;
	}
	void vroom() {
		cout << "Vroooom" << endl;
	}

};

class Car : protected Motor {

public:
	void Move() {
		Switch();
		fuel();
		vroom();

	}


};


class SportsCar : protected Car {

public:
	void Move() {
		Switch();
		fuel();
		vroom();
		vroom();
		vroom();


	}



};

class Mammal {

public:
	void f1() {
		cout << "Atributes of mammal" << endl;

	}


};


class Bird {

public:
	void f2() {
		cout << "Atributes of bird" << endl;

	}

};


class Repitle {
public:
	void f3() {
		cout << "Atributes od reptile" << endl;

	}


};

class Platypus : public Mammal, public Bird, public Repitle {

public:
	void Swim() {
		cout << "Atributes of platypus itself" << endl;
	}


};







int main() {
	
	Platypus freak;
	freak.f1();
	freak.f2();
	freak.f3();
	freak.Swim();




	return 0;
}