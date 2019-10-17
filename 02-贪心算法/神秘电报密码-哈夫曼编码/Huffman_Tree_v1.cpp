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
#include <vector>

using namespace std;

#define MAXVALUE 10000

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
    vector<int> bit;
} HCodeType;
/**
 哈夫曼树
 */
void HuffmanTree(vector<HNodeType> &node_vector,int n)
{
    int i, j;   //循环使用
    int left, right;    //每次需从数组中找出的俩个节点的数组下标
    double left_weight, right_wieght;
    for (i = 0 ; i < n; i++) {
        cout << "请输入" << i + 1 << "个节点及对应的权重，以空格分隔" << endl;
        HNodeType huffNode;
        huffNode.weight = 0;
        huffNode.parent = -1;
        huffNode.lchild = -1;
        huffNode.rchild = -1;
        
        cin >> huffNode.value >> huffNode.weight;
        node_vector.push_back(huffNode);
    }
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
        for (j = 0; j < node_vector.size(); j++) {
            if (node_vector.at(j).weight < left_weight && node_vector.at(j).parent == -1) {
                right_wieght = left_weight;
                right = left;
                left_weight = node_vector.at(j).weight;
                left = j;
            } else if (node_vector.at(j).weight < right_wieght && node_vector.at(j).parent == -1){
                right_wieght = node_vector.at(j).weight;
                right = j;
            }
        }
        node_vector.at(left).parent = n + i;
        node_vector.at(right).parent = n + i;
        
        HNodeType huffNode;
        huffNode.weight = left_weight + right_wieght;
        huffNode.lchild = left;
        huffNode.rchild = right;
        huffNode.parent = -1;
        
        node_vector.push_back(huffNode);
        cout << "第" << i + 1 << "次循环：" << node_vector.at(left).weight << " " << node_vector.at(right).weight  << endl;
    }
    
    for (i = 0; i < node_vector.size(); i++) {
        cout << "parent:" << node_vector.at(i).parent << "    lchild:" <<node_vector.at(i).lchild << " rchild:" << node_vector.at(i).rchild
        << "    weight:" << node_vector.at(i).weight  << "    value:" << node_vector.at(i).value << endl;
    }
}
/**
 哈夫曼编码转换
 */
void HuffmanCode(vector<HCodeType> &code_vector,vector<HNodeType> node_vector,int n)
{
    int i, c, p;
    for (i = 0; i < n; i++) {
        HCodeType cd;
        c = i;
        p = node_vector.at(c).parent;
        while (p != -1) {
            if(node_vector.at(p).lchild == c){
                cd.bit.push_back(0);
            } else {
                cd.bit.push_back(1);
            }
            c = p;
            p = node_vector.at(c).parent;
        }
        code_vector.push_back(cd);
    }
}
int main()
{
    int i, j, n;
    cout << "请输入节点数量"<< endl;
    cin >> n;
    
    vector<HNodeType> Node_vector;
    vector<HCodeType> Code_vector;

    HuffmanTree(Node_vector, n);
    HuffmanCode(Code_vector,Node_vector,n);
    
    for (i = 0; i < n; i++) {
        cout << Node_vector.at(i).value << ": Huffman code is: ";
        for (j = Code_vector.at(i).bit.size() - 1; j > -1 ; j--) {
            cout << Code_vector.at(i).bit.at(j);
        }
        cout << endl;
    }
    return 0;
}

/**
 a: Huffman code is: 0100
 b: Huffman code is: 011
 c: Huffman code is: 00
 d: Huffman code is: 10
 e: Huffman code is: 11
 f: Huffman code is: 0101
 
 */
