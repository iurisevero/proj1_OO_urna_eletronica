#include <bits/stdc++.h>
#include "binary_search.hpp"
#include "candidato.hpp"
#include "presidente.hpp"
#include "governador.hpp"
#include "senador.hpp"
#include "deputado_distrital.hpp"
#include "deputado_federal.hpp"
#include "eleitor.hpp"
#include "leitor_de_arquivos.hpp"

using namespace std;

//Estruturas de Armazenamento de dados
vector<Candidato> sub_candidatos;
vector<Presidente> presidente;
vector<Governador> governador;
vector<Senador> senador;
vector<Deputado_Federal> deputado_federal;
vector<Deputado_Distrital> deputado_distrital;
vector<Eleitor> eleitores;
map<int, string> partidos;

//Estruturas para contagem de votos
int quantidade_de_nulos=0;
int quantidade_de_brancos=0;
map<int, int> votos_para_partido;
map<int, int> votos_para_deputado_federal;
map<int, int> votos_para_deputado_distrital;
map<int, int> votos_para_senador;
map<int, int> votos_para_governador;
map<int, int> votos_para_presidente;

//Funções
void organizador_de_candidato(Candidato candidato_atual);
void organizador_de_sub_candidato(Candidato candidato_atual);
void organizador_de_partidos(Candidato candidato_atual);
void contador_de_votos(Eleitor eleitor);
void imprime_dados_do_eleitor(Eleitor eleitor, ofstream *dados);
void imprime_candidatos_vencedores();
void limpa_buffer();
int localizador_de_candidato(int numero_do_candidato, int codigo_do_cargo);
int voto_deputado_distrital(); 
int voto_deputado_federal(); 
int voto_senador(int senador, int posicao_senador_1); 
int voto_governador();
int voto_presidente(); 

int main(){

	vector<Candidato> candidatos;
	while(1){
		try{
			candidatos = leitor_de_arquivo_DF();
		}
		catch(int e){
			return 0;
		}
		break;
	}
	for(auto p: candidatos){
		organizador_de_candidato(p);
		organizador_de_partidos(p);
	}

	while(1){
		try{
			candidatos = leitor_de_arquivo_BR();
		}
		catch(int e){
			continue;
		}
		break;
	}
	for(auto p: candidatos){
		organizador_de_candidato(p);
		organizador_de_partidos(p);
	}

	for(auto p: sub_candidatos){
		organizador_de_sub_candidato(p);
	}

	int N, retorno;
	while(1){
		cout << "Insira o número de eleitores: ";
		retorno = scanf(" %d", &N);
		if(retorno){
			break;
		}
		else{
			cout << "Valor inválido\n";
			limpa_buffer();
		}
	}
	limpa_buffer();
	for(int i=0; i<N; ++i){
		cout << "\nInsira seu nome: ";
		string nome;
		getline(cin, nome);
		int deputado_federal = voto_deputado_federal();
		int deputado_distrital = voto_deputado_distrital();
		int senador_1 = voto_senador(1, 0);
		int senador_2 = voto_senador(2, senador_1);
		int governador = voto_governador();
		int presidente = voto_presidente();
		Eleitor eleitor_atual = Eleitor(nome, presidente, governador, senador_1, senador_2, deputado_federal, deputado_distrital);
		contador_de_votos(eleitor_atual);
		eleitores.push_back(eleitor_atual);
		limpa_buffer();
	}

	imprime_candidatos_vencedores();

	ofstream dados_dos_eleitores("data/dados_dos_eleitores.txt");
	for(int i=0; i<N; ++i){
		imprime_dados_do_eleitor(eleitores[i], &dados_dos_eleitores);
	}
	dados_dos_eleitores.close();
}

void organizador_de_candidato(Candidato candidato_atual){
	switch(candidato_atual.get_codigo_do_cargo()){
		case 1:{
			Presidente presidente_atual = Presidente(candidato_atual.get_nome_ue(), candidato_atual.get_codigo_do_cargo(), "Presidente", candidato_atual.get_numero_do_candidato(), candidato_atual.get_nome_do_candidato(), candidato_atual.get_apelido_do_candidato(), candidato_atual.get_numero_do_partido(), candidato_atual.get_sigla_do_partido(), candidato_atual.get_nome_do_partido());
			presidente.push_back(presidente_atual);
			break;
		}
		case 2:
			sub_candidatos.push_back(candidato_atual);
			break;
		case 3:{
			Governador governador_atual = Governador(candidato_atual.get_nome_ue(), candidato_atual.get_codigo_do_cargo(), "Governador", candidato_atual.get_numero_do_candidato(),
				candidato_atual.get_nome_do_candidato(), candidato_atual.get_apelido_do_candidato(), candidato_atual.get_numero_do_partido(), candidato_atual.get_sigla_do_partido(), candidato_atual.get_nome_do_partido());
			governador.push_back(governador_atual);
			break;
		}
		case 4:
			sub_candidatos.push_back(candidato_atual);
			break;
		case 5:{
			Senador senador_atual = Senador(candidato_atual.get_nome_ue(), candidato_atual.get_codigo_do_cargo(), "Senador", candidato_atual.get_numero_do_candidato(),
				candidato_atual.get_nome_do_candidato(), candidato_atual.get_apelido_do_candidato(), candidato_atual.get_numero_do_partido(), candidato_atual.get_sigla_do_partido(), candidato_atual.get_nome_do_partido());
			senador.push_back(senador_atual);
			break;
		}
		case 6:{
			Deputado_Federal deputado_federal_atual = Deputado_Federal(candidato_atual.get_nome_ue(), candidato_atual.get_codigo_do_cargo(), "Deputadom Federal", candidato_atual.get_numero_do_candidato(),
				candidato_atual.get_nome_do_candidato(), candidato_atual.get_apelido_do_candidato(), candidato_atual.get_numero_do_partido(), candidato_atual.get_sigla_do_partido(), candidato_atual.get_nome_do_partido());
			deputado_federal.push_back(deputado_federal_atual);
			break;
		}
		case 8:{
			Deputado_Distrital deputado_distrital_atual = Deputado_Distrital(candidato_atual.get_nome_ue(), candidato_atual.get_codigo_do_cargo(), "Deputado Distrital", candidato_atual.get_numero_do_candidato(),
				candidato_atual.get_nome_do_candidato(), candidato_atual.get_apelido_do_candidato(), candidato_atual.get_numero_do_partido(), candidato_atual.get_sigla_do_partido(), candidato_atual.get_nome_do_partido());
			deputado_distrital.push_back(deputado_distrital_atual);
			break;
		}
		case 9:
			sub_candidatos.push_back(candidato_atual);
			break;
		case 10:
			sub_candidatos.push_back(candidato_atual);
			break;
		default:
			cout << "Cargo inválido\n";
			break;
	}
}

