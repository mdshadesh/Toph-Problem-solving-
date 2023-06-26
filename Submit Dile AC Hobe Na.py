def count_common_ids(n, group1, group2):
    common_ids = set(group1) & set(group2)
    return len(common_ids)

n = int(input())
group1 = list(map(int, input().split()))
group2 = list(map(int, input().split()))

common_ids_count = count_common_ids(n, group1, group2)
print(common_ids_count)
