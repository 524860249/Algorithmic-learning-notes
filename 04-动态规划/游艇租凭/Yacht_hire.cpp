//
//  Yacht_hire.cpp
//  算法
//
//  Created by 白杰杰 on 2019/10/23.
//  Copyright © 2019 jay. All rights reserved.
//

#include <iostream>

using namespace std;

const int ms = 1000;
int r[ms][ms],m[ms][ms],s[ms][ms];
int n;

void rent()
{
    int i,j,k,d;
    //乘客从起点开始
    //依次按照3个站点、4个站点....直到所有站点。
    for (d=3; d <= n; d++) {
        for (i=1; i<=n-d+1; i++) {
            //j为每次计算的临时终点
            j=i+d-1;
            //k为中转站点，找出组合中花费最小的，替换二维表中原有的值
            for (k = i+1; k<j; k++) {
                int temp;
                temp = m[i][k] + m[k][j];
                if (temp < m[i][j]) {
                    m[i][j] = temp;
                    //记录从站点i到j的最优停靠点
                    s[i][j] = k;
                }
            }
        }
    }
}
void print(int i ,int j)
{
    if (s[i][j] == 0) {
        cout << "--" << j;
        return;
    }
    print(i, s[i][j]);
    print(s[i][j],j);
}

int main()
{
    int i,j;
    cout << "请输入站点的个数：";
    cin >> n;
    cout << "依次输入各站点之间的租金：";
    for (i = 1; i<=n; i++) {
        for (j = i+1; j<=n; j++) {
            cin >> r[i][j];
            m[i][j] = r[i][j];
        }
    }
    rent();
    cout << "花费的最少租金为：" << m[1][n] << endl;
    cout << "最少租金经过的站点：" << 1;
    print(1, n);
    cout << endl;
    return 0;
}
