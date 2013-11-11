#include "Escola.h"

//Aluno
/**
 *
 * @return int _alunos
 */
vector<Aluno *> Escola::getAlunos() {
	return _alunos;
}
	
void Escola::setAluno(Aluno* a){
	_alunos.push_back(a);
}
/**
 *
 * @param n
 * @return
 */
Aluno * Escola::getAlunoByNome(string n) {
	vector<Aluno*>::iterator it = _alunos.begin();
	for (; it < _alunos.end(); it++) {
		if ((*it)->getNome() == n) {
			return (*it);
		}
	}
	Aluno * a = new Aluno(n, 1, (new Turma()));
	throw new AlunoNaoExistente(a);
}

/**
 *
 * @param nome
 * @param numero
 * @param t
 * @return
 */
bool Escola::addAluno(string nome, int numero, Turma * t) {
	Aluno * a2 = new Aluno(nome, numero, t);
	_alunos.push_back(a2);
	return true;
}

/**
 *
 * @param a
 * @return
 */
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

/**
 *
 * @param a
 * @return
 */
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

/**
 *
 * @param a
 * @return boolean
 */
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

/**
 * @brief Devolve todos os professores existentes na Escola
 * @return Professor * _professores
 */
//Professor
vector<Professor *> Escola::getProfessores(){
	return _professores;
}

/**
 * @brief Set method Professor* into Professores array
 * @param p
 */
void Escola::setProfessor(Professor* p){
	_professores.push_back(p);
}

/**
 *
 * @param n
 * @return
 */
Professor * Escola::getProfessorByNome(const string n){
	for(unsigned int i=0;i < _professores.size();i++){
		if(_professores[i]->getNome()==n){
			return _professores[i];
		}
	}
	Professor* p=new Professor(n, NULL, NULL);
	throw new ProfessorNaoExistente(p);
}
/**
 *
 * @param n
 * @param d
 * @param t
 * @return
 */
bool Escola::addProfessor(string n, string  d, int t){
	Professor * p2 = new Professor(n, getDisciplinaByNome(d), getTurmaById(t));
	_professores.push_back(p2);
	return true;
}
/**
 *
 * @param p
 * @return
 */
string Escola::showProfessor(Professor * p){
	vector<Professor*>::iterator it = _professores.begin();
	stringstream s;
	for (; it < _professores.end(); it++) {
		if ((*it) == p) {
			s << "Nome: " << p->getNome() << " - Disciplina: " << p->getDiscipina()->getNome() << endl;
			for(unsigned int i=0;i<p->getTurmas().size();i++){
				s<< " - Turma: " << p->getTurmas()[i]->getID() << " - Ano: " << p->getTurmas()[i]->getAnoEscolar() << endl;
			}
			return s.str();
		}
	}
	throw new ProfessorNaoExistente(p);
}
/**
 *
 * @param p
 * @return
 */
bool Escola::updateProfessor(Professor * p){
	bool b = false;

	vector<Professor*>::iterator it = _professores.begin();

	for (; it < _professores.end(); it++) {
		if ((*it) == p) {
			b = true;
			break;
		}
	}
	if(b){
		(*it) = p;
		return true;
	}
	throw new ProfessorNaoExistente(p);
}
/**
 *
 * @param n
 * @return
 */
bool Escola::removeProfessor(const string n){
	bool b = false;

	vector<Professor*>::iterator it = _professores.begin();

	for (; it < _professores.end(); it++) {
		if ((*it) == getProfessorByNome(n)) {
			b = true;
			break;
		}
	}
	if(b){
		_professores.erase(it);
	}
	throw ProfessorNaoExistente(getProfessorByNome(n));
}

//Turma
/**
 *
 * @return
 */
vector<Turma *> Escola::getTurmas(){
	return _turmas;
}
/**
 *
 * @param t
 */
void Escola::setTurma(Turma* t){
	_turmas.push_back(t);
}
/**
 *
 * @param id
 * @return
 */
