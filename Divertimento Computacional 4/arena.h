
// FUNCOES
void largada();
void circuloMaior();
void circuloMenor();
int limitesArena(int cx, int cy);
void desenhaArena();
void inicializaArena();



void largada(){

  glBegin(GL_QUADS);

    glVertex2f ( 0, 0);
    glVertex2f ( wLargada, 0);
    glVertex2f ( wLargada, hLargada);
    glVertex2f ( 0, hLargada);

  glEnd();

}


void circuloMaior()
{

  glColor3f(rCirculo1, gCirculo1, bCirculo1);
  circulo(raioCirculo1);

  return;

}


void circuloMenor()
{

  glColor3f(rCirculo2, gCirculo2, bCirculo2);
  circulo(raioCirculo2);

  return;
 }


 int limitesArena(int cx, int cy, int raio){


  float limiteSuperior = sqrt(((cxCirculo1-cx)*(cxCirculo1-cx)) + ((cyCirculo1-cy)*(cyCirculo1-cy)));

 	  //printf("limiteSuperior %f raio %f -- %d\n", limiteSuperior, raioCirculo1);

  if(limiteSuperior<=(raioCirculo1-raio+2) && limiteSuperior>=(raioCirculo2+raio+2)){
    return 0;
  }

  return 1;

 }


 void desenhaArena()
{


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

   // glutSwapBuffers();
}

void inicializaArena()
{

  //Arena

  largada();
  circuloMaior();
  circuloMenor();

}
