#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

/*bool guloso(long chute, const vector<long>& sacos_original, long C, long T) {
    vector<long> sacos = sacos_original; 
    long capacidade = T * chute;

    long atual = 0;
    while (!sacos.empty()) {
        long volume = sacos.back();
        sacos.pop_back();

        if (volume > capacidade) return false;

        if (atual + volume <= capacidade) {
            atual += volume;
        } 
        
        else {
            C--;
            if (C == 0) return false;
            atual = volume;
        }
    }

    return true;
}*/

bool guloso(long chute, const vector<long>& sacos, long C, long T) {
    long capacidade = T * chute;
    long atual = 0;

    for (int i = 0; i < sacos.size(); ++i) {
        long volume = sacos[i];
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

int main(int argc, char *argv[]){
    long N = stoi(argv[1]);  //Sacos de Pipoca
    long C = stoi(argv[2]); // N de Competidores Disponível
    long T = stoi(argv[3]); // Velocidade


    long soma = 0;

    vector<long> sacos;

    for (int i = 4; i < 3 + N; i++) {
        long val = stol(argv[i]);
        sacos.push_back(val);
        soma += val;
    }

    //Busca Binária

    long ini = 1;
    long fim = soma;
    long resp = fim;

    while (ini <= fim) {
        long meio = (ini + fim) / 2;

        if (guloso(meio, sacos, C, T)) {
            resp = meio;
            fim = meio - 1;
        } else {
            ini = meio + 1;
        }
    }

    cout << resp << "\n";

    return 0;
}
