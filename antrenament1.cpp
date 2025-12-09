#include <iostream>
using namespace std;

class Masina {
private:
	float* pret;
	float greutate;
	int nrLocuri;
	const string marca;
public:
	Masina():marca("Dacia") {
		this->greutate = 2000;
		this->nrLocuri = 5;
		this->pret = nullptr;
	}

	Masina(int greutate, int nrLocuri, string marca) :marca(marca) {
		this->greutate = greutate;
		this->nrLocuri = nrLocuri;
		this->pret = new float[this->nrLocuri];
		for (int i = 0; i < nrLocuri; i++) {
			this->pret[i] = pret[i];
		}
	}

	Masina(const Masina& m) {
		this->greutate = m.greutate;
		this->nrLocuri = m.nrLocuri;
		this->pret = new float[this->nrLocuri];
		for (int i = 0; i < nrLocuri; i++) {
			this->pret[i] = m.pret[i];
		}
	}

	~Masina() {
		if (this->pret != nullptr) {
			delete[]this->pret;
		}
		cout << "destructor apelat" << endl;
	}

	//getteri
	float getGreutate() {
		return this->greutate;
	}
	int getNrLocuri() {
		return this->nrLocuri;
	}
	const string getMarca() {
		return this->marca;
	}

	//setteri
	void setGreutate(int greutate) {
		if (greutate > 0) {
			this->greutate = greutate;
		}
		else {
			cout << "Greutatea nu poate fi < 0" << endl;
		}
	}
	void setNrLocuri(int nrLocuri) {
		if (nrLocuri > 0 && nrLocuri <5) {
			this->nrLocuri = nrLocuri;
		}
		else {
			cout << "Numarul de locuri este min 1 - max 5" << endl;
		}
	}

	friend ostream& operator<<(ostream& out, const Masina& m) {
		out << m.greutate << endl;
		out << m.nrLocuri << endl;
		out << m.marca << endl;
		if (m.pret != nullptr) {
			out << m.pret << endl;
		}
		else {
			out << "nu exista pret setat" << endl;
		}
		return out;
	}

};


void main() {
	Masina m1;
	cout << m1 << endl;
}