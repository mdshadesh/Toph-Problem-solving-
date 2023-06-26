n = int(input())
superpowers = list(map(int, input().split()))

triplet_count = 0
for power in superpowers:
    if power % 3 == 0:
        triplet_count += 1

print(triplet_count)
