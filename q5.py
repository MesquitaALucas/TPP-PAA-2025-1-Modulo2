import sys

def main():
    caso = 0
    for line in sys.stdin:
      caso += 1
      inventario = []
      #NUMERO DE ITEMS E CAPACIDADE
      N, C = map(int, line.split())
      if N == 0 and C == 0:
        break
      for i in range(N):
        #PESO E INTERESSE
        W, V = input().split()
        W = int(W)
        V = int(V)
        inventario.append((W, V))

      Mochila = [[0] * (C + 1) for _ in range(N + 1)]

      
      for i in range(1, N + 1):
          for j in range(1, C + 1):
              if inventario[i-1][0] <= j:  
                  Mochila[i][j] = max(inventario[i-1][1] + Mochila[i-1][j - inventario[i-1][0]], Mochila[i-1][j])
              else:
                  Mochila[i][j] = Mochila[i-1][j]

      print(f"Caso {caso}: {Mochila[N][C]}")
      


if __name__ == "__main__":
    main()

        
