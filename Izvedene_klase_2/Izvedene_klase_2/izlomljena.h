#ifndef _izlomljena_h_
#define _izlomljena_h_
#include "linija.h"

#include "tacka6.h"




namespace Linije {

	class Izlomljena : public Linija{

		

	private:

		void kopiraj(const Tacka*, int);
		void premesti(Izlomljena& lin) {
			tem = lin.tem;
			n = lin.n;
			lin.tem = nullptr;
		}
		void brisi() {
			delete[] tem;
		}

	protected:
		Tacka* tem;
		int n;



	public:
		Izlomljena(const Tacka* niz, int k) {
			kopiraj(niz, k);
		}

		Izlomljena(const Izlomljena& lin) : Linija(lin) {
			kopiraj(lin.tem, lin.n);
		}

		Izlomljena(Izlomljena&& lin) : Linija(move(lin)) {
			premesti(lin);
		}

		~Izlomljena()
		{
			brisi();
		}
		
		Izlomljena& operator=(const Izlomljena& lin) { // Dodela vrednosti
			if (this != &lin)                            //   kopiranjem.
			{
				brisi(); Linija::operator=(lin); kopiraj(lin.tem, lin.n);
			}
			return *this;
		}
		Izlomljena& operator=(Izlomljena&& lin) {      // Dodela vrednosti
			if (this != &lin)                            //   premeštanjem.
			{
				brisi(); Linija::operator=(move(lin)); premesti(lin);
			}
			return *this;
		}
		double duzina() const override;           // Dužina linije.
		Izlomljena* kopija() const& override      // Kopija linije kopiranjem.
		{
			return new Izlomljena(*this);
		}
		Izlomljena* kopija() && override          // Kopija linije premeštanjem.
		{
			return new Izlomljena(move(*this));
		}
	private:
		virtual void pisi(ostream& it) const override { // Pisanje linije.
			Linija::pisi(it); it << "[izlomljena: ";
			Tacka::pisiNiz(it, tem, n); it << ']';
		}



	};




}





#endif // !_izlomljena_h_
