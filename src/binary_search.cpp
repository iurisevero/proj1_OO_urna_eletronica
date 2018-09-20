#include <bits/stdc++.h>
#include "binary_search.hpp"

using namespace std;

int binary_search_candidato(int size, int numero_do_candidato, vector<Candidato> candidatos){
	int left = 0, right = size;
	bool candidato_encontrado = false;
	for(int i=0; i<500; ++i){
		int medium = left + (right-left)/2;
		if(candidatos[medium].get_numero_do_candidato() == numero_do_candidato){
			candidato_encontrado = true;
			left = medium;
			break;
		}
		else if(candidatos[medium].get_numero_do_candidato() < numero_do_candidato){
			left = medium;
		}
		else{
			right = medium;
		}
	}
	if(candidato_encontrado)
		return left;
	else
		return -1;
}


int binary_search_presidente(int size, int numero_do_candidato, vector<Presidente> candidatos){
	int left = 0, right = size;
	bool candidato_encontrado = false;
	for(int i=0; i<500; ++i){
		int medium = left + (right-left)/2;
		if(candidatos[medium].get_numero_do_candidato() == numero_do_candidato){
			candidato_encontrado = true;
			left = medium;
			break;
		}
		else if(candidatos[medium].get_numero_do_candidato() < numero_do_candidato){
			left = medium;
		}
		else{
			right = medium;
		}
	}
	if(candidato_encontrado)
		return left;
	else
		return -1;
}

int binary_search_governador(int size, int numero_do_candidato, vector<Governador> candidatos){
	int left = 0, right = size;
	bool candidato_encontrado = false;
	for(int i=0; i<500; ++i){
		int medium = left + (right-left)/2;
		if(candidatos[medium].get_numero_do_candidato() == numero_do_candidato){
			candidato_encontrado = true;
			left = medium;
			break;
		}
		else if(candidatos[medium].get_numero_do_candidato() < numero_do_candidato){
			left = medium;
		}
		else{
			right = medium;
		}
	}
	if(candidato_encontrado)
		return left;
	else
		return -1;
}

int binary_search_senador(int size, int numero_do_candidato, vector<Senador> candidatos){
	int left = 0, right = size;
	bool candidato_encontrado = false;
	for(int i=0; i<500; ++i){
		int medium = left + (right-left)/2;
		if(candidatos[medium].get_numero_do_candidato() == numero_do_candidato){
			candidato_encontrado = true;
			left = medium;
			break;
		}
		else if(candidatos[medium].get_numero_do_candidato() < numero_do_candidato){
			left = medium;
		}
		else{
			right = medium;
		}
	}
	if(candidato_encontrado)
		return left;
	else
		return -1;
}

int binary_search_deputado_distrital(int size, int numero_do_candidato, vector<Deputado_Distrital> candidatos){
	int left = 0, right = size;
	bool candidato_encontrado = false;
	for(int i=0; i<500; ++i){
		int medium = left + (right-left)/2;
		if(candidatos[medium].get_numero_do_candidato() == numero_do_candidato){
			candidato_encontrado = true;
			left = medium;
			break;
		}
		else if(candidatos[medium].get_numero_do_candidato() < numero_do_candidato){
			left = medium;
		}
		else{
			right = medium;
		}
	}
	if(candidato_encontrado)
		return left;
	else
		return -1;
}

int binary_search_deputado_federal(int size, int numero_do_candidato, vector<Deputado_Federal> candidatos){
	int left = 0, right = size;
	bool candidato_encontrado = false;
	for(int i=0; i<500; ++i){
		int medium = left + (right-left)/2;
		if(candidatos[medium].get_numero_do_candidato() == numero_do_candidato){
			candidato_encontrado = true;
			left = medium;
			break;
		}
		else if(candidatos[medium].get_numero_do_candidato() < numero_do_candidato){
			left = medium;
		}
		else{
			right = medium;
		}
	}
	if(candidato_encontrado)
		return left;
	else
		return -1;
}
