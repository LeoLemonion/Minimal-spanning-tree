#include "GraphPrim.h"

int GraphPrim::findMin(vector<int>& ans)
{
	int index = 0;
	int min = ans[0];
	for (int i = 0; i < ans.size(); i++)
	{
		if (min > ans[i])
		{
			min = ans[i];
			index = i;
		}
	}
	return index;
}

void GraphPrim::Init()
{
	cout << "请输入点的个数" << endl;
	cin >> nodeNumber;

	visited.resize(nodeNumber + 1);//初始化

	graph.resize(nodeNumber + 1);//初始化
	for (int i = 0; i <nodeNumber + 1; i++)
		graph[i].resize(nodeNumber + 1, MAX);

	cout << "请输入开始点" << endl;
	cin >> startPoint;
	int a, b;
	cout << "请输入出发点、到达点和路径长度,以‘#’为全部结束" << endl;
	while ((cin >> a && a != '#') && (cin >> b && b != '#'))
	{
		cin >> graph[a][b];//输入权值
		graph[b][a] = graph[a][b];
	}
}

void GraphPrim::Prim(int start)
{
	int temp;
	sum = 0;		
	side.resize(nodeNumber + 1);
	node.push_back(start);
	visited[start] = true;
	for(int i = 1; i <= nodeNumber; i++)
		side[i] = graph[start][i];	
	for(int i = 1; i <= nodeNumber; i++)//找生成树集合点集相连最小权值的边	
	{
		temp = MAX;
		for(int j = 1; j <= nodeNumber; j++)
			if (!visited[j] && temp > side[j])
			{
				temp = side[start = j];
			}
		if(temp == MAX)//如果是无穷了
			break;	
		visited[start] = true; //加入最小生成树集合
		node.push_back(start);
		useSide.push_back(temp);
		sum += temp;//记录权值之和		
		for(int j = 1; j <= nodeNumber; ++j) //更新边数组	
			if (!visited[j] && side[j] > graph[start][j])
			{
				side[j] = graph[start][j];
			}
	}
}

void GraphPrim::Display()
{
	Prim(startPoint);
	cout << "显示最大权值" << sum << endl;
	cout << "路径显示: ";
	for (int i = 0; i < node.size(); i++)
		cout << node[i] << " ";
	cout << endl;
}
