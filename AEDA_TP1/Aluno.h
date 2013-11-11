/*
 * Aluno.h
 *
 *  Created on: 30/09/2013
 *      Author: João
 */

#ifndef _ALUNO_H_
#define _ALUNO_H_

#include <string>
#include "Turma.h"


#define MAX_ALUNOS 30

using namespace std;

class Aluno {
	string nome;
	int numero, idTurma;
public:
	Aluno(string nome, int numero, int idTurma);

	string getNome();
	int getNumero();
	int getTurma();

	void setNome(string nome);
	void setNumero(int numero);
	void setTurma(int idTurma);
};
#endif /* ALUNO_H_ */
