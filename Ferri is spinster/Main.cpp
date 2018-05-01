#include <vector>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Studenti.h"

Studenti students;

void color() {
	int colore=students.color();
	switch (colore) {
	case 0:
		system("color 9");
		system("cls");
		break;
	case 1:
		system("color A");
		system("cls");
		break;
	case 2:
		system("color E");
		system("cls");
		break;
	case 3:
		system("color C");
		system("cls");
		break;
	default:
		cout << "Error" << endl;

	}

}
void addStudent() {
	int voto;
	vector<int>voti;
	char scelta;
	string nome;
	cout << "Inserisci nome alunno" << endl;
	cin >> nome;
	do{
	cout << "Inserisci voti alunno" << endl;
	cin >> voto;
	if (voto >= 10 && voto <= 0) {
		throw Studenti();
		return;
	}
	voti.push_back(voto);
	cout << "Continuare?[s/n]" << endl;
	cin >> scelta;
	system("cls");
	} 
	while (scelta!='n');
	system("cls");
	Studenti s(voti,nome);
	
	students.writeOnFile(s);
}
void menu() {
	int scelta;
	while (true) {
	cout << "1.Visualizza registro" << endl;
	cout << "2.Aggiungi alunno" << endl;
	cout << "3.Cambia colore registro" << endl;
	cout << "4.Cancella registro" << endl;
		cin >> scelta;
		system("cls");
		switch (scelta) {
		case 1:
			students.readFromFile();
			break;
		case 2:
			addStudent();
			break;
		case 3:
			color();
			break;
		case 4:
			students.deleteRegister();
			break;
		default:
			cout << "Error" << endl;

		}
	}

}
void main() {
	
	menu();
	getchar();

}