void organizador_de_sub_candidato(Candidato candidato_atual){
	switch(candidato_atual.get_codigo_do_cargo()){
		case 2:{
			int posicao_presidente = localizador_de_candidato(candidato_atual.get_numero_do_candidato(), 1);
			if(posicao_presidente>=0){
				presidente[posicao_presidente].set_nome_do_vice(candidato_atual.get_nome_do_candidato());
				presidente[posicao_presidente].set_apelido_do_vice(candidato_atual.get_apelido_do_candidato());
				presidente[posicao_presidente].set_numero_do_partido_do_vice(candidato_atual.get_numero_do_partido());
				presidente[posicao_presidente].set_sigla_do_partido_do_vice(candidato_atual.get_sigla_do_partido());
				presidente[posicao_presidente].set_nome_do_partido_do_vice(candidato_atual.get_nome_do_partido());
			}
			break;
		}
		case 4:{
			int posicao_governador = localizador_de_candidato(candidato_atual.get_numero_do_candidato(), 3);
			if(posicao_governador>=0){
				governador[posicao_governador].set_nome_do_vice(candidato_atual.get_nome_do_candidato());
				governador[posicao_governador].set_apelido_do_vice(candidato_atual.get_apelido_do_candidato());
				governador[posicao_governador].set_numero_do_partido_do_vice(candidato_atual.get_numero_do_partido());
				governador[posicao_governador].set_sigla_do_partido_do_vice(candidato_atual.get_sigla_do_partido());
				governador[posicao_governador].set_nome_do_partido_do_vice(candidato_atual.get_nome_do_partido());
			}
			break;
		}
		case 9:{
			int posicao_senador_1 = localizador_de_candidato(candidato_atual.get_numero_do_candidato(), 5);
			if(posicao_senador_1>=0){
				senador[posicao_senador_1].set_nome_do_suplente_1(candidato_atual.get_nome_do_candidato());
				senador[posicao_senador_1].set_apelido_do_suplente_1(candidato_atual.get_apelido_do_candidato());
			}
			break;
		}
		case 10:{
			int posicao_senador_2 = localizador_de_candidato(candidato_atual.get_numero_do_candidato(), 5);
			if(posicao_senador_2>=0){
				senador[posicao_senador_2].set_nome_do_suplente_2(candidato_atual.get_nome_do_candidato());
				senador[posicao_senador_2].set_apelido_do_suplente_2(candidato_atual.get_apelido_do_candidato());
			}
			break;
		}
		default:
			cout << "Cargo inválido\n";
			break;
	}
}

void organizador_de_partidos(Candidato candidato_atual){
	if(partidos.find(candidato_atual.get_numero_do_partido())==partidos.end()){
		partidos[candidato_atual.get_numero_do_partido()] = candidato_atual.get_nome_do_partido();
		votos_para_partido[candidato_atual.get_numero_do_partido()] = 0;
	}
}

void imprime_dados_do_eleitor(Eleitor eleitor, ofstream *dados){
	*dados << "Eleitor: " << eleitor.get_nome_do_eleitor() << endl;
	*dados << "	Presidente: ";
	switch(eleitor.get_presidente()){
		case -1:
			*dados << "Nulo\n";
			break;
		case -2:
			*dados << "Branco\n";
			break;
		default:
			*dados << presidente[eleitor.get_presidente()].get_nome_do_candidato() << endl;
			break;
	}
	*dados << "	Governador: ";
	switch(eleitor.get_governador()){
		case -1:
			*dados << "Nulo\n";
			break;
		case -2:
			*dados << "Branco\n";
			break;
		default:
			*dados << governador[eleitor.get_governador()].get_nome_do_candidato() << endl;
			break;
	}
	*dados << "	Senador 1: ";
	switch(eleitor.get_senador_1()){
		case -1:
			*dados << "Nulo\n";
			break;
		case -2:
			*dados << "Branco\n";
			break;
		default:
			*dados << senador[eleitor.get_senador_1()].get_nome_do_candidato() << endl;
			break;
	}
	*dados << "	Senador 2 ";
	switch(eleitor.get_senador_2()){
		case -1:
			*dados << "Nulo\n";
			break;
		case -2:
			*dados << "Branco\n";
			break;
		default:
			*dados << senador[eleitor.get_senador_2()].get_nome_do_candidato() << endl;
			break;
	}
	*dados << "	Deputado Federal: ";
	switch(eleitor.get_deputado_federal()){
		case -1:
			*dados << "Nulo\n";
			break;
		case -2:
			*dados << "Branco\n";
			break;
		default:
			if(eleitor.get_deputado_federal()<0){
				*dados << partidos[-1*eleitor.get_deputado_federal()] << endl;
			}
			else{
				*dados << deputado_federal[eleitor.get_deputado_federal()].get_nome_do_candidato() << endl;
			}
			break;
	}
	*dados << "	Deputado Distrital: ";
	switch(eleitor.get_deputado_distrital()){
		case -1:
			*dados << "Nulo\n";
			break;
		case -2:
			*dados << "Branco\n";
			break;
		default:
			if(eleitor.get_deputado_distrital()<0){
				*dados << partidos[-1*eleitor.get_deputado_distrital()] << endl;
			}
			else{
				*dados << deputado_distrital[eleitor.get_deputado_distrital()].get_nome_do_candidato() << endl;
			}
			break;
	}

	*dados << endl;
}

