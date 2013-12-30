#ifndef LIVRARIA_H_
#define LIVRARIA_H_

#include <string>
#include <vector>
#include "Disciplina.h"
#include <sstream>

using namespace std;

class Livraria{
	string denominacao;
	string localizacao;
	int distancia;
	vector<Disciplina*> especialidade;
	vector<int> anoEscolaridade;
public:
	Livraria(void);
	Livraria(string denominacao, string localizacao, int distancia, vector<Disciplina*> especialidade, vector<int> anoEscolaridade);
	~Livraria(void);

	string getDenominacao();
	string getLocalizacao();
	int getDistancia();
	vector<Disciplina*> getEspecialidade();
	vector<int> getAnoEscolaridade();

	void setDenominacao(string denominacao);
	void setLocalizacao(string localizacao);
	void setDistancia(int distancia);
	void setEspecialidade(vector<Disciplina*> especialidade);
	void setAnoEscolaridade(vector<int> anoEscolaridade);

	void addEspecialidade(Disciplina* d);
	void addAnoEscolaridade(int ano);

	bool operator==(Livraria * liv);
	string print();
	string printSaveFormat()const;
};
#endif

