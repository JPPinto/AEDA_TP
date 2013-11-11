#include "Professor.h"
#include <iostream>

Professor::Professor(string n, Disciplina * d,Turma * t) {
	_nome = n;
	_disciplina = d;
	addTurma(t);
}

bool Professor::addTurma(Turma * t){

	vector<Turma *>::iterator it = _turmas.begin();

	for(;it != _turmas.end();it++){
		if((*it)->getID() == t->getID())
			throw new TurmaExistente(t);
	}

	_turmas.push_back(t);

	return true;
}

bool Professor::removeTurma(const int id){

	if(!_turmas.size() || _turmas.size() == 1)
		return false;

	vector<Turma *>::iterator it = _turmas.begin();

	for(;it != _turmas.end();it++){
		if((*it)->getID() == id){
			_turmas.erase(it);
			return true;
		}	
	}

	throw new TurmaNaoExistente(new Turma(id));
}

Professor::~Professor() {

	delete(_disciplina);

	for (int i = 0; i < _turmas.size(); i++)
	{
		delete(_turmas[i]);
	}
}

DirectorTurma::DirectorTurma(string n, Disciplina * d,Turma* t, Turma * t_responsavel):Professor(n,d,t){
	addTurmaResponsavel(t_responsavel);
}

bool DirectorTurma::addTurmaResponsavel(Turma * t){

	vector<Turma *>::iterator it = _turmas_resposaveis.begin();

	for(;it != _turmas_resposaveis.end();it++){
		if((*it)->getID() == t->getID())
			throw new TurmaExistente(t);
	}

	_turmas_resposaveis.push_back(t);

	return true;
}

bool DirectorTurma::removeTurmaResponsavel(const int id){

	if(!_turmas_resposaveis.size() || _turmas_resposaveis.size() == 1)
		return false;

	vector<Turma *>::iterator it = _turmas_resposaveis.begin();

	for(;it != _turmas_resposaveis.end();it++){
		if((*it)->getID() == id){
			_turmas_resposaveis.erase(it);
			return true;
		}	
	}

	throw new TurmaNaoExistente(new Turma(id));
}

DirectorTurma::~DirectorTurma(){

	_turmas_resposaveis.clear();
}

