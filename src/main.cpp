#include <bits/stdc++.h>
#include "binary_search.hpp"
#include "candidato.hpp"
#include "presidente.hpp"
#include "governador.hpp"
#include "senador.hpp"
#include "deputado_distrital.hpp"
#include "deputado_federal.hpp"

using namespace std;

vector<Candidato> candidatos;
vector<Presidente> presidente;
vector<Governador> governador;
vector<Senador> senador;
vector<Deputado_Federal> deputado_federal;
vector<Deputado_Distrital> deputado_distrital;


void organizador_de_candidato(Candidato candidato_atual);
int localizador_de_candidato(int numero_do_candidato, int codigo_do_cargo);

int main(){

	//Deputado Distrital
	cout << "DEPUTADO DISTRITAL:\n\nInsira o codigo do candidato: ";
	int numero_do_candidato;
	cin >> numero_do_candidato;
	int posicao = localizador_de_candidato(numero_do_candidato, 8);
	if(posicao==-1){
		cout << 
	}
}

void organizador_de_candidato(Candidato candidato_atual){

	switch(candidato_atual->get_codigo_do_cargo){
		case 1:
			presidente.push_back(candidato_atual);
			break;
		case 2:
			candidatos.push_back(candidato_atual);
			break;
		case 3:
			governador.push_back(candidato_atual);
			break;
		case 4:
			candidatos.push_back(candidato_atual);
			break;
		case 5:
			senador.push_back(candidato_atual);
			break;
		case 6:
			deputado_federal.push_back(candidato_atual);
			break;
		case 8:
			deputado_distrital.push_back(candidato_atual);
			break;
		case 9:
			candidatos.push_back(candidato_atual);
			break;
		case 10:
			candidatos.push_back(candidato_atual);
			break;
		default:
			cout << "Cargo inválido\n";
	}
}

int localizador_de_candidato(int numero_do_candidato, int codigo_do_cargo){
	switch(codigo_do_cargo){
		case 1:
			sort(presidente.begin(), presidente.end());
			return binary_search_presidente(presidente.size(), numero_do_candidato, presidente);
		case 3:
			sort(governador.begin(), governador.end());
			return binary_search_governador(governador.size(), numero_do_candidato, governador);
		case 5:
			sort(senador.begin(), senador.end());
			return binary_search_governador(senador.size(), numero_do_candidato, senador);
		case 6:
			sort(deputado_federal.begin(), deputado_federal.end());
			return binary_search_governador(deputado_federal.size(), numero_do_candidato, deputado_federal);
		case 8:
			sort(deputado_distrital.begin(), deputado_distrital.end());
			return binary_search_governador(deputado_distrital.size(), numero_do_candidato, deputado_distrital);
		default:
			cout << "Cargo inválido\n";
	}
}