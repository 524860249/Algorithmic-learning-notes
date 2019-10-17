//
//  Huffman_Tree.cpp
//  算法
//
//  Created by 白杰杰 on 2019/10/14.
//  Copyright © 2019 jay. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;
#define MAXBIT 100
#define MAXVALUE 10000
#define MAXLEAF 30
#define MAXNODE MAXLEAF*2 - 1

typedef struct
{
    double weight;
    int parent;
    int lchild;
    int rchild;
    char value;
} HNodeType;

typedef struct
{
    int bit[MAXBIT];
    int start;
} HCodeType;

HNodeType HuffNode[MAXNODE];
HCodeType HuffCode[MAXLEAF];

void HuffmanTree(HNodeType HuffNode[MAXNODE], int n)
{
    int i, j;   //循环使用
    int left, right;    //每次需从数组中找出的俩个节点的数组下标
    double left_weight, right_wieght;
    for (i = 0; i < 2 * n -1; i++) {
        HuffNode[i].weight = 0;
        HuffNode[i].parent = -1;
        HuffNode[i].lchild = -1;
        HuffNode[i].rchild = -1;
    }
    for (i = 0 ; i < n; i++) {
        cout << "请输入" << i + 1 << "个节点及对应的权重，以空格分隔" << endl;
        cin >> HuffNode[i].value >> HuffNode[i].weight;
    }
    int size = n;
    //构造哈夫曼树
    //i < n-1 循环完毕后，最终剩余的为根节点
    for (i = 0; i < n-1; i++) {
        left_weight = right_wieght = MAXVALUE;
        left = right = -1;
        /**
         使用贪心策略每次找出还没有父节点的俩个权重最小的节点
         将权重略小的节点置于左侧节点，权重略大的节点置于右侧节点
         使用当前俩个节点生成一个新的节点，放置于列表的最后，以便下次循环使用
         */
        for (j = 0; j < n + i; j++) {
            if (HuffNode[j].weight < left_weight && HuffNode[j].parent == -1) {
                right_wieght = left_weight;
                right = left;
                left_weight = HuffNode[j].weight;
                left = j;
            } else if (HuffNode[j].weight < right_wieght && HuffNode[j].parent == -1){
                right_wieght = HuffNode[j].weight;
                right = j;
            }
        }
        HuffNode[left].parent = n + i;
        HuffNode[right].parent = n + i;
        //通过左右俩个节点生成其父节点，并将父节点放置于数组最后
        HuffNode[n + i].weight = left_weight + right_wieght;
        HuffNode[n + i].lchild = left;
        HuffNode[n + i].rchild = right;
        size++;
        cout << "第" << i + 1 << "次循环：" << HuffNode[left].weight << " " << HuffNode[right].weight  << endl;
    }
    
    for (i = 0; i < size; i++) {
        cout << "parent:" << HuffNode[i].parent << "    lchild:" << HuffNode[i].lchild << " rchild:" << HuffNode[i].rchild
        << "    weight:" << HuffNode[i].weight  << "    value:" << HuffNode[i].value << endl;
    }
    
    
    
}
void HuffmanCode(HCodeType HuffCode[MAXLEAF],int n)
{
    HCodeType cd;
    int i, j, c, p;
    for (i = 0; i < n; i++) {
        cd.start = n - 1;
        c = i;
        p = HuffNode[c].parent;
        while (p != -1) {
            if(HuffNode[p].lchild == c){
                cd.bit[cd.start] = 0;
            } else {
                cd.bit[cd.start] = 1;
            }
            cd.start--;
            c = p;
            p = HuffNode[c].parent;
        }
        for (j = cd.start + 1; j < n; j++) {
            HuffCode[i].bit[j] = cd.bit[j];
            cout <<HuffCode[i].bit[j];
        }
        cout << endl;
        HuffCode[i].start = cd.start;
    }
}
int main()
{
    int i, j, n;
    cout << "请输入节点数量"<< endl;
    cin >> n;
    HuffmanTree(HuffNode, n);
    
    cout << n  << endl;
    
    HuffmanCode(HuffCode, n);
    
    for (i = 0; i < n; i++) {
        cout << HuffNode[i].value << ": Huffman code is: ";
        for (j = HuffCode[i].start + 1; j < n; j++) {
            cout << HuffCode[i].bit[j];
        }
        cout << endl;
    }
    return 0;
}
