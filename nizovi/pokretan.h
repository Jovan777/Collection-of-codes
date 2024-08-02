#ifndef _pokretan_h_
#define _pokretan_h_

class Pokretan {


public:
	virtual ~Pokretan() = default;
	virtual Pokretan& proteklo(double dt) = 0;

};






#endif // !_pokretan_h_
