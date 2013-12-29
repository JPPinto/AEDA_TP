/*
 * Horario.h
 *
 *  Created on: 30/09/2013
 *      Author: João
 */

#ifndef HORARIO_H_
#define HORARIO_H_

#define INICIO 480
#define FIM 1200
#define VARIANCIA 30

#include <vector>
#include "Disciplina.h"

using namespace std;
/// Horário de uma Turma
class Horario {
private:
	vector<Disciplina*> disciplinas;
public:
	Horario();
	virtual ~Horario();

	vector<Disciplina*> getDisciplinas()const;
	bool addDisciplina(Disciplina* d);
};
#endif /* HORARIO_H_ */
