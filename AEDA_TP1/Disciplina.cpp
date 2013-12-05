#include "Disciplina.h"
#include "Excepcao.h"

#define DURACAO_MAX 90

/**
 *
 * @param nome
 * @param d
 * @param h
 */
Disciplina::Disciplina(string nome, int d, int h) {
	this->_nome=nome;
	setDuracao(d);
}

/**
 *
 * @return
 */
string Disciplina::getNome() const{
	return _nome;
}
/**
 *
 * @param nome
 */
void Disciplina::setNome(string nome){
	this->_nome=nome;
}
/**
 *
 * @return
 */
int Disciplina::getDuracao() const{
	return _duracao;
}
/**
 *
 * @param d
 */
void Disciplina::setDuracao(int d){
	if(d > DURACAO_MAX || d <= 0)
		throw DuracaoExcedida(d);
	_duracao = d;
}
/**
 *
 * @return
 */
int Disciplina::getHoraInicio() const{
	return _hora_inicio;
}
/**
 *
 * @param h
 */
void Disciplina::setHoraInicio(int h){
	_hora_inicio = h;
}
/**
 *
 * @return
 */
int Disciplina::getHoraFim() const{
	return _hora_inicio+_duracao;
}
/**
 *
 * @param d2
 * @return
 */
bool Disciplina::operator==(Disciplina * d2){
	return _nome == d2->getNome();
}

string Disciplina::print(){
		stringstream s;
		s << "Nome: " << getNome() << " Duracao: " << getDuracao()
			<< " Hora Inicio: " << getHoraInicio() << ";" << endl;
			return s.str();
}