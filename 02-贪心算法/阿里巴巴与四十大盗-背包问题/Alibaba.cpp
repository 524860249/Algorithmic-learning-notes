//
//  Alibaba.cpp
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

struct treasure{
    double weight;
    double price;
    double quality;
} t[N];

bool cmp(treasure first,treasure second)
{
    return first.quality > second.quality;
}

int main()
{
    int treasureNum;  //宝物的数量
    double loadNum;    //驴子的画运载能力
    
    cout << "请输入驴子的载重能力" << endl;
    cin >> loadNum;
    cout << "请输入宝物的数量" << endl;
    cin >> treasureNum;
    for (int i = 0; i < treasureNum; i++) {
        cout << "请输入第" << i + 1 << "个宝物的重量及价格，以空格分隔：" << endl;
        cin >> t[i].weight >> t[i].price;
        t[i].quality = t[i].price / t[i].weight;
    }
    
    sort(t, t + treasureNum, cmp);
    for (int i = 0; i < treasureNum; i++) {
        cout << "重量:" << t[i].weight << " 价格:" << t[i].price << " 性价比:" << t[i].quality << endl;
    }
    
    double totalValue = 0.0;
    for (int i = 0; i < treasureNum; i++) {
        if (loadNum > t[i].weight) {
            totalValue += t[i].price;
            loadNum -= t[i].weight;
            cout << "宝物重量:" << t[i].weight << " 宝物价格：" << t[i].price << " 宝物性价比:" << t[i].quality << " 已经装载重量:" << totalValue << " 剩余空间:" << loadNum <<  endl;
        } else {
            totalValue += t[i].price * (loadNum / t[i].weight);
            cout << "宝物重量:" << t[i].weight << " 宝物价格：" << t[i].price << " 宝物性价比:" << t[i].quality << " 已经装载重量:" << totalValue << " 剩余空间:" << loadNum << " 拆分当前宝物，取重量为" << loadNum << "的，其价值为" << t[i].price * (loadNum / t[i].weight) << endl;
            break;
        }
    }
    cout << "阿里巴巴运走的财宝的总价值为" << totalValue << endl;
    return 0;
}
