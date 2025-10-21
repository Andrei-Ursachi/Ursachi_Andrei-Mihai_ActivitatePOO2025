#include <iostream>
using namespace std;

class Fruct {
private:
	char* nume;
	string culoare;
	float greutate;
	int lunaMaturitate;
	int nrSeminte;
	float* greutatiSeminte;

public:
	Fruct() {
		this->culoare = "rosu";
		this->greutate = 0.1;
		this->lunaMaturitate = 6;
		this->nrSeminte = 5;
		this->greutatiSeminte = nullptr;
		this->nume = nullptr;

	}

	Fruct(char* nume, string culoare, float greutate, int lunaMaturitate, int nrSeminte, float* greutatiSeminte) {
		this->culoare = culoare;
		this->greutate = greutate;
		this->lunaMaturitate = lunaMaturitate;
		this->nrSeminte = nrSeminte;
		this->greutatiSeminte = new float[nrSeminte];
		for (int i = 0; ;i++) {
			this->greutatiSeminte[i] = greutatiSeminte[i];
		}
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);

	}

	void setGreutate(float greutate) {
		if (greutate > 0) {
			(*this).greutate = greutate;
		}
	}

	float getGreutate() {
		return this->greutate;
	}

	char* getNume() {
		return this->nume;
	}

	void setNume(const char* nume) {
		if (strlen(nume) > 0) {
			if (this->nume != nullptr) {
				delete[] this->nume;
			}
			this->nume = new char[strlen(nume) + 1];
			strcpy_s(this->nume, strlen(nume) + 1, nume);
		}
	}

	void setCuloare(string culoare) {
		if (culoare.length() > 0) {
			this->culoare = culoare;
		}
	}

	void setGreutatiSeminte(int nrSeminte, float* greutatiSeminte) {
		if (nrSeminte > 0) {
			this->nrSeminte = nrSeminte;
			if (this->greutatiSeminte != nullptr) {
				delete[] this->greutatiSeminte;
			}
			this->greutatiSeminte = new float[nrSeminte];
			for (int i = 0; i < nrSeminte;i++) {
				this->greutatiSeminte[i] = greutatiSeminte[i];
			}
		}
	}

	float* getGreutatiSeminte() {
		return this->greutatiSeminte;
	}

	/*float getGreutateSamanata(int pozitie) {
		if()
	}*/
};


int main() {
	Fruct fruct;

	fruct.setGreutate(2.5);
	cout << fruct.getGreutate() << endl;

	fruct.setNume("Mar");

	int seminte = 3;
	float* vector = new float[3] {0.1, 0.2, 0.3};
	fruct.setGreutatiSeminte(seminte, vector);

	cout << fruct.getGreutatiSeminte()[0] << endl;
	cout << fruct.getGreutatiSeminte()[1] << endl;
	cout << fruct.getGreutatiSeminte()[2] << endl;

	return 0;
};