
// FUNCOES
int colisaoInimigo(int cx, int cy);
void inicializaInimigo();
void desenhaInimigo(void);



typedef struct Inimigo{

	float raio, r, g, b;
	int cx, cy;
	char id[10];

} Inimigo;


Inimigo vetorInimigo[3];

int quantidadeInimigos = 3;


 int colisaoInimigo(int cx, int cy, int raio){


 	for (int i = 0; i < quantidadeInimigos; ++i)
 	{
 		float distInimigo = sqrt(((vetorInimigo[i].cx-cx)*(vetorInimigo[i].cx-cx)) + ((vetorInimigo[i].cy-cy)*(vetorInimigo[i].cy-cy)));
 		float raioTotal = vetorInimigo[i].raio+raio+1;


 	//	printf("distInimigo %f raioTotal %f\n", distInimigo, raioTotal);
 		if(distInimigo<=raioTotal){
    		return 1;
  		}
 	}

  	return 0;

 }



 void inicializaInimigo()
{

	for (int i = 0; i < quantidadeInimigos; ++i)
	{
		vetorInimigo[i].raio=0.0;
		vetorInimigo[i].cx=0;
		vetorInimigo[i].cy=0;
		strcpy(vetorInimigo[i].id,"Inimigo");
	}
              
}



void desenhaInimigo(void)
{    

    
    for (int i = 0; i < quantidadeInimigos; ++i)
    {
    	glPushMatrix();
    	glColor3f(vetorInimigo[i].r, vetorInimigo[i].g, vetorInimigo[i].b);
    	glTranslatef(vetorInimigo[i].cx, vetorInimigo[i].cy,0);
    	circulo(vetorInimigo[i].raio);
    	//printf("%d %d %d %f\n", i+1, vetorInimigo[i].cx, vetorInimigo[i].cy, vetorInimigo[i].raio);
    	glPopMatrix();
    }

  //  glutSwapBuffers();
                             
}


