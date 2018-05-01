
#include <vector>
#include <iostream>
#include <fstream>
#include <exception>
#include <string>
using namespace std;
class Classe :public exception{
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
	virtual const char* what() const throw() {
		return "Error";
	};
protected:
	int _Studenti;
	string _nome;

	
};



class Studenti : public Classe{
protected:
	vector<int> _voti;
	string _nome;

public:
	Studenti():Classe() {
		vector<int>::iterator it;
		for (it = _voti.begin(); it != _voti.end(); ++it) {
			_voti.push_back(10);
		}
		_nome = "";
}
	Studenti(vector<int> voti, string nome)  {
		
		_voti.insert(_voti.end(), voti.begin(), voti.end());
		voti.clear();
		_nome = nome;
	};
	vector<int> const getVoto() const { return _voti; }
	string getNome() { return _nome; }
	virtual const char* what() const throw() {
		return "Error";
	}
	virtual const int andamento() { return 10; }
	friend ostream& operator<<(ostream& os, Studenti& rhs) {

		os << rhs.getNome() << ":"  << endl;
		vector<int>::iterator it;
		for (std::vector<int>::const_iterator ii = rhs._voti.begin(); ii != rhs._voti.end(); ++ii)
		{
			os<< *ii <<" ";
		}
		
		return os;
	}
	virtual void writeOnFile(const Studenti studente)const {

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
	virtual void readFromFile()const {
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
	virtual void deleteRegister() {
		ofstream myfile;
		myfile.open("C:\\Users\\Rici\\Desktop\\MYDATABASE.txt", ios::out);
		myfile << "";
		myfile.close();
	}
	virtual int color() {
		
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