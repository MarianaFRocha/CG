
#include <stdlib.h>
#include <GL/glut.h>

bool eixos = true,
     wire = true;

float rotX = 0.0, 
      rotY = 0.0, 
      rotX_ini, rotY_ini;

float obsX = 0.0, 
      obsY = 0.0, 
      obsZ = 100.0, 
      obsX_ini, obsY_ini, obsZ_ini;
      
int x_ini, y_ini, bot;

GLfloat fAspect;

//-----------------------------------------------------------------------
void desenhaEixos()
{
    glLineWidth( 2.0f );
    
    glBegin( GL_LINES );
    	glColor3f ( 1.0f, 0.0f, 0.0f );
    	glVertex3f( 0.0f, 0.0f, 0.0f );
    	glVertex3f( 2.0f, 0.0f, 0.0f );
    	
    	glColor3f ( 0.0f, 1.0f, 0.0f );
    	glVertex3f( 0.0f, 0.0f, 0.0f );
    	glVertex3f( 0.0f, 2.0f, 0.0f );
    	
    	glColor3f ( 0.0f, 0.0f, 1.0f );
    	glVertex3f( 0.0f, 0.0f, 0.0f );
    	glVertex3f( 0.0f, 0.0f, 2.0f );
   	glEnd();
}
//------------------------------------------------------------------------------
void desenhaCenarioWire()
{
    //tampo da mesa
    glColor3f( 0.5, 0.2, 0.13 );
    glPushMatrix();
        glScalef( 1.0, 0.15, 1.0 );
        glutWireCube( 50 );
    glPopMatrix();
    
    //p� da mesa
    glPushMatrix();
        glTranslatef( -22.0, -15.0, 22.0 );
        glScalef( 0.10, 0.5, 0.10 );
        glutWireCube(50);
    glPopMatrix();
    //p� da mesa
    glPushMatrix();
        glTranslatef( 22.0, -15.0, 22.0 );
        glScalef( 0.10, 0.5, 0.10 );
        glutWireCube(50);
    glPopMatrix();
    //p� da mesa
    glPushMatrix();
        glTranslatef( -22.0, -15.0, -22.0 );
        glScalef( 0.10, 0.5, 0.10 );
        glutWireCube(50);
    glPopMatrix();
    //p� da mesa
    glPushMatrix();
        glTranslatef( 22.0, -15.0, -22.0 );
        glScalef( 0.10, 0.5, 0.10 );
        glutWireCube(50);
    glPopMatrix();
    
    // bule
    glColor3f( 0.0, 0.2, 0.7 );
    glPushMatrix();
        glTranslatef( 0.0, 9.0, 0.0 );
        glutWireTeapot( 7 );
    glPopMatrix();
    
    //esferas
    glColor3f( 0.3, 0.3, 0.3 );
    glPushMatrix();
        glTranslatef( 3.0, 7.0, 20.0 );
        glutWireSphere( 3, 10, 10 );
    glPopMatrix();
}    
//------------------------------------------------------------------------------
void desenhaCenarioSolid()
{
    //tampo da mesa
    glColor3f( 0.5, 0.2, 0.13 );
    glPushMatrix();
        glScalef( 1.0, 0.15, 1.0 );
        glutSolidCube( 50 );
    glPopMatrix();
    
    //p� da mesa
    glPushMatrix();
        glTranslatef( -22.0, -15.0, 22.0 );
        glScalef( 0.10, 0.5, 0.10 );
        glutSolidCube(50);
    glPopMatrix();
    //p� da mesa
    glPushMatrix();
        glTranslatef( 22.0, -15.0, 22.0 );
        glScalef( 0.10, 0.5, 0.10 );
        glutSolidCube(50);
    glPopMatrix();
    //p� da mesa
    glPushMatrix();
        glTranslatef( -22.0, -15.0, -22.0 );
        glScalef( 0.10, 0.5, 0.10 );
        glutSolidCube(50);
    glPopMatrix();
    //p� da mesa
    glPushMatrix();
        glTranslatef( 22.0, -15.0, -22.0 );
        glScalef( 0.10, 0.5, 0.10 );
        glutSolidCube(50);
    glPopMatrix();
    
    // bule
    glColor3f( 0.0, 0.2, 0.7 );
    glPushMatrix();
        glTranslatef( 0.0, 9.0, 0.0 );
        glutSolidTeapot( 7 );
    glPopMatrix();
    
    //esferas
    glColor3f( 0.3, 0.3, 0.3 );
    glPushMatrix();
        glTranslatef( 3.0, 7.0, 20.0 );
        glutSolidSphere( 3, 10, 10 );
    glPopMatrix();
}    
//------------------------------------------------------------------------------
void display(void)
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if( eixos ) desenhaEixos();

	if( wire )
       desenhaCenarioWire();
    else
       desenhaCenarioSolid();

	glutSwapBuffers();
}

