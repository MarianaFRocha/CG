#include <GL/glut.h>
#include "tinyxml/tinyxml.h"
#include <stdio.h> 
#include <string.h>    
#include <math.h>
#include <vector>
#include <iostream>


#define PI 3.1415926535898     

int win=500;

//Variaveis do Carro

//Circulo limite do carro - Dados do svg
float raioJodador;
int cxJogador, cyJogador;   

//Desenho do Carro
float corpoLargura, corpoAltura;
float eixoLargura, eixoAltura;
float rodaLargura, rodaAltura, deslocamantoX;
float canhaoLargura, canhaoAltura;
float raioX, raioY; //raio das rodas

//Posicao
int cx,cy, xAnterior; 

//Movimento
int angRoda=0, angCarro=90;
float angCanhao;

//tiro
float velTiro=0.2;

bool teclasEstado[256];
int  passo=5;


int flagCanhao=0, flagTiro=0;

typedef struct Tiro{

  float cxTiro, cyTiro, angTiro;

}Tiro;

std::vector<Tiro> tiros;



void keyPressed (unsigned char tecla, int x, int y) {  

    teclasEstado[tecla] = true; 
    //printf("%c\n", tecla);

}

void keyUp (unsigned char tecla, int x, int y) {  
  
    teclasEstado[tecla] = false;  
} 
           


void keyOperations(){

    int aux;

   // printf(" entrou \n");

    if(teclasEstado['w'] == true && teclasEstado['a'] == true){
          angCarro+=passo;
          
    }
    if(teclasEstado['w'] == true && teclasEstado['d'] == true){

          angCarro-=passo;

      }

    if(teclasEstado['s'] == true && teclasEstado['d'] == true){

          angCarro+=passo;
    }
    if(teclasEstado['s'] == true && teclasEstado['a'] == true){
            angCarro-=passo;
          
          
      }
      if(teclasEstado['w'] == true){
        
          cx+=passo*cos(angCarro*(PI/180));
          cy+=passo*sin(angCarro*(PI/180));

      }
      if(teclasEstado['s'] == true){
        
          cx-=passo*cos(angCarro*(PI/180));
          cy-=passo*sin(angCarro*(PI/180));       

    }


     if(teclasEstado['a'] == true){
       if(angRoda<=45)
            angRoda=angRoda+passo;
     }else{

       if(teclasEstado['d'] == true){
         if(angRoda>=-45)
              angRoda=angRoda-passo;

       }else{
        angRoda=0;
       }
     }

    glutPostRedisplay();

}

void circulo(float raio){


  float angle;
  int i, circle_points = 1000;
  char id[50];
  strcpy(id,"Pista");

  // Desenha um círculo (elipse) preenchido com a cor corrente
  glBegin(GL_POLYGON);

      for(i = 0; i < circle_points; i++) {
          angle = (2*PI*i)/circle_points;
          glVertex2f((raio*cos(angle)),(raio*sin(angle)));
                 }
  glEnd();

  glFlush();

  return;

}

void retangulo(int largura, int altura){


    glBegin(GL_QUADS);

      glVertex2f ( 0, 0); 
      glVertex2f ( largura, 0);
      glVertex2f ( largura, altura);
      glVertex2f ( 0, altura);

    glEnd();

}


void circuferencia(float raioX, float raioY){

    float angle;
    int i, circle_points = 1000;

    // Desenha um círculo (elipse) preenchido com a cor corrente
    glBegin(GL_POLYGON);

        for(i = 0; i < circle_points; i++) {
          angle = (2*PI*i)/circle_points;
          glVertex2f((raioX*cos(angle)),(raioY*sin(angle)));
        }
    glEnd();

    glFlush();

    return;
}

void desenhaEixos(){
  
  //Eixo X Vermelho
  glColor3f (1,0,0);
  glBegin(GL_LINES);
    glVertex3f(0,0,0);
    glVertex3f(win,0,0);
    glVertex3f(0,0,0);
    glVertex3f(-win,0,0);
  glEnd();

  //Eixo Y Vermelho
  glColor3f (0,1,0);
  glBegin(GL_LINES);
    glVertex3f(0,0,0);
    glVertex3f(0,win,0);
    glVertex3f(0,0,0);
    glVertex3f(0,-win,0);
  glEnd();


}

Tiro bala(){

  Tiro t;
  
  t.cxTiro= cx + cos(angCarro*PI/180.0)*(corpoAltura/2) + cos((angCarro+angCanhao)*PI/180.0)*canhaoAltura;
  t.cyTiro= cy + sin(angCarro*PI/180.0)*(corpoAltura/2) + sin((angCarro+angCanhao)*PI/180.0)*canhaoAltura;
  
  t.angTiro = angCarro + angCanhao;
  
  return t;

}



void desenhaTiro(){



  if(tiros.size()>0){
    for(int i = 0; i < tiros.size(); i++){
        glPushMatrix();
        glColor3f(0.2, 0.2, 1.0);
        glTranslatef(tiros[i].cxTiro, tiros[i].cyTiro, 0);
        circulo(corpoAltura/20);

        //If esta dentro da arena
        tiros[i].cxTiro += cos(tiros[i].angTiro*PI/180.0)*passo*velTiro;
        tiros[i].cyTiro += sin(tiros[i].angTiro*PI/180.0)*passo*velTiro;
        //else
        //tiros.pop_back();
        glPopMatrix();

    }

  }
  glutPostRedisplay();
}



