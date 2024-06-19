n = int(input())
x, y = map(int, input().split())
print(4 - (x == 1) - (x == n) - (y == 1) - (y == n))
