#include "UI.h"

UI::UI(){
	escola = new Escola();
}

UI::UI(Escola * escola){
	this->escola = escola;
}

void UI::init() {

	int opccao;

	do {
		cout << "########################################" << endl;
		cout << "#     Gestao de turmas numa escola     #" << endl;
		cout << "########################################" << endl << endl;
		cout << "[1] Manutencao das entidades;" << endl;
		cout << "[2] Fazer associacoes entre entidades;" << endl;
		cout << "[3] Listagens;" << endl;
		cout << "[4] Sair." << endl;

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
			return;
			break;
		default:
			cout << "A opccao escolhida nao existe! Escolha outra." << endl;
			break;
		}
	} while (opccao != 4);
}

void UI::menuManutencao() {
	int mmo;

	do {
		cout << "########################################" << endl;
		cout << "#     Gestao de turmas numa escola     #" << endl;
		cout << "########################################" << endl << endl;
		cout << "[1] Manutencao de alunos;" << endl;
		cout << "[2] Manutencao de professores e directores de turma;" << endl;
		cout << "[3] Manutencao de turmas;" << endl;
		cout << "[4] Manutencao de disciplinas;" << endl;
		cout << "[5] Voltar." << endl;

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
			return;
			break;
		default:
			cout << "A opccao escolhida nao existe! Escolha outra." << endl;
			break;
		}
	} while (mmo != 5);
}

void UI::manutencao(int i) {

	int crud;
	string entidade;

	switch(i){
	case 1:
		entidade = "Aluno";
		break;
	case 2:
		entidade = "Professor";
		break;
	case 3:
		entidade = "Turma";
		break;
	case 4:
		entidade = "Disciplina";
		break;
	}

	do {
		cout << "########################################" << endl;
		cout << "#     Gestao de turmas numa escola     #" << endl;
		cout << "########################################" << endl << endl;
		cout << "1. Adicionar " << entidade << ";" << endl;
		cout << "2. Seleccionar " << entidade << ";" << endl;
		cout << "3. Actualizar " << entidade << ";" << endl;
		cout << "4. Eliminar " << entidade << ";" << endl;
		cout << "5. Voltar" << "." << endl;

		cin >> crud;

		switch (crud) {
		case 1:
			try{
				criar(i);
			}catch(NaoEPossivelAdicionarAluno &e){
				cout << e.getError() << endl;
			}
			catch(TurmaNaoExistente & e){
				cout << e.getErro() << endl;
			}		
			catch(DisciplinaNaoExistente & e){
				cout << e.getErro() << endl;
			}
			catch(NaoEPossivelAdicionarProfessor & e){
				cout << e.getErro() << endl;
			}
			catch(NaoEPossivelAdicionarDisciplina & e){
				cout << e.getErro() << endl;
			}
			catch(NaoEPossivelAdicionarTurma & e){
				cout << e.getErro() << endl;
			}
			break;
		case 2:
			//ler(i);
			break;
		case 3:
			//actualizar(i);
			break;
		case 4:
			//eliminar(i);
			break;
		case 5:
			return;
			break;
		default:
			cout << "A opccao escolhida nao existe! Escolha outra." << endl;
			break;
		}
	} while (crud != 5);
}

void UI::menuAssociacoes() {

}

void UI::menuListagens() {

	int opccao;

	do {
		cout << "########################################" << endl;
		cout << "#     Gestao de turmas numa escola     #" << endl;
		cout << "########################################" << endl << endl;
		cout << "[1] Listar Alunos;" << endl;
		cout << "[2] Listar Professores;" << endl;
		cout << "[3] Listar Directores de Turma (apenas);" << endl;
		cout << "[4] Listar Disciplinas;" << endl;
		cout << "[5] Listar Turmas;" << endl;
		cout << "[6] Sair." << endl;

		cin >> opccao;

		switch (opccao) {
		case 1:
			escola->printAlunos();
			break;
		case 2:
			escola->printProfessores();
			break;
		case 3:
			escola->printDirectoresTurma();
			break;
		case 4:
			escola->printDisciplinas();
			break;
		case 5:
			escola->printTurmas();
			break;
		case 6:
			return;
			break;
		default:
			cout << "A opccao escolhida nao existe! Escolha outra." << endl;
			break;
		}
	} while (opccao != 4);

}

