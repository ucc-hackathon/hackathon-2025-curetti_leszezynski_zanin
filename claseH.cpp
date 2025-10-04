#include "claseH.h"

  habi::habi(){

    elemento = "arma"; 

  }
  habi::habi(string E){

    elemento = E;

  }
  string habi::eliminarE(){
    string temp = elemento;
    elemento = "";  
    return temp;
  }
  habi::~habi(){}