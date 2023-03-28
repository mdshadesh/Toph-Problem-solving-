n = int(input())
r, c = None, None
a = []
for i in range(n):
    row = list(input().strip())
    a.append(row)
    if '@' in row:
        r, c = i, row.index('@')
p = 15
found = False
w = None
while p != 0:
    if a[r][c] == '#':
        found = True
        break
    if a[r][c] == '$':
        p += 15
    if c != n - 1 and a[r][c + 1] != '.' and a[r][c + 1] != '@' and w != 'r':
        c += 1
        p -= 1
        w = 'l'
    elif c != 0 and a[r][c - 1] != '.' and a[r][c - 1] != '@' and w != 'l':
        c -= 1
        p -= 1
        w = 'r'
    elif r != 0 and a[r - 1][c] != '.' and a[r - 1][c] != '@' and w != 'u':
        r -= 1
        p -= 1
        w = 'd'
    elif r != n - 1 and a[r + 1][c] != '.' and a[r + 1][c] != '@' and w != 'd':
        r += 1
        p -= 1
        w = 'w'
    else:
        break
if found:
    print("Yes")
else:
    print("No")
