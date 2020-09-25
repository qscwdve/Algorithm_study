N = int(input())

lst = [N for i in range(N + 1)]
lst[0] = 0
lst[1] = 0
for i in range(2, N + 1):
    lst[i] = lst[i-1] + 1
    if i % 2 == 0 and lst[i//2] + 1 < lst[i]:
        lst[i] = lst[i//2] + 1
    if i % 3 == 0 and lst[i//3] + 1 < lst[i]:
        lst[i] = lst[i//3] + 1
print(lst[N])
