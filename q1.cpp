#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>

using namespace std;


int main() {
    while (true) {
        long M, N, L, K,aux;
        long goal = 0;
        long resposta = 0;
        long usar = 0;

        cin >> M >> N;
 
        if (M == 0 && N == 0) break;

        M = M*100;
        N = N*100;

        cin >> L >> K;

        vector<long> tabuas;

        for (long i = 0; i < K; ++i) {
            cin >> aux;
            tabuas.push_back(aux);
        }


        if(N%L == 0){
            goal = M*(N/L);
        }
        else if (M%L == 0){
            goal = M*(N/L);
        }

        while(true){
            usar = tabuas[(tabuas.size()-1)];
            tabuas.pop_back();
            goal = goal - usar;
            resposta++;
            if (tabuas.empty() == 1 || goal < 0) {
                printf("impossivel\n");
                break;
            }
            if (goal == 0){
                printf("%ld\n", resposta);
            }
            
            
        }


    }


    return 0;
}
