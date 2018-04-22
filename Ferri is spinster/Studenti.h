




#include <vector>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;
class Studenti {
protected:
	int voti;
	string nome;

public:
	Studenti() {
		voti = 10;
		nome = "Rici";


	}
	int getVoto() { return voti; }
	string getNome() { return nome; }
	friend ostream& operator<<(ostream& os, Studenti& rhs) {

		os << rhs.getNome() << " " << rhs.getVoto() << endl;
		return os;
	}

};