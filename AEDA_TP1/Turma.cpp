#include "Turma.h"
/**
 * @brief default empty constructor for Turma
 */
Turma::Turma(){

}
/**
 * @brief Constructor non-empty for Turma
 * @param id
 * @param anoEscolar
 */
Turma::Turma(int id, int anoEscolar) {
	this->id=id;
	this->anoEscolar=anoEscolar;
}
/**
 *
 * @param id
 */
Turma::Turma(int id) {
	this->id=id;
	this->anoEscolar = 0;
}
/**
 * @brief Default destructor
 */
Turma::~Turma() {}

/**
 *
 * @return
 */
int Turma::getID(){
	return id;
}
/**
 *
 * @param i
 */
void Turma::setID(int i){
	id=i;
}
/**
 *
 * @return
 */
int Turma::getAnoEscolar(){
	return anoEscolar;
}
/**
 *
 * @param ae
 */
void Turma::setAnoEscolar(int ae){
	anoEscolar=ae;
}
/**
 *
 * @return
 */
Horario* Turma::getHorario(){
	return horario;
}
/**
 *
 * @param h
 */
void Turma::setHorario(Horario* h){

}
/**
 *
 * @param t2
 * @return
 */
bool Turma::operator==(Turma * t2){
	return id == t2->getID();
}

string Turma::print(){
		stringstream s;
		s << "ID: " << getID() << " Ano Escolar: " << getAnoEscolar() << ";" << endl;
			return s.str();
}