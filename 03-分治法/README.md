# 什么是分治法
分而治之是很古老的策略，本意是将一个较大的问题拆分为若干个规模较小的的相同的子问题，而后分而治之。又称为分治算法。
### 分治算法的要素：   
	1、原问题可拆分为若干个规模较小的相同子问题   
	2、子问题之间相互独立   
	3、各个子问题的解合并后即为原问题的解   

### 二分搜索
如果我们要从一个有序的序列中查找数字X是否存在，我们可以直接循环判断每一个数字是否同X相等，如果相同则表示X存在于序列。这样查找数组最快只需要一次，最慢则需要N此，其时间复杂度为O(n)。因为是有序的序列，那么是否可以有更快的查询方式呢？   
我们可以通过二分搜索的方式查询。
#### 算法设计
> 1. 我们可以将序列分为三个部分，从中获取中间位置的数据 M，M左侧的序列及M右侧的序列。   
> 2. 使用M和X对比，如果M = X则直接返回，如果M > X则X应当在M左侧的序列中，如果M < X 则X应当在M的右侧序列中。   
> 3. 重复拆分M左侧或右侧的序列，直至找到对应数据。若最终都为找到，则表示当前数据不存在于序列中。   
#### 程序实现
	#include <stdio.h>
	#include <iostream>
	#include <cstdlib>
	#include <cstdio>
	#include <algorithm>

	using namespace std;

	const int M =1000;
	int x,n,i;
	int s[M];

	int BinarySearch(int n,int s[],int x)
	{
	    int low = 0,high = n - 1;
	    while (low <= high) {
	        int middle = (low + high) / 2;
	        if (x == s[middle]) {
	            return middle;
	        } else if (x < s[middle]){
	            high = middle - 1;
	        } else {
	            low = middle + 1;
	        }
	    }
	    return -1;
	}

	int main()
	{
	    cout << "输入数列中的元素个数:";
	    cin >> n;
	    cout << "请依次输入数列中的元素";
	    for (i = 0; i < n; i++) {
	        cin >> s[i];
	    }
	    sort(s,s + n);
	    cout << "排序后的数组为：";
	    for (i = 0; i< n ; i++) {
	        cout << s[i] << " ";
	    }
	    cout << endl;
	    cout << "请输入要查找的数字：";
	    
	    while (cin >> x) {
	        i = BinarySearch(n, s, x);
	        if (i == -1) {
	            cout << "该数字不存在于数列中" << endl;
	        } else {
	            cout << "该数字在序列的第"<< i + 1 << "位上" << endl;
	        }
	    }
	    return 0;
	}
#### 算法分析
相比较循环挨个查询序列数据的时间复杂度O(n)，二分搜索的时间复杂度将为了O(logn)

### 合并排序
合并排序采用的是分治策略，将一个大的问题拆分为很多个小问题，先解决小的问题，继而合并众多小问题得到原问题的解。又称为归并排序   
排序问题给定的一个是无序的序列，通过分治策略将序列分为俩个大致相等的子序列，如果子序列依然较大，则继续拆分，直至拆分至其中子序列中只包含一个元素，而后进行合并即可得到最终解。
#### 算法设计
> 1. 将序列从中拆分为俩个子序列，如果序列还较大，则将子序列继续拆分，直至俩个子序列中只有一个元素，因为只有一个元素的序列是有序的。
> 2. 将俩个序列合并排序
> 3. 将所有排好序的有序子序列进行合并，得到最终的有序序列
#### 程序实现
	#include <cstdlib>
	#include <iostream>
	#include <cstdio>

	using namespace std;

	void Merge(int A[],int low,int mid,int high)
	{
	    int *Temp = new int[high - low -1];
	    int i = low,j = mid + 1,k = 0;
	    while (i <= mid && j <= high) {
	        if (A[i] <= A[j]) {
	            Temp[k++] = A[i++];
	        } else {
	            Temp[k++] = A[j++];
	        }
	    }
	    while (i <= mid) {
	        Temp[k++] = A[i++];
	    }
	    while (j <= high) {
	        Temp[k++] = A[j++];
	    }
	    for (i = low,k = 0;i<=high; i++) {
	        A[i] = Temp[k++];
	        cout << A[i] << " ";
	    }
	    cout << endl;
	    delete []Temp;
	}
	void MergeSort(int A[],int low,int high)
	{
	    if (low < high) {
	        int mid = (low + high) / 2;
	        MergeSort(A, low, mid);
	        MergeSort(A, mid + 1, high);
	        Merge(A, low, mid, high);
	    }
	}
	int main()
	{
	    int n,A[100];
	    cout << "请输入数列中的元素个数："  << endl;
	    cin >> n;
	    cout << "请依次输入数列中的元素" << endl;
	    for (int i = 0; i < n; i++) {
	        cin >> A[i];
	    }
	    MergeSort(A, 0, n-1);
	    cout << "合并排序的结果" << endl;
	    for (int i = 0; i < n; i++) {
	        cout << A[i] << " ";
	    }
	    cout << endl;
	    return 0;
	}

### 快速排序 
上面我们了解了归并排序，每次都将小问题一分为二，直到不能分时再合并排序，这个操作拆分很简单，但归并是就比较复杂了，需要一个辅助的数组完成合并。    
而快速排序是通过将序列拆分为独立的俩个序列，而其中一个序列的所有数据都小于另一个序列的数据，然后重复执行此方法，直至某个序列中只存在一个元素时进行合并。   
#### 算法设计
> 1. 从序列中随机找出一个元素作为基准值，然后根据这个基准值将序列分为俩子序列，一个全部大于这个基准值，一个全部小于这个基准值
> 2. 重复第一个步骤，直至其中一序列的元素只有一个。
> 3. 将所有子序列合并，得到最终的解

#### 程序实现
	#include <iostream>
	using namespace std;

	int Partition(int r[],int low,int high)
	{
	    int i = low,j = high,pivot=r[low];
	    while (i<j) {
	        while (i < j && r[j] > pivot){
	            j--;
	        }
	        if (i < j) {
	            swap(r[i++],r[j]);
	        }
	        
	        while (i < j&& r[i] <= pivot) i++;
	        if (i < j) {
	            swap(r[i],r[j--]);
	        }
	    }
	    return i;
	}

	void QuickSort(int R[],int low,int high)
	{
	    int mid;
	    if(low < high){
	        mid = Partition(R,low, high);
	        QuickSort(R, low, mid -1);
	        QuickSort(R, mid+1, high);
	    }
	}

	int main()
	{
	    int a[1000];
	    int i,N;
	    cout << "请输入需要排序的数据的个数：";
	    cin >> N;
	    cout << "请输入要排序的数字" << endl;;
	    for (i = 0; i < N; i++) {
	        cin >> a[i];
	    }
	    cout << "------------" << endl;
	    for (i = 0; i < N; i++) {
	        cout << a[i] << " ";
	    }
	    cout << endl;
	    QuickSort(a, 0, N-1);
	    cout << "排序后的序列为：" << endl;
	    for (i = 0; i< N; i++) {
	        cout << a[i] << endl;
	    }
	    cout << endl;
	    return 0;
	}



