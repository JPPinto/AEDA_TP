#ifndef DISCIPLINA_H_
#define DISCIPLINA_H_

#include <string>
#include <vector>

using namespace std;

class Disciplina {
private:
	string _nome;
public:
	Disciplina();
	Disciplina(string _nome);
	virtual ~Disciplina();
	string getNome();
	void setNome(string _nome);

};
#endif /* DISCIPLINA_H_ */
