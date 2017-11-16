#include<iostream>
using namespace std;

class Apartament
{
private:
	char* adresa; //sir de caractere alocat dinamic
	char proprietar[50]; //sir de caractere alocat static
	const unsigned int an_constructie; //constant
	char confort; 
	double pret;
	unsigned int numar_camere;
	float* suprafete_camere; //vector alocat dinamic

	static int numar_apartamente; //atribut static

public:
	//constructor fara parametri
	//atributele constante se initializeaza obligatoriu in lista de initializari a constructorului dupa :
	//daca sunt mai multe atribute constante atunci ele se vor separa prin virgula
	Apartament():an_constructie(2000) {
		this->adresa = new char[strlen("Necunoscuta") + 1];
		strcpy(this->adresa, "Necunoscuta");
		strcpy(this->proprietar, "Necunoscut");
		this->confort = '1';
		this->pret = 0;
		this->numar_camere = 0;
		this->suprafete_camere = NULL;

		//incrementez variabila statica pentru ca s-a creat un apartament nou
		Apartament::numar_apartamente++;
	}

	//constructor cu toti parametrii
	Apartament(char* v_adresa, char v_proprietar[50], char v_confort, 
		unsigned int v_an_constructie, double v_pret,
		unsigned int v_numar_camere, float* v_suprafete_camere)
		:an_constructie(v_an_constructie){
		//pentru sirurile de caractere alocate dinamic este obligatoriu sa se aloce memorie inainte de initializare
		this->adresa = new char[strlen(v_adresa) + 1];
		//initializarea sirurilor de caractere se face mereu cu strcpy. Nu se va folosi operatorul = !!!
		strcpy(this->adresa, v_adresa);

		//pentru sirurile de caractere alocate static nu se va aloca memorie in prealabil
		strcpy(this->proprietar, v_proprietar);

		this->confort = v_confort;
		this->pret = v_pret;
		this->numar_camere = v_numar_camere;

		//pentru vectorii alocati dinamic este obligatoriu sa se aloce memorie inainte de initializare
		this->suprafete_camere = new float[v_numar_camere];
		//copierea valorilor de la un vector la altul se va face obligatoriu asa si nu cu operatorul = !!!
		for (int i = 0; i < v_numar_camere; i++)
		{
			this->suprafete_camere[i] = v_suprafete_camere[i];
		}
		//incrementez variabila statica pentru ca s-a creat un apartament nou
		Apartament::numar_apartamente += 1;
	}


	//constructor cu parametri cu valori implicite
	//pentru atributul confort, implicit este valoarea 3
	Apartament(char* v_adresa, char v_proprietar[50], unsigned int v_an_constructie,
		double v_pret,
		unsigned int v_numar_camere, float* v_suprafete_camere, char v_confort = '3')
		:an_constructie(v_an_constructie), confort(v_confort)
	{
		//pentru sirurile de caractere alocate dinamic este obligatoriu sa se aloce memorie inainte de initializare
		this->adresa = new char[strlen(v_adresa) + 1];
		//initializarea sirurilor de caractere se face mereu cu strcpy. Nu se va folosi operatorul = !!!
		strcpy(this->adresa, v_adresa);

		//pentru sirurile de caractere alocate static nu se va aloca memorie in prealabil
		strcpy(this->proprietar, v_proprietar);

		this->pret = v_pret;
		this->numar_camere = v_numar_camere;

		//pentru vectorii alocati dinamic este obligatoriu sa se aloce memorie inainte de initializare
		this->suprafete_camere = new float[v_numar_camere];
		//copierea valorilor de la un vector la altul se va face obligatoriu asa si nu cu operatorul = !!!
		for (int i = 0; i < v_numar_camere; i++)
		{
			this->suprafete_camere[i] = v_suprafete_camere[i];
		}
		//incrementez variabila statica pentru ca s-a creat un apartament nou
		Apartament::numar_apartamente += 1;
	}

	//destructor
	//obligatoriu daca avem cel putin un camp alocat dinamic in clasa
	~Apartament() {
		if (this->adresa != NULL)
		{
			delete[] this->adresa;
		}

		if (this->suprafete_camere != NULL)
		{
			delete[] this->suprafete_camere;
		}

		//decrementez variabila statica pentru ca s-a distrus un apartament
		Apartament::numar_apartamente--;
	}

