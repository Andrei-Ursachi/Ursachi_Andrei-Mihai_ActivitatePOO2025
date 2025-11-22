#include <iostream>
using namespace std;

class Biblioteca {
	string adresa;
	int nrAbonati;
	float pretAbonament;
	char* ultimaVizita;
public:
	Biblioteca() {
		this->adresa = "adresa1";
		this->nrAbonati = 0;
		this->pretAbonament = 0;
		this->ultimaVizita = nullptr;
	}

	Biblioteca(string adresa, int nrAbonati, char* ultimaVizita) {
		this->adresa = adresa;
		this->nrAbonati = nrAbonati;
		if (ultimaVizita != nullptr) {
			this->ultimaVizita = new char[strlen(ultimaVizita) + 1];
			strcpy_s(this->ultimaVizita, strlen(ultimaVizita) + 1, ultimaVizita);
		}
		else {
			this->ultimaVizita = nullptr;
		}
	}

	//copiere
	Biblioteca(const Biblioteca& b) {
		this->adresa = b.adresa;
		this->nrAbonati = b.nrAbonati;
		if (ultimaVizita != nullptr) {
			this->ultimaVizita = new char[strlen(b.ultimaVizita) + 1];
			strcpy_s(this->ultimaVizita, strlen(b.ultimaVizita) + 1, b.ultimaVizita);
		}
		else {
			this->ultimaVizita = nullptr;
		}
	}

	char* getUltimaVizita() {
		return this->ultimaVizita;
	}
	string getAdresa() {
		return this->adresa;
	}
	int getNrAbonati() {
		return this->nrAbonati;
	}
	float getPretAbonament() {
		return this->pretAbonament;
	}

	void setAdresa(string adresa) {
		if (adresa.length() > 0) {
			this->adresa = adresa;
		}
	}

	~Biblioteca() {
		if (this->ultimaVizita != nullptr) {
			delete[]this->ultimaVizita;
		}
		cout << "apel la destructor" << endl;
	}

	friend ostream& operator<<(ostream& out, Biblioteca& b) {
		out << b.adresa << endl;
		out << b.nrAbonati << endl;
		out << b.pretAbonament << endl;
		if (b.ultimaVizita != nullptr) {
			out << b.ultimaVizita << endl;
		}
		else {
			cout << " nu avem o ultima vizita" << endl;
		}
		return out;
	}

	//ca si copiere doar ca adaug conditie ca this != referinta obiect + destructor
	Biblioteca& operator=(const Biblioteca& b) {
		if (this != &b) {
			if (this->ultimaVizita != nullptr) {
				delete[]this->ultimaVizita;
			}
			this->adresa = b.adresa;
			this->nrAbonati = b.nrAbonati;
			if (ultimaVizita != nullptr) {
				this->ultimaVizita = new char[strlen(b.ultimaVizita) + 1];
				strcpy_s(this->ultimaVizita, strlen(b.ultimaVizita) + 1, b.ultimaVizita);
			}
			else {
				this->ultimaVizita = nullptr;
			}
		}
		return *this;
	}

};

void main() {
	Biblioteca b1;
	cout << b1 << endl;

	Biblioteca b2 = b1;
	cout << b2 << endl;

	Biblioteca b3;
	b3 = b2;
	cout << b3 << endl;

	b2.setAdresa("Bucuresti");
	cout << b2 << endl;

}
