#include <GL/glut.h>
#include <stdio.h>



int largura;
int altura;




void quadrado2(int x, int y){

	int x1=x-25;
	int x2=x+25;
	int y1=y-25;
	int y2=y+25;

	printf("Quadrado: x1:%d x2:%d y1:%d y2:%d \n", x1,x2,y1,y2);

	glBegin( GL_QUADS );

		glColor3f( 1.0, 0.0, 0.0 ); //Cor do Quadrado

		glVertex3i(x1, y2, 0);	//Parte Esquerda de Cima				
		glVertex3i( x2, y2, 0);	//Parte Direita de Cima				
		glVertex3i( x2,y1, 0);	//Pare Direita de Baixo				
		glVertex3i(x1,y1, 0);	//Parte Esquerda de Baixo

	glEnd();

	glFlush();

}


void quadrado(int x, int y){

	float x1=(x/1000.0)-0.25;
	float x2=(x/1000.0)+0.25;
	float y1=(y/1000.0)-0.25;
	float y2=(y/1000.0)+0.25;

	printf("Quadrado: x1:%f x2:%f y1:%f y2:%f \n", x1,x2,y1,y2);

	glBegin( GL_QUADS );

		glColor3f( 1.0, 0.0, 0.0 ); //Cor do Quadrado

		glVertex3f(x1, y2, 0.0f);	//Parte Esquerda de Cima				
		glVertex3f( x2, y2, 0.0f);	//Parte Direita de Cima				
		glVertex3f( x2,y1, 0.0f);	//Pare Direita de Baixo				
		glVertex3f(x1,y1, 0.0f);	//Parte Esquerda de Baixo

	glEnd();

	glFlush();

}

void mouse(int botao, int estado, int x, int y){

	if(botao == GLUT_LEFT_BUTTON && estado == GLUT_DOWN){
		printf("botao esquerdo\nPosicao x %d y %d \n", x,y);
		quadrado2(x,y);

	}
}

void Desenha(void){

	glClear(GL_COLOR_BUFFER_BIT);
	//quadrado();

	glFlush();
}




void passiveMotion(int x, int y){
	printf("mouse na tela x %d y %d\n", x, y);
}



int main(int argc, char *argv[]){

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutCreateWindow ("Divertimento Computacional 1");
	glutDisplayFunc(Desenha);
	glutMouseFunc(mouse);
	glutReshapeFunc(reshape);
	//glutPassiveMotionFunc(passiveMotion);
	glutMainLoop();
	
}