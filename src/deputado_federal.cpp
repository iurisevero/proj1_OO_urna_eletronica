#include <bits/stdc++.h>
#include "deputado_federal.hpp"

using namespace std;

Deputado_Federal :: Deputado_Federal(){
	set_nome_ue("");
	set_codigo_do_cargo(0);
	set_descricao_do_cargo("");
	set_numero_do_candidato(0);
	set_nome_do_candidato("");
	set_apelido_do_candidato("");
	set_numero_do_partido(0);
	set_sigla_do_partido("");
	set_nome_do_partido("");
}

Deputado_Federal :: Deputado_Federal(int codigo_do_cargo, int numero_do_candidato, int numero_do_partido){
	set_nome_ue("");
	set_codigo_do_cargo(codigo_do_cargo);
	set_numero_do_candidato(numero_do_candidato);
	set_numero_do_partido(numero_do_partido);
	set_descricao_do_cargo("");
	set_nome_do_candidato("");
	set_apelido_do_candidato("");
	set_sigla_do_partido("");
	set_nome_do_partido("");
}
Deputado_Federal :: Deputado_Federal(string nome_ue, int codigo_do_cargo, string descricao_do_cargo, int numero_do_candidato, string nome_do_candidato, string apelido_do_candidato,
				int numero_do_partido, string sigla_do_partido, string nome_do_partido){
	set_nome_ue(nome_ue);
	set_codigo_do_cargo(codigo_do_cargo);
	set_descricao_do_cargo(descricao_do_cargo);
	set_numero_do_candidato(numero_do_candidato);
	set_nome_do_candidato(nome_do_candidato);
	set_apelido_do_candidato(apelido_do_candidato);
	set_numero_do_partido(numero_do_partido);
	set_sigla_do_partido(sigla_do_partido);
	set_nome_do_partido(nome_do_partido);
}

Deputado_Federal :: ~Deputado_Federal(){}

void Deputado_Federal :: imprime_dados(){
	cout << "Deputado Federal: " << get_apelido_do_candidato() << " - " << get_nome_ue() << endl;
	cout << "Numero do Deputado Federal: " << get_numero_do_candidato() << endl;
	cout << "Partido do Deputado Federal: " << get_sigla_do_partido() << " " << get_numero_do_partido() << endl;
	cout << get_nome_do_partido() << endl;
	cout << endl;
}