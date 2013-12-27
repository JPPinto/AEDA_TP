#include "IO_Files.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

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
				{
					stringstream ssd;
					ssd << "";

					vector<string> _temp_disciplinas;
					//Separation of every discipline on a professor
					for(auto i = 0u; i < _temp[5].size(); i++){

						if(_temp[5][i] == '-' || i == _temp[5].size() - 1){

							if(i == _temp[5].size() - 1)
								ssd << _temp[5][i];

							_temp_disciplinas.push_back(ssd.str());
							ssd.str(std::string());
							continue;
						}
						ssd << _temp[5][i];
					}

					escola->addProfessor(_temp[1], _temp[2], stoi(_temp[3]), stoi(_temp[4]));

					Professor * _temp_prof = escola->getProfessorByNome(_temp[1]);

					for(auto i = 1u; i < _temp_disciplinas.size();i++){
						_temp_prof->addDisciplinaAres(escola->getDisciplinaByNome(_temp_disciplinas[i]));
					}
				}
				break;
			case 3:
				escola->addTurma(stoi(_temp[1]), stoi(_temp[2]));
				break;
			case 4:
				escola->addDisciplina(_temp[1], stoi(_temp[2]), stoi(_temp[3]));
				break;
			case 5:
				{
				stringstream ssd;
				ssd << "";

				vector<string> _temp_disciplinas;
				//Separation of every discipline on a professor
				for(auto i = 0u; i < _temp[6].size(); i++){

					if(_temp[6][i] == '-' || i == _temp[6].size() - 1){

						if(i == _temp[6].size() - 1)
							ssd << _temp[6][i];

						_temp_disciplinas.push_back(ssd.str());
						ssd.str(std::string());
						continue;
					}
					ssd << _temp[6][i];
				}

				escola->addDirector(_temp[1], _temp[2], stoi(_temp[3]), stoi(_temp[4]), stoi(_temp[5]));
				
				Professor * _temp_prof = escola->getProfessorByNome(_temp[1]);

				for(auto i = 1u; i < _temp_disciplinas.size();i++){
					_temp_prof->addDisciplinaAres(escola->getDisciplinaByNome(_temp_disciplinas[i]));
				}
				}
				break;
			default:
				break;
			}
		} 		catch(...){
			cout << "ERRO DESCONHECIDO!" << endl;
		}
	
	}
	
	cout << "File " << file << " loaded successfully!" << endl << endl;
	
	myfile.close();

	//cout << alunos << endl << profs << endl  << "DT: " << directors << endl << turma << endl << disciplinas << endl;

	return escola;
}

void IO::SaveData(Escola * escola, const string file){

	ofstream myfile;
	myfile.open (file, ios::out || ios::trunc);

	if(!myfile){
		cout << "UNABLE TO OPEN FILE!" << endl;
		return;
	}
	
	auto _temp_exProf = escola->getExProfessores();
	auto it = _temp_exProf.begin();

	for (auto i = 0u; i < escola->getDiscipinas().size();i++)
	{
		myfile << escola->getDiscipinas()[i]->printSaveFormat(); 
	}

	for (auto i = 0u; i < escola->getTurmas().size();i++)
	{
		myfile << escola->getTurmas()[i]->printSaveFormat(); 
	}

	for (auto i = 0u; i < escola->getProfessores().size();i++)
	{
		myfile << escola->getProfessores()[i]->printSaveFormat(); 
	}

	for (; it != _temp_exProf.end();it++)
	{
		myfile << "ExProfessor " << (*it)->printSaveFormat(); 
	}

	for (auto i = 0u; i < escola->getAlunos().size();i++)
	{
		myfile << escola->getAlunos()[i]->printSaveFormat(); 
	}

	cout << "File " << file << " saved sucessufully!" << endl << endl;

	myfile.close();
	return;
}
