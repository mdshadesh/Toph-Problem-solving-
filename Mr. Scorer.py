b = r = w = 0

for i in [*open(0)][1:]:
    s, t = i.split()
    r += int(s)

    if t == "WD" or t == "N":
        r += 1

    if t == "W":
        w += 1
        b += 1

    if t == "L":
        b += 1

    print(f"{r}|{w}|{b//6}.{b%6}")
