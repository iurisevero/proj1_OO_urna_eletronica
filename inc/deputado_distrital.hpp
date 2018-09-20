#ifndef DEPUTADO_DISTRITAL_HPP
#define DEPUTADO_DISTRITAL_HPP

#include "candidato.hpp"
#include <bits/stdc++.h>
using namespace std;

class Deputado_Distrital: public Candidato{
private:
	string nome_do_suplente_1;
	string apelido_do_suplente_1;
	string nome_do_suplente_2;
	string apelido_do_suplente_2;

public:
	Deputado_Distrital();
	Deputado_Distrital(int codigo_do_cargo, int numero_do_candidato, int numero_do_partido);
	Deputado_Distrital(string nome_ue, int codigo_do_cargo, string descricao_do_cargo, int numero_do_candidato, string nome_do_candidato, string apelido_do_candidato,
	int numero_do_partido, string sigla_do_partido, string nome_do_partido);

	~Deputado_Distrital();

	void imprime_dados();
};


#endif