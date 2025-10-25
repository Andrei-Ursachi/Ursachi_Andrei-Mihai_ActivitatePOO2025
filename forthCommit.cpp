#include<iostream>
using namespace std;

//Andrei = Abecedar; Mihai = Manual ; Ursachi = Uniforma
class Abecedar {
public:
	int bucatiVandute;
	const string titlu;
	static int nrPagini;
	string editura;
	float* pretAbecedar;
	//constructor 1
	Abecedar(int bucatiVandute, string titluNou) : titlu(titluNou) {
		this->bucatiVandute = bucatiVandute;
		this->editura = "testName";
		this->pretAbecedar = new float(12.3);
	}
	//constructor 2
	Abecedar() : titlu("Titlu constructor 2") {
		this->bucatiVandute = 0;
		this->editura = "Editura Litera";
		this->pretAbecedar = nullptr;
	}
	//constructor 3
	Abecedar(int bucati, string edituraNoua, string titluNou, float pret) : titlu(titluNou) {
		this->bucatiVandute = bucati;
		this->editura = edituraNoua;
		this->pretAbecedar = new float(pret);
	}

	void afisare() {
		cout << "Titlu abecedar: " << this->titlu << ";" << "\n";
		cout << "Numele editurii: " << this->editura << "\n";
		cout << "Bucati vandute: " << this->bucatiVandute << "\n";
		if (this->pretAbecedar != nullptr) {
			cout << "Pret abecedar: " << *(this->pretAbecedar) << "\n";
		}
		else {
			cout << "Abecedarul nu are pret!" << "\n";
		}
		cout << "Numar pagini: " << nrPagini << "\n" << endl;
	}

	//destructor
	~Abecedar() {
		if (this->pretAbecedar != nullptr) {
			delete this->pretAbecedar;
			this->pretAbecedar = nullptr;
		}
	}

	//functie statica de calcul
	static void marirePret(Abecedar& abecedar) {
		if (abecedar.pretAbecedar == nullptr) return;
		int randomMarire = rand() % 20 + 1;
		*(abecedar.pretAbecedar) += *(abecedar.pretAbecedar) * (randomMarire / 100.0f);
		cout << "Pretul a crescut cu " << randomMarire << "% pentru " << abecedar.titlu << endl;
	}
};