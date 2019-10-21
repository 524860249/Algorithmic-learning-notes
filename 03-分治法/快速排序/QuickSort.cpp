//
//  QuickSort.cpp
//  算法
//
//  Created by 白杰杰 on 2019/10/17.
//  Copyright © 2019 jay. All rights reserved.
//

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
    for (int c = 0; c < 6; c++) {
        cout << r[c] << " ";
    }
    cout << endl;
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
