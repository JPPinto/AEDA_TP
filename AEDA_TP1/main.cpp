#include <string.h>
#include <iostream>
#include <sstream>
#include <vector>
#include "Excepcao.h"
#include "Escola.h"
#include "Aluno.h"
#include "Professor.h"
#include "Turma.h"
#include "Disciplina.h"
#include "Horario.h"
#include "UI.h"

using namespace std;
//
//////Manutencao
//void menuManutencao(Escola * escola);
//void manutencao(int i, Escola * escola);
//
////Associacao
//void menuAssociacoes();
//
//////Listagens
//void menuListagens();
//
//////CRUD
//bool criar(int i, Escola * escola);
//bool ler(int i, Escola * escola);
////bool actualizar(int i);
////bool eliminar(int i);


int main() {

	UI ui = UI();

	ui.init();

	//int opccao;
	//Escola * escola = new Escola();

	//do {
	//	cout << "##############################" << endl;
	//	cout << "#Gestao de turmas numa escola#" << endl;
	//	cout << "##############################" << endl;
	//	cout << "1. Manutencao das entidades" << endl;
	//	cout << "2. Fazer associacoes entre entidades" << endl;
	//	cout << "3. Listagens" << endl;
	//	cout << "4. Sair" << endl;

	//	cin >> opccao;

	//	switch (opccao) {
	//	case 1:
	//		menuManutencao(escola);
	//		break;
	//	case 2:
	//		menuAssociacoes();
	//		break;
	//	case 3:
	//		menuListagens();
	//		break;
	//	case 4:
	//		break;
	//	default:
	//		cout << "A opccao escolhida nao existe. Escolha outra." << endl;
	//		break;
	//	}
	//} while (opccao != 4);

	return 0;
}

