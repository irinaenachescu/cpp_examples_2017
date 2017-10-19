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
		strcpy(this->adresa, "necunoscuta");
		this->an_constructie = 2000;
		this->confort = '2';
		this->numar_camere = 0;
		this->suprafete = NULL;

	}

	void afisare();

	Apartament(char* v_proprietar, char v_adresa[50], unsigned int v_an_constructie,
		char v_confort, int v_nr_camere, double* v_suprafete){
		this->proprietar = new char[strlen(v_proprietar) + 1];
		strcpy(this->proprietar, v_proprietar);
		strcpy(this->adresa, v_adresa);
		this->confort = v_confort;
		this->an_constructie = v_an_constructie;
		this->numar_camere = v_nr_camere;
		this->suprafete = new double[this->numar_camere];
		for (int i = 0; i < this->numar_camere; i++){
			this->suprafete[i] = v_suprafete[i];
		}

	}

	~Apartament(){
		cout << "In destructor..." << endl;
		if (this->proprietar != NULL){
			delete[] this->proprietar;
		}
		if (this->suprafete != NULL) {
			delete[] this->suprafete;
		}
	}
};

void Apartament::afisare(){
	cout << "Proprietar: " << this->proprietar << endl;
	cout << "Adresa: " << this->adresa << endl;
	cout << "An constructie: " << this->an_constructie << endl;
	cout << "Confort: " << this->confort << endl;
	cout << "Numar camere: " << this->numar_camere << endl;
	for (int i = 0; i < this->numar_camere; i++) {
		cout << "Suprafata camerei " << i + 1 << " este: " << this->suprafete[i] << endl;
	}

	
}


void main(){
	Apartament a1;
	a1.afisare();

	Apartament* pa1;
	pa1 = &a1;
	pa1->afisare();

	Apartament* pa2 = new Apartament();
	pa2->afisare();
	delete pa2;

	double v[3] = {10.5,16.3,12.5};
	Apartament a2("Irina", "strada x, nr y", 2010, '1', 3, v);
	a2.afisare();

}