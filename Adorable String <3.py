def isvowel(ch):
    return ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u'

t = int(input())
for _ in range(t):
    n = int(input())
    s = input().strip()

    ans = 0
    cnt = {0: 1}
    V = 0
    for i in range(1, n + 1):
        V += isvowel(s[i - 1])
        A, B = 2 * V - i, 2 * V - i + 1
        ans += cnt.get(B, 0)
        cnt[A] = cnt.get(A, 0) + 1

    print(ans)
