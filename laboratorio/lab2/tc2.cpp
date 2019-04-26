#include <GL/glut.h>
#include <stdio.h>
#include <string.h>



int dx = 0, dy = 0;
float ang1=0, ang2=0,ang3=0, angRoda=0;

void init( void )
{
	glClear( GL_COLOR_BUFFER_BIT );
    glColor3f( 0.0, 0.0, 0.0);  
    glMatrixMode( GL_PROJECTION );

    gluOrtho2D(-250,250,-250,250);

    
}



void desenhaRetangulo(int altura, int largura, float r, float g, float b){



	glColor3f(r,g,b);

	glBegin( GL_QUADS );        

        	glVertex2f ( -largura/2, 0); 
            glVertex2f ( largura/2, 0);
            glVertex2f ( largura/2, altura);
            glVertex2f ( -largura/2, altura);

    glEnd();

}


void desenhaEixos(){
	
	//Eixo X Vermelho
	glColor3f (1,0,0);
	glBegin(GL_LINES);
		glVertex3f(0,0,0);
		glVertex3f(250,0,0);
		glVertex3f(0,0,0);
		glVertex3f(-250,0,0);
	glEnd();

	//Eixo Y Vermelho
	glColor3f (0,1,0);
	glBegin(GL_LINES);
		glVertex3f(0,0,0);
		glVertex3f(0,250,0);
		glVertex3f(0,0,0);
		glVertex3f(0,-250,0);
	glEnd();


}


void desenha(){

	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	desenhaEixos();

	glPushMatrix();
	glTranslatef(dx, dy, 0);


	//Retangulos Superiores
	glPushMatrix();
	glTranslatef(-45, 40,0);
	glRotatef(ang1,0,0,1);
	desenhaRetangulo(80,10,0,0,1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(45, 40,0);
	glRotatef(ang3,0,0,1);
	desenhaRetangulo(80,10,0,1,0.5);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 40,0);
	glRotatef(ang2,0,0,1);
	desenhaRetangulo(80,10,1,1,0);
	glPopMatrix();

	//Base
	desenhaRetangulo(40,100,1,0.2,1);

	//Rodas
	glPushMatrix();
	glTranslatef(-30, 0,0);
	glRotatef(angRoda,0,0,1);
	glTranslatef(0,-10,0);
	desenhaRetangulo(20,20,0.2,0.2,0.2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(30, 0,0);
	glRotatef(angRoda,0,0,1);
	glTranslatef(0,-10,0);
	desenhaRetangulo(20,20,0.2,0.2,0.2);
	glPopMatrix();

	glPopMatrix();


	glutSwapBuffers();
}



void teclas(unsigned char tecla, int x, int y){
	switch(tecla){
		case 'w':{
			angRoda++;
			dy++;	
			break;
		}
		case 'a':{
			angRoda++;
			dx--;
			break;
		}
		case 's':{
			dy--;
			angRoda--;			
			break;
		}
		case 'd':{
			angRoda--;
			dx++;
			break;
		}
		case 'r':{
			ang1++;
			break;
		}
		case 'f':{
			ang1--;
			break;
		}
		case 't':{
			ang2++;
			break;
		}
		case 'g':{
			ang2--;
			break;
		}
		case 'y':{
			ang3++;
			break;
		}
		case 'h':{
			ang3--;
			break;
		}

		case 27:{
			exit(0);
			break;
		}

	}
	glutPostRedisplay();
}


int main (int argc, char *argv[]){


    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
    glutInitWindowSize( 400, 400); // TAMANHO DA JANELA
    glutCreateWindow("Atividade 2");
    init();
	glutDisplayFunc(desenha); 
	glutKeyboardFunc(teclas);
	glRotatef(0,0,0,1);
  
    glutMainLoop();

	return 0;
}