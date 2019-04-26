#include <GL/glut.h>

#define SENS_OBS 50.0

int orto = 1;

float win = 10.0f;
float aspecto;
float angulo = 60.0f;
float rotX =0.0, rotY =0.0, rotX_ini, rotY_ini;
float obsX=0.0, obsY=0.0, obsZ=5.0, obsX_ini, obsY_ini, obsZ_ini;
int x_ini, y_ini, bot;
int objeto = 0;
int wire = 1;


void desenhaEixo();
void formas();
void display();
void projecao();
void reshape(GLsizei w, GLsizei h);
void keyboard(unsigned char tecla, int x, int y);

void motion (int x, int y){

	projecao();
	if(bot == GLUT_MIDDLE_BUTTON){
		int deltaz=y_ini - y;
		obsZ= obsZ+deltaz/SENS_OBS;

	}

}


void mouse (int button, int state, int x, int y){

	if(state==GLUT_DOWN){
		x_ini=x;
		y_ini=y;
		obsX_ini=obsX;
		obsY_ini=obsY_ini;
		obsZ_ini=obsZ_ini;
		rotY_ini=rotX;
		rotY_ini=rotY;
		bot=button;

	}
	else bot =-1;
	glutPostRedisplay();
}


void desenhaEixo(){
	glLineWidth(2.0f);
	glBegin(GL_LINES);

		glColor3f(1.0f,0.0f,0.0f);
		glVertex3f(0.0f,0.0f,0.0f);
		glVertex3f(2.0f,0.0f,0.0f);

		glColor3f(0.0f,1.0f,0.0f);
		glVertex3f(0.0f,0.0f,0.0f);
		glVertex3f(0.0f,2.0f,0.0f);

		glColor3f(0.0f,0.0f,1.0f);
		glVertex3f(0.0f,0.0f,0.0f);
		glVertex3f(0.0f,0.0f,2.0f);

	glEnd();

}

void formas(){
	switch(objeto){
		case 1:
			if(wire){ glutWireSphere (2,10,10);}
			else{
				glutSolidSphere(2,10,10);
			}
			break;
		case 2:
		if(wire){ glutWireCube (2);}
		else{
			glutSolidCube(2);}
		break;

	}
}
void display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	desenhaEixo();
	formas();

	glutSwapBuffers();
}


void projecao(){

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	if(orto){
		glOrtho(-win * aspecto, win * aspecto, -win, win, -win, win);

	}else{

		gluPerspective(angulo, aspecto, 0.0f, 1000.0f);
	}

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(obsX,obsY,obsZ,0.0,0.0,0.0,0.0,1.0,0.0);

}

void reshape(GLsizei w, GLsizei h){
	if(h==0) h=1;

	glViewport(0,0,w,h);
	aspecto = (float) w/h;
	projecao();

}

void keyboard(unsigned char tecla, int x, int y){
 
	switch (tecla){

		case 27:exit(0);break;
		case 'p':
		case 'P': orto = 0; projecao(); break;
		case 'o':
		case 'O': orto = 1; projecao(); break;
		case 'w':
		case 'W':
			wire=!wire;
			break;
		case '1':
			objeto=1;
			break;
		case '2':
			objeto=2;
			break;
	}

	glutPostRedisplay();

}

int main(int argc, char *argv[]){

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);

	glutInitWindowSize(500, 500);
	glutCreateWindow("xxt");

	glutDisplayFunc(display);

	glutReshapeFunc(reshape);

	glutKeyboardFunc(keyboard);

	glutMouseFunc(mouse);
	glutMotionFunc(motion);

	glutMainLoop();

	return 0;
}
