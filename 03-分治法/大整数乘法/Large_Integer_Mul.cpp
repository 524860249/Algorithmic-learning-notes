//
//  Large_Integer_Mul.cpp
//  算法
//
//  Created by 白杰杰 on 2019/10/18.
//  Copyright © 2019 jay. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

#define M 100
char str_a[1000];
char str_b[1000];
typedef struct _Node
{
    int str[M];
    int len;
    int pow;
} Node,*pNode;

/**
    src 被拆分的字符结点
    des b拆分后的结果结点
    st 拆分点
    len 拆分的数据长度
 */
void split(pNode src,pNode des,int st,int len)
{
    int i,j;
    for (i = st,j=0; i<st + len; i++,j++) {
        des->str[j] = src->str[i];
    }
    des->len = len;
    des->pow = st + src->pow;
}

void add(pNode pa,pNode pb,pNode result)
{
    int i,cc,k,palen,pblen,len;
    int ta,tb;
    pNode temp;
    if(pa->pow < pb->pow)
    {
        temp = pa;
        pa = pb;
        pb = temp;
    }
    result->pow = pb->pow;
    cc = 0;
    palen = pa->len + pa->pow;
    pblen = pb->len + pb->pow;
    
    if (palen > pblen) {
        len = palen;
    } else {
        len = pblen;
    }
    k = pa->pow - pb->pow;
    
    for (i = 0; i < len - result->pow; i++) {
        if (i < k) {
            ta = 0;
        } else {
            ta = pa->str[i - k];
        }
        if (i < pb->len) {
            tb = pb->str[i];
        }else{
            tb = 0;
        }
        if (i>=pa->len + k) {
            ta = 0;
        }
        result->str[i] = (ta + tb + cc) % 10;
        cc = (ta + tb + cc) / 10;
    }
    if (cc) {
        result->str[i++] = cc;
    }
    result->len = i;
}

void mul(pNode pa,pNode pb,pNode result)
{
    int i, cc, w;
    int ma = pa->len >> 1,mb = pb->len >> 1;
    Node ah,al,bh,bl;
    Node t1,t2,t3,t4,z;
    pNode temp;
    
    if (!ma || !mb) {
        if(!ma)
        {
            temp = pa;
            pa = pb;
            pb = temp;
        }
        result->pow = pa->pow + pb->pow;
        w = pb->str[0];
        cc = 0;
        for (i = 0; i < pa->len; i++) {
            result->str[i] = (w * pa ->str[i] + cc) % 10;
            cc = (w * pa->str[i] +cc) / 10;
        }
        if (cc) {
            result->str[i++] = cc;
        }
        result->len = i;
        return;
    }
    //大整数拆分，将大整数拆分为俩个部分，高位部分和低位部分ah和al
    split(pa, &ah, ma, pa->len-ma);
    split(pa, &al, 0, ma);
    split(pb, &bh, mb, pb->len-mb);
    split(pb, &bl, 0, mb);
    
    //根据乘法运算法则，(a + b) * (c + d) = ac + ad + bc +bd
    mul(&ah, &bh, &t1);
    mul(&ah, &bl, &t2);
    mul(&al, &bh, &t3);
    mul(&al, &bl, &t4);

    //将所有拆分后的数据合并即是我们所需的s值
    add(&t3, &t4, result);
    add(&t2, result, &z);
    add(&t1, &z, result);
}

int main_LIM()
{
    Node result,a ,b;
    cout << "输入大整数 a:" << endl;
    cin >> str_a;
    cout << "输入大整数 b:" << endl;
    cin >> str_b;
    
    cout << strlen(str_a) << endl;
    cout << strlen(str_b) << endl;
    
    a.len = strlen(str_a);
    b.len = strlen(str_b);
    
    cout << a.len << endl;
    cout << b.len << endl;
    
    int z = 0,i;
    for (i = a.len - 1; i >= 0; i--) {
        a.str[z++] = str_a[i] - '0';
    }
    a.pow = 0;
    z = 0;
    for (i = b.len -1; i >= 0; i--) {
        b.str[z++] = str_b[i] - '0';
    }
    b.pow = 0;
    mul(&a, &b, &result);
    cout << "最终结果为：";
    
    for (i = result.len - 1; i>= 0; i--) {
        cout << result.str[i];
    }
    cout << endl;
    
    return 0;
    
}
