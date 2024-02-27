#include<string>
#include<fstream>//ʹ���ļ�����ȡ����
#include<iostream>
#include<stdlib.h>
using namespace std;

#define MAX_VERTEX_NUM 100//��󶥵���


//У԰��ͼ->��Ȩ����ͼ->�ڽӱ�洢�ṹ
typedef struct Edge{
	int adjvex;//����ָ���������λ��
	struct Edge* nextEdge;//ָ����һ���ߵ�ָ��
	double distance;//�ߵ�Ȩ��=�������
}Edge;//�߱�Ķ���

typedef struct VNode{
	string vexname;//�ص�����
	string intro;//�ص���
	double x, y;//�ص�����
	int outdegree;//�ö���ĳ���
	Edge* firstedge;//ָ�������ö���ĵ�һ����
}VNode,AdjList[MAX_VERTEX_NUM];//���㣬�������鶨��

typedef struct {
	AdjList vertices;
	int vexnum, edgenum;//������������
}Graph;//ͼ�Ľṹ����

void DataInFile(const char* FileName, Graph &map);
void DataOutFile(const char* FileName, Graph& map);
void Print(Graph& map);