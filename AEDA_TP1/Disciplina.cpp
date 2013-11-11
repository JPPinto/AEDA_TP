#include "Disciplina.h"

Disciplina::Disciplina(){

}

Disciplina::Disciplina(string nome) {
	this->_nome=nome;
}

Disciplina::~Disciplina() {
	// TODO Auto-generated destructor stub
}

string Disciplina::getNome(){
	return _nome;
}

void Disciplina::setNome(string nome){
	this->_nome=nome;
}