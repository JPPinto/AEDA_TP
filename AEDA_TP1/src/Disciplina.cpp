/*
 * Disciplina.cpp
 *
 *  Created on: 30/09/2013
 *      Author: João
 */

#include "Disciplina.h"

Disciplina::Disciplina(){

}

Disciplina::Disciplina(string nome, int id) {
	this->nome=nome;
	this->id=id;
	//iniciar vector

}

Disciplina::~Disciplina() {
	// TODO Auto-generated destructor stub
}

string Disciplina::getNome(){
	return nome;
}

void Disciplina::setNome(string nome){
	this->nome=nome;
}

int Disciplina::getID(){
	return id;
}

void Disciplina::setID(int id){
	this->id=id;
}
