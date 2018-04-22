#include <vector>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Studenti.h"
void writeOnFile() {

	ofstream myfile;
	myfile.open("C:\\Users\\Rici\\Desktop\\MYDATABASE.txt", ios::app);
	Studenti studente;
	vector<Studenti> s;
	s.push_back(studente);
	vector<Studenti>::iterator it;
	for (it = s.begin();it != s.end();++it) {
		myfile << *it << endl;
	}
	myfile.close();

}
void readFromFile() {
	string line;
	ifstream myfile("C:\\Users\\Rici\\Desktop\\MYDATABASE.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			cout << line << '\n';
		}
		myfile.close();
	}

	else cout << "Unable to open file";


}
void main() {
	writeOnFile();
	readFromFile();
	getchar();

}