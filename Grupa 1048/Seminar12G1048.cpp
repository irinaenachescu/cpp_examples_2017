#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include<list>
#include<set>
#include<map>

using namespace std;

class NumarNegativException : public exception {
public:
	char* what() {
		return "Numarul nu poate fi negativ";
	}
};

void citireAn() {
	try {
		cout << "Dati anul de nastere: ";
		int an;
		cin >> an;
		if (an < 0) {
			throw new NumarNegativException();
		}
		else if (an > 2017) {
			throw an;
		}
		else if (an < 1900) {
			throw "Nu esti cam batran?";
		}
		cout << "An validat: " << an << endl;
	}
	catch (NumarNegativException* ex) {
		cout << ex->what() << endl;
		citireAn();
	}
	catch (int an) {
		cout << "Nu se poate da un an in viitor. Ati intodus: " << an << endl;
		citireAn();
	}
	catch (char* mesaj) {
		cout << mesaj << endl;
		citireAn();
	}
	catch (...) { //care prinde orice
		cout << "Eroare generica..." << endl;
		citireAn();
	}
}
void main()
{
	//1. tratarea exceptiilor
	//citireAn();

	//2. string
	string masina = "Dacia";
	cout << masina << endl;
	masina = masina + " Logan";
	cout << masina << endl;
	cout << masina.length() << endl;
	masina = "Volkswagen";
	cout << masina.substr(5, 5);

	//3. STL
	cout << "-----------Vector-------------" << endl;
	vector<int> numere;
	numere.push_back(15);
	numere.push_back(22);
	numere.push_back(27);
	numere.pop_back();
	numere.push_back(10);
	
	cout << numere[1] << endl;
	//afisare 1 cu []
	for (int i = 0; i < numere.size(); i++) {
		cout << numere[i] << " ";
	}
	cout << endl;
	//afisare 2 cu iteratori
	vector<int>::iterator it1;
	for (it1 = numere.begin(); it1 != numere.end(); it1++) {
		cout << *it1 << " ";
	}
	cout << endl;

	cout << "-------------List---------" << endl;
	list<float> lista;
	lista.push_back(11.2f);
	lista.push_front(12.8f);
	lista.push_back(15.9f);
	lista.push_front(10.2);
	lista.pop_front(); //12.8 11.2 15.9
	lista.sort();
	lista.reverse();

	list<float>::reverse_iterator it2;
	for (it2 = lista.rbegin(); it2 != lista.rend(); it2++) {
		cout << *it2 << " ";
	}
	cout << endl;

	cout << "-----------------Set------------" << endl;
	set<string> nume;
	nume.insert("Irina");
	nume.insert("Elena");
	nume.insert("Ioana");
	nume.insert("Irina");
	nume.insert("Radu");

	set<string>::iterator it3;
	for (it3 = nume.begin(); it3 != nume.end(); it3++) {
		cout << *it3 << " ";
	}
	cout << endl;

	it3 = nume.find("Cristina");
	if (it3 != nume.end()) {
		cout << *it3;
	}
	else {
		cout << "Nu s-a gasit info in set." << endl;
	}

	cout << "-----------------Map------------" << endl;
	map<int, string> studenti;
	studenti[1] = "Irina";
	studenti[1] = "Mihaela";
	studenti[100] = "Cristina";
	studenti.insert(make_pair(13, "Ioana"));

	map<int, string>::reverse_iterator it4;
	for (it4 = studenti.rbegin(); it4 != studenti.rend(); it4++) {
		cout << it4->first << " " << it4->second << endl;
	}

	string num = studenti[13];
	if (!num.empty()) {
		cout << num << endl;
	}
	else {
		cout << "Nu s-a gasit in map." << endl;
	}


}


