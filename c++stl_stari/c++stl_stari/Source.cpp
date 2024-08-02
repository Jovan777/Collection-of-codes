#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <forward_list>

using namespace std;



int getNumChars(string& input, char chToFind) {
	int found=0;
	auto charOffset = input.find(chToFind);
	while (charOffset != string::npos)
	{
		found++;

		charOffset = input.find(chToFind, charOffset + 1);

	}


	return found;
}





bool sortPredicate(const int& lhs, const int& rhs) {
	return lhs > rhs;

}


/*
case '4':
	cout << "Enter n" << endl;
	cin >> n;
	vector<int>::iterator found = find(vec.begin(), vec.end(), n);
	if (found != vec.end())
	{
		cout << "Number " << n << " is in vector" << endl;
	}
	else
	{
		cout << "Number " << n << " is not in vector" << endl;
	}
	break;

*/

char options() {

	cout << "Enter an option: " << endl;
	cout << "1. Enter lenght and breadth: " << endl;
	cout << "2. Query a value given an index" << endl;
	cout << "3. Display dimensions of all packeges" << endl;
	cout << "4. Is entered element in vector?" << endl;
	cout<<"Quit"<<endl;

	char c;
	cin >> c;
	return c;
}

template<typename T>
void DisplayDQ(deque<T> deq) {

	for (auto i = deq.cbegin(); i !=deq.cend(); i++)
	{
		cout << *i << " ";

	}


}


class Dimensions {
private:
	int length, breadth;
	string strOut;
	friend void displayDimension(Dimensions vec);


public:
	Dimensions(int Len, int Brd) : length(Len), breadth(Brd){}

	



};

void displayDimension(Dimensions vec) {

	cout << "Length: " << vec.length << " , Breadth: " << vec.breadth << endl;

}




template <typename T>
void Display(const T& container) {

	for (auto i = container.cbegin(); i !=container.cend(); i++)
	{
		cout << i->first<<" "<<i->second << endl;
	}
	cout << endl;

}


struct Contact {

	string name;
	string phone;
	string display;

	Contact(const string& inName, const string& inPhone) {
		name = inName;
		phone = inPhone;
		display = name + " " + phone;

	}


	bool operator ==(const Contact& item) const {
		return (this->phone == item.phone);

	}


	bool operator <(const Contact& item) const {
		return (this->phone < item.phone);

	}

	operator const char* () const {

		return display.c_str();
	}

};

bool sortOnPhone(const Contact& item1, const Contact& item2) {

	return (item1.phone < item2.phone);
}


struct Dictionary
{
	string word;
	string meaning;


	Dictionary(const string& rec, const string& znacenje) : word(rec), meaning(znacenje) {}

	bool operator < (const Dictionary& another) {

		return (word < another.word);

	}

	bool operator == (const Dictionary & another) {
		return (this->word == another.word);
	}



};


struct PredIgnoreCase {

	bool operator()(const string& str1, const string& str2)const {



		string str1NoCase(str1);
		string str2NoCase(str2);


		transform(str1.begin(), str1.end(), str1NoCase.begin(), ::tolower);
		transform(str2.begin(), str2.end(), str2NoCase.begin(), ::tolower);


		return (str1NoCase < str2NoCase);

	}




};


struct PredIgnoreCase1
{
	bool operator()(const string& str1, const string& str2) const
	{
		string str1NoCase(str1), str2NoCase(str2);
		transform(str1.begin(), str1.end(), str1NoCase.begin(), ::tolower);
		transform(str2.begin(), str2.end(), str2NoCase.begin(), ::tolower);

		return(str1NoCase < str2NoCase);
	};
};


template<typename T>
struct DisplayElement {

	int count;

	DisplayElement() : count(0) {};


	void operator () (const T& element) {
		count++;
		cout << element << ' ';
	}



};


template <typename T>
struct IsMultiple {

	T divisor;

	IsMultiple(const T& div) : divisor(div) {}

	bool operator () (const T& element) {
		return (element % divisor) == 0;

	}



};

template<typename T>
class Multiply {

public: 
	T operator ()(const T& elem1, const T& elem2) {

		return elem1 * elem2;
	}


};


class compareString {

public: 
	bool operator () (const string& str1, const string& str2) {

		string lower1;
		string lower2;


		lower1.resize(str1.size());
		lower2.resize(str2.size());

		transform(str1.begin(), str1.end(), lower1.begin(), ::tolower);
		transform(str2.begin(), str2.end(), lower2.begin(), ::tolower);

		return (lower1 < lower2);

	}



};


template<typename T>
struct Double {

	void operator ()(const T element) {
		cout << element * 2 << " ";

	}


};


template<typename T>
class sortAsc {
public:

	bool operator () (const T& num1, const T& num2) const{
		return num1 < num2;
	}



};



template<typename T>
void displayVec(const T& cont) {
	for (int i = 0; i < cont.size(); i++)
	{
		cout << cont[i] << " ";
	}
	cout << endl;
}


template<typename T>
void displayString(const T& element) {

	for (auto i = element.cbegin(); i !=element.cend(); i++)
	{
		cout << *i << endl;
	}
}



int main() {

	vector<int> vec{ 25,26,27,28,29 };
	for_each(vec.begin(), vec.end(), [](const int& elem) {cout << elem << " "; });
	vector<int> vec2{ 25,26,27,28,29 };



	int div = 4;
	cout << endl;

	auto element = find_if(vec.begin(), vec.end(), [div](int divinded) {return (divinded % div) == 0; });
	if (element!=vec.end())
	{
		cout << *element << endl;
	}
	cout << endl;

	vector<int> res;
	res.resize(vec.size());

	transform(vec.begin(), vec.end(), vec2.begin(), res.begin(),
		[](int a, int b) {return a * b; });

	displayVec(res);

	
	vector<string> names{ "jim", "Jack", "Anna", "Sam" };




	sort(names.begin(), names.end(),
		[](const string& str1, const string& str2)->bool
		{
			string lower1;
			string lower2;

			lower1.resize(str1.size());
			lower2.resize(str2.size());

			transform(str1.begin(), str1.end(), lower1.begin(), ::tolower);
			transform(str2.begin(), str2.end(), lower2.begin(), ::tolower);

			return (lower1 < lower2);

		});


	displayString(names);
	cout << endl;


	int num = 5;
	for_each(res.begin(), res.end(),
		[num](int& elem) {elem += num; });

	displayVec(res);

	sort(res.begin(), res.end(),
		[](int num1, int num2) {return (num1 > num2); });

	cout << endl;
	displayVec(res);



	return 0;
};