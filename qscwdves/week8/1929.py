import math

NM = input()
N_M = NM.split()
N_M[0] = int(N_M[0])
N_M[1] = int(N_M[1])
max = int(math.sqrt(N_M[1])) + 1
lst = [0 for _ in range(N_M[1] + 1)]
lst[0] = 1
lst[1] = 1
index = 2
while index <= max:
    a = 2
    while a*index <= N_M[1]:
        lst[a*index] = 1
        a = a + 1
    index = index + 1
    if index > max:
        break
    while lst[index] == 1:
        index = index + 1
for i in range(N_M[0], N_M[1]+1):
    if lst[i] == 0:
        print(i)
