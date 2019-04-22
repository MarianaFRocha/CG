#include <GL/glut.h>
#include "tinyxml/tinyxml.h"
#include <stdio.h> 
#include <string.h>    
#include <math.h>

#define PI 3.1415926535898      
           

//variáveis globais 

char nomeArquivo[50];
bool teclasEstado[256];
int  passo=3;

//Variaveis para a Arena
float raioCirculo1, raioCirculo2, rCirculo1, gCirculo1, bCirculo1, rCirculo2, gCirculo2, bCirculo2; 
int cxCirculo1, cyCirculo1, cxCirculo2, cyCirculo2;

//Inimigo
float raioInimigo, rInimigo, gInimigo, bInimigo; 
int cxInimigo1, cyInimigo1, cxInimigo2, cyInimigo2, cxInimigo3, cyInimigo3;

//Jogador
float raioJodador, rJodador, gJodador, bJodador;
int cxJogador, cyJogador;

//Largada
int xLargada, yLargada, wLargada, hLargada;
float rLargada, gLargada, bLargada;

     

void selecionaCor(char *cor, float *r , float *g, float *b){

    if(strcmp(cor, "white") == 0){
      *r=1.0 , *g=1.0, *b=1.0;
    }

    if(strcmp(cor, "black") == 0){
      *r=0 , *g=0, *b=0;
    }

    if(strcmp(cor, "red") == 0){
      *r=1.0 , *g=0, *b=0;
    }

    if(strcmp(cor, "green") == 0){
      *r=0 , *g=1.0, *b=0;
    }

    if(strcmp(cor, "blue") == 0){
      *r=0 , *g=0, *b=1.0;
    }
}

           
//Função que lê as informações do arquivo XML
void parseXML(char *nomeXML){


  TiXmlDocument arq; 

  if(arq.LoadFile(nomeXML)){

    TiXmlElement *arquivo = arq.FirstChildElement("aplicacao")->FirstChildElement("arquivoDaArena");

    char *caminho= (char*) arquivo->Attribute("caminho");
    if(strcmp(caminho, "")!=0)
    {
        strcat(nomeArquivo,caminho);
        strcat(nomeArquivo,"/");
    }
    
    char *nome= (char*) arquivo->Attribute("nome");
    strcat(nomeArquivo,nome);
    strcat(nomeArquivo,".");

    char *tipo= (char*) arquivo->Attribute("tipo");
    strcat(nomeArquivo,tipo);

 //   printf("%s\n", nomeArquivo);
    

  }else{
    printf("Falha na leitura do arquivo!!\n");
  }


  return; 

}


//Função que lê as informações do arquivo SVG
void parse(char *aux, int num, int *cx, int *cy, float *raio, float *r , float *g, float *b){

  TiXmlDocument arquivo(nomeArquivo);

  int x=1;


  if(arquivo.LoadFile()){


    TiXmlElement *circulo = arquivo.FirstChildElement("svg")->FirstChildElement("circle");

    //Busca no arquivo o id da informação que deseja ler
    char *i = (char*) circulo->Attribute("id");


    while(strcmp(i, aux)!=0 || x!=num){

      //printf("\n %s %s %d %d\n", i, aux, x, num);

       if(strcmp(i, aux) == 0){
        x++;
      }

      //Teste para ver se os dados informados existem no arquivo
      //E nao passar do limito do arquivo svg - nao acontecer erro de segmentacao 
      if(circulo=circulo->NextSiblingElement("circle")){    
        i = (char*) circulo->Attribute("id");       
      }else{
        printf("Nao foi possivel encontrar elemento no arquivo svg !!\n");
      }
    }

    //Le as informacoes do svg

    circulo->QueryIntAttribute("cx", cx);
    circulo->QueryIntAttribute("cy", cy);
    circulo->QueryFloatAttribute("r", raio);
    char *cor = (char*) circulo->Attribute("fill");

    selecionaCor(cor, r, g, b);


  }else{
    printf("Falha na leitura do arquivo!!\n");
  }

  return; 

}


