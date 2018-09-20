#include <bits/stdc++.h>
#include "governador.hpp"

using namespace std;

Governador :: Governador(){
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

Governador :: Governador(int codigo_do_cargo, int numero_do_candidato, int numero_do_partido){
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
Governador :: Governador(string nome_ue, int codigo_do_cargo, string descricao_do_cargo, int numero_do_candidato, string nome_do_candidato, string apelido_do_candidato,
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

Governador :: ~Governador(){}

//Métodos de Inserção
void Governador :: set_nome_do_vice(string nome_do_vice){
	this->nome_do_vice = nome_do_vice;
}
void Governador :: set_apelido_do_vice(string apelido_do_vice){
	this->apelido_do_vice = apelido_do_vice;
}
void Governador :: set_numero_do_partido_do_vice(int numero_do_partido_do_vice){
	this->numero_do_partido_do_vice = numero_do_partido_do_vice;
}
void Governador :: set_sigla_do_partido_do_vice(string sigla_do_partido_do_vice){
	this->sigla_do_partido_do_vice = sigla_do_partido_do_vice;
}
void Governador :: set_nome_do_partido_do_vice(string nome_do_partido_do_vice){
	this->nome_do_partido_do_vice = nome_do_partido_do_vice;
}

//Métodos de Visualização
string Governador :: get_nome_do_vice(){
	return nome_do_vice;
}
string Governador :: get_apelido_do_vice(){
	return apelido_do_vice;
}
int Governador :: get_numero_do_partido_do_vice(){
	return numero_do_partido_do_vice;
}
string Governador :: get_sigla_do_partido_do_vice(){
	return sigla_do_partido_do_vice;
}
string Governador :: get_nome_do_partido_do_vice(){
	return nome_do_partido_do_vice;
}

void Governador :: imprime_dados(){
	cout << "Governador: " << get_apelido_do_candidato() << endl;
	cout << "Numero do Governador: " << get_numero_do_candidato() << endl;
	cout << "Partido do Governador: " << get_sigla_do_partido() << " " << get_numero_do_partido() << endl;
	cout << get_nome_do_partido() << endl;
	cout << "Vice-governador: " << get_apelido_do_vice() << endl;
	cout << "Partido do Vice-governador: " << get_sigla_do_partido_do_vice() << " " << get_numero_do_partido_do_vice() << endl;
	cout << get_nome_do_partido_do_vice() << endl; 
	cout << endl;
}