
int raioTiroInimigo=5;

typedef struct TiroInimigo{

    float cxTiro, cyTiro, sen, cos;

}TiroInimigo;


typedef struct Inimigo{

	float raio, r, g, b;
	int cx, cy;
	char id[10];
	bool vivo;
	std::vector<TiroInimigo> tiros;

} Inimigo;

Inimigo vetorInimigo[3];

int quantidadeInimigos = 3;

// FUNCOES
int colisaoInimigo(int cx, int cy);
void inicializaInimigo();
void desenhaInimigo(void);
void desenhaTiroInimigo();
int colisaoJogador(int cxIn, int cyIn, int raioIn);
TiroInimigo balaInimigo(Inimigo i);


void movimentaInimigo(Inimigo i){

		if(limitesArena(i.cx, i.cy, i.raio)){
			i.cx++;
			i.cx--;
		}

}

void Timer(int value)
{

		if(value==1){

				if(limitesArena(vetorInimigo[0].cx, vetorInimigo[0].cy, vetorInimigo[0].raio)==1 || colisaoJogador(vetorInimigo[0].cx, vetorInimigo[0].cy, vetorInimigo[0].raio)== 1){
					velInimigo3=-velInimigo3;
				}

				vetorInimigo[0].cy+=velInimigo3;

				if(limitesArena(vetorInimigo[1].cx, vetorInimigo[1].cy, vetorInimigo[1].raio)==1 || colisaoJogador(vetorInimigo[1].cx, vetorInimigo[1].cy, vetorInimigo[1].raio)== 1){
					velInimigo2=-velInimigo2;
				}

				vetorInimigo[1].cx+=velInimigo2;


				if(limitesArena(vetorInimigo[2].cx, vetorInimigo[2].cy, vetorInimigo[2].raio)==1 || colisaoJogador(vetorInimigo[2].cx, vetorInimigo[2].cy, vetorInimigo[2].raio)== 1){
					velInimigo=-velInimigo;
				}

				vetorInimigo[2].cx+=velInimigo;
				vetorInimigo[2].cy+=velInimigo;
				//printf("2 %d %d\n", vetorInimigo[2].cx, vetorInimigo[2].cy);

				glutPostRedisplay();
				glutTimerFunc(50,Timer, 1);

			}

		if(value==2){

			for (int i = 0; i < quantidadeInimigos; i++) {
				if(vetorInimigo[i].vivo == false){
          vetorInimigo[i].vivo=true;
        }
      }

      glutTimerFunc(7000,Timer, 2);
      glutPostRedisplay();

		}

		if (value==3) {
			for (int i = 0; i < 3; i++) {
				if(vetorInimigo[i].vivo == true)
					vetorInimigo[i].tiros.push_back(balaInimigo(vetorInimigo[i]));
			}

      float inc = freqTiro*10000;
    //  printf("%f\n", freqTiro*10000);

			glutPostRedisplay();
			glutTimerFunc(1500*inc,Timer, 3);
		}

}


 int colisaoInimigo(int cx, int cy, int raio){


	 	for (int i = 0; i < quantidadeInimigos; ++i)
	 	{
			if(vetorInimigo[i].vivo==true){
		 		float distInimigo = sqrt(((vetorInimigo[i].cx-cx)*(vetorInimigo[i].cx-cx)) + ((vetorInimigo[i].cy-cy)*(vetorInimigo[i].cy-cy)));
		 		float raioTotal = vetorInimigo[i].raio+raio+1;
		 		//printf("distInimigo %f raioTotal %f\n", distInimigo, raioTotal);
		 		if(distInimigo<=raioTotal){
		    		return 1;
		  		}
			}
	 	}
  	return 0;
 }

 int inimigoAtingido(int cx, int cy, int raio){

	 for (int i = 0; i < quantidadeInimigos; ++i)
	 {
		 float distInimigo = sqrt(((vetorInimigo[i].cx-cx)*(vetorInimigo[i].cx-cx)) + ((vetorInimigo[i].cy-cy)*(vetorInimigo[i].cy-cy)));
		 float raioTotal = vetorInimigo[i].raio+raio+1;
	 //	printf("distInimigo %f raioTotal %f\n", distInimigo, raioTotal);
		 if(distInimigo<=raioTotal){
			 return i;
		 }
	 }
	 return -1;
 }

 void inicializaInimigo()
{
		velInimigo=velInimigo*20;
		velInimigo2=velInimigo*2;
		velInimigo3=velInimigo*2;

		for (int i = 0; i < quantidadeInimigos; ++i)
		{
			vetorInimigo[i].raio=0.0;
			vetorInimigo[i].cx=0;
			vetorInimigo[i].cy=0;
			strcpy(vetorInimigo[i].id,"Inimigo");
			vetorInimigo[i].vivo=true;
		}

}