void contador_de_votos(Eleitor eleitor){
	switch(eleitor.get_presidente()){
		case -1:
			quantidade_de_nulos++;
			break;
		case -2:
			quantidade_de_brancos++;
			break;
		default:
			if(votos_para_presidente.find(eleitor.get_presidente())==votos_para_presidente.end()){
				votos_para_presidente[eleitor.get_presidente()] = 1;
				votos_para_partido[presidente[eleitor.get_presidente()].get_numero_do_partido()]++;
			}
			else{
				votos_para_presidente[eleitor.get_presidente()]++;
				votos_para_partido[presidente[eleitor.get_presidente()].get_numero_do_partido()]++;
			}
			break;
	}
	switch(eleitor.get_governador()){
		case -1:
			quantidade_de_nulos++;
			break;
		case -2:
			quantidade_de_brancos++;
			break;
		default:
			if(votos_para_governador.find(eleitor.get_governador())==votos_para_governador.end()){
				votos_para_governador[eleitor.get_governador()] = 1;
				votos_para_partido[governador[eleitor.get_governador()].get_numero_do_partido()]++;
			}
			else{
				votos_para_governador[eleitor.get_governador()]++;
				votos_para_partido[governador[eleitor.get_governador()].get_numero_do_partido()]++;
			}
			break;
	}
	switch(eleitor.get_senador_1()){
		case -1:
			quantidade_de_nulos++;
			break;
		case -2:
			quantidade_de_brancos++;
			break;
		default:
			if(votos_para_senador.find(eleitor.get_senador_1())==votos_para_senador.end()){
				votos_para_senador[eleitor.get_senador_1()] = 1;
				votos_para_partido[senador[eleitor.get_senador_1()].get_numero_do_partido()]++;
			}
			else{
				votos_para_senador[eleitor.get_senador_1()]++;
				votos_para_partido[senador[eleitor.get_senador_1()].get_numero_do_partido()]++;
			}
			break;
	}
	switch(eleitor.get_senador_2()){
		case -1:
			quantidade_de_nulos++;
			break;
		case -2:
			quantidade_de_brancos++;
			break;
		default:
			if(votos_para_senador.find(eleitor.get_senador_2())==votos_para_senador.end()){
				votos_para_senador[eleitor.get_senador_2()] = 1;
				votos_para_partido[senador[eleitor.get_senador_2()].get_numero_do_partido()]++;
			}
			else{
				votos_para_senador[eleitor.get_senador_2()]++;
				votos_para_partido[senador[eleitor.get_senador_2()].get_numero_do_partido()]++;
			}
			break;
	}
	switch(eleitor.get_deputado_federal()){
		case -1:
			quantidade_de_nulos++;
			break;
		case -2:
			quantidade_de_brancos++;
			break;
		default:
			if(eleitor.get_deputado_federal()<0){
				votos_para_partido[eleitor.get_deputado_federal()*-1]++;
			}
			else{
				if(votos_para_deputado_federal.find(eleitor.get_deputado_federal())==votos_para_deputado_federal.end()){
					votos_para_deputado_federal[eleitor.get_deputado_federal()] = 1;
					votos_para_partido[deputado_federal[eleitor.get_deputado_federal()].get_numero_do_partido()]++;
				}
				else{
					votos_para_deputado_federal[eleitor.get_deputado_federal()]++;
					votos_para_partido[deputado_federal[eleitor.get_deputado_federal()].get_numero_do_partido()]++;
				}
			}
			break;
	}
	switch(eleitor.get_deputado_distrital()){
		case -1:
			quantidade_de_nulos++;
			break;
		case -2:
			quantidade_de_brancos++;
			break;
		default:
			if(eleitor.get_deputado_distrital()<0){
				votos_para_partido[eleitor.get_deputado_distrital()*-1]++;
			}
			else{
				if(votos_para_deputado_distrital.find(eleitor.get_deputado_distrital())==votos_para_deputado_distrital.end()){
					votos_para_deputado_distrital[eleitor.get_deputado_distrital()] = 1;
					votos_para_partido[deputado_distrital[eleitor.get_deputado_distrital()].get_numero_do_partido()]++;
				}
				else{
					votos_para_deputado_distrital[eleitor.get_deputado_distrital()]++;
					votos_para_partido[deputado_distrital[eleitor.get_deputado_distrital()].get_numero_do_partido()]++;
				}
			}
	}
}

