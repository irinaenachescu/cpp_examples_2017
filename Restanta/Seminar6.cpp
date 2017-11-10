#include<iostream>
using namespace std;

class Apartament {
private:
	char* proprietar;
	char adresa[50];
	unsigned int an_constructie;
	char confort;
	int numar_camere;
	double* suprafete;

	const int id;
	static unsigned int numar_apartamente;
public:
	Apartament() :id(Apartament::numar_apartamente) {
		this->proprietar = new char[strlen("Anonim") + 1];
		strcpy(this->proprietar, "Anonim");
		strcpy(this->adresa, "Necunoscuta");
		this->an_constructie = 2000;
		this->confort = '2';
		this->numar_camere = 0;
		this->suprafete = NULL;
		Apartament::numar_apartamente += 1;

	}

	Apartament(char* v_proprietar, char v_adresa[50], char v_confort,
		unsigned int v_an_constructie, int v_numar_camere, double* v_suprafete)
		:id(Apartament::numar_apartamente++) {
		this->proprietar = new char[strlen(v_proprietar) + 1];
		strcpy(this->proprietar, v_proprietar);
		strcpy(this->adresa, v_adresa);
		this->confort = v_confort;
		this->an_constructie = v_an_constructie;
		this->numar_camere = v_numar_camere;
		this->suprafete = new double[this->numar_camere];
		for (int i = 0; i < this->numar_camere; i++) {
			this->suprafete[i] = v_suprafete[i];
		}
	}

	Apartament(char* v_proprietar, char v_adresa[50], char v_confort,
		unsigned int v_an_constructie = 2017)
		:an_constructie(v_an_constructie),
		id(Apartament::numar_apartamente++)
	{
		this->proprietar = new char[strlen(v_proprietar) + 1];
		strcpy(this->proprietar, v_proprietar);
		strcpy(this->adresa, v_adresa);
		this->confort = v_confort;
		this->numar_camere = 0;
		this->suprafete = NULL;
	}

	Apartament(const Apartament& sursa) :
		id(Apartament::numar_apartamente++) {
		this->proprietar = new char[strlen(sursa.proprietar) + 1];
		strcpy(this->proprietar, sursa.proprietar);
		strcpy(this->adresa, sursa.adresa);
		this->confort = sursa.confort;
		this->an_constructie = sursa.an_constructie;
		this->numar_camere = sursa.numar_camere;
		this->suprafete = new double[this->numar_camere];
		for (int i = 0; i < this->numar_camere; i++) {
			this->suprafete[i] = sursa.suprafete[i];
		}
	}

	void afisare();

	~Apartament() {
		cout << "In destructor..";
		if (this->proprietar != NULL) {
			delete[] this->proprietar;
		}
		if (this->suprafete != NULL) {
			delete[] this->suprafete;
		}
		Apartament::numar_apartamente--;
	}

	//getteri si setteri

	char* getProprietar() {
		return this->proprietar;
	}

	char* getAdresa() {
		return this->adresa;
	}

	//getter si setter pentru vector
	int getNumarCamere() {
		return this->numar_camere;
	}

	double* getSuprafete() {
		return this->suprafete;
	}

	//intotdeauna setez vectorul cu numarul de elemente
	void setSuprafete(double* v_suprafete, int v_numar_camere) {
		this->numar_camere = v_numar_camere;
		if (this->suprafete != NULL) {
			delete[] this->suprafete;
		}
		this->suprafete = new double[v_numar_camere];
		for (int i = 0; i < this->numar_camere; i++) {
			this->suprafete[i] = v_suprafete[i];
		}
	}

	void setProprietar(char* v_proprietar) {
		if (strlen(v_proprietar) < 3) {
			throw new exception("Nume prea scurt");
		}
		else {
			if (this->proprietar != NULL) {
				delete[] this->proprietar;
			}
			this->proprietar = new char[strlen(v_proprietar) + 1];
			strcpy(this->proprietar, v_proprietar);
		}
	}

	//doar getter pentru constant
	int getId() {
		return this->id;
	}

	//pentru static fac getter
	static unsigned int getNumarApartamente() {
		return Apartament::numar_apartamente;
	}

	static void setNumarApartamente(unsigned int nr) {
		Apartament::numar_apartamente = nr;
	}

