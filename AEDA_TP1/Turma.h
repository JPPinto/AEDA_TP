/*
 * Turma.h
 *
 *  Created on: 30/09/2013
 *      Author: João
 */

#ifndef TURMA_H_
#define TURMA_H_

#include "Horario.h"

using namespace std;

class Turma {
	int id, anoEscolar;
	Horario horario;

public:
	Turma();
	Turma(int id, int anoEscolar);
	Turma(int id);
	virtual ~Turma();
	int getID();
	void setID(int i);
	int getAnoEscolar();
	void setAnoEscolar(int ae);
	Horario getHorario();
	void setHorario(Horario h);
};
#endif /* TURMA_H_ */
