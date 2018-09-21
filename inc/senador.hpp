#ifndef SENADOR_HPP
#define SENADOR_HPP

#include "candidato.hpp"
#include <bits/stdc++.h>
using namespace std;

class Senador: public Candidato{
private:
	string nome_do_suplente_1;
	string apelido_do_suplente_1;
	string nome_do_suplente_2;
	string apelido_do_suplente_2;

public:
	Senador();
	Senador(int codigo_do_cargo, int numero_do_candidato, int numero_do_partido);
	Senador(string nome_ue, int codigo_do_cargo, string descricao_do_cargo, int numero_do_candidato, string nome_do_candidato, string apelido_do_candidato,
	int numero_do_partido, string sigla_do_partido, string nome_do_partido);

	~Senador();

	//Métodos de Inserção
	void set_nome_do_suplente_1(string nome_do_suplente_1);
	void set_apelido_do_suplente_1(string apelido_do_suplente_1);
	void set_nome_do_suplente_2(string nome_do_suplente_2);
	void set_apelido_do_suplente_2(string apelido_do_suplente_2);

	//Métodos de Visualização
	string get_nome_do_suplente_1();
	string get_apelido_do_suplente_1();
	string get_nome_do_suplente_2();
	string get_apelido_do_suplente_2();

	void imprime_dados();
};


#endif