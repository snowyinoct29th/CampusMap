#include"DataStructure.h"

//��ӡ��ͼ
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

//��ɾ�Ĳ�


//�����·���⡪>prim�㷨�����С������
void Prim(Graph& map)
{

}
