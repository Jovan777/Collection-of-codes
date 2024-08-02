#ifndef _izraz_h_
#define _izraz_h_


#include <iostream>
using namespace std;

namespace Izrazi {

	class Izraz {


	public:
		virtual ~Izraz() = default;
		virtual double vredn() const = 0;
		virtual Izraz* kopija() const = 0;
	private:
		virtual void pisi(ostream& it) const = 0;
		friend ostream& operator<<(ostream& it, const Izraz& iz) {
			iz.pisi(it);
			return it;

		}







	};

}

#endif // !_izraz_h_
