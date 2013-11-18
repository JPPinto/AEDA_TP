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

using namespace std;

class UI{

private:
	Escola * escola;

public:
	UI();
	UI(Escola * escola);

	void init();
	
	////Manutencao
	void menuManutencao();
	void manutencao(int i);

	//Associacao
	void menuAssociacoes();

	////Listagens
	void menuListagens();

	////CRUD
	bool criar(int i);
	bool ler(int i);
	bool actualizar(int i);
	bool eliminar(int i);
	void chooseProfessorType( int & tipoProfessor );
};