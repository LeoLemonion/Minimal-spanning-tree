#pragma once
#ifndef _GRAPHKRUSKAL_H_
#define _GRAPHKRUSKAL_H_
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<vector>
using namespace std;
//	这是利用邻接矩阵来实现的克鲁斯卡尔搜索最小生成树的算法
struct node
{
	int from, to;
	int sideID;//记录边号，已选定可以输出的边
	int distance;
};

class GraphKurskal
{
private:
	vector<node>graph;//记录边
	vector<bool>visited;//是否经历过
	vector<int>IDofSide;//每条边的ID
	int minDistacne;//最小权值
	int nodeNumber;//几个点

	//void Sort();//这个程序是调用库函数的sort函数进行排序，因此没有写自定义sort函数
public:
	void Init();//初始化
	void Kruskal();//进行克鲁斯卡尔算法，找到最小生成树
	void Display();//显示

};
bool cmp(node a1,node a2);//从小到大排序的函数

#endif // !_GRAPHKRUSKAL_H_
