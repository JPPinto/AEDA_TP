#include "Aluno.h"
#include "Excepcao.h"
#include "Escola.h"
#include <algorithm>

/**
 *
 * @param n
 * @param numero
 * @param t
 */
Aluno::Aluno(string n, int numero,Turma * t):Pessoa(n){
	this->_numero=numero;
	setTurma(t);
}
/**
 *
 * @return int _numero
 */
int Aluno::getNumero(){
	return _numero;
}
/**
 *
 * @return Turma _turma
 */
Turma * Aluno::getTurma(){
	return _turma;
}

/**
 *
 * @param numero
 */
void Aluno::setNumero(int numero){
	if(numero<=0 && numero>MAX_ALUNOS){
		throw new AlunosPorTurmaExcedido(this);
	}else{
		this->_numero=numero;
	}
}
/**
 *
 * @param t
 */
void Aluno::setTurma(Turma * t){
	_turma = t;
}
/**
 *
 * @param a2
 * @return
 */
bool Aluno::operator==(Aluno * a2){
	return (getNome() == a2->getNome()) && (this->getNumero() == a2->getNumero());
}
/**
 *
 * @return
 */
string Aluno::print(){
	stringstream s;
			s << "Nome: " << getNome() << " Numero: " << getNumero()
					<< " Turma: " << getTurma()->getID() << ";" << endl;
			return s.str();
}

string Aluno::printSaveFormat()const{

	stringstream s;

	string _temp_nome = getNome();
	replace(_temp_nome.begin(),_temp_nome.end(), ' ', '.');

	s << "Aluno " << _temp_nome << " " << _numero << " " << _turma->getID() << endl;

	return s.str();
}

