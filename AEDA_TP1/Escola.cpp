#include "Escola.h"

//Aluno
/**
*
* @return int _alunos
*/
vector<Aluno *> Escola::getAlunos() {
	return _alunos;
}
void Escola::setAlunos( vector<Aluno*> a )
{
	_alunos = a;
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
	throw AlunoNaoExistente(n);
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

	for(auto i = 0u; i < _alunos.size(); i++){
		if(_alunos[i] == a2)
			throw NaoEPossivelAdicionarAluno(nome);
	}

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

	throw AlunoNaoExistente(a->getNome());
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
	throw AlunoNaoExistente(a->getNome());
}

/**
*
* @param a
* @return boolean
*/
void Escola::removeAluno(string a) {
	bool b = false;

	vector<Aluno*>::iterator it = _alunos.begin();

	for (; it < _alunos.end(); it++) {
		if ((*it)->getNome() == a) {
			b = true;
			break;
		}
	}
	if(b){
		_alunos.erase(it);
	}else{
		throw AlunoNaoExistente(a);
	}
}

void Escola::printAlunos(){
	if(_alunos.empty())
		cout << endl << "Nao existem alunos inscritos!" << endl;
	else
		for(unsigned int i = 0; i < _alunos.size(); i++){
			cout << _alunos[i]->print(); 
		}
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
void Escola::setProfessores( vector<Professor*> p )
{
	_professores = p;
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
	Professor* p=new Professor(n, NULL, NULL, 0);
	throw ProfessorNaoExistente(n);
}
/**
*
* @param n
* @param d
* @param t
* @return
*/
bool Escola::addProfessor(string n, string  d, int t, long c){
	Professor * p2 = new Professor(n, getDisciplinaByNome(d), getTurmaById(t), c);

	for (auto i = 0u; i < _professores.size();i++)
	{
		if(_professores[i] == p2)
			throw NaoEPossivelAdicionarProfessor(n);
	}

	_professores.push_back(p2);
	return true;
}

bool Escola::addDirector(string n, string  d, int t1, long c,int t2){
	DirectorTurma * p2 = new DirectorTurma(n, getDisciplinaByNome(d), getTurmaById(t1), c, getTurmaById(t2));

	for (auto i = 0u; i < _professores.size();i++)
	{
		if(_professores[i] == p2)
			throw NaoEPossivelAdicionarProfessor(n);
	}

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
	throw ProfessorNaoExistente(p->getNome());
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
	throw ProfessorNaoExistente(p->getNome());
}
/**
*
* @param n
* @return
*/
void Escola::removeProfessor(const string n){
	bool b = false;

	vector<Professor*>::iterator it = _professores.begin();

	for (; it < _professores.end(); it++) {
		if ((*it)->getNome() == n) {
			b = true;
			break;
		}
	}
	if(b){
		_professores.erase(it);
	}
	throw ProfessorNaoExistente(n);
}

void Escola::printProfessores(){
	if(_professores.empty())
		cout << endl << "Nao existem Professores inscritos!" << endl;
	else
		for(unsigned int i = 0; i < _professores.size(); i++){
			if(!_professores[i]->getDirectorTurma())
			cout << _professores[i]->print();
		}
}

void Escola::printDirectoresTurma(){
	if(_professores.empty())
		cout << endl << "Nao existem Professores inscritos!" << endl;
	else
		for(unsigned int i = 0; i < _professores.size(); i++){
			if(_professores[i]->getDirectorTurma())
				cout << _professores[i]->print();
		}
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
void Escola::setTurmas( vector<Turma*> t )
{
	_turmas = t;
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
	throw TurmaNaoExistente(id);
}
/**
*
* @param id
* @param anoEscolar
* @return
*/
bool Escola::addTurma(int id, int anoEscolar){
	Turma * t2 = new Turma(id, anoEscolar);

	for (auto i = 0u; i < _turmas.size();i++)
	{
		if(_turmas[i] == t2)
			throw NaoEPossivelAdicionarTurma(id);
	}

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

	throw TurmaNaoExistente(t->getID());
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
	throw TurmaNaoExistente(t->getID());
}
/**
*
* @param id
* @return
*/
void Escola::removeTurma(const int id){
	bool b = false;

	vector<Turma*>::iterator it = _turmas.begin();

	for (; it < _turmas.end(); it++) {
		if ((*it)->getID() == id) {
			b = true;
			break;
		}
	}
	if(b){
		_turmas.erase(it);
	}
	throw TurmaNaoExistente(id);
}

void Escola::printTurmas(){
	if(_turmas.empty())
		cout << endl << "Nao existem Turmas!" << endl;
	else
		for(unsigned int i = 0; i < _turmas.size(); i++){
			cout << _turmas[i]->print();
		}
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
void Escola::setDisciplina(vector<Disciplina *> d){
	_disciplinas = d;
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
			return (*it);
		}
	}
	throw DisciplinaNaoExistente(n);
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

	for(auto i = 0u; i < _disciplinas.size(); i++){
		if(_disciplinas[i]->getNome() == d2->getNome())
			throw NaoEPossivelAdicionarDisciplina(d2->getNome());
	}

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
			s << endl << "Disciplina: " << d->getNome() << " - Duracao: " << d->getDuracao()
				<< " - Hora de inicio: " << d->getHoraInicio() << endl;
			return s.str();
		}
	}
	throw DisciplinaNaoExistente(d->getNome());
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
	throw DisciplinaNaoExistente(d->getNome());
}
/**
*
* @param n
* @return
*/
void Escola::removeDisciplina(const string n){
	bool b = false;

	vector<Disciplina*>::iterator it = _disciplinas.begin();

	for (; it < _disciplinas.end(); it++) {
		if ((*it)->getNome() == n) {
			b = true;
			break;
		}
	}
	if(b){
		_disciplinas.erase(it);
	}
	throw DisciplinaNaoExistente(n);
}

void Escola::printDisciplinas(){
	if(_disciplinas.empty())
		cout << endl << "Nao existem Disciplinas!" << endl;
	else
		for(unsigned int i = 0; i < _disciplinas.size(); i++){
			cout << _disciplinas[i]->print();
		}
}

Escola::Escola() {
}
