#include "red_tela.h"



Red_tela::Red_tela(int kap) : tela(new Telo* [kap]), kap(kap), duz(0), prvo(0) ,posl(0) {
	for (int i = 0; i < kap; i++)
	{
		tela[i] = 0;
	}
};


void Red_tela::kopiraj(const Red_tela& rt) {
	duz = rt.duz;
	kap = rt.kap;
	prvo = rt.prvo;
	posl = rt.posl;
	for (int i = 0; i < kap; i++)
	{
		tela[i] = rt.tela[i] ? rt.tela[i]->kopija() : nullptr;
	}


}

void Red_tela::brisi() {                     // Oslobaðanje memorije.
	if (!tela) return;
	for (int i = 0; i < kap-1; delete tela[i++]);
	delete[] tela;
}


ostream& operator<<(ostream& it, const Red_tela& r) {
	it << "Red [ ";
	for (int i = 0; i < r.duz; i++)
	{
		it << *r.tela[(r.prvo + i) & r.kap];
	}
	it << " ]";
	return it;

}



