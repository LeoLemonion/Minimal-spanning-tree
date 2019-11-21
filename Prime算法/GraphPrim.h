#pragma once
#ifndef _GRAPHPRIM_H_
#define _GRAPHPRIM_H_
#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;

const int MAX = INT_MAX;

class GraphPrim
{
private:
	vector<vector<int>>graph;//邻接矩阵存储点与边的关系
	vector<bool>visited;//判断是否经历过
	vector<int>side;

	vector<int>node;//取点的路径，用来存放输出点的顺序
	vector<int>useSide;//使用的边，用来存放边的权值

	int nodeNumber;//点的个数
	int startPoint;//开始点
	int sum;

	int findMin(vector<int>& ans);//返回下标

public:
	void Init();//初始化
	void Prim(int start);//普利姆算法，以及开始点
	void Display();//显示参数
};


#endif // !_GRAPHPRIM_H_