	//constructor de copiere
	//permite crearea unui obiect nou pe baza unui obiect existent
	//obligatoriu daca avem cel putin un atribut alocat dinamic in clasa
	Apartament(const Apartament& sursa) :an_constructie(sursa.an_constructie)
	{
		//pentru sirurile de caractere alocate dinamic este obligatoriu sa se aloce memorie inainte de initializare
		this->adresa = new char[strlen(sursa.adresa) + 1];
		//initializarea sirurilor de caractere se face mereu cu strcpy. Nu se va folosi operatorul = !!!
		strcpy(this->adresa, sursa.adresa);

		//pentru sirurile de caractere alocate static nu se va aloca memorie in prealabil
		strcpy(this->proprietar, sursa.proprietar);

		this->confort = sursa.confort;
		this->pret = sursa.pret;
		this->numar_camere = sursa.numar_camere;

		//pentru vectorii alocati dinamic este obligatoriu sa se aloce memorie inainte de initializare
		this->suprafete_camere = new float[sursa.numar_camere];
		//copierea valorilor de la un vector la altul se va face obligatoriu asa si nu cu operatorul = !!!
		for (int i = 0; i < sursa.numar_camere; i++)
		{
			this->suprafete_camere[i] = sursa.suprafete_camere[i];
		}

		//incrementez variabila statica pentru ca s-a creat un apartament nou
		Apartament::numar_apartamente = Apartament::numar_apartamente + 1;
	}

	//supraincarcarea operatorului= 
	//obligatoriu daca avem cel putin un atribut alocat dinamic in clasa si dorim sa copiem valorile unui
	//obiect intr-altul
	Apartament& operator=(const Apartament& sursa)
	{
		/*pentru ca in obiectul curent atributele sunt deja initalizate se vor face verificari pentru 
		a se dezaloca inainte memoria ocupata de atributele care sunt alocate dinamic.
		Se evita astfel crearea de memory leaks.
		*/

		if (this->adresa != NULL)
		{
			delete[] this->adresa;
		}
		//pentru sirurile de caractere alocate dinamic este obligatoriu sa se aloce memorie inainte de initializare
		this->adresa = new char[strlen(sursa.adresa) + 1];
		//initializarea sirurilor de caractere se face mereu cu strcpy. Nu se va folosi operatorul = !!!
		strcpy(this->adresa, sursa.adresa);

		//pentru sirurile de caractere alocate static nu se va aloca memorie in prealabil
		strcpy(this->proprietar, sursa.proprietar);

		this->confort = sursa.confort;
		this->pret = sursa.pret;
		this->numar_camere = sursa.numar_camere;

		if (this->suprafete_camere != NULL)
		{
			delete[] this->suprafete_camere;
		}
		//pentru vectorii alocati dinamic este obligatoriu sa se aloce memorie inainte de initializare
		this->suprafete_camere = new float[sursa.numar_camere];
		//copierea valorilor de la un vector la altul se va face obligatoriu asa si nu cu operatorul = !!!
		for (int i = 0; i < sursa.numar_camere; i++)
		{
			this->suprafete_camere[i] = sursa.suprafete_camere[i];
		}

		//returnez mereu obiectul curent, cel in care am copiat valorile din sursa
		return *this;
	}

	//supraincarcarea operatorului << pentru clasa Apartament
	friend ostream& operator<<(ostream& o, Apartament apartament)
	{
		o << "==========================" << endl;
		o << "Adresa: " << apartament.adresa << endl;
		o << "Proprietar: " << apartament.proprietar << endl;
		o << "Tip confort: " << apartament.confort << endl;
		o << "An constructie: " << apartament.an_constructie << endl;
		o << "Pret: " << apartament.pret << endl;
		o << "Numar de camere: " << apartament.numar_camere << endl;
		if (apartament.numar_camere > 0)
		{
			o << "Suprafata camerelor: " << endl;
			for (int i = 0; i < apartament.numar_camere; i++)
			{
				o << "Camera " << i + 1 << " are: " << apartament.suprafete_camere[i] << " mp." << endl;
			}
		}
		o << "==========================" << endl;

		return o;
	}

	/*
		GETTERI si SETTERI (Interfata publica a atributelor)
	*/

	//getter pentru adresa
	char* getAdresa()
	{
		return this->adresa;
	}

