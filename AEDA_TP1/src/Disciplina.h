/*
 * Disciplina.h
 *
 *  Created on: 30/09/2013
 *      Author: João
 */

#ifndef DISCIPLINA_H_
#define DISCIPLINA_H_

#include <string>
#include <vector>

using namespace std;

class Disciplina {
	string nome;
	int id;

public:
	Disciplina();
	Disciplina(string nome, int id);
	virtual ~Disciplina();
	string getNome();
	void setNome(string nome);
	int getID();
	void setID(int id);
};
#endif /* DISCIPLINA_H_ */
