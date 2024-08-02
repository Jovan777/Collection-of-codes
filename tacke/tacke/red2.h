class Red {

private:
	int* niz, kap, prvi, posl, duz;

public:
	explicit Red(int k = 10);
	Red(const Red& rd);
	Red(Red&& rd);

	~Red()
	{
		delete[] niz;
	}

	void stavi(int b);
	int uzmi();

	bool prazan() const { return duz == 0; }
	bool pun() const { return duz == kap; }

	void pisi() const;
	void prazni() { duz = prvi = posl = 0; }


};