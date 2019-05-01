
//Carro
//Voltas que o carro da na arena
int voltas;
bool checkpoint[4];
bool jogo=true;
bool venceu=false;
int contVida=10;

//Circulo limite do carro - Dados do svg
float raioJodador, rJogador, gJogador, bJogador;
//int cxJogador, cyJogador;

//tiro
float velTiro, raioTiro;
int flagCanhao=0;

//Desenho do Carro
int corpoLargura, corpoAltura;
int eixoLargura, eixoAltura;
int rodaLargura, rodaAltura, deslocamantoX;
int canhaoLargura, canhaoAltura;
float raioX, raioY; //raio das rodas
float descargaAltura, descargaLargura;
float lateralTriangulo;

//Posicao
float cx,cy,xAnterior, yAnterior;

//Movimento
int angRoda=0, angCarro=90, flagMovimento;
float angCanhao;

//Inimigo
float freqTiro, velInimigo, velInimigo2, velInimigo3, velTiroInimigo;

//Arena
float raioCirculo1, raioCirculo2, rCirculo1, gCirculo1, bCirculo1, rCirculo2, gCirculo2, bCirculo2;
int cxCirculo1, cyCirculo1, cxCirculo2, cyCirculo2;

//Largada
int xLargada, yLargada, wLargada, hLargada;
float rLargada, gLargada, bLargada;
