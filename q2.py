import sys
import math

def distancia(p1, p2):
    return math.hypot(p1[0] - p2[0], p1[1] - p2[1])

def PMP(pontos):
    if len(pontos) <= 1:
        return float("inf")
    if len(pontos) == 2:
        return distancia(pontos[0], pontos[1])

    pontos.sort(key=lambda x: x[0])
    N = len(pontos)
    mediana = N // 2
    esquerda = pontos[:mediana]
    direita = pontos[mediana:]

    d1 = PMP(esquerda)
    d2 = PMP(direita)
    d = min(d1, d2)

    meio_x = pontos[mediana][0]
    faixa = [p for p in pontos if abs(p[0] - meio_x) < d]
    faixa.sort(key=lambda p: p[1])

    for i in range(len(faixa)):
        for j in range(i + 1, min(i + 7, len(faixa))):
            d_ij = distancia(faixa[i], faixa[j])
            if d_ij < d:
                d = d_ij

    return d

def main():
    linhas = sys.stdin.readlines()
    i = 0

    while i < len(linhas):
        N = int(linhas[i])
        i += 1
        if N == 0:
            break

        pontos = []
        for _ in range(N):
            x_str, y_str = linhas[i].strip().split()
            pontos.append((float(x_str), float(y_str)))
            i += 1

        resposta = PMP(pontos)
        if resposta < 10000.0:
            print(f"{resposta:.4f}")
        else:
            print("INFINITY")

if __name__ == "__main__":
    main()
