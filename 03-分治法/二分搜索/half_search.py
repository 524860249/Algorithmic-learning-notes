#二分法查找
#时间复杂度 O(logn)
def binary_search(list,item):
    start = 0;
    end = len(list) - 1;
    while start <= end:
        mid = int((start + end) / 2);
        guess = list[mid];
        if guess == item:
            return mid;
        if guess > item:
            end = mid - 1
        else:
            start = mid + 1
    return None;
list = [12,13,14,15,16,18,24,27,31,35,37,39,40,45,47,49,50,59]
index = binary_search(list,24)

print("您要查找的数字的位置是：",index);