/*
 * Horario.h
 *
 *  Created on: 30/09/2013
 *      Author: João
 */

#ifndef HORARIO_H_
#define HORARIO_H_

#include <vector>
#include "Disciplina.h"

using namespace std;

class Horario {
	vector<Disciplina> disciplinas;
public:
	Horario();
	virtual ~Horario();
};
#endif /* HORARIO_H_ */
