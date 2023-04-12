for t in range(int(input())):
    a, b, c, n = map(int, input().split())
    x = b - a
    print(f"Case {t+1}:", x == c - b and a + n*x - x or "Error")
