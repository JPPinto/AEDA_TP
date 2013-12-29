#include "Livraria.h"


Livraria::Livraria(void){
}

Livraria::Livraria(string denominacao, string localizacao, vector<Disciplina*> especialidade, vector<int> anoEscolaridade){
	this->denominacao=denominacao;
	this->localizacao=localizacao;
	this->especialidade=especialidade;
	this->anoEscolaridade=anoEscolaridade;
}


Livraria::~Livraria(void){
}

string Livraria::getDenominacao(){
	return denominacao;
}
	
string Livraria::getLocalizacao(){
	return localizacao;
}
	
vector<Disciplina*> Livraria::getEspecialidade(){
	return especialidade;
}
	
vector<int> Livraria::getAnoEscolaridade(){
	return anoEscolaridade;
}

void Livraria::setDenominacao(string denominacao){
	this->denominacao=denominacao;
}
	
void Livraria::setLocalizacao(string localizacao){
	this->localizacao=localizacao;
}
	
void Livraria::setEspecialidade(vector<Disciplina*> especialidade){
	this->especialidade=especialidade;
}
	
void Livraria::setAnoEscolaridade(vector<int> anoEscolaridade){
	this->anoEscolaridade=anoEscolaridade;
}

void Livraria::addEspecialidade(Disciplina* d){
	especialidade.push_back(d);
}

void Livraria::addAnoEscolaridade(int ano){
	anoEscolaridade.push_back(ano);
}

bool Livraria::operator==(Livraria * liv){
	return this->denominacao==liv->getDenominacao();
}
