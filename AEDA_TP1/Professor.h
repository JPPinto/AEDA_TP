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

protected:
	string _nome;

public:
	Pessoa(string n){_nome = n;}
	void setNome(const string n){_nome = n;}
	string getNome()const{return _nome;}
	virtual string print(){return "";}

};

/// Professor de uma Escola (class Base), podendo ou nao ser Director de Turma
class Professor : public Pessoa{

protected:

	bool director_turma;
	Disciplina * _disciplina;		///< Disciplina que o Professor lecciona
	vector<Turma *> _turmas;		///< Turmas em que o Professor lecciona
	vector<Disciplina *> _d_area;	///< Disciplinas da sua area
	long int contacto;				///< Contacto telefonico
	//Horario horario;				///< Horario das turmas em que o Professsor lecciona

public:
	Professor(string n, Disciplina * d,Turma* t, long c);			///< Construtor de Professor inicializando com o minimo de uma turma

	bool addTurma(Turma * t);								///< Adiciona uma Turma as do Professor
	bool removeTurma(const int id);							///< Remove uma Turma das do Professor

	string print();											///< Devolve uma string com toda a informacao do Professor
	void setContacto(const long int c){contacto = c;}		///< Altera o contacto
	long int getContacto()const{return contacto;}			///< Devolve o contacto
	void setDisciplina(Disciplina * d){_disciplina = d;}	///< Altera a disciplina que o professor lecciona
	vector<Disciplina *> getDArea()const{return _d_area;}	///< Devolve as disciplinas da sua area
	Disciplina * getDiscipina()const{return _disciplina;}	///< Devolve a disciplina que o professor lecciona
	vector<Turma *> getTurmas()const{return _turmas;}		///< Devolve as turmas que o professor lecciona
	void addDisciplinaAres(Disciplina *);					///< Adiciona displina as disciplinas da area do Professor
	bool getDirectorTurma(){return director_turma;}			///< Devolve se este Professor e director de turma
	bool operator==(Professor * p2);						///< Definicao do operador ==
	virtual string printSaveFormat()const;					///< Devolve uma string no formato para guardar em ficheiros
	virtual ~Professor();									///< Destrutor de Professor

};

/// Classe derivado de Professor tendo a mais um vector com as turmas de que e responsavel
class DirectorTurma: public Professor{

private:
	vector<Turma *> _turmas_resposaveis;	///< Turmas que o DirectorTurma e responsavel
	//Horario _horario_atendimento;			///< Horario de atendimento das turmas responsaveis do DirectorTurma

public:
	DirectorTurma(string n, Disciplina * d,Turma* t, long c ,Turma * t_responsavel);
	bool addTurmaResponsavel(Turma * t);
	bool removeTurmaResponsavel(const int id);
	bool operator==(DirectorTurma * p2);
	string printSaveFormat()const;			///< Devolve uma string no formato para guardar em ficheiros
	string print();

	vector<Turma *> getTurmasResponsaveis()const {return _turmas_resposaveis;}

	~DirectorTurma();
};
#endif /* PROFESSOR_H_ */
