//
//  Fibonacci_sequence.cpp
//  斐波那契数列数列
//
//  Created by 白杰杰 on 2019/10/10.
//  Copyright © 2019 jay. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

//使用递归求出斐波那契数列数列的第N个值是多少
//其时间复杂度未指数阶
//随着n的增大，算法的时间复杂度成指数增长
//n为40时我们基本可以很快得出结果，如果等n大于50时，计算就需要大量的时间，如果等n大于100时，我们估计要等到明年了
int Fib_seq(int n)
{
    if (n < 1) {
        return -1;
    }
    if (n == 1 || n == 2) {
        return 1;
    }
    return Fib_seq(n -1) + Fib_seq(n-2);
}
//初始化斐波那契数列的前俩位，当然均为1，将数据存储到数组中
//使用循环，取数组数列的前俩项之和，赋值给当前项
//待循环结束，我们就得到了完整的斐波那契数列数列
//时间复杂度为O(n),相比Fib_seq时间复杂度大大降低
//因我们记录了完整的斐波那契数列，所以空间复杂度也为O(n)
int Fib_seq1(int n)
{
    if (n < 1) {
        return -1;
    }
    int *a = int long[n + 1];    //定义了一个长度为n+1的数组，下标为0的空间未使用
    a[1] = 1;
    a[2] = 1;
    for (int i = 3; i <= n; i++) {
        a[i] = a[i - 1] + a[i - 2];
    }
    return a[n];
}
//通过使用俩个变量赋值，碾转相加，每次只记录前一项
//时间复杂度为O(n)
//空间复杂度降低为O(1)
int Fib_seq2(int n)
{
    if (n < 1){
        return -1;
    }
    if (n == 1 || n == 2) {
        return 1;
    }
    int num1 = 1;
    int num2 = 1;
    for (int i = 3; i <= n; i++) {
        num2 = num1 + num2;
        num1 = num2 - num1;
    }
    return num2;
}

//递归变换d的方式
//时间复杂度为O(n)
long Fib_seq3(long a, long b, int count)
{
    if(count == 0)
        return b;
//    cout << a << "--" << b << endl;
    return Fib_seq3(a+b,a,count-1);
}

/**
 a = b*q + a*q + a*p
 b = b*p + a*q
 其中p=0,q=1
 把这种变换称为T变换，那么对于T的平方来说，有：
 a = (bp+aq)p+(bq+aq+ap)*q+(bq+aq+ap)*p = b(2pq+q^2)+a(p^2+2pq+3q^2)
 b = (bp+aq)p+(bq+aq+ap)q = b(p^2+q^2)+a(q^2+2pq)
 时间复杂度为O(logn)
 
 */
int Fib_seq4(int a,int b,int p,int q,int count)
{
    if (count == 0)
        return b;
    else
        if (count%2)
            return Fib_seq4(b*p+a*q+a*p,b*p+a*q,p,q,count-1);
        else
            return Fib_seq4(a,b,p*p+q*q,q*q+2*p*q,count/2);
}
int main()
{
    int num = 20;
    cout << Fib_seq(num) << endl;
    cout << Fib_seq1(num) << endl;
    cout << Fib_seq2(num) << endl;
    cout << Fib_seq3(1,0,num) << endl;
    cout << Fib_seq4(1,0,0,1,num) << endl;
    return 0;
}
