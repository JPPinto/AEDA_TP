/*
 * Aluno.cpp
 *
 *  Created on: 30/09/2013
 *      Author: João
 */

#include "Aluno.h"
#include "Excepcao.h"
#include "Escola.h"


Aluno::Aluno(string n, int numero,Turma * t):Pessoa(n){
	this->_numero=numero;
	setTurma(t);
}

int Aluno::getNumero(){
	return _numero;
}

Turma * Aluno::getTurma(){
	return _turma;
}

void Aluno::setNumero(int numero){
	if(numero<=0 && numero>MAX_ALUNOS){
		throw new AlunosPorTurmaExcedido(this);
	}else{
		this->_numero=numero;
	}
}

void Aluno::setTurma(Turma * t){
	_turma = t;
}

bool Aluno::operator==(Aluno * a2){
	return (getNome() == a2->getNome()) && (this->getNumero() == a2->getNumero());
}

string Aluno::print(){
	stringstream s;
			s << "Nome: " << getNome() << " - Numero: " << getNumero()
					<< " - Turma: " << getNumero() << endl;
			return s.str();
}