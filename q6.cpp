#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool guloso(long chute, const vector<long>& sacos, long C, long T) {
    long capacidade = T * chute;
    long atual = 0;

    for (long volume : sacos) {
        if (volume > capacidade) return false;

        if (atual + volume <= capacidade) {
            atual += volume;
        } else {
            C--;
            if (C == 0) return false;
            atual = volume;
        }
    }

    return true;
}

int main() {
    long N, C, T;
    
    cin >> N >> C >> T; //Sacos de pipocas, N de Competidores, Velocidade

    vector<long> sacos;
    long soma = 0;
    long maior = 0;

    for (int i = 0; i < N; i++) {
        long val;
        cin >> val;
        sacos.push_back(val);
        soma += val;
        maior = max(maior, val);
    }

    long ini = (maior + T - 1) / T; // menor tempo possível
    long fim = soma; // maior tempo possível
    long resp = fim;

    // Busca binária 
    while (ini <= fim) {
        long meio = (ini + fim) / 2;

        if (guloso(meio, sacos, C, T)) {
            resp = meio;
            fim = meio - 1;
        } else {
            ini = meio + 1;
        }
    }

    // Imprime o resultado final
    cout << resp << "\n";

    return 0;
}
