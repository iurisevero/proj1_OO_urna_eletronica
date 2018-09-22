#include <bits/stdc++.h>
#include "presidente.hpp"

using namespace std;

Presidente :: Presidente(){
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

Presidente :: Presidente(int codigo_do_cargo, int numero_do_candidato, int numero_do_partido){
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
Presidente :: Presidente(string nome_ue, int codigo_do_cargo, string descricao_do_cargo, int numero_do_candidato, string nome_do_candidato, string apelido_do_candidato,
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

Presidente :: ~Presidente(){}

//Métodos de Inserção
void Presidente :: set_nome_do_vice(string nome_do_vice){
	this->nome_do_vice = nome_do_vice;
}
void Presidente :: set_apelido_do_vice(string apelido_do_vice){
	this->apelido_do_vice = apelido_do_vice;
}
void Presidente :: set_numero_do_partido_do_vice(int numero_do_partido_do_vice){
	this->numero_do_partido_do_vice = numero_do_partido_do_vice;
}
void Presidente :: set_sigla_do_partido_do_vice(string sigla_do_partido_do_vice){
	this->sigla_do_partido_do_vice = sigla_do_partido_do_vice;
}
void Presidente :: set_nome_do_partido_do_vice(string nome_do_partido_do_vice){
	this->nome_do_partido_do_vice = nome_do_partido_do_vice;
}

//Métodos de Visualização
string Presidente :: get_nome_do_vice(){
	return nome_do_vice;
}
string Presidente :: get_apelido_do_vice(){
	return apelido_do_vice;
}
int Presidente :: get_numero_do_partido_do_vice(){
	return numero_do_partido_do_vice;
}
string Presidente :: get_sigla_do_partido_do_vice(){
	return sigla_do_partido_do_vice;
}
string Presidente :: get_nome_do_partido_do_vice(){
	return nome_do_partido_do_vice;
}

void Presidente :: imprime_dados(){
	cout << "Presidente: " << get_apelido_do_candidato() << " - " << get_nome_ue() << endl;
	cout << "Numero do Presidente: " << get_numero_do_candidato() << endl;
	cout << "Partido do Presidente: " << get_sigla_do_partido() << " " << get_numero_do_partido() << endl;
	cout << get_nome_do_partido() << endl;
	cout << "Vice-presidente: " << get_apelido_do_vice() << endl;
	cout << "Partido do Vice-presidente: " << get_sigla_do_partido_do_vice() << " " << get_numero_do_partido_do_vice() << endl;
	cout << get_nome_do_partido_do_vice() << endl; 
	cout << endl;
}