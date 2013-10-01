/*
 * Turma.cpp
 *
 *  Created on: 30/09/2013
 *      Author: João
 */

#include "Turma.h"

Turma::Turma(){

}

Turma::Turma(int id, int anoEscolar) {
	this->id=id;
	this->anoEscolar=anoEscolar;
}

Turma::~Turma() {
	// TODO Auto-generated destructor stub
}

int Turma::getID(){
	return id;
}

void Turma::setID(int i){
	id=i;
}

int Turma::getAnoEscolar(){
	return anoEscolar;
}

void Turma::setAnoEscolar(int ae){
	anoEscolar=ae;
}

Horario Turma::getHorario(){
	return horario;
}

void Turma::setHorario(Horario h){

}
