#include "UI.h"
#include <algorithm>

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
	} while (opccao != 3);
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
		cout << "[5] Manutencao de ex-professores;" << endl;
		cout << "[6] Manutencao de livrarias;" << endl;
		cout << "[7] Voltar." << endl;

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
			manutencao(5);
			break;
		case 6:
			manutencao(6);
			break;
		case 7:
			return;
			break;
		default:
			cout << "A opccao escolhida nao existe! Escolha outra." << endl;
			break;
		}
	} while (mmo != 6);
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
	case 5:
		entidade = "Ex-Professor";
		break;
	case 6:
		entidade = "Livraria";
		break;
	}

	do {
		cout << "########################################" << endl;
		cout << "#     Gestao de turmas numa escola     #" << endl;
		cout << "########################################" << endl << endl;
		cout << "[1] Adicionar " << entidade << ";" << endl;
		cout << "[2] Seleccionar/Alterar " << entidade << ";" << endl;
		cout << "[3] Eliminar " << entidade << ";" << endl;
		cout << "[4] Voltar" << "." << endl;

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
				seleccionar(i);
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
		case 4:
			return;
			break;
		default:
			cout << "A opccao escolhida nao existe! Escolha outra." << endl;
			break;
		}
	} while (crud != 4);
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
		cout << "[4] Listar Ex-Professores;" << endl;
		cout << "[5] Listar Disciplinas;" << endl;
		cout << "[6] Listar Turmas;" << endl;
		cout << "[7] Listar Livrarias;" << endl;
		cout << "[8] Voltar." << endl;

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
		case 5:
			escola->printDisciplinas();
			break;
		case 4:
			escola->printExProfessores();
			break;
		case 6:
			escola->printTurmas();
			break;
		case 7:
			escola->printLivraria();
			break;
		case 8:
			return;
			break;
		default:
			cout << "A opccao escolhida nao existe! Escolha outra." << endl;
			break;
		}
	} while (opccao != 7);

}

