#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
using namespace std;


class NumarNegativException : public exception {
public:
	//suprascriu comportamentul din parinte
	char* what() {
		return "Numarul nu poate fi negativ.";
	}
};
void main()
{
   //1. tratare exceptii
	try {
		cout << "Dati anul de nastere: ";
		int an;
		//cin >> an;
		an = 2000;
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
		cout << ex->what();
	}
	catch (int an) {
		cout << "Anul nu poate fi in viitor. Ati introdus: " << an << endl;
	}
	catch (char* mesaj) {
		cout << mesaj << endl;
	}
	catch (...) { //orice 
		cout << "Eroare generica." << endl;
	}

	//2. string
	string masina = "Dacia";
	cout << masina << endl;
	masina = masina + " Logan";
	cout << masina << endl;
	cout << masina.length() << endl;
	masina = "Volkswagen";
	cout << masina.substr(5, 5);

	//3. STL
	cout << "---------------Vector------------" << endl;
	vector<int> numere;
	numere.push_back(15);
	numere.push_back(12);
	numere.push_back(21);
	numere.pop_back();
	numere.push_back(5); //15 12 5 
	cout << numere[1] << endl;
	//1. afisare clasica cu []
	for (int i = 0; i < numere.size(); i++) {
		cout << numere[i] << " ";
	}
	cout << endl;
	//2. afisare cu iteratori
	vector<int>::iterator it1;
	for (it1 = numere.begin(); it1 != numere.end(); it1++) {
		cout << *it1 << " ";
	}
	cout << endl;


	cout << "--------------List------------" << endl;
	list<float> lista;
	lista.push_back(11.5f);
	lista.push_front(18.3f);
	lista.push_back(5.6);
	lista.pop_front();
	lista.push_back(7.2);
	lista.sort();
	lista.reverse();
	list<float>::reverse_iterator it2;
	for (it2 = lista.rbegin(); it2 != lista.rend(); it2++) {
		cout << *it2 << " ";
	}
	cout << endl;

	cout << "------------------Set--------------" << endl;
	set<string> nume;
	nume.insert("Irina");
	nume.insert("Elena");
	nume.insert("Ioana");
	nume.insert("Irina");
	nume.insert("Raluca");
	set<string>::iterator it3;
	for (it3 = nume.begin(); it3 != nume.end(); it3++) {
		cout << *it3 << " ";
	}
	cout << endl;

	it3 = nume.find("Irina");
	if (it3 != nume.end()) {
		cout << "S-a gasit." << endl;
	}
	else {
		cout << "Nu s-a gasit." << endl;
	}

	cout << "------------Map------------" << endl;
	map<int, string> studenti;
	studenti[1] = "Irina";
	studenti[50] = "Cristina";
	studenti.insert(make_pair(13, "Ioan"));

	map<int, string>::reverse_iterator it4;
	for (it4 = studenti.rbegin(); it4 != studenti.rend(); it4++) {
		cout << it4->first << " " << it4->second << endl;
	}

	string num = studenti[131];
	if (!num.empty()) {
		cout << num << endl;
	}
	else {
		cout << "Nu s-a gasit" << endl;
	}

}

