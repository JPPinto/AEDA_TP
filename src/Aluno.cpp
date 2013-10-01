/*
 * Aluno.cpp
 *
 *  Created on: 30/09/2013
 *      Author: João
 */

#include "Aluno.h"

Aluno::Aluno(int idTurma, string nome, int numero) {
	this->idTurma=idTurma;
	this->nome=nome;
	this->numero=numero;
}

Aluno::~Aluno() {

}

int Aluno::getIDturma(){
	return idTurma;
}

void Aluno::setIDturma(int idT){
	idTurma=idT;
}

string Aluno::getNome(){
	return nome;
}

void Aluno::setNome(string n){
	nome=n;
}

int Aluno::getNumero(){
	return numero;
}

void Aluno::setNumero(int n){
	numero=n;
}
