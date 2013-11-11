#include "Escola.h"

//Aluno
vector<Aluno *> Escola::getAlunos() {
	return _alunos;
}

Aluno * Escola::getAlunoByNome(const string n) const {
	vector<Aluno*>::iterator it = alunos.begin();
	for (; it < alunos.end(); it++) {
		if ((*it)->getNome() == n) {
			return (*it);
		}
	}
	Aluno a(n, 1, 1);
	throw new AlunoNaoExistente(a);
}

bool Escola::addAlunos(Aluno * a) {
	string nome;
	int numero, turma;
	cout << "?!ALUNO!?" << endl;
	cout << "Nome: ";
	getline(cin, nome);
	cout << "Numero: ";
	cin >> numero;
	cout << "Turma: ";
	cin >> turma;

	Aluno a2(nome, numero, turma);
	alunos.push_back(a2);
	return true;
}

void Escola::showAluno(Aluno * a) {
	vector<Aluno*>::iterator it = alunos.begin();
	for (; it < alunos.end(); it++) {
		if ((*it) == a) {
			cout << "Nome: " << a->getNome() << " - Numero: " << a->getNumero()
					<< " - Turma: " << a->getNumero();
		}
	}
	throw new AlunoNaoExistente(a);
}

bool Escola::updateAluno(Aluno * a) {
	bool b = false;
	vector<Aluno*>::iterator it = alunos.begin();
	for (; it < alunos.end(); it++) {
		if ((*it) == a) {
			b = true;
		}
	}
}

bool Escola::removeAluno(Aluno * a) {

}

//Professor
vector<Professor *> getProfessores(); ///< Devolve todos os professores existentes na Escola
Professor * getProfessorByNome(const string n) const; ///< Devolve o Professor com o nome igual a n

bool addProfessor(Professor * p);			///< Adiciona um Professor a Escola
bool showProfessor();							///< Mostra o Professor no ecra
bool updateProfessor(Professor * p);	///< Altera a informacao do Professor
bool removeProfessor(const string n);		///< Remove um Professor da Escola

//Turma
vector<Turma *> getTurmas() const;///< Devolve todas as turmas existentes na Escola
Turma * getTurmaById(const int id);		///< Devolve a Turma com o id igual a id

bool addTurma(Turma * t);						///< Adiciona uma Turma a Escola
bool showTurma();									///< Mostra a Turma no ecra
bool updateTurma(Turma * t);				///< Altera a informacao da Turma
bool removeTurma(const int id);					///< Remove uma Turma da Escola

//Disciplina
vector<Disciplina *> getDiscipinas() const;	///< Devolve todas as Disciplinas que sao leccionadas na Escola
Disciplina * getDisciplinaByNome(const string n) const;	///< Devolve a Disciplina com o nome igual a n

bool addDisciplina(Disciplina * d);		///< Adiciona uma Disciplina a Escola
bool showDisciplina();							///< Mostra a Disciplina no ecra
bool updateDisciplina(Disciplina * d);	///< Altera a informacao da Disciplina
bool removeDisciplina(const string n);

Escola::Escola() {
}
