#include<iostream>
#include<fstream>

using namespace std;

class Petitie {
private:
	const int id;
	string data;
	string numeComplet;
	int nrZile;
	bool status;
	char* descriere;

public:

	//constructor 1 - fara parametri
	Petitie() :id(0) {
		this->data = "azi";
		this->numeComplet = "Constructor unu";
		this->nrZile = 2;
		this->status = true;
		this->descriere = nullptr;
	}

	//constructor 2 - cu parametri
	Petitie(string data, string numeComplet, int nrZile, bool status, char* descriere) :id(1) {
		this->data = data;
		this->numeComplet = numeComplet;
		this->nrZile = nrZile;
		this->status = status;

		if (descriere != nullptr) {
			this->descriere = new char[strlen(descriere) + 1];
			strcpy_s(this->descriere, strlen(descriere) + 1, descriere);
		}
		else {
			this->descriere = nullptr;
		}
	}

	//constructor copiere
	Petitie(const Petitie& pet) :id(pet.id) {
		this->data = pet.data;
		this->numeComplet = pet.numeComplet;
		this->nrZile = pet.nrZile;
		this->status = pet.status;

		if (pet.descriere != nullptr) {
			this->descriere = new char[strlen(pet.descriere) + 1];
			strcpy_s(this->descriere, strlen(pet.descriere) + 1, pet.descriere);
		}
		else {
			this->descriere = nullptr;
		}
	}

	//destructor
	~Petitie() {
		if (this->descriere != nullptr) {
			delete[] this->descriere;
		}
		cout << "aici se apeleaza destructorul" << endl;
	}

	//operator <<
	friend ostream& operator<<(ostream& out, const Petitie& p) {
		out << p.id << endl;
		out << p.data << endl;
		out << p.numeComplet << endl;
		out << p.nrZile << endl;
		out << p.status << endl;

		if (p.descriere != nullptr) {
			out << p.descriere << endl;
		}
		else {
			out << "Nu exista valoare pt. descriere!" << endl;
		}

		return out;
	}

	//operator =
	Petitie& operator=(const Petitie& pet) {
		if (this == &pet) return *this;

		if (this->descriere != nullptr) {
			delete[] this->descriere;
		}

		this->data = pet.data;
		this->numeComplet = pet.numeComplet;
		this->nrZile = pet.nrZile;
		this->status = pet.status;

		if (pet.descriere != nullptr) {
			this->descriere = new char[strlen(pet.descriere) + 1];
			strcpy_s(this->descriere, strlen(pet.descriere) + 1, pet.descriere);
		}
		else {
			this->descriere = nullptr;
		}

		return *this;
	}

	bool operator!() {
		if (status == 0 && nrZile > 30) {
			return true;
		}
		else {
			return false;
		}
	}

	void operator~() {
		if (status == 0) {
			status = 1;
		}
		else {
			status = 0;
		}
	}

	//getters
	string getData() {
		return this->data;
	}

	string getNumeComplet() {
		return this->numeComplet;
	}

	int getNrZile() {
		return this->nrZile;
	}

	bool getStatus() {
		return this->status;
	}

	char* getDescriere() {
		return this->descriere;
	}

};


void main() {

	Petitie p1;
	cout << p1 << endl;

	char text[] = "test";
	Petitie p2("Anul 2002", "Reclamatie", 2, true, text);
	cout << p2 << endl;

	Petitie p3 = p2; //constructor copiere
	cout << p3 << endl;

	bool ok = !p1;
	cout << (ok ? "Expirata" : "Ok") << endl;

	p1.operator~();  //apel operator schimbare status
	cout << "Aici e apelat ~" << endl << p1 << endl;

	cout << p1.getData() << endl;
	cout << p1.getNumeComplet() << endl;
	cout << p1.getNrZile() << endl;
	cout << p1.getStatus() << endl;

	
	if (p1.getDescriere() != nullptr)
		cout << p1.getDescriere() << endl;
	else
		cout << "Descriere NULL" << endl;
}
