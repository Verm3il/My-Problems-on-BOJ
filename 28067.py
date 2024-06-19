def onLine(p1, p2, p3):
    dx1 = p1[0] - p2[0]
    dy1 = p1[1] - p2[1]
    dx2 = p2[0] - p3[0]
    dy2 = p2[1] - p3[1]
    return dy1 * dx2 == dx1 * dy2


def d(p1, p2):
    dx = p1[0] - p2[0]
    dy = p1[1] - p2[1]
    return dx * dx + dy * dy


n, m = map(int, input().split())
pt = [(i, j) for i in range(n + 1) for j in range(m + 1)]
st = set()

for i in range(len(pt)):
    for j in range(i):
        for k in range(j):
            if onLine(pt[i], pt[j], pt[k]):
                continue
            vt = [d(pt[i], pt[j]), d(pt[j], pt[k]), d(pt[k], pt[i])]
            vt.sort()
            st.add(tuple(vt))

print(len(st))
