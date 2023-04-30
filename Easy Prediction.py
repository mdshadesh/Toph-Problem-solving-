for _ in [0]*int(input()):  # loop over the test cases
    input()  # read and discard the value of n
    # read the values of the stones, split them into a list of integers,
    # and filter out any zeros or negative values
    stones = [x for x in map(int, input().split()) if x > 0]
    # determine the winner based on the parity of the number of remaining stones
    winner = 'Bob' if len(stones) % 2 == 0 else 'Alice'
    print(winner)
