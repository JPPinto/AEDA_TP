#ifndef _ALUNO_H_
#define _ALUNO_H_

#include <string>
#include "Turma.h"


#define MAX_ALUNOS 30

using namespace std;

class Aluno {
	string _nome;
	int _numero;
	Turma * _turma;
public:
	Aluno(string nome, int numero, int id);

	string getNome();
	int getNumero();
	Turma * getTurma();

	void setNome(string nome);
	void setNumero(int numero);
	void setTurma(int id);
	bool operator==(Aluno * a2);
};
#endif /* ALUNO_H_ */
