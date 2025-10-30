#include <iostream>
#include <vector>
#include <algorithm>

// Algoritmo de cambio de monedas (mínimo número de monedas)
int coinChange(const std::vector<int>& coins, int amount)
{
    const int INF = amount + 1;
    std::vector<int> dp(amount + 1, INF);
    dp[0] = 0;

    for (int coin : coins) {
        for (int x = coin; x <= amount; ++x) {
            dp[x] = std::min(dp[x], dp[x - coin] + 1);
        }
    }

    return dp[amount] == INF ? -1 : dp[amount];
}

int main()
{
    std::vector<int> monedas = {1, 2, 5, 10};
    int monto = 39;

    int resultado = coinChange(monedas, monto);

    if (resultado == -1)
        std::cout << "No hay forma de dar el cambio para " << monto << "\n";
    else
        std::cout << "Mínimo número de monedas para " << monto << ": " << resultado << "\n";

    return 0;
}