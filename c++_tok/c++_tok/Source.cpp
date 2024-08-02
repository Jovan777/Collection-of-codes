#include <iostream>
#include<vector>
#define _CRT_SECURE_NO_WARNINGS
#include<list>
#include<algorithm>
#include <deque>
#include <stack>
#include <queue>
#include <functional>
#include <bitset>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace::std;


struct Human
{
	Human() {};
	int age;
	char name[30];
	char DOB[20];


	Human(const char* inName, int inAge, const char* inDob) : age(inAge) {

		strcpy_s(name, inName);
		strcpy_s(DOB, inDob);

	}


};


class CustomExc : public std::exception {

	string reason;
public:
	CustomExc(const char* why) : reason(why){}


	virtual const char* what() const throw() {
		return reason.c_str();
	}


};



double Divide(double dividend, double divisor)
{
	if (divisor == 0) {
		throw CustomExc("Custom exc : cannot divide by 0");

	}
	return (dividend / divisor);
}

int main() {

	ofstream MyFile;
	MyFile.open("HelloFile.txt", ios_base::out);

	if (MyFile.is_open())
	{

		cout << "File open succesful" << endl;

		MyFile << "Text file" << endl;
		MyFile << "Hello world" << endl;

		cout << "Finished writing" << endl;
		MyFile.close();

	}




	ifstream newFile;
	newFile.open("HelloFile.txt", ios_base::in);

	if (newFile.is_open())
	{
		cout << "File open succesful. It contains : " << endl;
		string contents;

		while (newFile.good())
		{
			getline(newFile, contents);
			cout << contents << endl;

		}
		cout << "Finished reading" << endl;
		newFile.close();


	}
	else
	{
		cout << "open failed" << endl;
	}


	cout << endl << endl;

	Human Input("Sidharta Rao", 101, "May 1916");

	ofstream fsOut("MyBinary.bin", ios_base::out | ios_base::binary);

	cout << "Writing object in binary file" << endl;
	fsOut.write(reinterpret_cast<const char*>(&Input), sizeof(Input));
	fsOut.close();

	ifstream fsIn("MyBinary.bin", ios_base::in, ios_base::binary);

	if (fsIn.is_open())
	{

		Human person;
		fsIn.read((char*)&person, sizeof(person));
		cout << "Reading from binary file" << endl;
		cout << "Name : " << person.name << endl;
		cout << "Age : " << person.age << endl;
		cout << "Dob : " << person.DOB << endl;


	}
	cout << endl << endl;

	int n = 777;

	stringstream convert;
	convert << n;
	
	string inp;
	convert >> inp;
	cout << "Integer : " << n << endl;
	cout << "String : " << inp << endl;

	stringstream another;
	another << inp;
	int copy;
	another >> copy;
	cout << "Copy int : " << copy << endl;


	cout << "Enter dividend: ";
	double dividend = 0;
	cin >> dividend;
	cout << "Enter divisor: ";
	double divisor = 0;
	cin >> divisor;

	try
	{
		cout << "Result is: " << Divide(dividend, divisor);
	}
	catch (exception& exp)
	{
		cout << exp.what() << endl;

	}



	return 0;
}


