
// FUNCOES
void desenhaCarro(void);
void inicializaCarro(void);
void desenhaTiro();
void contadorVoltas();
void controleVoltas();
void inicializaCheckPoint();


//Variaveis do Carro

typedef struct Tiro{

    float cxTiro, cyTiro, angTiro;

}Tiro;

std::vector<Tiro> tiros;


void desenhaCarro(void)
{
    desenhaTiro();
    controleVoltas();

    if(angCarro>=360 || angCarro<=-360){
      angCarro=0;
    }

    glPushMatrix();

      glTranslatef(cx,cy,0);
      glRotatef(angCarro,0,0,1);
      glRotatef(-90,0,0,1);

      //eixos das rodas e veiculo
      //direito inferior
      glPushMatrix();
      glColor3f(0.4, 0.4, 1);
      glTranslatef(corpoLargura/2,((2*eixoAltura)-corpoAltura/2),0);
      retangulo(eixoLargura, eixoAltura);
      glPopMatrix();

      //direito superior
      glPushMatrix();
      glColor3f(0.4, 0.4, 1);
      glTranslatef(corpoLargura/2,((corpoAltura/2-(3*eixoAltura))),0);
      retangulo(eixoLargura, eixoAltura);
      glPopMatrix();

      //esquerdo inferior
      glPushMatrix();
      glColor3f(0.4, 0.4, 1);
      glTranslatef(-corpoLargura,((2*eixoAltura)-corpoAltura/2),0);
      retangulo(eixoLargura, eixoAltura);
      glPopMatrix();

      //direito superior
      glPushMatrix();
      glColor3f(0.4, 0.4, 1);
      glTranslatef(-corpoLargura,((corpoAltura/2-(3*eixoAltura))),0);
      retangulo(eixoLargura, eixoAltura);
      glPopMatrix();

      //Rodas

      //roda direita inferior
      glPushMatrix();
      glColor3f(0.2, 0.2, 0.2);
      glTranslatef((eixoLargura/2)+corpoLargura/2,(eixoAltura-corpoAltura/2),0);
      retangulo(rodaLargura, rodaAltura);
      glPopMatrix();


      //esquerdo inferior
      glPushMatrix();
      glColor3f(0.2, 0.2, 0.2);
      glTranslatef(-(eixoLargura/2)-corpoLargura,(eixoAltura-corpoAltura/2),0);
      retangulo(rodaLargura, rodaAltura);
      glPopMatrix();

      //direito superior
      glPushMatrix();
      glColor3f(0.2, 0.2, 0.2);
      glTranslatef((eixoLargura/2)+corpoLargura/2+rodaLargura/2,((corpoAltura/2-(4*eixoAltura))+rodaAltura/2),0);
      glRotatef(angRoda,0,0,1);
      glTranslatef(-rodaLargura/2, -rodaAltura/2,0);
      retangulo(rodaLargura, rodaAltura);
      glPopMatrix();

      //esquerdo superior
      glPushMatrix();
      glColor3f(0.2, 0.2, 0.2);
      glTranslatef(-(eixoLargura/2)-corpoLargura+rodaLargura/2,(rodaAltura/2+(corpoAltura/2-(4*eixoAltura))),0);
      glRotatef(angRoda,0,0,1);
      glTranslatef(-rodaLargura/2, -rodaAltura/2,0);
      retangulo(rodaLargura, rodaAltura);
      glPopMatrix();

      //Canhao
      glPushMatrix();
      glColor3f(0.09, 0.75, 0.5);
      glTranslatef(0,((corpoAltura/2)),0);
      glRotatef(angCanhao,0,0,1);
      glTranslatef(-canhaoLargura/2,0,0);
      retangulo(canhaoLargura, canhaoAltura);
      glPopMatrix();

      //corpo do veiculo
      glPushMatrix();
      glColor3f(0.4, 1, 0.4);
      glTranslatef(-(corpoLargura/2),-(corpoAltura/2),0);
      retangulo(corpoLargura, corpoAltura);
      glPopMatrix();


     //movimento

      glPushMatrix();
      glColor3f(0.3, 0.3, 0.3);
      glTranslatef(-(corpoLargura/2)+descargaLargura,-(corpoAltura/2)-descargaAltura,0);
      retangulo(descargaLargura, descargaAltura);
      glPopMatrix();


      glPushMatrix();
      glColor3f(0.3, 0.3, 0.3);
      glTranslatef(descargaLargura,-(corpoAltura/2)-descargaAltura,0);
      retangulo(descargaLargura, descargaAltura);
      glPopMatrix();

    if(flagMovimento==1) {
      glPushMatrix();
      glColor3f(0.5,0.5,0.5);
      glTranslatef(-(corpoLargura/2)+lateralTriangulo*1.5,-(corpoAltura/2)-descargaAltura-lateralTriangulo,0);
      desenhaTriangulo(lateralTriangulo);
      glPopMatrix();

      glPushMatrix();
      glColor3f(0.5,0.5,0.5);
      glTranslatef(lateralTriangulo*1.5,-(corpoAltura/2)-descargaAltura-lateralTriangulo,0);
      desenhaTriangulo(lateralTriangulo);
      glPopMatrix();

      flagMovimento=0;
    }



      //raio circuferencio do corpo
      glPushMatrix();
      glColor3f(0.09, 0.75, 0.5);
      glTranslatef(0,0,0);
      circuferencia(raioX,raioY);
      glPopMatrix();


    glPopMatrix();

    yAnterior=cy;
}


