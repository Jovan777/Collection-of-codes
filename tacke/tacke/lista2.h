#pragma once

class Lista {

	struct Elem
	{
		int broj;
		Elem* sled;
		Elem(int b, Elem* s = nullptr) : broj(b), sled(s) {};

	};

	Elem* prvi;

public:
	Lista() : prvi(nullptr){};

	Lista(int b) : prvi(new Elem(b)) {};

	Lista(const Lista& lst);
	Lista(Lista&& lst) {
		prvi = lst.prvi;
		lst.prvi = nullptr;
	}

	~Lista()
	{
		//prazni();
	}

	int duz() const;

	void pisi() const; 
	void na_pocetak(int b) {
		prvi = new Elem(b, prvi);
	}


	void na_kraj(int b);
	void citaj1(int n);
	void citaj2(int n);

	void umetni(int b);
	void prazni();
	void izostavi(int b);





};
