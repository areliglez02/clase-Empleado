#include <iostream>
#include <string>
//declaracion de la clase
class Empleado {
private:
    int ClaveEmpleado;
    std::string nombre;
    std::string domicilio;
    float sueldo;
    std::string reportas;

public:
    // Constructores
    // Constructor por default
    Empleado() {
        ClaveEmpleado = 0;
        nombre = "";
        domicilio = "";
        sueldo = 0;
        reportas = "";
    }

    // Constructor con parámetros
    Empleado(int C, std::string n, std::string d, float s, std::string r) {
        ClaveEmpleado = C;
        nombre = n;
        domicilio = d;
        sueldo = s;
        reportas = r;
    }

    // Métodos
    void Imprime() {
        std::cout << "Clave: " << ClaveEmpleado << "\nNombre: " << nombre << "\nDomicilio: " << domicilio << "\nSueldo: " << sueldo << "\nReporta a: " << reportas << std::endl;
    }

    void CambiarDomic(std::string d) {
        domicilio = d;
    }

    void ReportaA(std::string r) {
        reportas = r;
    }

    void ActualSueldo(float s) {
        sueldo = s;
    }
};

int main() {
    // Declaración de objetos
    Empleado JefePlanta(1, "Alberto Plaza", "Morelos #50", 5000.0, "Jefe de planta");
    Empleado JefePersonal(2, "Fernando Gracia", "16 de septiembre #67B", 6000.0, "Jefe personal");

    char repite = 1;
    int opc;
    do {
        std::cout << "\n\t\tMENU PRINCIPAL" << std::endl;
        std::cout << "\n\n1. Cambio de domicilio\n2. Actualizacion de sueldo\n3. Imprimir datos de empleado\n4. Cambiar persona que reporta\n5. Salir" << std::endl;
        std::cout << "Opcion: ";
        std::cin >> opc;
        switch (opc) {
            case 1: {
                std::string nuevoDomicilio;
                std::cout << "Nuevo domicilio: ";
                std::cin.ignore();
                std::getline(std::cin, nuevoDomicilio);
                JefePlanta.CambiarDomic(nuevoDomicilio);
                JefePersonal.CambiarDomic(nuevoDomicilio);
                break;
            }
            case 2: {
                float nuevoSueldo;
                std::cout << "Nuevo sueldo: ";
                std::cin >> nuevoSueldo;
                JefePlanta.ActualSueldo(nuevoSueldo);
                JefePersonal.ActualSueldo(nuevoSueldo);
                break;
            }
            case 3:
                JefePlanta.Imprime();
                JefePersonal.Imprime();
                break;
            case 4: {
                std::string nuevaPersona;
                std::cout << "Nueva persona que reporta: ";
                std::cin.ignore();
                std::getline(std::cin, nuevaPersona);
                JefePlanta.ReportaA(nuevaPersona);
                JefePersonal.ReportaA(nuevaPersona);
                break;
            }
            case 5:
                repite = 0;
                break;
            default:
                std::cout << "Opcion no valida." << std::endl;
                break;
        }
    } while (repite);

    return 0;
}