#include <string.h>
#include <iostream>
#include <sstream>
#include <vector>
#include "Aluno.h"
#include "Professor.h"
#include "Turma.h"
#include "Disciplina.h"
#include "Horario.h"

using namespace std;

//Manutencao
void menuManutencao();
void manutencao(int i);

//Associacao
void menuAssociacoes();

//Listagens
void menuListagens();

//CRUD
bool criar(int i);
bool ler(int i);
bool actualizar(int i);
bool eliminar(int i);

//Informacao
vector<Aluno> alunos;
vector<Professor> professores;
vector<Turma> turmas;
vector<Disciplina> disciplinas;
vector<Horario> horarios;

int main() {

	int opccao;

	do {
		cout << "##############################" << endl;
		cout << "#Gestao de turmas numa escola#" << endl;
		cout << "##############################" << endl;
		cout << "1. Manutencao das entidades" << endl;
		cout << "2. Fazer associacoes entre entidades" << endl;
		cout << "3. Listagens" << endl;
		cout << "4. Sair" << endl;

		cin >> opccao;

		switch (opccao) {
		case 1:
			menuManutencao();
			break;
		case 2:
			menuAssociacoes();
			break;
		case 3:
			menuListagens();
			break;
		case 4:
			break;
		default:
			cout << "A opccao escolhida nao existe. Escolha outra." << endl;
			break;
		}
	} while (opccao != 4);

	return 0;
}

void menuManutencao() {
	int mmo;

	do {
		cout << "##############################" << endl;
		cout << "#Gestao de turmas numa escola#" << endl;
		cout << "##############################" << endl;
		cout << "1. Manutencao de alunos" << endl;
		cout << "2. Manutencao de professores e directores de turma" << endl;
		cout << "3. Manutencao de turmas" << endl;
		cout << "4. Manutencao de disciplinas" << endl;
		cout << "5. Voltar" << endl;

		cin >> mmo;

		switch (mmo) {
		case 1:
			manutencao(1);
			break;
		case 2:
			manutencao(2);
			break;
		case 3:
			manutencao(3);
			break;
		case 4:
			manutencao(4);
			break;
		case 5:
			break;
		default:
			cout << "A opccao escolhida nao existe. Escolha outra." << endl;
			break;
		}
	} while (mmo != 5);
}

void manutencao(int i) {
	int crud;
	string entidade;

	if (i == 1) {
		entidade = "aluno";
	} else if (i == 2) {
		entidade = "professor";
	} else if (i == 3) {
		entidade = "turma";
	} else {
		entidade = "disciplina";
	}

	do {
		cout << "##############################" << endl;
		cout << "#Gestao de turmas numa escola#" << endl;
		cout << "##############################" << endl;
		cout << "1. Criar " << entidade << endl;
		cout << "2. Ler " << entidade << endl;
		cout << "3. Actualizar " << entidade << endl;
		cout << "4. Eliminar " << entidade << endl;
		cout << "5. Voltar" << endl;

		cin >> crud;

		switch (crud) {
		case 1:
			criar(i);
			break;
		case 2:
			ler(i);
			break;
		case 3:
			actualizar(i);
			break;
		case 4:
			eliminar(i);
			break;
		case 5:
			break;
		default:
			cout << "A opccao escolhida nao existe. Escolha outra." << endl;
			break;
		}
	} while (crud != 5);
}

void menuAssociacoes() {

}

void menuListagens() {

}

bool criar(int i) {
	int idTurma, numero, idDisciplina, qtdTurmas, anoEscolar;
	string nome = "";
	vector<int> profTurmas;

	if (i == 1) {
		cout << "?!ALUNO!?" << endl;
		cout << "Nome:" << endl;
		cin >> nome;
		cout << "Numero:" << endl;
		cin >> numero;
		cout << "Numero da turma:" << endl;
		cin >> idTurma;

		Aluno aluno(idTurma, nome, numero);
		alunos.push_back(aluno);
		cout << "Aluno criado com sucesso" << endl;
	} else if (i == 2) {
		cout << "?!PROFESSOR!?" << endl;
		cout << "Nome:" << endl;
		cin >> nome;
		cout << "Identificacao da disciplina:" << endl;
		cin >> idDisciplina;
		cout << "Numero de turmas em que da aulas:" << endl;
		cin >> qtdTurmas;
		for (int i = 0; i < qtdTurmas; i++) {
			cout << "Numero da " << (i + 1) << "º turma:" << endl;
			cin >> idTurma;
			profTurmas.push_back(idTurma);
		}
		//director de turma
		//e necessario mudar o true
		Professor professor(nome, idDisciplina, profTurmas, true);
		professores.push_back(professor);
	} else if (i == 3) {
		cout << "?!TURMA!?" << endl;
		cout << "Numero da turma:" << endl;
		cin >> idTurma;
		cout << "Ano Escolar:" << endl;
		cin >> anoEscolar;

		Turma turma(idTurma, anoEscolar);
		turmas.push_back(turma);
	} else {
		cout << "?!DISCIPLINA!?" << endl;
		cout << "Nome:" << endl;
		cin >> nome;
		cout << "Numero:" << endl;
		cin >> idDisciplina;

		Disciplina disc(nome, idDisciplina);
		disciplinas.push_back(disc);
	}		//tambem devera ter horario
	return true;
}

bool ler(int i) {
	if (i == 1) {
		if (alunos.empty()) {
			cout << "Nao existem alunos para ler" << endl;
		} else {
			for (unsigned int i = 0; i < alunos.size(); i++) {
				cout << "Nome: " << alunos[i].getNome() << " - Numero: "
						<< alunos[i].getNumero() << " - Turma: "
						<< alunos[i].getIDturma() << endl;
			}
		}
		return true;
	} else if (i == 2) {
		if (professores.empty()) {
			cout << "Nao existem professores para ler" << endl;
		} else {
			//listar os professores e as respectivas turmas
		}
		return true;
	} else if (i == 3) {
		if (turmas.empty()) {
			cout << "Nao existem turmas para ler" << endl;
		}
		return true;
	} else {
		if (disciplinas.empty()) {
			cout << "Nao existem disciplinas para ler" << endl;
		}
		return true;
	}
	return false;
}

bool actualizar(int i) {
	int idTurma, numero, idDisciplina, qtdTurmas, anoEscolar;
	string nome = "";
	if (i == 1) {
		if (alunos.empty()) {
			cout << "Nao existem alunos para actualizar" << endl;
		} else {
			int num = 0;
			cout << "Qual o numero do aluno que pretende actualizar?" << endl;
			for (unsigned int j = 0; j < alunos.size(); j++) {
							cout << "Nome: " << alunos[j].getNome() << " - Numero: "
									<< alunos[j].getNumero() << " - Turma: "
									<< alunos[j].getIDturma() << endl;
						}
			cin >> num;
			for (unsigned int j = 0; j < alunos.size(); j++) {
				if (alunos[j].getNumero() == num) {
					cout << "?!ALUNO!?" << endl;
					cout << "Nome:" << endl;
					cin >> nome;
					cout << "Numero:" << endl;
					cin >> numero;
					cout << "Numero da turma:" << endl;
					cin >> idTurma;

					alunos[j].setNome(nome);
					alunos[j].setNumero(numero);
					alunos[j].setIDturma(idTurma);
					cout << "Aluno criado com sucesso" << endl;
				}
			}
		}
	}
	return true;
}

bool eliminar(int i) {
	return false;
}