void parseLargada(){

  TiXmlDocument arquivo(nomeArquivo);

  if(arquivo.LoadFile()){

    TiXmlElement *largada = arquivo.FirstChildElement("svg")->FirstChildElement("rect");

    largada->QueryIntAttribute("x", &xLargada);
    largada->QueryIntAttribute("y", &yLargada);
    largada->QueryIntAttribute("width", &wLargada);
    largada->QueryIntAttribute("height", &hLargada);
    char *auxCor=(char*) largada->Attribute("fill");

    selecionaCor(auxCor, &rLargada, &gLargada, &bLargada);

 }else{
    printf("Falha na leitura do arquivo!!\n");
  }

 // printf("%d %d %d %d \n", xLargada, yLargada, wLargada, hLargada);

  return;

}



void largada(){

  glBegin(GL_QUADS);

    glVertex2f ( 0, 0); 
    glVertex2f ( wLargada, 0);
    glVertex2f ( wLargada, hLargada);
    glVertex2f ( 0, hLargada);

  glEnd();

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



           
void circuloMaior()
{

  char id[50];
  strcpy(id,"Pista");

  parse(id,1, &cxCirculo1, &cyCirculo1, &raioCirculo1, &rCirculo1, &gCirculo1, &bCirculo1);
  //printf("%s %d %d %f\n", id, cxCirculo, cyCirculo, raioCirculo1);
 
  glColor3f(rCirculo1, gCirculo1, bCirculo1);
  circulo(raioCirculo1);

  return;

}
           
           
void circuloMenor()
{
  char id[50];
  strcpy(id,"Pista");

  parse(id,2, &cxCirculo2, &cyCirculo2, &raioCirculo2, &rCirculo2, &gCirculo2, &bCirculo2);
 // printf("%s %d %d %f\n", id, cxCirculo2, cyCirculo2, raioCirculo2);
  glColor3f(rCirculo2, gCirculo2, bCirculo2);
  circulo(raioCirculo2);

  return;
 }


 int limitesArena(int cx, int cy){


  float limiteSuperior = sqrt(((cxCirculo1-cx)*(cxCirculo1-cx)) + ((cyCirculo1-cy)*(cyCirculo1-cy)));

    //printf("limiteSuperior %f raio %f -- %d\n", limiteSuperior, raioCirculo1);

  if(limiteSuperior<=(raioCirculo1-raioJodador) && limiteSuperior>=(raioCirculo2+raioJodador)){
    return 0;
  }

  return 1;

 }


 int colisaoInimigo(int cx, int cy){


  float distInimigo1= sqrt(((cxInimigo1-cx)*(cxInimigo1-cx)) + ((cyInimigo1-cy)*(cyInimigo1-cy))),
        distInimigo2= sqrt(((cxInimigo2-cx)*(cxInimigo2-cx)) + ((cyInimigo2-cy)*(cyInimigo2-cy))),
        distInimigo3= sqrt(((cxInimigo3-cx)*(cxInimigo3-cx)) + ((cyInimigo3-cy)*(cyInimigo3-cy)));

  float raioTotal = raioInimigo+raioJodador;

 // printf("limiteSuperior %f raio %f \n", distInimigo, (raioInimigo+raioJodador));

  if(distInimigo1>=raioTotal && distInimigo2>=raioTotal && distInimigo3>=raioTotal){
    return 0;
  }

  return 1;

 }
           

           
void inimigo(int num, int *cxInimigo, int *cyInimigo)
{
  char id[50];
  strcpy(id,"Inimigo");

  parse(id,num, cxInimigo, cyInimigo, &raioInimigo, &rInimigo, &gInimigo, &bInimigo);
  //printf("%s %d %d %f\n", id, cxCirculo, cyCirculo, raioCirculo2)
  
  glColor3f(rInimigo, gInimigo, bInimigo);
  circulo(raioInimigo);


}


void jogador()
{

  glColor3f(rJodador, gJodador, bJodador);
  circulo(raioJodador);

}
   


void keyPressed (unsigned char tecla, int x, int y) {  

    teclasEstado[tecla] = true;  
    //printf("%c\n", tecla);
    glutPostRedisplay();
}

void keyUp (unsigned char tecla, int x, int y) {  
  
    teclasEstado[tecla] = false;  
} 
           


void keyOperations(){

    int aux;

   // printf(" entrou \n");

    if(teclasEstado['w'] == true){
      aux=cyJogador + passo;
      if(limitesArena(cxJogador, aux) == 0 && colisaoInimigo(cxJogador, aux) == 0)
        cyJogador+=passo;
    }

     if(teclasEstado['a'] == true){
        aux=cxJogador - passo;
        if(limitesArena(aux, cyJogador) == 0 && colisaoInimigo(aux, cyJogador) == 0)
          cxJogador-=passo;

     }

     if(teclasEstado['s'] == true){
      aux=cyJogador - passo;
      if(limitesArena(cxJogador, aux) == 0 && colisaoInimigo(cxJogador, aux) == 0)
        cyJogador-=passo; 
     }

     if(teclasEstado['d'] == true){
      aux=cxJogador + passo;
      if(limitesArena(aux , cyJogador) == 0 && colisaoInimigo(aux , cyJogador) == 0)
        cxJogador+=passo;

     }


}

           
// Callback chamada para fazer o desenho
void Desenha(void)
{
    keyOperations();
    

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
                              
    glClear(GL_COLOR_BUFFER_BIT);
                   
    glPushMatrix();
    glTranslatef(cxCirculo1, cyCirculo1,0);
    glColor3f(rCirculo1, gCirculo1, bCirculo1);
    circulo(raioCirculo1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cxCirculo2, cyCirculo2,0);
    glColor3f(rCirculo2, gCirculo2, bCirculo2);
    circulo(raioCirculo2);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(xLargada, yLargada,0);
    glColor3f(rLargada, gLargada, bLargada);
    largada();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cxInimigo1, cyInimigo1,0);
    glColor3f(rInimigo, gInimigo, bInimigo);
    circulo(raioInimigo);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(cxInimigo2, cyInimigo2,0);
    glColor3f(rInimigo, gInimigo, bInimigo);
    circulo(raioInimigo);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cxInimigo3, cyInimigo3,0);
    glColor3f(rInimigo, gInimigo, bInimigo);
    circulo(raioInimigo);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cxJogador, cyJogador,0);
    jogador();
    glPopMatrix();
                                  
    glFlush();
    glutSwapBuffers();
}