void imprime_candidatos_vencedores(){
	ofstream candidatos_vencedores("data/candidatos_vencedores.txt");
	cout << "Quantidade de votos brancos: " << quantidade_de_brancos << endl;
	cout << "\nQuantidade de votos nulos: " << quantidade_de_nulos << endl;
	candidatos_vencedores << "Quantidade de votos brancos: " << quantidade_de_brancos << endl;
	candidatos_vencedores << "\nQuantidade de votos nulos: " << quantidade_de_nulos << endl;
	int maior = 0, posicao_maior;
	for(auto p: votos_para_presidente){
			if(p.second>maior){
				maior = p.second;
				posicao_maior = p.first;
			}
	}
	if(maior > 0){
		cout << "\nPresidente com mais votos: " << presidente[posicao_maior].get_apelido_do_candidato() << "\nVotos: " << maior << endl;
		candidatos_vencedores << "\nPresidente com mais votos: " << presidente[posicao_maior].get_apelido_do_candidato() << "\nVotos: " << maior << endl;
	}
	else{
		cout << "Não houveram votos para presidente.\n";
		candidatos_vencedores << "Não houveram votos para presidente.\n";
	}
	maior = 0;
	for(auto p: votos_para_governador){
			if(p.second>maior){
				maior = p.second;
				posicao_maior = p.first;
			}
	}
	if(maior > 0){
		cout << "\nGovernador com mais votos: " << governador[posicao_maior].get_apelido_do_candidato() << "\nVotos: " << maior << endl;
		candidatos_vencedores << "\nGovernador com mais votos: " << governador[posicao_maior].get_apelido_do_candidato() << "\nVotos: " << maior << endl;
	}
	else{
		cout << "Não houveram votos para governador.\n";
		candidatos_vencedores << "Não houveram votos para governador.\n";
	}
	maior = 0;
	for(auto p: votos_para_senador){
			if(p.second>maior){
				maior = p.second;
				posicao_maior = p.first;
			}
	}
	if(maior > 0){
		cout << "\nSenador com mais votos: " << senador[posicao_maior].get_apelido_do_candidato() << "\nVotos: " << maior << endl;
		candidatos_vencedores << "\nSenador com mais votos: " << senador[posicao_maior].get_apelido_do_candidato() << "\nVotos: " << maior << endl;
	}
	else{
		cout << "Não houveram votos para senador.\n";
		candidatos_vencedores << "Não houveram votos para senador.\n";
	}
	cout << "\nDeputados Federais com mais votos:\n";
	candidatos_vencedores << "\nDeputados Federais com mais votos:\n";
	for(int i=1; i<=5; ++i){
		maior = 0;
		for(auto p: votos_para_deputado_federal){
				if(p.second>maior){
					maior = p.second;
					posicao_maior = p.first;
				}
		}
		if(maior > 0){
			cout << i << ") " << deputado_federal[posicao_maior].get_apelido_do_candidato() << "\nVotos: " << maior << endl;
			candidatos_vencedores << i << ") " << deputado_federal[posicao_maior].get_apelido_do_candidato() << "\nVotos: " << maior << endl;
		}
		else{
			cout << "Não houveram votos para deputado federal.\n";
			candidatos_vencedores << "Não houveram votos para deputado federal.\n";
		}
		votos_para_deputado_federal[posicao_maior] = -1;
	}
	cout << "\nDeputados Distritais com mais votos:\n";
	candidatos_vencedores << "\nDeputados Distritais com mais votos:\n";
	for(int i=1; i<=5; ++i){
		maior = 0;
		for(auto p: votos_para_deputado_distrital){
				if(p.second>maior){
					maior = p.second;
					posicao_maior = p.first;
				}
		}
		if(maior > 0){
			cout << i << ") " << deputado_distrital[posicao_maior].get_apelido_do_candidato() << "\nVotos: " << maior << endl;
			candidatos_vencedores << i << ") " << deputado_distrital[posicao_maior].get_apelido_do_candidato() << "\nVotos: " << maior << endl;
		}
		else{
			cout << "Não houveram votos para deputado distrital.\n";
			candidatos_vencedores << "Não houveram votos para deputado distrital.\n";
		}
		votos_para_deputado_distrital[posicao_maior] = -1;
	}
	maior = 0;
	for(auto p: votos_para_partido){
			if(p.second>maior){
				maior = p.second;
				posicao_maior = p.first;
			}
	}
	if(maior > 0){
		cout << "\nPartido com mais votos: " << partidos[posicao_maior] << "\nVotos: " << maior << endl;
		candidatos_vencedores << "\nPartido com mais votos: " << partidos[posicao_maior] << "\nVotos: " << maior << endl;
	}
	else{
		cout << "Não houveram votos para partido.\n";
		candidatos_vencedores << "Não houveram votos para partido.\n";
	}

	candidatos_vencedores.close();
}

void limpa_buffer(){
	char lixo;
	do{
		scanf("%c", &lixo);
	}while(lixo!='\n');
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
			return binary_search_senador(senador.size(), numero_do_candidato, senador);
		case 6:
			sort(deputado_federal.begin(), deputado_federal.end());
			return binary_search_deputado_federal(deputado_federal.size(), numero_do_candidato, deputado_federal);
		case 8:
			sort(deputado_distrital.begin(), deputado_distrital.end());
			return binary_search_deputado_distrital(deputado_distrital.size(), numero_do_candidato, deputado_distrital);
		default:
			cout << "Cargo inválido\n";
			return 0;
	}
}

