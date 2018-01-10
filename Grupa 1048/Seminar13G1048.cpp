// Seminar13G1048.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class PaginaWeb {
private:
	char adresaUrl[100];
	int rating; // nu poate sa fie >5
	static int RATING_MAXIM;

public:
	PaginaWeb(char v_adresaUrl[100], int v_rating) {
		strcpy(this->adresaUrl, v_adresaUrl);
		this->setRating(v_rating);
	}

	void setRating(int v_rating) {
		if (v_rating >= 0 && v_rating <= PaginaWeb::RATING_MAXIM) {
			this->rating = v_rating;
		}
		else if(v_rating>PaginaWeb::RATING_MAXIM){
			cout << "Rating peste valoarea maxima...Se va seta cu MAXIM." << endl;
			this->rating = PaginaWeb::RATING_MAXIM;
		}
		else {
			cout << "Rating negativ...Se va seta cu 0." << endl;
			this->rating = 0;
		}
	}

	friend ostream& operator<<(ostream& out, PaginaWeb& p) {
		out << "Adresa url: " << p.adresaUrl << endl;
		out << "Rating: " << p.rating << endl;

		return out;
	}

	friend istream& operator>>(istream& in, PaginaWeb& p) {
		cout << "Dati adresa url: ";
		in >> p.adresaUrl;
		cout << "Dati ratingul: ";
		int r;
		in >> r;
		p.setRating(r);

		return in;
	}

	void setAdresa(char v_adresaUrl[100]) {
		strcpy(this->adresaUrl, v_adresaUrl);
	}

	PaginaWeb& operator+=(int v) {
		this->setRating(v + this->rating);

		return *this;
	}

	int getRating() {
		return this->rating;
	}

	char* getAdresaUrl() {
		return this->adresaUrl;
	}

	static int getRatingMaxim() {
		return PaginaWeb::RATING_MAXIM;
	}
};

int PaginaWeb::RATING_MAXIM = 5;

class Bookmark {
private:
	const int idIntrare;
	PaginaWeb* paginaWeb;
	char* descriere;

public:
	Bookmark(int v_idIntrare, PaginaWeb* v_paginaWeb)
	:idIntrare(v_idIntrare){
		this->paginaWeb = v_paginaWeb;
		this->descriere = new char[strlen("") + 1];
		strcpy(this->descriere, "");
	}
	Bookmark(int v_idIntrare, PaginaWeb* v_paginaWeb,
		char* v_descriere) :idIntrare(v_idIntrare) {
		this->paginaWeb = v_paginaWeb;
		this->descriere = new char[strlen(v_descriere) + 1];
		strcpy(this->descriere, v_descriere);
	}
	
	void setDescriere(char* v_descriere) {
		if (this->descriere != NULL) {
			delete[] this->descriere;
		}
		this->descriere = new char[strlen(v_descriere) + 1];
		strcpy(this->descriere, v_descriere);
	}

	~Bookmark() {
		if (this->descriere != NULL) {
			delete[] this->descriere;
		}
	}

	Bookmark(const Bookmark& sursa)
	:idIntrare(sursa.idIntrare){
		this->paginaWeb = sursa.paginaWeb;
		this->descriere = new char[strlen(sursa.descriere) + 1];
		strcpy(this->descriere, sursa.descriere);
	}

	Bookmark& operator=(const Bookmark& sursa) {
		if (this->descriere != NULL) {
			delete[] this->descriere;
		}
		this->paginaWeb = sursa.paginaWeb;
		this->descriere = new char[strlen(sursa.descriere) + 1];
		strcpy(this->descriere, sursa.descriere);

		return *this;
	}

	friend bool operator>(Bookmark& b1, Bookmark& b2) {
		return b1.paginaWeb->getRating() >
			b2.paginaWeb->getRating();
	}

	char* getUrl() {
		return this->paginaWeb->getAdresaUrl();
	}

	friend ostream& operator<<(ostream& out, Bookmark& b) {
		out << "Id intrare: " << b.idIntrare << endl;
		out << *b.paginaWeb;
		out << "Descriere: " << b.descriere << endl;

		return out;
	}

	int getRating() {
		return this->paginaWeb->getRating();
	}

	explicit operator int() {
		return strlen(this->paginaWeb->getAdresaUrl());
	}

	friend istream& operator>>(istream& in, Bookmark& b) {
		PaginaWeb* p = new PaginaWeb("", 0);
		in >> *p;
		b.paginaWeb = p;
		cout << "Dati descriere: ";
		char buffer[50];
		in.ignore();
		in.getline(buffer, 50);
		b.setDescriere(buffer);

		return in;
	}
};
void main()
{
	//PaginaWeb p1; nu exista
	PaginaWeb p2("www.ase.ro", 5);
	PaginaWeb p3 = p2;
	//cin >> p2;
	cout << p2 << p3;
	p2.setAdresa("www.csie.ase.ro");
	p2 += 1; //incrementare rating
	cout << p2 << p3;

	Bookmark b1(1, &p2);
	Bookmark b2(2, &p3, "Pagina ASE");
	b1.setDescriere("Pagina Web ASE");
	if (b2 > b1) {
		cout << b2.getUrl() << " are rating mai mare" << endl;
	}
	else {
		cout << b1.getUrl() << " are rating mai mare" << endl;
	}
	cout << b1;

	cin >> b1;
	cout << "Lungime URL: " << (int)b1 << endl;
	cout << b1.getUrl() << " are ratingul " << b1.getRating()
		<< " din maxim: " << PaginaWeb::getRatingMaxim() << endl;

}

