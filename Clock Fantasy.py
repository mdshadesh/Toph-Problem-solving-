import sys

for line in sys.stdin.readlines()[1:]:
    a, b = map(float, line.split())
    print("{:.10f}".format(a * b / 2))
