# Solution in Python 3

n = int(input()) # Taking input for number of test cases
for i in range(1, n+1):
    a, b, c = map(int, input().split()) # Taking input of the three numbers
    if a > b and a > c:
        print("Case %d: A" % i) # Printing the output in the given format
    elif b > a and b > c:
        print("Case %d: B" % i)
    elif c > a and c > b:
        print("Case %d: C" % i)
    else:
        print("Case %d: Confused" % i)
