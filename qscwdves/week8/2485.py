def Euclidean(a, b):
    r_1 = a
    r_2 = b
    r_3 = r_1 % r_2
    while r_3 != 0:
        r_1 = r_2
        r_2 = r_3
        r_3 = r_1 % r_2
    return r_2


N = int(input())
lst = [int(input()) for _ in range(N)]
distance = []
distance = [abs(lst[i] - lst[i+1]) for i in range(N-1)]
gcd = Euclidean(distance[0], distance[1])
for i in range(2, len(distance)):
    if distance[i] % gcd != 0:
        gcd = Euclidean(distance[i], gcd)
    if gcd == 1:
        break
ans = 0
for i in range(len(distance)):
    ans = ans + distance[i]//gcd - 1
print(ans)