int voto_deputado_distrital(){
	int voto;
	bool voto_valido = false;
	cout << "\nDEPUTADO DISTRITAL:\n";

	cout << "Deseja votar em branco?\n1)Sim\n2)Não\nDigite sua opção: ";
	while(1){
		int voto_branco=0, retorno;
		retorno = scanf("%d", &voto_branco);
		if(retorno){
			if(voto_branco == 1){
				cout << "Voto em branco.\n\n";
				voto_valido = true;
				voto = -2;
				break;
			}
			else if(voto_branco == 2){
				break;		
			}
			else{
				cout << "Valor inválido, digite novamente!\n1)Sim\n2)Não\nDigite sua opção: ";
			}
		}
		else{
			cout << "Valor inválido, digite novamente!\n1)Sim\n2)Não\nDigite sua opção: ";
			 limpa_buffer();
		}
	}
	if(voto_valido){
		cout << "Deseja confirmar o voto?\n1)Confirmar\n2)Cancelar\nDigite sua opção: ";
		while(1){
			int confirmacao, retorno;
			retorno = scanf("%d", &confirmacao);
			if(retorno){
				if(confirmacao == 1){
					cout << "Voto confirmado.\n\n";
					break;
				}
				else if(confirmacao == 2){
					voto_valido=false;
					break;		
				}
				else{
					cout << "Valor inválido, digite novamente!\n1)Confirmar\n2)Cancelar\nDigite sua opção: ";
				}
			}
			else{
				cout << "Valor inválido, digite novamente!\n1)Confirmar\n2)Cancelar\nDigite sua opção: ";
				limpa_buffer();
			}
		}
	}

	if(!voto_valido){
		while(1){
			cout << "Insira o código do candidato: ";
			int numero_do_candidato, retorno;
			retorno = scanf("%d", &numero_do_candidato);
			if(retorno&&((numero_do_candidato<100000&&numero_do_candidato>9999)||(numero_do_candidato<100&&numero_do_candidato>9))){
				if(numero_do_candidato<100){
					if(partidos.find(numero_do_candidato)==partidos.end()){
						cout << "Partido não encontrado.\n\nDeseja votar nulo?\n1)Sim\n2)Não\nDigite sua opção: ";
						while(1){
							int voto_nulo;
							retorno = scanf("%d", &voto_nulo);
							if(retorno){
								if(voto_nulo == 1){

									voto_valido = true;
									voto = -1;
									break;
								}
								else if(voto_nulo == 2){
									break;		
								}
								else{
									cout << "Valor inválido, digite novamente!\n1)Sim\n2)Não\nDigite sua opção: ";
								}
							}
							else{
								cout << "Valor inválido, digite novamente!\n1)Sim\n2)Não\nDigite sua opção: ";
								 limpa_buffer();
							}
						}		
					}
					else{
						voto_valido = true;
						voto = -1*numero_do_candidato;
					}
				}
				else{
					int posicao = localizador_de_candidato(numero_do_candidato, 8);
					if(posicao==-1){
						cout << "Candidato não encontrado.\n\nDeseja votar nulo?\n1)Sim\n2)Não\nDigite sua opção: ";
						while(1){
							int voto_nulo;
							retorno = scanf("%d", &voto_nulo);
							if(retorno){
								if(voto_nulo == 1){

									voto_valido = true;
									voto = -1;
									break;
								}
								else if(voto_nulo == 2){
									break;		
								}
								else{
									cout << "Valor inválido, digite novamente!\n1)Sim\n2)Não\nDigite sua opção: ";
								}
							}
							else{
								cout << "Valor inválido, digite novamente!\n1)Sim\n2)Não\nDigite sua opção: ";
								 limpa_buffer();
							}
						}		
					}
					else{
						voto_valido = true;
						voto = posicao;
					}
				}
				bool voto_confirmado = false;
				if(voto_valido){
					if(voto >= 0){
						deputado_distrital[voto].imprime_dados();
					}
					else if(voto==-1){
						cout << "Voto nulo\n\n";
					}
					else{
						cout << partidos[-1*voto] << endl << endl;
					}
					cout << "Deseja confirmar o voto?\n1)Confirmar\n2)Cancelar\nDigite sua opção: ";
					while(1){
						int confirmacao;
						retorno = scanf("%d", &confirmacao);
						if(retorno){
							if(confirmacao == 1){
								cout << "Voto confirmado.\n\n";
								voto_confirmado = true;
								break;
							}
							else if(confirmacao == 2){
								break;		
							}
							else{
								cout << "Valor inválido, digite novamente!\n1)Confirmar\n2)Cancelar\nDigite sua opção: ";
							}
						}
						else{
							cout << "Valor inválido, digite novamente!\n1)Confirmar\n2)Cancelar\nDigite sua opção: ";
						}
					}	

					if(voto_confirmado) break;					
				}
			}
			else{
				cout << "Código inválido.\nO código deve conter 5 caracteres numéricos, com valores entre 1 e 9.\n\n";
				 limpa_buffer();
			}
		}
	}

	return voto;
}

