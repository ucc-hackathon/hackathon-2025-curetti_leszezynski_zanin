#include <iostream>
#include <string>
using namespace std;


class libro {
private:
    int codigo;
    string titulo;
    string autor;
    int year;
    string tipo;
    bool check; 
    int contador; 

public:
    libro();
    libro(int _codigo, int _year, string _tipo, string _titulo, string _autor);

    int getCodigo();
    int getYear();
    string getTipo();
    string getAutor();
    string getTitulo();
    bool getCheck();
    int getContador();

    void setYear(int _year);
    void setCheck(bool _check);
    void setTipo(string _tipo);
    void setAutor(string _autor);
    void setCodigo(int _codigo);
    void setTitulo(string _titulo);
    void setContador(int _contador);

    void registrar();
    void listar();

    void pedir();
    void devolver();

    ~libro();
};


libro::libro() {
    codigo = 0;
    contador = 0;
    titulo = "";
    autor = "";
    year = 0;
    tipo = "";
    check = false;
}

libro::libro(int _codigo, int _year, string _tipo, string _titulo, string _autor) {
    codigo = _codigo;
    titulo = _titulo;
    autor = _autor;
    tipo = _tipo;
    year = _year;
    contador = 0;
    check = false;
}

int libro::getCodigo() { return codigo; }
int libro::getYear() { return year; }
string libro::getTipo() { return tipo; }
string libro::getAutor() { return autor; }
string libro::getTitulo() { return titulo; }
bool libro::getCheck() { return check; }
int libro::getContador() { return contador; }

void libro::setYear(int _year) { year = _year; }
void libro::setCodigo(int _codigo) { codigo = _codigo; }
void libro::setTipo(string _tipo) { tipo = _tipo; }
void libro::setCheck(bool _check) { check = _check; }
void libro::setTitulo(string _titulo) { titulo = _titulo; }
void libro::setAutor(string _autor) { autor = _autor; }
void libro::setContador(int _contador) { contador = _contador; }

void libro::pedir() {
    check = true;
    contador++;
}

void libro::devolver() {
    check = false;
}

void libro::listar() {
    cout << "\nTitulo: " << titulo
         << "\nAutor: " << autor
         << "\nAño: " << year
         << "\nTipo: " << tipo
         << "\nCodigo: " << codigo
         << "\nPrestado: " << (check ? "SI" : "NO")
         << "\nVeces prestado: " << contador << endl;
}

libro::~libro() {}


class Persona {
protected:
    int legajo;
    int cantPe; 

public:
    Persona(int _legajo, int _cantPe);
    Persona();

    void setLegajo(int _legajo);
    int getLegajo();
    void setCantPe(int _cantPe);
    int getCantPe();

    virtual void buscar() {}
    virtual void top() {}
    virtual void masMostrar() {}
    virtual void Prestar(libro &p);
    virtual void Devolver(libro &p);

    virtual ~Persona();
};

Persona::Persona() {
    legajo = 0;
    cantPe = 0;
}

Persona::Persona(int _legajo, int _cantPe) {
    legajo = _legajo;
    cantPe = _cantPe;
}

void Persona::setLegajo(int _legajo) { legajo = _legajo; }
int Persona::getLegajo() { return legajo; }

void Persona::setCantPe(int _cantPe) { cantPe = _cantPe; }
int Persona::getCantPe() { return cantPe; }

void Persona::Prestar(libro &p) {
    if (p.getCheck()) {
        cout << "El libro '" << p.getTitulo() << "' no esta disponible.\n";
    } else {
        p.pedir();
        cantPe++;
        cout << "El libro '" << p.getTitulo() << "' fue prestado.\n";
    }
}

void Persona::Devolver(libro &p) {
    if (!p.getCheck()) {
        cout << "El libro '" << p.getTitulo() << "' no este prestado.\n";
    } else {
        p.devolver();
        cout << "El libro '" << p.getTitulo() << "' fue devuelto.\n";
    }
}

Persona::~Persona() {}

class Profesor : public Persona {
private:
    string area;

public:
    Profesor(int _legajo, int _cantPe, string _area);
    Profesor();

    string getArea();
    void setArea(string _area);
    void buscar() {}
    void top() {}
    void masMostrar() {}
    void Prestar(libro &p);
    void Devolver(libro &p);
    ~Profesor();
};

