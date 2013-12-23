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
		cout << "[2] Listagens;" << endl;
		cout << "[3] Sair." << endl;

		cin >> opccao;

		switch (opccao) {
		case 1:
			menuManutencao();
			break;
		case 2:
			menuListagens();
			break;
		case 3:
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
			catch(DuracaoExcedida & e){
				cout << e.getErro() << endl;
			}
			catch(...){
				cout<<"ERRO DESCONHECIDO!"<<endl;
			}
			break;
		case 2:
			try{

				ler(i);
			}
			catch(AlunoNaoExistente a){
				cout<<a.getErro()<<endl;
			}
			catch(ProfessorNaoExistente p){
				cout<<p.getErro()<<endl;
			}
			catch(TurmaNaoExistente t){
				cout<<t.getErro()<<endl;
			}
			catch(DisciplinaNaoExistente d){
				cout<<d.getErro()<<endl;
			}
			catch(...){
				cout<<"ERRO DESCONHECIDO!"<<endl;
			}
			break;
		case 3:
			//actualizar(i);
			break;
		case 4:
			try{
				eliminar(i);
			}
			catch(DisciplinaNaoExistente d){
				cout<<d.getErro()<<endl;
			}
			catch(AlunoNaoExistente d){
				cout<<d.getErro()<<endl;
			}
			catch(ProfessorNaoExistente d){
				cout<<d.getErro()<<endl;
			}
			catch(TurmaNaoExistente d){
				cout<<d.getErro()<<endl;
			}
			catch(...){
				cout<<"ERRO DESCONHECIDO!"<<endl;
			}
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

void UI::criar(int i) {
	int idTurma = 0, numero = 0, idTurmaResponsavel = 0, anoEscolar = 0, tipoProfessor = 0, duracao = 0, horaInicio = 0, contacto = 0;
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

	} else if (i == 2) {
		if(!escola->getDiscipinas().size() || !escola->getTurmas().size()){

			tipoProfessor = chooseProfessorType();

			if(tipoProfessor == 3)
				return;

			if(tipoProfessor == 1)
				cout << "==PROFESSOR==" << endl;
			else if(tipoProfessor == 2)
				cout << "==DIRECTOR DE TURMA==" << endl;

			cout << "Nome: " << endl;
			cin >> nome;
			cout << "Nome da disciplina: " << endl;
			cin >> nome_disciplina;
			cout << "ID de uma Turma de leccionacao: " << endl;
			cin >> idTurma;
			cout << "Contacto: " << endl;
			cin >> contacto;

			if(tipoProfessor == 2){
				cout << "ID de uma Turma responsavel(pode ser a mesma que a anterior):" << endl;
				cin >> idTurmaResponsavel;

				escola->addDirector(nome, nome_disciplina, idTurma, contacto, idTurmaResponsavel);
				cout << "\nDirector de Turma criado com sucesso!" << endl;
				return;
			}

			escola->addProfessor(nome, nome_disciplina, idTurma, contacto);
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
}

int UI::chooseProfessorType()
{
	int x = 0;
	while(x < 1 || x > 3){
		cout << endl << "Escolha o tipo de Professor: " << endl;
		cout << "[1] Professor" << endl;
		cout << "[2] Director de Turma" << endl;
		cout << "[3] Sair." << endl;
		cin >> x;
	}

	return x;
}

void UI::ler(int i) {

	int num = 0;
	string nome = "";

	if (i == 1) {
		if (escola->getAlunos().empty()) {
			cout << "Nao existem alunos para ler!" << endl;
		} else {
			cout << "Qual o nome do aluno que pretende ver?" << endl;
			cin >> nome;
			cout << escola->showAluno(escola->getAlunoByNome(nome)) << endl;
		}

	} else if (i == 2) {
		if (escola->getProfessores().empty()) {
			cout << "Nao existem professores para ler" << endl;
		} else {
			cout << "Qual o nome do professor que pretende ver?" << endl;
			cin >> nome;
			cout << escola->showProfessor(escola->getProfessorByNome(nome)) << endl;
		}

	} else if (i == 3) {
		if (escola->getTurmas().empty()) {
			cout << "Nao existem turmas para ler" << endl;
		} else {
			cout <<"Qual o numero da turma que pretende ver?"<<endl;
			cin >> num;
			cout << escola->showTurma(escola->getTurmaById(num)) << endl;
		}

	} else if(i == 4){
		if (escola->getDiscipinas().empty()) {
			cout << "Nao existem disciplinas para ler" << endl;
		} else {
			cout <<"Qual o nome da disciplina que pretende ver?"<<endl;
			cin >> nome;
			cout << escola->showDisciplina(escola->getDisciplinaByNome(nome)) << endl;
		}
	}
}

void UI::actualizar(int i) {

	string nome = "";
	int num = 0;
	if (i == 1) {
		//eliminar o aluno a ser alterado
		//chamar criar()
		//se sem sucesso repor o aluno anterior 
		if (escola->getAlunos().empty()) {
			cout << "Nao existem alunos para ler!" << endl;
		} else {
			cout << "Qual o nome do aluno que pretende editar?" << endl;
			cin >> nome;

			Aluno * _temp_aluno = escola->getAlunoByNome(nome);

			cout << escola->showAluno(_temp_aluno) << endl;

			escola->removeAluno(_temp_aluno->getNome());
			cout << "Reinsira as informações do aluno: " << _temp_aluno->getNome() << " ." << endl << endl;

			criar(1);
		}

	} else if (i == 2) {
		if (escola->getProfessores().empty()) {
			cout << "Nao existem professores para editar" << endl;
		} else {
			cout << "Qual o nome do professor que pretende ver?" << endl;
			cin >> nome;
			cout << escola->showProfessor(escola->getProfessorByNome(nome)) << endl;
		}

	} else if (i == 3) {
		if (escola->getTurmas().empty()) {
			cout << "Nao existem turmas para editar" << endl;
		} else {
			cout <<"Qual o numero da turma que pretende ver?"<<endl;
			cin >> num;
			cout << escola->showTurma(escola->getTurmaById(num)) << endl;
		}

	} else if(i == 4){
		if (escola->getDiscipinas().empty()) {
			cout << "Nao existem disciplinas para editar" << endl;
		} else {
			cout <<"Qual o nome da disciplina que pretende ver?"<<endl;
			cin >> nome;
			cout << escola->showDisciplina(escola->getDisciplinaByNome(nome)) << endl;
		}
	}
}

void UI::eliminar(int i) {

	int num;
	string nome;

	if (i == 1) {
		if (escola->getAlunos().empty()) {
			cout << "Nao existem alunos para eliminar!" << endl;
		} else {
			cout << "Qual o nome do aluno que pretende eliminar?" << endl;
			cin >> nome;
			escola->removeAluno(nome);
		}

	} else if (i == 2) {
		if (escola->getProfessores().empty()) {
			cout << "Nao existem professores para eliminar" << endl;
		} else {
			cout << "Qual o nome do professor que pretende eliminar?" << endl;
			cin >> nome;
			escola->removeProfessor(nome);
		}

	} else if (i == 3) {
		if (escola->getTurmas().empty()) {
			cout << "Nao existem turmas para eliminar" << endl;
		} else {
			cout <<"Qual o numero da turma que pretende eliminar?"<<endl;
			cin >> num;
			escola->removeTurma(num);
		}

	} else if(i == 4){
		if (escola->getDiscipinas().empty()) {
			cout << "Nao existem disciplinas para eliminar" << endl;
		} else {
			cout <<"Qual o nome da disciplina que pretende eliminar?"<<endl;
			cin >> nome;
			escola->removeDisciplina(nome);
		}
	}
}