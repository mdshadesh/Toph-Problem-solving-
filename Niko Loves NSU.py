# skip the first input line
input()

# map the count method to each character in "NSU" and get the minimum count
result = min(map(input().count, "NSU"))

# print the result
print(result)