Profesor::Profesor() : Persona() { area = ""; }

Profesor::Profesor(int _legajo, int _cantPe, string _area)
    : Persona(_legajo, _cantPe) {
    area = _area;
}

string Profesor::getArea() { return area; }
void Profesor::setArea(string _area) { area = _area; }

void Profesor::Prestar(libro &p) {
    cout << "[Profesor] ";
    Persona::Prestar(p);
}

void Profesor::Devolver(libro &p) {
    cout << "[Profesor] ";
    Persona::Devolver(p);
}

Profesor::~Profesor() {}

class Alumno : public Persona {
private:
    int grado;

public:
    Alumno();
    Alumno(int _legajo, int _cantPe, int _grado);

    int getGrado();
    void setGrado(int _grado);
    void Prestar(libro &p);
    void Devolver(libro &p);
    ~Alumno();
};

Alumno::Alumno() : Persona() { grado = 0; }

Alumno::Alumno(int _legajo, int _cantPe, int _grado)
    : Persona(_legajo, _cantPe) {
    grado = _grado;
}

int Alumno::getGrado() { return grado; }
void Alumno::setGrado(int _grado) { grado = _grado; }

void Alumno::Prestar(libro &p) {
    cout << "[Alumno] ";
    Persona::Prestar(p);
}

void Alumno::Devolver(libro &p) {
    cout << "[Alumno] ";
    Persona::Devolver(p);
}

Alumno::~Alumno() {}



int main() {
    libro *vector2[5];
    vector2[0] = new libro(1231232, 1680, "Matematica", "Calculo", "Isaac Newton");
    vector2[1] = new libro(1238123, 2005, "Lengua", "La Granja", "George Orwell");
    vector2[2] = new libro(12423223, 2009, "Economia", "Crisis 2001", "Anónimo");
    vector2[3] = new libro(1992323, 1998, "Fisica", "Fisica I", "Castillo Jorge");
    vector2[4] = new libro(19239924, 2010, "Programación", "La Casa", "Don Pepe");

    Persona *vector[3];
    vector[0] = new Alumno(101, 0, 2);
    vector[1] = new Profesor(102, 0, "Filosofia");
    vector[2] = new Alumno(103, 0, 3);

    vector[0]->Prestar(*vector2[0]);
    vector[0]->Devolver(*vector2[0]);
    vector[1]->Prestar(*vector2[1]);
    vector[2]->Prestar(*vector2[1]); 

    cout << "\nLISTA DE LIBROS" << endl;
    for (int i = 0; i < 5; i++) {
        vector2[i]->listar();
    }

 
        
    int n;
    string nombre;
    string titulo;
	do{
	
	cout<<"desea buscar libro por autor [1] o por titulo [2]"<<endl;
	cin>>n;
	}while((n!=1)&&(n!=2));
	
	if(n==1){
		cout<<"Digite el nombre del autor: ";
		cin>>nombre;
		
		
	} else {
		cout<<"Digite el titulo: ";
		cin>>titulo;
	}
	
	cout<<"Libro mas prestado: "; vector2[0]->getTitulo(); cout<<endl;
	cout<<"Segundo libro mas prestado: "; vector2[1]->getTitulo(); cout<<endl;
	cout<<"tercer libro mas prestado: "; vector2[2]->getTitulo(); cout<<endl;	

  
    
    int o = 9999999;
    int mayor;

    
    for(int i=0; i<3; i++){
    	if(o > vector[i]->getCantPe())
     	o = vector[i]->getCantPe();
    	mayor = vector[i]->getLegajo();
    }   
	cout<<"Legajo del usuario con mas cantidad de pedidos: "<<mayor<<" con una cantidad de "<<o<<endl;
	 
	int k = 99999999;
	string mayorB; 
	
	for(int i=0; i<4; i++){
    	if(o > vector2[i]->getContador())
     	k = vector2[i]->getContador();
    	mayorB = vector2[i]->getTitulo();
    }   
	cout<<"Libro con mas cantidad de pedidos: "<<mayorB<<" con una cantidad de "<<k; 
    
	 for (int i = 0; i < 3; i++)
        delete vector[i];
    for (int i = 0; i < 5; i++)
        delete vector2[i];
	
    return 0;
}

