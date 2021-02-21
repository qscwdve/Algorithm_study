def egcd(a, b):
    if a == 0:
        return (b, 0, 1)
    else:
        g, y, x = egcd(b % a, a)
        return (g, x - (b // a) * y, y)

def modinv(a, m):
    g, x, y = egcd(a, m)
    if g != 1:
        raise Exception('modular inverse does not exist')
    else:
        return x % m

n = int(input())
F, ans = [1, 1], 1

for i in range(2, n):
    F.append((F[i - 1]*i)%10007)

for k in range(1, n//2 + 1):
    one = n - 2*k   
    num = (F[one] * F[k])%10007
    ans += (F[one + k] * modinv(num, 10007)) % 10007
print(ans % 10007)
