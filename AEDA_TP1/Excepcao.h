#include <sstream>
#include "Turma.h"
#include "Disciplina.h"
#include "Horario.h"


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
