#include <iostream>

using std::cin;using std::cout;
const double FAKTOR = 3.14159 / 180;


class Ugao {
private: 
	double ugao;

public:

	Ugao(double u = 0) {
		ugao = u;
	}

	Ugao(int stp, int min, int sek=0) {
		ugao = ((sek / 60 + min) / 60 + stp) * FAKTOR;
	}

	double rad() const { return ugao; }
	int stp() const{
		return int(ugao / FAKTOR);
	}

	int min() const{
		return int(ugao / FAKTOR*60)%60;

	}
	int sek() const {
		return int(ugao / FAKTOR * 3600) % 60;

	}


	void razlozi(int& st, int& mi, int& se) {
		st = stp();
		mi = min();
		se = sek();
	}

	Ugao& dodaj(Ugao u) {
		ugao += u.ugao;
		return *this;
	}


	Ugao& pomnozi(double a) {
		ugao *= a;
		return *this;
	}


	void citaj() {
		cin >> ugao;

	}
	void citajStep() {
		int step, min, sek;
		cin >> step >> min >> sek;
		*this = Ugao(step, min, sek);

	}


	void pisi() const {
		cout << ugao;
	}

	void pisiStep() const {
		cout << "( " << this->stp() << " , " << this->min() << " , " << this->sek() << " )";
	}

};