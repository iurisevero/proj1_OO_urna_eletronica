#ifndef PRESIDENTE_HPP
#define PRESIDENTE_HPP

#include "candidato.hpp"
#include <bits/stdc++.h>
using namespace std;

class Presidente: public Candidato{
private:
	string nome_do_vice;
	string apelido_do_vice;
	int numero_do_partido_do_vice;
	string sigla_do_partido_do_vice;
	string nome_do_partido_do_vice;
public:
	Presidente();
	Presidente(int codigo_do_cargo, int numero_do_candidato, int numero_do_partido);
	Presidente(string nome_ue, int codigo_do_cargo, string descricao_do_cargo, int numero_do_candidato, string nome_do_candidato, string apelido_do_candidato,
	int numero_do_partido, string sigla_do_partido, string nome_do_partido);

	~Presidente();

	//Métodos de Inserção
	void set_nome_do_vice(string nome_do_vice);
	void set_apelido_do_vice(string apelido_do_vice);
	void set_numero_do_partido_do_vice(int numero_do_partido_do_vice);
	void set_sigla_do_partido_do_vice(string sigla_do_partido_do_vice);
	void set_nome_do_partido_do_vice(string nome_do_partido_do_vice);

	//Métodos de Visualização
	string get_nome_do_vice();
	string get_apelido_do_vice();
	int get_numero_do_partido_do_vice();
	string get_sigla_do_partido_do_vice();
	string get_nome_do_partido_do_vice();

	void imprime_dados();
};


#endif