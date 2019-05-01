
// FUNCOES
void keyPressed (unsigned char tecla, int x, int y);
void keyUp (unsigned char tecla, int x, int y);
void keyOperations();
void mouse(int botao, int estado, int x, int y);


bool teclasEstado[256];
int  passo=3, passoGiro=3;

void keyPressed (unsigned char tecla, int x, int y) {

    teclasEstado[tecla] = true;
    //printf("%c\n", tecla);
}

void keyUp (unsigned char tecla, int x, int y) {

    teclasEstado[tecla] = false;
}

void mouse(int botao, int estado, int x, int y){

  if(botao == GLUT_LEFT_BUTTON && estado == GLUT_DOWN){
    tiros.push_back(bala());
  }

}



void keyOperations(){

    int auxCX, auxCY;

   // printf(" entrou \n");

    flagMovimento=0;


    if(teclasEstado['w'] == true){
      flagMovimento=1;
      auxCX=cx+passo*cos(angCarro*(PI/180));
      auxCY=cy+passo*sin(angCarro*(PI/180));
      if(limitesArena(auxCX, auxCY, raioJodador) == 0 && colisaoInimigo(auxCX, auxCY, raioJodador) == 0){
          cx=auxCX;
          cy=auxCY;

      }
      if(teclasEstado['w'] == true && teclasEstado['a'] == true){
          angCarro+=passoGiro;
      }
      if(teclasEstado['w'] == true && teclasEstado['d'] == true){
        angCarro-=passoGiro;
      }

    }

     if(teclasEstado['s'] == true){
      flagMovimento=1;
      auxCX=cx-passo*cos(angCarro*(PI/180));
      auxCY=cy-passo*sin(angCarro*(PI/180));
      if(limitesArena(auxCX, auxCY, raioJodador) == 0 && colisaoInimigo(auxCX, auxCY, raioJodador) == 0){
          cx=auxCX;
          cy=auxCY;
      }
      if(teclasEstado['s'] == true && teclasEstado['a'] == true){
        angCarro-=passoGiro;
      }
      if(teclasEstado['s'] == true && teclasEstado['d'] == true){
        angCarro+=passoGiro;
      }

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
