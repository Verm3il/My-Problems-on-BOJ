n = int(input())
ans = [0 for _ in range(n)]
num = n
for i in range(1, n, 2):
    ans[i] = num
    num -= 1
num = 1
for i in range(0, n, 2):
    ans[i] = num
    num += 1
print(*ans)