void UI::criar(int i) {
	int idTurma = 0, numero = 0, idTurmaResponsavel = 0, anoEscolar = 0, tipoProfessor = 0, duracao = 0, horaInicio = 0, contacto = 0;
	string nome = "", nome_disciplina = "";

	string denominacao, localizacao, disciplina;
	int distancia, ano;
	vector<Disciplina*> dis;
	vector<int> anos;

	if (i == 1) {
		if(!escola->getTurmas().empty()){
			cout << "==ALUNO==" << endl;
			cout << "Nome: ";
			cin >> nome;
			replace(nome.begin(),nome.end(), '.', ' ');
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
		if(!escola->emptyDisciplinas() || !escola->emptyTurmas()){

			tipoProfessor = chooseProfessorType();

			if(tipoProfessor == 3)
				return;

			if(tipoProfessor == 1)
				cout << "==PROFESSOR==" << endl;
			else if(tipoProfessor == 2)
				cout << "==DIRECTOR DE TURMA==" << endl;

			cout << "Nome: " << endl;
			cin >> nome;
			replace(nome.begin(),nome.end(), '.', ' ');
			cout << "Nome da disciplina: " << endl;
			cin >> nome_disciplina;
			replace(nome_disciplina.begin(),nome_disciplina.end(), '.', ' ');
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
		replace(nome.begin(),nome.end(), '.', ' ');
		cout << "Duracao da aula (em minutos):" << endl;
		cin >> duracao;
		cout << "Hora de inicio (entre as 8:00 e as 16:00):" << endl;
		cin >> horaInicio;

		escola->addDisciplina(nome, duracao, horaInicio);
	} else if(i == 5){
		try{
			retirarProfessor();
		}
		catch(NaoEPossivelAdicionarProfessor & e){
			cout << e.getErro() << endl;
		}
		catch(ProfessorNaoExistente & e){
			cout << e.getErro() << endl;
		}
		catch(...){
			cout<<"ERRO DESCONHECIDO!"<<endl;
		}
	}else if(i == 6){
		cout << "==LIVRARIA==" << endl;
		cout << "Denominacao:" << endl;
		cin >> denominacao;
		cout << "Localizacao:" << endl;
		cin >> localizacao;
		cout << "Distancia:" << endl;
		cin >> distancia;

		int aNum=0, escNum=0;

		cout << "Quantos areas de especialidade pretende introduzir?"<<endl;
		cin >> aNum;
		cout << "Quais as areas de especialidade?" <<endl;
		for(unsigned int i=0; i<aNum;i++){
			cin>>disciplina;
			dis.push_back(escola->getDisciplinaByNome(disciplina));
		}

		cout << "Quantos anos de escolaridade pretende introduzir?"<<endl;
		cin >> escNum;
		cout << "Quais os anos de escolaridade?" <<endl;
		for(unsigned int i=0; i<escNum;i++){
			cin>>ano;
			anos.push_back(ano);
		}

		escola->addLivraria(denominacao, localizacao, distancia, dis,anos);
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

void UI::seleccionar(int i) {

	int num = 0, opcao = 0, contacto = 0;
	string nome = "";

	if (i == 1) {
		if (escola->getAlunos().empty()) {
			cout << "Nao existem alunos para ler!" << endl;
		} else {
			cout << "Qual o nome do aluno que pretende ver?" << endl;
			cin >> nome;
			replace(nome.begin(),nome.end(), '.', ' ');
			cout << escola->showAluno(escola->getAlunoByNome(nome)) << endl;
		}

	} else if (i == 2) {
		if (escola->getProfessores().empty()) {
			cout << "Nao existem professores para ler" << endl;
		} else {
			cout << "Qual o nome do professor que pretende ver?" << endl;
			cin >> nome;
			replace(nome.begin(),nome.end(), '.', ' ');
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
			replace(nome.begin(),nome.end(), '.', ' ');
			cout << escola->showDisciplina(escola->getDisciplinaByNome(nome)) << endl;
		}

	} else if(i == 5){
		if (escola->getExProfessores().empty()) {
			cout << "Nao existem Ex-Professores para selecionar." << endl;
		} else {

			cout <<"Qual o nome do Ex-Professor que pretende ver/alterar?"<<endl;
			cin >> nome;
			replace(nome.begin(),nome.end(), '.', ' ');

			Professor * _temp_exprof = escola->getExProfessorByNome(nome);

			cout << _temp_exprof->print() << endl;

			do 
			{
				cout << "########################################" << endl;
				cout << "#     Gestao de turmas numa escola     #" << endl;
				cout << "########################################" << endl << endl;
				cout << "[1] Alterar nome;" << endl;
				cout << "[2] Alterar contacto;" << endl;
				cout << "[3] Voltar." << endl;

				cin >> opcao;

				switch (opcao)
				{
				case 1:
					cout << "Novo nome do Ex_professor " << _temp_exprof->getNome() << ":" << endl;
					cin >> nome;
					replace(nome.begin(),nome.end(), '.', ' ');
					_temp_exprof->setNome(nome);
					break;
				case 2:
					cout << "Novo contacto do Ex_professor " << _temp_exprof->getNome() << ":" << endl;
					cin >> contacto;
					_temp_exprof->setContacto(contacto);
					break;
				case 3:
					return;
					break;
				default:
					break;
				}
			} while (opcao != 3);
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
			replace(nome.begin(),nome.end(), '.', ' ');
			escola->removeAluno(nome);
		}

	} else if (i == 2) {
		if (escola->getProfessores().empty()) {
			cout << "Nao existem professores para eliminar" << endl;
		} else {
			cout << "Qual o nome do professor que pretende eliminar?" << endl;
			cin >> nome;
			replace(nome.begin(),nome.end(), '.', ' ');
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
			replace(nome.begin(),nome.end(), '.', ' ');
			escola->removeDisciplina(nome);
		}
	}else if(i == 5){
		if (escola->getExProfessores().empty()) {
			cout << "Nao existem Ex-Professores para selecionar." << endl;
		} else {

			cout <<"Qual o nome do Ex-Professor que pretende ver/alterar?"<<endl;
			cin >> nome;
			replace(nome.begin(),nome.end(), '.', ' ');

			Professor * _temp_exprof = escola->getExProfessorByNome(nome);

			cout <<_temp_exprof->print() << endl << endl;

			do 
			{
				cout << "Tem a certeza que pretende ELIMINAR este Ex-Professor:" << endl;
				cout << "[1] Sim;" << endl;
				cout << "[2] Nao, cancelar pedido." << endl;

				cin >> num;
			} while (num != 1 && num != 2);

			if(num == 1){
				escola->removerExProfessor(_temp_exprof->getNome());
				cout << "O Ex-Professor " << _temp_exprof->getNome() << " foi eliminado com sucesso!" << endl << endl;
				return;
			}
			if(num == 2)
				cout << "Pedido cancelado..." << endl << endl;
				return;
		}
	}
}

void UI::retirarProfessor(){

	string nome = "";

	if (escola->getProfessores().empty()) {
		cout << "Nao existem professores para ler" << endl;
	} else {
		cout << "Qual o nome do professor que pretende retirar?" << endl;
		cin >> nome;
		replace(nome.begin(),nome.end(), '.', ' ');
		escola->addExProfessor(escola->getProfessorByNome(nome));
		cout << "Professor " << nome << " retirado com sucesso!" << endl;
	}
}