#include "Escola.h"

vector<Aluno *> Escola::getAlunos(){
	return _alunos;
}

bool addAluno(Aluno * a){
	return true;
}

bool removeAluno(Aluno * a){
	return true;
}

//Aluno * Escola::getAlunoByName(string nome){
//	return new Aluno();
//}

vector<Professor *> Escola::getProfessores()const{
	return _professores;
}

vector<Turma *> Escola::getTurmas()const{
	return _turmas;
}

vector<Disciplina *> Escola::getDiscipinas()const{
	return _disciplinas;
}

Escola::Escola(){
}