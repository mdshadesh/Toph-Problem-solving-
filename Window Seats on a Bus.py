test = int(input())
i = 0
while test:
    length, width, distance = map(float, input().split())
    left_area = ((width*length)-(distance*length))/2
    print("Case {}: {:.2f}".format(i+1, left_area))
    i += 1
    test -= 1
