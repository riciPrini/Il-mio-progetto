
#include <vector>
#include <iostream>
#include <fstream>
#include <exception>
#include <string>
#include <numeric>  
using namespace std;
class Classe :public exception{
public:
	//----CONSTRUCTOR----//
	Classe() :_nome("4b"), _Studenti(22) {};
	Classe(string nome) :_nome(nome) {};
	Classe(string nome, int Studenti) : _nome(nome), _Studenti(Studenti) {};
	//----GET & SET----//
	int getStudenti() { return _Studenti; }
	string getNome() { return _nome; }
	void setSteudenti(int studenti) { _Studenti = studenti; }
	void setNome(string Nome) { _nome = Nome; }
	//----ENUM----//
	enum colori {
		blue,
		green,
		yellow,
		red,
	};
	//----VIRTUAL PURO----//
	virtual int andamento() = 0;
	//----MYEXCEPTION----//
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
	string _classe;
	string _giudizio;
	string _andamento;
public:
	//----STRUCT----//
	struct giudizio {
		string good="Buono";
		string medium = "Ok" ;
		string bad ="Non si applica";
	};
	//----SOURCHE FILE----//
	const string percorso = "C:\\Users\\Rici\\Desktop\\MYDATABASE.txt";
	//----CONSTRUCTOR----//
	Studenti():Classe() {
		vector<int>::iterator it;
		for (it = _voti.begin(); it != _voti.end(); ++it) {
			_voti.push_back(10);
		}
		_nome = "";
		_classe = "";
		_giudizio = "";
}
	Studenti(vector<int> voti, string nome, string classe, string andamento,string giudizio)  {
		
		_voti.insert(_voti.end(), voti.begin(), voti.end());
		voti.clear();
		_nome = nome;
		_classe = classe;
		_andamento = andamento;
		_giudizio = giudizio;
	};
	Studenti(vector<int> voti, string nome, string classe, string andamento) {

		_voti.insert(_voti.end(), voti.begin(), voti.end());
		voti.clear();
		_nome = nome;
		_classe = classe;
		_andamento = andamento;
		
	};

	//----GET & SET----//
	vector<int> const getVoto() const { return _voti; }
	string getNome() { return _nome; }
	string getClass() { return _classe; }
	string getAndamento() { return _andamento; }
	string getGiudzio() { return _giudizio; }
	void setNome(int nome) { _nome = nome; }
	void setClasse(string classe) { _classe = classe; }
	void setAndamento(string andamento) { _andamento = andamento; }
	void setGiudizio(string giudizio) { _giudizio = giudizio; }
	//----MYEXCEPTION----//
	virtual const char* what() const throw() {
		return "Error";
	}
	//----VIRTUAL PURO----//
	virtual int andamento() { return 10; }
	//----MEDIA----//
	virtual double media() {
		double media=1.0 * std::accumulate(_voti.begin(), _voti.end(), 0LL) / _voti.size();
		if (media>=6) {
			setGiudizio("Promosso");

		}
		else if (media <6 && media >=5) {
			setGiudizio("Da deciedere in consiglio di classe ");

		}
		else if (media < 5) {
			setGiudizio("Bocciato");

		}
		return media;

	}
	//---OVERLOAD << ----//
	friend ostream& operator<<(ostream& os, Studenti& rhs) {
		
		os << "Classe:" << rhs.getClass() << endl;
		os<< rhs.getNome() << ":"  << endl;
		vector<int>::iterator it;
		for (std::vector<int>::const_iterator ii = rhs._voti.begin(); ii != rhs._voti.end(); ++ii)
		{
			os<< *ii <<" ";
		}
		os << "Media: " << rhs.media() << endl;
		os << "Andamento: " << rhs.getAndamento() << endl;
		os << "Giudizio: " << rhs.getGiudzio() << endl;
		return os;
	}
	//----ANDAMENTO STUDENTE----//
	virtual string andamentoStudente() {
		int scelta;
		giudizio g;
		cout << "" << endl;
		cout << "1:Buono" << endl;
		cout << "2:OK" << endl;
		cout << "3:Non si applica" << endl;
		cin >> scelta;
		switch (scelta) {
		case 1:
			system("cls");
			return g.good;
			break;
		case 2:
			system("cls");
			return g.medium;
			break;
		case 3:
			system("cls");
			return g.bad;
			break;
		default:
			cout << "Error";


		}

	}
	//----WRITE ON FILE----//
	virtual void writeOnFile(const Studenti studente)const {

		ofstream myfile;
		myfile.open(percorso, ios::app);
		vector<Studenti> s;
		s.push_back(studente);
		vector<Studenti>::iterator it;
		for (it = s.begin();it != s.end();++it) {
			myfile << *it << endl;
		}
		myfile.close();

	}
	//----READ FORM FILE----//
	virtual void readFromFile()const {
		string line;
		ifstream myfile(percorso);
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
	//----DELETE REGISTER----//
	virtual void deleteRegister() {
		ofstream myfile;
		myfile.open("C:\\Users\\Rici\\Desktop\\MYDATABASE.txt", ios::out);
		myfile << "";
		myfile.close();
	}
	//----REGISTER COLOR----//
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