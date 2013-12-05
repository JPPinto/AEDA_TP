#include <iostream>
#include "Excepcao.h"
#include "Professor.h"

/**
 *
 * @param n
 * @param d
 * @param t
 */
Professor::Professor(string n, Disciplina * d,Turma * t):Pessoa(n) {
	_disciplina = d;
	bool x = addTurma(t);
	director_turma = false;
}
/**
 * @brief adds turma t to Professor
 * @param t
 * @return boolean
 */
bool Professor::addTurma(Turma * t){

	vector<Turma *>::iterator it = _turmas.begin();

	for(;it != _turmas.end();it++){
		if((*it)->getID() == t->getID())
			throw TurmaExistente(t);
	}

	_turmas.push_back(t);

	return true;
}
/**
 *
 * @param id
 * @return
 */
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
/**
 * @brief Destructor for Professor
 */
Professor::~Professor() {

	delete(_disciplina);
	_turmas.clear();
}
/**
 *
 * @param n
 * @param d
 * @param t
 * @param t_responsavel
 */
DirectorTurma::DirectorTurma(string n, Disciplina * d,Turma* t, Turma * t_responsavel):Professor(n,d,t){
	addTurmaResponsavel(t_responsavel);
	director_turma = true;
}
/**
 *
 * @param t
 * @return
 */
bool DirectorTurma::addTurmaResponsavel(Turma * t){

	vector<Turma *>::iterator it = _turmas_resposaveis.begin();

	for(;it != _turmas_resposaveis.end();it++){
		if((*it)->getID() == t->getID())
			throw TurmaExistente(t);
	}

	_turmas_resposaveis.push_back(t);

	return true;
}
/**
 *
 * @param id
 * @return
 */
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

	throw TurmaNaoExistente(new Turma(id));
}
/**
 * @brief Destructor for DirectorTurma
 */
DirectorTurma::~DirectorTurma(){

	_turmas_resposaveis.clear();
}
/**
 *
 * @param a2
 * @return
 */
bool Professor::operator==(Professor * a2){
	return (getNome() == a2->getNome()) && (_disciplina == a2->getDiscipina());
}
/**
 *
 * @return
 */
string Professor::print(){
	stringstream s;
	s << "Nome: " << getNome() << " - Disciplina Leccionada: " << getDiscipina()->getNome() << ";"<< endl;
	s << "Turmas em que lecciona:" << endl;
	for(unsigned int i=0;i< getTurmas().size();i++){
		s << "			ID: " << getTurmas()[i]->getID() << " Ano: " << getTurmas()[i]->getAnoEscolar() << ";"<< endl;
	}
	return s.str();
}

string DirectorTurma::print(){
	stringstream s;
	s << "Nome: " << getNome() << " - Disciplina Leccionada: " << getDiscipina()->getNome() << ";"<< endl;
	s << "Turmas em que lecciona:" << endl;
	for(unsigned int i=0;i< getTurmas().size();i++){
		s << "			ID: " << getTurmas()[i]->getID() << " Ano: " << getTurmas()[i]->getAnoEscolar() << ";"<< endl;
	}
	s << "Turmas responsaveis:" << endl;
	for(unsigned int i=0;i< getTurmasResponsaveis().size();i++){
		s << "			ID: " << getTurmasResponsaveis()[i]->getID() << " Ano: " << getTurmasResponsaveis()[i]->getAnoEscolar() << ";"<< endl;
	}
	return s.str();
}

bool DirectorTurma::operator==(DirectorTurma* p2){
	return (getNome() == p2->getNome()) && (_disciplina == p2->getDiscipina());
}