	//setter pentru adresa
	void setAdresa(char* v_adresa)
	{
		/*pentru ca in obiectul curent adresa este deja initalizata se face verificare pentru
		a se dezaloca inainte memoria ocupata de atributul alocat dinamic adresa.
		Se evita astfel crearea de memory leaks.
		*/
		if (this->adresa != NULL)
		{
			delete[] this->adresa;
		}
		this->adresa = new char[strlen(v_adresa) + 1];
		strcpy(this->adresa, v_adresa);
	}

	//getter pentru proprietar
	char* getProprietar()
	{
		return this->proprietar;
	}

	//setter pentru proprietar
	void setProprietar(char v_proprietar[50])
	{
		//pentru ca atributul proprietar e alocat static nu este nevoie sa se dezaloce 
		//respectiv sa se aloce memorie inainte
		strcpy(this->proprietar, v_proprietar);
	}

	//getter pentru atributul constant an constructie. Un atribut constant are doar getter (nu are setter).
	unsigned int getAnConstructie()
	{
		return this->an_constructie;
	}

	//getter pentru confort 
	char getConfort()
	{
		return this->confort;
	}

	//setter pentru confort
	void setConfort(char v_confort)
	{
		this->confort = v_confort;
	}

	//getter pentru pret
	double getPret()
	{
		return this->pret;
	}

	//setter pentru pret
	void setPret(double v_pret)
	{
		this->pret = v_pret;
	}

	//getter pentru atributul static numar_apartamente
	static int getNumarApartamente()
	{
		return Apartament::numar_apartamente;
	}

	//setter pentru numar_camere
	//Se vor trimite ca parametri atat vectorul cu valori cat si numarul de elemente
	void setSuprafeteCamere(float* v_suprafete_camere, unsigned int v_numar_camere)
	{
		this->numar_camere = v_numar_camere;
		if (this->suprafete_camere != NULL)
		{
			delete[] this->suprafete_camere;
		}
		this->suprafete_camere = new float[v_numar_camere];
		for (int i = 0; i < v_numar_camere; i++)
		{
			this->suprafete_camere[i] = v_suprafete_camere[i];
		}
	}

	//getter pentru suprafete camere
	float* getSuprafeteCamere()
	{
		return this->suprafete_camere;
	}

	//getter pentru numar camere
	unsigned int getNumarCamere()
	{
		return this->numar_camere;
	}

	//supraincarcarea operatorului >> pentru clasa Apartament
	friend istream& operator>>(istream& i, Apartament& apartament)
	{
		char buffer[50];
		cout << "Dati adresa: ";
		i.getline(buffer, 50);
		if (apartament.adresa != NULL)
		{
			delete[] apartament.adresa;
		}
		apartament.adresa = new char[strlen(buffer) + 1];
		strcpy(apartament.adresa, buffer);
		cout << "Dati proprietarul: ";
		i.getline(apartament.proprietar, 50);
		cout << "Dati gradul de confort: ";
		i >> apartament.confort;
		cout << "Dati pretul: ";
		i >> apartament.pret;
		cout << "Dati numarul de camere: ";
		i >> apartament.numar_camere;
		if (apartament.suprafete_camere != NULL)
		{
			delete[] apartament.suprafete_camere;
		}
		apartament.suprafete_camere = new float[apartament.numar_camere];
		for (int k = 0; k < apartament.numar_camere; k++)
		{
			cout << "Dati suprafata camerei " << k + 1 << ": ";
			i >> apartament.suprafete_camere[k];
		}
		return i;
	}

	//metoda membra a clasei care calculeaza suprafata medie a unei camere intr-un apartament
	float calculeazaSuprafataMedie()
	{
		if (this->numar_camere == 0)
		{
			return 0;
		}
		else
		{
			float v_suprafata = 0;
			for (int i = 0; i < this->numar_camere; i++)
			{
				v_suprafata += this->suprafete_camere[i];
			}
			return v_suprafata/this->numar_camere;
		}
	}

	//supraincarcarea operatorului ++ (forma prefixata)
	//Acesta va creste numarul de camere cu 1
	//Noua camera va avea implicit suprafata de 6 mp
	Apartament& operator++()
	{
		//creez un vector nou de suprafete care sa includa si noua camera
		float* v_suprafete_camere = new float[this->numar_camere + 1];
		//copiez suprafele existente
		for (int i = 0; i < this->numar_camere; i++)
		{
			v_suprafete_camere[i] = this->suprafete_camere[i];
		}
		//includ si suprafata camerei recent adaugate
		v_suprafete_camere[this->numar_camere] = 6;
		this->numar_camere++;
		if (this->suprafete_camere != NULL)
		{
			delete[] this->suprafete_camere;
		}
		this->suprafete_camere = v_suprafete_camere;

		return *this;
	}

