#ifndef DISCIPLINA_H_
#define DISCIPLINA_H_

#include <string>
#include <vector>

using namespace std;

///Class representa uma Disciplina contendo a sua designacao, duracao e hora de inicio.
class Disciplina {
private:
	string _nome;					///< Designacao da Disciplina
	int _duracao;					///< Duracao de uma aula da Disciplina em minutos
	int _hora_inicio;				///< Hora de inicio da aula
public:

	Disciplina(string _nome, int d, int h);
	string getNome() const;
	void setNome(string _nome);
	int getDuracao() const;
	void setDuracao(int d);
	int getHoraInicio() const;
	void setHoraInicio(int h);
	int getHoraFim() const;
	string print();

	bool operator==(Disciplina * d2);///< Verificasse quando o nome entre os dois objetos e igual 

	virtual ~Disciplina(){}
};
#endif /* DISCIPLINA_H_ */
