#include<string>
#include<fstream>//使用文件流存取数据
#include<iostream>
#include<stdlib.h>
using namespace std;

#define MAX_VERTEX_NUM 100//最大顶点数


//校园地图->带权无向图->邻接表存储结构
typedef struct Edge{
	int adjvex;//边所指顶点的索引位置
	struct Edge* nextEdge;//指向下一条边的指针
	double distance;//边的权重=两点距离
}Edge;//边表的定义

typedef struct VNode{
	string vexname;//地点名称
	string intro;//地点简介
	double x, y;//地点坐标
	int outdegree;//该顶点的出度
	Edge* firstedge;//指向依附该顶点的第一条边
}VNode,AdjList[MAX_VERTEX_NUM];//顶点，顶点数组定义

typedef struct {
	AdjList vertices;
	int vexnum, edgenum;//顶点数，边数
}Graph;//图的结构定义

void DataInFile(const char* FileName, Graph &map);
void DataOutFile(const char* FileName, Graph& map);
void Print(Graph& map);