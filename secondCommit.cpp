#include <iostream>
using namespace std;

class Autobuz {
private:
	static int nrAutobuze; //trebuie sa contorizeze automat nr autobuze create
	const int idAutobuz; //unic pe autobuz
	int capacitate;
	int nrPersoaneImbarcate; // < capacitate
	char* producator;

public:
	//constructor fara parametri
	Autobuz() : idAutobuz(++nrAutobuze) {
		this->capacitate = 20;
		this->nrPersoaneImbarcate = capacitate;
		this->producator = nullptr;
	}

	//constructor cu parametri
	Autobuz(int _capacitate, int _nrPersoaneImbarcate, char* _producator, int idNou) :idAutobuz(idNou), capacitate(_capacitate),
		nrPersoaneImbarcate(_nrPersoaneImbarcate) {

	}

	//destructor
	~Autobuz() {
		if (this->producator != nullptr) {
			delete[]this->producator;
		}
	}

	//metoda de afisare DE REFACUT
	void afisare() {
		cout << "Autobuzul " << idAutobuz << " face parte din flota de " << nrAutobuze
			<< " autobuze a primariei capitalei. Capacitatea lor este de "
			<< capacitate << " iar nr. de persoane imbarcate este " << nrPersoaneImbarcate << '.\n';

	}

	//get si set pt. capacitate
	int getCapacitate() {
		return capacitate;
	}

	void setCapacitate(int _capacitate) {
		if (_capacitate > 0) {
			capacitate = _capacitate;
		}
	}

	//get si set pt. nrPerosaneImbarcate
	int getNrPersoaneImbarcate() {
		return nrPersoaneImbarcate;
	}

	void setNrPersoaneImbarcate(int _nrPersoaneImbarcate) {
		if (_nrPersoaneImbarcate >= 0 && _nrPersoaneImbarcate <= capacitate) {
			nrPersoaneImbarcate = _nrPersoaneImbarcate;
		}
	}

};
int Autobuz::nrAutobuze = 0;

void main() {
	Autobuz autobuz1;
	autobuz1.afisare();

	Autobuz autobuz2;
	autobuz2.afisare();

}