void desenhaCarro(void)
{

     keyOperations();
  
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
                              
    glClear(GL_COLOR_BUFFER_BIT);


    desenhaEixos();
    desenhaTiro();

    glPushMatrix();

      glTranslatef(cx,cy,0);
      glRotatef(angCarro,0,0,1);
      glRotatef(-90,0,0,1);

      //eixos das rodas e veiculo
      //direito inferior
      glPushMatrix();
      glColor3f(0.4, 0.4, 1);
      glTranslatef(corpoLargura/2,((2*eixoAltura)-corpoAltura/2),0);
      retangulo(eixoLargura, eixoAltura);
      glPopMatrix();

      //direito superior
      glPushMatrix();
      glColor3f(0.4, 0.4, 1);
      glTranslatef(corpoLargura/2,((corpoAltura/2-(3*eixoAltura))),0);
      retangulo(eixoLargura, eixoAltura);
      glPopMatrix();

      //esquerdo inferior
      glPushMatrix();
      glColor3f(0.4, 0.4, 1);
      glTranslatef(-corpoLargura,((2*eixoAltura)-corpoAltura/2),0);
      retangulo(eixoLargura, eixoAltura);
      glPopMatrix();

      //direito superior
      glPushMatrix();
      glColor3f(0.4, 0.4, 1);
      glTranslatef(-corpoLargura,((corpoAltura/2-(3*eixoAltura))),0);
      retangulo(eixoLargura, eixoAltura);
      glPopMatrix();

      //Rodas

      //roda direita inferior
      glPushMatrix();
      glColor3f(0.2, 0.2, 0.2);
      glTranslatef((eixoLargura/2)+corpoLargura/2,(eixoAltura-corpoAltura/2),0);
      retangulo(rodaLargura, rodaAltura);
      glPopMatrix();


      //esquerdo inferior
      glPushMatrix();
      glColor3f(0.2, 0.2, 0.2);
      glTranslatef(-(eixoLargura/2)-corpoLargura,(eixoAltura-corpoAltura/2),0);
      retangulo(rodaLargura, rodaAltura);
      glPopMatrix();

      //direito superior
      glPushMatrix();
      glColor3f(0.2, 0.2, 0.2);
      glTranslatef((eixoLargura/2)+corpoLargura/2+rodaLargura/2,((corpoAltura/2-(4*eixoAltura))+rodaAltura/2),0);
      glRotatef(angRoda,0,0,1);
      glTranslatef(-rodaLargura/2, -rodaAltura/2,0);
      retangulo(rodaLargura, rodaAltura);
      glPopMatrix();

      //esquerdo superior
      glPushMatrix();
      glColor3f(0.2, 0.2, 0.2);
      glTranslatef(-(eixoLargura/2)-corpoLargura+rodaLargura/2,(rodaAltura/2+(corpoAltura/2-(4*eixoAltura))),0);
      glRotatef(angRoda,0,0,1);
      glTranslatef(-rodaLargura/2, -rodaAltura/2,0);
      retangulo(rodaLargura, rodaAltura);
      glPopMatrix();

      //Canhao
      glPushMatrix();
      glColor3f(0.09, 0.75, 0.5);
      glTranslatef(0,((corpoAltura/2)-20),0);
      glRotatef(angCanhao,0,0,1);
      glTranslatef(-canhaoLargura/2,0,0);
      retangulo(canhaoLargura, canhaoAltura);
      glPopMatrix();

      //corpo do veiculo
      glPushMatrix();
      glColor3f(0.4, 1, 0.4);
      glTranslatef(-(corpoLargura/2),-(corpoAltura/2),0);
      retangulo(corpoLargura, corpoAltura);   
      glPopMatrix();



      //raio circuferencio do corpo
      glPushMatrix();
      glColor3f(0.09, 0.75, 0.5);
      glTranslatef(0,0,0);
      circuferencia(raioX,raioY);
      glPopMatrix();
     

    glPopMatrix();

    glFlush();
    glutSwapBuffers();
}


void inicializaCarro(void)
{

  cx=0;
  cy=0;
  xAnterior=0;
  angCanhao=0;


  //corpocorpoAltura=400;
  corpoAltura=200;
  //corpoAltura=((raioJodador*2)-10);
  corpoLargura=(corpoAltura/3);
  //eixo
  eixoAltura=corpoAltura/10;
  eixoLargura=corpoLargura/1.5;
  //roda
  rodaAltura=(corpoAltura/3);
  rodaLargura=corpoLargura/2;
  deslocamantoX=0;
  //canhão
  canhaoAltura=corpoLargura/1.5;
  canhaoLargura=corpoLargura/3;
  //raio circuferencio do corpo
  raioX=corpoLargura/2.5;
  raioY=corpoAltura/3.5;
              
}

void Inicializa(){

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    inicializaCarro();


}

void Desenha(){

  desenhaCarro();

}


// Callback chamada quando o tamanho da janela é alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D (-win, win, -win, win);


}






void mouse(int botao, int estado, int x, int y){

  if(botao == GLUT_LEFT_BUTTON && estado == GLUT_DOWN){
    tiros.push_back(bala());
  }

}


void passiveMotion(int x, int y){

  if(x<xAnterior && angCanhao<45){
    angCanhao+=2;
  }else{
    if(x>xAnterior && angCanhao>-45){
      angCanhao-=2;
    }
  }
  xAnterior=x;

  glutPostRedisplay();

}



// Programa principal
int main(int argc, char *argv[])
{


	glutInit(&argc,argv);//inicializa
  	Inicializa();
  	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  	glutInitWindowSize(500,500);
  	glutInitWindowPosition(10,10);
  	glutCreateWindow("Divertimento Computacional 3");
  	glutDisplayFunc(Desenha);
  	glutReshapeFunc(AlteraTamanhoJanela);
    glutKeyboardFunc(keyPressed);
    glutKeyboardUpFunc(keyUp);
    glutMouseFunc(mouse);
    glutPassiveMotionFunc(passiveMotion);
    //glutTimerFunc(120, Timer, 1);
 
  	glutMainLoop();

}