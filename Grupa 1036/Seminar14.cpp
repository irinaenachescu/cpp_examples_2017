#include<iostream>
using namespace std;

class Cerere{
private:
	char* continut;
	char* data;
	int nrInregistrare;
	char cnp[14];
	bool stare;
public:
	Cerere(int v_nrInregistrare, char* v_data, char v_cnp[14],
		char* v_continut){
		this->nrInregistrare = v_nrInregistrare;
		this->data = new char[strlen(v_data) + 1];
		strcpy(this->data, v_data);
		strcpy(this->cnp, v_cnp);
		this->continut = new char[strlen(v_continut) + 1];
		strcpy(this->continut, v_continut);
		this->stare = false;
	}

	Cerere(int v_nrInregistrare, char* v_data){
		this->nrInregistrare = v_nrInregistrare;
		this->data = new char[strlen(v_data) + 1];
		strcpy(this->data, v_data);
		strcpy(this->cnp, "");
		this->continut = NULL;
		this->stare = false;
	}
	Cerere(const Cerere& sursa){
		this->nrInregistrare = sursa.nrInregistrare;
		this->data = new char[strlen(sursa.data) + 1];
		strcpy(this->data, sursa.data);
		strcpy(this->cnp, sursa.cnp);
		this->continut = new char[strlen(sursa.continut) + 1];
		strcpy(this->continut, sursa.continut);
		this->stare = sursa.stare;
	}

	~Cerere(){
		if (this->continut != NULL){
			delete[] this->continut;
		}
		if (this->data != NULL){
			delete[] this->data;
		}
	}

	Cerere& operator=(const Cerere& sursa){
		if (this->continut != NULL){
			delete[] this->continut;
		}
		if (this->data != NULL){
			delete[] this->data;
		}
		this->nrInregistrare = sursa.nrInregistrare;
		this->data = new char[strlen(sursa.data) + 1];
		strcpy(this->data, sursa.data);
		strcpy(this->cnp, sursa.cnp);
		this->continut = new char[strlen(sursa.continut) + 1];
		strcpy(this->continut, sursa.continut);
		this->stare = sursa.stare;

		return *this;
	}

	friend ostream& operator<<(ostream& out, Cerere& c){
		out << "Id inregistrare: " << c.nrInregistrare << endl;
		out << "Data: " << c.data << endl;
		out << "Cnp: " << c.cnp << endl;
		out << "Continut: " << c.continut << endl;
		out << "Stare: ";
		if (c.stare == true){
			out << "rezolvata" << endl;
		}
		else{
			out << "nerezolvata" << endl;
		}

		return out;
	}

	void setData(char* v_data){
		if (this->data != NULL){
			delete[] this->data;
		}
		this->data = new char[strlen(v_data) + 1];
		strcpy(this->data, v_data);
	}

	void setContinut(char* v_continut){
		if (this->continut != NULL){
			delete[] this->continut;
		}
		this->continut = new char[strlen(v_continut) + 1];
		strcpy(this->continut, v_continut);
	}
	friend istream& operator>>(istream& in, Cerere& c){
		cout << "Dati nr inregistrare: ";
		in >> c.nrInregistrare;
		cout << "Dati data: ";
		char buffer[50];
		in >> buffer;
		c.setData(buffer);
		cout << "Dati continut: ";
		in.ignore();
		in.getline(buffer, 50);
		c.setContinut(buffer);
		cout << "Dati cnp: ";
		in >> c.cnp;
		cout << "Dati stare (0/1): ";
		in >> c.stare;

		return in;
	}

	explicit operator int(){
		return this->nrInregistrare;
	}

	bool operator!(){
		//dau true cand data e proasta
		char* cnp = this->cnp;
		string cnpS = cnp;
		if (cnpS.length() == 13){
			string an = cnpS.substr(1, 2);
			string luna = cnpS.substr(3, 2);
			string zi = cnpS.substr(5, 2);
			if (atoi(zi.c_str()) <= 31 && atoi(zi.c_str()) >= 1
				&& atoi(luna.c_str()) >= 1 && atoi(luna.c_str()) <= 12){
				return false;
			}
		}
		return true;		
	}
};

class ListaCereri{
private:
	int nr_cereri;
	Cerere** cereri;
public:
	ListaCereri(){
		this->nr_cereri = 0;
		this->cereri = NULL;
	}
	~ListaCereri(){
		if (this->cereri != NULL){
			delete[] this->cereri;
		}
	}

	ListaCereri(const ListaCereri& sursa){
		this->nr_cereri = sursa.nr_cereri;
		this->cereri = new Cerere*[this->nr_cereri];
		for (int i = 0; i < this->nr_cereri; i++){
			this->cereri[i] = sursa.cereri[i];
		}
	}

	Cerere& operator[](int i){
		if (i >= 0 && i < this->nr_cereri){
			return *(this->cereri[i]);
		}
		else{
			throw new exception("Index invalid...");
		}
	}

	ListaCereri& operator+=(Cerere* c){
		Cerere** aux = new Cerere*[this->nr_cereri+1];
		for (int i = 0; i < this->nr_cereri; i++){
			aux[i] = this->cereri[i];
		}
		aux[this->nr_cereri] = c;
		this->nr_cereri++;
		if (this->cereri != NULL){
			delete[] this->cereri;
		}
		this->cereri = aux;
		return *this;
	}

	friend ostream& operator<<(ostream& out, ListaCereri& lista){
		out << "Nr cereri: " << lista.nr_cereri << endl;
		for (int i = 0; i < lista.nr_cereri; i++){
			out << *lista.cereri[i];
		}

		return out;
	}

};
void main(){
	//fara constructor default
	Cerere c1(1, "17.01.2014", "1790523510070", "Solicitare ajutor social");
	Cerere c2(20, "17.01.2014");//null cnp si continut
	//cin >> c2;
	cout << c1;
	int nrInregistrare = (int)c2;
	if (!c2){
		cout << "Cererea nu e valida." << endl; //validare data nastere cnp
	}

	/*Am renuntat la pointer*/
	ListaCereri lista = ListaCereri();
	lista += &c1;
	lista += new Cerere(1, "17.01.2014", "12345678912", "Sol loc parcare");
	
	cout << "-----------Lista---------------" << endl;
	cout << lista;

	try{
		//Cerere copie = lista[1];
		Cerere copie = lista[2];
		cout << "-----------Index---------------" << endl;
		cout << copie;
	}
	catch (exception* ex){
		cout << ex->what()<< endl;
	}
}