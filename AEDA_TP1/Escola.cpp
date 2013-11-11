#include "Escola.h"

//Aluno
vector<Aluno *> Escola::getAlunos() {
	return _alunos;
}

Aluno * Escola::getAlunoByNome(const string n) {
	vector<Aluno*>::iterator it = _alunos.begin();
	for (; it < _alunos.end(); it++) {
		if ((*it)->getNome() == n) {
			return (*it);
		}
	}
	Aluno * a = new Aluno(n, 1, 1);
	throw new AlunoNaoExistente(a);
}

bool Escola::addAlunos(string nome, int numero, int turma) {
	Aluno * a2 = new Aluno(nome, numero, turma);
	_alunos.push_back(a2);
	return true;
}

string Escola::showAluno(Aluno * a) {
	vector<Aluno*>::iterator it = _alunos.begin();
	stringstream s;
	for (; it < _alunos.end(); it++) {
		if ((*it) == a) {
			s << "Nome: " << a->getNome() << " - Numero: " << a->getNumero()
					<< " - Turma: " << a->getNumero() << endl;
			return s.str();
		}
	}

	throw new AlunoNaoExistente(a);
}

bool Escola::updateAluno(Aluno * a) {
	bool b = false;

	vector<Aluno*>::iterator it = _alunos.begin();

	for (; it < _alunos.end(); it++) {
		if ((*it) == a) {
			b = true;
			break;
		}
	}
	if(b){
		(*it) = a;
		return true;
	}
	throw AlunoNaoExistente(a);
}

bool Escola::removeAluno(Aluno * a) {
	bool b = false;

	vector<Aluno*>::iterator it = _alunos.begin();

	for (; it < _alunos.end(); it++) {
		if ((*it) == a) {
			b = true;
			break;
		}
	}
	if(b){
		_alunos.erase(it);
	}
	throw AlunoNaoExistente(a);
}

//Professor
vector<Professor *> Escola::getProfessores(){
	return _professores;
}

Professor * Escola::getProfessorByNome(const string n){
	for(int i=0;i < _professores.size();i++){
		if(_professores[i]->getNome()==n){
			return _professores[i];
		}
	}
	//throw
}

bool Escola::addProfessor(Professor * p);
bool Escola::showProfessor();
bool Escola::updateProfessor(Professor * p);
bool Escola::removeProfessor(const string n);

//Turma
vector<Turma *> getTurmas() ;
Turma * getTurmaById(const int id);

bool addTurma(Turma * t);
bool showTurma();
bool updateTurma(Turma * t);
bool removeTurma(const int id);

//Disciplina
vector<Disciplina *> getDiscipinas() ;
Disciplina * getDisciplinaByNome(const string n);

bool addDisciplina(Disciplina * d);
bool showDisciplina();
bool updateDisciplina(Disciplina * d);
bool removeDisciplina(const string n);

Escola::Escola() {
}
