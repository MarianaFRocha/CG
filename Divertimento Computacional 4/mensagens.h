

void criaMensagem(char *string){
  int c;
  for (c=0; string[c] != '\0'; c++) {
		glutStrokeCharacter(GLUT_STROKE_ROMAN, string[c]);
	}
}


void mensagemTela(int voltas, int contVida){

  std::string auxMensagem;
  std::ostringstream aux, aux2;
  aux << voltas;

  auxMensagem = "VOLTAS : ";
  auxMensagem += aux.str();

  char* mensagem1 = (char *)alloca(auxMensagem.size() + 1);
  memcpy(mensagem1, auxMensagem.c_str(), auxMensagem.size() + 1);

  aux2 << contVida;

  auxMensagem = "VIDAS : ";
  auxMensagem += aux2.str();

  char* mensagem2 = (char *)alloca(auxMensagem.size() + 1);
  memcpy(mensagem2, auxMensagem.c_str(), auxMensagem.size() + 1);

  glPushMatrix();
    glTranslatef(cxCirculo1-raioCirculo1+10, cyCirculo1+raioCirculo1-30, 0);
    glScalef(0.15, 0.15, 0);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glLineWidth(3.0);
    glColor3f(0.0, 0.0, 0.0);
    criaMensagem(mensagem1);
  glPopMatrix();

  glPushMatrix();
    glTranslatef(cxCirculo1-raioCirculo1+10, cyCirculo1+raioCirculo1-50, 0);
    glScalef(0.15, 0.15, 0);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glLineWidth(3.0);
    glColor3f(0.0, 0.0, 0.0);
    criaMensagem(mensagem2);
  glPopMatrix();

}

void mensagemGameOver(){

  std::string auxMensagem;

  auxMensagem = "GAME OVER";

  char* mensagem = (char *)alloca(auxMensagem.size() + 1);
  memcpy(mensagem, auxMensagem.c_str(), auxMensagem.size() + 1);

  glPushMatrix();
    glTranslatef(cxCirculo1-200, cyCirculo1, 0);
    glScalef(0.5, 0.5, 0);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glLineWidth(5.0);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glColor3f(1.0, 0.0, 0.0);
    criaMensagem(mensagem);
  glPopMatrix();

}

void mensagemVitoria(){

  std::string auxMensagem;
  auxMensagem = "VOCE VENCEU";

  char* mensagem = (char *)alloca(auxMensagem.size() + 1);
  memcpy(mensagem, auxMensagem.c_str(), auxMensagem.size() + 1);

  glPushMatrix();
    glTranslatef(cxCirculo1-225, cyCirculo1, 0);
    glScalef(0.5, 0.5, 0);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glLineWidth(5.0);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glColor3f(0.0, 1.0, 0.0);
    criaMensagem(mensagem);
  glPopMatrix();

}
