#ifndef LIVRARIA_H_
#define LIVRARIA_H_

#include <string>
#include <vector>
#include "Disciplina.h"
#include <sstream>
#include <functional>

using namespace std;

class Livraria{
	string denominacao;
	string localizacao;
	int distancia;
	vector<Disciplina*> especialidade;
	vector<int> anoEscolaridade;
public:
	struct minLivraria : public std::binary_function<Livraria*, Livraria*, bool>{
		bool operator()(const Livraria* min, const Livraria* max) const{
			return min<max;
		}
	};

	Livraria(void);
	Livraria(string denominacao, string localizacao, int distancia, vector<Disciplina*> especialidade, vector<int> anoEscolaridade);
	~Livraria(void);

	string getDenominacao() const;
	string getLocalizacao() const;
	int getDistancia() const;
	vector<Disciplina*> getEspecialidade() const;
	vector<int> getAnoEscolaridade() const;

	void setDenominacao(string denominacao);
	void setLocalizacao(string localizacao);
	void setDistancia(int distancia);
	void setEspecialidade(vector<Disciplina*> especialidade);
	void setAnoEscolaridade(vector<int> anoEscolaridade);

	void addEspecialidade(Disciplina* d);
	void addAnoEscolaridade(int ano);

	bool operator==(Livraria * liv);
	bool operator<(Livraria * liv);
	string print();
	string printSaveFormat()const;
};
#endif

