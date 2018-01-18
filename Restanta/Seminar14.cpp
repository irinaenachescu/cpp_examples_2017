#include<iostream>
#include<fstream>
using namespace std;

class Calc {
private:
	float pret;
public:
	int idCalc;
	char marca[30];
	Calc(int v_idCalc, char v_marca[30], float v_pret) {
		this->idCalc = v_idCalc;
		strcpy(this->marca, v_marca);
		this->pret = v_pret;
	}
	Calc() {
		this->idCalc = 1000;
		strcpy(this->marca, "No name");
		this->pret = 2000;
	}

	friend ostream& operator<<(ostream& out,
		Calc& c) {
		out << "Id calc: " << c.idCalc << endl;
		out << "Marca: " << c.marca << endl;
		out << "Pret: " << c.pret << endl;

		return out;
	}

	friend ofstream& operator<<(ofstream& out,
		Calc& c) {
		out <<  c.idCalc << endl;
		out <<  c.marca << endl;
		out <<  c.pret << endl;

		return out;
	}

	float getPret() {
		return this->pret;
	}
};


class Pers {
public:
	int idPers;
	char nume[30];
	Calc* pCalc;
	int idCalc;

	Pers() {
		this->idPers = 100;
		strcpy(this->nume, "Anonim");
		this->pCalc = NULL;
		this->idCalc = 0;
	}
	Pers(int v_idPers, char v_nume[30]) {
		this->idPers = v_idPers;
		strcpy(this->nume, v_nume);
		this->pCalc = NULL;
		this->idCalc = 0;
	}

	friend ostream& operator<<(ostream& out, Pers& p) {
		out << "Id pers: " << p.idPers << endl;
		out << "Nume: " << p.nume << endl;
		if (p.pCalc != NULL) {
			out << "Info calculator: " << endl;
			out << *p.pCalc;
		}
		else {
			out << "Fara calculator" << endl;
		}
		return out;
	}

	void operator<<(Calc& c) {
		this->pCalc = &c;
		this->idCalc = c.idCalc;
	}

	friend void operator >> (Calc&c, Pers& p) {
		p.pCalc = &c;
		p.idCalc = c.idCalc;
	}

	friend bool operator>(Pers& p, Calc& c) {
		return p.pCalc->getPret() > c.getPret();
	}

	bool operator>(Pers& p2) {
		return this->pCalc->getPret() > p2.pCalc->getPret();
	}
};
void main() {
	Pers p1(123, "Popescu"), p2, p3, p4;
	//100, Anonim, null si 0
	Calc c1(1001, "Fujitsu", 3200),
		c2(1002, "Acer", 3500), c3, c4;
	//1000, No name, 2000
	cout << c1;


	//p1 << c1;
	p2 << c2;
	c1 >> p1;

	cout << p1 << p2;

	p4.pCalc = new Calc(1004, "Dell", 4000);
	if (p1 > c2) {
		cout << p1.nume << " are un calculator mai scump decat " << c2.marca << endl;
	}
	else {
		cout << p1.nume << " are un calculator mai ieftin decat " << c2.marca << endl;
	}

	if (p1 > p2) {
		cout << p1.nume << " are un calculator mai scump decat " << p2.nume << endl;
	}
	else {
		cout << p1.nume << " are un calculator mai ieftin decat " << p2.nume << endl;
	}

	ofstream  calcOut;
	calcOut.open("Calc.txt", fstream::out);
	if (calcOut.is_open()) {
		calcOut << c1;
		calcOut << c2;
		calcOut.close();
	}
	else {
		cout << "Eroare la scrierea in fisier.";
	}
}