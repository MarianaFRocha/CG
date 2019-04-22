#include <GL/glut.h>
#include <iostream>
#include <cstdio>

#define POINTS 1
#define LINES 2
#define LINE_STRIP 3
#define LINE_LOOP 4
#define POLYGON 5
#define TRIANGLES 6
#define TRIANGLE_STRIP 7
#define TRIANGLE_FAN 8
#define QUADS 9
#define QUAD_STRIP 0

using namespace std;

int primitiva;

void display( void ){
    //Limpar todos os pixels
    glClear( GL_COLOR_BUFFER_BIT );
    glColor3f( 1.0, 1.0, 1.0 );
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1,0xFFFF);

    if( primitiva == POINTS ){
        glPointSize ( 5.0 );
        glBegin( GL_POINTS );
            glColor3f( 1.0, 0.0, 0.0 );
            glVertex3f ( -0.80, -0.00, 0.00 );

            glColor3f( 0.0, 1.0, 0.0 );
            glVertex3f ( 0.80, 0.80, 0.00 );

            glColor3f( 0.0, 0.0, 1.0 );
            glVertex3f ( 0.00, -0.80, 0.00 );

            glColor3f( 1.0, 0.0, 1.0 );
            glVertex3f ( -0.60, -0.60, 0.00 );
        glEnd();
    }

    else if( primitiva == LINES ){
        glLineWidth( 5.0 );
        glBegin( GL_LINES );
            glColor3f( 1.0, 0.0, 0.0 );
            glVertex3f ( -0.80, -0.00, 0.00 );

            glColor3f( 0.0, 1.0, 0.0 );
            glVertex3f ( 0.80, 0.80, 0.00 );

            glColor3f( 0.0, 0.0, 1.0 );
            glVertex3f ( 0.00, -0.80, 0.00 );

            glColor3f( 1.0, 0.0, 1.0 );
            glVertex3f ( -0.60, -0.60, 0.00 );
        glEnd();
    }

    else if( primitiva == LINE_STRIP ){
        glLineWidth( 5.0 );
         glBegin( GL_LINE_STRIP );
            glColor3f( 1.0, 0.0, 0.0 );
            glVertex3f ( -0.80, -0.00, 0.00 );

            glColor3f( 0.0, 1.0, 0.0 );
            glVertex3f ( 0.80, 0.80, 0.00 );

            glColor3f( 0.0, 0.0, 1.0 );
            glVertex3f ( 0.00, -0.80, 0.00 );

            glColor3f( 1.0, 0.0, 1.0 );
            glVertex3f ( -0.60, -0.60, 0.00 );

        glEnd();
    }

    else if( primitiva == LINE_LOOP ){
        glLineWidth( 5.0 );
        glBegin( GL_LINE_LOOP );
            glColor3f( 1.0, 0.0, 0.0 );
            glVertex3f ( -0.80, -0.00, 0.00 );

            glColor3f( 0.0, 1.0, 0.0 );
            glVertex3f ( 0.80, 0.80, 0.00 );

            glColor3f( 0.0, 0.0, 1.0 );
            glVertex3f ( 0.00, -0.80, 0.00 );

            glColor3f( 1.0, 0.0, 1.0 );
            glVertex3f ( -0.60, -0.60, 0.00 );
        glEnd();
    }

    else if( primitiva == POLYGON ){
        glBegin( GL_POLYGON );
            glColor3f( 1.0, 0.0, 0.0 );
            glVertex3f ( -0.80, -0.00, 0.00 );

            glColor3f( 0.0, 1.0, 0.0 );
            glVertex3f ( 0.80, 0.80, 0.00 );

            glColor3f( 0.0, 0.0, 1.0 );
            glVertex3f ( 0.00, -0.80, 0.00 );

            glColor3f( 1.0, 0.0, 1.0 );
            glVertex3f ( -0.60, -0.60, 0.00 );  
        glEnd();
    }

    else if( primitiva == TRIANGLES ){
        glBegin( GL_TRIANGLES );
            glColor3f( 1.0, 0.0, 1.0 );
            glVertex3f ( -0.80, -0.80, 0.00 );
            glVertex3f ( -0.80, 0.80, 0.00 );
            glColor3f( 1.0, 0.0, 0.0 );
            glVertex3f ( -0.20, 0.00, 0.00 );

            glColor3f( 1.0, 0.0, 1.0 );
            glVertex3f ( 0.80, 0.80, 0.00 );
            glVertex3f ( 0.80, -0.80, 0.00 );
            glColor3f( 1.0, 0.0, 0.0 );
            glVertex3f ( 0.20, 0.00, 0.00 );
        glEnd();

    }

    else if(primitiva == TRIANGLE_STRIP){
        glBegin( GL_TRIANGLE_STRIP );
            glVertex3f ( -0.50, -0.20, 0.00 );
            glVertex3f ( -0.20, 0.80, 0.00 );
            glVertex3f ( 0.00, -0.40, 0.00 );
            glVertex3f ( 0.60, 0.40, 0.00 );
            glVertex3f ( 0.80, -0.20, 0.00 );
        glEnd();

        glColor3f( 1.0, 0.0, 0.2 );
        glLineWidth( 2.0 );
        glLineStipple(8,0xAAAA);
        glBegin( GL_LINES );
            glVertex3f ( -0.50, -0.20, 0.00 );
            glVertex3f ( -0.20, 0.80, 0.00 );

            glVertex3f ( -0.20, 0.80, 0.00 );
            glVertex3f ( 0.00, -0.40, 0.00 );

            glVertex3f ( 0.00, -0.40, 0.00 );
            glVertex3f ( 0.60, 0.40, 0.00 );

            glVertex3f ( 0.60, 0.40, 0.00 );
            glVertex3f ( 0.80, -0.20, 0.00 );
        glEnd();

    }
    else if(primitiva ==TRIANGLE_FAN){
        glBegin( GL_TRIANGLE_FAN );
            glVertex3f ( -0.40, 0.50, 0.00 );
            glVertex3f ( -0.60, 0.00, 0.00 );
            glVertex3f ( -0.15, -0.50, 0.00 );
            glVertex3f ( 0.30, -0.40, 0.00 );
            glVertex3f ( 0.60, 0.00, 0.00 );
            glVertex3f ( 0.40, 0.60, 0.00 );
        glEnd();

        glColor3f( 1.0, 0.0, 0.0 );
        glLineWidth( 2.0 );
        glLineStipple(8,0xAAAA);
        glBegin( GL_LINES );
            glVertex3f ( -0.40, 0.50, 0.00 );
            glVertex3f ( -0.60, 0.00, 0.00 );

            glVertex3f ( -0.40, 0.50, 0.00 );
            glVertex3f ( -0.15, -0.50, 0.00 );

            glVertex3f ( -0.40, 0.50, 0.00 );
            glVertex3f ( 0.30, -0.40, 0.00 );

            glVertex3f ( -0.40, 0.50, 0.00 );
            glVertex3f ( 0.60, 0.00, 0.00 );

            glVertex3f ( -0.40, 0.50, 0.00 );
            glVertex3f ( 0.40, 0.60, 0.00 );
        glEnd();
    }

    else if(primitiva == QUADS){
        glBegin( GL_QUADS );
            glVertex3f ( -0.30, 0.20, 0.00 );
            glVertex3f ( -0.30, -0.10, 0.00 );
            glVertex3f ( -0.50, -0.20, 0.00 );
            glVertex3f ( -0.60, 0.10, 0.00 );

            glVertex3f ( -0.10, 0.25, 0.00 );
            glVertex3f ( 0.50, 0.30, 0.00 );
            glVertex3f ( 0.45, -0.10, 0.00 );
            glVertex3f ( 0.00, -0.05, 0.00 );
        glEnd();
    }

    else if(primitiva == QUAD_STRIP){
         glBegin( GL_QUAD_STRIP );
            glVertex3f ( 0.50, 0.80, 0.00 );
            glVertex3f ( 0.70, 0.00, 0.00 );
            glVertex3f ( -0.20, 0.30, 0.00 );
            glVertex3f ( 0.20, -0.20, 0.00 );
            glVertex3f ( -0.70, -0.50, 0.00 );
            glVertex3f ( -0.10, -0.90, 0.00 );
        glEnd();

        glColor3f( 1.0, 0.0, 0.0 );
        glLineWidth( 2.0 );
        glLineStipple(8,0xAAAA);
        glBegin( GL_LINES );
            glVertex3f ( 0.50, 0.80, 0.00 );
            glVertex3f ( 0.70, 0.00, 0.00 );
            glVertex3f ( -0.20, 0.30, 0.00 );
            glVertex3f ( 0.20, -0.20, 0.00 );
            glVertex3f ( -0.70, -0.50, 0.00 );
            glVertex3f ( -0.10, -0.90, 0.00 );
        glEnd();

    }

    glutSwapBuffers();
}

