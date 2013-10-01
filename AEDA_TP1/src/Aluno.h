/*
 * Aluno.h
 *
 *  Created on: 30/09/2013
 *      Author: João
 */

#ifndef ALUNO_H_
#define ALUNO_H_

#include <string>
#include "Turma.h"

using namespace std;

class Aluno {
	string nome;
	int numero, idTurma;
public:
	Aluno(int idTurma, string nome, int numero);
	virtual ~Aluno();
	int getIDturma();
	void setIDturma(int idT);
	string getNome();
	void setNome(string n);
	int getNumero();
	void setNumero(int n);
};
#endif /* ALUNO_H_ */
