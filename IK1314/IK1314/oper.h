#ifndef _oper_h_
#define _oper_h_


#include "izraz.h"
#include <compare>
#include <cmath>

using namespace std;


namespace Izrazi {
	class Oper : public Izraz {


	protected:
		Izraz* a, * b;
		void pisi(ostream& it, char op) const {
			it<<"(" << *a << op << *b << ")";
		}

	private:
		void kopiraj(const Oper& o)   {
			a = o.a->kopija();
			b = o.b->kopija();
		}

		void brisi() {
			delete a; delete b;
		}

	
		;
	public:
		Oper(const Izraz& a, const Izraz& b) : a(a.kopija()), b(b.kopija()) {};

		Oper(const Oper& o) {
			kopiraj(o);
		}

		Oper& operator=(const Oper& o) {
			if (this!=&o)
			{
				brisi();
				kopiraj(o);
			}
			return *this;
		}
		
		~Oper()
		{
			brisi();
		}



	};

	class Zbir : public Oper {
		void pisi(ostream& it) const override {
			return Oper::pisi(it, '+');
		}

	public:
		Zbir(const Izraz& a, const Izraz& b) : Oper(a, b) {};

		double vredn() const override {
			return a->vredn() + b->vredn();
		}

		Zbir* kopija() const override {
			return new Zbir(*this);
		}



	};

	class Razlika : public Oper {
		void pisi(ostream& it) const override {
			return Oper::pisi(it, '-');
		}

	public:
		Razlika(const Izraz& a, const Izraz& b) : Oper(a, b) {};

		double vredn() const override {
			return a->vredn() - b->vredn();
		}

		Razlika* kopija() const override {
			return new Razlika(*this);
		}



	};


	class Proizv : public Oper {
		void pisi(ostream& it) const override {
			return Oper::pisi(it, '*');
		}

	public:
		Proizv(const Izraz& a, const Izraz& b) : Oper(a, b) {};

		double vredn() const override {
			return a->vredn() * b->vredn();
		}

		Proizv* kopija() const override {
			return new Proizv(*this);
		}



	};

	class Kolic : public Oper {
		void pisi(ostream& it) const override {
			return Oper::pisi(it, '/');
		}

	public:
		Kolic(const Izraz& a, const Izraz& b) : Oper(a, b) {};

		double vredn() const override {
			return a->vredn() / b->vredn();
		}

		Kolic* kopija() const override {
			return new Kolic(*this);
		}



	};

	class Step : public Oper {
		void pisi(ostream& it) const override {
			return Oper::pisi(it, '^');
		}

	public:
		Step(const Izraz& a, const Izraz& b) : Oper(a, b) {};

		double vredn() const override {
			return pow(a->vredn() ,  b->vredn());
		}

		Step* kopija() const override {
			return new Step(*this);
		}



	};

	inline Zbir operator+(const Izraz& a, const Izraz& b) {
		return Zbir(a, b);
	}

	inline Razlika operator-(const Izraz& a, const Izraz& b) {
		return Razlika(a, b);
	}

	inline Proizv operator*(const Izraz& a, const Izraz& b) {
		return Proizv(a, b);
	}
	inline Kolic operator/(const Izraz& a, const Izraz& b) {
		return Kolic(a, b);
	}
	inline Step operator^(const Izraz& a, const Izraz& b) {
		return Step(a, b);
	}

	inline bool operator<(const Izraz& a, const Izraz& b) {
		return a.vredn() < b.vredn();
	}
	inline bool operator>(const Izraz& a, const Izraz& b) {
		return !(a < b);
	}
	inline bool operator==(const Izraz& a, const Izraz& b) {
		return a.vredn() == b.vredn();
	}
	inline bool operator <=(const Izraz& a, const Izraz& b) {
		return a.vredn() <= b.vredn();
	}





}





#endif // !_oper_h_
