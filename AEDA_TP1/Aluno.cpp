/*
 * Aluno.cpp
 *
 *  Created on: 30/09/2013
 *      Author: João
 */

#include "Aluno.h"
#include "Excepcao.h"


Aluno::Aluno(string nome, int numero, int idTurma){
	this->nome=nome;
	this->numero=numero;
	setTurma(idTurma);
}

string Aluno::getNome(){
	return nome;
}

int Aluno::getNumero(){
	return numero;
}

int Aluno::getTurma(){
	return idTurma;
}

void Aluno::setNome(string nome){
	this->nome=nome;
}

void Aluno::setNumero(int numero){
	if(numero<=0 && numero>MAX_ALUNOS){
		throw new AlunosPorTurmaExcedido(this);
	}else{
		this->numero=numero;
	}
}

void Aluno::setTurma(int idTurma){
	this->idTurma=idTurma;
}