void desenhaInimigo(void)
{
		desenhaTiroInimigo();

    for (int i = 0; i < quantidadeInimigos; ++i)
    {
			if (vetorInimigo[i].vivo==true) {
				glPushMatrix();
	    	glColor3f(vetorInimigo[i].r, vetorInimigo[i].g, vetorInimigo[i].b);
	    	glTranslatef(vetorInimigo[i].cx, vetorInimigo[i].cy,0);
	    	circulo(vetorInimigo[i].raio);
	    	//printf("%d %d %d %f\n", i+1, vetorInimigo[i].cx, vetorInimigo[i].cy, vetorInimigo[i].raio);
				movimentaInimigo(vetorInimigo[i]);
	    	glPopMatrix();
			}
    }
}


TiroInimigo balaInimigo(Inimigo i){

  TiroInimigo t;

	float dx, dy, r;

	dx = i.cx - cx;
  dy = i.cy - cy;
	r = sqrt(dx*dx + dy*dy);

	t.cos = -dx / r;
  t.sen = -dy / r;
  t.cxTiro = i.cx + t.cos*i.raio;
  t.cyTiro = i.cy + t.sen*i.raio;

	//printf("OK %f \n");

  return t;
}

int colisaoJogador(int cxIn, int cyIn, int raioIn){

	float distJogador = sqrt(((cx-cxIn)*(cx-cxIn)) + ((cy-cyIn)*(cy-cyIn)));
	float raioTotal = raioIn+raioJodador;
	//	printf("distInimigo %f raioTotal %f\n", distInimigo, raioTotal);
	if(distJogador<=raioTotal){
		return 1;
	}
	return 0;

}



void desenhaTiroInimigo(){

	for (int i = 0; i < 3; i++) {
		  if(vetorInimigo[i].tiros.size()>0){

		    for(int j = 0; j < vetorInimigo[i].tiros.size(); j++){
		        glPushMatrix();
		        glColor3f(1.0, 0.8, 0.8);
		        glTranslatef(vetorInimigo[i].tiros[j].cxTiro, vetorInimigo[i].tiros[j].cyTiro, 0);
		        circulo(raioTiroInimigo);

		        float auxX= vetorInimigo[i].tiros[j].cxTiro + vetorInimigo[i].tiros[j].cos*velTiroInimigo;
		        float auxY= vetorInimigo[i].tiros[j].cyTiro + vetorInimigo[i].tiros[j].sen*velTiroInimigo;

		        if(limitesArena(auxX, auxY, raioTiro) == 0 && colisaoJogador(auxX, auxY, raioTiroInimigo) == 0){
							vetorInimigo[i].tiros[j].cxTiro += vetorInimigo[i].tiros[j].cos*velTiroInimigo*10;
			        vetorInimigo[i].tiros[j].cyTiro += vetorInimigo[i].tiros[j].sen*velTiroInimigo*10;
		        }else{
		          if(colisaoJogador(auxX, auxY, raioTiroInimigo) == 1){
								if(contVida==0){
		            	venceu=false;
									jogo=false;
								}else{
									contVida--;
								}
		          }
		          vetorInimigo[i].tiros.erase(vetorInimigo[i].tiros.begin()+j);
		        }
		        glPopMatrix();

		    	}
		  	}
	}
  glutPostRedisplay();
}
