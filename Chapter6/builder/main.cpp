/* In order to avoid this
    Persona p("Juan", "Perez", 30, "Av Siempre Viva", "501", "Argentina", true, false);
    Lets build something that makes this
    Persona p = Persona::Builder()
        .nombre("Juan")
        .apellido("Perez")
        .edad(30)
        .direccion("Av Siempre Viva 501")
        .nacionalidad("Argentina")
        .casado(true)
        .build();
*/

#include <string>

class Persona {
private:
    std::string nombre;
    std::string apellido;
    int edad;
    std::string direccion;
    std::string nacionalidad;
    bool casado;

    // Constructor privado: solo el Builder puede usarlo
    Persona(const std::string& n, const std::string& a, int e,
            const std::string& dir, const std::string& nac, bool c)
        : nombre(n), apellido(a), edad(e),
          direccion(dir), nacionalidad(nac), casado(c) {}

public:
    class Builder {
    private:
        std::string nombre = "";
        std::string apellido = "";
        int         edad = 0;
        std::string direccion = "";
        std::string nacionalidad = "";
        bool        casado = false;

    public:
        Builder& nombre_(const std::string& n) { nombre = n; return *this; }
        Builder& apellido_(const std::string& a) { apellido = a; return *this; }
        Builder& edad_(int e) { edad = e; return *this; }
        Builder& direccion_(const std::string& d) { direccion = d; return *this; }
        Builder& nacionalidad_(const std::string& n) { nacionalidad = n; return *this; }
        Builder& casado_(bool c) { casado = c; return *this; }

        Persona build() {
            return Persona(nombre, apellido, edad, direccion, nacionalidad, casado);
        }
    };

    // For example purposes
    std::string info() const {
        return nombre + " " + apellido + " (" + std::to_string(edad) + ") - " + nacionalidad;
    }
};

#include <iostream>

int main() {
    Persona p = Persona::Builder()
                    .nombre_("Juan")
                    .apellido_("Perez")
                    .edad_(30)
                    .direccion_("Av Siempre Viva 501")
                    .nacionalidad_("Argentina")
                    .casado_(true)
                    .build();

    std::cout << p.info() << std::endl;
    return 0;
}