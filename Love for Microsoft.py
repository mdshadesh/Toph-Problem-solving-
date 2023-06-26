s = input()  # Read the username from input

print(('Only I', 'We both')[set('microsoft').issubset(set(s))] + " love Microsoft!")
