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
		s << endl << "ERRO: " << "Turma " << turma->getID() << " ja e leccionada por este professor!" << endl;
		return s.str();
	}
	virtual ~TurmaExistente(){}		///< Destrutor
};

/// Excepcao lancada quando a Turma a ser acedida nao existe
class TurmaNaoExistente
{
public:
	int id;					///< Turma inesxistente
	TurmaNaoExistente(int t){
		id = t;
	}
	string getErro(){
		stringstream s;
		s << endl << "ERRO: " <<  "Turma " << id << " nao existe!" << endl;
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
		s << endl << "ERRO: " << "Aluno " << aluno->getNome() << " excede o limite da turma!" << endl;
		return s.str();
	}
	virtual ~AlunosPorTurmaExcedido(){}	///< Destrutor
};

/// Excepcao lancada quando o Aluno a ser acedido nao existe
class AlunoNaoExistente
{
public:
	string nome;				///< Aluno inesxistente
	AlunoNaoExistente(string a){
		nome = a;
	}
	string getErro(){				///< Mensagem de erro lancada pela excepcao
		stringstream s;
		s << endl << "ERRO: " << "Aluno " << nome << " nao existe!" << endl;
		return s.str();
	}
	virtual ~AlunoNaoExistente(){}	///< Destrutor
};

/// Excepcao lancada quando o Professor a ser acedido nao existe
class ProfessorNaoExistente
{
public:
	string nome;					///< Professor inesxistente
	ProfessorNaoExistente(string p){
		nome = p;
	}
	string getErro(){				///< Mensagem de erro lancada pela excepcao
		stringstream s;
		s << endl << "ERRO: " << "Professor " << nome << " nao existe!" << endl;
		return s.str();
	}
	virtual ~ProfessorNaoExistente(){}	///< Destrutor
};

/// Excepcao lancada quando o Professor a ser acedido nao existe
class DisciplinaNaoExistente
{
public:
	string disciplina;					///< Nome de disciplina inesxistente

	DisciplinaNaoExistente(string d){
		disciplina = d;
	}
	string getErro(){				///< Mensagem de erro lancada pela excepcao
		stringstream s;
		s << endl << "ERRO: " << "Disciplina: " << disciplina << " nao existe!" << endl;
		return s.str();
	}
	virtual ~DisciplinaNaoExistente(){}	///< Destrutor
};

/// Excepcao lancada quando na criação de uma nova dsiciplina esta excede os limites de duracao por aula
class DuracaoExcedida{

public: 
	int _duracao;

	DuracaoExcedida(int d){
		_duracao = d;
	}

	string getErro()const{
		stringstream s;
		s << endl << "ERRO: " << "A duracao, " << _duracao << ", excedeu os limites estabelecidos!(0 - 90)" << endl;
		return s.str();
	}
};

/// Excepcao lancada quando nao e possivel adicionar alunos
class NaoEPossivelAdicionarAluno{
private:
	string id;
public:
	NaoEPossivelAdicionarAluno(){
		id ="";
	}
	NaoEPossivelAdicionarAluno(string i){
		id =i;
	}
	string getError(){
		stringstream s;
		if(id != "")
			s << endl << "ERRO: " << "Ja existe o Aluno " << id << " !" << endl;
		else
			s << endl << "ERRO: " << "Nao e possivel adicionar Alunos sem antes haver Turmas!" << endl;

		return s.str();
	}
};

/// Excepcao lancada quando nao e possivel adicionar profesores
class NaoEPossivelAdicionarProfessor{
private:
	string id;
public:
	NaoEPossivelAdicionarProfessor(){
		id = "";
	}
	NaoEPossivelAdicionarProfessor(string i){
		id = i;
	}
	string getErro(){
		stringstream s;

		if(id != "")
			s << endl << "ERRO: " << "Ja existe o Professor " << id << " !" << endl;
		else
			s << endl << "ERRO: " << "Nao foi possivel adicionar Professor!" << endl;

		return s.str();
	}
};

/// Excepcao lancada quando nao e possivel adicionar turmas
class NaoEPossivelAdicionarTurma{
private:
	int id;
public:
	NaoEPossivelAdicionarTurma(){
		id = -1;
	}
	NaoEPossivelAdicionarTurma(int i){
		id = i;
	}
	string getErro(){
		stringstream s;

		if(id != -1)
			s << endl << "ERRO: " << "Ja existe a Turma " << id << " !" << endl;
		else
			s << endl << "ERRO: " << "Nao foi possivel adicionar Turma!" << endl;

		return s.str();
	}
};

/// Excepcao lancada quando nao e possivel adicionar disciplinas
class NaoEPossivelAdicionarDisciplina{
private:
	string nome;
public:
	NaoEPossivelAdicionarDisciplina(){
		nome = "";
	}
	NaoEPossivelAdicionarDisciplina(string n){
		nome = n;
	}
	string getErro(){
		stringstream ss;

		if(!nome.size())
			ss << endl << "ERRO: " << "Ja existe a Disciplina " << nome << " !" << endl;
		else
			ss << endl << "ERRO: " << "Nao foi possivel adicionar Disciplina!" << endl;

		return ss.str();
	}
};

#endif
