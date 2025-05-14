#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[]){
    int j = 1;
    while(true){
        int M = stoi(argv[j]); //Comprimento  
        j++;
        int N = stoi(argv[j]); //Largura
        j++;
        if (N == 0 && M == 0) break; 
        int L = stoi(argv[j]); //Largura das Tabuas
        j++;
        int K = stoi(argv[j]); //Numero de Tabuas
        j++;

        int tabuas[K];
        int Mochila[K][K];
        int goal = 0;
        int NumTabuas = 0;

        for(int i=0; i<K; i++){
            tabuas[i] == stoi(argv[i+j+1]);
            j++;
        }

        //MONTAR A MATRIZ

        if(N%K != 0){
            cout << "impossivel\n";
        }
        else{
            goal = M * (N/K);
        }

        //PROCURAR O GOAL E ENCONTRAR O NÚMERO DE TABUAS 

    }


    return 0;
}
