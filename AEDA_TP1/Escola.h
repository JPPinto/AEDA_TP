#ifndef ESCOLA_H_
#define ESCOLA_H_

#include "Aluno.h"
#include "Turma.h"
#include "Excepcao.h"
#include "Horario.h"
#include "Disciplina.h"
#include "Professor.h"

using namespace std;

///Representa uma Escola contendo todos os seus Alunos, Professores, Turmas, Disciplinas e Horarios
class Escola
{
private:
	vector<Aluno*> _alunos;			///< Todos os alunos inscritos na Escola
	vector<Professor*> _professores;	///< Todos os Professores que leccionam na Escola
	vector<Turma*> _turmas;			///< Todas as turmas existentes na Escola
	//vector<Horario *> _horarios; N�o h� horarios sem turmas, tem de ser um atributo de Turma
	vector<Disciplina*> _disciplinas;	///< Todas as disciplinas existentes na Escola

public:

	Escola();

	//Aluno
	vector<Aluno *> getAlunos();							///< Devolve os alunos inscritos na Escola
	Aluno * getAlunoByNome(const string n) const;			///< Devolve o Aluno com o nome igual a n

	bool addAlunos(Aluno * a);								///< Adiciona um Aluno a Escola
	void showAluno(Aluno * a);								///< Mostra o Aluno no ecra
	bool updateAluno(Aluno * a);							///< Altera informacao do Aluno
	bool removeAluno(Aluno * a);							///< Remove um Aluno da Escola


	//Professor
	vector<Professor *> getProfessores();					///< Devolve todos os professores existentes na Escola
	Professor * getProfessorByNome(const string n) const;	///< Devolve o Professor com o nome igual a n

	bool addProfessor(Professor * p);						///< Adiciona um Professor a Escola
	bool showProfessor(Professor * p);						///< Mostra o Professor no ecra
	bool updateProfessor(Professor * p);					///< Altera a informacao do Professor
	bool removeProfessor(const string n);					///< Remove um Professor da Escola


	//Turma
	vector<Turma *> getTurmas()const;						///< Devolve todas as turmas existentes na Escola
	Turma * getTurmaById(const int id);						///< Devolve a Turma com o id igual a id

	bool addTurma(Turma * t);								///< Adiciona uma Turma a Escola
	bool showTurma(Turma * t);								///< Mostra a Turma no ecra
	bool updateTurma(Turma * t);							///< Altera a informacao da Turma
	bool removeTurma(const int id);							///< Remove uma Turma da Escola


	//Disciplina
	vector<Disciplina *> getDiscipinas()const;				///< Devolve todas as Disciplinas que sao leccionadas na Escola
	Disciplina * getDisciplinaByNome(const string n)const;	///< Devolve a Disciplina com o nome igual a n

	bool addDisciplina(Disciplina * d);						///< Adiciona uma Disciplina a Escola
	bool showDisciplina(Disciplina * d);					///< Mostra a Disciplina no ecra
	bool updateDisciplina(Disciplina * d);					///< Altera a informacao da Disciplina
	bool removeDisciplina(const string n);					///< Remove uma disciplina da Escola

	~Escola();
};
#endif
