#include "eleitor.hpp"
#include <bits/stdc++.h>

using namespace std;

Eleitor :: Eleitor(){
	nome_do_eleitor = "";
	presidente = -1;
	governador = -1;
	senador_1 = -1;
	senador_2 = -1;
	deputado_federal = -1;
	deputado_distrital = -1;
}
Eleitor :: Eleitor(string nome_do_eleitor){
	set_nome_do_eleitor(nome_do_eleitor);
	presidente = -1;
	governador = -1;
	senador_1 = -1;
	senador_2 = -1;
	deputado_federal = -1;
	deputado_distrital = -1;
}
Eleitor :: Eleitor(string nome_do_eleitor, int presidente, int governador, int senador_1, int senador_2, int deputado_federal, int deputado_distrital){
	set_nome_do_eleitor(nome_do_eleitor);
	set_presidente(presidente);
	set_governador(governador);
	set_senador_1(senador_1);
	set_senador_2(senador_2);
	set_deputado_federal(deputado_federal);
	set_deputado_distrital(deputado_distrital);
}

Eleitor :: ~Eleitor(){}

//Métodos de Inserçã
void Eleitor :: set_nome_do_eleitor(string nome_do_eleitor){
	this->nome_do_eleitor = nome_do_eleitor;
}
void Eleitor :: set_presidente(int presidente){
	this->presidente = presidente;
}
void Eleitor :: set_governador(int governador){
	this->governador = governador;
}
void Eleitor :: set_senador_1(int senador_1){
	this->senador_1 = senador_1;
}
void Eleitor :: set_senador_2(int senador_2){
	this->senador_2 = senador_2;
}
void Eleitor :: set_deputado_federal(int deputado_federal){
	this->deputado_federal = deputado_federal;
}
void Eleitor :: set_deputado_distrital(int deputado_distrital){
	this->deputado_distrital = deputado_distrital;
}

//Métodos de Visualizaçã
string Eleitor :: get_nome_do_eleitor(){
	return nome_do_eleitor;
}
int Eleitor :: get_presidente(){
	return presidente;	
}
int Eleitor :: get_governador(){
	return governador;	
}
int Eleitor :: get_senador_1(){
	return senador_1;
}
int Eleitor :: get_senador_2(){
	return senador_2;
}
int Eleitor :: get_deputado_federal(){
	return deputado_federal;
}
int Eleitor :: get_deputado_distrital(){
	return deputado_distrital;
}

bool Eleitor :: operator<(Eleitor &p){
	return nome_do_eleitor < p.get_nome_do_eleitor();
}