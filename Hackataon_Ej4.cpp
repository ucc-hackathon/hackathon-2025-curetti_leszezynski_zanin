#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <map>
#include <queue>
using namespace std;

class Tuberia {
private:
    int nASCII;
public:
    Tuberia (int n){
        nASCII = n;
    }
    char getChar() {
        return (char)nASCII;
    }
};

map<char, vector<bool>> conexiones = {
    //   U    D    L    R
    {(char)205, {0,0,1,1}}, // ═
    {(char)186, {1,1,0,0}}, // ║
    {(char)187, {0,1,1,0}}, // ╗
    {(char)188, {1,0,1,0}}, // ╝
    {(char)200, {1,0,0,1}}, // ╚
    {(char)201, {0,1,0,1}}, // ╔
    {(char)202, {0,1,1,1}}, // ╦
    {(char)203, {1,0,1,1}}, // ╩
    {(char)204, {1,1,0,1}}, // ╠
    {(char)185, {1,1,1,0}}, // ╣
    {(char)206, {1,1,1,1}}  // ╬
};

void mostrarTablero(vector<vector<char>> &tablero) {
    int n = tablero.size();
    cout << "   ";
    for(int j=0; j<n; j++) cout << j+1 << " ";
    cout << endl;

    for(int i=0; i<n; i++){
        cout << i+1 << " ";
        if(i+1 < 10) cout << " ";
        for(int j=0; j<n; j++){
            cout << tablero[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void mostrarPiezasJugador(vector<char> &piezasJ) {
    cout << "Piezas disponibles del jugador (" << piezasJ.size() << "):\n";
    for(int i=0; i<(int)piezasJ.size(); i++){
        cout << i+1 << ": " << piezasJ[i] << "  ";
        if((i+1)%15==0) cout << endl;
    }
    cout << "\n" << endl;
}

extern map<char, vector<bool>> conexiones; 

// Movimientos: Up, Down, Left, Right
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// Direcciones opuestas
int opuesto[4] = {1, 0, 3, 2};

int calcularPuntaje(vector<vector<char>> &tablero) {
    int n = tablero.size();
    vector<vector<bool>> visitado(n, vector<bool>(n,false));
    int puntos = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(tablero[i][j] != '.' && !visitado[i][j]){
                int piezas = 0;
                int conexionesTramo = 0;

                queue<pair<int,int>> q;
                q.push({i,j});
                visitado[i][j] = true;

                while(!q.empty()){
                    auto [x,y] = q.front(); q.pop();
                    piezas++;

                    char actual = tablero[x][y];

                    for(int d=0; d<4; d++){
                        int nx = x + dx[d];
                        int ny = y + dy[d];

                        if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
                        char vecino = tablero[nx][ny];

                        // Verificamos conexión válida
                        if(vecino!='.' && conexiones[actual][d] && conexiones[vecino][opuesto[d]]){
                            conexionesTramo++;

                            if(!visitado[nx][ny]){
                                visitado[nx][ny] = true;
                                q.push({nx,ny});
                            }
                        }
                    }
                }
                conexionesTramo /= 2;

                // Puntaje tramo
                puntos += conexionesTramo * piezas;
            }
        }
    }

    return puntos;
}

int main (){
    srand(time(0));

    int n;
    cout << "Ingrese valor del tablero (8 a 20): ";
    cin >> n;

    if(n < 4 || n > 20){
        cout << "Valor fuera de rango." << endl;
        return 1;
    }

    // Piezas posibles
    Tuberia Tuberias [11] = {
        Tuberia (185), Tuberia (186), Tuberia (187),
        Tuberia (188), Tuberia (200), Tuberia (201),
        Tuberia (202), Tuberia (203), Tuberia (204),
        Tuberia (205), Tuberia (206)
    };

    int totalCasillas = n * n;
    int piezasJugador = totalCasillas / 2;
    int piezasPC      = totalCasillas - piezasJugador;

    // Piezas del jugador
    vector<char> piezasJ;
    for(int i=0; i<piezasJugador; i++){
        char c = Tuberias[rand()%11].getChar();
        piezasJ.push_back(c);
    }

    // Tablero vacío
    vector<vector<char>> tablero(n, vector<char>(n, '.'));
    int idxC = 0; 
    int turno = 0;

    // Juego por turnos
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << "\n===== TURNO " << turno+1 << " =====\n";
            mostrarTablero(tablero);

            if(((i*n + j) % 2) == 0){
                // TURNO JUGADOR
                if(piezasJ.empty()){
                    cout << "El jugador ya no tiene piezas.\n";
                    continue;
                }

                mostrarPiezasJugador(piezasJ);

                int eleccion;
                while(true){
                    cout << "Elija el numero de pieza a colocar: ";
                    if(!(cin >> eleccion)){
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Entrada invalida. Intente de nuevo.\n";
                        continue;
                    }
                    if(eleccion < 1 || eleccion > (int)piezasJ.size()){
                        cout << "Numero fuera de rango. Intente de nuevo.\n";
                    } else break;
                }

                tablero[i][j] = piezasJ[eleccion-1];
                piezasJ.erase(piezasJ.begin() + (eleccion-1));

            } else {
                // TURNO PC
                if(idxC < piezasPC){
                    tablero[i][j] = Tuberias[rand()%11].getChar();
                    idxC++;
                    cout << "La computadora coloco una pieza.\n";
                }
            }
            turno++;
        }
    }

    cout << "\n=== JUEGO TERMINADO ===\n";
    mostrarTablero(tablero);

    int puntos = calcularPuntaje(tablero);
    cout << "Puntaje final: " << puntos << endl;

    return 0;
}
