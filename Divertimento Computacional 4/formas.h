
#define PI 3.1415926535898  

// FUNCOES
void retangulo(int largura, int altura);
void circuferencia(float raioX, float raioY);
void circulo(float raio);


void desenhaTriangulo(float lateralTriangulo){
    
  glBegin(GL_TRIANGLES);
        glVertex3f(-lateralTriangulo, -lateralTriangulo,0.0);
        glVertex3f(0.0f, lateralTriangulo,0.0);
        glVertex3f(lateralTriangulo, -lateralTriangulo,0.0);              
     glEnd();

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