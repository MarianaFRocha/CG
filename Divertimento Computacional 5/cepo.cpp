
//Biblioteca Audio: sudo apt-get install libopenal0a libopenal-dev
//copilar: make all && ./trabalhocg


//Teclas 1 e 2 para acender e apargar as luzes 


#include <stdlib.h>
#include <GL/glut.h>
#include "OpenAL.h"
#include <stdio.h>
#include <string.h>
#include <math.h>


float rotX = 0.0, 
      rotY = 0.0, 
      rotX_ini, rotY_ini;

float obsX = 0.0, 
      obsY = 0.0, 
      obsZ = 100.0, 
      obsX_ini, obsY_ini, obsZ_ini;
      
int x_ini, y_ini, bot;

GLfloat fAspect;

int posPrego = -20, passoMartelo=1, angMartelo=90;

bool mover = false, luz1=false, luz2=false;    

//Contador Global para funcao mouse
int cont = 0;


void desenhaMartelo(){

	GLUquadricObj *caboMartelo = gluNewQuadric();
	GLUquadricObj *martelo = gluNewQuadric();
	GLUquadricObj *tampa = gluNewQuadric();
	GLUquadricObj *tampa2 = gluNewQuadric();


	glPushMatrix();

		if(mover == true && angMartelo<20){
			angMartelo+=passoMartelo;
			if(angMartelo == 20){
				alSourcePlay(Sources[explosao]);
			}
		}
		if(mover == false){
			angMartelo=0;
		}
		

		//Cabo do Martelo
		glPushMatrix();

		    glColor3f(0.36,0.25,0.20);
		    glRotatef(angMartelo,1,1,1);
		    glRotatef(90,0,1,1);
			glTranslatef(0,20,0);
			glRotatef(100,1,0,0);
		    gluCylinder(caboMartelo, 2, 2, 25, 32, 32);  // cabo martelo

		glPopMatrix();

		// //Parte de cima do martelo
		 glPushMatrix();

		 	glRotatef(angMartelo,1,1,1);

		     glPushMatrix();
		 	    glTranslatef(-11,16.5,6);
		 		glRotatef(140,1,0,1);
		    	glRotatef(90,1,0,0);
		 	    gluDisk(tampa2, 0.0f, 5, 50, 1);
		     glPopMatrix();

		    
		    glTranslatef(-18,5,13);
		 	glRotatef(140,1,0,1);
		    glRotatef(90,1,0,0);
		 	gluDisk(tampa, 0.0f, 5, 50, 1);
		    gluCylinder(martelo, 5, 5, 15, 32, 32); // base martelo

		glPopMatrix();

	glPopMatrix();

	glutPostRedisplay();

}

void desenhaCepo(){

	glPushMatrix();

		GLUquadricObj *cepo = gluNewQuadric();
		GLUquadricObj *tampa = gluNewQuadric();
		GLUquadricObj *tampa2 = gluNewQuadric();

	    glColor3f(0.72, 0.25, 0.05);
	    glTranslatef(-18,-12,18);
	    glPushMatrix();
	    	glTranslatef(0,-20,0);
	    	glRotatef(90,1,0,0);
	    	gluDisk(tampa2, 0.0f, 10, 50, 1);
	    glPopMatrix();
		glRotatef(90,1,0,0);
		gluDisk(tampa, 0.0f, 10, 50, 1);
		gluCylinder(cepo, 10, 10, 20, 32, 32);
	 	gluDeleteQuadric(cepo);

	glPopMatrix();
}


void desenhaPrego(){

	GLUquadricObj *prego = gluNewQuadric();

	glPushMatrix();

	    glColor3f(0.4, 0.4, 0.4);
	    glTranslatef(-18,0,18);
		glRotatef(90,1,0,0);
		gluCylinder(prego, 0.5, 0, 15, 32, 32);

	glPopMatrix();


}
void display(void)
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	desenhaMartelo();
	desenhaPrego();
	desenhaCepo();
	
	glutSwapBuffers();
	glFlush();
}


