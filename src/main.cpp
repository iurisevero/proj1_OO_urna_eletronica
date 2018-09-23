#include <bits/stdc++.h>
#include "binary_search.hpp"
#include "candidato.hpp"
#include "presidente.hpp"
#include "governador.hpp"
#include "senador.hpp"
#include "deputado_distrital.hpp"
#include "deputado_federal.hpp"
#include "eleitor.hpp"

using namespace std;

vector<Candidato> candidatos;
vector<Presidente> presidente;
vector<Governador> governador;
vector<Senador> senador;
vector<Deputado_Federal> deputado_federal;
vector<Deputado_Distrital> deputado_distrital;
vector<Eleitor> eleitores;

void organizador_de_candidato(Candidato candidato_atual);
void organizador_de_sub_candidato(Candidato candidato_atual);
void imprime_dados_do_eleitor(Eleitor eleitor);
void limpa_buffer();
int localizador_de_candidato(int numero_do_candidato, int codigo_do_cargo);
int voto_deputado_distrital(); 
int voto_deputado_federal(); 
int voto_senador(int senador, int posicao_senador_1); 
int voto_governador();
int voto_presidente(); 

int main(){
	vector<Candidato> teste_candidatos;
	Candidato candidato1;
	candidato1.set_nome_ue("DF");
	candidato1.set_codigo_do_cargo(1);
	candidato1.set_descricao_do_cargo("Presidente");
	candidato1.set_numero_do_candidato(11);
	candidato1.set_nome_do_candidato("AAA");
	candidato1.set_apelido_do_candidato("A");
	candidato1.set_numero_do_partido(11);
	candidato1.set_sigla_do_partido("AA");
	candidato1.set_nome_do_partido("A A");
	teste_candidatos.push_back(candidato1);
	Candidato candidato2;
	candidato2.set_nome_ue("DF");
	candidato2.set_codigo_do_cargo(2);
	candidato2.set_descricao_do_cargo("Vice Presidente");
	candidato2.set_numero_do_candidato(11);
	candidato2.set_nome_do_candidato("aaa");
	candidato2.set_apelido_do_candidato("a");
	candidato2.set_numero_do_partido(11);
	candidato2.set_sigla_do_partido("AA");
	candidato2.set_nome_do_partido("A A");
	teste_candidatos.push_back(candidato2);
	Candidato candidato3;
	candidato3.set_nome_ue("DF");
	candidato3.set_codigo_do_cargo(3);
	candidato3.set_descricao_do_cargo("Governo");
	candidato3.set_numero_do_candidato(11);
	candidato3.set_nome_do_candidato("BBB");
	candidato3.set_apelido_do_candidato("B");
	candidato3.set_numero_do_partido(11);
	candidato3.set_sigla_do_partido("BB");
	candidato3.set_nome_do_partido("B B");
	teste_candidatos.push_back(candidato3);
	Candidato candidato4;
	candidato4.set_nome_ue("DF");
	candidato4.set_codigo_do_cargo(4);
	candidato4.set_descricao_do_cargo("Governo");
	candidato4.set_numero_do_candidato(11);
	candidato4.set_nome_do_candidato("bbb");
	candidato4.set_apelido_do_candidato("b");
	candidato4.set_numero_do_partido(11);
	candidato4.set_sigla_do_partido("BB");
	candidato4.set_nome_do_partido("B B");
	teste_candidatos.push_back(candidato4);
	Candidato candidato5;
	candidato5.set_nome_ue("DF");
	candidato5.set_codigo_do_cargo(5);
	candidato5.set_descricao_do_cargo("Senador");
	candidato5.set_numero_do_candidato(111);
	candidato5.set_nome_do_candidato("CCC");
	candidato5.set_apelido_do_candidato("C");
	candidato5.set_numero_do_partido(11);
	candidato5.set_sigla_do_partido("CC");
	candidato5.set_nome_do_partido("C C");
	teste_candidatos.push_back(candidato5);
	Candidato candidato6;
	candidato6.set_nome_ue("DF");
	candidato6.set_codigo_do_cargo(6);
	candidato6.set_descricao_do_cargo("Deputado");
	candidato6.set_numero_do_candidato(1111);
	candidato6.set_nome_do_candidato("DDD");
	candidato6.set_apelido_do_candidato("D");
	candidato6.set_numero_do_partido(11);
	candidato6.set_sigla_do_partido("DD");
	candidato6.set_nome_do_partido("D D");
	teste_candidatos.push_back(candidato6);
	Candidato candidato7;
	candidato7.set_nome_ue("DF");
	candidato7.set_codigo_do_cargo(8);
	candidato7.set_descricao_do_cargo("Deputado dist");
	candidato7.set_numero_do_candidato(11111);
	candidato7.set_nome_do_candidato("EEE");
	candidato7.set_apelido_do_candidato("E");
	candidato7.set_numero_do_partido(11);
	candidato7.set_sigla_do_partido("EE");
	candidato7.set_nome_do_partido("E E");
	teste_candidatos.push_back(candidato7);
	Candidato candidato8;
	candidato8.set_nome_ue("DF");
	candidato8.set_codigo_do_cargo(9);
	candidato8.set_descricao_do_cargo("sup1");
	candidato8.set_numero_do_candidato(111);
	candidato8.set_nome_do_candidato("FFF");
	candidato8.set_apelido_do_candidato("F");
	candidato8.set_numero_do_partido(11);
	candidato8.set_sigla_do_partido("FF");
	candidato8.set_nome_do_partido("F F");
	teste_candidatos.push_back(candidato8);
	Candidato candidato9;
	candidato9.set_nome_ue("DF");
	candidato9.set_codigo_do_cargo(10);
	candidato9.set_descricao_do_cargo("SUP2");
	candidato9.set_numero_do_candidato(111);
	candidato9.set_nome_do_candidato("GGG");
	candidato9.set_apelido_do_candidato("G");
	candidato9.set_numero_do_partido(11);
	candidato9.set_sigla_do_partido("GG");
	candidato9.set_nome_do_partido("G G");
	teste_candidatos.push_back(candidato9);

	for(int i=0; i<teste_candidatos.size(); ++i)
		organizador_de_candidato(teste_candidatos[i]);
	for(int i=0; i<candidatos.size(); ++i)
		organizador_de_sub_candidato(candidatos[i]);

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
		eleitores.push_back(eleitor_atual);
		limpa_buffer();
	}

	for(int i=0; i<N; ++i){
		imprime_dados_do_eleitor(eleitores[i]);
	}
}

