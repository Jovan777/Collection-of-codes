#ifndef sekvenca_h_
#define sekvenca_h_


using namespace std;

#include <iostream>
#include <string>




template<typename T>
class Sekvenca
{
	struct Elem {
		T data;
		Elem* sled;
		Elem(T d, Elem* s = nullptr) : data(d), sled(s) {};

	};

	Elem* prvi, * posl;

	void kopiraj(const Sekvenca& s);
	void premesti(Sekvenca& s) {
		prvi = s.prvi;
		posl = s.posl;
		s.prvi = nullptr;
		s.posl = nullptr;

	}
	void brisi() {
		while (prvi)
		{
			Elem* old = prvi;
			prvi = prvi->sled;
			delete old;
		}

	}




public:

	Sekvenca()  {
		prvi = nullptr; posl = nullptr;
	};
	Sekvenca(const Sekvenca& s) {
		kopiraj(s);
	}
	Sekvenca(Sekvenca&& s) {
		premesti(s);
	}
	~Sekvenca()
	{
		brisi();
	}
	
	Sekvenca& operator=(const Sekvenca& s) {
		if (this!=&s)
		{
			brisi();
			kopiraj(s);

		}
		return *this;
	}


	Sekvenca& operator=( Sekvenca&& s) {
		if (this != &s)
		{
			brisi();
			premesti(s);

		}
		return *this;
	}

	void dodaj(T t) {
		posl = (prvi ? posl->sled : prvi) = new Elem(t);
	}
	
	T& pocetak() const {
		return prvi->data;
	}

	int duz() const {
		int n = 0;
		for (Elem* temp = prvi; temp ; temp=temp->sled)
		{
			n++;
		}
		return n;
	}

	T& operator[](int i) {
		int n = 0;
		for (Elem* temp = prvi; temp ; temp=temp->sled, n++)
		{
			if (n==i)
			{
				return temp->data;
			}
		}
		

	}





};

#endif // !sekvenca_h_
