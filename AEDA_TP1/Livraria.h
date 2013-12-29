#ifndef LIVRARIA_H_
#define LIVRARIA_H_

#include <string>
#include <vector>
#include "Disciplina.h"

using namespace std;

class Livraria{
	string denominacao;
	string localizacao;
	vector<Disciplina*> especialidade;
	vector<int> anoEscolaridade;
public:
	Livraria(void);
	Livraria(string denominacao, string localizacao, vector<Disciplina*> especialidade, vector<int> anoEscolaridade);
	~Livraria(void);

	string getDenominacao();
	string getLocalizacao();
	vector<Disciplina*> getEspecialidade();
	vector<int> getAnoEscolaridade();

	void setDenominacao(string denominacao);
	void setLocalizacao(string localizacao);
	void setEspecialidade(vector<Disciplina*> especialidade);
	void setAnoEscolaridade(vector<int> anoEscolaridade);

	void addEspecialidade(Disciplina* d);
	void addAnoEscolaridade(int ano);

	bool operator==(Livraria * liv);
};
#endif

