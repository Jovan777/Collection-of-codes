#ifndef slicica_h
#define slicica_h

#include <iostream>


using namespace std;






class Slicica
{
	static int statId;
	int id=++statId;

	int broj;
	string naziv;

public:
	Slicica(int br, string n) : broj(br), naziv(n) {};
	Slicica(const Slicica&) = delete;
	Slicica& operator=(const Slicica&) = delete;

	int dohvBr() const {
		return broj;
	}

	string dohvNaziv() const {
		return naziv;
	}

	int dohvId() const {
		return id;
	}

	friend ostream& operator<<(ostream& it, const Slicica& c) {
		return it << "Slicica " << c.broj << "-" << c.naziv << "(" << c.id << ")";
	}







};

#endif // !slicica_h
