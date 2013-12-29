#include <iostream>
#include <algorithm>
#include "Excepcao.h"
#include "Professor.h"


/**
*
* @param n
* @param d
* @param t
*/
Professor::Professor(string n, Disciplina * d,Turma * t, long c):Pessoa(n) {
	_disciplina = d;
	addTurma(t);
	director_turma = false;
	addDisciplinaAres(_disciplina);
	contacto = c;
}

Professor::Professor(string n, Disciplina * d, long c):Pessoa(n) {
	_disciplina = d;
	director_turma = false;
	addDisciplinaAres(_disciplina);
	contacto = c;
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

void Professor::setTurmas(vector<Turma *> t){
	_turmas = t;
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

	throw new TurmaNaoExistente(id);
}

void Professor::setContacto(const long int c){
	if(c < 900000000 || c > 999999999)
		throw ContactoOutOfBounds(c);
	else
	{
		contacto = c;
	}
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
DirectorTurma::DirectorTurma(string n, Disciplina * d,Turma* t, long c, Turma * t_responsavel):Professor(n,d,t,c){
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

	throw TurmaNaoExistente(id);
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
bool Professor::operator==(const Professor & a2)const {
	return (getNome() == a2.getNome()) && (_disciplina == a2.getDiscipina());
}
/**
*
* @return
*/
string Professor::print(){
	stringstream s;
	s << "Nome: " << getNome() << endl;
	s << "			Disciplina Leccionada: " << getDiscipina()->getNome() << ";" << endl;
	s << "			Contacto: "<< contacto << ";" << endl;

	if(!_turmas.empty()){
		s << "	Turmas em que lecciona:" << endl;
		for(auto i=0u;i< getTurmas().size();i++){
			s << "			ID: " << getTurmas()[i]->getID() << " Ano: " << getTurmas()[i]->getAnoEscolar() << ";"<< endl;
		}
	}

	s << "	Disciplinas da sua area:" << endl;
	for(auto i=0u;i< _d_area.size();i++){
		s << "			Nome: " << _d_area[i]->getNome() << " Duracao: " << _d_area[i]->getDuracao()
			<< " Hora Inicio: " << _d_area[i]->getHoraInicio() << ";" << endl;
	}
	return s.str();
}

void Professor::addDisciplinaAres(Disciplina * d){
	if(_d_area.empty())
		_d_area.push_back(d);
	else
	{
		for(auto i = 0u; i < _d_area.size();i++){
			if(_d_area[i]->getNome() == d->getNome())
				throw(DisciplinaExistente(d->getNome()));
		}

		_d_area.push_back(d);
	}
}

string DirectorTurma::print(){
	stringstream s;
	s << "Nome: " << getNome() << endl;
	s << "			Disciplina Leccionada: " << getDiscipina()->getNome() << ";" << endl;
	s << "			Contacto: "<< contacto << ";" << endl;

	if(!_turmas.empty()){
		s << "	Turmas em que lecciona:" << endl;
		for(unsigned int i=0;i< getTurmas().size();i++){
			s << "			ID: " << getTurmas()[i]->getID() << " Ano: " << getTurmas()[i]->getAnoEscolar() << ";"<< endl;
		}
	}
	s << "	Disciplinas da sua area:" << endl;
	for(auto i=0u;i< _d_area.size();i++){
		s << "			Nome: " << _d_area[i]->getNome() << " Duracao: " << _d_area[i]->getDuracao()
			<< " Hora Inicio: " << _d_area[i]->getHoraInicio() << ";" << endl;
	}

	if(!_turmas_resposaveis.empty()){
		s << "	Turmas responsaveis:" << endl;
		for(unsigned int i=0;i< getTurmasResponsaveis().size();i++){
			s << "			ID: " << getTurmasResponsaveis()[i]->getID() << " Ano: " << getTurmasResponsaveis()[i]->getAnoEscolar() << ";"<< endl;
		}
	}
	return s.str();
}

bool DirectorTurma::operator==(DirectorTurma* p2){
	return (getNome() == p2->getNome()) && (_disciplina == p2->getDiscipina());
}

string Professor::printSaveFormat()const{
	stringstream s;

	s << "Professor ";
	string _temp_nome = getNome();
	replace(_temp_nome.begin(),_temp_nome.end(), ' ', '.');

	string _temp_disc = getDiscipina()->getNome();
	replace(_temp_disc.begin(),_temp_disc.end(), ' ', '.');

	s << _temp_nome << " "<< _temp_disc;
	for(auto i=0u;i< getTurmas().size();i++){
		s << " " << getTurmas()[i]->getID();
		if(i != getTurmas().size() - 1)
			s << "-";
	}

	s << " " << contacto << " ";

	for(auto i=0u;i< _d_area.size();i++){

		string _temp_area = _d_area[i]->getNome();
		replace(_temp_area.begin(),_temp_area.end(), ' ', '.');

		s << _temp_area;
		if(i != _d_area.size() - 1)
			s << "-";
	}

	s << endl;

	return s.str();
}	

string DirectorTurma::printSaveFormat()const{
	stringstream s;

	s << "DirectorTurma ";
	string _temp_nome = getNome();
	replace(_temp_nome.begin(),_temp_nome.end(), ' ', '.');

	string _temp_disc = getDiscipina()->getNome();
	replace(_temp_disc.begin(),_temp_disc.end(), ' ', '.');

	s << _temp_nome << " " << _temp_disc;
	for(auto i=0u;i< getTurmas().size();i++){
		s << " " << getTurmas()[i]->getID();
		if(i != getTurmas().size() - 1)
			s << "-";
	}

	s << " " << contacto;

	for(unsigned int i=0;i< getTurmasResponsaveis().size();i++){
		s << " " << getTurmasResponsaveis()[i]->getID();
		if(i != getTurmasResponsaveis().size() - 1)
			s << "-";
	}

	s << " ";

	for(auto i=0u;i< _d_area.size();i++){

		string _temp_area = _d_area[i]->getNome();
		replace(_temp_area.begin(),_temp_area.end(), ' ', '.');

		s << _d_area[i]->getNome();
		if(i != _d_area.size() - 1)
			s << "-";
	}



	s << endl;

	return s.str();
}