/*g++ trabalho.cpp -lGL -lGLU -lglut
tinyxml/tinyxml.cpp tinyxml/tinystr.cpp tinyxml/tinyxmlerror.cpp 
tinyxml/tinyxmlparser.cpp
*/
#include <GL/glut.h>
#include <stdio.h>
#include <string.h>
#include "tinyxml/tinyxml.h"


int clickE = 0;
int posX, posY;

//variaveis das configuracoes da aplicacao
float largura, altura, fcorR, fcorG, fcorB, tam, corR, corG, corB;
char tituloJanela[200];
const char *nomeXML;


void movimentoMouse(int x, int y){
	if (clickE == 1){
		posX = x;
		posY = y;
	}
}

void mouseCriaQuad(int botao, int estado, int x, int y){

	if (( botao == GLUT_LEFT_BUTTON) && (estado == GLUT_DOWN)){
		clickE =1;
		posX = x;
		posY = y;
	}

	if ((botao == GLUT_RIGHT_BUTTON) && ( estado == GLUT_DOWN)){
		clickE = 0;
		glClear(GL_COLOR_BUFFER_BIT);
		glFlush();
	}

	//"seta" uma flag para que na proxima iteracao do mainloop() a funcao desenha() e chamada
	//lembrando que a mainloop() tem que saber que o proximo frame sera apresentado com
	//a funcao glutPostRedisplay()
	glutPostRedisplay();

}

void desenha(void){
	
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(corR, corG, corB);

    if (clickE == 1){

    	//glColor3f(0.0, 1.0, 0.0);

		float p = tam/2;

		glBegin(GL_QUADS);
			glVertex2f(posX-p,posY+p);
			glVertex2f(posX+p, posY+p);
	        glVertex2f(posX+p,posY-p);
			glVertex2f(posX-p,posY-p);
	        

		glEnd();
    }

    glutPostRedisplay();
    glFlush();
}

void inicializa(void){
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glMatrixMode(GL_PROJECTION);//especifica qual a matriz atual
	glLoadIdentity();//troca a matrix atual com a identidade
	gluOrtho2D(0.0f, largura, altura, 0.0f); //define uma projecao 2D na matrix (glMatrixMode)
}


void AlteraTamanhoJanela(GLsizei w, GLsizei h){
   // Evita a divisao por zero
   if(h == 0) h = 1;
           
   // Especifica as dimensões da Viewport
   glViewport(0, 0, w, h);

   // Inicializa o sistema de coordenadas
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();

   // Estabelece a janela de seleção (left, right, bottom, top)
   if (w <= h) 
           gluOrtho2D (0.0f, largura, altura*h/w, 0.0f);
   else 
           gluOrtho2D (0.0f, largura*w/h, altura, 0.0f);
}

int parseXML(){

	TiXmlDocument doc;  

	//char nomeXML[200];
	//printf("Insira o nome do arquivo de config XML: ");
	//scanf("%s", nomeXML);
	printf("%s",nomeXML);	
	//verifica se o arquivo foi carregado
	if(!doc.LoadFile(nomeXML)){
		printf("Erro ao carregar o arquivo !\n");
		return 0;
	}

	else{
		//root ira apontar para o elemento raiz do arquivo xml (aplicacao)
		TiXmlElement *root = doc.FirstChildElement();

		//um ponteiro para o elemento janela e outro para quadrado
		TiXmlElement *janela = root->FirstChildElement("janela");
		TiXmlElement *quadrado = root->FirstChildElement("quadrado");

		//defino as variaveis que irei usar para ter as informacoes da aplicacao
			 	

		//pego as atributos e textos necessarios que estao no escopo do elemento janela
		char *larguraText = (char*)janela->FirstChildElement("largura")->GetText();
		char *alturaText = (char*)janela->FirstChildElement("altura")->GetText();
		largura = atoi(larguraText);
		altura = atoi(alturaText);


		janela->FirstChildElement("fundo")->QueryFloatAttribute("corR", &fcorR);
		janela->FirstChildElement("fundo")->QueryFloatAttribute("corG", &fcorG);
		janela->FirstChildElement("fundo")->QueryFloatAttribute("corB", &fcorB);

		TiXmlElement *titulo = janela->FirstChildElement("titulo");
		strcpy(tituloJanela, (char*)titulo->GetText());

		//pego as atributos e textos necessarios que estao no escopo do elemento quadrado
		quadrado->QueryFloatAttribute("tamanho", &tam);
		quadrado->QueryFloatAttribute("corR", &corR);
		quadrado->QueryFloatAttribute("corG", &corG);
		quadrado->QueryFloatAttribute("corB", &corB);
	}
	return 1;
}
