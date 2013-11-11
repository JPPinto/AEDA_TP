#ifndef _ESCOLA_H_
#define _ESCOLA_H_

#include "Aluno.h"
#include "Turma.h"
#include "Horario.h"
#include "Disciplina.h"
#include "Professor.h"

///Representa uma Escola contendo todos os seus Alunos, Professores, Turmas, Disciplinas e Horarios
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

	vector<Aluno *> getAlunos();							///< Devolve os alunos inscritos na Escola
		
	bool addAlunos(Aluno * a);								///< Adiciona um Aluno a Escola

	bool removeAluno(Aluno * a);							///< Remove um Aluno da Escola

	Aluno * getAlunoByNome(const string n) const;			///< Devolve o Aluno com o nome igual a n

	vector<Professor *> getProfessores()const;				///< Devolve todos os Professores que leccionam na Escola

	bool addProfessor(Professor * p);						///< Adiciona um Professor a Escola

	bool removeProfessor(const string n);					///< Remove um Professor da Escola

	Professor * getProfessorByNome(const string n) const;	///< Devolve o Professor com o nome igual a n

	vector<Turma *> getTurmas()const;						///< Devolve todas as turmas existentes na Escola

	bool addTurma(Turma * t);								///< Adiciona uma Turma a Escola

	bool removeTurma(const int id);							///< Remove uma Turma da Escola

	Turma * getTurmaById(const int id);						///< Devolve a Turma com o id igual a id

	vector<Disciplina *> getDiscipinas()const;				///< Devolve todas as Disciplinas que sao leccionadas na Escola

	bool addDisciplina(Disciplina * d);						///< Adiciona uma Disciplina a Escola

	bool removeDisciplina(const string n);					///< Remove uma disciplina da Escola

	Disciplina * getDisciplinaByNome(const string n)const;	///< Devolve a Disciplina com o nome igual a n

	~Escola();
};
#endif