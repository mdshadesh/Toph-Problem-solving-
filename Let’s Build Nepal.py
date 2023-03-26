nep = "nepal"

# read the number of test cases
for i in range(int(input())):
    # read the string
    s = input()
    # initialize a counter variable to count the number of characters from "nepal" present in the string
    c = 0
    # loop through each character in "nepal"
    for i in nep:
        # check if the character is present in the string
        if i in s:
            # increment the counter variable
            c += 1
    # check if more than 4 characters from "nepal" are present in the string
    if c > 4:
        print("Maile Nepal banauna sakchhu!!")
    else:
        print("Hami sabai milera Nepal Banau hai!!")
