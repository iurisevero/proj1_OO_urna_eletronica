#ifndef GOVERNADOR_HPP
#define GOVERNADOR_HPP

#include "candidato.hpp"
#include <bits/stdc++.h>
using namespace std;

class Governador: public Candidato{
private:
	string nome_do_vice;
	string apelido_do_vice;
	int numero_do_partido_do_vice;
	string sigla_do_partido_do_vice;
	string nome_do_partido_do_vice;
public:
	Governador();
	Governador(int codigo_do_cargo, int numero_do_candidato, int numero_do_partido);
	Governador(string nome_ue, int codigo_do_cargo, string descricao_do_cargo, int numero_do_candidato, string nome_do_candidato, string apelido_do_candidato,
	int numero_do_partido, string sigla_do_partido, string nome_do_partido);

	~Governador();

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