void organizador_de_candidato(Candidato candidato_atual){
	switch(candidato_atual.get_codigo_do_cargo()){
		case 1:{
			Presidente presidente_atual = Presidente(candidato_atual.get_nome_ue(), candidato_atual.get_codigo_do_cargo(), "Presidente", candidato_atual.get_numero_do_candidato(), candidato_atual.get_nome_do_candidato(), candidato_atual.get_apelido_do_candidato(), candidato_atual.get_numero_do_partido(), candidato_atual.get_sigla_do_partido(), candidato_atual.get_nome_do_partido());
			presidente.push_back(presidente_atual);
			break;
		}
		case 2:
			candidatos.push_back(candidato_atual);
			break;
		case 3:{
			Governador governador_atual = Governador(candidato_atual.get_nome_ue(), candidato_atual.get_codigo_do_cargo(), "Governador", candidato_atual.get_numero_do_candidato(),
				candidato_atual.get_nome_do_candidato(), candidato_atual.get_apelido_do_candidato(), candidato_atual.get_numero_do_partido(), candidato_atual.get_sigla_do_partido(), candidato_atual.get_nome_do_partido());
			governador.push_back(governador_atual);
			break;
		}
		case 4:
			candidatos.push_back(candidato_atual);
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
			candidatos.push_back(candidato_atual);
			break;
		case 10:
			candidatos.push_back(candidato_atual);
			break;
		default:
			cout << "Cargo inválido\n";
			break;
	}
}

