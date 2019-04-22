

#include <GL/glut.h>
#include <stdio.h>
#include <string.h>
#include "tinyxml/tinyxml.h"


float larguraJanela, alturaJanela, tamanhoQuadrado;
int corJanelaR, corJanelaG, corJanelaB, corQuadradoR, corQuadradoG, corQuadradoB;
char tituloJanela[300];


void parse(char *nomeArquivo){


	TiXmlDocument arquivo; 
	if(arquivo.LoadFile(nomeArquivo)){

		TiXmlElement *aplicacao = arquivo.FirstChildElement();
		

		//Lendo do XML Info da Janala
		TiXmlElement *janela = aplicacao->FirstChildElement("janela");

		//Largura
		char *larguraInfo = (char*)janela->FirstChildElement("largura")->GetText();
		larguraJanela=atoi(larguraInfo);

		//Altura
		char *alturaInfo = (char*)janela->FirstChildElement("altura")->GetText();
		alturaJanela=atoi(alturaInfo);

		//Cor de Fundo
		janela->FirstChildElement("fundo")->QueryIntAttribute("corR", &corJanelaR);
		janela->FirstChildElement("fundo")->QueryIntAttribute("corG", &corJanelaG);
		janela->FirstChildElement("fundo")->QueryIntAttribute("corB", &corJanelaB);

		//Titulo
		char *tituloInfo = (char*)janela->FirstChildElement("titulo")->GetText();
		strcpy(tituloJanela, tituloInfo);		

		//Lendo do XML Info do Quadrado
		TiXmlElement *quadrado = aplicacao->FirstChildElement("quadrado");

		//Tamanho
		quadrado->QueryFloatAttribute("tamanho", &tamanhoQuadrado);

		//Cor do Quadrado
		quadrado->QueryIntAttribute("corR", &corQuadradoR);
		quadrado->QueryIntAttribute("corG", &corQuadradoG);
		quadrado->QueryIntAttribute("corB", &corQuadradoB);



	}else{
		printf("Falha na leitura do arquivo!!\n");
	}


	return; 

}


int main (int argc, char *argv[]){

	if(argc < 2)
  	{
		printf("\nErro: Arquivo nao enderecado !!!\n\n");
        	exit(1);
	}

	parse(argv[1]);

	printf("\n\ntitulo: %s largura %f altura %f corR %d corB %d corG %d \n", tituloJanela, larguraJanela, alturaJanela, corJanelaR, corJanelaB, corJanelaB);
	printf("Quadrado- Tamanho %f corR %d corG %d corB %d \n", tamanhoQuadrado, corQuadradoR, corQuadradoG,corQuadradoB);

	return 0;
}