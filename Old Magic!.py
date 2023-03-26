# Take input as a function
i = input

# Create an empty list l to store inputs
l = []

# Take input of number of test cases
n = int(i())

# Loop through the range 1 to n to get inputs
for j in [1]*n:

    # Append the input values as a list to l
    l += [i().split()]

# Take input of the initial value of a
a = int(i())

# Loop through the range n-1 to -1 with a step of -1
for j in range(n-1, -1, -1):

    # Take the second value of the jth index of l as integer c
    c = int(l[j][1])

    # Take the first value of the jth index of l as string t
    t = l[j][0]

    # Use conditional operator to calculate a based on the value of t
    a = t<'b' and a-c or t<'e' and a*c or t<'n' and a//c or a+c

# Print the final value of a
print(a)
