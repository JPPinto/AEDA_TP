#include "Livraria.h"


Livraria::Livraria(void){
}

Livraria::Livraria(string denominacao, string localizacao, int distancia, vector<Disciplina*> especialidade, vector<int> anoEscolaridade){
	this->denominacao=denominacao;
	this->localizacao=localizacao;
	this->distancia=distancia;
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
	
string Livraria::print(){
	stringstream ss;
	ss<<"Denominacao: "<<denominacao<<" \n	Localizacao: "<<localizacao<<"\n	Area de especialidade: ";
	for(int i=0;i<especialidade.size();i++){
		ss<<especialidade[i]->getNome()<<",";
	}
	ss<<"\n		Anos de escolaridade";
	for(int i=0;i<anoEscolaridade.size();i++){
		ss<<anoEscolaridade[i]<<",";
	}
	ss<<"\n";
	return ss.str();
}

