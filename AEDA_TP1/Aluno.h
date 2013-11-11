#ifndef _ALUNO_H_
#define _ALUNO_H_

#include <string>
#include "Turma.h"
#include "Professor.h"


#define MAX_ALUNOS 30

using namespace std;

class Aluno : public Pessoa{

	int _numero;
	Turma * _turma;
public:
	Aluno(string n, int numero,Turma * t);


	int getNumero();
	Turma * getTurma();

	void setNumero(int numero);
	void setTurma(Turma * t);
	bool operator==(Aluno * a2);
	string print();
};
#endif /* ALUNO_H_ */
