//
//  MergeSort.cpp
//  算法
//
//  Created by 白杰杰 on 2019/10/17.
//  Copyright © 2019 jay. All rights reserved.
//

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
    }
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
