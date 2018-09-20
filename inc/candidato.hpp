#ifndef CANDIDATO_HPP
#define CANDIDATO_HPP

#include <bits/stdc++.h>
using namespace std;

class Candidato{
private:
	string nome_ue;
	int codigo_do_cargo;
	string descricao_do_cargo;
	int numero_do_candidato;
	string nome_do_candidato;
	string apelido_do_candidato;
	int numero_do_partido;
	string sigla_do_partido;
	string nome_do_partido;

public:
	Candidato();
	Candidato(int codigo_do_cargo, int numero_do_candidato, int numero_do_partido);
	Candidato(string nome_ue, int codigo_do_cargo, string descricao_do_cargo, int numero_do_candidato, string nome_do_candidato, string apelido_do_candidato,
	int numero_do_partido, string sigla_do_partido, string nome_do_partido);

	~Candidato();

	//Métodos de inserção
	void set_nome_ue(string nome_ue);
	void set_codigo_do_cargo(int codigo_do_cargo);
	void set_descricao_do_cargo(string descricao_do_cargo);
	void set_numero_do_candidato(int numero_do_candidato);
	void set_nome_do_candidato(string nome_do_candidato);
	void set_apelido_do_candidato(string apelido_do_candidato);
	void set_numero_do_partido(int numero_do_partido);
	void set_sigla_do_partido(string sigla_do_partido);
	void set_nome_do_partido(string nome_do_partido);

	//Métodos de visualização
	string get_nome_ue();
	int get_codigo_do_cargo();
	int get_numero_do_candidato();
	string get_apelido_do_candidato();
	int get_numero_do_partido();
	string get_sigla_do_partido();
	string get_nome_do_partido();

	//Método de Ordenação
	bool operator<(Candidato &p);

	//Método de Impressão
	virtual void imprime_dados();
};

#endif