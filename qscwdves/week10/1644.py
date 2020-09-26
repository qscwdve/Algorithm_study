import math

N = int(input())
if N == 1:
    print(0)
elif N == 2:
    print(1)
else:
    max = int(math.sqrt(N)) + 1
    lst = [0 for _ in range(N + 1)]
    prime = []
    index = 2
    while index <= max:
        a = 2
        while a*index <= N:
            lst[a*index] = 1
            a = a + 1
        prime.append(index)
        index = index + 1
        while lst[index] == 1:
            index = index + 1
    for i in range(max + 1, N+1):
        if lst[i] == 0:
            prime.append(i)
        if len(prime) > 1 and i + prime[-2] > N:
            break

    count = 1
    if lst[N] != 0:
        count = 0
    for i in range(len(prime) - 1):
        value = prime[i]
        for k in range(i+1, len(prime)):
            if value >= N:
                break
            value = value + prime[k]
        if value == N:
            count = count + 1
    print(count)
