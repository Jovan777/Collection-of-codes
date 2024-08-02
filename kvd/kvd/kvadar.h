#ifndef _kvadar_h_
#define _kvadar_h_



static double Vuk;
static double  Vmax;




class Kvadar
{
	


	double a, b, c;



public:

	static double dohvVMax() { return Vmax; }
	static bool postaviVmax(double max) {
		if (max<Vuk)
		{
			return false;
		}
		Vmax = max;
		return true;
	}






};

#endif // !_kvadar_h_
