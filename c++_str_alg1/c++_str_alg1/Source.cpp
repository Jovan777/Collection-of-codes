#include <iostream>
#include<vector>
#include<list>
#include<algorithm>
#include <deque>
#include <stack>
#include <queue>
#include <functional>
#include <bitset>


using namespace std;



template<typename T>
bool isEven(const T& elem) {

	return (elem % 2) == 0;

}


template<typename T>
void Display(const T& elem) {

	for ( auto i =elem.cbegin(); i !=elem.cend(); i++)
	{
		cout << *i << " ";
	}
	cout << endl<< "Number of elements : " << elem.size() << endl;
}

template<typename T>
struct Disp {
	int count;

	Disp() : count(0) {};

	void operator() (const T& elem) {
		count++;
		cout << elem << " ";

	}

};

template<typename T>
class smart_ptr {
private: 
	T* rawPtr;
public:
	smart_ptr(T* pData) : rawPtr(pData){}
	~smart_ptr()
	{
		delete rawPtr;
	}

	smart_ptr(const smart_ptr& anotherSP);

	smart_ptr& operator = (const smart_ptr& anotherSP);


	T& operator * ()const {
		return *(rawPtr);

	}

	T* operator ->() const{
		return rawPtr;
	}

};




class Fish {
public:

	Fish() { cout << "Fish: Constructed!" << endl; }
	~Fish() { cout << "Fish: Destructed!" << endl; }

	void virtual Swim()  { cout << "Fish swims in water" << endl; }



};
#include <memory>


class Carp : public Fish {

public:
	void Swim() {
		cout << "Carp swim" << endl;

	}



};


void MakeFishSwim(const unique_ptr<Fish>& inFish)
{
	inFish->Swim();
}





class Person {

public:
	int age;
	bool female;

	bool operator < (const Person& another) {

		bool bRet = false;
		if (age>another.age)
		{
			bRet = true;
		}
		else if (female && another.female) {
			bRet = true;
		}


		return bRet;
	}


};


struct  CaseSensitive {

	bool operator() (const string& str1, const string& str2) {

		string copy1(str1), copy2(str2);

		transform(copy1.begin(), copy1.end(), copy1.begin(), ::tolower);
		transform(copy2.begin(), copy2.end(), copy2.begin(), ::tolower);

		return (copy1 < copy2);

	}




};



