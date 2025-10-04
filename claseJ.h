#ifndef CLASEJ_H
#define CLASEJ_H

#include <iostream>
#include <cstdlib>

using namespace std;

class jugador{
private:

  int pasos = 0;
  int posicion = 0; 
  int puntos = 0;

public:

  jugador();
  jugador(int D);
  jugador(int P, int D);
  void mover(char D);
  int mostrarPuntos();
  int mostrarPasos();
  int pos();
  string tomarE(string E);
  void mostrarM();
  ~jugador();

};
#endif