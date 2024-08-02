#include <iostream>
#include <cstdlib>

using namespace std;


class Red {

	struct Elem {
		int pod;
		Elem* sled;
		Elem(int p, Elem* s = nullptr) : pod(p), sled(s) {};
	};

	Elem* prvi, * posl;
	int duz;
	void kopiraj(const Red& r);
	void premesti(Red& r) {
		prvi = r.prvi;
		posl = r.posl;
		duz = r.duz;
		r.posl = nullptr;
		r.prvi = nullptr;

	}

	void brisi();

public:
	Red() {
		prvi = posl = nullptr;
		duz = 0;
	}

	Red(int a) {
		prvi = posl = new Elem(a);
		duz = 1;
	}
	Red(const Red& r) {
		kopiraj(r);
	}
	Red(Red&& r) {
		premesti(r);
	}
	~Red()
	{
		brisi();
	}

	Red& operator=(const Red& r) {
		if (this!=&r)
		{
			brisi();
			kopiraj(r);
		}
		return *this;
	}
	Red& operator=(Red&& r) {
		if (this!=&r)
		{
			brisi();
			premesti(r);
		}
		return *this;
	}

	int duzina() const {
		return duz;
	}
	bool prazan() const {
		return !duz;
	}
	int uzmi();
	Red& operator+=(const Red& r);
	Red operator+(const Red& r) const {
		return Red(*this) += r;
	}
	int vodeci() const {
		if (!prvi)
		{
			exit(1);
		}
		else
		{
			return prvi->pod;
		}
	}

	Red operator-(int k) const;
	Red& operator-=(int k) {
		return *this = *this - k;
	}
	Red& operator~() {
		brisi();
		return *this;
	}



};