void inicializaCarro(void)
{
  voltas=0;

  xAnterior=0;
  yAnterior=0;
  angCanhao=0;

  inicializaCheckPoint();

  //corpo
  corpoAltura=((raioJodador*2)-10);
  corpoLargura=corpoAltura/3;
  //eixo
  eixoAltura=corpoAltura/10;
  eixoLargura=corpoLargura/2;
  //roda
  rodaAltura=(corpoAltura/3);
  rodaLargura=eixoLargura;
  deslocamantoX=0;
  //canhão
  canhaoAltura=corpoLargura/1.5;
  canhaoLargura=corpoLargura/2.5;
  //raio circuferencio do corpo
  raioX=corpoLargura/2.5;
  raioY=corpoAltura/3.5;

  raioTiro=corpoAltura/20;

  descargaAltura=corpoAltura/10;
  descargaLargura=0.5*descargaAltura;

  lateralTriangulo=descargaLargura;

  //printf("Jogador %d %d %f %d %d\n", cx, cy, raioJodador, corpoAltura, corpoLargura);

}


//Canhão


void passiveMotion(int x, int y){

  if((angCarro>0 && angCarro<180) || (angCarro>-360 && angCarro<-180)){
    if(x<xAnterior && angCanhao<45){
      angCanhao+=3;
      flagCanhao=1;
    }else{
      if(x>xAnterior && angCanhao>-45){
        angCanhao-=3;
        flagCanhao=1;
      }else{
        flagCanhao=0;
      }
    }
  }else{

    if(angCarro<0 || angCarro>180){
      if(x>xAnterior && angCanhao<45){
        angCanhao+=3;
        flagCanhao=1;
      }else{
        if(x<xAnterior && angCanhao>-45){
          angCanhao-=3;
          flagCanhao=1;
        }else{
          flagCanhao=0;
        }
      }
    }
  }

  xAnterior=x;

  glutPostRedisplay();

}


Tiro bala(){

  Tiro t;

  t.cxTiro= cx + cos(angCarro*PI/180.0)*(corpoAltura/2) + cos((angCarro+angCanhao)*PI/180.0)*canhaoAltura;
  t.cyTiro= cy + sin(angCarro*PI/180.0)*(corpoAltura/2) + sin((angCarro+angCanhao)*PI/180.0)*canhaoAltura;

  t.angTiro = angCarro + angCanhao;

  return t;

}



void desenhaTiro(){

  if(tiros.size()>0){
    for(int i = 0; i < tiros.size(); i++){
        glPushMatrix();
        glColor3f(1.0, 0.2, 0.2);
        glTranslatef(tiros[i].cxTiro, tiros[i].cyTiro, 0);
        circulo(raioTiro);

        float auxX= tiros[i].cxTiro + cos(tiros[i].angTiro*PI/180.0)*velTiro*10;
        float auxY= tiros[i].cyTiro + sin(tiros[i].angTiro*PI/180.0)*velTiro*10;

        if(limitesArena(auxX, auxY, raioTiro) == 0 && colisaoInimigo(auxX, auxY, raioTiro) == 0){
          tiros[i].cxTiro += cos(tiros[i].angTiro*PI/180.0)*velTiro*10;
          tiros[i].cyTiro += sin(tiros[i].angTiro*PI/180.0)*velTiro*10;
        }else{
          if(colisaoInimigo(auxX, auxY, raioTiro) == 1){
            int ini = inimigoAtingido(auxX, auxY, raioTiro);
            vetorInimigo[ini].vivo=false;
          }
          tiros.erase(tiros.begin()+i);
        }
        glPopMatrix();

    }

  }
  glutPostRedisplay();
}

void inicializaCheckPoint(){

  for (int i = 0; i < 4; i++) {
    checkpoint[i]=false;
  }

}


void controleVoltas(){

    int posicaoX=cx;
    int posicaoY=cy;
    bool flag = true;

    if(voltas == 5){
      jogo=false;
      venceu=true;
    }

    if(posicaoX>=(cxCirculo1+raioCirculo2) && posicaoX<=(cxCirculo1+raioCirculo1) && posicaoY>=(cyCirculo1-5) && posicaoY<=(cyCirculo1+5)){
      checkpoint[0]=true;
      for (int i = 0; i < 4; i++) {
        if(checkpoint[i]==false){
          flag=false;
        }
      }
      if(flag == true){
        voltas++;
        inicializaCheckPoint();
      }
    }
    if(posicaoY>=(cyCirculo1+raioCirculo2) && posicaoY<=(cyCirculo1+raioCirculo1) && posicaoX>=(cxCirculo1-5) && posicaoX<=(cxCirculo1+5)){
      checkpoint[1]=true;
    }
    if(posicaoX>=(cxCirculo1-raioCirculo1) && posicaoX<=(cxCirculo1-raioCirculo2) && posicaoY>=(cyCirculo1-5) && posicaoY<=(cyCirculo1+5)){
      if(checkpoint[1]==true)
        checkpoint[2]=true;
    }
    if(posicaoY>=(cyCirculo1-raioCirculo1) && posicaoY<=(cyCirculo1-raioCirculo2) && posicaoX>=(cxCirculo1-5) && posicaoX<=(cxCirculo1+5)){
      if(checkpoint[2]==true)
        checkpoint[3]=true;
    }

}

// void contadorVoltas(){
//
//   int iniXlargada, fimXlargada, iniYlargada;
//
//   iniYlargada=yLargada;
//   iniXlargada= xLargada - wLargada;
//   fimXlargada=xLargada - wLargada;
//
//    controleVoltas();
//
//   if(cy==iniYlargada && (cx>iniXlargada && cx<fimXlargada)){
//
//     if(((angCarro>0 && angCarro<180) || (angCarro>-360 && angCarro<-180))){
//       printf("entrou\n");
//
//     }
//   }
// }
