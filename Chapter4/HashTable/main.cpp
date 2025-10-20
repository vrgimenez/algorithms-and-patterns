#include <iostream>
#include "hashTable.h"

int main() {
    HashTable ht(10);

    ht.insert(1, "Ana");
    ht.insert(2, "Luis");
    ht.insert(12, "Carlos");  // Colisión con 2
    ht.insert(22, "María");   // Colisión con 2 también
    ht.insert(3, "Sofía");

    std::cout << "Tabla hash inicial:\n";
    ht.display();

    std::cout << "\nBuscar clave 12: " << ht.search(12) << "\n";

    std::cout << "\nEliminar clave 2\n";
    ht.remove(2);

    std::cout << "\nTabla final:\n";
    ht.display();

    return 0;
}