void projecao(void)
{
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();

	gluPerspective( 60, fAspect, 0.1, 1000 );

	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();

	gluLookAt( obsX,obsY,obsZ, 0,0,0, 0,1,0 );
}


void reshape( GLsizei w, GLsizei h )
{
	if ( h == 0 ) h = 1;
	glViewport(0, 0, w, h);
	fAspect = (GLfloat)w/(GLfloat)h;

	projecao();
}




void luz(){


    if(luz1==true){

	    float ambient[]= {0.9, 0.9, 0.9, 1.0};
	    float posicao[]={10.0,10.0,10.0,0.0};

		glLightfv(GL_LIGHT0, GL_POSITION, posicao);
	    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient);
	    glEnable(GL_LIGHTING);
	    glEnable(GL_LIGHT0);
	    glEnable(GL_COLOR_MATERIAL);
	    glEnable(GL_DEPTH_TEST);

	}
	else{
		glDisable(GL_LIGHT0);
	}

	if(luz2==true){

	    float difusa[]={1.0,0.0,0.0,0.0};
	    float posicao[]={-20.0,-10.0,0.0,0.0};

	    glLightfv(GL_LIGHT1, GL_DIFFUSE, difusa);
	    glLightfv(GL_LIGHT1, GL_POSITION, posicao);	  
	    glEnable(GL_LIGHTING);
	    glEnable(GL_LIGHT1);
	    glEnable(GL_COLOR_MATERIAL);
	    glEnable(GL_DEPTH_TEST);  
	}
	else{
		glDisable(GL_LIGHT1);
	}


}

void keyboard( unsigned char key, int x, int y )
{
    switch( key )
    {
        case 27: exit(0); break;
                    
        case '1':
        	luz1=!luz1;
        	luz();
        	    break;
 	      
        case '2':
        	luz2=!luz2;
        	luz();
        	    break;
    }    
    glutPostRedisplay();
}


void Inicializa (void)
{   

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	alSourcePlay(Sources[musica]); 
    
}

#define SENS_ROT 5.0
#define SENS_OBS 20.0
#define SENS_TRANSL 30.0

void motion( int x, int y )
{
    if( bot == GLUT_RIGHT_BUTTON)
    {
        int deltax = x_ini - x;
        int deltay = y_ini - y;
        rotY = rotY_ini - deltax/SENS_ROT;
        rotX = rotX_ini - deltay/SENS_ROT;
    } 
    else if( bot == GLUT_MIDDLE_BUTTON )
    {
        int deltaz = y_ini - y;
        obsZ = obsZ_ini + deltaz/SENS_OBS;
    }
    
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    
    glTranslatef( -obsX, -obsY, -obsZ );
    glRotatef( rotX, 1, 0, 0 );
    glRotatef( rotY, 0, 1, 0 );
    
    glutPostRedisplay();
}



void mouse( int button, int state, int x, int y )
{

	if(button == GLUT_LEFT_BUTTON)
    {
    	cont++;
    	if(cont == 2){
    		cont=0;
    		mover=!mover;
    	}
    }

    if( state == GLUT_DOWN )
    {
        x_ini = x;
        y_ini = y;
        
        obsX_ini = obsX;
        obsY_ini = obsY;
        obsZ_ini = obsZ;
        
        rotX_ini = rotX;
        rotY_ini = rotY;
        
        bot = button;
    } else {
        bot = -1;
    }
}        
//------------------------------------------------------------------------------
int main(int argc, char *argv[])
{

    alutInit(NULL, 0);
    alGetError();
    if(LoadALData() == AL_FALSE) return 0;
    SetListenerValues();


    glutInit( &argc, argv );
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); 
	glutInitWindowSize( 450, 450 ); 
	glutCreateWindow("Divertimento Computacional 5");

	glutDisplayFunc( display );
	glutReshapeFunc( reshape );
	glutKeyboardFunc( keyboard );
    glutMouseFunc( mouse );
    glutMotionFunc( motion );

	Inicializa();
 
	glutMainLoop();
	return 0;
}


