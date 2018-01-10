// Seminar13G1036.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <map>

using namespace std;

class Calc {
private:
	float pret;
public:
	int idCalc;
	char marca[30];
	Calc() {
		this->idCalc = 1000;
		strcpy(this->marca, "Noname");
		this->pret = 2000;
	}

	Calc(int v_idCalc, char v_marca[30], float v_pret) {
		this->idCalc = v_idCalc;
		strcpy(this->marca, v_marca);
		this->pret = v_pret;
	}

	friend ostream& operator<<(ostream& out, Calc& c) {
		out << "Id Calc: " << c.idCalc << endl;
		out << "Marca: " << c.marca << endl;
		out << "Pret: " << c.pret << endl;

		return out;
	}

	int getIdCalc() {
		return this->idCalc;
	}

	float getPret() {
		return this->pret;
	}

	friend ofstream& operator<<(ofstream& out,
		Calc& c) {
		out << c.idCalc << endl;
		out << c.marca << endl;
		out << c.pret << endl;

		return out;
	}

	friend ifstream& operator>>(ifstream& in,
		Calc& c) {
		in >> c.idCalc;
		in >> c.marca;
		in >> c.pret;

		return in;
	}
};

class Pers {
private:
	int idPers;
public:
	int idCalc;
	char nume[30];
	Calc* pCalc;
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
		out << "Id Pers: " << p.idPers << endl;
		out << "Nume: " << p.nume << endl;
		if (p.pCalc != NULL) {
			out << *p.pCalc;
		}
		else {
			out << "Fara calculator." << endl;
		}

		return out;
	}

	void operator<<(Calc& c) {
		this->pCalc = &c;
		this->idCalc = c.getIdCalc();
	}

	bool operator>(Calc& c) {
		return this->pCalc->getPret() > c.getPret();
	}

	bool operator>(Pers& p) {
		return this->pCalc->getPret() >
			p.pCalc->getPret();
	}

	friend ofstream& operator<<(ofstream& out,
	    Pers& p) {
		out << p.idPers << endl;
		out << p.nume << endl;
		out << p.idCalc << endl;

		return out;
	}

	friend ifstream& operator>>(ifstream& in,
		Pers& p) {
		in >> p.idPers;
		in >> p.nume;
		in >> p.idCalc;

		return in;
	}
};

void main()
{
	//1 pct
	Pers p1(123, "Popescu"), p2, p3, p4;
	//100, Anonim, null si 0

	Calc c1(1001, "Fujitsu", 3200),
		c2(1002, "Acer", 3500), c3, c4;
	//1000, "Noname",2000

	//2 pct
	p1 << c1; p2 << c2;
	cout << c1;

	//1 pct
	cout << p1 << p2;

	p4.pCalc = new Calc(1004, "Dell", 2500);
	if (p1 > c2) {
		cout << p1.nume << " are un calculator"
			<< " mai scump decat " << c2.marca << endl;

	}
	else {
		cout << p1.nume << " are un calculator"
			<< " mai ieftin decat " << c2.marca << endl;
	}

	if (p1 > p2) {
		cout << p1.nume << " are calculator mai scump decat " <<
			p2.nume;
	}
	else {
		cout << p1.nume << " are calculator mai ieftin decat " <<
			p2.nume;
	}

	ofstream calcOut, persOut;
	calcOut.open("Calculatoare.txt", fstream::out);
	persOut.open("Persoane.txt", fstream::out);
	calcOut << c1; calcOut << c2;
	calcOut.close();
	persOut << p1; persOut << p2; //fara pCalc
	persOut.close();

	ifstream calcInp;
	calcInp.open("Calculatoare.txt", fstream::in);
	if (calcInp.is_open()) {
		calcInp >> c3; calcInp >> c4;
		calcInp.close();
	}
	cout << "Restaurare calculatoare: " << endl;
	cout << c3 << c4;

	map<int, Calc> reteaCalc;
	reteaCalc.insert(pair<int, Calc>(c3.idCalc, c3));
	reteaCalc.insert(pair<int, Calc>(c4.idCalc, c4));

	cout << "---------------Map-------------" << endl;
	map<int, Calc>::iterator it;
	for (it = reteaCalc.begin(); it != reteaCalc.end(); it++) {
		cout << "Key: " << it->first << endl;
		cout << "Value: " << endl;
		cout << it->second;
	}

	ifstream persInp;
	persInp.open("Persoane.txt", fstream::in);
	if (persInp.is_open()) {
		persInp >> p3;
		persInp >> p4;
		persInp.close();
	}
	it = reteaCalc.find(p3.idCalc);
	p3.pCalc = &(it->second);
	cout << p3;
	
}

