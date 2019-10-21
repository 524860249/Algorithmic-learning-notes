
def merge(left,right):
    temp = [];
    i = j = 0;
    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            temp.append(left[i])
            i += 1
        else:
            temp.append(right[j])
            j += 1
    if j == len(left):
        for item in left[i:]:
            temp.append(item)
    else:
        for item in right[j:]:
            temp.append(item)
    return temp

def merge_sort(lists):
    if len(lists) <= 1:
        return lists
    middle = int(len(lists) / 2)
    left = merge_sort(lists[:middle])
    right = merge_sort(lists[middle:])
    return merge(left,right)


sort_list = [12,2,334,123,565,23,56,755]
result_list = merge_sort(sort_list);
for item in result_list:
    print(item)