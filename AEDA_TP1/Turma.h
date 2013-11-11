#ifndef TURMA_H_
#define TURMA_H_

#include "Horario.h"

using namespace std;

class Turma {

private:
	int id, anoEscolar;
	Horario* horario;

public:
	Turma();
	Turma(int id, int anoEscolar);
	Turma(int id);
	virtual ~Turma();

	int getID();
	int getAnoEscolar();
	Horario* getHorario();

	void setID(int i);
	void setAnoEscolar(int ae);
	void setHorario(Horario* h);
};
#endif /* TURMA_H_ */