void organizador_de_sub_candidato(Candidato candidato_atual){
	switch(candidato_atual.get_codigo_do_cargo()){
		case 2:{
			int posicao_presidente = binary_search_presidente(presidente.size(), candidato_atual.get_numero_do_candidato(), presidente);
			presidente[posicao_presidente].set_nome_do_vice(candidato_atual.get_nome_do_candidato());
			presidente[posicao_presidente].set_apelido_do_vice(candidato_atual.get_apelido_do_candidato());
			presidente[posicao_presidente].set_numero_do_partido_do_vice(candidato_atual.get_numero_do_partido());
			presidente[posicao_presidente].set_sigla_do_partido_do_vice(candidato_atual.get_sigla_do_partido());
			presidente[posicao_presidente].set_nome_do_partido_do_vice(candidato_atual.get_nome_do_partido());
			break;
		}
		case 4:{
			int posicao_governador = binary_search_governador(governador.size(), candidato_atual.get_numero_do_candidato(), governador);
			governador[posicao_governador].set_nome_do_vice(candidato_atual.get_nome_do_candidato());
			governador[posicao_governador].set_apelido_do_vice(candidato_atual.get_apelido_do_candidato());
			governador[posicao_governador].set_numero_do_partido_do_vice(candidato_atual.get_numero_do_partido());
			governador[posicao_governador].set_sigla_do_partido_do_vice(candidato_atual.get_sigla_do_partido());
			governador[posicao_governador].set_nome_do_partido_do_vice(candidato_atual.get_nome_do_partido());
			break;
		}
		case 9:{
			int posicao_senador_1 = binary_search_senador(senador.size(), candidato_atual.get_numero_do_candidato(), senador);
			senador[posicao_senador_1].set_nome_do_suplente_1(candidato_atual.get_nome_do_candidato());
			senador[posicao_senador_1].set_apelido_do_suplente_1(candidato_atual.get_apelido_do_candidato());
			break;
		}
		case 10:{
			int posicao_senador_2 = binary_search_senador(senador.size(), candidato_atual.get_numero_do_candidato(), senador);
			senador[posicao_senador_2].set_nome_do_suplente_2(candidato_atual.get_nome_do_candidato());
			senador[posicao_senador_2].set_apelido_do_suplente_2(candidato_atual.get_apelido_do_candidato());
			break;
		}
		default:
			cout << "Cargo inválido\n";
			break;
	}
}

