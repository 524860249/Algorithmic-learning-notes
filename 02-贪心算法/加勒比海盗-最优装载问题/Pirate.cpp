//
//  Pirate.cpp
//  算法
//
//  Created by 白杰杰 on 2019/10/12.
//  Copyright © 2019 jay. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 10000;
int main_p()
{
    double weights[N];  //记录所有古董的重量
    double loadNum; //海盗船的载重
    int antiqueNum; //古董的数量
    cout << "请输入海盗船的载重" << endl;
    cin >> loadNum;
    cout << "请输入古董的个数" << endl;
    cin >> antiqueNum;
    for (int i = 0; i < antiqueNum; i++) {
        cout << "请输入第" << i + 1 << "个古董的重量" << endl;
        cin >> weights[i];
    }
    //古董重量排序，从小到大
    sort(weights, weights + antiqueNum);
    //记录已经选择的古董的重量
    double temp = 0.0;
    //记录已经选择的古董的数量
    int takeNum = 0;
    for (int i = 0; i < antiqueNum; i++) {
        if (temp + weights[i] > loadNum) {
            break;
        }
        temp += weights[i];
        takeNum += 1;
    }
    cout << "可以装载" << takeNum << "个古董，总重量共" << temp << endl;
    return 0;
}
