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

	//copiere
	Masina(const Masina& m):marca(m.marca) {
		this->greutate = m.greutate;
		this->nrLocuri = m.nrLocuri;
		if (nrLocuri > 0 && m.pret != nullptr) {
			this->pret = new float[this->nrLocuri];
			for (int i = 0; i < this->nrLocuri; i++) {
				this->pret[i] = m.pret[i];
			}
		}
		else {
			this->pret = nullptr;
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

	//supraincarcare <<
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

	//supraincarcare = (ca constructorul de copiere)
	Masina& operator=(const Masina& m) {
		if (this != &m) {
			if (this->pret != nullptr) {
				delete[]this->pret;
			}
		}
		this->greutate = m.greutate;
		this->nrLocuri = m.nrLocuri;
		if (nrLocuri > 0 && m.pret != nullptr) {
			this->pret = new float[this->nrLocuri];
			for (int i = 0; i < this->nrLocuri; i++) {
				this->pret[i] = m.pret[i];
			}
		}
		else {
			this->pret = nullptr;
		}
		return *this;
	}
};


void main() {
	Masina m1;
	cout << m1 << endl;

	Masina m2(22.5, 5, "Ford");
	cout << m2 << endl;

	Masina m3 = m1;
	cout << m3 << endl;

	Masina m4;
	m4 = m1;
	cout << m4 << endl;
}