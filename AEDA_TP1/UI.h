#include <string.h>
#include <iostream>
#include <sstream>
#include <vector>
#include "Excepcao.h"
#include "Escola.h"

using namespace std;

class UI{

private:
	Escola * escola;

public:
	UI();
	UI(Escola * escola);

	void init();
	
	///Manutencao
	void menuManutencao();
	void manutencao(int i);
	void retirarProfessor();

	///Listagens
	void menuListagens();

	///CRUD
	void criar(int i);
	void seleccionar(int i);
	void eliminar(int i);
	int chooseProfessorType();
};