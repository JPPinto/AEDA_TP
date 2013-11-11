#include "Disciplina.h"
#include "Excepcao.h"

#define DURACAO_MAX 90

Disciplina::Disciplina(string nome, int d, int h) {
	this->_nome=nome;
	setDuracao(d);
}


string Disciplina::getNome() const{
	return _nome;
}

void Disciplina::setNome(string nome){
	this->_nome=nome;
}

int Disciplina::getDuracao() const{
	return _duracao;
}

void Disciplina::setDuracao(int d){
	if(d > DURACAO_MAX || d <= 0)
		throw new DuracaoExcedida(d);
	_duracao = d;
}

int Disciplina::getHoraInicio() const{
	return _hora_inicio;
}

void Disciplina::setHoraInicio(int h){
	_hora_inicio = h;
}

int Disciplina::getHoraFim() const{
	return _hora_inicio+_duracao;
}
