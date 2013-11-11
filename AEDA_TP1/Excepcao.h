#include <sstream>
#include "Turma.h"
#include "Disciplina.h"
#include "Horario.h"

class TurmaExistente
{
public:
	Turma * turma;
	TurmaExistente(Turma * t){
		turma = t;
	}
	string getErro(){
		stringstream s;
		s << "Turma " << turma->getID() << " ja e leccionada por este professor!" << endl;
		return s.str();
	}
	virtual ~TurmaExistente(){}
};

class TurmaNaoExistente
{
public:
	Turma * turma;
	TurmaNaoExistente(Turma * t){
		turma = t;
	}
	string getErro(){
		stringstream s;
		s << "Turma " << turma->getID() << " nao existe!" << endl;
		return s.str();
	}
	virtual ~TurmaNaoExistente(){}
};
