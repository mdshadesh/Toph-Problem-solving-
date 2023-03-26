for i in range(int(input())):
    s = input().lower().split()
    if "programming" in s or "developer" in s or "cse" in s:
        print("Case {}: CSE Department".format(i+1))
    elif "ce" in s:
        print("Case {}: CE Department".format(i+1))
    elif "eee" in s:
        print("Case {}: EEE Department".format(i+1))
    elif "photo" in s:
        print("Case {}: SECPA".format(i+1))
    elif "culture" in s or "cultural" in s:
        print("Case {}: Shoroborno".format(i+1))
    else:
        print("Case {}: Sylhet Engineering College".format(i+1))
