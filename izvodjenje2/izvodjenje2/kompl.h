#ifndef kompl_h
#define kompl_h


#include "objekat.h"
#include <utility>
#include <iostream>

using namespace std;




class Kompl : public Objekat
{
	double re, im;

	bool jednako(const Objekat& obj) const override{
		return re == ((Kompl&)obj).re && im == ((Kompl&)obj).im;
	}
	
	

	void pisi(ostream& it) const override {
		it << "[" << re << " + j" << im << "]";
	}
	void citaj(istream& ut) override {
		char zn;
		ut >> zn >> re >> zn >> im >> zn;
	 }

	

public:
	Kompl(double ree = 0, double imm = 0) : re(ree), im(imm) {};
	string getClass() const override {
		return "Kompleksni";
	}

	Kompl* kopija() const& override {
		return new Kompl(*this);
	}

	Kompl* kopija() && override {
		return new Kompl(move(*this));
	}


};

#endif // !kompl_h
