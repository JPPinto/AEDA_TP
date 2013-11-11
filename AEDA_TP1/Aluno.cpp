/*
 * Aluno.cpp
 *
 *  Created on: 30/09/2013
 *      Author: João
 */

#include "Aluno.h"
#include "Excepcao.h"
#include "Escola.h"


Aluno::Aluno(string nome, int numero, int id){
	this->_nome=nome;
	this->_numero=numero;
	setTurma(id);
}

string Aluno::getNome(){
	return _nome;
}

int Aluno::getNumero(){
	return _numero;
}

Turma * Aluno::getTurma(){
	return _turma;
}

void Aluno::setNome(string nome){
	this->_nome=nome;
}

void Aluno::setNumero(int numero){
	if(numero<=0 && numero>MAX_ALUNOS){
		throw new AlunosPorTurmaExcedido(this);
	}else{
		this->_numero=numero;
	}
}

void Aluno::setTurma(int id){

	Turma* _temp_turma = NULL;

	_temp_turma = Escola::getTurmaById(id);

	if(_temp_turma == NULL)
		throw TurmaNaoExistente(new Turma(id));
	else
		_turma = _temp_turma;
}

bool Aluno::operator==(Aluno * a2){
	return (getNome() == a2->getNome()) && (this->getNumero() == a2->getNumero());
}