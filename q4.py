import sys

MOD = 10**6

def matriz_mult(a, b):
    return [
        [(a[0][0]*b[0][0] + a[0][1]*b[1][0]) % MOD,
         (a[0][0]*b[0][1] + a[0][1]*b[1][1]) % MOD],
        [(a[1][0]*b[0][0] + a[1][1]*b[1][0]) % MOD,
         (a[1][0]*b[0][1] + a[1][1]*b[1][1]) % MOD]
    ]

def matriz_potencia(T, exp):
    id = [[1, 0],
           [0, 1]]  
    while exp > 0:
        if exp & 1:
            id = matriz_mult(id, T)
        T = matriz_mult(T, T)
        exp >>= 1
    return id

def solve_case(N, K, L):
    M = N // 5

    # casos base
    if M == 0:
        return 1         # nenhum veículo
    if M == 1:
        return K % MOD   # um micro–ônibus

    threshold = 10**6

    #programação dinamica com exponenciação de matrizriz
    if M <= threshold:
        dp_prev = 1         # dp[0]
        dp_cur  = K % MOD   # dp[1]
        for _ in range(2, M+1):
            dp_next = (K * dp_cur + L * dp_prev) % MOD
            dp_prev, dp_cur = dp_cur, dp_next
        return dp_cur


    K_mod = K % MOD
    L_mod = L % MOD
    T = [[K_mod, L_mod],
         [1,     0    ]]


    Tn = matriz_potencia(T, M-1)


    return (Tn[0][0] * K_mod + Tn[0][1] * 1) % MOD

def main():
    for line in sys.stdin:
        N, K, L = map(int, line.split())
        ans = solve_case(N, K, L)
        print(f"{ans:06d}")

if __name__ == "__main__":
    main()
