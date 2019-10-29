//
//  Edit_distance.cpp
//  算法
//
//  Created by 白杰杰 on 2019/10/22.
//  Copyright © 2019 jay. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

const int N = 1000;

char str1[N],str2[N];
int dis[N][N];

int min(int a,int b)
{
    return a>b?b:a;
}

int editDistance(char *str1,char *str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    for (int i = 0; i <= len1; i++) {
        dis[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) {
        dis[0][j] = j;
    }
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int dif;
            if (str1[i-1] == str2[j-1]) {
                dif = 0;
            } else {
                dif = 1;
            }
            int temp = min(dis[i][j-1] + 1,dis[i-1][j] + 1);
            dis[i][j] = min(temp,dis[i-1][j-1] + dif);
        }
    }
    return dis[len1][len2];
}
int main()
{
    cout << "输入第一个字符串" << endl;
    cin >> str1;
    cout << "输入第二个字符串" << endl;
    cin >> str2;
    
    cout << str1 << "和" << str2 << "的编辑距离是：" << editDistance(str1, str2) << endl;
    return 0;
}

