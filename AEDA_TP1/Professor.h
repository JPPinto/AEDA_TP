/*
 * Professor.h
 *
 *  Created on: 30/09/2013
 *      Author: João
 */

#ifndef PROFESSOR_H_
#define PROFESSOR_H_

#include <string>
#include <vector>
#include "Turma.h"
#include "Disciplina.h"
#include "Horario.h"

using namespace std;

class Professor {
	string nome;
	int idDisciplina;
	vector<int> turmas;
	bool directorTurma;
	Horario horario;

public:
	Professor(string nome, int idDisciplina, vector<int> turmas, bool directorTurma);
	virtual ~Professor();
};
#endif /* PROFESSOR_H_ */
