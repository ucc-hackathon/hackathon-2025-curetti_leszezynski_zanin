#include "claseJ.h"

jugador::jugador(){

  pasos = rand();
  posicion = 1;


}
jugador::jugador(int D){

  int P = rand();
  pasos = P;
  posicion = D; 

}
jugador::jugador(int P, int D){

  pasos = P;
  posicion = D;
  puntos = 0; 

}
void jugador::mover(char D){

int nuevaPos = posicion;
  switch (posicion + 1) {
      case 1: 
          if (D == 'S' || D == 's') nuevaPos = 3;
          break;
      case 2: 
          if (D == 'S' || D == 's') nuevaPos = 4;
          break;
      case 3: 
          if (D == 'N' || D == 'n') nuevaPos = 1;
          else if (D == 'E' || D == 'e') nuevaPos = 4;
          break;
      case 4: 
          if (D == 'N' || D == 'n') nuevaPos = 2;
          else if (D == 'O' || D == 'o') nuevaPos = 5;
          else if (D == 'E' || D == 'e') nuevaPos = 3;
          else if (D == 'S' || D == 's') nuevaPos = 6;
          break;
      case 5: 
          if (D == 'O' || D == 'o') nuevaPos = 4;
          else if (D == 'S' || D == 's') nuevaPos = 7;
          break;
      case 6: 
          if (D == 'N' || D == 'n') nuevaPos = 4;
          else if (D == 'E' || D == 'e') nuevaPos = 7;
          break;
      case 7: 
          if (D == 'O' || D == 'o') nuevaPos = 6;
          else if (D == 'N' || D == 'n') nuevaPos = 5;
           break;
      default:
          cout << "Posición inválida\n";
          break;
  }

  if (nuevaPos != posicion) {
    posicion = nuevaPos;
    pasos--;
    cout << "Te has movido a la habitación " << (posicion) << endl;
  } else {
      cout << "No puedes moverte en esa dirección desde aquí.\n";
  }

};

int jugador::mostrarPuntos(){
  return puntos;
}
int jugador::mostrarPasos(){
  return pasos;
};
string jugador::tomarE(string E){
  puntos++;
  return E;
};
void jugador::mostrarM(){
  cout << "el Mapa es el siguiente" << endl 
       << "|Hab 1|  |Hab 2|" << endl
       << "   |        |   " << endl
       << "|Hab 3|--|Hab 4|--|Hab 5|" << endl
       << "            |        |   " << endl
       << "         |Hab 6|--|Hab 7|" << endl;
};
int jugador::pos(){
  return posicion;
};
jugador::~jugador(){}