int main() {

	vector<int> vec{ 1,2,3,4,5, 3 };
	int n;
	cout << "Enter n: " << endl;
	n = 3;

	auto found = find(vec.begin(), vec.end(), n);
	if (found!=vec.cend())
	{
		cout << "Number " << n << " found at position [" << distance(vec.begin(), found) << "]" << endl;

	}
	cout << endl;

	auto paran = find_if(vec.begin(), vec.end(), [](int n) {return (n % 2) == 0; });
	if (paran!=vec.cend())
	{
		cout << "First even number is : " << *paran << endl;

	}

	auto numThree = count(vec.begin(), vec.end(), 3);
	cout << "Number of 3 in vector is " << numThree << endl;


	auto numEven = count_if(vec.cbegin(), vec.cend(), isEven<int>);
	cout << "Number of even elements in vector is : " << numEven << endl;
	cout << "Number of odd elements in vector is : " <<vec.size()- numEven << endl;


	vector<int> vec2{ 2017, 0,-1,42,10101,25,7,7,7 };
	list<int> lista{ -1,42,10101 };
	cout << endl;
	Display(vec2);
	Display(lista);

	auto range = search(vec2.cbegin(), vec2.cend(), lista.cbegin(), lista.cend());
	if (range!=vec2.end())
	{
		cout << "Sequence in list found in vector at position " << distance(vec2.cbegin(), range) << endl;

	}
	else
	{
		cout << "There is no such sequence in vector" << endl;
	}


	auto part = search_n(vec2.cbegin(), vec2.cend(), 3, 7);
	if (part!=vec2.end())
	{
		cout << "Sequence  found in vector at position " << distance(vec2.cbegin(), part) << endl;

	}
	else
	{
		cout << "There is no such sequence in vector" << endl;
	}


	vector<int> vec3(3);

	fill(vec3.begin(), vec3.end(), 7);

	vec3.resize(6);

	fill_n(vec3.begin() + 3, 3, 3);

	Display(vec3);

	cout << endl;

	vector<int> vec4(5);
	srand(time(NULL));

	generate(vec4.begin(), vec4.end(), rand);

	Display(vec4);

	cout << endl;
	list<int> lista2(5);
	generate_n(lista2.begin(), 3, rand);
	Display(lista2);


	vector<int> vec5{ 2017,0,-1,42,10101,25 };
	Disp<int> functor = for_each(vec5.cbegin(), vec5.cend(), Disp<int>());
	cout << functor.count << " elements displayed" << endl;

	vector<char> vec6{ 'a', 'b', 'c' };
	int numC = 0;
	for_each(vec6.begin(), vec6.end(), [&numC](char c) {cout << c << ' '; numC++; });

	cout << endl;
	cout <<"Number of chars : "<<numC << endl;


	string str1("THIS iS new String");

	cout << str1 << endl;

	string lowerCopy;
	lowerCopy.resize(str1.size());

	transform(str1.cbegin(), str1.cend(), lowerCopy.begin(), ::tolower);
	cout << lowerCopy << endl;


	vector<int> vec7{ 1,2,3,4,5,6,8 };

	vector<int> vec8(vec7.size(), -1);

	deque<int> res1(vec7.size());

	transform(vec7.begin(), vec7.end(), vec8.begin(), res1.begin(), plus<int>());

	cout << endl;
	Display(res1);
	cout << endl;



	list<int> lista3{ 2017, 0,-1,42,10101,25 };
	Display(lista3);


	vector<int> vector1;
	vector1.resize(lista3.size() * 2);

	auto lastELem = copy(lista3.begin(), lista3.end(), vector1.begin());

	cout << endl;
	Display(vector1);

	copy_if(lista3.begin(), lista3.end(), lastELem,
		[](int n) {return ((n % 2) != 0); });

	Display(vector1);

	cout << endl;


	auto newEnd = remove(vector1.begin(), vector1.end(), 0);
	Display(vector1);

	vector1.erase(newEnd, vector1.end());
	Display(vector1);

	newEnd = remove_if(vector1.begin(), vector1.end(),
		[](int n) {return ((n % 2) != 0); });

	vector1.erase(newEnd, vector1.end());


	Display(vector1);


	vector<int> vec11(6);
	fill(vec11.begin(), vec11.begin() + 3, 8);

	fill_n(vec11.begin() + 3, 3, 5);

	Display(vec11);

	random_shuffle(vec11.begin(), vec11.end());

	Display(vec11);
	replace(vec11.begin(), vec11.end(), 5, 8);

	Display(vec11);

	replace_if(vec11.begin(), vec11.end(),
		[](int n) {return ((n % 2) == 0); }, 7);

	Display(vec11);






	vector<string> names{ "John", "jack", "sean", "Anna" };

	names.push_back("jack");

	Display(names);

	sort(names.begin(), names.end());
	Display(names);


	bool find = binary_search(names.begin(), names.end(), "John");

	if (find)
	{
		cout << "Name John was found" << endl;
	}
	else
	{
		cout << "Name not in the vector" << endl;
	}

	auto kraj = unique(names.begin(), names.end());
	names.erase(kraj, names.end());
	Display(names);

	vector<int> vec22{ 2017,0,-1,42,10101,25 };

	vector<int> vec2copy(vec22);

	Display(vec2copy);

	partition(vec22.begin(), vec22.end(), [](int n) {return ((n % 2) == 0); });

	stable_partition(vec2copy.begin(), vec2copy.end(), [](int n) {return ((n % 2) != 0); });

	Display(vec22);
	Display(vec2copy);

	names.push_back("Brad");


	sort(names.begin(), names.end());
	Display(names);


	auto minPos = lower_bound(names.begin(), names.end(), "Brad");
	auto maxPos = upper_bound(names.begin(), names.end(), "Brad");


	cout << "Min pos where Brad can be inserted is : " << distance(names.begin(), minPos) << endl;
	cout << "Max pos where Brad can be inserted is : " << distance(names.begin(), maxPos) << endl;

	names.insert(minPos, "Brad");
	Display(names);


	stack<int> stek1;
	stek1.push(25);
	stek1.push(10);
	stek1.push(-1);
	stek1.push(5);

	cout << "Top of stack is : " << stek1.top() << endl;
	while (stek1.size()!=0)
	{
		cout << "Popping topmost element in stack : " << stek1.top() << endl;
		stek1.pop();

	}

	if (stek1.size()==0)
	{
		cout << "Stack is empty" << endl;
	}



	queue<int> red1;

	red1.push(1);
	red1.push(2);
	red1.push(3);
	red1.push(4);
	red1.push(5);

	cout << "Front of queue : " << red1.front() << endl << "Back of queue : " << red1.back() << endl;

	while (red1.size()!=0)
	{
		cout << "Deleting element from queue : " << red1.front() << endl;
		red1.pop();

	}

	if (red1.size()==0)
	{
		cout << "Queue is empty" << endl;
	}

	priority_queue<int, vector<int>, greater<int>> pq;


	pq.push(10);
	pq.push(5);
	pq.push(-1);
	pq.push(20);

	while (pq.size()!=0)
	{

		cout << "Deleting element from pq : " << pq.top() << endl;
		pq.pop();

	}

	if (pq.size()==0)
	{
		cout << "PQ is empty" << endl;
	}

	vector<bool> flags(3);
	flags[0] = true;
	flags[1] = true;
	flags[2] = false;


	flags.push_back(true);

	for (int i = 0; i < flags.size(); i++)
	{
		cout << flags[i] << ' ';
	}

	flags.flip();
	cout << endl;

	for (int i = 0; i < flags.size(); i++)
	{
		cout << flags[i] << ' ';
	}


	unique_ptr<Fish> smartFish(new Carp);
	smartFish->Swim();
	MakeFishSwim(smartFish);









	return 0;
}