int voto_deputado_federal(){
	int voto;
	bool voto_valido = false;
	cout << "\nDEPUTADO FEDERAL:\n";

	cout << "Deseja votar em branco?\n1)Sim\n2)Não\nDigite sua opção: ";
	while(1){
		int voto_branco=0, retorno;
		retorno = scanf("%d", &voto_branco);
		if(retorno){
			if(voto_branco == 1){
				cout << "Voto em branco.\n\n";
				voto_valido = true;
				voto = -2;
				break;
			}
			else if(voto_branco == 2){
				break;		
			}
			else{
				cout << "Valor inválido, digite novamente!\n1)Sim\n2)Não\nDigite sua opção: ";
				limpa_buffer();
			}
		}
		else{
			cout << "Valor inválido, digite novamente!\n1)Sim\n2)Não\nDigite sua opção: ";
			limpa_buffer();
		}
	}
	if(voto_valido){
		cout << "Deseja confirmar o voto?\n1)Confirmar\n2)Cancelar\nDigite sua opção: ";
		while(1){
			int confirmacao, retorno;
			retorno = scanf("%d", &confirmacao);
			if(retorno){
				if(confirmacao == 1){
					cout << "Voto confirmado.\n\n";
					break;
				}
				else if(confirmacao == 2){
					voto_valido=false;
					break;		
				}
				else{
					cout << "Valor inválido, digite novamente!\n1)Confirmar\n2)Cancelar\nDigite sua opção: ";
				}
			}
			else{
				cout << "Valor inválido, digite novamente!\n1)Confirmar\n2)Cancelar\nDigite sua opção: ";
				limpa_buffer();
			}
		}
	}

	if(!voto_valido){
		while(1){
			cout << "Insira o código do candidato: ";
			int numero_do_candidato, retorno;
			retorno = scanf("%d", &numero_do_candidato);
			if(retorno&&((numero_do_candidato<10000&&numero_do_candidato>999)||(numero_do_candidato<100&&numero_do_candidato>9))){
				if(numero_do_candidato<100){
					if(partidos.find(numero_do_candidato)==partidos.end()){
						cout << "Partido não encontrado.\n\nDeseja votar nulo?\n1)Sim\n2)Não\nDigite sua opção: ";
						while(1){
							int voto_nulo;
							retorno = scanf("%d", &voto_nulo);
							if(retorno){
								if(voto_nulo == 1){

									voto_valido = true;
									voto = -1;
									break;
								}
								else if(voto_nulo == 2){
									break;		
								}
								else{
									cout << "Valor inválido, digite novamente!\n1)Sim\n2)Não\nDigite sua opção: ";
								}
							}
							else{
								cout << "Valor inválido, digite novamente!\n1)Sim\n2)Não\nDigite sua opção: ";
								 limpa_buffer();
							}
						}		
					}
					else{
						voto_valido = true;
						voto = -1*numero_do_candidato;
					}
				}
				else{
					int posicao = localizador_de_candidato(numero_do_candidato, 6);
					if(posicao==-1){
						cout << "Candidato não encontrado.\n\nDeseja votar nulo?\n1)Sim\n2)Não\nDigite sua opção: ";
						while(1){
							int voto_nulo;
							retorno = scanf("%d", &voto_nulo);
							if(retorno){
								if(voto_nulo == 1){

									voto_valido = true;
									voto = -1;
									break;
								}
								else if(voto_nulo == 2){
									break;		
								}
								else{
									cout << "Valor inválido, digite novamente!\n1)Sim\n2)Não\nDigite sua opção: ";
								}
							}
							else{
								cout << "Valor inválido, digite novamente!\n1)Sim\n2)Não\nDigite sua opção: ";
								 limpa_buffer();
							}
						}		
					}
					else{
						voto_valido = true;
						voto = posicao;
					}
				}
				bool voto_confirmado = false;
				if(voto_valido){
					if(voto >= 0){
						deputado_federal[voto].imprime_dados();
					}
					else if(voto==-1){
						cout << "Voto nulo\n\n";
					}
					else{
						cout << partidos[-1*voto] << endl << endl;
					}
					cout << "Deseja confirmar o voto?\n1)Confirmar\n2)Cancelar\nDigite sua opção: ";
					while(1){
						int confirmacao;
						retorno = scanf("%d", &confirmacao);
						if(retorno){
							if(confirmacao == 1){
								cout << "Voto confirmado.\n\n";
								voto_confirmado = true;
								break;
							}
							else if(confirmacao == 2){
								break;		
							}
							else{
								cout << "Valor inválido, digite novamente!\n1)Confirmar\n2)Cancelar\nDigite sua opção: ";
							}
						}
						else{
							cout << "Valor inválido, digite novamente!\n1)Confirmar\n2)Cancelar\nDigite sua opção: ";
							 limpa_buffer();
						}
					}
					if(voto_confirmado) break;						
				}
			}
			else{
				cout << "Código inválido.\nO código deve conter 4 caracteres numéricos, com valores entre 1 e 9.\n\n";
				 limpa_buffer();
			}
		}
	}

	return voto;
}

