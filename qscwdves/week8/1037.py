n = int(input())
strr = input()
lst = strr.split()
min = int(lst[0])
max = int(lst[0])
for i in range(n):
    lst[i] = int(lst[i])
    if max < lst[i]:
        max = lst[i]
    if min > lst[i]:
        min = lst[i]
print(max*min)
