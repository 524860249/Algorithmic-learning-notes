//
//  Goldbach_conjecture.cpp
//  算法
//  哥德巴赫猜想
// 任意大于2的偶数，都可以表示成俩个素数之和
// 验证2000以内的大于2的偶数都能分解为俩个素数之和
//
//  Created by 白杰杰 on 2019/10/11.
//  Copyright © 2019 jay. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
//判断当前数字是否为素数
int is_prime(int i)
{
    int j;
    if (i <= 1) return 0;
    if (i == 2) return 1;
    for (j = 2; j <= (int)(sqrt((double)i)); j++) {
        if (!(i%j)) return 0;
    }
    return 1;
}
//哥德巴赫猜想实现
//从大于2的偶数项至2000，循环处理
//将每一项逐个拆分为俩个数字，验证这俩个数字是否均为素数
//如果当内存循环完全执行完毕，切未发现俩个相加等于当前外层循环的数字的素数，则n的值恰好等于i，则证明哥德巴赫猜想不成立
//算法效率并不理想，因为分解后的每个值都需要调用prime函数验证是否为素数
void gold_con()
{
    int i ,n;
    for (i = 4; i <= 2000; i += 2) {
        for (n = 2; n < i; n++) {
            if (is_prime(n)) {
                if (is_prime(i - n)) {
                    cout << i << "=" << n << "+" << i - n << endl;
                    break;
                }
            }
        }
        if (i == n) {
            cout << "证明异常" << endl;
        }
    }
}
/**
 判断所有可以分解得到的数字是否为素数，将分解后的数字作为数组的下标，是否为素数作为当前下标的值
 如2位素数，则prime_arr[2]的值为1，3为素数，则prime_arr[3]的值为1，而4非素数，则prime_arr[4]的值为0，以此类推
 这样做在验证数字是否为素数时，只需要调用数组即可，大大减小了时间复杂度
 我们申明一个长度为1999的数组（数组下标从0开始，我们需要存储的最大下标为1998）
 */
void gold_con1()
{
    int *prime_arr = new int[1999];
    for (int i = 2; i < 1998; i++) {
        prime_arr[i] = is_prime(i);
    }
    int i ,n;
    for (i = 4; i < 2000; i += 2) {
        for (n = 2; n < i; n++) {
            if (prime_arr[n]) {
                if (prime_arr[i - n]) {
                    cout << i << "=" << n << "+" << i - n << endl;
                    break;
                }
            }
        }
        if (i == n) {
            cout << "error" << endl;
        }
    }
}
/**
 存储记录2000以内的所有数字是否为素数，以数字为下标，是否为素数为值，存储在数组中。
 以数组存储2000以内的所有素数
 将数字分解至少包含一个素数的俩个数，验证另外一个数字是否为素数
 当以302个素数为基础拆分完毕后，所有对应的数字均不为素数则证明哥德巴赫猜想不成立。
 */
void gold_con2()
{
    int *prime_arr = new int[302];
    int *data_arr = new int[1999];
    int index = 0;
    for (int i = 2; i<1998; i++) {
        if (is_prime(i)) {
            data_arr[i] = 1;
            prime_arr[index++] = i;
        }else{
            data_arr[i] = 0;
        }
    }
    for (int i = 4; i< 2000; i += 2) {
        int j;
        bool flag = true;
        for (j = 0; prime_arr[j] < i; j++) {
            if (data_arr[i - prime_arr[j]]) {
                flag = false;
                cout << i << "=" << prime_arr[j] << "+" << i-prime_arr[j] << endl;
                break;
            }
        }
        if (flag) {
            cout << "error" << endl;
        }
    }
}

int main()
{
//    gold_con();
//    gold_con1();
    gold_con2();
//    if (prime(2)) {
//        cout << "success" << endl;
//    }
}
