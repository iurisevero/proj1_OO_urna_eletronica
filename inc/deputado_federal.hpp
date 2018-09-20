#ifndef DEPUTADO_FEDERAL_HPP
#define DEPUTADO_FEDERAL_HPP

#include "candidato.hpp"
#include <bits/stdc++.h>
using namespace std;

class Deputado_Federal: public Candidato{
private:
	string nome_do_suplente_1;
	string apelido_do_suplente_1;
	string nome_do_suplente_2;
	string apelido_do_suplente_2;

public:
	Deputado_Federal();
	Deputado_Federal(int codigo_do_cargo, int numero_do_candidato, int numero_do_partido);
	Deputado_Federal(string nome_ue, int codigo_do_cargo, string descricao_do_cargo, int numero_do_candidato, string nome_do_candidato, string apelido_do_candidato,
	int numero_do_partido, string sigla_do_partido, string nome_do_partido);

	~Deputado_Federal();

	void imprime_dados();
};


#endif