#ifndef TURMA_H_
#define TURMA_H_

#include "Horario.h"
#include <sstream>

using namespace std;

class Turma {

private:
	int id, anoEscolar;

public:
	Turma();
	Turma(int id, int anoEscolar);
	Turma(int id);
	virtual ~Turma();

	int getID();
	int getAnoEscolar();

	void setID(int i);
	void setAnoEscolar(int ae);
	string print();
	string printSaveFormat()const;

	bool operator==(Turma * t2);
};
#endif /* TURMA_H_ */
