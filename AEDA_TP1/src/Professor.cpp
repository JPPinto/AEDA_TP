/*
 * Professor.cpp
 *
 *  Created on: 30/09/2013
 *      Author: João
 */

#include "Professor.h"
#include <iostream>

Professor::Professor(string nome, int idDisciplina, vector<int> turmas, bool directorTurma) {
	this->nome=nome;
	this->idDisciplina=idDisciplina;
	for(unsigned int i=0;i < turmas.size();i++){
		this->turmas.push_back(turmas[i]);
	}
	this->directorTurma=directorTurma;
}

Professor::~Professor() {
	// TODO Auto-generated destructor stub
}
