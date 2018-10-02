# Exercício de Programação 1

Acesse a descrição completa deste exercício na [wiki](https://gitlab.com/oofga/eps_2018_2/ep1/wikis/Descricao)

## Como usar o projeto

* Compile o projeto com o comando:

```sh
make
```

* Execute o projeto com o comando:

```sh
make run
```

* Após a execução serão criados dois arquivos na pasta data:
```sh
dados_dos_eleitores.txt
candidatos_vencedores.txt
```

## Funcionalidades do projeto

Dado um determinado número de eleitores, o projeto armazena o nome e os votos de cada eleitor. Em seguida ele mostra na tela os candidatos com mais votos, o partido com mais voto e também cria dois arquivos, um que armazena os dados da eleição e outro com os dados dos eleitores.

## Bugs e problemas

Em caso de empate na quantidade de votos, o código elege um "vencedor" de acordo com a ordem de armazenamento dos mesmos.

## Referências

* Orientação a Objetos - Introdução, Prof. Renato Coral Sampaio 
* http://www.tse.jus.br/eleicoes/eleicoes-2018/simulador-de-votacao-na-urna-eletronica
* https://pt.stackoverflow.com/questions/328178/contar-quantas-colunas-h%C3%A1-em-um-arquivo-csv-com-c