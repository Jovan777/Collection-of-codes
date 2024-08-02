#ifndef _tacka6_h_
#define _tacka6_h_

#include <iostream>
using namespace std;


namespace Linije {

	class Tacka {

		double x, y;
	public :
		Tacka(double xx = 0, double yy = 0) : x(xx), y(yy) {};
		double aps() const { return x; }
		double ord() const { return y; }

		friend ostream& operator<<(ostream& it, const Tacka& t) {
			return it << "( " << t.x << " , " << t.y << " )";
		}
		static void pisiNiz(ostream& it, const Tacka* niz, int duz) {
			it << " ( ";
			for (int i = 0; i < duz; i++)
			{
				if (i)
				{
					it << " , ";
					it << niz[i];
				}

			}
			it << " )";

		}

	};



}




#endif // !_tacka6_h
