#include"GraphKruskal.h"

int main()
{
	GraphKurskal g1;
	g1.Init();
	g1.Kruskal();
	g1.Display();
	return 0;
}

/*
输入样例：
1 1 1
1 4 2
2 6 4
1 5 5
5 6 9
1 3 12
2 3 13
3 4 18
4 5 32

*/
