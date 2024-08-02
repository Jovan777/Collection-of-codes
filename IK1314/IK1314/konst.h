#ifndef _konst_h_
#define _konst_h_



#include "izraz.h"


namespace Izrazi {


	class Konst : public Izraz {

		double vrd;
		void pisi(ostream& it) const override {
			it << vrd;
		}
		void operator=(const Konst&) {};
	public:
		Konst(double vr = 0) : vrd(vr) {};
		double vredn() const override {
			return vrd;
		}
		Konst* kopija() const override {
			return new Konst(*this);
		}





	};






}


#endif // !_konst_h_

