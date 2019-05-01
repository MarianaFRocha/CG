
// FUNCOES
void parseXML(char *nomeXML, char *nomeSVG, float *velTiro, float *freqTiro, float *velInimigo, float *velTiroInimigo);
void parse(char *nomeArquivo, char *aux, int num, int *cx, int *cy, float *raio, float *r , float *g, float *b);
void parseLargada(char *nomeArquivo, int *xLargada, int *yLargada, int *wLargada, int *hLargada, char *cor);
void selecionaCor(char *cor, float *r , float *g, float *b);



//Função que lê as informações do arquivo XML
void parseXML(char *nomeXML, char *nomeSVG, float *velTiro, float *freqTiro, float *velInimigo, float *velTiroInimigo){

 char nomeArquivo[25]="";

  TiXmlDocument arq;

  if(arq.LoadFile(nomeXML)){

    TiXmlElement *arquivo = arq.FirstChildElement("aplicacao")->FirstChildElement("arquivoDaArena");

    char *caminho= (char*) arquivo->Attribute("caminho");
    if(strcmp(caminho, "")!=0 && strcmp(caminho, "coloque o seu caminho aqui para testar")!=0)
    {
        strcat(nomeArquivo,caminho);
        strcat(nomeArquivo,"/");
    }

    char *nome= (char*) arquivo->Attribute("nome");
    strcat(nomeArquivo,nome);
    //printf("nome %s\n", nome);
    strcat(nomeArquivo,".");

    char *tipo= (char*) arquivo->Attribute("tipo");
    strcat(nomeArquivo,tipo);

    strcpy(nomeSVG, nomeArquivo);

    //printf("%s\n", nomeArquivo);

    TiXmlElement *carro = arq.FirstChildElement("aplicacao")->FirstChildElement("carro");
    carro->QueryFloatAttribute("velTiro", velTiro);

    TiXmlElement *inimigo = arq.FirstChildElement("aplicacao")->FirstChildElement("inimigo");
    inimigo->QueryFloatAttribute("freqTiro", freqTiro);
    inimigo->QueryFloatAttribute("velInimigo", velInimigo);
    inimigo->QueryFloatAttribute("velTiro", velTiroInimigo);

  }else{
    printf("Falha na leitura do arquivo!!\n");
  }

  return;

}


//Função que lê as informações do arquivo SVG
void parse(char *nomeArquivo, char *aux, int num, int *cx, int *cy, float *raio, float *r , float *g, float *b){

  TiXmlDocument arquivo(nomeArquivo);

  int x=1;


  if(arquivo.LoadFile()){


    TiXmlElement *circulo = arquivo.FirstChildElement("svg")->FirstChildElement("circle");

    //Busca no arquivo o id da informação que deseja ler
    char *i = (char*) circulo->Attribute("id");


    while(strcmp(i, aux)!=0 || x!=num){

      //printf("\n %s %s %d %d\n", i, aux, x, num);

       if(strcmp(i, aux) == 0){
        x++;
      }

      //Teste para ver se os dados informados existem no arquivo
      //E nao passar do limito do arquivo svg - nao acontecer erro de segmentacao
      if(circulo=circulo->NextSiblingElement("circle")){
        i = (char*) circulo->Attribute("id");
      }else{
        printf("Nao foi possivel encontrar elemento no arquivo svg !!\n");
      }
    }

    //Le as informacoes do svg

    circulo->QueryIntAttribute("cx", cx);
    circulo->QueryIntAttribute("cy", cy);
    circulo->QueryFloatAttribute("r", raio);
    char *cor = (char*) circulo->Attribute("fill");

    selecionaCor(cor, r, g, b);


  }else{
    printf("Falha na leitura do arquivo!!\n");
  }

  return;

}


void parseLargada(char *nomeArquivo, int *xLargada, int *yLargada, int *wLargada, int *hLargada, char *cor){


  TiXmlDocument arquivo(nomeArquivo);

  if(arquivo.LoadFile()){

    TiXmlElement *largada = arquivo.FirstChildElement("svg")->FirstChildElement("rect");

    largada->QueryIntAttribute("x", xLargada);
    largada->QueryIntAttribute("y", yLargada);
    largada->QueryIntAttribute("width", wLargada);
    largada->QueryIntAttribute("height", hLargada);
    char *auxCor=(char*) largada->Attribute("fill");

    cor=auxCor;

 }else{
    printf("Falha na leitura do arquivo!!\n");
  }

 // printf("%d %d %d %d \n", xLargada, yLargada, wLargada, hLargada);

  return;

}



void selecionaCor(char *cor, float *r , float *g, float *b){

    if(strcmp(cor, "white") == 0){
      *r=1.0 , *g=1.0, *b=1.0;
    }

    if(strcmp(cor, "black") == 0){
      *r=0 , *g=0, *b=0;
    }

    if(strcmp(cor, "red") == 0){
      *r=1.0 , *g=0, *b=0;
    }

    if(strcmp(cor, "green") == 0){
      *r=0 , *g=1.0, *b=0;
    }

    if(strcmp(cor, "blue") == 0){
      *r=0 , *g=0, *b=1.0;
    }
}
