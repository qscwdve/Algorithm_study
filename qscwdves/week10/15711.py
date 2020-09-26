import random


def Fantastic_Mate(n):
    if n == 2 or n == 3:
        return "NO"
    if n % 2 == 0:
        return "YES";
    if isprime(n-2):
        return "YES"
    return "NO"


def isprime(n):
    if n < 2 or not n & 1:
        return False
    if n == 2:
        return True
    def mrtest(b):
        x = pow(b, t, n)
        if x == 1:
            return True
        for i in range(s):
            if x == n - 1:
                return True
            x = pow(x, 2, n)
        return False
    s = 0
    t = n - 1
    while not t & 1:
        s += 1
        t >>= 1
    for i in range(10):
        b = random.randrange(2, n)
        if not mrtest(b):
            return False
    return True


T = int(input())
for i in range(T):
    N = input().split()
    print(Fantastic_Mate(int(N[0]) + int(N[1])))
