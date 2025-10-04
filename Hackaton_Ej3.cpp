#include <iostream>
using namespace std;
class Equipo{
    private:
        string nombre;
    public:
    Equipo (string n){
        nombre = n;
    }
    string getNombre () const {return nombre;}
};

class Partido {
    private:
        Equipo equipo1;
        Equipo equipo2;
        int golesEquipo1;
        int golesEquipo2;
    public:
    Partido (Equipo eq1, Equipo eq2, int g1, int g2): equipo1(eq1), equipo2(eq2), golesEquipo1(g1), golesEquipo2 (g2){}
    Equipo getEquipo1 () const {return equipo1;}
    Equipo getEquipo2 () const {return equipo2;}
    int getGolesEquipo1 () const {return golesEquipo1;}
    int getGolesEquipo2 () const {return golesEquipo2;}
    int totalGoles() const { return golesEquipo1 + golesEquipo2; }
};

 int main (){
    Equipo equipos[6] = {
        Equipo("Universidad Catolica de Cordoba"),
        Equipo("Universidad Nacional de Cordoba"),
        Equipo("Universidad Tecnologica Nacional"),
        Equipo("Universidad Nacional de Rio Cuarto"),
        Equipo("Universidad Blas Pascal"),
        Equipo("Universidad Empresarial Siglo XXI")
    };
    int puntos[6] = {0, 0, 0, 0, 0, 0};

    Partido Partidos[15]{
        Partido(equipos[3], equipos[4], 0, 0),
        Partido(equipos[0], equipos[3], 3, 0),
        Partido(equipos[2], equipos[4], 2, 2),
        Partido(equipos[1], equipos[5], 3, 1),
        Partido(equipos[4], equipos[5], 2, 1),
        Partido(equipos[0], equipos[2], 4, 1),
        Partido(equipos[1], equipos[3], 2, 2),
        Partido(equipos[0], equipos[4], 0, 2),
        Partido(equipos[1], equipos[2], 0, 1),
        Partido(equipos[2], equipos[3], 0, 1),
        Partido(equipos[0], equipos[1], 2, 1),
        Partido(equipos[0], equipos[5], 2, 2),
        Partido(equipos[1], equipos[4], 1, 3),
        Partido(equipos[2], equipos[5], 1, 0),
        Partido(equipos[3], equipos[5], 2, 3)
    };
    for (int i = 0; i < 15; i++) {
        string e1 = Partidos[i].getEquipo1().getNombre();
        string e2 = Partidos[i].getEquipo2().getNombre();
        int g1 = Partidos[i].getGolesEquipo1();
        int g2 = Partidos[i].getGolesEquipo2();

        int id1 = -1, id2 = -1;
        for (int j = 0; j < 6; j++) {
            if (equipos[j].getNombre() == e1) id1 = j;
            if (equipos[j].getNombre() == e2) id2 = j;
        }

        if (g1 > g2) {
            puntos[id1] += 3;
        } else if (g1 < g2) {
            puntos[id2] += 3;
        } else {
            puntos[id1] += 1;
            puntos[id2] += 1;
        }
    }

    for (int i = 0; i < 15 - 1; i++) {
        for (int j = 0; j < 15 - i - 1; j++) {
            if (Partidos[j].totalGoles() < Partidos[j + 1].totalGoles()) {
                Partido temp = Partidos[j];
                Partidos[j] = Partidos[j + 1];
                Partidos[j + 1] = temp;
            }
        }
    }

    cout << "\n--- Partidos ordenados por cantidad de goles ---" << endl;
    for (int i = 0; i < 15; i++) {
        cout << Partidos[i].getEquipo1().getNombre() << " " 
             << Partidos[i].getGolesEquipo1() << " - " 
             << Partidos[i].getGolesEquipo2() << " " 
             << Partidos[i].getEquipo2().getNombre() 
             << "  (Total: " << Partidos[i].totalGoles() << " goles)" << endl;
    }

    for (int i = 0; i < 6 - 1; i++) {
        for (int j = 0; j < 6 - i - 1; j++) {
            if (puntos[j] < puntos[j + 1]) {
                int aux = puntos[j];
                puntos[j] = puntos[j + 1];
                puntos[j + 1] = aux;
                Equipo temp = equipos[j];
                equipos[j] = equipos[j + 1];
                equipos[j + 1] = temp;
            }
        }
    }

    cout << "\n--- Podio ---" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << ". " << equipos[i].getNombre() 
             << " (" << puntos[i] << " pts)" << endl;
    }

    return 0;
}