	Apartament& operator=(const Apartament& sursa) {
		if (this->proprietar != NULL) {
			delete[] this->proprietar;
		}
		if (this->suprafete != NULL) {
			delete[] this->suprafete;
		}
		this->proprietar = new char[strlen(sursa.proprietar) + 1];
		strcpy(this->proprietar, sursa.proprietar);
		strcpy(this->adresa, sursa.adresa);
		this->confort = sursa.confort;
		this->an_constructie = sursa.an_constructie;
		this->numar_camere = sursa.numar_camere;
		this->suprafete = new double[this->numar_camere];
		for (int i = 0; i < this->numar_camere; i++) {
			this->suprafete[i] = sursa.suprafete[i];
		}

		return *this;
	}

	 friend ostream& operator<<(ostream& out, Apartament& a) {
		 out << "Id: " << a.id << endl;
		 out << "Proprietar: " << a.proprietar << endl;
		 out << "Adresa: " << a.adresa << endl;
		 out << "Confort: " << a.confort << endl;
		 out << "An: " << a.an_constructie << endl;
		 out << "Numar camere: " << a.numar_camere << endl;
		 for (int i = 0; i < a.numar_camere; i++) {
			 out << "\t " << a.suprafete[i] << endl;
		 }
		 return out;
	}

	 friend istream& operator >> (istream& in, Apartament& a)
	 {
		 cout << "Dati proprietar: ";
		 char buffer[50];
		 in >> buffer;

		 if (a.proprietar != NULL) {
			 delete[] a.proprietar;
		 }
		 a.proprietar = new char[strlen(buffer) + 1];
		 strcpy(a.proprietar, buffer);

		 cout << "Dati adresa: ";
		 in.ignore();
		 in.getline(a.adresa, 50);

		 cout << "Dati confort: ";
		 in >> a.confort;

		 cout << "Dati an: ";
		 in >> a.an_constructie;

		 cout << "Dati nr camere: ";
		 in >> a.numar_camere;

		 if (a.suprafete != NULL) {
			 delete[] a.suprafete;
		 }
		 a.suprafete = new double[a.numar_camere];
		 for (int i = 0; i < a.numar_camere; i++) {
			 cout << "Dati suprafata camerei " << i + 1 << ": ";
			 in >> a.suprafete[i];
		 }

		 return in;




	 }
};

unsigned int Apartament::numar_apartamente = 0;

void Apartament::afisare() {
	cout << "Id: " << this->id << endl;
	cout << "Proprietar: " << this->proprietar << endl;
	cout << "Adresa: " << this->adresa << endl;
	cout << "An constructie: " << this->an_constructie << endl;
	cout << "Confort: " << this->confort << endl;
	cout << "Numar camere: " << this->numar_camere << endl;
	for (int i = 0; i < this->numar_camere; i++) {
		cout << "Suprafata camerei " << i + 1 << " este: "
			<< this->suprafete[i] << endl;
	}
}

void main() {

	Apartament::setNumarApartamente(1000);
	Apartament a1;
	a1.afisare();

	Apartament* pa1;
	pa1 = &a1;
	pa1->afisare();

	Apartament* pa2;
	pa2 = new Apartament();
	delete pa2; //apel destructor

	cout << "-------------------------------------" << endl;

	double v[3] = { 15, 16.3, 18.6 };
	Apartament a2("Irina", "strada x", '1', 2019, 3, v);
	a2.afisare();

	Apartament* pa3 = new Apartament("Mihaela", "strada y", '2', 2007, 3, v);
	pa3->afisare();
	delete pa3;

	Apartament a3("Mihai", "strada z", '1');
	a3.afisare();

	Apartament* pa4 = new Apartament("Alex", "strada h", '2', 2020);
	pa4->afisare();
	delete pa4;

	Apartament a4 = a3; //constructor de copiere
	a4.afisare();

	Apartament a5;
	a5.setProprietar("Popescu");
	cout << "Proprietar: " << a5.getProprietar() << endl;

	cout << "************************************" << endl;
	Apartament a6;
	double vs[3] = { 15.6,18,19 };
	a6.setSuprafete(vs, 3);

	cout << "Numarul de camere: " << a6.getNumarCamere() << endl;
	for (int i = 0; i < a6.getNumarCamere(); i++) {
		cout << "Suprafata camerei " << i + 1 << " este: " <<
			a6.getSuprafete()[i] << endl;
	}

	cout << "Numarul de apartamente in total este: " <<
		Apartament::getNumarApartamente() << endl;

	cout << "*****************************" << endl;
	a6 = a5;
	a6.afisare();
	cout << a6;

	cin >> a6;
	cout << a6;
}