int voto_senador(int senador_votado, int posicao_senador_1){
	int voto;
	bool voto_valido = false;
	printf("\nSENADOR - %dº vaga:\n", senador_votado);

	cout << "Deseja votar em branco?\n1)Sim\n2)Não\nDigite sua opção: ";
	while(1){
		int voto_branco=0, retorno;
		retorno = scanf("%d", &voto_branco);
		if(retorno){
			if(voto_branco == 1){
				cout << "Voto em branco.\n\n";
				voto_valido = true;
				voto = -2;
				break;
			}
			else if(voto_branco == 2){
				break;		
			}
			else{
				cout << "Valor inválido, digite novamente!\n1)Sim\n2)Não\nDigite sua opção: ";
			}
		}
		else{
			cout << "Valor inválido, digite novamente!\n1)Sim\n2)Não\nDigite sua opção: ";
			limpa_buffer();
		}
	}
	if(voto_valido){
		cout << "Deseja confirmar o voto?\n1)Confirmar\n2)Cancelar\nDigite sua opção: ";
		while(1){
			int confirmacao, retorno;
			retorno = scanf("%d", &confirmacao);
			if(retorno){
				if(confirmacao == 1){
					cout << "Voto confirmado.\n\n";
					break;
				}
				else if(confirmacao == 2){
					voto_valido=false;
					break;		
				}
				else{
					cout << "Valor inválido, digite novamente!\n1)Confirmar\n2)Cancelar\nDigite sua opção: ";
				}
			}
			else{
				cout << "Valor inválido, digite novamente!\n1)Confirmar\n2)Cancelar\nDigite sua opção: ";
				limpa_buffer();
			}
		}
	}

	if(!voto_valido){
		while(1){
			cout << "Insira o código do candidato: ";
			int numero_do_candidato, retorno;
			retorno = scanf("%d", &numero_do_candidato);
			if(retorno&&numero_do_candidato<1000&&numero_do_candidato>99){
				int posicao = localizador_de_candidato(numero_do_candidato, 5);
				if(posicao==-1||(posicao==posicao_senador_1&&senador_votado==2)){
					cout << "Candidato não encontrado/Candidato já selecionado.\n\nDeseja votar nulo?\n1)Sim\n2)Não\nDigite sua opção: ";
					while(1){
						int voto_nulo;
						retorno = scanf("%d", &voto_nulo);
						if(retorno){
							if(voto_nulo == 1){
								voto_valido = true;
								break;
							}
							else if(voto_nulo == 2){
								break;		
							}
							else{
								cout << "Valor inválido, digite novamente!\n1)Sim\n2)Não\nDigite sua opção: ";
							}
						}
						else{
							cout << "Valor inválido, digite novamente!\n1)Sim\n2)Não\nDigite sua opção: ";
							limpa_buffer();
						}
					}		
				}
				else{
					voto_valido = true;
				}
				bool voto_confirmado = false;
				if(voto_valido){
					voto = posicao;
					if(voto >= 0){
						senador[voto].imprime_dados();
					}
					else{
						cout << "Voto nulo\n\n";
					}
					cout << "Deseja confirmar o voto?\n1)Confirmar\n2)Cancelar\nDigite sua opção: ";
					while(1){
						int confirmacao;
						retorno = scanf("%d", &confirmacao);
						if(retorno){
							if(confirmacao == 1){
								cout << "Voto confirmado.\n\n";
								voto_confirmado = true;
								break;
							}
							else if(confirmacao == 2){
								break;		
							}
							else{
								cout << "Valor inválido, digite novamente!\n1)Confirmar\n2)Cancelar\nDigite sua opção: ";
							}
						}
						else{
							cout << "Valor inválido, digite novamente!\n1)Confirmar\n2)Cancelar\nDigite sua opção: ";
							limpa_buffer();
						}
					}
					if(voto_confirmado) break;						
				}
			}
			else{
				cout << "Código inválido.\nO código deve conter 3 caracteres numéricos, com valores entre 1 e 9.\n\n";
				limpa_buffer();
			}
		}
	}

	return voto;
}

int voto_governador(){
	int voto;
	bool voto_valido = false;
	cout << "\nGOVERNADOR:\n";

	cout << "Deseja votar em branco?\n1)Sim\n2)Não\nDigite sua opção: ";
	while(1){
		int voto_branco=0, retorno;
		retorno = scanf("%d", &voto_branco);
		if(retorno){
			if(voto_branco == 1){
				cout << "Voto em branco.\n\n";
				voto_valido = true;
				voto = -2;
				break;
			}
			else if(voto_branco == 2){
				break;		
			}
			else{
				cout << "Valor inválido, digite novamente!\n1)Sim\n2)Não\nDigite sua opção: ";
			}
		}
		else{
			cout << "Valor inválido, digite novamente!\n1)Sim\n2)Não\nDigite sua opção: ";
			limpa_buffer();
		}
	}
	if(voto_valido){
		cout << "Deseja confirmar o voto?\n1)Confirmar\n2)Cancelar\nDigite sua opção: ";
		while(1){
			int confirmacao, retorno;
			retorno = scanf("%d", &confirmacao);
			if(retorno){
				if(confirmacao == 1){
					cout << "Voto confirmado.\n\n";
					break;
				}
				else if(confirmacao == 2){
					voto_valido=false;
					break;		
				}
				else{
					cout << "Valor inválido, digite novamente!\n1)Confirmar\n2)Cancelar\nDigite sua opção: ";
				}
			}
			else{
				cout << "Valor inválido, digite novamente!\n1)Confirmar\n2)Cancelar\nDigite sua opção: ";
				limpa_buffer();
			}
		}
	}

	if(!voto_valido){
		while(1){
			cout << "Insira o código do candidato: ";
			int numero_do_candidato, retorno;
			retorno = scanf("%d", &numero_do_candidato);
			if(retorno&&numero_do_candidato<100&&numero_do_candidato>9){
				int posicao = localizador_de_candidato(numero_do_candidato, 3);
				if(posicao==-1){
					cout << "Candidato não encontrado.\n\nDeseja votar nulo?\n1)Sim\n2)Não\nDigite sua opção: ";
					while(1){
						int voto_nulo;
						retorno = scanf("%d", &voto_nulo);
						if(retorno){
							if(voto_nulo == 1){
								voto_valido = true;
								break;
							}
							else if(voto_nulo == 2){
								break;		
							}
							else{
								cout << "Valor inválido, digite novamente!\n1)Sim\n2)Não\nDigite sua opção: ";
							}
						}
						else{
							cout << "Valor inválido, digite novamente!\n1)Sim\n2)Não\nDigite sua opção: ";
							limpa_buffer();
						}
					}		
				}
				else{
					voto_valido = true;
				}
				bool voto_confirmado = false;
				if(voto_valido){
					voto = posicao;
					if(voto >= 0){
						governador[voto].imprime_dados();
					}
					else{
						cout << "Voto nulo\n\n";
					}
					cout << "Deseja confirmar o voto?\n1)Confirmar\n2)Cancelar\nDigite sua opção: ";
					while(1){
						int confirmacao;
						retorno = scanf("%d", &confirmacao);
						if(retorno){
							if(confirmacao == 1){
								cout << "Voto confirmado.\n\n";
								voto_confirmado = true;
								break;
							}
							else if(confirmacao == 2){
								break;		
							}
							else{
								cout << "Valor inválido, digite novamente!\n1)Confirmar\n2)Cancelar\nDigite sua opção: ";
							}
						}
						else{
							cout << "Valor inválido, digite novamente!\n1)Confirmar\n2)Cancelar\nDigite sua opção: ";
							limpa_buffer();
						}
					}
					if(voto_confirmado) break;						
				}
			}
			else{
				cout << "Código inválido.\nO código deve conter 2 caracteres numéricos, com valores entre 1 e 9.\n\n";
				limpa_buffer();
			}
		}
	}

	return voto;
}

