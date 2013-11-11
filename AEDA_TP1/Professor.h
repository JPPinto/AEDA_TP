/*
* Professor.h
*
*  Created on: 30/09/2013
*      Author: João
*/

#ifndef PROFESSOR_H_
#define PROFESSOR_H_

#include <string>
#include <sstream>
#include <vector>
#include "Turma.h"
#include "Disciplina.h"
#include "Horario.h"
#include "Excepcao.h"

using namespace std;

class Professor {

private:
	string _nome;					///< Nome do Professor
	Disciplina * _disciplina;		///< Disciplina que o Professor lecciona
	vector<Turma *> _turmas;		///< Turmas em que o Professor lecciona
	//Horario horario;				///< Horario das turmas em que o Professsor lecciona

public:
	Professor(string n, Disciplina * d,Turma* t);

	bool addTurma(Turma * t);
	bool removeTurma(const int id);

	void setNome(const string n){_nome = n;}
	string getNome()const{return _nome;}
	void setDisciplina(Disciplina * d){_disciplina = d;}
	Disciplina * getDiscipina()const{return _disciplina;}
	vector<Turma *> getTurmas()const{return _turmas;}

	virtual ~Professor();

};

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
