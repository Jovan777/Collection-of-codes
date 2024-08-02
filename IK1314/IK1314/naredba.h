#ifndef _naredba_h_
#define _naredba_h_

#include <iostream>
#include <iomanip>

using namespace std;

static int nv = 0;

namespace Naredbe {
	class Naredba {


	public:
		virtual ~Naredba() = default;
		virtual Naredba* kopija() const = 0;
		virtual void izvrsi() const = 0;
		int nivo = 0;


	protected:
		virtual void pisi(ostream& it) const {
			it << setw(nivo * 2) << "";
		}

		friend ostream& operator<<(ostream& it, const Naredba& nar) {
			nar.pisi(it);
			return it;
		}






	};




}



#endif // !_naredba_h_
