#include <iostream>
#include "claseJ.h"
#include "claseH.h"

using namespace std;

int main(){

  habi* H[7];
  jugador* j1;
  int Act = 0;
  char dir = 'o';
  int posi = 0;

  j1 = new jugador(5, 0);
  for (int i = 0; i < 7; i++){
    
    H[i] = new habi("arma");

  }
  do{
   cout << "que desea realizar" << endl
       << "1- mostrar Mapa" << endl
       << "2- Moverte" << endl
       << "3- tomar objeto" << endl;
    cin >> Act;
    switch (Act) {
    case 1:
        j1->mostrarM();
        posi = j1->pos();
        cout << "Pos actual: hab " << posi + 1 << endl;
      break;
    case 2:
        cout << "Donde te quieres mover (N/E/O/S)?" << endl;
        cin >> dir;
        j1->mover(dir);
      break;
    case 3:
        posi = j1->pos();
        cout << "Pos actual: hab" << posi + 1 << endl;
        cout << "Objeto obtenido: " << j1->tomarE(H[posi]->eliminarE()) << endl;
      break;
    
    default:

      cout << "no es una accion valida" <<endl;

      break;
    }
    system("PAUSE");
    system("cls");

  } while (j1->mostrarPasos() > 0);
   
  delete j1;
  for (int i = 0; i < 7; i++) {
    delete H[i];
  }
  
  return 0;
}