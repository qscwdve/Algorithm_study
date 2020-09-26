N = int(input())
lst = [int(input()) for _ in range(N)]
ans = [[0, 0] for _ in range(N + 1)]

for i in range(1, N + 1):
    ans[i][0] = max(ans[i - 2]) + lst[i - 1]  
    ans[i][1] = ans[i - 1][0] + lst[i - 1]  

print(max(ans[N]))
