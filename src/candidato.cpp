#include "candidato.hpp"
#include <bits/stdc++.h>

using namespace std;

Candidato :: Candidato(){
	nome_ue = "";
	codigo_do_cargo = 0;
	descricao_do_cargo = "";
	numero_do_candidato = 0;
	nome_do_candidato = "";
	apelido_do_candidato = "";
	numero_do_partido = 0;
	sigla_do_partido = "";
	nome_do_partido = "";
}

Candidato :: Candidato(int codigo_do_cargo, int numero_do_candidato, int numero_do_partido){
	nome_ue = "";
	set_codigo_do_cargo(codigo_do_cargo);
	descricao_do_cargo = "";
	set_numero_do_candidato(numero_do_candidato);
	nome_do_candidato = "";
	apelido_do_candidato = "";
	set_numero_do_partido(numero_do_partido);
	sigla_do_partido = "";
	nome_do_partido = "";
}
Candidato :: Candidato(string nome_ue, int codigo_do_cargo, string descricao_do_cargo, int numero_do_candidato, string nome_do_candidato, string apelido_do_candidato,
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


Candidato :: ~Candidato(){}

//Métodos de inserção
void Candidato :: set_nome_ue(string nome_ue){
	this->nome_ue = nome_ue;
}
void Candidato :: set_codigo_do_cargo(int codigo_do_cargo){
	this->codigo_do_cargo = codigo_do_cargo;
}
void Candidato :: set_descricao_do_cargo(string descricao_do_cargo){
	this->descricao_do_cargo = descricao_do_cargo;
}
void Candidato :: set_numero_do_candidato(int numero_do_candidato){
	this->numero_do_candidato = numero_do_candidato;
}
void Candidato :: set_nome_do_candidato(string nome_do_candidato){
	this->nome_do_candidato = nome_do_candidato;
}
void Candidato :: set_apelido_do_candidato(string apelido_do_candidato){
	this->apelido_do_candidato = apelido_do_candidato;
}
void Candidato :: set_numero_do_partido(int numero_do_partido){
	this->numero_do_partido = numero_do_partido;
}
void Candidato :: set_sigla_do_partido(string sigla_do_partido){
	this->sigla_do_partido = sigla_do_partido;
}
void Candidato :: set_nome_do_partido(string nome_do_partido){
	this->nome_do_partido = nome_do_partido;
}

//Métodos de visualização
string Candidato :: get_nome_ue(){
	return nome_ue;
}
int Candidato :: get_codigo_do_cargo(){
	return codigo_do_cargo;
}
int Candidato :: get_numero_do_candidato(){
	return numero_do_candidato;
}
string Candidato :: get_nome_do_candidato(){
	return nome_do_candidato;
}
string Candidato :: get_apelido_do_candidato(){
	return apelido_do_candidato;
}
int Candidato :: get_numero_do_partido(){
	return numero_do_partido;
}
string Candidato :: get_sigla_do_partido(){
	return sigla_do_partido;
}
string Candidato :: get_nome_do_partido(){
	return nome_do_partido;
}

bool Candidato :: operator<(Candidato &p){
	if(codigo_do_cargo == p.get_codigo_do_cargo()){
		return numero_do_candidato < p.get_numero_do_candidato();
	}
	return codigo_do_cargo < p.get_codigo_do_cargo();
}

void Candidato :: imprime_dados(){
	cout << "Candidato: " << get_apelido_do_candidato() << endl;
	cout << "Numero do Candidato: " << get_numero_do_candidato() << endl;
	cout << "Partido: " << get_sigla_do_partido() << " " << get_numero_do_partido() << endl;
	cout << get_nome_do_partido() << endl; 
}
