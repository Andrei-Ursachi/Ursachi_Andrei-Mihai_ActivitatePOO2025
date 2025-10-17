#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

using namespace std;

class Eveniment {
    string numeOrganizator;
    int oraIncepere;
    int durata; //numar ore;
    char* locatie;
public:
    //const implicit
    Eveniment() {
        this->numeOrganizator = "";
        this->oraIncepere = 0;
        this->durata = 0;
        char* locatie = NULL;
    }

    //constructor toti param
    Eveniment(string numeOrganizator, int oraIncepere, int durata, char* locatie) {
        this->numeOrganizator = numeOrganizator;
        this->oraIncepere = oraIncepere;
        this->durata = durata;
        this->locatie = new char[strlen(locatie) + 1];
        strcpy(this->locatie, locatie);
    }

    //constructor copiere
    Eveniment(const Eveniment& e) {
        this->numeOrganizator = e.numeOrganizator;
        this->oraIncepere = e.oraIncepere;
        this->durata = e.durata;
        this->locatie = new char[strlen(e.locatie) + 1];
        strcpy(this->locatie, e.locatie);
    }

    //getter setter
    int getDurata() {
        return this->durata;
    }

    void setDurata(int durata) {
        this->durata = durata;
    }

    //destructor
    ~Eveniment() {
        if (this->locatie != NULL) {
            delete[]this->locatie;
        }
    }

    //operator =
    Eveniment& operator=(const Eveniment& e) {
        if (this != &e)
        {
            if (this->locatie != NULL) {
                delete[]this->locatie;
            }
            this->numeOrganizator = e.numeOrganizator;
            this->oraIncepere = e.oraIncepere;
            this->durata = e.durata;
            this->locatie = new char[strlen(e.locatie) + 1];
            strcpy(this->locatie, e.locatie);
        }
        return *this;
    }

    //operator afisare
    friend ostream& operator<<(ostream& out, const Eveniment& e) {
        out << e.numeOrganizator << endl;
        out << e.oraIncepere << endl;
        out << e.durata << endl;
        if (e.locatie != NULL) {
            cout << e.locatie << endl;
        }
        else {
            cout << "nu este locatie" << endl;
        }
        return out;
    }

    //terminare
    bool oraSfarsit(int oraCurenta)const {
        return this->oraIncepere + this->durata;
    }

    //operator ==comparare
    bool operator<(Eveniment& e) {
        return this->durata < e.durata;
    }

    //operator++
    //post
    Eveniment operator++(int) {
        Eveniment copie = *this;
        if (durata >= 0) {
            this->durata++;
        }
        return copie;
    }
    //pre
    Eveniment operator++() {
        if (durata >= 0) {
            this->durata++;
        }
        return *this;
    }
};

void main() {
    Eveniment e;
    cout << e << endl;

    char locatie[] = { "Sala palatului" };
    Eveniment e1("VasileOrganizator", 21, 2, locatie);
    cout << e1 << endl;

    //eveniment terminat
    int oraCurenta = 22;
    if (e1.oraSfarsit(oraCurenta)) {
        cout << "a luat sfarsit" << endl;
    }
    else {
        cout << "nu a luat sfarsit" << endl;
    }
    cout << endl << endl;

    //constructor copiere
    Eveniment e2 = e1;
    cout << e2 << endl << endl;

    //apel operator = 
    e2 = e1;
    cout << e2.getDurata() << endl;

    //apelare ==
    if (e1 < e2) {
        cout << "primul e mai mic" << endl;
    }
    else {
        cout << "primul e mai mare" << endl;
    }
    cout << endl;
    cout << "operator ++ post" << endl;
    //call ++
    Eveniment e3 = e2++;
    cout << e2 << endl;
    cout << e1 << endl;
    cout << endl;
    cout << "operator ++ pre" << endl;
    Eveniment e4 = ++e3;
    cout << e2 << endl;
    cout << e1 << endl;

}
