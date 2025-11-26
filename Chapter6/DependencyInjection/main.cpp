#include <iostream>
#include <memory>
using namespace std;

// Interfaz (abstracción)
class IMessageService {
public:
    virtual void send(const std::string& msg) = 0;
    virtual ~IMessageService() = default;
};

// Implementación concreta 1: Email
class EmailService : public IMessageService {
public:
    void send(const std::string& msg) override {
        std::cout << "[EMAIL REAL] " << msg << std::endl;
    }
};

// Mock de testing
class MockService : public IMessageService {
public:
    bool called = false;
    std::string lastMessage;

    void send(const std::string& msg) override {
        called = true;
        lastMessage = msg;
        // No imprime nada → no manda emails reales
    }
};

// Clase que recibe la dependencia "inyectada"
class Notificador {
private:
    IMessageService* service;

public:
    Notificador(IMessageService* s) : service(s) {}

    void alerta(const std::string& msg) {
        service->send(msg);
    }
};

int main() {
    // ---- MODO REAL ----
    EmailService email;
    Notificador n1(&email);
    n1.alerta("Servidor caído");

    // ---- MODO TEST ----
    MockService mock;
    Notificador n2(&mock);

    n2.alerta("Test MSG");

    // Verificación manual del mock
    if (mock.called)
        std::cout << "Mock OK: se llamó send(\"" << mock.lastMessage << "\")\n";
        
    else
        std::cout << "Mock ERROR: nunca fue llamado\n";

    return 0;
}