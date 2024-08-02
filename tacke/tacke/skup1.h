

class Skup {
private:
	int vel;
	double* niz;

	void kopiraj(const Skup&);
	void premesti(Skup& s) {
		vel = s.vel;
		niz = s.niz;
		s.niz = nullptr;
	}


	void brisi() {
		delete[] niz;
		niz = nullptr;
		vel = 0;
	}

public:

	Skup() {
		niz = nullptr;
		vel = 0;
	}
	Skup(double a) {

		niz = new double[vel = 1];
		niz[0] = a;

	}

	Skup(Skup&& s) {
		premesti(s);
	}

	Skup(const Skup& s) {
		kopiraj(s);
	}
	~Skup()
	{
		brisi();
	}

	void unija(const Skup&, const Skup&);
	void presek(const Skup&, const Skup&);
	void razlika(const Skup&, const Skup&);

	void pisi() const;
	void citaj();
	int velicina() const{
		return vel;
	}






};