void reshape( int largura, int altura ){ 
    cout << "Largura: " << largura << " Altura: " << altura << endl;
}

void apagaDesenhos(){
    primitiva = -1;
    return;
}

void keyboard(unsigned char tecla, int x, int y){

    //Ativa o desenho de uma determinada primitiva
    if(tecla >= '0' && tecla <= '9') {
        primitiva = tecla - 48;
    }

    //Exibir no terminal as teclas pressionadas
    if(tecla == 13){
        cout << "Tecla pressionada: " << "(Quebra de linha)" << "\tcodigo: "<< (int)tecla;
    }else if(tecla == 8){
        cout << "Tecla pressionada: " << "(Backspace)" << "\tcodigo: "<< (int)tecla;
        apagaDesenhos();
    }else if(tecla == 9){
        cout << "Tecla pressionada: " << "(Tab)" << "\tcodigo: "<< (int)tecla;
    }else if(tecla == 127){
        cout << "Tecla pressionada: " << "(Delete)" << "\tcodigo: "<< (int)tecla;
        apagaDesenhos();
    }else if(tecla == 27) {
        exit(0);
    }else{ 
        cout << "Tecla pressionada: " << (char)tecla << "\tcodigo: "<< (int)tecla;
    }

    //Exibir no terminal o SHIFT/CTRL/ALT
    int SCA = glutGetModifiers();
    if(SCA == 1) cout << "\t SHIFT Pressionado";
    if(SCA == 2) cout << "\t CTRL Pressionado";
    if(SCA == 3) cout << "\t ALgo Pressionado";
    if(SCA == 4) cout << "\t ALT Pressionado";

    cout << endl;
    glutPostRedisplay();
}

