#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <algorithm>

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

        long tabuas[K];

        for (long i = 0; i < K; ++i) {
            cin >> tabuas[i];
        }

        sort(tabuas, tabuas + K, greater<long>());

        if(N%L == 0){
            goal = (N/L);
            for (int i = 0; i < K; i++){
                if (tabuas[i] == M){
                    resposta++;
                    goal --;
                }
                else{
                    for (int j = K-1; j > i; j--){
                        if (tabuas[i] + tabuas[j] == M){
                            resposta += 2;
                            goal --;
                            break;
                        }
                        else if (j == i){
                            printf("impossivel\n");
                        }
                    }
                }
            }
        }
        else if (M%L == 0){
            goal = (M/L);
            for (int i = 0; i < K; i++){
                if (tabuas[i] == N){
                    resposta++;
                    goal --;
                }
                else{
                    for (int j = K-1; j > i; j--){
                        if (tabuas[i] + tabuas[j] == N){
                            resposta += 2;
                            goal --;
                            break;
                        }
                        else if (j == i){
                            printf("impossivel\n");
                        }
                    }
                }
            }
        }
        else{
            printf("impossivel\n");
            break;
        }


    }


    return 0;
}
