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

//Ex Professores
Professor * Escola::getExProfessorByNome(const string s){

	auto _temp_exprofs = getExProfessores();

	for(auto it = _temp_exprofs.begin();it != _temp_exprofs.end();it++){
		if(s == (*it)->getNome())
			return (*it);
	}

	throw ProfessorNaoExistente(s);
}

void Escola::addExProfessor(Professor * prof){

	auto _temp_turmas = prof->getTurmas();
	_temp_turmas.clear();

	prof->setTurmas(_temp_turmas);

	_ex_profs.insert(prof);

	if(_professores.empty())
		return;

	auto it = _professores.begin();

	for(; it != _professores.end(); it++){
		if((*it) == prof){
			_professores.erase(it);
			return;
		}
	}
}

void Escola::removerExProfessor(const string n){

	if(_ex_profs.empty())
		throw ProfessorNaoExistente(n);

	auto it = _ex_profs.begin();

	for (;it != _ex_profs.end();it++)	{
		if((*it)->getNome() == n){
			_ex_profs.erase(it);
			return;
		}
	}

	throw ProfessorNaoExistente(n);
}

void Escola::printExProfessores()const{

	if(_ex_profs.empty())
		cout << "Nao existem Ex-Professores!" << endl;

	auto it = _ex_profs.begin();

	for (;it!= _ex_profs.end(); it++)	{
		cout << (*it)->print();
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

	vector<Disciplina*>::iterator it = _disciplinas.begin();

	for (; it < _disciplinas.end(); it++) {
		if ((*it)->getNome() == n) {
			_disciplinas.erase(it);
			return;
		}
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

priority_queue<Livraria*, vector<Livraria*>, Livraria::minLivraria> Escola::getLivrarias(){
	return _livrarias;
}

void Escola::setLivrarias(priority_queue<Livraria*, vector<Livraria*>, Livraria::minLivraria> livrarias){
	this->_livrarias=livrarias;
}

Livraria * Escola::getLivrariaByDenominacao(const string n){
	auto _temp = _livrarias;

	while(!_temp.empty()){
		if(_temp.top()->getDenominacao()==n){
			return _temp.top();
		}
		_temp.pop();
	}
	throw LivrariaNaoExistente(n);
}

void Escola::fillLivrarias(vector<Livraria*> liv){
	for(unsigned int i =0; i<liv.size();i++){
		_livrarias.push(liv[i]);
	}
}

void Escola::addLivraria(Livraria * liv){
	auto _temp = _livrarias;

	while(!_temp.empty()){

		if(_temp.top() == liv){
			throw NaoEPossivelAdicionarLivraria(liv->getDenominacao());
		}
		_temp.pop();
	}

	_livrarias.push(liv);
}

bool Escola::updateLivraria(const string n){
	Livraria* liv=getLivrariaByDenominacao(n);
	auto _temp = _livrarias;

	while(!_temp.empty()){

		if(_temp.top() == liv){
			throw LivrariaNaoExistente(liv->getDenominacao());
		}
		_temp.pop();
	}

	_livrarias.push(liv);return false;
}

void Escola::removeLivraria(const string n){
	priority_queue<Livraria*> _temp;
	auto _liv_size = _livrarias.size();

	while(!_livrarias.empty()){
		if(_livrarias.top()->getDenominacao() == n){
			_livrarias.pop();
			break;
		}else{
			_temp.push(_livrarias.top());
			_livrarias.pop();
		}
	}
	if(_temp.size() == _liv_size)
		throw LivrariaNaoExistente(n);

	while(!_temp.empty()){
		_livrarias.push(_temp.top());
		_temp.pop();
	}	
}

void Escola::printLivraria(){
	//begin -- so para testar
	// 	vector<int> anos;
	// 	anos.push_back(3);
	// 	anos.push_back(2);
	// 	Livraria* liv=new Livraria("Ainda a definir","E so ver no gps",20,_disciplinas,anos);
	// 	_livrarias.push(liv);
	//end

	auto _temp = _livrarias;
	while(!_temp.empty()){
		cout<<_temp.top()->print();
		_temp.pop();
	}
}

Livraria* Escola::pesquisaEspecialidade(string especialidade){
	auto _temp = _livrarias;
	while(!_temp.empty()){
		for(int i=0; i<_temp.top()->getEspecialidade().size();i++){
			if(_temp.top()->getEspecialidade()[i]->getNome()==especialidade){
				return _temp.top();
			}
		}
		_temp.pop();
	}
}

Livraria* Escola::pesquisaAno(int ano){
	auto _temp = _livrarias;
	while(!_temp.empty()){
		for(int i=0; i<_temp.top()->getAnoEscolaridade().size();i++){
			if(_temp.top()->getAnoEscolaridade()[i]==ano){
				return _temp.top();
			}
		}
		_temp.pop();
	}
}


BST<Funcionario> Escola::getFuncionarios() const{
	return arvoreFuncionarios;
}


bool Escola::addFuncionario(string n, long contacto){
	Funcionario f1(n,contacto);
	arvoreFuncionarios.insert(f1);
}

bool Escola::updateFuncionario(Funcionario * f){
}


void Escola::removeFuncionario(const string n){
	bool found;
	BSTItrIn<Funcionario> it = arvoreFuncionarios;
	while (!it.isAtEnd()) {
		if (it.retrieve().getNome() == n) {
			found = true;
			break;
		}

		it.advance();
	}
	if (found){
		arvoreFuncionarios.remove(it.retrieve());
	}

}


bool Escola::addTurmaFunc(Turma *t, string nome){
	bool found;
	BSTItrIn<Funcionario> it = arvoreFuncionarios;
	while (!it.isAtEnd()) {
		if (it.retrieve().getNome() == nome) {
			found = true;
			break;
		}

		it.advance();
	}
	if (found){
		it.retrieve().addTurma(t);
	}
}

void Escola::printFuncionarios(){
	bool found;
	BSTItrIn<Funcionario> it = arvoreFuncionarios;
	while (!it.isAtEnd())
	{ 
		cout << it.retrieve().print();
		it.advance();
		found =true;
	}
	if(!found){
		cout << endl << "Nao existem Funcionarios adicionados!" << endl;
	}
}
Escola::Escola() {
}
