#include "IO_Files.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iostream>

Escola * IO::LoadData(const string file){

	Escola * escola = new Escola();

	ifstream myfile;
	string line;
	int alunos = 0, profs = 0, turma = 0, disciplinas = 0, directors = 0, type = 0;

	myfile.open (file);
	//Parsing..
	while(getline(myfile,line)){
		vector<string> _temp;

		//Count
		if(line[0] == 'A'){
			alunos++;
			type = 1;
		}
		else if(line[0] == 'P'){
			profs++;
			type = 2;
		}
		else if(line[0] == 'T'){
			turma++;
			type = 3;
		}
		else if(line[8] == 'T'){
			directors++;
			type = 5;
		}
		else if(line[0] == 'D'){
			disciplinas++;
			type = 4;
		}


		stringstream ss;
		ss << "";
		//Separation of every element
		for(auto i = 0u; i < line.size(); i++){

			if(line[i] == ' ' || i == line.size() - 1){
				if(i == line.size() - 1)
					ss << line[i];
				_temp.push_back(ss.str());
				ss.str(std::string());
				continue;
			}
			ss << line[i];
		}

		//replace every '.' by ' '
		for(auto i = 0u; i < _temp.size(); i++){

			replace( _temp[i].begin(), _temp[i].end(), '.', ' ' );
			//cout << _temp[i] << " ";

		}//cout << endl;


		try{
			switch(type){
			case 1:
				{ 
					Turma * _temp_turma = NULL; 
					_temp_turma = escola->getTurmaById(stoi(_temp[3]));

					escola->addAluno(_temp[1], stoi(_temp[2]), _temp_turma);
				}
				break;
			case 2:
				escola->addProfessor(_temp[1], _temp[2], stoi(_temp[3]));
				break;
			case 3:
				escola->addTurma(stoi(_temp[1]), stoi(_temp[2]));
				break;
			case 4:
				escola->addDisciplina(_temp[1], stoi(_temp[2]), stoi(_temp[3]));
				break;
			case 5:
				escola->addDirector(_temp[1], _temp[2], stoi(_temp[3]), stoi(_temp[4]));
				break;
			default:
				break;
			}
		}catch(...){
			cout << "ERRO DESCONHECIDO!" << endl;
		}

	}
	myfile.close();

	//cout << alunos << endl << profs << endl  << "DT: " << directors << endl << turma << endl << disciplinas << endl;

	return escola;
}

void IO::SaveData(const string file){
	return;
}
