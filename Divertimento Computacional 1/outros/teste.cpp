#include <GL/glut.h>
#include <iostream>
#include <cstdio>

#define QUADS 1

using namespace std;

int primitiva;
int px, py;
float vx, vy; // valor do vertice em x e em y


void display( void ){
	//printf("vx: %f vy: %f \n", vx,vy);
    //Limpar todos os pixels
    glClear( GL_COLOR_BUFFER_BIT );
    glColor3f( 1.0, 1.0, 1.0 );
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1,0xFFFF);
	if(primitiva == QUADS){
        glBegin( GL_QUADS );
            glVertex3f ( -0.9, -0.9, 0.00 ); // TAMANHO //1  2 localização dos vertices
            glVertex3f ( -0.9, 0.9, 0.00 );//            3  4
            glVertex3f ( 0.9, 0.9, 0.00 );
            glVertex3f ( 0.9, -0.9, 0.00 );

        glEnd();
    }

    glutSwapBuffers();
}

//Calcula a posição dos vertices para o quadrado .. de entrada px e py detectada no passiveMotion
void calculaVertice(int x, int y){
printf("x: %d y: %d \n", x,y);
	vx=((x-250)/250)+0.1;
	vy=((y-250)/250)+0.1;
printf("vx: %f vy: %f \n", vx,vy);
}



void mouse(int botao, int estado, int x, int y){
	while(botao==GLUT_LEFT_BUTTON && estado==GLUT_DOWN)
	{
	//	printf("Botão esquerdo clicado \n");
		primitiva=1;
		display();
	}
	if(botao==GLUT_RIGHT_BUTTON && estado==GLUT_DOWN)
	{
	//	printf("Botão direito clicado \n");
		primitiva=-1;
		display();
	}
	
	calculaVertice(x,y);
}



void passiveMotion(int x, int y){
    cout << "Mouse Position (" << x << "," << y << ")" << endl;
}

void init( void )
{
    //Selecionar cor de fundo preto
    glClearColor( 0.0, 0.0, 0.0, 0.0 );
    
    //Inicializar sistema de visualizaçao
    glMatrixMode( GL_PROJECTION );
    glOrtho( 1.0 ,0.0, 1.0, 0.0, -1.0, 1.0 );
    glLoadIdentity();
}    

int main(int argc, char *argv[])
{
    primitiva = -1;
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB );
    glutInitWindowSize( 500.0, 200.0 ); // TAMANHO DA JANELA
    //glutInitWindowPosition( 300, 75 ); // POSIÇÃO DA JANELA
    glutCreateWindow( "AT1" );
    
    init();
//	glutMouseFunc( mouse );    
	glutDisplayFunc( display );
  	glutMouseFunc( mouse );
    glutPassiveMotionFunc( passiveMotion );
    glutMainLoop();
    return 0;
}
