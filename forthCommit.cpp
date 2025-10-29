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
int Abecedar::nrPagini = 100;

class Manual {
public:
	char* denumire;
	int static numarAutori;
	const string edituraManual;
	float pretManual;

	Manual():edituraManual("Pagina") {
		this->denumire = nullptr;
		this->pretManual = 20.3;
	}

	Manual(float pretManual, const string edituraManual) :edituraManual(edituraManual) {
		this->denumire = new char[strlen(denumire)+1];
		strcpy_s(this->denumire, strlen(denumire) + 1,denumire);
		this->pretManual = pretManual;
	}

	Manual(char* denumire, const string edituraManual, float pretManual) :edituraManual(edituraManual) {
		this->denumire = new char[strlen(denumire)+1];
		strcpy_s(denumire, strlen(denumire) + 1,denumire);
		this->pretManual = pretManual;
	}

	//getter si setter
	int getPret() {
		return this->pretManual;
	}

	void setPret(int pretManual) {
		this->pretManual = pretManual;
	}

	//destructor
	~Manual() {
		if (this->denumire != nullptr) {
			delete[]this->denumire;
		}
		cout << "aici se apeleaza destructor" << endl;
	}

	//supraincarcare <<
	friend ostream& operator<<(ostream& out, const Manual& m) {
		out << m.denumire << endl;
		out << m.edituraManual << endl;
		out << m.pretManual << endl;
		out << m.numarAutori << endl;
		return out;
	}
	
	//functie calcul statica
	void calculPretPerAutor() {
		if (numarAutori > 3) {
			pretManual *= 1.7;
		}
		else {
			pretManual *= 1.1;
		}
	}

};
int Manual::numarAutori = 5;

void main() {

}