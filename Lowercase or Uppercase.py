for x in range(int(input())):
    s=input().strip();
    print(f'Case {x+1}: {len(s)-max(len([a for a in s if a.isupper()]),len([a for a in s if a.islower()]))}')
