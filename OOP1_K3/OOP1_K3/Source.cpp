#include <iostream>


using namespace std;


template<typename T>
class Lista {

	struct Elem {
		T pod;
		Elem* sled;
		Elem* pret;

		Elem(T p, Elem* pre = nullptr, Elem* s = nullptr) : pod(p), sled(s), pret(pre) {};

	};
	
	Elem* prvi, * posl;
	mutable Elem* temp, * pret;

public:
	Lista() : prvi(nullptr), posl(nullptr), temp(nullptr), pret(nullptr) {};

	void dodajKraj(T pod) {
		Elem* old = posl;
		Elem* novi = new Elem(pod);
		posl = (prvi ? posl->sled : prvi) = novi;
		novi->pret = old;


	}

	void dodajPoc(T pod) {
		Elem* novi = new Elem(pod);
		Elem* p = prvi;
		novi->sled = p;
		p->pret = novi;
		novi->pret = nullptr;
		prvi = novi;

	}

	bool imaTek() const {
		return temp != nullptr;
	}

	T& getTemp() {
		return temp->pod;
	}

	void naPrvi() {
		temp = prvi;
	}

	void naPosl() {
		temp = posl;
	}

	void naSled() {
		temp = temp->sled;
	}

	void naPret() {
		temp = temp->pret;
	}

	void delTemp() {

		Elem* old = temp;
		
		Elem* sledeci = temp->sled;

		Elem* prethodni = temp->pret;

		prethodni->sled = sledeci;

		sledeci->pret = prethodni;

		temp = prethodni;

		delete old;

	}


	void pisi_od_poc() {

		for (Elem* temp = prvi; temp ; temp=temp->sled)
		{
			cout << temp->pod << " ";
		}
		cout << endl;

	}


	void pisi_od_kraj() {

		for (Elem* temp = posl; temp ; temp=temp->pret)
		{
			cout << temp->pod << " ";
		}
		cout << endl;

	}


};



class Adresa {

	int* bajtovi = new int[6];

public:
	Adresa(int b=0)  {
		for (int i = 0; i < 6; i++)
		{
			bajtovi[i] = b;
		}
	}

	friend bool operator==(const Adresa& a1, const Adresa& a2) {
		for (int i = 0; i < 6; i++)
		{
			if (a1.bajtovi[i]!=a2.bajtovi[i])
			{
				return false;
			}
		}
		return true;
	}

	friend ostream& operator<<(ostream& it, const Adresa& a) {
		for (int i = 0; i < 6; i++)
		{
			cout << hex << a.bajtovi[i];
			if (i!=5)
			{
				it << ":";
			}
		}
		return it;
	}



};

class Okvir {

	Adresa izvor;
	Adresa odrediste;
	const char* sadrzaj;
	int duz;

public:
	Okvir(Adresa i, Adresa o,const char* s, int d) : izvor(i), odrediste(o), sadrzaj(s), duz(d) {};

	Adresa getIzvor() const {
		return izvor;
	}

	Adresa getOdr() const {
		return odrediste;
	}

	const char* getSadr() const {
		return sadrzaj;
	}

	int getDuz() const {
		return duz;
	}

	friend ostream& operator<<(ostream& it, const Okvir& o) {
		it << "Frame[src:" << o.izvor << " dst:" << o.odrediste << " content:" << o.sadrzaj << "]";
		return it;
	}

};


class Interfejs {


	Adresa adr;
	Interfejs* sused;
	MrezniUredjaj* mojUredjaj = nullptr;

public:
	Interfejs(MrezniUredjaj* m) : mojUredjaj(m) {};

	Adresa getAdr() const {
		return adr;
	}

	void postAdr(Adresa a){
		adr = a;
	}

	Interfejs* getInter() const {
		return sused;
	}

	void postaviInter(Interfejs* in){
		sused = in;
	}

	void posaljiOkvir(Okvir& o) {
		if (sused)
		{
			sused->prihvati(o);
		}
	}

	void prihvati(Okvir& o){
		mojUredjaj->obradi(o, this);
	}





};


class MrezniUredjaj {
protected:
	Interfejs** ints;
	int broj;


public:
	MrezniUredjaj(int b) : broj(b) {
		ints = new Interfejs * [b];
		for (int i = 0; i < b; i++)
		{
			ints[i] = new Interfejs(this);
		}
	}

	virtual void obradi( Okvir&, const Interfejs*) = 0;


	Interfejs* dohvSlobodan() {
		for (int i = 0; i < broj; i++)
		{
			if (ints[i]->getInter()==nullptr)
			{
				return ints[i];
			}
		}
		return nullptr;
	}




};



class Hab : public MrezniUredjaj {

public:
	Hab(int b) : MrezniUredjaj(b) {};

	void obradi(Okvir& o, const Interfejs* ulaz) override{
		for (int i = 0; i < broj; i++)
		{
			if (ints[i]!=ulaz)
			{
				ints[i]->posaljiOkvir(o);
			}

		}


	}



};


class Svic : public MrezniUredjaj {

	struct Par {

		const Adresa macAdr;
		const Interfejs* inter;

		Par(Adresa mac, const Interfejs* i) : macAdr(mac), inter(i) {};

	};

	Lista<Par*> tab;

public:

	Svic(int br) : MrezniUredjaj(br) {};

	void obradi(Okvir& o, const Interfejs* i) override {
		bool noviPar = true;
		const Interfejs* tempInt = nullptr;





	}







};






int main() {

	Lista<int> l1;


	l1.dodajKraj(5);
	l1.dodajKraj(7);
	l1.dodajPoc(3);


	Adresa a1(15);
	Adresa a2(38);


	cout << a1 << endl;



	Okvir o1(a1, a2, "Racunarski centar", 15);

	cout << o1 << endl;

	

	return 0;
}
