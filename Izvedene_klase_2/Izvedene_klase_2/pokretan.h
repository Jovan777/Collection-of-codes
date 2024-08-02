// pokretan.h - Apstraktna klasa pokretnih objekata.

#ifndef _pokretan_h_
#define _pokretan_h_

class Pokretan {
public:
	virtual ~Pokretan() = default;                 // Virtuelan destruktor.
	virtual Pokretan& proteklo(double dt) = 0;     // Proteklo je vreme dt.
};

#endif
