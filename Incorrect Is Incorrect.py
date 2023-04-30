# split the input and handle invalid input
try:
    x, c = input().split("=")
    a, b = map(int, x.split("+"))
    p = a + b + int(c)
except ValueError:
    print("Invalid input")
else:
    # check if solution is possible and print output
    solution = f"{p//2}+0={p//2}" if p % 2 == 0 else "Impossible"
    print(solution)
