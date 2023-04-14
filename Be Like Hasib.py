while True:
    try:
        N, X = map(int, input().split())
    except:
        break
    left, right = 1, N
    cnt = 0
    
    while left < right:
        mid = (left + right) // 2
        cnt += 1
        if X > mid:
            left = mid + 1
        else:
            right = mid
    
    print(cnt)
