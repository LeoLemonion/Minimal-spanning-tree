#include "GraphKruskal.h"


void GraphKurskal::Init()
{
	node n1;
	int i = 0;
	cout << "请输入有几个点" << endl;
	cin >> nodeNumber;
	visited.resize(nodeNumber + 1, false);
	cout << "请输入各边的关系，'#'结束" << endl;
	cout << "请按照格式：开始点---终止点---距离" << endl;
	while ((cin >> n1.from&& n1.from != '#') && (cin >> n1.to&& n1.to != '#'))
	{
		cin >> n1.distance;
		n1.sideID = ++i;
		graph.push_back(n1);
	}
}

void GraphKurskal::Kruskal()
{

	sort(graph.begin(), graph.end(),cmp);//进行函数比较
		//当选择的边数不为节点数减一的情况，我们继续循环
	minDistacne = 0;
	for (int i = 0; i < graph.size(); i++)
	{
		//判断图中的点是否遍历过，如果遍历过，那么跳过，否则继续遍历
		if (!visited[graph[i].from] || !visited[graph[i].to])
		{
			visited[graph[i].from] = true;
			visited[graph[i].to] = true;
			IDofSide.push_back(graph[i].sideID);
			minDistacne += graph[i].distance;
			if (IDofSide.size() == nodeNumber - 1)
				break;
		}
	}
}

void GraphKurskal::Display()
{
	cout << "总距离是：" << minDistacne << endl<<"权边是：";
	for (int i = 0; i < IDofSide.size(); i++)
		cout << graph[IDofSide[i]-1].distance << " ";
	cout << endl;
}

bool cmp(node a1, node a2)
{
	return a1.distance > a2.distance ? false : true;
}
