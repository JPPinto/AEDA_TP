#ifndef _ESCOLA_H_
#define _ESCOLA_H_

#include "Aluno.h"
#include "Professor.h
#include "Turma.h"
#include "Horario.h"
#include "Disciplina.h"

class Escola
{
private:
	vector<Aluno *> _alunos;
	vector<Professor *> _professores;
	vector<Turma *> _turmas;
	//vector<Horario *> _horarios; Não há horarios sem turmas, tem de ser um atributo de Turma
	vector<Disciplina *> _disciplinas;

public:

	Escola();

	Escola(Escola escola);

	vector<Aluno *> getAlunos();

	vector<Professor *> getProfessores();
	
	vector<Turma *> getTurmas();
	
	vector<Disciplina *> getDiscipinas();

	~Escola();
}

#endif