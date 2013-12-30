#include <algorithm>
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

string Livraria::getDenominacao() const{
	return denominacao;
}
	
string Livraria::getLocalizacao() const{
	return localizacao;
}
	
vector<Disciplina*> Livraria::getEspecialidade() const{
	return especialidade;
}
	
vector<int> Livraria::getAnoEscolaridade() const{
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
	
bool Livraria::operator<(Livraria * liv){
	return this->distancia<liv->distancia;
}
	
string Livraria::print(){
	stringstream ss;

	ss<<"Nome: "<<denominacao<<"\n	Localizacao: "<<localizacao<< endl;
	ss <<"	Area de especialidade: " << endl;
	for(auto i = 0u;i<especialidade.size();i++){
		ss<< "		" <<especialidade[i]->getNome()<<";" << endl;
	}
	ss<<"	Anos de escolaridade:";
	for(auto i = 0u;i<anoEscolaridade.size();i++){
		ss<< " " << anoEscolaridade[i];
	}

	ss << endl;

	return ss.str();
}

string Livraria::printSaveFormat()const{
	stringstream s;

	s << "Livraria ";
	string _temp_nome = denominacao;
	replace(_temp_nome.begin(),_temp_nome.end(), ' ', '.');

	string _temp_local = localizacao;
	replace(_temp_local.begin(),_temp_local.end(), ' ', '.');

	s << _temp_nome << " " << _temp_local << " " << distancia << " ";

	for(auto i=0u;i< this->especialidade.size();i++){

		string _temp_especial = especialidade[i]->getNome();
		replace(_temp_especial.begin(),_temp_especial.end(), ' ', '.');

		s << _temp_especial;
		if(i != especialidade.size() - 1)
			s << "-";
	}
	
	s << " ";

	for(unsigned int i=0;i< anoEscolaridade.size();i++){

		s << anoEscolaridade[i];

		if(i != anoEscolaridade.size() - 1)
			s << "-";
	}

	s << endl;

	return s.str();
}

