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

	friend ostream& operator<<(ostream& out, const Abecedar& a) {
		out << "Titlu abecedar: " << a.titlu << ";" << "\n";
		out << "Numele editurii: " << a.editura << "\n";
		out << "Bucati vandute: " << a.bucatiVandute << "\n";
		out << "Numar pagini: " << nrPagini << "\n" << endl;
		if (a.pretAbecedar != nullptr) {
			cout << "Pret abecedar: " << *(a.pretAbecedar) << "\n";
		}
		else {
			cout << "Abecedarul nu are pret!" << "\n";
		}
		return out;
	}

	//destructor
	~Abecedar() {
		if (this->pretAbecedar != nullptr) {
			delete[] this->pretAbecedar;
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
		if (m.denumire != nullptr) {
			out << m.denumire << endl;
		}
		else {
			out << "Nu exista denumire pt obiectul manual" << endl;
		}
		out << m.edituraManual << endl;
		out << m.pretManual << endl;
		out << m.numarAutori << endl;
		return out;
	}
	
	//functie calcul statica
	static void calculPretPerAutor(float pretManual) {
		if (numarAutori > 3) {
			pretManual *= 1.7;
		}
		else {
			pretManual *= 1.1;
		}
	}

};
int Manual::numarAutori = 5;


class Uniforma {
public:
	int marime;
	static int nrComponente;
	char* producator;
	float pret;
	const string culoare;

	Uniforma():culoare("albastru") {
		this->marime = 20;
		this->pret = 5000.99;
		this->producator = nullptr;
	}

	Uniforma(const string culoare, int marime) :culoare(culoare) {
		this->marime = marime;
		this->producator = nullptr;
		this->pret = 9.99;
	}

	Uniforma(const string culoare, int marime, char* producator, float pret) :culoare(culoare) {
		this->marime = marime;
		this->pret = pret;
		this->producator = new char[strlen(producator) + 1];
		strcpy_s(producator, strlen(producator) + 1, producator);
	}

	~Uniforma() {
		if (this->producator != nullptr) {
			delete[]this->producator;
		}
		cout << "aici apelez destructor uniforma" << endl;
	}

	//overload <<
	friend ostream& operator<<(ostream& out, const Uniforma& u) {
		out << u.marime << endl;
		out << u.nrComponente << endl;
		out << u.pret << endl;
		out << u.culoare << endl;
		if (u.producator != nullptr) {
			cout << u.producator << endl;
		}
		else {
			cout << "Obiectul nu are valoare producator!" << endl;
		}
		return out;

	}

	//fct statica calcul
	static float calculPretMediu(float totalPreturi) {
		if (nrComponente > 0) {
			return totalPreturi / nrComponente;
		}
		else {
			return 0;
		}	
	}

};
int Uniforma::nrComponente = 5;

void main() {
	//clasa abecedar
	Abecedar abecedarUnu;
	cout << abecedarUnu << endl;
	//clasa manual
	//clasa uniforma
	Uniforma uniformaUnu;
	cout << uniformaUnu << endl;
	
	float pretMediu = Uniforma::calculPretMediu(2500);
	cout << "pretul mediu per componenta este: " << pretMediu;

}