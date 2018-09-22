#include <bits/stdc++.h>
#include "senador.hpp"

using namespace std;

Senador :: Senador(){
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

Senador :: Senador(int codigo_do_cargo, int numero_do_candidato, int numero_do_partido){
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
Senador :: Senador(string nome_ue, int codigo_do_cargo, string descricao_do_cargo, int numero_do_candidato, string nome_do_candidato, string apelido_do_candidato,
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

Senador :: ~Senador(){}

//Métodos de Inserção
void Senador :: set_nome_do_suplente_1(string nome_do_suplente_1){
	this->nome_do_suplente_1 = nome_do_suplente_1;
}
void Senador :: set_apelido_do_suplente_1(string apelido_do_suplente_1){
	this->apelido_do_suplente_1 = apelido_do_suplente_1;
}
void Senador :: set_nome_do_suplente_2(string nome_do_suplente_2){
	this->nome_do_suplente_2= nome_do_suplente_2;
}
void Senador :: set_apelido_do_suplente_2(string apelido_do_suplente_2){
	this->apelido_do_suplente_2 = apelido_do_suplente_2;
}

//Métodos de Visualização
string Senador :: get_nome_do_suplente_1(){
	return nome_do_suplente_1;
}
string Senador :: get_apelido_do_suplente_1(){
	return apelido_do_suplente_1;
}
string Senador :: get_nome_do_suplente_2(){
	return nome_do_suplente_2;
}
string Senador :: get_apelido_do_suplente_2(){
	return apelido_do_suplente_2;
}

void Senador :: imprime_dados(){

	cout << "Senador: " << get_apelido_do_candidato() << " - " << get_nome_ue() << endl;
	cout << "Numero do Senador: " << get_numero_do_candidato() << endl;
	cout << "Partido do Senador: " << get_sigla_do_partido() << " " << get_numero_do_partido() << endl;
	cout << get_nome_do_partido() << endl;
	cout << "Suplente 1: " << get_apelido_do_suplente_1() << endl;
	cout << "Suplente 2: " << get_apelido_do_suplente_2() << endl;
	cout << endl;
}