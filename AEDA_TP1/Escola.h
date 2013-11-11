#ifndef _ESCOLA_H_
#define _ESCOLA_H_

#include "Aluno.h"
#include "Turma.h"
#include "Horario.h"
#include "Disciplina.h"
#include "Professor.h"

class Escola
{
private:
	vector<Aluno *> _alunos;			///< Todos os alunos inscritos na Escola
	vector<Professor *> _professores;	///< Todos os Professores que leccionam na Escola
	vector<Turma *> _turmas;			///< Todas as turmas existentes na Escola
	//vector<Horario *> _horarios; Não há horarios sem turmas, tem de ser um atributo de Turma
	vector<Disciplina *> _disciplinas;	///< Todas as disciplinas existentes na Escola

public:

	Escola();

	vector<Aluno *> getAlunos();

	bool addAlunos(Aluno * a);

	bool removeAluno(Aluno * a);

	Aluno * getAlunoByName(string nome) const;

	vector<Professor *> getProfessores()const;

	vector<Turma *> getTurmas()const;

	vector<Disciplina *> getDiscipinas()const;

	~Escola();
};
#endif