#include"DataStructure.h"

//打印地图
void Print(Graph& map)
{
	cout << map.vexnum << ' ' << map.edgenum << endl;
	int i = 0;
	while (i < map.vexnum)
	{
		cout << map.vertices[i].vexname << ' ' << map.vertices[i].intro << ' ' << map.vertices[i].x << ' ' << map.vertices[i].y;
		cout << ' ' << map.vertices[i].outdegree;
		int j = 0;
		Edge* newEdge = map.vertices[i].firstedge;
		while (j++ < map.vertices[i].outdegree)
		{
			cout << ' ' << newEdge->adjvex << ' ' << newEdge->distance;
			newEdge = newEdge->nextEdge;
		}
		i++;
		if (i < map.vexnum) cout << endl;
	}
}

//增删改查


//铺设电路问题—>prim算法求解最小生成树
void Prim(Graph& map)
{

}
