#ifndef EXCEPCAO_H_
#define EXCEPCAO_H_

#include <sstream>
#include "Turma.h"
#include "Disciplina.h"
#include "Horario.h"
#include "Aluno.h"
#include "Professor.h"

using namespace std;


/// Excepcao lancada quando uma Turma a ser adicionada ao vector de Turmas de uma Professor que ja contem a mesma
class TurmaExistente
{
public:
	Turma * turma;					///< Turma ja existente
	TurmaExistente(Turma * t){ 
		turma = t;
	}
	string getErro(){				///< Mensagem de erro lancada por esta excepcao
		stringstream s;
		s << "Turma " << turma->getID() << " ja e leccionada por este professor!" << endl;
		return s.str();
	}
	virtual ~TurmaExistente(){}		///< Destrutor
};

/// Excepcao lancada quando a Turma a ser acedida nao existe
class TurmaNaoExistente
{
public:
	Turma * turma;					///< Turma inesxistente
	TurmaNaoExistente(Turma * t){
		turma = t;
	}
	string getErro(){				///< Mensagem de erro lancada pela excepcao
		stringstream s;
		s << "Turma " << turma->getID() << " nao existe!" << endl;
		return s.str();
	}
	virtual ~TurmaNaoExistente(){}	///< Destrutor
};

/// Excepçao lancada quando o numero de alunos por turma é excedido
class AlunosPorTurmaExcedido
{
public:
	Aluno * aluno;					///< Aluno que excede o limite da turma
	AlunosPorTurmaExcedido(Aluno * a){
		aluno=a;
	}
	string getErro(){				///< Mensagem de erro lancada pela excepcao
		stringstream s;
		s << "Aluno " << aluno->getNome() << " excede o limite da turma!" << endl;
		return s.str();
	}
	virtual ~AlunosPorTurmaExcedido(){}	///< Destrutor
};

/// Excepcao lancada quando o Aluno a ser acedido nao existe
class AlunoNaoExistente
{
public:
	Aluno * aluno;					///< Aluno inesxistente
	AlunoNaoExistente(Aluno * a){
		aluno = a;
	}
	string getErro(){				///< Mensagem de erro lancada pela excepcao
		stringstream s;
		s << "Aluno " << aluno->getNome() << " nao existe!" << endl;
		return s.str();
	}
	virtual ~AlunoNaoExistente(){}	///< Destrutor
};

/// Excepcao lancada quando o Professor a ser acedido nao existe
class ProfessorNaoExistente
{
public:
	Professor* professor;					///< Aluno inesxistente
	ProfessorNaoExistente(Professor* p){
		professor = p;
	}
	string getErro(){				///< Mensagem de erro lancada pela excepcao
		stringstream s;
		s << "Professor " << professor->getNome() << " nao existe!" << endl;
		return s.str();
	}
	virtual ~ProfessorNaoExistente(){}	///< Destrutor
};

class DuracaoExcedida{

public: 
	int _duracao;

	DuracaoExcedida(int d){
		_duracao = d;
	}

	string getErro()const{
		stringstream s;
		s << "A duracao, " << _duracao << ", excedeu os limites estabelecidos!(0 - 90)" << endl;
		return s.str();
	}
};

#endif