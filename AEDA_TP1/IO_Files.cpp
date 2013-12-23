#include "IO_Files.h"
#include <iostream>
#include <fstream>

Escola * IO::LoadData(const string file){

	Escola * escola = new Escola();

	ifstream myfile;
	string line;
	int alunos = 0, profs = 0, turma = 0, disciplinas = 0;
	myfile.open (file);
	while(getline(myfile,line)){

		if(line == "Aluno"){
			alunos++;
		}
		else if(line == "Professor"){
			profs++;
		}
		else if(line == "Turma"){
			turma++;
		}
		else if(line == "Disciplina"){
			disciplinas++;
		}
	}
	myfile.close();

	cout << alunos << endl << profs << endl << turma << endl << disciplinas << endl;
	
	return escola;
}

	void IO::SaveData(const string file){
		return;
	}

