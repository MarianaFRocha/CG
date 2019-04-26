#include <GL/glut.h>
#include <stdio.h>           
           
GLfloat win;
// ** Declare as variáveis globais responsáveis pela movimentação dos objetos          


int dx, andaBorboleta=0, passo=1, andaBorboleta1=0, passo1=2;
float ang;
           
           
void DesenhaBorboleta()
{
        glColor3f(1,0.2,1);

       glLineWidth(2);
       glBegin(GL_LINE_LOOP); 
            glVertex2f(0.5,1.0);
            glVertex2f(0.5,-1.0);
            glVertex2f(-0.5,1.0);
            glVertex2f(-0.5,-1.0);
       glEnd();
}
           
           
void DesenhaBraco()
{

        glColor3f(0.2,0.5,0.2);


        glLineWidth(2);
        glBegin(GL_LINE_LOOP);
                   glVertex2f(-1.0,-0.8);
                   glVertex2f(1.0,-0.8);
                   glVertex2f(1.0,4.6);                 
                   glVertex2f(-1.0,4.6);
        glEnd();
        glPointSize(2);
        glBegin(GL_POINTS);
                   glVertex2i(0,0);   
        glEnd();
 }
           
           
void DesenhaBase()
{

        glColor3f(0.5,0.2,0.8);

         glLineWidth(2);
         glBegin(GL_LINE_LOOP);
					glVertex2f(-1.5,-1.5);
					glVertex2f(-1.0,-1.5);
					glVertex2f(-1.0,-1);
					glVertex2f(1.0,-1);
					glVertex2f(1.0,-1.5);
					glVertex2f(1.5,-1.5);
					glVertex2f(1.5,1);       
					glVertex2f(-1.5,1);
          glEnd();
}
           
           
// Callback chamada para fazer o desenho
void Desenha(void)
{
           glMatrixMode(GL_MODELVIEW);
           glLoadIdentity();
                              
           glClear(GL_COLOR_BUFFER_BIT);
                   
           // ** Chame as funções adequadas para fazer o desenho
           glPushMatrix();

            glTranslatef(dx, 0,0);

              glPushMatrix();
                glScalef(1.5,1.5,1);
                DesenhaBase();
              glPopMatrix();

              glPushMatrix();
                glRotatef(ang,0,0,1);
                glTranslatef(0, 1,0);  
                DesenhaBraco();
              glPopMatrix();

            glPopMatrix();


          glPushMatrix();
            glTranslatef(andaBorboleta, 10,0);
            DesenhaBorboleta();
          glPopMatrix();


          glPushMatrix();
            glColor3f(1,0.2,0.6);
            glTranslatef(andaBorboleta1, 13,0);
            DesenhaBorboleta();
          glPopMatrix();


                                       
           glFlush();
}


// Responsável pelas inicializações
void Inicializa(void)
{
          dx=0;
          ang=0.0;
           // Set clear color to blue
           glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

           win = 20;

           // ** Faça aqui a inicialização das variáveis globais
               
           printf(" Setas para esquerda e para direita movimentam a base (vermelha)");
           printf("\n Home e End rotacionam o braco 1 (verde)");
           printf("\n PageUP e PageDn rotacionam o braco 2 (azul)");
}


// Callback chamada quando o tamanho da janela é alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
            // Especifica o tamanho da Viewport 
            glViewport(0, 0, w, h);

            // Inicializa o sistema de coordenadas
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();

            // Estabelece o volume de visualização (left, right, bottom, top)
            gluOrtho2D (-win, win, -win, win);
}
           
           
// Callback chamada de acordo com um  "idle" 
void Timer(int value)
{
             // ** Altere aqui a(s) variável(is) responsável(is) pelo movimento da "borboleta"

          if(value ==1){

            if(andaBorboleta>win-2 || andaBorboleta<-win+2)
                passo=-passo;

            andaBorboleta+=passo;

            glutPostRedisplay();
            glutTimerFunc(120,Timer, 1);

          }
          if(value == 2){


            if(andaBorboleta1>win-2 || andaBorboleta1<-win+2)
                passo1=-passo1;

            andaBorboleta1+=passo1;

            glutPostRedisplay();
            glutTimerFunc(100,Timer, 2);


          }

}


// Callback chamada quando as teclas especiais são pressionadas
void TeclasEspeciais(int key, int x, int y)
{
             // Move a base
	         if(key == GLUT_KEY_LEFT)
			        dx--;  

            if(key == GLUT_KEY_RIGHT)
		          dx++;
             // Rotaciona braco1
            if(key == GLUT_KEY_HOME)
              ang--;
			        // ** Incremente/Decremente a variável adequada
            if(key == GLUT_KEY_END)

              ang++;
		            // ** Incremente/Decremente a variável adequada
              
             // Rotaciona braco2
             if(key == GLUT_KEY_PAGE_UP)
			        // ** Incremente/Decremente a variável adequada
             if(key == GLUT_KEY_PAGE_DOWN)
		            // ** Incremente/Decremente a variável adequada              
                                                
             glutPostRedisplay();
}


// Programa principal
int main(int argc, char *argv[])
{
			 glutInit(&argc,argv);//inicializa
             glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
             glutInitWindowSize(400,350);
             glutInitWindowPosition(10,10);
             glutCreateWindow("Exemplo");
             Inicializa();
             glutDisplayFunc(Desenha);
             glutReshapeFunc(AlteraTamanhoJanela);
             glutSpecialFunc(TeclasEspeciais);
             glutTimerFunc(120, Timer, 1);
             glutTimerFunc(100, Timer, 2);
             glutMainLoop();
}
