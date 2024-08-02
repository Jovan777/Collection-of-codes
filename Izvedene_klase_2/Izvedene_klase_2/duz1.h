#ifndef  _duz1_h_
#define _duz1_h_

#include "linija.h"
#include "tacka6.h"
#include <cmath>
#include <utility>
using namespace std;

namespace Linije {


	class Duz : public Linija {

		Tacka A, B;

	public:
		explicit Duz(const Tacka& A = Tacka(-1, -1), const Tacka& B = Tacka(1, 1)) : A(A), B(B) {};

		double duzina() const override {

			return sqrt(pow(A.aps() - B.aps(), 2) + pow(A.ord() - B.ord(), 2));

		}
		Duz* kopija() const& override               // Kopija duži kopiranjem.
		{
			return new Duz(*this);
		}
		
		Duz* kopija() && override                   // Kopija duži premeštanjem.
		{
			return new Duz(move(*this));
		}

	private:
		void pisi(ostream& it) const override {
			Linija::pisi(it);
			it << " [ duz : A" << A << " , B" << B << " ]";

		}



	};




}








#endif // ! _duz1_h_
