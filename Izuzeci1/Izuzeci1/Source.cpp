#include <iostream>

using namespace std;


static int pos_id = 0;
class Akter {

	int id = pos_id++;
	double t_min, t_max;
	double t;

	double t_sluc() {

		return t_min + (t_max - t_min) * rand() / (RAND_MAX + 1);

	}

	virtual void radnja() = 0;


public:
	Akter(double tmin = 0, double tmax = 1) : t_min(tmin), t_max(tmax), t(0) {};
	virtual ~Akter()
	{

	}

	void proteklo(double dt) {
		if ((t-=dt)<=0)
		{
			radnja();
			t = t_sluc();
		}

	}


	friend ostream& operator<<(ostream& it, const Akter& a) {
		return it << "    " << a.id;
	}


};


class Casovnik {

	struct Elem
	{
		Akter* akter;
		Elem* sled;
		Elem(Akter* akt, Elem* s = nullptr) : akter(akt), sled(s) {};

	};

	Elem* prvi, * posl;

public:
	Casovnik() : prvi(nullptr), posl(nullptr) {};

	Casovnik& operator+=(Akter* a) {
		posl = (prvi ? posl->sled : prvi) = new Elem(a);
		return *this;
	}

	Casovnik& operator-=(Akter* akt) {
		Elem* temp = prvi, *pret=nullptr;
		while (temp && temp->akter!=akt)
		{
			pret = temp;
			temp = temp->sled;
		}
		if (temp)
		{
			(!pret ? prvi : pret->sled) = temp->sled;
			if (temp==posl)
			{
				posl = pret;
			}
			delete temp;


		}


		return *this;

	}


	void radi(double dt, double dmax) {
		for (double t = 0; t < dmax; t+=dt)
		{
			cout << "Vreme : " << t << endl;
			for (Elem* temp = prvi; temp ; temp=temp->sled)
			{
				temp->akter->proteklo(dt);
			}
		}


	}


};

class G_puno {

public:
	friend ostream& operator<<(ostream& it, const G_puno&) {
		return it << "Skladiste je puno";
	}


};


class G_prazno {

public:
	friend ostream& operator<<(ostream& it, const G_prazno&) {
		return it << "Skladiste je prazno";
	}


};


template<typename T>
class Skladiste {

	T* niz;
	int kap, duz;
	int prvi, posl;

public:
	Skladiste(int k = 10) : kap(10), duz(0), prvi(0), posl(0) {
		niz = new T[k];  /////
	};


	void stavi(const T& t) {
		if (duz==kap)
		{
			throw G_puno();
		}
		niz[posl++] = t;
		if (posl==kap)
		{
			posl = 0;
		}
		duz++;


	}

	T uzmi() {
		if (duz==0)
		{
			throw G_prazno();
		}
		T t = niz[prvi++];
		if (prvi==kap)
		{
			prvi = 0;
		}
		duz--;
		return t;


	}



};

template<typename T>
class Proizvodjac : public Akter {
	Skladiste<T>* sklad;

public:
	Proizvodjac(Skladiste<T>* skl, double t_min = 0, double t_max = 0) : sklad(skl), Akter(t_min, t_max) {}

	void radnja() override {
		cout << *this<<" : ";
		try
		{
			T t = T();
			sklad->stavi(t);
			cout << "stavio : " << t << endl;


		}
		catch (G_puno& g)
		{
			cout << g << endl;
		}


	}



};


template<typename T>
class Potrosac : public Akter{

	Skladiste<T>* sklad;

public:

	Potrosac(Skladiste<T>* skl, double t_min = 0, double t_max = 0) : sklad(skl), Akter(t_min, t_max) {}

	void radnja() override {
		cout << *this << endl;
		try
		{
			cout << "uzeo : " << sklad->uzmi() << endl;
		}
		catch (G_prazno g)
		{
			cout << g << endl;
		}
	}







};







class Proizvod {

	int broj;

public:
	Proizvod() : broj(1000 * rand() / (RAND_MAX + 1)) {}
	friend ostream& operator<<(ostream& it, const Proizvod& p) {
		return it << p.broj;

	}


};






int main() {

	Skladiste<Proizvod> s(3);
	Akter** akteri = new Akter * [5];
	Casovnik c;
	c += akteri[0] = new Proizvodjac<Proizvod>(&s, 2, 4);
	c += akteri[1] = new Proizvodjac<Proizvod>(&s, 1, 5);
	c += akteri[2] = new Proizvodjac<Proizvod>(&s, 1.5, 4.5);
	c += akteri[3] = new Potrosac<Proizvod>(&s, 1.5, 4.5);
	c += akteri[4] = new Potrosac<Proizvod>(&s, 1.5, 4.5);


	c.radi(0.25, 10);





	

	return 0;
}