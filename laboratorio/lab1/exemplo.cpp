#include <GL/glut.h>
#include <stdio.h>



void Desenha(void){

	glClear(GL_COLOR_BUFFER_BIT);

	glFlush();
}

void inicializa(void){
	glClearColor(0.5,0.3,0.7,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0f, 250.0f,0.0f,250.0f);
}

void reshape(int largura, int altura){
	printf("%d %d\n", largura, altura);
}

void keyboard(unsigned char tecla, int x, int y){
	switch(tecla){
		case 'a':{
			printf("tecla a\n");
			break;
		}
	}
}

void special(int tecla, int x, int y){
	if(tecla == GLUT_KEY_F1){
		printf("f1 \n" );
	}

}

void mouse(int botao, int estado, int x, int y){

	if(botao == GLUT_LEFT_BUTTON && estado == GLUT_DOWN){
		printf("botao esquerdo\n");

	}
}

void passiveMotion(int x, int y){
	printf("mouse na tela x %d y %d\n", x, y);
}

void quadrado(){
	//glBegin();
	//glEnd();

}

int main(int argc, char *argv[]){

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutCreateWindow ("primeiro programa");
	glutDisplayFunc(Desenha);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(special);
	glutMouseFunc(mouse);
	//glutMotionFunc(motion);
	glutPassiveMotionFunc(passiveMotion);
	inicializa();
	glutMainLoop();
	
}
