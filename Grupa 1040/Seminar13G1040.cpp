// Seminar13G1040.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class IntrareCalendar {
private:
	char dataCalendar[20];
	int ora;
	int minute;
	int secunde;

public:
	IntrareCalendar() {
		strcpy(this->dataCalendar, "01/01/2018");
		this->ora = 12;
		this->minute = 0;
		this->secunde = 0;
	}

	IntrareCalendar(char v_dataCalendar[20],
		int v_ora, int v_minute) {
		strcpy(this->dataCalendar, v_dataCalendar);
		this->ora = v_ora;
		this->minute = v_minute;
		this->secunde = 0;
	}

	friend ostream& operator<<(ostream& out,
		IntrareCalendar& ic) {
		out << "Data calendar: " << ic.dataCalendar << endl;
		out << "Ora: " << ic.ora << endl;
		out << "Minute: " << ic.minute << endl;
		out << "Secunde: " << ic.secunde << endl;

		return out;
	}

	friend istream& operator>>(istream& in,
		IntrareCalendar& ic) {
		cout << "Dati data calendar: ";
		in >> ic.dataCalendar;
		cout << "Dati ora: ";
		in >> ic.ora;
		cout << "Dati minutele: ";
		in >> ic.minute;
		cout << "Dati secundele: ";
		in >> ic.secunde;
		return in;
	}

	void setData(char v_dataCalendar[20]) {
		strcpy(this->dataCalendar, v_dataCalendar);
	}

	IntrareCalendar operator++(int) {
		IntrareCalendar copie = *this;
		if (this->minute == 59) {
			this->minute = 0;
			this->ora++;
		}
		else {
			this->minute++;
		}
		return copie;
	}

	int getOra() {
		return this->ora;
	}

	void setOra(int v_ora) {
		this->ora = v_ora;
	}

	int getMinute() {
		return this->minute;
	}
};

class Eveniment {
private:
	const int idIntrare;
	IntrareCalendar data;
	char* detalii;
	static int nrIntrari;

public:
	~Eveniment() {
		if (this->detalii != NULL) {
			delete[] this->detalii;
		}
		Eveniment::nrIntrari--;
	}
	Eveniment(int v_idIntrare, IntrareCalendar
		v_data):idIntrare(v_idIntrare) {
		this->data = v_data;
		this->detalii = new char[strlen("") + 1];
		strcpy(this->detalii, "");

		Eveniment::nrIntrari++;
	}

	Eveniment(int v_idIntrare, IntrareCalendar
		v_data, char* v_detalii)
	:idIntrare(v_idIntrare) {
		this->data = v_data;
		this->detalii = new char[strlen(v_detalii) + 1];
		strcpy(this->detalii, v_detalii);

		Eveniment::nrIntrari++;
	}

	Eveniment(const Eveniment& sursa)
	:idIntrare(sursa.idIntrare){
		this->data = sursa.data;
		this->detalii = new char[strlen(sursa.detalii) + 1];
		strcpy(this->detalii, sursa.detalii);

		Eveniment::nrIntrari++;
	}

	Eveniment& operator=(const Eveniment& sursa) {
		if (this->detalii != NULL) {
			delete[] this->detalii;
		}
		this->data = sursa.data;
		this->detalii = new char[strlen(sursa.detalii) + 1];
		strcpy(this->detalii, sursa.detalii);

		return *this;
	}

	void setDetalii(char* v_detalii) {
		if (this->detalii != NULL) {
			delete[] this->detalii;
		}
		this->detalii = new char[strlen(v_detalii) + 1];
		strcpy(this->detalii, v_detalii);
	}

	friend ostream& operator<<(ostream& out, Eveniment& e) {
		out << "Id intrare: " << e.idIntrare << endl;
		out << e.data;
		out << "Detalii: " << e.detalii << endl;

		return out;
	}

	Eveniment& operator+=(int v_ore) {
		this->data.setOra(this->data.getOra() + v_ore);

		return *this;
	}

	explicit operator int() {
		return this->data.getOra() * 60 +
			this->data.getMinute();
	}

	static int total() {
		return Eveniment::nrIntrari;
	}

	friend istream& operator>>(istream& in,
		Eveniment& e) {
		in >> e.data;
		cout << "Dati detaliile: ";
		char buffer[50];
		in.ignore();
		in.getline(buffer, 50);
		e.setDetalii(buffer);

		return in;
	}


};

int Eveniment::nrIntrari = 0;

void main()
{
	IntrareCalendar m1; //ora 12, 1 ian an curent
	IntrareCalendar m2("23/01/2017", 9, 30);
	IntrareCalendar m3 = m2;
	//cin >> m1;
	cout << m1 << m2 << m3;
	m2.setData("23.01.2017");
	m3 = m1;
	IntrareCalendar m4 = m2++;
	cout << m2 << m3 << m4;

	Eveniment e1(1, m2);
	Eveniment e2(2, m4, "Examen POO");
	e1.setDetalii("Pregatire examen");
	e1 += 2;
	cout << e1;

	cin >> e1;
	int totalMinute = (int)e1;
	cout << "Total minute: " << totalMinute << endl;
	cout << "Total evenimente: " << Eveniment::total() << endl;
}

