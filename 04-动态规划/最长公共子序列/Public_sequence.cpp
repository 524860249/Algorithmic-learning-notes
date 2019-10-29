//
//  Public_sequence.cpp
//  算法
//
//  Created by 白杰杰 on 2019/10/22.
//  Copyright © 2019 jay. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

const int N = 1002;
int c[N][N],b[N][N];
char s1[N],s2[N];
int len1,len2;

void deal()
{
    int i,j;
    for (i = 1; i <= len1; i++) {
        for (j = 1; j <= len2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = 1;
            } else {
                if (c[i][j -1] >= c[i-1][j]) {
                    c[i][j] = c[i][j-1];
                    b[i][j] = 2;
                }else{
                    c[i][j] = c[i-1][j];
                    b[i][j] = 3;
                }
            }
        }
    }
}

void print(int i,int j)
{
    if (i < 0 || j < 0) {
        return;
    }
    if (c[i][j] == c[i-1][j-1]) {
        print(i - 1, j - 1);
        return;
    }
    if (c[i][j-1] == c[i-1][j] && c[i-1][j-1] == c[i][j-1]) {
        print(i - 1, j - 1);
        cout << s1[i - 1];
        return;
    }
    if (c[i][j-1] >= c[i-1][j]) {
        print(i,j-1);
    }
    if (c[i-1][j] > c[i][j-1]) {
        print(i-1,j);
    }
}


int main()
{
    int i,j;
    char result[N];
    cout << "输入第一个字符串" << endl;
    cin >> s1;
    cout << "输入第二个字符串" << endl;;
    cin >> s2;
    
    len1 = strlen(s1);
    len2 = strlen(s2);
    
    for (i = 0; i <= len1; i++) {
        c[i][0] = 0;
    }
    for (j = 0;j <= len2; j++) {
        c[0][j] = 0;
    }
    deal();
    
    cout << "    ";
    for (j = 0; j <= len2; j++) {
        cout << s2[j] << " ";
    }
    cout << endl;
    for (i = 0; i <= len1;i++) {
        if (i > 0) {
            cout << s1[i - 1] << " ";
        }else{
            cout << "  ";
        }
        
        for (j = 0; j <= len2; j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "-------------------" << endl;
    
    print(len1,len2);
    cout << endl;
    return 0;
}
