#ifndef ESCOLA_H_
#define ESCOLA_H_

//#include <memory.hpp>
#include <unordered_set>
#include <iostream>
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
	vector<Aluno*> _alunos;					///< Todos os alunos inscritos na Escola
	vector<Professor*> _professores;		///< Todos os Professores que leccionam na Escola
	vector<Turma*> _turmas;					///< Todas as turmas existentes na Escola
	//vector<Horario *> _horarios; Não há horarios sem turmas, tem de ser um atributo de Turma
	vector<Disciplina*> _disciplinas;		///< Todas as disciplinas existentes na Escola
	tr1::unordered_set<Professor *, Professor::Hash_Prof> _ex_profs;  

public:

	Escola();

	//Aluno	
	vector<Aluno *> getAlunos();
	void setAlunos(vector<Aluno*> a);				///< Define o vector _alunos
	Aluno * getAlunoByNome(string n);				///< Devolve o Aluno com o nome igual a n

	bool addAluno(string nome,int numero, Turma* t);///< Adiciona um Aluno a Escola
	string showAluno(Aluno * a);					///< Mostra o Aluno no ecra
	bool updateAluno(Aluno * a);					///< Altera informacao do Aluno
	void removeAluno(string a);					///< Remove um Aluno da Escola
	void printAlunos();								///< Imprime os dados de todos os alunos

	//Professor
	vector<Professor *> getProfessores();			///< Devolve todos os professores existentes na Escola
	void setProfessores(vector<Professor*> p);		///< Define o vector _professores
	Professor * getProfessorByNome(const string n);	///< Devolve o Professor com o nome igual a n

	bool addProfessor(string n, string  d,int t, long c);	///< Adiciona um Professor a Escola
	bool addDirector(string n, string d, int t1, long c, int t2);	///< Adiciona um Director a Escola
	string showProfessor(Professor * p);			///< Mostra o Professor no ecra
	bool updateProfessor(Professor * p);			///< Altera a informacao do Professor
	void removeProfessor(const string n);			///< Remove um Professor da Escola
	void printProfessores();						///< Imprime os dados de todos os Professores
	void printDirectoresTurma();					///< Imprime os dados de todos os Directores de Tuma

	//Ex Professores
	tr1::unordered_set<Professor *, Professor::Hash_Prof> getExProfessores(){return _ex_profs;}
	void setExProfessores(tr1::unordered_set<Professor *, Professor::Hash_Prof> ex) {_ex_profs = ex;}
	Professor * getExProfessorByNome(const string s);
	void addExProfessor(Professor * prof);			///< Adiciona um professor a tabela de Ex Professores
	void removerExProfessor(const string n);		///< Remove um ex professor da tabela
	void printExProfessores()const;							///< Imprime os dados de todos os ex professores
	string printSaveData()const;					///< Imprime os dados de todos os ex professores em format para o ficheiro de output

	//Turma
	vector<Turma *> getTurmas();					///< Devolve todas as turmas existentes na Escola
	void setTurmas(vector<Turma*> t);				///< Define o vector _turmas
	Turma * getTurmaById(int id);					///< Devolve a Turma com o id igual a id
	bool emptyTurmas()const{return _turmas.empty();}///< Devolve se _turmas esta vazio

	bool addTurma(int id, int anoEscolar);			///< Adiciona uma Turma a Escola
	string showTurma(Turma * t);					///< Mostra a Turma no ecra
	bool updateTurma(Turma * t);					///< Altera a informacao da Turma
	void removeTurma(const int id);					///< Remove uma Turma da Escola
	void printTurmas();								///< Imprime os dados de todas as Turmas


	//Disciplina
	vector<Disciplina *> getDiscipinas();					///< Devolve todas as Disciplinas que sao leccionadas na Escola
	void setDisciplina(vector<Disciplina *> d);				///< Define o vector _disciplinas
	Disciplina * getDisciplinaByNome(const string n);		///< Devolve a Disciplina com o nome igual a n
	bool emptyDisciplinas()const{							///< Devolve se _turmas esta vazio
		return _disciplinas.empty();}						

	bool addDisciplina(string nome, int d, int h);			///< Adiciona uma Disciplina a Escola
	string showDisciplina(Disciplina * d);					///< Mostra a Disciplina no ecra
	bool updateDisciplina(Disciplina * d);					///< Altera a informacao da Disciplina
	void removeDisciplina(const string n);					///< Remove uma disciplina da Escola
	void printDisciplinas();								///< Imprime os dados de todas as Disciplinas

	~Escola();
};
#endif
