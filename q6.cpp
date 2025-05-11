#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Bucket {
    int vol;
    bool taken;
  };

bool allBucketsEmpty(Bucket sacos[], int N){
    for (int i = 0; i < N; ++i) {
        if (sacos[i].vol > 0) {
            return false;
        };
    }
    return true; 
};

int main(int argc, char *argv[]){
    int N = stoi(argv[1]);  //Sacos de Pipoca
    int C = stoi(argv[1]); // N de Competidores Disponível
    int T = stoi(argv[1]); // Velocidade

    Bucket sacos[N]; //Registrar o Volume de Cada Saco

    int time = 0; //Tempo total
    int Taken[C];
    int aux = 0;

    for (int i = 0; i ++; i < N){
        sacos[i].vol = stoi(argv[i+4]);
        sacos[i].taken = false;
    }

    while (!allBucketsEmpty(sacos, N)){
        for (int i = 0; i ++; i < N){
            if(sacos[i].taken == false && sacos[i].vol > 0){
                Taken[C] == i;
                C--;
                sacos[i].taken = true;
            }
            if (C == 0){
                i  == N;
            }
        }



    }

    return time;
}
