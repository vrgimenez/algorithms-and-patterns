#include <iostream>
#include <vector>
#include <iomanip>

// Estructura que representa un objeto con peso y valor
struct Item {
    int weight;
    int value;
};

// Función recursiva con memorización
int knapsackRec(int i, int W, const std::vector<Item>& items, std::vector<std::vector<int>>& memo) {
    // Caso base: sin objetos o capacidad 0
    if (i == 0 || W == 0)
        return 0;

    // Si ya está calculado, reutilizar
    if (memo[i][W] != -1)
        return memo[i][W];

    // Si el objeto actual es muy pesado, no se puede incluir
    if (items[i - 1].weight > W)
        return memo[i][W] = knapsackRec(i - 1, W, items, memo);

    // Caso general: elegir el máximo entre incluirlo o no
    int incluir = items[i - 1].value + knapsackRec(i - 1, W - items[i - 1].weight, items, memo);
    int excluir = knapsackRec(i - 1, W, items, memo);

    return memo[i][W] = std::max(incluir, excluir);
}

int knapsack(int W, const std::vector<Item>& items) {
    int n = items.size();

    // Crear tabla de memorización inicializada en -1
    std::vector<std::vector<int>> memo(n + 1, std::vector<int>(W + 1, -1));

    // Llamada recursiva inicial
    int result = knapsackRec(n, W, items, memo);

    // Mostrar tabla resultante (opcional)
    std::cout << "\nTabla de memorización final:\n";
    for (int i = 0; i <= n; ++i) {
        for (int w = 0; w <= W; ++w)
            std::cout << std::setw(4) << (memo[i][w] == -1 ? 0 : memo[i][w]);
        std::cout << "\n";
    }

    return result;
}

int knapsackIter(int W, const std::vector<Item>& items) {
    int n = items.size();

    // Tabla DP de tamaño (n+1) x (W+1)
    std::vector<std::vector<int>> K(n + 1, std::vector<int>(W + 1, 0));

    // Construcción de la tabla de abajo hacia arriba
    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (items[i - 1].weight <= w) {
                K[i][w] = std::max(
                    items[i - 1].value + K[i - 1][w - items[i - 1].weight],
                    K[i - 1][w]
                );
            } else {
                K[i][w] = K[i - 1][w];
            }
        }
    }

    // Mostrar tabla intermedia (opcional para visualización educativa)
    std::cout << "Tabla de valores parciales (DP):\n";
    for (int i = 0; i <= n; ++i) {
        for (int w = 0; w <= W; ++w)
            std::cout << std::setw(4) << K[i][w];
        std::cout << "\n";
    }

    // Retornar el valor máximo posible
    return K[n][W];
}

int main() {
    int W = 7;
    std::vector<Item> items = {
        {3, 4},
        {4, 5},
        {2, 3}
    };

    std::cout << "Capacidad de la mochila: " << W << "\n";
    std::cout << "Objetos disponibles:\n";
    for (size_t i = 0; i < items.size(); ++i)
        std::cout << "  Objeto " << i + 1 << " -> peso: " << items[i].weight
                  << ", valor: " << items[i].value << "\n";

    int maxValue = knapsack(W, items);
    std::cout << "\nValor máximo posible Recursivo: " << maxValue << "\n";

    maxValue = knapsackIter(W, items);
    std::cout << "\nValor máximo posible Iterativo: " << maxValue << "\n";


    return 0;
}