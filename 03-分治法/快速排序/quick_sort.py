
#找到一个基准值，然后将数组分为小于基准值的子数组，和大于基准值的子数组
#递归处理各个子数组，直到数组为空或只包含一个元素的"有序"数组
#拼接小于基准值的子有序数组 + 基准值 + 大于基准值的子有序数组 即可得到完整的有序数组
#时间复杂度 最复杂的情况时间复杂度为O(n²) 平均情况下O(n logn)

def quick_sort(arr):
    if len(arr) < 2:
        #基线条件，：数组为空或只包含一个元素的数组即可认为当前数组是有序的。
        return arr;
    else:
        #选择一个基准值
        pivot = arr[0]
        #获取一个数组中全部小于基准值的子数组
        less = [i for i in arr[1:] if i <= pivot]
        #获取一个数组中全部大于基准值的子数组
        greater = [i for i in arr[1:] if i > pivot]
        #小于基准值的数组+基准值+大于基准值的数组 = 有序的数组
        #递归子数组至基线条件，即数组为空或只包含一个元素的"有序"数组
        return quick_sort(less) + [pivot] + quick_sort(greater);

print(quick_sort([12,4,13,56,75,23,13]))


print(1/2)