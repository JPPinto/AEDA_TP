/*
 * Aluno.cpp
 *
 *  Created on: 30/09/2013
 *      Author: João
 */

#include "Aluno.h"
#include "Excepcao.h"
#include "Escola.h"

/**
 *
 * @param n
 * @param numero
 * @param t
 */
Aluno::Aluno(string n, int numero,Turma * t):Pessoa(n){
	this->_numero=numero;
	setTurma(t);
}
/**
 *
 * @return int _numero
 */
int Aluno::getNumero(){
	return _numero;
}
/**
 *
 * @return Turma _turma
 */
Turma * Aluno::getTurma(){
	return _turma;
}

/**
 *
 * @param numero
 */
void Aluno::setNumero(int numero){
	if(numero<=0 && numero>MAX_ALUNOS){
		throw new AlunosPorTurmaExcedido(this);
	}else{
		this->_numero=numero;
	}
}
/**
 *
 * @param t
 */
void Aluno::setTurma(Turma * t){
	_turma = t;
}
/**
 *
 * @param a2
 * @return
 */
bool Aluno::operator==(Aluno * a2){
	return (getNome() == a2->getNome()) && (this->getNumero() == a2->getNumero());
}
/**
 *
 * @return
 */
string Aluno::print(){
	stringstream s;
			s << "Nome: " << getNome() << " Numero: " << getNumero()
					<< " Turma: " << getNumero() << ";" << endl;
			return s.str();
}
