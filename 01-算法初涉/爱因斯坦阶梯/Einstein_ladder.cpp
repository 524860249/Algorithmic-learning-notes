//
//  Einstein_ladder.cpp
//  算法
// 爱因斯坦阶梯问题
// 有一条长阶梯，一步走俩阶最后余一阶，一步走三阶最后余俩阶
// 一步走五阶最后余四阶，一步走六阶最后余五阶
// 一步走七阶刚好可以走完，问一共多少阶
//  Created by 白杰杰 on 2019/10/11.
//  Copyright © 2019 jay. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
/**
 从1开始循环递增的逐个结算是否满足所有的条件，如果条件满足，则结束循环
 我们在运行支持无法知道while循环究竟会循环多少次
 但是我们逐一去计算每一个数字是否满足确实有点蠢
 */
int ein_ladder()
{
    int n = 1;
    while(!(n %2 == 1 && n % 3 == 2 && n % 5 == 4 && n % 6 == 5 && n % 7 == 0))
    {
        n++;
    }
    cout << "1:" << n << endl;
    return n;
}
/**
 我们再来分析一下问题，每步走7阶刚好可走完，那么我们需要的记过数字就应当是7的倍数
 我们来优化一下我们的算法
 我们的步长由1变为7，运行的执行次数自然也缩小了7倍
 */
int ein_ladder1()
{
    int n = 7;
    while(!(n %2 == 1 && n % 3 == 2 && n % 5 == 4 && n % 6 == 5 && n % 7 == 0))
    {
        n += 7;
    }
    cout << "2:" << n << endl;
    return n;
}

/**
 我们再次分析一下问题，每步跨出的阶数为2、3、5、6，刚好每次剩余的阶数为1、2、4、5，刚好总是差一步就可以刚好跨完
 那么结果的数字必然是2、3、5、6的公倍数-1，并且是7的整数倍
 首先我们来求出2、3、5、6的公倍数
 6位2和3的最小公倍数，所以我们只需求出5和6的最小公倍数：30
 然后减去每次刚好差的一步，作为初始结果，循环判断结果是否满足整除7，若不整除，则每次叠加30，直至最终结果
 
 分析代码可知，相比较上面的算法，此算法时间复杂度明显又有所降低
 */
int ein_ladder2()
{
    int com_mul = 6;
    while(!(com_mul % 5 == 0))
    {
        com_mul += 6;
    }
    int result = com_mul - 1;
    while(!(result % 7 == 0))
    {
        result += com_mul;
    }
    cout << result << endl;
    return com_mul;
}

int main()
{
    ein_ladder();
    ein_ladder1();
    ein_ladder2();
    return 0;
    
}