	//supraincarcarea oepratorului ++ (forma postfixata)
	//Acesta va creste numarul de camere cu 1
	//Noua camera va avea implicit suprafata de 6 mp
	Apartament operator++(int)
	{
		Apartament copie = *this;
		//creez un vector nou de suprafete care sa includa si noua camera
		float* v_suprafete_camere = new float[this->numar_camere + 1];
		//copiez suprafele existente
		for (int i = 0; i < this->numar_camere; i++)
		{
			v_suprafete_camere[i] = this->suprafete_camere[i];
		}
		//includ si suprafata camerei recent adaugate
		v_suprafete_camere[this->numar_camere] = 6;
		this->numar_camere++;
		if (this->suprafete_camere != NULL)
		{
			delete[] this->suprafete_camere;
		}
		this->suprafete_camere = v_suprafete_camere;

		return copie;
	}

	//supraincarcarea operatorului + care aduna 2 apartamente
	//Rezultatul va fi un apartament care are ambii proprietari
	//restul informatiilor vor fi preluate de la primul proprietar
	Apartament operator+(Apartament apartament)
	{
		Apartament copie = *this;
		//concatenam proprietarii
		char* v_proprietar = strcat(this->proprietar, " si ");
		strcat(v_proprietar, apartament.proprietar);
		//actualizam proprietarul
		strcpy(copie.proprietar, v_proprietar);
		return copie;
	}

	//supraincarcarea operatorului *=
	//Se va actualiza pretul apartamentului cu un procent primit ca parametru
	Apartament& operator*=(int procent)
	{
		this->pret *= 1+ (float)procent / 100;
		return *this;
	}

	//supraincarcarea operatorului - care scade pretul unui apartament cu o valoare primita ca parametru -> a-100
	friend Apartament operator-(Apartament apartament, double v_pret)
	{
		Apartament copie = apartament;
		copie.pret -= v_pret;
		return copie;
	}

	//supraincarcarea operatorului - care scade dintr-o valoare primita ca parametru pretul unui apartament ->100-a
	friend Apartament operator-(double v_pret, Apartament apartament)
	{
		Apartament copie = apartament;
		copie.pret = v_pret - copie.pret;
		return copie;
	}

	//supraincarcarea operatorului de indexare care sa permita accesul la suprafata unei camere
	//dupa indexul acesteia
	float& operator[](int index)
	{
		if (index < 0 || index >= this->numar_camere)
		{
			cout << "Index in afara limitelor!" << endl;
			throw new exception("Index in afara limitelor!");
		}
		else 
		{
			return this->suprafete_camere[index];
		}
	}

	//supraincarcarea operatorului cast care face cast de la un apartament la pretul sau
	explicit operator double()
	{
		return this->pret;
	}

	//supraincarcarea operatorului functie care calculeaza suprafata totala a apartamentului
	float operator()()
	{
		float v_suprafata = 0;
		for (int i = 0; i < this->numar_camere; i++)
		{
			v_suprafata += this->suprafete_camere[i];
		}
		return v_suprafata;
	}

