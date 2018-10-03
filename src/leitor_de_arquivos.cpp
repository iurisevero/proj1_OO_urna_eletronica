#include <bits/stdc++.h>
#include "candidato.hpp"
#include "leitor_de_arquivos.hpp"

using namespace std;

vector<Candidato> leitor_de_arquivo_DF(){
	ifstream file("data/consulta_cand_2018_DF.csv");

    if(!file.is_open())
    {
        cout<<"Erro! Não foi possível abrir o arquivo de consulta DF\n";
        throw(1);
    }

    string buffer;
    vector<vector<string> > linhas; 

    while(!file.eof())
    {
        getline(file, buffer); 
        stringstream ss(buffer); 

        vector<string> linha; 
        while (getline(ss, buffer, ';')) { 
            linha.push_back(buffer.substr(1, buffer.size() - 2)); 
        }

        linhas.push_back(linha); 
    }
    vector<string> NM_UE,  DS_CARGO, NM_CANDIDATO, NM_URNA_CANDIDATO, SG_PARTIDO, NM_PARTIDO; 
    vector<int> CD_CARGO, NR_CANDIDATO, NR_PARTIDO, CD_SITUACAO_CANDIDATURA;
    for (size_t i = 1; i < linhas.size(); ++i){
	    for (size_t j = 0; j < linhas[i].size(); ++j){
	       
	    	if (linhas[0][j] == "NM_UE"){ 
	            NM_UE.push_back(linhas[i][j]);
	        }
	        if (linhas[0][j] == "DS_CARGO"){ 
	            DS_CARGO.push_back(linhas[i][j]);
	        }
	        if (linhas[0][j] == "NM_CANDIDATO"){ 
	            NM_CANDIDATO.push_back(linhas[i][j]);
	        }
	        if (linhas[0][j] == "NM_URNA_CANDIDATO"){ 
	            NM_URNA_CANDIDATO.push_back(linhas[i][j]);
	        }
	        if (linhas[0][j] == "SG_PARTIDO"){ 
	            SG_PARTIDO.push_back(linhas[i][j]);
	        }
	        if (linhas[0][j] == "NM_PARTIDO"){ 
	            NM_PARTIDO.push_back(linhas[i][j]);
	        }
	        if (linhas[0][j] == "CD_CARGO"){ 
	            CD_CARGO.push_back(stoi(linhas[i][j]));
	        }
	        if (linhas[0][j] == "NR_CANDIDATO"){ 
	            NR_CANDIDATO.push_back(stoi(linhas[i][j]));
	        }
	        if (linhas[0][j] == "NR_PARTIDO"){ 
	            NR_PARTIDO.push_back(stoi(linhas[i][j]));
	        }
	        if(linhas[0][j] == "CD_SITUACAO_CANDIDATURA"){
	        	CD_SITUACAO_CANDIDATURA.push_back(stoi(linhas[i][j]));
	        }
	    }
   	}

   	vector<Candidato> candidatos;
   	int size = NM_PARTIDO.size();
   	for(int i=0; i<size; ++i){
   		if(CD_SITUACAO_CANDIDATURA[i]==3){
   			continue;
   		}
   		Candidato candidato_analizado = Candidato(NM_UE[i], CD_CARGO[i], DS_CARGO[i], NR_CANDIDATO[i], NM_CANDIDATO[i], NM_URNA_CANDIDATO[i], 
   			NR_PARTIDO[i], SG_PARTIDO[i], NM_PARTIDO[i]);
   		candidatos.push_back(candidato_analizado);
   	}
   	file.close();
    return candidatos;
}

vector<Candidato> leitor_de_arquivo_BR(){
	ifstream file("data/consulta_cand_2018_BR.csv");

    if(!file.is_open())
    {
        cout<<"Erro! Não foi possível abrir o arquivo de consulta BR\n";
        throw(2);
    }

    string buffer;
    vector<vector<string> > linhas; 

    while(!file.eof())
    {
        getline(file, buffer); 
        stringstream ss(buffer); 

        vector<string> linha; 
        while (getline(ss, buffer, ';')) { 
            linha.push_back(buffer.substr(1, buffer.size() - 2));
        }

        linhas.push_back(linha); 
    }
    vector<string> NM_UE,  DS_CARGO, NM_CANDIDATO, NM_URNA_CANDIDATO, SG_PARTIDO, NM_PARTIDO; 
    vector<int> CD_CARGO, NR_CANDIDATO, NR_PARTIDO, CD_SITUACAO_CANDIDATURA;
    for (size_t i = 1; i < linhas.size(); ++i){
	    for (size_t j = 0; j < linhas[i].size(); ++j){
	     
	    	if (linhas[0][j] == "NM_UE"){ 
	            NM_UE.push_back(linhas[i][j]);
	        }
	        if (linhas[0][j] == "DS_CARGO"){ 
	            DS_CARGO.push_back(linhas[i][j]);
	        }
	        if (linhas[0][j] == "NM_CANDIDATO"){ 
	            NM_CANDIDATO.push_back(linhas[i][j]);
	        }
	        if (linhas[0][j] == "NM_URNA_CANDIDATO"){ 
	            NM_URNA_CANDIDATO.push_back(linhas[i][j]);
	        }
	        if (linhas[0][j] == "SG_PARTIDO"){ 
	            SG_PARTIDO.push_back(linhas[i][j]);
	        }
	        if (linhas[0][j] == "NM_PARTIDO"){ 
	            NM_PARTIDO.push_back(linhas[i][j]);
	        }
	        if (linhas[0][j] == "CD_CARGO"){ 
	            CD_CARGO.push_back(stoi(linhas[i][j]));
	        }
	        if (linhas[0][j] == "NR_CANDIDATO"){ 
	            NR_CANDIDATO.push_back(stoi(linhas[i][j]));
	        }
	        if (linhas[0][j] == "NR_PARTIDO"){ 
	            NR_PARTIDO.push_back(stoi(linhas[i][j]));
	        }
	        if(linhas[0][j] == "CD_SITUACAO_CANDIDATURA"){
	        	CD_SITUACAO_CANDIDATURA.push_back(stoi(linhas[i][j]));
	        }
	    }
   	}

   	vector<Candidato> candidatos;
   	int size = NM_PARTIDO.size();
   	for(int i=0; i<size; ++i){
   		if(CD_SITUACAO_CANDIDATURA[i]==3){
   			continue;
   		}
   		Candidato candidato_analizado = Candidato(NM_UE[i], CD_CARGO[i], DS_CARGO[i], NR_CANDIDATO[i], NM_CANDIDATO[i], NM_URNA_CANDIDATO[i], 
   			NR_PARTIDO[i], SG_PARTIDO[i], NM_PARTIDO[i]);
   		candidatos.push_back(candidato_analizado);
   	}
   	file.close();
    return candidatos;
}