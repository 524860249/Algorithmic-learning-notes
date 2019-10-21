//
//  Binary_Search.cpp
//  算法
//
//  Created by 白杰杰 on 2019/10/17.
//  Copyright © 2019 jay. All rights reserved.
//

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
