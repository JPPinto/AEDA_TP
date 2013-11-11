#ifndef PROFESSOR_H_
#define PROFESSOR_H_

#include <string>
#include <sstream>
#include <vector>
#include "Turma.h"
#include "Disciplina.h"

using namespace std;
/// Classe Base para Professor e Aluno
class Pessoa {

private:
	string _nome;

public:
	Pessoa(string n){_nome = n;}
	void setNome(const string n){_nome = n;}
	string getNome()const{return _nome;}
	virtual string print(){return "";}

};

/// Professor de uma Escola (class Base), podendo ou nao ser Director de Turma
class Professor : public Pessoa{

	///< Nome do Professor
	Disciplina * _disciplina;		///< Disciplina que o Professor lecciona
	vector<Turma *> _turmas;		///< Turmas em que o Professor lecciona
	//Horario horario;				///< Horario das turmas em que o Professsor lecciona
public:
	Professor(string n, Disciplina * d,Turma* t);			///< Construtor de Professor inicializando com o minimo de uma turma

	bool addTurma(Turma * t);								///< Adiciona uma Turma as do Professor
	bool removeTurma(const int id);							///< Remove uma Turma das do Professor

	string print();
	void setDisciplina(Disciplina * d){_disciplina = d;}
	Disciplina * getDiscipina()const{return _disciplina;}
	vector<Turma *> getTurmas()const{return _turmas;}
	bool operator==(Professor * p2);
	virtual ~Professor();

};

/// Classe derivado de Professor tendo a mais um vector com as turmas de que e responsavel
class DirectorTurma: public Professor{

private:
	vector<Turma *> _turmas_resposaveis;	///< Turmas que o DirectorTurma e responsavel
	//Horario _horario_atendimento;			///< Horario de atendimento das turmas responsaveis do DirectorTurma

public:
	DirectorTurma(string n, Disciplina * d,Turma* t, Turma * t_responsavel);
	bool addTurmaResponsavel(Turma * t);
	bool removeTurmaResponsavel(const int id);

	vector<Turma *> getTurmasResponsaveis(){return _turmas_resposaveis;}

	~DirectorTurma();
};
#endif /* PROFESSOR_H_ */
