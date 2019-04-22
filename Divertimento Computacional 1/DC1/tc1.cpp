

#include <GL/glut.h>
#include <stdio.h>
#include <string.h>
#include "tinyxml/tinyxml.h"


float larguraJanela, alturaJanela, tamanhoQuadrado, corJanelaR, corJanelaG, corJanelaB, corQuadradoR, corQuadradoG, corQuadradoB;
float posicaoX, posicaoY;
char tituloJanela[300];

int primitiva; //Flag para o botão esquerdo ou direito do mouse

//Função que lê as informações do arquivo XML
void parse(char *nomeArquivo){


	TiXmlDocument arquivo; 
	if(arquivo.LoadFile(nomeArquivo)){

		TiXmlElement *aplicacao = arquivo.FirstChildElement();
		

		//Lendo do XML Info da Janala
		TiXmlElement *janela = aplicacao->FirstChildElement("janela");

		//Largura
		char *larguraInfo = (char*)janela->FirstChildElement("largura")->GetText();
		larguraJanela=atoi(larguraInfo);

		//Altura
		char *alturaInfo = (char*)janela->FirstChildElement("altura")->GetText();
		alturaJanela=atoi(alturaInfo);

		//Cor de Fundo
		janela->FirstChildElement("fundo")->QueryFloatAttribute("corR", &corJanelaR);
		janela->FirstChildElement("fundo")->QueryFloatAttribute("corG", &corJanelaG);
		janela->FirstChildElement("fundo")->QueryFloatAttribute("corB", &corJanelaB);

		//Titulo
		char *tituloInfo = (char*)janela->FirstChildElement("titulo")->GetText();
		strcpy(tituloJanela, tituloInfo);		

		//Lendo do XML Info do Quadrado
		TiXmlElement *quadrado = aplicacao->FirstChildElement("quadrado");

		//Tamanho
		quadrado->QueryFloatAttribute("tamanho", &tamanhoQuadrado);

		//Cor do Quadrado
		quadrado->QueryFloatAttribute("corR", &corQuadradoR);
		quadrado->QueryFloatAttribute("corG", &corQuadradoG);
		quadrado->QueryFloatAttribute("corB", &corQuadradoB);



	}else{
		printf("Falha na leitura do arquivo!!\n");
	}


	return; 

}


void display( void ){
	
    //Limpar todos os pixels
    glClear( GL_COLOR_BUFFER_BIT );
    glColor3f( corQuadradoR, corQuadradoG, corQuadradoB); //Define a cor do quadrado
    glEnable(GL_LINE_STIPPLE);

    float metade=tamanhoQuadrado/2.0;


	if(primitiva == 1)
	{
	        glBegin( GL_QUADS );        

        	glVertex2f ( posicaoX-metade, posicaoY+metade); // TAMANHO //1  2 localização dos vertices
            glVertex2f ( posicaoX-metade, posicaoY-metade);//            3  4
            glVertex2f ( posicaoX+metade, posicaoY-metade);
            glVertex2f ( posicaoX+metade, posicaoY+metade);

        glEnd();
    }
    
    glutPostRedisplay();  //Ficar exibindo novamente - Para arrastar -
    glFlush();
}




void init( void )
{
	//Selecionar cor de fundo
    glClearColor(corJanelaR, corJanelaG, corJanelaB ,0.0f);    
    //Inicializar sistema de visualizaçao
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    
}


void mouse(int botao, int estado, int x, int y)
{

	if(botao==GLUT_LEFT_BUTTON && estado==GLUT_DOWN)  //Botão esquerdo presionado pega as posições de x e y para o quadrado
	{
		primitiva=1;
		posicaoX=x;
		posicaoY=y;
	}
	if(botao==GLUT_RIGHT_BUTTON && estado==GLUT_DOWN) //Botão direito apaga o quadrado
	{
		primitiva=-1;
	}

	display();
	
}

void mover(int x, int y){

	if(primitiva==1)
	{
		primitiva=1;
		posicaoX=x;
		posicaoY=y;
	}

}


void reshape(GLsizei w, GLsizei h){

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();

   glViewport(0, 0, w, h); //Define dimensao
   gluOrtho2D (0.0f, larguraJanela, alturaJanela, 0.0f); //especificar coordenadas
}



int main (int argc, char *argv[]){

	if(argc < 2)  //Confere se o arquivo xml foi passado
  	{
		printf("\nErro: Arquivo nao enderecado !!!\n\n");
        	exit(1);
	}

	parse(argv[1]); 

	//printf("\n\ntitulo: %s largura %f altura %f corR %d corB %d corG %d \n", tituloJanela, larguraJanela, alturaJanela, corJanelaR, corJanelaB, corJanelaB);
	//printf("Quadrado- Tamanho %f corR %d corG %d corB %d \n", tamanhoQuadrado, corQuadradoR, corQuadradoG,corQuadradoB);


	primitiva = -1;
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
    glutInitWindowSize( larguraJanela,  alturaJanela); // TAMANHO DA JANELA
    glutCreateWindow(tituloJanela);
    init();
	glutDisplayFunc(display); 
  	glutMouseFunc(mouse);
  	glutMotionFunc(mover);
  	glutReshapeFunc(reshape);
  
    glutMainLoop();

	return 0;
}