// Responsável pelas inicializações
void Inicializa(void)
{

  // Set clear color to blue
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

  //Le as informações do SVG para as variaveis

  //Jogador
  char id[50];
  strcpy(id,"Jogador");
  parse(id,1, &cxJogador, &cyJogador, &raioJodador, &rJodador, &gJodador, &bJodador);
  parseLargada();
  circuloMaior();
  circuloMenor();
  inimigo(1, &cxInimigo1, &cyInimigo1);
  inimigo(2, &cxInimigo2, &cyInimigo2);
  inimigo(3, &cxInimigo3, &cyInimigo3);

              
}


// Callback chamada quando o tamanho da janela é alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(cxCirculo1-raioCirculo1 ,cxCirculo1+raioCirculo1, cyCirculo1-raioCirculo1, cyCirculo1+raioCirculo1);


}

// Programa principal
int main(int argc, char *argv[])
{
 parseXML(argv[1]);

	glutInit(&argc,argv);//inicializa
  Inicializa();
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(500,500);
  glutInitWindowPosition(10,10);
  glutCreateWindow("Divertimento Computacional 2");
  glutDisplayFunc(Desenha);
  glutReshapeFunc(AlteraTamanhoJanela);
  glutKeyboardFunc(keyPressed);
  glutKeyboardUpFunc(keyUp);
  glutMainLoop();



}
