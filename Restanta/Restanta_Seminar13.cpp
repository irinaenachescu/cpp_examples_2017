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

	IntrareCalendar(char v_dataCalendar[20], int v_ora, int v_minute) {
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

	friend istream& operator >> (istream& in,
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
		//cresc min in this;
		if (this->minute == 59) {
			this->minute = 0;
			this->ora++;
		}
		else {
			this->minute++;
		}
		return copie;
	}

	void setOra(int v_ora) {
		this->ora = v_ora;
	}

	int getOra() {
		return this->ora;
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
	Eveniment(int v_idIntrare, IntrareCalendar v_data)
	:idIntrare(v_idIntrare){
		this->data = v_data;
		this->detalii = new char[strlen("") + 1];
		strcpy(this->detalii, "");

		Eveniment::nrIntrari++;
	}

	Eveniment(int v_idIntrare, IntrareCalendar
		v_data, char* v_detalii)
	:idIntrare(v_idIntrare){
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

	~Eveniment() {
		if (this->detalii != NULL) {
			delete[] this->detalii;
		}
		Eveniment::nrIntrari--;
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

	friend ostream& operator<<(ostream& out,
		Eveniment& e) {
		out << "Id intrare: " << e.idIntrare << endl;
		out << e.data; //apeleaza << din IntrareCalendar
		out << "Detalii: " << e.detalii << endl;

		return out;
	}

	Eveniment& operator+=(int v_ore) {
		this->data.setOra(this->data.getOra() +
			v_ore);

		return *this;
	}

	//total minute
	explicit operator int() {
		return this->data.getOra() * 60 +
			this->data.getMinute();
	}

	static int total() {
		return Eveniment::nrIntrari;
	}

	friend istream& operator >> (istream& in,
		Eveniment& e) {
		in >> e.data; //apel la operatorul>> din IntrareCalendar
		cout << "Dati detalii: ";
		char buffer[50];
		in.ignore();
		in.getline(buffer, 50);
		e.setDetalii(buffer);

		return in;

	}
};

int Eveniment::nrIntrari = 0;
void main() {
	IntrareCalendar m1;//01 Ian an curent, ora 12
	IntrareCalendar m2("11/01/2018", 9, 30);
	IntrareCalendar m3 = m2;
	//cin >> m1;
	cout << m1 << m2 << m3;
	m2.setData("11.01.2018");
	m3 = m1;
	IntrareCalendar m4 = m2++; //incrementare min
	cout << m2 << m3 << m4;

	Eveniment e1(1, m2);
	Eveniment e2(2, m4, "Examen POO");
	e1.setDetalii("Pregatire examen POO");
	e1 += 2; //adauga 2 ore
	cout << e1;

	//cin >> e1;
	int totalMinute = (int)e1;
	cout << totalMinute << endl;
	cout << "Total evenimente: " << Eveniment::total() << endl;

	Eveniment** agenda;
	int nrEvenimente;

	//initializare agenda cu min 3 ev citite de la consola
	cout << "Dati nr de evenimente: ";
	cin >> nrEvenimente;

	agenda = new Eveniment*[nrEvenimente];
	for (int i = 0; i < nrEvenimente; i++) {
		Eveniment* e = new Eveniment(
			Eveniment::total() + 1,
			IntrareCalendar(),
			""
		);
		cin >> *e;
		agenda[i] = e;
	}

	//afisare agenda
	cout << "--------Afisare agenda---------" << endl;
	for (int i = 0; i < nrEvenimente; i++) {
		cout << *agenda[i];
	}

}