//void menuManutencao(Escola * escola) {
//	int mmo;
//
//	do {
//		cout << "##############################" << endl;
//		cout << "#Gestao de turmas numa escola#" << endl;
//		cout << "##############################" << endl;
//		cout << "1. Manutencao de alunos" << endl;
//		cout << "2. Manutencao de professores e directores de turma" << endl;
//		cout << "3. Manutencao de turmas" << endl;
//		cout << "4. Manutencao de disciplinas" << endl;
//		cout << "5. Voltar" << endl;
//
//		cin >> mmo;
//
//		switch (mmo) {
//		case 1:
//			manutencao(1, escola);
//			break;
//		case 2:
//			manutencao(2, escola);
//			break;
//		case 3:
//			manutencao(3, escola);
//			break;
//		case 4:
//			manutencao(4, escola);
//			break;
//		case 5:
//			break;
//		default:
//			cout << "A opccao escolhida nao existe. Escolha outra." << endl;
//			break;
//		}
//	} while (mmo != 5);
//}
//
//void manutencao(int i, Escola * escola) {
//	int crud;
//	string entidade;
//
//	if (i == 1) {
//		entidade = "aluno";
//	} else if (i == 2) {
//		entidade = "professor";
//	} else if (i == 3) {
//		entidade = "turma";
//	} else {
//		entidade = "disciplina";
//	}
//
//	do {
//		cout << "##############################" << endl;
//		cout << "#Gestao de turmas numa escola#" << endl;
//		cout << "##############################" << endl;
//		cout << "1. Criar " << entidade << endl;
//		cout << "2. Ler " << entidade << endl;
//		cout << "3. Actualizar " << entidade << endl;
//		cout << "4. Eliminar " << entidade << endl;
//		cout << "5. Voltar" << endl;
//
//		cin >> crud;
//		
//		switch (crud) {
//		case 1:
//			criar(i, escola);
//			break;
//		case 2:
//			ler(i, escola);
//			break;
//		case 3:
//			//actualizar(i);
//			break;
//		case 4:
//			//eliminar(i);
//			break;
//		case 5:
//			break;
//		default:
//			cout << "A opccao escolhida nao existe. Escolha outra." << endl;
//			break;
//		}
//	} while (crud != 5);
//}
//
//void menuAssociacoes() {
//
//}
//
//void menuListagens() {
//
//}
//
//bool criar(int i, Escola * escola) {
//	int idTurma, numero, idTurmaResponsavel, anoEscolar;
//	int tipoProfessor, duracao = 0, horaInicio = 0;
//	string nome = "", nome_disciplina = "";
//	vector<int> profTurmas;
//
//	if (i == 1) {
//		if(!escola->getTurmas().empty()){
//			cout << "?!ALUNO!?" << endl;
//			cout << "Nome:" << endl;
//			cin >> nome;
//			cout << "Numero:" << endl;
//			cin >> numero;
//			cout << "Numero da turma:" << endl;
//			cin >> idTurma;
//		} else {
//			cout << "Nao e possivel adicionar Alunos sem antes haver Turmas!" << endl;
//			return false;
//		}
//		Turma * _temp = NULL;
//		try{
//			_temp = escola->getTurmaById(idTurma);
//
//			if(_temp != NULL){
//				Aluno * aluno = new Aluno(nome, numero, _temp);
//				escola->setAluno(aluno);
//				cout << "Aluno criado com sucesso!" << endl;
//			} else {
//				cout << "Numero de Turma invalido!" << endl;
//			}
//		}catch(TurmaNaoExistente x){
//			cout << x.getErro() << endl;
//		}
//
//	} else if (i == 2) {
//		if(!escola->getDiscipinas().size() || !escola->getTurmas().size()){
//
//			while(tipoProfessor < 1 && tipoProfessor > 3){
//				cout << "Escolha o tipo de Professor:" << endl;
//				cout << "1. Professor" << endl;
//				cout << "2. Director de Turma" << endl;
//				cout << "3. Sair." << endl;
//				cin >> tipoProfessor;
//			}
//
//			if(tipoProfessor == 3)
//				return false;
//
//			if(tipoProfessor == 1)
//				cout << "?!PROFESSOR!?" << endl;
//			else
//				cout << "?!Director de Turma!?" << endl;
//
//			cout << "Nome:" << endl;
//			cin >> nome;
//			cout << "Nome da disciplina:" << endl;
//			cin >> nome_disciplina;
//			cout << "ID de uma Turma de leccionacao:" << endl;
//			cin >> idTurma;
//
//			if(tipoProfessor == 2){
//				cout << "ID de uma Turma responsavel(pode ser a mesma que a anterior):" << endl;
//				cin >> idTurmaResponsavel;
//			}
//
//			Disciplina * _temp = NULL;
//			Turma * _temp2 = NULL;
//
//			_temp = escola->getDisciplinaByNome(nome_disciplina);
//			_temp2 = escola->getTurmaById(idTurma);
//
//			if(tipoProfessor== 2){
//
//				Turma * _temp3 = NULL;
//				_temp3 = escola->getTurmaById(idTurmaResponsavel);
//
//				if(_temp == NULL)
//					cout << "Nome de Disciplina invalido!" << endl;
//				else	if(_temp2 == NULL)
//					cout << "Numero de Turma a leccionar invalido!!" << endl;
//				else    if(_temp3 == NULL)
//					cout << "Numero de Turma responsavel invalido!!" << endl;
//				else if(_temp != NULL && _temp2 != NULL && _temp3 != NULL){
//					DirectorTurma * _temp_director = new DirectorTurma(nome, _temp, _temp2, _temp3);
//					escola->getProfessores().push_back(_temp_director);
//					cout << "Director de Turma criado com sucesso!" << endl;
//				}
//						
//			}
//
//			if(_temp != NULL && _temp2 != NULL){
//				Professor * professor = new Professor(nome, _temp, _temp2);
//				escola->setProfessor(professor);
//				cout << "Professor criado com sucesso!" << endl;
//			} else {
//				cout << "Numero de Turma OU Disciplina invalido!" << endl;
//			}
//		} else {
//			cout << "Nao e possivel adicionar Professores sem antes adicionar Disciplinas OU Turmas!" << endl;
//		}
//	} else if (i == 3) {
//		cout << "?!TURMA!?" << endl;
//		cout << "Numero da turma:" << endl;
//		cin >> idTurma;
//		cout << "Ano Escolar:" << endl;
//		cin >> anoEscolar;
//
//		Turma * turma = new Turma(idTurma, anoEscolar);
//		escola->setTurma(turma);
//		cout << "Turma criada com sucesso!" << endl;
//	} else {
//		cout << "?!DISCIPLINA!?" << endl;
//		cout << "Nome:" << endl;
//		cin >> nome;
//		cout << "Duracao da Aula (em minutos):" << endl;
//		cin >> duracao;
//		cout << "Hora de inicio (entre as 8:00 e as 16:00):" << endl;
//		cin >> horaInicio;
//
//		Disciplina * disc = new Disciplina(nome, duracao, horaInicio);
//		escola->getDiscipinas().push_back(disc);
//	}
//	return true;
//}
//
//bool ler(int i, Escola * escola) {
//	int num;
//	string nome;
//	if (i == 1) {
//		if (escola->getAlunos().empty()) {
//			cout << "Nao existem alunos para ler" << endl;
//		} else {
//			cout << "Qual o nome do aluno que pretende ver?" << endl;
//			getline(cin, nome);
//			try{
//				cout << escola->showAluno(escola->getAlunoByNome(nome)) << endl;
//			}catch(AlunoNaoExistente a){
//				cout<<a.getErro()<<endl;
//			}
//		}
//		return true;
//	} else if (i == 2) {
//		if (escola->getProfessores().empty()) {
//			cout << "Nao existem professores para ler" << endl;
//		} else {
//			cout << "Qual o nome do professor que pretende ver?" << endl;
//			getline(cin, nome);
//			try{
//				cout << escola->showProfessor(escola->getProfessorByNome(nome)) << endl;
//			}catch(ProfessorNaoExistente p){
//				cout<<p.getErro()<<endl;
//			}
//		}
//		return true;
//	} else if (i == 3) {
//		if (escola->getTurmas().empty()) {
//			cout << "Nao existem turmas para ler" << endl;
//		} else {
//			cout <<"Qual o numero da turma que pretende ver?"<<endl;
//			cin >> num;
//			try{
//				cout << escola->showTurma(escola->getTurmaById(num)) << endl;
//			}catch(TurmaNaoExistente t){
//				cout<<t.getErro()<<endl;
//			}
//		}
//		return true;
//	} else {
//		if (escola->getDiscipinas().empty()) {
//			cout << "Nao existem disciplinas para ler" << endl;
//		} else {
//			cout <<"Qual o nome da disciplina que pretende ver?"<<endl;
//			getline(cin, nome);
//			try{
//				cout << escola->showDisciplina(escola->getDisciplinaByNome(nome)) << endl;
//			}catch(DisciplinaNaoExistente d){
//				cout<<d.getErro()<<endl;
//			}
//		}
//		return true;
//	}
//	return false;
//}
//
//bool actualizar(int i) {
//	int idturma, numero, iddisciplina, qtdturmas, anoescolar;
//	string nome = "";
//	if (i == 1) {
//		if (alunos.empty()) {
//			cout << "nao existem alunos para actualizar" << endl;
//		} else {
//			int num = 0;
//			cout << "Qual o numero do aluno que pretende actualizar?" << endl;
//			for (unsigned int j = 0; j < alunos.size(); j++) {
//							cout << "nome: " << alunos[j].getnome() << " - numero: "
//									<< alunos[j].getnumero() << " - turma: "
//									<< alunos[j].getidturma() << endl;
//						}
//			cin >> num;
//			for (unsigned int j = 0; j < alunos.size(); j++) {
//				if (alunos[j].getnumero() == num) {
//					cout << "?!ALUNO!?" << endl;
//					cout << "nome:" << endl;
//					cin >> nome;
//					cout << "numero:" << endl;
//					cin >> numero;
//					cout << "numero da turma:" << endl;
//					cin >> idturma;
//
//					alunos[j].setnome(nome);
//					alunos[j].setnumero(numero);
//					alunos[j].setidturma(idturma);
//					cout << "aluno criado com sucesso" << endl;
//				}
//			}
//		}
//	}
//	return true;
//}
//
//bool eliminar(int i) {
//	return false;
//}
