#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include<set>
#include<map>

using namespace std;
class NumarNegativException:public exception {
public:
	char* what() {
		return "Numarul nu poate fi negativ";
	}
};
void main()
{
   //1. Tratare exceptii
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
	catch (...) {
		cout << "Eroare generica" << endl;
	}

	//2.string
	string nume = "Irina";
	cout << nume << endl;
	nume = nume + " Mihaela";
	cout << nume << endl;
	cout << nume.length() << endl;
	nume = "Cristina";
	cout << nume.substr(0, 4) << endl;

	//3. STL
	cout << "-----------------Vector-------------------" << endl;
	vector<int> numere;
	numere.push_back(15);
	numere.push_back(13);
	numere.push_back(18);
	numere.push_back(22);
	numere.pop_back();
	cout << numere[1] << endl;
	//afisare 1
	for (int i = 0; i < numere.size(); i++) {
		cout << numere[i] << " ";
	}
	cout << endl;

	//afisare cu iteratori
	vector<int>::iterator it1;
	for (it1 = numere.begin(); it1 != numere.end(); it1++) {
		cout << *it1 << " ";
	}
	cout << endl;

	cout << "------------------List----------------" << endl;
	list<float> lista;
	lista.push_back(12.3f);
	lista.push_front(11.1f);
	lista.push_back(9.5f);
	lista.push_front(18.9f);
	lista.pop_front();
	lista.sort();
	lista.reverse();
	list<float>::reverse_iterator it2;
	for (it2 = lista.rbegin(); it2 != lista.rend(); it2++) {
		cout << *it2 << " ";
	}
	cout << endl;

	//set
	cout << "----------------Set------------" << endl;
	set<string> studenti;
	studenti.insert("Irina");
	studenti.insert("Elena");
	studenti.insert("Radu");
	studenti.insert("Ioana");
	studenti.insert("Irina");

	set<string>::iterator it3;
	for (it3 = studenti.begin(); it3 != studenti.end(); it3++) {
		cout << *it3 << " ";
	}
	cout << endl;
	it3 = studenti.find("Ionut");
	if (it3 != studenti.end()) {
		cout << "S-a gasit." << endl;
	}
	else {
		cout << "Nu s-a gasit." << endl;
	}

	//map
	cout << "----------------Map------------" << endl;
	map<int, string> elevi;
	elevi[1] = "Irina";
	elevi[20] = "Cristina";
	elevi.insert(make_pair(3, "Ioana"));

	map<int, string>::reverse_iterator it4;
	for (it4 = elevi.rbegin(); it4 != elevi.rend(); it4++)
	{
		cout << it4->first << " " << it4->second << endl;
	}

	string elev = elevi[200];
	if (!elev.empty()) {
		cout << elev << endl;
	}
	else {
		cout << "Lipsa" << endl;
	}

}

