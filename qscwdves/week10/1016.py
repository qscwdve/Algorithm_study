import math


def prime(N):
    max = int(math.sqrt(N)) + 1
    lst = [0 for _ in range(N + 1)]
    prime = []
    index = 2
    while index <= max:
        a = 2
        while a * index <= N:
            lst[a * index] = 1
            a = a + 1
        prime.append(index)
        index = index + 1
        if index > max:
            break
        while lst[index] == 1:
            index = index + 1
    for i in range(max + 1, N + 1):
        if lst[i] == 0:
            prime.append(i)
    return prime


def find(num):
    global lst, min, max, count
    if num >= min:
        div = 1
    elif min % num == 0:
        div = min//num
    else:
        div = min//num + 1
    value = div*num
    while value <= max:
        if lst[value-min] == 0:
            lst[value-min] = 1
            count = count + 1
        value = value + num
    pass


n = (input()).split()
min = int(n[0])
max = int(n[1])
max_num = int(math.sqrt(max))
min_num = int(math.sqrt(min))

lst = [0 for _ in range(max - min + 1)]
sqrt_lst = prime(max_num)
count = 0
for i in sqrt_lst:
    find(i*i)
print(max - min + 1 - count)
