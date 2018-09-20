#ifndef ELEITOR_HPP
#define ELEITOR_HPP

#include <bits/stdc++.h>
using namespace std;

class Eleitor{
private:
	string nome_do_eleitor;
	int presidente;
	int governador;
	int senador;
	int deputado_federal;
	int deputado_distrial;

public:
	Eleitor();
	Eleitor(string nome_do_eleitor);
	Eleitor(string nome_do_eleitor, int presidente, int governador, int senador, int deputado_federal, int deputado_distrial);

	~Eleitor();

	//Métodos de Inserção
	void set_nome_do_eleitor(string nome_do_eleitor);
	void set_presidente(int presidente);
	void set_governador(int governador);
	void set_senador(int senador);
	void set_deputado_federal(int deputado_federal);
	void set_deputado_distrital(int deputado_distrial);

	//Métodos de Visualização
	string get_nome_do_eleitor();
	int get_presidente();
	int get_governador();
	int get_senador();
	int get_deputado_federal();
	int get_deputado_distrital();

	bool operator<(Eleitor &p);


};

#endif