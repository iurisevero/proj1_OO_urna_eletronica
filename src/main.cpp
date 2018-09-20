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
int voto_deputado_distrital(); 
int voto_deputado_federal(); 
int voto_senador(int senador); 
int voto_governador(); 
int voto_presidente(); 

int main(){

	//Deputado Distrital
	int voto = voto_deputado_distrital();
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

int voto_deputado_distrital(){
	int voto;
	bool voto_valido = false;
	cout << "DEPUTADO DISTRITAL:\n\n"

	cout << "Deseja votar em branco?\n1)Sim\n2)Não\nDigite sua opção: ";
	while(1){
		int voto_branco=0, retorno;
		retorno = scanf("%d", &voto_branco);
		if(retorno){
			if(voto_branco == 1){
				"Voto em branco.\n";
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
			cout << "Valor inválido, digite novamente!\n1)Sim\n2)Não\nDigite sua opção: "
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
								"Voto anulado.\n";
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
						}
					}		
				}
				else{
					voto_valido = true;
				}

				if(voto_valido){
					voto = posicao;
					break;
				}
			}
			else{
				cout << "Código inválido.\nO código deve conter 5 caracteres numéricos, com valores entre 1 e 9.\n";
			}
		}
	}

	return voto;
}

int voto_deputado_federal(){
	int voto;
	bool voto_valido = false;
	cout << "DEPUTADO FEDERAL:\n\n"

	cout << "Deseja votar em branco?\n1)Sim\n2)Não\nDigite sua opção: ";
	while(1){
		int voto_branco=0, retorno;
		retorno = scanf("%d", &voto_branco);
		if(retorno){
			if(voto_branco == 1){
				"Voto em branco.\n";
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
			cout << "Valor inválido, digite novamente!\n1)Sim\n2)Não\nDigite sua opção: "
		}
	}

	if(!voto_valido){
		while(1){
			cout << "Insira o código do candidato: ";
			int numero_do_candidato, retorno;
			retorno = scanf("%d", &numero_do_candidato);
			if(retorno&&numero_do_candidato<10000&&numero_do_candidato>999){
				int posicao = localizador_de_candidato(numero_do_candidato, 8);
				if(posicao==-1){
					cout << "Candidato não encontrado.\nDeseja votar nulo?\n1)Sim\n2)Não\nDigite sua opção: ";
					while(1){
						int voto_nulo;
						retorno = scanf("%d", &voto_nulo);
						if(retorno){
							if(voto_nulo == 1){
								"Voto anulado.\n";
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
						}
					}		
				}
				else{
					voto_valido = true;
				}

				if(voto_valido){
					voto = posicao;
					break;
				}
			}
			else{
				cout << "Código inválido.\nO código deve conter 4 caracteres numéricos, com valores entre 1 e 9.\n";
			}
		}
	}

	return voto;
}

int voto_senador(int senador){
	int voto;
	bool voto_valido = false;
	printf("SENADOR - %dº vaga:\n\n", senador);

	cout << "Deseja votar em branco?\n1)Sim\n2)Não\nDigite sua opção: ";
	while(1){
		int voto_branco=0, retorno;
		retorno = scanf("%d", &voto_branco);
		if(retorno){
			if(voto_branco == 1){
				"Voto em branco.\n";
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
			cout << "Valor inválido, digite novamente!\n1)Sim\n2)Não\nDigite sua opção: "
		}
	}

	if(!voto_valido){
		while(1){
			cout << "Insira o código do candidato: ";
			int numero_do_candidato, retorno;
			retorno = scanf("%d", &numero_do_candidato);
			if(retorno&&numero_do_candidato<1000&&numero_do_candidato>99){
				int posicao = localizador_de_candidato(numero_do_candidato, 8);
				if(posicao==-1){
					cout << "Candidato não encontrado.\nDeseja votar nulo?\n1)Sim\n2)Não\nDigite sua opção: ";
					while(1){
						int voto_nulo;
						retorno = scanf("%d", &voto_nulo);
						if(retorno){
							if(voto_nulo == 1){
								"Voto anulado.\n";
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
						}
					}		
				}
				else{
					voto_valido = true;
				}

				if(voto_valido){
					voto = posicao;
					break;
				}
			}
			else{
				cout << "Código inválido.\nO código deve conter 3 caracteres numéricos, com valores entre 1 e 9.\n";
			}
		}
	}

	return voto;
}

int voto_governador(){
	int voto;
	bool voto_valido = false;
	cout << "GOVERNADOR:\n\n"

	cout << "Deseja votar em branco?\n1)Sim\n2)Não\nDigite sua opção: ";
	while(1){
		int voto_branco=0, retorno;
		retorno = scanf("%d", &voto_branco);
		if(retorno){
			if(voto_branco == 1){
				"Voto em branco.\n";
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
			cout << "Valor inválido, digite novamente!\n1)Sim\n2)Não\nDigite sua opção: "
		}
	}

	if(!voto_valido){
		while(1){
			cout << "Insira o código do candidato: ";
			int numero_do_candidato, retorno;
			retorno = scanf("%d", &numero_do_candidato);
			if(retorno&&numero_do_candidato<100&&numero_do_candidato>9){
				int posicao = localizador_de_candidato(numero_do_candidato, 8);
				if(posicao==-1){
					cout << "Candidato não encontrado.\nDeseja votar nulo?\n1)Sim\n2)Não\nDigite sua opção: ";
					while(1){
						int voto_nulo;
						retorno = scanf("%d", &voto_nulo);
						if(retorno){
							if(voto_nulo == 1){
								"Voto anulado.\n";
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
						}
					}		
				}
				else{
					voto_valido = true;
				}

				if(voto_valido){
					voto = posicao;
					break;
				}
			}
			else{
				cout << "Código inválido.\nO código deve conter 2 caracteres numéricos, com valores entre 1 e 9.\n";
			}
		}
	}

	return voto;
}

int voto_presidente(){
	int voto;
	bool voto_valido = false;
	cout << "PRESIDENTE:\n\n"

	cout << "Deseja votar em branco?\n1)Sim\n2)Não\nDigite sua opção: ";
	while(1){
		int voto_branco=0, retorno;
		retorno = scanf("%d", &voto_branco);
		if(retorno){
			if(voto_branco == 1){
				"Voto em branco.\n";
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
			cout << "Valor inválido, digite novamente!\n1)Sim\n2)Não\nDigite sua opção: "
		}
	}

	if(!voto_valido){
		while(1){
			cout << "Insira o código do candidato: ";
			int numero_do_candidato, retorno;
			retorno = scanf("%d", &numero_do_candidato);
			if(retorno&&numero_do_candidato<100&&numero_do_candidato>9){
				int posicao = localizador_de_candidato(numero_do_candidato, 8);
				if(posicao==-1){
					cout << "Candidato não encontrado.\nDeseja votar nulo?\n1)Sim\n2)Não\nDigite sua opção: ";
					while(1){
						int voto_nulo;
						retorno = scanf("%d", &voto_nulo);
						if(retorno){
							if(voto_nulo == 1){
								"Voto anulado.\n";
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
						}
					}		
				}
				else{
					voto_valido = true;
				}

				if(voto_valido){
					voto = posicao;
					break;
				}
			}
			else{
				cout << "Código inválido.\nO código deve conter 2 caracteres numéricos, com valores entre 1 e 9.\n";
			}
		}
	}

	return voto;
}