//------------------------------------------------------------------------------
void projecao(void)
{
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();

	gluPerspective( 60, fAspect, 0.1, 1000 );

	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();

	gluLookAt( obsX,obsY,obsZ, 0,0,0, 0,1,0 );
}

//------------------------------------------------------------------------------
void reshape( GLsizei w, GLsizei h )
{
	if ( h == 0 ) h = 1;
	glViewport(0, 0, w, h);
	fAspect = (GLfloat)w/(GLfloat)h;

	projecao();
}

//------------------------------------------------------------------------------
void keyboard( unsigned char key, int x, int y )
{
    switch( key )
    {
        case 27: exit(0); break;
                    
        case 'a':
        case 'A': eixos = !eixos;
        	      break;
 	      
        case 'w':
        case 'W': wire = !wire;
        	      break;
    }    
    glutPostRedisplay();
}

//------------------------------------------------------------------------------
void Inicializa (void)
{   
    float ambient[]= {0.2, 0.9, 0.9, 1.0};
    float difusa[]={1.0,1.0,1.0,1.0};
    float posicao[]={40.0,0.0,0.0,0.0};
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, difusa);
    glLightfv(GL_LIGHT0, GL_POSITION, posicao);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_DEPTH_TEST);
}
//-----------------------------------------------------------------------
#define SENS_ROT 5.0
#define SENS_OBS 20.0
#define SENS_TRANSL 30.0

void motion( int x, int y )
{
    if( bot == GLUT_LEFT_BUTTON )
    {
        int deltax = x_ini - x;
        int deltay = y_ini - y;
        rotY = rotY_ini - deltax/SENS_ROT;
        rotX = rotX_ini - deltay/SENS_ROT;
    } 
    else if( bot == GLUT_RIGHT_BUTTON )
    {
        int deltaz = y_ini - y;
        obsZ = obsZ_ini + deltaz/SENS_OBS;
    }
    else if( bot == GLUT_MIDDLE_BUTTON )
    {
        int deltax = x_ini - x;
        int deltay = y_ini - y;
        obsX = obsX_ini + deltax/SENS_TRANSL;
        obsY = obsY_ini - deltay/SENS_TRANSL;
    }
    
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    
    glTranslatef( -obsX, -obsY, -obsZ );
    glRotatef( rotX, 1, 0, 0 );
    glRotatef( rotY, 0, 1, 0 );
    
    glutPostRedisplay();
}
//-----------------------------------------------------------------------
void mouse( int button, int state, int x, int y )
{
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
    glutInit( &argc, argv );
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); 
	glutInitWindowSize( 450, 450 ); 
	glutCreateWindow("Exemplo 3D com Iluminacao");

	glutDisplayFunc( display );
	glutReshapeFunc( reshape );
	glutKeyboardFunc( keyboard );
    glutMouseFunc( mouse );
    glutMotionFunc( motion );

	Inicializa();
 
	glutMainLoop();
	return 0;
}
//------------------------------------------------------------------------------