void SpecialKeys(int tecla, int x, int y){

    cout << "Tecla especial pressionada - " << tecla <<": ";

    //Verifica se os botões de F1 à F12 estão pressionados
    for(int i = 0;i<12;i++){ 
        if(tecla == (GLUT_KEY_F1 + i))
            cout << "KEY_F" << (i+1);
    }

    //Outras teclas especiais
    switch (tecla){
        case GLUT_KEY_LEFT:
            cout << "KEY_LEFT";
            break;
        case GLUT_KEY_UP:
            cout << "KEY_UP";
            break;
        case GLUT_KEY_RIGHT:
            cout << "KEY_RIGHT";
            break;
        case GLUT_KEY_DOWN:
            cout << "KEY_DOWN";
            break;
        case GLUT_KEY_PAGE_UP:
            cout << "KEY_PAGE_UP";
            break;
        case GLUT_KEY_PAGE_DOWN:
            cout << "KEY_PAGE_DOWN";
            break;
        case GLUT_KEY_HOME:
            cout << "KEY_HOME";
            break;
        case GLUT_KEY_END:
            cout << "KEY_END";
            break;
        case GLUT_KEY_INSERT:
            cout << "KEY_INSERT";
            break;
        case 109:  
            cout << "KEY_NUM_LOCK";
            break;
        case 112:  
            cout << "KEY_LEFT_SHIFT";
            break;
        case 113:  
            cout << "KEY_RIGTH_SHIFT";
            break;
        case 114:
            cout << "KEY_LEFT_CTRL";
            break;
        case 116:
            cout << "KEY_LEFT_ALT";
            break;
    }
    cout << endl;
}

void mouse(int botao, int estado, int x, int y){
    switch(botao){
        case GLUT_LEFT_BUTTON:
            cout << "Botao esquerdo ";
            break;
        case GLUT_RIGHT_BUTTON:
            cout << "Botao direito ";
            break;            
    }
    if(botao == GLUT_LEFT_BUTTON || botao == GLUT_RIGHT_BUTTON){
        switch(estado){
            case GLUT_DOWN:
                cout << "pressionado";
                break;
            case GLUT_UP:
                cout << "liberado";
                break;
        }
        cout << endl;
    }
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
    glutInitWindowSize( 500, 500 );
    glutInitWindowPosition( 70, 75 );
    glutCreateWindow( "Primeira lista de exercícios" );
    
    init();
    glutDisplayFunc( display );
    glutReshapeFunc( reshape );
    glutKeyboardFunc ( keyboard );
    glutSpecialFunc( SpecialKeys );
    glutMouseFunc( mouse );
    glutPassiveMotionFunc( passiveMotion );
    glutMainLoop();
    return 0;
}