	//supraincarcarea operatorului == care verifica daca 2 apartamente sunt egale
	//2 apartamente sunt considerate egale daca au aceeasi adresa si acelasi proprietar
	bool operator==(Apartament apartament)
	{
		if (strcmp(this->adresa, apartament.adresa) == 0
			&& strcmp(this->proprietar, apartament.proprietar) == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//supraincarcarea operatorului! care returneaza false in cazul in care vectorul de suprafete
	//este NULL si true in caz contrar
	bool operator!()
	{
		if (this->suprafete_camere == NULL)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
};

//initializare variabila statica
int Apartament::numar_apartamente = 0;

void main()
{
	//testare constructor fara parametri
	Apartament a1;

	//verificare supraincarcare operator<<
	cout << a1;

	//initializare vector cu 2 elemente pentru a fi folosit la parametru la suprafetele camerelor
	float v[2] = { 9.5, 12.6 };
	//testare constructor cu toti parametrii
	Apartament a2("Str. Mihail Moxa", "Irina Enachescu", '1', 2010, 90000, 2, v);
	cout << a2;

	//testare constructor de copiere
	Apartament a3 = a2;
	cout << a3;

	//testare operator=
	Apartament a4;
	a4 = a3;
	cout << a4;

	//testare constructor cu valori implicite
	Apartament a5("Blvd. Constructorilor", "Popescu Ion", 2013, 95000, 2, v);
	cout << a5;

	//testare constructor cu valori implicite
	Apartament a6("Blvd. Constructorilor", "Popescu Ion", 2013, 95000, 2, v, '2');
	cout << a6;

	//testare metoda membra a clasei calculeazaSuprafataMedie
	cout << "Suprafata medie a unei camere pentru apartamentul 6 este: " 
		<< a6.calculeazaSuprafataMedie() << endl;

	//testare getteri si setteri
	Apartament a7; //apartament initializat prin constructorul fara parametri
	cout << a7;

	//apel setteri
	a7.setAdresa("Blvd. Iuliu Maniu");
	a7.setProprietar("Mihai Pop");
	a7.setConfort('2');
	a7.setPret(65700.5);
	a7.setSuprafeteCamere(v, 2);

	//afisare apartament a7 folosind getteri
	cout << "======================" << endl;
	cout << "Afisare apartament prin getteri: " << endl;
	cout << "Adresa: " << a7.getAdresa() << endl;
	cout << "Proprietar: " << a7.getProprietar() << endl;
	cout << "Confort: " << a7.getConfort() << endl;
	cout << "An constructie: " << a7.getAnConstructie() << endl;
	cout << "Pret: " << a7.getPret() << endl;
	cout << "Numar camere: " << a7.getNumarCamere() << endl;
	if (a7.getNumarCamere() > 0)
	{
		for (int i = 0; i < a7.getNumarCamere(); i++)
		{
			cout << "Camera " << i + 1 << " are: " << a7.getSuprafeteCamere()[i] << " mp." << endl;
		}
	}
	cout << "======================" << endl;

	//testarea operatorului>> pentru a citi de la tastatura un apartament
	/*
	Apartament a8;
	cin >> a8;
	cout << a8;
	*/

	//testarea operatorului ++ forma prefixata
	Apartament a9;
	a9 = ++a7;
	//Atat a7 cat si a9 ar trebui sa aiba 3 camere
	cout << a7;
	cout << a9;

	//testarea operatorului ++ forma postfixata
	Apartament a10;
	a10 = a7++;
	//a7 ar trebui sa aiba acum 4 camere, insa a10 ar trebui sa aiba 3
	cout << a7;
	cout << a10;

	//testarea operatorului +
	Apartament a11;
	a11 = a2 + a5;
	cout << a11;

	//testarea operatorului *=
	//Se va creste pretul apartamentului 2 cu 50% -> din 90.000 la 135.000
	a2 *= 50;
	cout << a2;

	//testarea operatorului- in forma apartament - pret
	a2 = a2 - 5000;
	cout << a2;

	//testarea operatorului- in forma pret - apartament
	a2 = 200000 - a2;
	cout << a2;

	//testarea operatorului de indexare
	cout << "Suprafata camerei 2 din apartamentul 2 este: " << a2[1] << endl;
	//cout << "Suprafata camerei 3 din apartamentul 2 este: " << a2[2] << endl;
	//modificarea suprafetei unei camere folosind operatorul de indexare
	a2[1] = 13.5;
	cout << a2;


	//testarea operatorului cast
	cout << "Pretul apartamentului 2 este: " << (double)a2 << endl;

	//testarea operatorului functie
	cout << "Suprafata totala a apartamentului 2 este: " << a2() << endl;

	//testarea operatorului ==
	if (a5 == a6)
	{
		cout << "Apartamente egale!" << endl;
	}
	else
	{
		cout << "Apartamente diferite!" << endl;
	}

	//testarea operatorului ==
	if (a6 == a7)
	{
		cout << "Apartamente egale!" << endl;
	}
	else
	{
		cout << "Apartamente diferite!" << endl;
	}

	//testarea operatorului !
	if (!a2) {
		cout << "Apartament cu mai multe camere!" << endl;
	}
	else 
	{
		cout << "Apartament fara nicio camera!" << endl;
	}
	
	//testare getter atribut static
	cout << "Numarul total de apartamente din aplicatie este: " << Apartament::getNumarApartamente() << endl;
}
