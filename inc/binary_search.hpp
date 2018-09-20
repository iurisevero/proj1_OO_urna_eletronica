#ifndef BINARY_SEARCH_HPP
#define BINARY_SEARCH_HPP

#include <bits/stdc++.h>
#include "candidato.hpp"
#include "presidente.hpp"
#include "governador.hpp"
#include "senador.hpp"
#include "deputado_distrital.hpp"
#include "deputado_federal.hpp"

int binary_search_candidato(int size, int numero_do_candidato, vector<Candidato> candidatos);
int binary_search_presidente(int size, int numero_do_candidato, vector<Presidente> candidatos);
int binary_search_governador(int size, int numero_do_candidato, vector<Governador> candidatos);
int binary_search_senador(int size, int numero_do_candidato, vector<Senador> candidatos);
int binary_search_deputado_distrital(int size, int numero_do_candidato, vector<Deputado_Distrital> candidatos);
int binary_search_deputado_federal(int size, int numero_do_candidato, vector<Deputado_Federal> candidatos);


#endif