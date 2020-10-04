import copy
N = int(input())
RGB = [0, 0, 0]
for _ in range(N):
    now = input().split()
    ans = [10000000, 10000000, 10000000]
    for i in range(3):
        for k in range(3):
            if i != k and int(RGB[i]) + int(now[k]) < int(ans[k]):
                ans[k] = int(RGB[i]) + int(now[k])
    RGB = copy.copy(ans)
print(min(RGB))
