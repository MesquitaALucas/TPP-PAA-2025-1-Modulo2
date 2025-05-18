
def solve(remain, index, tabuas, memory):
    if remain == 0:
        return 0
    
    elif remain > 0 and index == len(tabuas):
        return -1
    
    elif remain < 0:
        return -1
    
    elif memory[index][remain] is None:
        usar = 1 + solve(remain - tabuas[index], index, tabuas, memory)

        nao_usar = solve(remain, index + 1, tabuas, memory)

        memory[index][remain] = min(usar,nao_usar)

    return memory[index][remain]

def main():

    while True:
        M = input()
        N = input()

        if M + N == 0:
            break

        L = input()
        K = input()


        tabuas = []


        for i in  K:
            aux = input()
            tabuas.append(aux)

        if M%L == 0:
            goal = (M/L) * N
            memory = [[None for _ in range (goal + 1) for _ in range(K)]]
            r = solve(goal, 0, tabuas, memory)
            if r == -1:
                print("impossivel\n")
            else:
                print (r + "\n")    


        elif N%L == 0:
            goal = (N/L) * M
            memory = [[None for _ in range (goal + 1) for _ in range(K)]]
            r = solve(goal, 0, tabuas, memory)
            print (r + "\n")

        else:
            print("impossivel\n")

if __name__ == "__main__":
    main()