void imprime_dados_do_eleitor(Eleitor eleitor){
	cout << "Eleitor: " << eleitor.get_nome_do_eleitor() << endl;
	cout << "	Presidente: ";
	switch(eleitor.get_presidente()){
		case -1:
			cout << "Nulo\n";
			break;
		case -2:
			cout << "Branco\n";
			break;
		default:
			cout << presidente[eleitor.get_presidente()].get_nome_do_candidato() << endl;
			break;
	}
	cout << "	Governador: ";
	switch(eleitor.get_governador()){
		case -1:
			cout << "Nulo\n";
			break;
		case -2:
			cout << "Branco\n";
			break;
		default:
			cout << governador[eleitor.get_governador()].get_nome_do_candidato() << endl;
			break;
	}
	cout << "	Senador 1: ";
	switch(eleitor.get_senador_1()){
		case -1:
			cout << "Nulo\n";
			break;
		case -2:
			cout << "Branco\n";
			break;
		default:
			cout << senador[eleitor.get_senador_1()].get_nome_do_candidato() << endl;
			break;
	}
	cout << "	Senador 2 ";
	switch(eleitor.get_senador_2()){
		case -1:
			cout << "Nulo\n";
			break;
		case -2:
			cout << "Branco\n";
			break;
		default:
			cout << senador[eleitor.get_senador_2()].get_nome_do_candidato() << endl;
			break;
	}
	cout << "	Deputado Federal: ";
	switch(eleitor.get_deputado_federal()){
		case -1:
			cout << "Nulo\n";
			break;
		case -2:
			cout << "Branco\n";
			break;
		default:
			cout << deputado_federal[eleitor.get_deputado_federal()].get_nome_do_candidato() << endl;
			break;
	}
	cout << "	Deputado Distrital: ";
	switch(eleitor.get_deputado_distrital()){
		case -1:
			cout << "Nulo\n";
			break;
		case -2:
			cout << "Branco\n";
			break;
		default:
			cout << deputado_distrital[eleitor.get_deputado_distrital()].get_nome_do_candidato() << endl;
			break;
	}
	cout << endl;
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
				cout << "Voto em branco.\n";
				voto_valido = true;
				voto = -2;
				break;
			}
			else if(voto_branco == 2){
				break;		
			}
			else{
				cout << "Valor inválido, digite novamente!\n1)Sim\n2)Não\nDigite sua opção: ";
				void limpa_buffer();
			}
		}
		else{
			cout << "Valor inválido, digite novamente!\n1)Sim\n2)Não\nDigite sua opção: ";
		}
	}

	if(!voto_valido){
		while(1){
			cout << "Insira o código do candidato: ";
			int numero_do_candidato, retorno;
			retorno = scanf("%d", &numero_do_candidato);
			if(retorno&&numero_do_candidato<100000&&numero_do_candidato>9999){
				int posicao = localizador_de_candidato(numero_do_candidato, 8);
				if(posicao==-1){
					cout << "Candidato não encontrado.\nDeseja votar nulo?\n1)Sim\n2)Não\nDigite sua opção: ";
					while(1){
						int voto_nulo;
						retorno = scanf("%d", &voto_nulo);
						if(retorno){
							if(voto_nulo == 1){
								cout << "Voto anulado.\n";
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
							void limpa_buffer();
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
						deputado_distrital[voto].imprime_dados();
					}
					else{
						cout << "Voto nulo\n";
					}
					cout << "Deseja confirmar o voto?\n1)Sim\n2)Não\nDigite sua opção: ";
					while(1){
						int confirmacao;
						retorno = scanf("%d", &confirmacao);
						if(retorno){
							if(confirmacao == 1){
								cout << "Voto confirmado.\n";
								voto_confirmado = true;
								break;
							}
							else if(confirmacao == 2){
								break;		
							}
							else{
								cout << "Valor inválido, digite novamente!\n1)Sim\n2)Não\nDigite sua opção: ";
							}
						}
						else{
							cout << "Valor inválido, digite novamente!\n1)Sim\n2)Não\nDigite sua opção: ";
						}
					}	

					if(voto_confirmado) break;					
				}
			}
			else{
				cout << "Código inválido.\nO código deve conter 5 caracteres numéricos, com valores entre 1 e 9.\n";
				void limpa_buffer();
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
				cout << "Voto em branco.\n";
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
			void limpa_buffer();
		}
	}

	if(!voto_valido){
		while(1){
			cout << "Insira o código do candidato: ";
			int numero_do_candidato, retorno;
			retorno = scanf("%d", &numero_do_candidato);
			if(retorno&&numero_do_candidato<10000&&numero_do_candidato>999){
				int posicao = localizador_de_candidato(numero_do_candidato, 6);
				if(posicao==-1){
					cout << "Candidato não encontrado.\nDeseja votar nulo?\n1)Sim\n2)Não\nDigite sua opção: ";
					while(1){
						int voto_nulo;
						retorno = scanf("%d", &voto_nulo);
						if(retorno){
							if(voto_nulo == 1){
								cout << "Voto anulado.\n";
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
							void limpa_buffer();
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
						deputado_federal[voto].imprime_dados();
					}
					else{
						cout << "Voto nulo\n";
					}
					cout << "Deseja confirmar o voto?\n1)Sim\n2)Não\nDigite sua opção: ";
					while(1){
						int confirmacao;
						retorno = scanf("%d", &confirmacao);
						if(retorno){
							if(confirmacao == 1){
								cout << "Voto confirmado.\n";
								voto_confirmado = true;
								break;
							}
							else if(confirmacao == 2){
								break;		
							}
							else{
								cout << "Valor inválido, digite novamente!\n1)Sim\n2)Não\nDigite sua opção: ";
							}
						}
						else{
							cout << "Valor inválido, digite novamente!\n1)Sim\n2)Não\nDigite sua opção: ";
							void limpa_buffer();
						}
					}
					if(voto_confirmado) break;						
				}
			}
			else{
				cout << "Código inválido.\nO código deve conter 4 caracteres numéricos, com valores entre 1 e 9.\n";
				void limpa_buffer();
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
				cout << "Voto em branco.\n";
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

	if(!voto_valido){
		while(1){
			cout << "Insira o código do candidato: ";
			int numero_do_candidato, retorno;
			retorno = scanf("%d", &numero_do_candidato);
			if(retorno&&numero_do_candidato<1000&&numero_do_candidato>99){
				int posicao = localizador_de_candidato(numero_do_candidato, 5);
				if(posicao==-1||(posicao==posicao_senador_1&&senador_votado==2)){
					cout << "Candidato não encontrado/Candidato já selecionado.\nDeseja votar nulo?\n1)Sim\n2)Não\nDigite sua opção: ";
					while(1){
						int voto_nulo;
						retorno = scanf("%d", &voto_nulo);
						if(retorno){
							if(voto_nulo == 1){
								cout << "Voto anulado.\n";
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
						cout << "Voto nulo\n";
					}
					cout << "Deseja confirmar o voto?\n1)Sim\n2)Não\nDigite sua opção: ";
					while(1){
						int confirmacao;
						retorno = scanf("%d", &confirmacao);
						if(retorno){
							if(confirmacao == 1){
								cout << "Voto confirmado.\n";
								voto_confirmado = true;
								break;
							}
							else if(confirmacao == 2){
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
					if(voto_confirmado) break;						
				}
			}
			else{
				cout << "Código inválido.\nO código deve conter 3 caracteres numéricos, com valores entre 1 e 9.\n";
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
				cout << "Voto em branco.\n";
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

	if(!voto_valido){
		while(1){
			cout << "Insira o código do candidato: ";
			int numero_do_candidato, retorno;
			retorno = scanf("%d", &numero_do_candidato);
			if(retorno&&numero_do_candidato<100&&numero_do_candidato>9){
				int posicao = localizador_de_candidato(numero_do_candidato, 3);
				if(posicao==-1){
					cout << "Candidato não encontrado.\nDeseja votar nulo?\n1)Sim\n2)Não\nDigite sua opção: ";
					while(1){
						int voto_nulo;
						retorno = scanf("%d", &voto_nulo);
						if(retorno){
							if(voto_nulo == 1){
								cout << "Voto anulado.\n";
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
						cout << "Voto nulo\n";
					}
					cout << "Deseja confirmar o voto?\n1)Sim\n2)Não\nDigite sua opção: ";
					while(1){
						int confirmacao;
						retorno = scanf("%d", &confirmacao);
						if(retorno){
							if(confirmacao == 1){
								cout << "Voto confirmado.\n";
								voto_confirmado = true;
								break;
							}
							else if(confirmacao == 2){
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
					if(voto_confirmado) break;						
				}
			}
			else{
				cout << "Código inválido.\nO código deve conter 2 caracteres numéricos, com valores entre 1 e 9.\n";
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
				cout << "Voto em branco.\n";
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

	if(!voto_valido){
		while(1){
			cout << "Insira o código do candidato: ";
			int numero_do_candidato, retorno;
			retorno = scanf("%d", &numero_do_candidato);
			if(retorno&&numero_do_candidato<100&&numero_do_candidato>9){
				int posicao = localizador_de_candidato(numero_do_candidato, 1);
				if(posicao==-1){
					cout << "Candidato não encontrado.\nDeseja votar nulo?\n1)Sim\n2)Não\nDigite sua opção: ";
					while(1){
						int voto_nulo;
						retorno = scanf("%d", &voto_nulo);
						if(retorno){
							if(voto_nulo == 1){
								cout << "Voto anulado.\n";
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
						cout << "Voto nulo\n";
					}
					cout << "Deseja confirmar o voto?\n1)Sim\n2)Não\nDigite sua opção: ";
					while(1){
						int confirmacao;
						retorno = scanf("%d", &confirmacao);
						if(retorno){
							if(confirmacao == 1){
								cout << "Voto confirmado.\n";
								voto_confirmado = true;
								break;
							}
							else if(confirmacao == 2){
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
					if(voto_confirmado) break;						
				}
			}
			else{
				cout << "Código inválido.\nO código deve conter 2 caracteres numéricos, com valores entre 1 e 9.\n";
				limpa_buffer();
			}
		}
	}

	return voto;
}