int voto_presidente(){
	int voto;
	bool voto_valido = false;
	cout << "\nPRESIDENTE:\n";

	cout << "Deseja votar em branco?\n1)Sim\n2)Não\nDigite sua opção: ";
	while(1){
		int voto_branco=0, retorno;
		retorno = scanf("%d", &voto_branco);
		if(retorno){
			if(voto_branco == 1){
				cout << "Voto em branco.\n\n";
				voto_valido = true;
				voto = -2;
				break;
			}
			else if(voto_branco == 2){
				break;		
			}
			else{
				cout << "Valor inválido, digite novamente!\n1)Sim\n2)Não\nDigite sua opção: ";
			}
		}
		else{
			cout << "Valor inválido, digite novamente!\n1)Sim\n2)Não\nDigite sua opção: ";
			limpa_buffer();
		}
	}
	if(voto_valido){
		cout << "Deseja confirmar o voto?\n1)Confirmar\n2)Cancelar\nDigite sua opção: ";
		while(1){
			int confirmacao, retorno;
			retorno = scanf("%d", &confirmacao);
			if(retorno){
				if(confirmacao == 1){
					cout << "Voto confirmado.\n\n";
					break;
				}
				else if(confirmacao == 2){
					voto_valido=false;
					break;		
				}
				else{
					cout << "Valor inválido, digite novamente!\n1)Confirmar\n2)Cancelar\nDigite sua opção: ";
				}
			}
			else{
				cout << "Valor inválido, digite novamente!\n1)Confirmar\n2)Cancelar\nDigite sua opção: ";
				limpa_buffer();
			}
		}
	}

	if(!voto_valido){
		while(1){
			cout << "Insira o código do candidato: ";
			int numero_do_candidato, retorno;
			retorno = scanf("%d", &numero_do_candidato);
			if(retorno&&numero_do_candidato<100&&numero_do_candidato>9){
				int posicao = localizador_de_candidato(numero_do_candidato, 1);
				if(posicao==-1){
					cout << "Candidato não encontrado.\n\nDeseja votar nulo?\n1)Sim\n2)Não\nDigite sua opção: ";
					while(1){
						int voto_nulo;
						retorno = scanf("%d", &voto_nulo);
						if(retorno){
							if(voto_nulo == 1){
								voto_valido = true;
								break;
							}
							else if(voto_nulo == 2){
								break;		
							}
							else{
								cout << "Valor inválido, digite novamente!\n1)Sim\n2)Não\nDigite sua opção: ";
							}
						}
						else{
							cout << "Valor inválido, digite novamente!\n1)Sim\n2)Não\nDigite sua opção: ";
							limpa_buffer();
						}
					}		
				}
				else{
					voto_valido = true;
				}
				bool voto_confirmado = false;
				if(voto_valido){
					voto = posicao;
					if(voto >= 0){
						presidente[voto].imprime_dados();
					}
					else{
						cout << "Voto nulo\n\n";
					}
					cout << "Deseja confirmar o voto?\n1)Confirmar\n2)Cancelar\nDigite sua opção: ";
					while(1){
						int confirmacao;
						retorno = scanf("%d", &confirmacao);
						if(retorno){
							if(confirmacao == 1){
								cout << "Voto confirmado.\n\n";
								voto_confirmado = true;
								break;
							}
							else if(confirmacao == 2){
								break;		
							}
							else{
								cout << "Valor inválido, digite novamente!\n1)Confirmar\n2)Cancelar\nDigite sua opção: ";
							}
						}
						else{
							cout << "Valor inválido, digite novamente!\n1)Confirmar\n2)Cancelar\nDigite sua opção: ";
							limpa_buffer();
						}
					}
					if(voto_confirmado) break;						
				}
			}
			else{
				cout << "Código inválido.\nO código deve conter 2 caracteres numéricos, com valores entre 1 e 9.\n\n";
				limpa_buffer();
			}
		}
	}
	return voto;
}