Turma * Escola::getTurmaById(const int id){
	vector<Turma*>::iterator it=_turmas.begin();
	for(; it!=_turmas.end();it++){
		if((*it)->getID()==id){
			return (*it);
		}
	}
	throw new TurmaNaoExistente((*it));
}
/**
 *
 * @param id
 * @param anoEscolar
 * @return
 */
bool Escola::addTurma(int id, int anoEscolar){
	Turma * t2 = new Turma(id, anoEscolar);
	_turmas.push_back(t2);
	return true;
}
/**
 *
 * @param t
 * @return
 */
string Escola::showTurma(Turma * t){
	vector<Turma*>::iterator it = _turmas.begin();
	stringstream s;
	for (; it < _turmas.end(); it++) {
		if ((*it) == t) {
			s << "Turma: " << t->getID() << " - Ano: " << t->getAnoEscolar() << endl;
			return s.str();
		}
	}

	throw new TurmaNaoExistente(t);
}
/**
 *
 * @param t
 * @return
 */
bool Escola::updateTurma(Turma * t){
	bool b = false;

	vector<Turma*>::iterator it = _turmas.begin();

	for (; it < _turmas.end(); it++) {
		if ((*it) == t) {
			b = true;
			break;
		}
	}
	if(b){
		(*it) = t;
		return true;
	}
	throw TurmaNaoExistente(t);
}
/**
 *
 * @param id
 * @return
 */
bool Escola::removeTurma(const int id){
	bool b = false;

	vector<Turma*>::iterator it = _turmas.begin();

	for (; it < _turmas.end(); it++) {
		if ((*it) == getTurmaById(id)) {
			b = true;
			break;
		}
	}
	if(b){
		_turmas.erase(it);
	}
	throw TurmaNaoExistente((*it));
}
/** */
//Disciplina
/**
 *
 * @return Disiciplina _disciplinas
 */
vector<Disciplina *> Escola::getDiscipinas() {
	return _disciplinas;
}
/**
 *
 * @param d
 */
void Escola::setDisciplina(Disciplina* d){
	_disciplinas.push_back(d);
}
/**
 *
 * @param n
 * @return
 */
Disciplina * Escola::getDisciplinaByNome(const string n){
	vector<Disciplina*>::iterator it=_disciplinas.begin();
	for(;it!=_disciplinas.end();it++){
		if((*it)->getNome()==n){
			return getDisciplinaByNome(n);
		}
	}
	throw new DisciplinaNaoExistente((*it));
}
/**
 *
 * @param nome
 * @param d
 * @param h
 * @return
 */
bool Escola::addDisciplina(string nome, int d, int h){
	Disciplina * d2 = new Disciplina(nome, d, h);
	_disciplinas.push_back(d2);
	return true;
}
/**
 *
 * @param d
 * @return
 */
string Escola::showDisciplina(Disciplina * d){
	vector<Disciplina*>::iterator it = _disciplinas.begin();
	stringstream s;
	for (; it < _disciplinas.end(); it++) {
		if ((*it) == d) {
			s << "Disciplina: " << d->getNome() << " - Duracao: " << d->getDuracao()
				<< " - Hora de inicio: " << d->getHoraInicio() << endl;
			return s.str();
		}
	}
	throw DisciplinaNaoExistente(d);
}
/**
 *
 * @param d
 * @return
 */
bool Escola::updateDisciplina(Disciplina * d){
	bool b = false;

	vector<Disciplina*>::iterator it = _disciplinas.begin();

	for (; it < _disciplinas.end(); it++) {
		if ((*it) == d) {
			b = true;
			break;
		}
	}
	if(b){
		(*it) = d;
		return true;
	}
	throw DisciplinaNaoExistente(d);
}
/**
 *
 * @param n
 * @return
 */
bool Escola::removeDisciplina(const string n){
	bool b = false;

	vector<Disciplina*>::iterator it = _disciplinas.begin();

	for (; it < _disciplinas.end(); it++) {
		if ((*it) == getDisciplinaByNome(n)) {
			b = true;
			break;
		}
	}
	if(b){
		_disciplinas.erase(it);
	}
	throw DisciplinaNaoExistente((*it));
}

Escola::Escola() {
}
