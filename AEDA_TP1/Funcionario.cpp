#include <iostream>
#include <algorithm>
#include "Excepcao.h"
#include "Funcionario.h"



/**
 *
 * @param n nome
 * @param t turma
 * @param contacto contacto
 */



Funcionario::Funcionario(string n, long contacto):Pessoa(n){
	this->_contacto=contacto;
}


Funcionario::~Funcionario(void)
{
}


void Funcionario::setTurmas(vector<Turma *> t){
	_turmas = t;
}

bool Funcionario::addTurma(Turma * t){

	vector<Turma *>::iterator it = _turmas.begin();

	for(;it != _turmas.end();it++){
		if((*it)->getID() == t->getID())
			throw TurmaExistente(t);
	}

	_turmas.push_back(t);

	return true;
}

bool Funcionario::removeTurma(const int id){

	if(!_turmas.size() || _turmas.size() == 1)
		return false;

	vector<Turma *>::iterator it = _turmas.begin();

	for(;it != _turmas.end();it++){
		if((*it)->getID() == id){
			_turmas.erase(it);
			return true;
		}	
	}

	throw TurmaNaoExistente(id);
}



string Funcionario::print(){
	stringstream s;
	s << "Nome: " << getNome() << endl;
	s << "			Contacto: "<< _contacto << ";" << endl;
	if(!_turmas.empty()){
		s << "	Turmas Supervisionadas:" << endl;
		for(unsigned int i=0;i< getTurmas().size();i++){
			s << "			ID: " << getTurmas()[i]->getID() << " Ano: " << getTurmas()[i]->getAnoEscolar() << ";"<< endl;
		}
	}
	return s.str();
}



string Funcionario::printSaveFormat()const{
	stringstream s;

	s << "Funcionário ";
	string _temp_nome = getNome();
	replace(_temp_nome.begin(),_temp_nome.end(), ' ', '.');

	s << _temp_nome << " ";
	for(auto i=0u;i< getTurmas().size();i++){
		s << " " << getTurmas()[i]->getID();
		if(i != getTurmas().size() - 1)
			s << "-";
	}

	s << " " << _contacto << " ";

	s << endl;

	return s.str();
}	