bool UI::criar(int i) {
	int idTurma = 0, numero = 0, idTurmaResponsavel = 0, anoEscolar = 0, tipoProfessor = 0, duracao = 0, horaInicio = 0;
	string nome = "", nome_disciplina = "";

	if (i == 1) {
		if(!escola->getTurmas().empty()){
			cout << "==ALUNO==" << endl;
			cout << "Nome: ";
			cin >> nome;
			cout << "Numero: ";
			cin >> numero;
			cout << "Numero da turma: ";
			cin >> idTurma;
		} else {
			throw NaoEPossivelAdicionarAluno();
		}
		Turma * _temp = NULL;

		_temp = escola->getTurmaById(idTurma);

		escola->addAluno(nome, numero, _temp);
		cout << "Aluno criado com sucesso!" << endl;
		return true;


	} else if (i == 2) {
		if(!escola->getDiscipinas().size() || !escola->getTurmas().size()){

			chooseProfessorType(tipoProfessor);

			if(tipoProfessor == 3)
				return false;

			if(tipoProfessor == 1)
				cout << "==PROFESSOR==" << endl;
			else
				cout << "==DIRECTOR DE TURMA==" << endl;

			cout << "Nome: " << endl;
			cin >> nome;
			cout << "Nome da disciplina: " << endl;
			cin >> nome_disciplina;
			cout << "ID de uma Turma de leccionacao: " << endl;
			cin >> idTurma;

			if(tipoProfessor == 2){
				cout << "ID de uma Turma responsavel(pode ser a mesma que a anterior):" << endl;
				cin >> idTurmaResponsavel;
			}

			if(tipoProfessor== 2){
				escola->addDirector(nome, nome_disciplina, idTurma, idTurmaResponsavel);
				//escola->addDirector();
				cout << "\nDirector de Turma criado com sucesso!" << endl;
				return true;
			}

			escola->addProfessor(nome, nome_disciplina, idTurma);
			cout << "Professor criado com sucesso!" << endl;

		} else {
			throw NaoEPossivelAdicionarProfessor();
		}

	} else if (i == 3) {
		cout << "==TURMA==" << endl;
		cout << "Numero da turma:" << endl;
		cin >> idTurma;
		cout << "Ano Escolar:" << endl;
		cin >> anoEscolar;

		escola->addTurma(idTurma, anoEscolar);
		cout << "Turma criada com sucesso!" << endl;

	} else if(i == 4){
		cout << "==DISCIPLINA==" << endl;
		cout << "Nome:" << endl;
		cin >> nome;
		cout << "Duracao da aula (em minutos):" << endl;
		cin >> duracao;
		cout << "Hora de inicio (entre as 8:00 e as 16:00):" << endl;
		cin >> horaInicio;

		escola->addDisciplina(nome, duracao, horaInicio);
	}
	return true;
}

void UI::chooseProfessorType( int & tipoProfessor )
{
	while(tipoProfessor < 1 && tipoProfessor > 3){
		cout << "Escolha o tipo de Professor: " << endl;
		cout << "[1] Professor" << endl;
		cout << "[2] Director de Turma" << endl;
		cout << "[3] Sair." << endl;
		cin >> tipoProfessor;
	}

}

//
//bool UI::ler(int i) {
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
//bool UI::actualizar(int i) {
//	int idturma, numero, iddisciplina, qtdturmas, anoescolar;
//	string nome = "";
//	if (i == 1) {
//		if (alunos.empty()) {
//			cout << "nao existem alunos para actualizar" << endl;
//		} else {
//			int num = 0;
//			cout << "Qual o numero do aluno que pretende actualizar?" << endl;
//			for (unsigned int j = 0; j < alunos.size(); j++) {
//				cout << "nome: " << alunos[j].getnome() << " - numero: "
//					<< alunos[j].getnumero() << " - turma: "
//					<< alunos[j].getidturma() << endl;
//			}
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
//bool UI::eliminar(int i) {
//	return false;
//}