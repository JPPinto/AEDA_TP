#ifndef _FUNCIONARIO_H_
#define _FUNCIONARIO_H_

#include <string>
#include "Turma.h"
#include "Professor.h"
#include<memory>

class Funcionario :public Pessoa{

protected:
	

	vector<Turma *> _turmas;
	long _contacto;

public:
	Funcionario(string n, long contacto);
	
	string print();
	void setContacto(const long int c);
	long int getContacto()const{return _contacto;}
	vector<Turma *> getTurmas()const{return _turmas;}
	bool addTurma(Turma * t);
	void setTurmas(vector<Turma *> t);
	bool removeTurma(const int id);
	bool operator<(const Funcionario & f2) const;
	bool operator==(const Funcionario & f2)const;
	virtual string printSaveFormat()const;


	virtual ~Funcionario(void);

};



#endif /* FUNCIONARIO_H_ */