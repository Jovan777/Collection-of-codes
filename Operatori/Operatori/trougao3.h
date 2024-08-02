#include "tacka3.h"

#include <iostream>
using namespace std;


class Trougao {

	Tacka A, B, C;

public:
	explicit Trougao(
		const Tacka& A = Tacka(),
		const Tacka& B = Tacka(1, 0),
		const Tacka& C = Tacka(0, 1)
	) : A(A), B(B), C(C) {};

	Tacka dohvA() const {
		return A;
	}

	Tacka dohvB() const {
		return B;
	}
	Tacka dohvC() const {
		return C;
	}

	double P() const {

		double a = A - B;
		double b = B - C;
		double c = C - A;
		double s = (a + b + c) / 2;
		return sqrt(s * (s - a) * (s - b) * (s - c));


	}

	bool operator==(const Trougao& t2) {
		return A == t2.A && B == t2.B && C == t2.C;
	}

	bool operator!=(const Trougao& t2) {
		return !(*this == t2);
	}

	friend ostream& operator<<(ostream& it, const Trougao& t) {
		return it << "[ " << t.A << " , " << t.B << " , " << t.C << " ]";
	}






};