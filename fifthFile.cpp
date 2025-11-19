#include<iostream>
#include<fstream>

using namespace std;

class Petitie {
	const int id;
	string data;
	string numeComplet;
	int nrZile;
	bool status;
	char* descriere;

	//no param
	Petitie() :id(id) {
		this->data = "azi";
		this->numeComplet = "Constructor unu";
		this->nrZile = 2;
		this->status = true;
		this->descriere = nullptr;
	}

	Petitie(string data, string numeComplet, int nrZile, bool status, char* descriere) :id(id) {
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

	Petitie(const Petitie& pet) :id(pet.id) {
		this->data = pet.data;
		this->numeComplet = pet.numeComplet;
		this->nrZile = pet.nrZile;
		this->status = pet.status;
		if (descriere != nullptr) {
			this->descriere = new char[strlen(pet.descriere) + 1];
			strcpy_s(this->descriere, strlen(pet.descriere) + 1, p.descriere);
		}
		else {
			this->descriere = nullptr;
		}
	}

	~Petitie() {
		if (this->descriere != nullptr) {
			delete[]this->descriere;
		}
		cout << "aici se apeleaza destructorul" << endl;
	}

	friend ostream& operator<<(ostream& out, const Petitie& p) {
		out << p.id << endl;
		out << p.data << endl;
		out << p.descriere << endl;
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

	void main() {

	}
};