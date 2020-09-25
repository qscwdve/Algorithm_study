one = [0 for _ in range(41)]
zero = [0 for _ in range(41)]
zero[0] = 1
one[1] = 1

T = int(input())
now = 1
for i in range(T):
    N = int(input())
    if N > now:
        for k in range(now + 1, N + 1):
            one[k] = one[k-1] + one[k-2]
            zero[k] = zero[k-1] + zero[k-2]
    print(zero[N], one[N])
