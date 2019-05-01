#include <GL/glut.h>
#include "tinyxml/tinyxml.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <iostream>
#include <sstream>

#include "globais.h"
#include "parse.h"
#include "formas.h"
#include "arena.h"
#include "inimigo.h"
#include "carro.h"
#include "controles.h"
#include "mensagens.h"



char nomeArquivo[50];



void Desenha(){

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glClear(GL_COLOR_BUFFER_BIT);

	keyOperations();

  if(jogo == true){
    desenhaArena();
    desenhaInimigo();
    desenhaCarro();
    mensagemTela(voltas, contVida);
  }else{
    if(venceu == true){
      mensagemVitoria();

    }else{
      mensagemGameOver();
    }

  }

  glutSwapBuffers();
  glFlush();

}

void Inicializa(){

  	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    inicializaInimigo();

    //Parse - Leitura de arquivos
    //Arena

    //Largada
    char cor[15];
    parseLargada(nomeArquivo, &xLargada, &yLargada, &wLargada, &hLargada, cor);
    selecionaCor(cor, &rLargada, &gLargada, &bLargada);

    char id[50];
    strcpy(id,"Pista");

    //Circulo Maior da Arena
    parse(nomeArquivo, id,1, &cxCirculo1, &cyCirculo1, &raioCirculo1, &rCirculo1, &gCirculo1, &bCirculo1);
   // printf("%s %d %d %f\n", id, cxCirculo1, cyCirculo1, raioCirculo1);

    //Circulo Menor da Arena
    parse(nomeArquivo, id,2, &cxCirculo2, &cyCirculo2, &raioCirculo2, &rCirculo2, &gCirculo2, &bCirculo2);
    //printf("%s %d %d %f\n", id, cxCirculo2, cyCirculo2, raioCirculo2);

    inicializaArena();

    //Inimigo
    strcpy(id,"Inimigo");

    for (int i = 0; i < quantidadeInimigos; ++i)
    {
      parse(nomeArquivo, id,(i+1), &vetorInimigo[i].cx, &vetorInimigo[i].cy, &vetorInimigo[i].raio, &vetorInimigo[i].r, &vetorInimigo[i].g, &vetorInimigo[i].b);
    }

    //Jogador
    strcpy(id,"Jogador");
    int auxX,auxY;
    parse(nomeArquivo, id,1, &auxX, &auxY, &raioJodador, &rJogador, &gJogador, &bJogador);
    cx=(float)auxX;
    cy=(float)auxY;

	  inicializaCarro();


}

// Callback chamada quando o tamanho da janela é alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (w <= h)
      gluOrtho2D(cxCirculo1-raioCirculo1 ,cxCirculo1+raioCirculo1, cyCirculo1-raioCirculo1, cyCirculo1+raioCirculo1*h/w);
    else
      gluOrtho2D(cxCirculo1-raioCirculo1 ,cxCirculo1+raioCirculo1*w/h, cyCirculo1-raioCirculo1, cyCirculo1+raioCirculo1);

}

// Programa principal
int main(int argc, char *argv[])
{
  if(argv[1]!=NULL){
    strcat(argv[1], "config.xml");
    parseXML(argv[1], nomeArquivo, &velTiro, &freqTiro, &velInimigo, &velTiroInimigo);
  }else{
    char caminhoArquivo[50];
    strcpy(caminhoArquivo, "config.xml");
    parseXML(caminhoArquivo, nomeArquivo, &velTiro, &freqTiro, &velInimigo, &velTiroInimigo);
  }

    glutInit(&argc,argv);
    Inicializa();
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(10,10);
    glutCreateWindow("Divertimento Computacional 4");
    glutDisplayFunc(Desenha);
    glutReshapeFunc(AlteraTamanhoJanela);
    glutKeyboardFunc(keyPressed);
    glutKeyboardUpFunc(keyUp);
    glutMouseFunc(mouse);
    glutPassiveMotionFunc(passiveMotion);
    glutTimerFunc(50, Timer, 1);
    glutTimerFunc(7000,Timer, 2);
    glutTimerFunc(1500,Timer, 3);
    glutMainLoop();


}
