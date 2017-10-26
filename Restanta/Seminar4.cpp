#include<iostream>
using namespace std;

class Apartament{
private:
	char* proprietar;
	char adresa[50];
	unsigned int an_constructie;
	char confort;
	int numar_camere;
	double* suprafete;
public:
	Apartament(){
		this->proprietar = new char[strlen("Anonim") + 1];
		strcpy(this->proprietar, "Anonim");
		strcpy(this->adresa, "Necunoscuta");
		this->an_constructie = 2000;
		this->confort = '2';
		this->numar_camere = 0;
		this->suprafete = NULL;

	}

	Apartament(char* v_proprietar, char v_adresa[50], char v_confort,
		unsigned int v_an_constructie, int v_numar_camere, double* v_suprafete){
		this->proprietar = new char[strlen(v_proprietar) + 1];
		strcpy(this->proprietar, v_proprietar);
		strcpy(this->adresa, v_adresa);
		this->confort = v_confort;
		this->an_constructie = v_an_constructie;
		this->numar_camere = v_numar_camere;
		this->suprafete = new double[this->numar_camere];
		for (int i = 0; i < this->numar_camere; i++){
			this->suprafete[i] = v_suprafete[i];
		}
	}

	Apartament(char* v_proprietar, char v_adresa[50], char v_confort,
		unsigned int v_an_constructie = 2017)
		:an_constructie(v_an_constructie)
	{
		this->proprietar = new char[strlen(v_proprietar) + 1];
		strcpy(this->proprietar, v_proprietar);
		strcpy(this->adresa, v_adresa);
		this->confort = v_confort;
		this->numar_camere = 0;
		this->suprafete = NULL;
	}

	Apartament(const Apartament& sursa){
		this->proprietar = new char[strlen(sursa.proprietar) + 1];
		strcpy(this->proprietar, sursa.proprietar);
		strcpy(this->adresa, sursa.adresa);
		this->confort = sursa.confort;
		this->an_constructie = sursa.an_constructie;
		this->numar_camere = sursa.numar_camere;
		this->suprafete = new double[this->numar_camere];
		for (int i = 0; i < this->numar_camere; i++){
			this->suprafete[i] = sursa.suprafete[i];
		}
	}

	void afisare();

	~Apartament(){
		cout << "In destructor..";
		if (this->proprietar != NULL){
			delete[] this->proprietar;
		}
		if (this->suprafete != NULL){
			delete[] this->suprafete;
		}
	}

	//getteri si setteri

	char* getProprietar(){
		return this->proprietar;
	}

	char* getAdresa(){
		return this->adresa;
	}

	void setProprietar(char* v_proprietar){
		if (strlen(v_proprietar) < 3){
			throw new exception("Nume prea scurt");
		}
		else{
			if (this->proprietar != NULL){
				delete[] this->proprietar;
			}
			this->proprietar = new char[strlen(v_proprietar) + 1];
			strcpy(this->proprietar, v_proprietar);
		}
	}
};

void Apartament::afisare(){
	cout << "Proprietar: " << this->proprietar << endl;
	cout << "Adresa: " << this->adresa << endl;
	cout << "An constructie: " << this->an_constructie << endl;
	cout << "Confort: " << this->confort << endl;
	cout << "Numar camere: " << this->numar_camere << endl;
	for (int i = 0; i < this->numar_camere; i++){
		cout << "Suprafata camerei " << i + 1 << " este: "
			<< this->suprafete[i] << endl;
	}
}

void main() {
	Apartament a1;
	a1.afisare();

	Apartament* pa1;
	pa1 = &a1;
	pa1->afisare();

	Apartament* pa2;
	pa2 = new Apartament();
	delete pa2; //apel destructor

	cout << "-------------------------------------" << endl;

	double v[3] = {15,16.3,18.6};
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
}