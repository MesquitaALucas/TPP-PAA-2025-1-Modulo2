#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    while (true) {
        long M, N;
        cin >> M >> N;
        if (M == 0 && N == 0) break;

        long L, K;
        cin >> L >> K;

        vector<long> tabuas(K);
        for (long i = 0; i < K; ++i) {
            cin >> tabuas[i];
            tabuas[i] *= 100; // converter para cm
        }

        M *= 100;
        N *= 100;

        sort(tabuas.begin(), tabuas.end());

        long melhor = -1;

        for (int orient = 0; orient < 2; ++orient) {
            long largura = (orient == 0 ? N : M);
            long comprimento = (orient == 0 ? M : N);

            if (largura % L != 0) continue;

            long faixas = largura / L;
            long i = 0, j = K - 1;
            long usadas = 0;
            long restantes = faixas;

            vector<bool> usada(K, false);

            for (long x = 0; x < K && restantes > 0; ++x) {
                if (tabuas[x] == comprimento && !usada[x]) {
                    usada[x] = true;
                    usadas++;
                    restantes--;
                }
            }

            i = 0, j = K - 1;
            while (i < j && restantes > 0) {
                if (usada[i]) { i++; continue; }
                if (usada[j]) { j--; continue; }

                long soma = tabuas[i] + tabuas[j];
                if (soma == comprimento) {
                    usada[i] = usada[j] = true;
                    usadas += 2;
                    restantes--;
                    i++;
                    j--;
                } else if (soma < comprimento) {
                    i++;
                } else {
                    j--;
                }
            }

            if (restantes == 0) {
                if (melhor == -1 || usadas < melhor) melhor = usadas;
            }
        }

        if (melhor == -1) cout << "impossivel" << endl;
        else cout << melhor << endl;
    }

    return 0;
}
