T = int(input())

for testCase in range(1, T + 1):
    N = int(input())
    A = list(map(int, input().split()))

    steps = 0
    maxValue = max(map(abs, A))

    steps += maxValue

    print(f"Case {testCase}: {steps}")
