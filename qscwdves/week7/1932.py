import copy
N = int(input())
before = []
for i in range(N):
    t = input().split()
    ans = copy.copy(t)
    for k in range(len(before)):
        ans_0 = int(before[k]) + int(t[k])
        ans_1 = int(before[k]) + int(t[k + 1])
        if int(ans[k]) < ans_0:
            ans[k] = ans_0
        if int(ans[k + 1]) < ans_1:
            ans[k + 1] = ans_1
    before = copy.copy(ans)
max = before[0]
for i in range(1, len(before)):
    if max < before[i]:
        max = before[i]
print(max)
