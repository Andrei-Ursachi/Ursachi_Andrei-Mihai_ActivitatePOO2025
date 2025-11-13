#include<iostream>
using namespace std;

//Andrei = Abecedar; Mihai = Manual ; Ursachi = Uniforma
class Abecedar {
private:
	int bucatiVandute;
	const string titlu;
	static int nrPagini;
	string editura;
	float* pretAbecedar;
public:
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
		this->pretAbecedar = new float[this->bucatiVandute];
		for (int i = 0; i < bucatiVandute; i++) {
			this->pretAbecedar[i] = pretAbecedar[i];
		}
	}

	//constr copiere abecedar
	Abecedar(const Abecedar& a): titlu(a.titlu) {
		this->bucatiVandute = a.bucatiVandute;
		this->editura = a.editura;
		this->pretAbecedar = new float[this->bucatiVandute];
		for (int i = 0; i < bucatiVandute; i++) {
			this->pretAbecedar[i] = a.pretAbecedar[i];
		}
	}
	
	//getter si setteri
	int getBucatiVandute() {
		return this->bucatiVandute;
	}
	void setBucatiVandute(int bucatiVandute) {
		this->bucatiVandute = bucatiVandute;
	}

	const string getTitlu() {
		return this->titlu;
	}
	
	int static getNrPagini() {
		return Abecedar::nrPagini;
	}
	void setNrPagini(static int nrPagini) {
		Abecedar::nrPagini=nrPagini;
	}

	string getEditura() {
		return this->editura;
	}
	void setEditura(string editura) {
		this->editura = editura;
	}

	float getPretAbecedar() {
		if (this->pretAbecedar == nullptr) {
			return 0;
		}
		return *(this->pretAbecedar);
	}
	void setPretAbecedar(float pretAbecedar) {
		if (this->pretAbecedar == nullptr) {
			this->pretAbecedar = new float;
		}
		*this->pretAbecedar = pretAbecedar;
	}

	//supraincarcare <<
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
	static float pretPePagina(const Abecedar& a) {
		if (a.pretAbecedar == nullptr || nrPagini == 0) return 0;
		return *(a.pretAbecedar) / nrPagini;
	}
};
int Abecedar::nrPagini = 100;

class Manual {
private:
	char* denumire;
	int static numarAutori;
	const string edituraManual;
	float pretManual;

public:
	Manual():edituraManual("Pagina") {
		this->denumire = nullptr;
		this->pretManual = 20.3;
	}

	Manual(float pretManual, const char* denumire) :edituraManual(edituraManual) {
		this->denumire = new char[strlen(denumire)+1];
		strcpy_s(this->denumire, strlen(denumire) + 1,denumire);
		this->pretManual = pretManual;
	}

	Manual(char* denumire, const string edituraManual, float pretManual) :edituraManual(edituraManual) {
		this->denumire = new char[strlen(denumire)+1];
		strcpy_s(this->denumire, strlen(denumire) + 1,denumire);
		this->pretManual = pretManual;
	}

	//constructor copiere
	Manual(const Manual& m) :edituraManual(m.edituraManual) {
		this->denumire = new char[strlen(m.denumire) + 1];
		strcpy_s(this->denumire, strlen(m.denumire) + 1, m.denumire);
		this->pretManual = m.pretManual;
	}

	//destructor
	~Manual() {
		if (this->denumire != nullptr) {
			delete[]this->denumire;
		}
		cout << "aici se apeleaza destructor" << endl;
	}

	//getter si setter
	int getPret() {
		return this->pretManual;
	}

	void setPret(int pretManual) {
		this->pretManual = pretManual;
	}

	char* getDenumire() {
		return this->denumire;
	}

	void setDenumire(const char* denumire) {
		if (this->denumire != nullptr) {
			delete[]this->denumire;
		}
		this->denumire = new char[strlen(denumire) + 1];
		strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
	}

	string getEditura() {
		return this->edituraManual;
	}

	int static getNumarAutori() {
		return Manual::numarAutori;
	}
	void setNumarAutori(static int numarAutori) {
		Manual::numarAutori = numarAutori;
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
	static float calculPretPerAutor(float pretManual) {
		if (numarAutori > 3) {
			pretManual *= 1.7;
		}
		else {
			pretManual *= 1.1;
		}
		return pretManual;
	}

};
int Manual::numarAutori = 5;


class Uniforma {
private:
	int marime;
	static int nrComponente;
	char* producator;
	float pret;
	const string culoare;
public:
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
		strcpy_s(this->producator, strlen(producator) + 1, producator);
	}

	//contructor copiere
	Uniforma(const Uniforma& u) :culoare(u.culoare) {
		this->marime = u.marime;
		this->pret = u.pret;
		this->producator = new char[strlen(u.producator) + 1];
		strcpy_s(this->producator, strlen(u.producator) + 1, u.producator);
	}

	//destructor
	~Uniforma() {
		if (this->producator != nullptr) {
			delete[]this->producator;
		}
		cout << "aici apelez destructor uniforma" << endl;
	}

	//getteri setteri
	int getMarime() {
		return this->marime;
	}

	void setMarime(int marime) {
		this->marime = marime;
	}

	int static getNumarComponente() {
		return Uniforma::nrComponente;
	}
	void setNumarAutori(static int nrComponente) {
		Uniforma::nrComponente = nrComponente;
	}

	char* getProducator() {
		return this->producator;
	}

	void setProducator(const char* producator) {
		if (this->producator != nullptr) {
			delete[]this->producator;
		}
		this->producator = new char[strlen(producator) + 1];
		strcpy_s(this->producator, strlen(producator) + 1, producator);
	}

	float getPret() {
		return this->pret;
	}

	void setPret(float pret) {
		this->pret = pret;
	}

	string getCuloare() {
		return this->culoare;
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

	Abecedar a2(6,"TestEditurra", "TitluTest", 454.5);
	cout << a2 << endl;

	Abecedar a3(322, "Titlu3");
	cout << a3 << endl;

	float rezultatFunctie = Abecedar::pretPePagina(a2);
	cout << "Pret pe pagina" << rezultatFunctie << endl;


	//clasa manual
	Manual manualUnu;
	cout << manualUnu << endl;

	Manual m2(25.6, "Mate");
	cout << m2 << endl;

	char valoareDenumire[] = "Matematica";
	Manual m3(valoareDenumire, "Editura3", 122.5);
	cout << m3 << endl;

	float cresterePret = Manual::calculPretPerAutor(6);
	cout << "Pretul manualului cand sunt 6 autori este de: " << cresterePret << " lei" << endl;


	//clasa uniforma
	Uniforma uniformaUnu;
	cout << uniformaUnu << endl;

	Uniforma u2("Turcoaz", 68);
	cout << u2 << endl;
	
	char valProd[] = "Gandul";
	Uniforma u3("Bleumarin", 66, valProd, 5000);

	float pretMediu = Uniforma::calculPretMediu(2500);
	cout << "pretul mediu per componenta este: " << pretMediu;

}