
#include <vector>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;
class Classe {
public:
	Classe() :_nome("4b"), _Studenti(22) {};
	Classe(string nome, int Studenti) : _nome(nome), _Studenti(Studenti) {};
	int getStudenti() { return _Studenti; }
	string getNome() { return _nome; }
	enum colori {
		blue,
		green,
		yellow,
		red,

	};
	virtual const int andamento() = 0;
protected:
	int _Studenti;
	string _nome;

	
};
class Studenti : public Classe{
protected:
	int _voti;
	string _nome;

public:
	Studenti():Classe() {
		_voti = 10;
		_nome = "Rici";
}
	Studenti(int voti, string nome) :_voti(voti), _nome(nome) {};
	int getVoto() { return _voti; }
	string getNome() { return _nome; }
	
	virtual const int andamento() { return 10; }
	friend ostream& operator<<(ostream& os, Studenti& rhs) {

		os << rhs.getNome() << ":" << rhs.getVoto() << endl;
		return os;
	}
	void writeOnFile(const Studenti studente)const {

		ofstream myfile;
		myfile.open("C:\\Users\\Rici\\Desktop\\MYDATABASE.txt", ios::app);
		vector<Studenti> s;
		s.push_back(studente);
		vector<Studenti>::iterator it;
		for (it = s.begin();it != s.end();++it) {
			myfile << *it << endl;
		}
		myfile.close();

	}
	void readFromFile()const {
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
	void deleteRegister() {
		ofstream myfile;
		myfile.open("C:\\Users\\Rici\\Desktop\\MYDATABASE.txt", ios::out);
		myfile << "";
		myfile.close();
	}
	int color() {
		
		int scelta;
		cout << "" << endl;
		cout << "1:BLUE" << endl;
		cout << "2:GREEN" << endl;
		cout << "3:YELLOW" << endl;
		cout << "4:RED" << endl;
		cin >> scelta;
		switch (scelta) {
		case 1:
			return blue;
			system("cls");
			break;
		case 2:
			return green;
			system("cls");
			break;
		case 3:
			return yellow;
			system("cls");
			break;
		case 4:
			return red;
			system("cls");
			break;
		default:
			cout << "Error";


		}
	}
};