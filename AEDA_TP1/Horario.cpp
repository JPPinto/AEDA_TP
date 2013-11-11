/*
 * Horario.cpp
 *
 *  Created on: 30/09/2013
 *      Author: João
 */

#include "Horario.h"

Horario::Horario() {

}

Horario::~Horario() {

}

vector<Disciplina*> Horario::getDisciplinas()const{
	return disciplinas;
}


bool Horario::addDisciplina(Disciplina* d){
	bool b=false;

	vector<Disciplina*>::iterator it=disciplinas.begin();
	for(;it!=disciplinas.end();it++){
		if((*it)->getHoraInicio()==d->getHoraInicio() || (*it)->getHoraFim()==d->getHoraFim()){
			b=false;
		}else{
			b=true;
			break;
		}
	}
	if(b){
		disciplinas.push_back(d);
		return true;
	}
	return false;
}
