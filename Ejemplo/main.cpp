#include <iostream>
#include <string>

using namespace std;

class Persona {

public:
    Persona(const string& n) { nombre = n; }
    virtual void Mostrar() const = 0;

protected:
    string nombre;

};

class Empleado: virtual public Persona {

public:
    Empleado(const string& n, float s): Persona(n), salario(s) {}
    void Mostrar () const {
        cout << "Empleado: "
             << nombre
             << ", Salario: "
             << salario << endl;
    }
    float LeerSalario() const { return salario; }
    void ModificarSalario(float s) { salario = s; }

protected:
    float salario;

};

class Estudiante: virtual public Persona {

public:
    Estudiante(const string& n, float nota): Persona(n), nota(nota) {}
    void Mostrar () const {
        cout << "Estudiante: " << nombre
             << ", Nota: " << nota
             << endl;
    }
    float LeerNota() const { return nota; }
    void ModificarNota(float no) { nota = no; }

protected:
    float nota;

};

/*class Becario: public Empleado, public Estudiante {

public:
    Becario(const string& n, float s, float no): Persona(n), Empleado(n,s), Estudiante(n,no) {}

};*/

int main(){
    Persona *Pepito = new Empleado("Jose", 1000);
    Persona *Pablito = new Estudiante("Pablo", 7.56);

    Pepito->Mostrar();
    Pablito->Mostrar();

    delete Pepito;
    delete Pablito;

    return 0;
}
