#include"DataStructure.h"

//读取文件并存入图中
void DataInFile(const char* FileName, Graph &map)
{
	ifstream IF(FileName);
	if (!IF.is_open())
	{
		cout << "error in opening file" << endl;
		exit(1);
	}//文件打开时出错
	int i = 0;
	map.vexnum = 0;
	map.edgenum = 0;
	while (!IF.eof())
	{
		IF >> map.vertices[i].vexname >> map.vertices[i].intro >> map.vertices[i].x >> map.vertices[i].y;//输入顶点信息
		IF >> map.vertices[i].outdegree;//输入该顶点的出度
		int j = 0;
		while (j++<map.vertices[i].outdegree)
		{
			Edge* newEdge=(Edge*)malloc(sizeof(Edge));
			if (newEdge != NULL)//空间分配成功
			{
				IF >> newEdge->adjvex >> newEdge->distance;
				newEdge->nextEdge = map.vertices[i].firstedge;
				map.vertices[i].firstedge = newEdge;//头插法建链表
				map.edgenum++;
			}
		}
		i++;
	}
	IF.close();//关闭文件
	map.vexnum = i;
	map.edgenum /= 2;
}

//将图中数据存入文件中
void DataOutFile(const char* FileName, Graph & map)
{
	ofstream OF(FileName);//默认以截断模式打开文件覆盖原内容
	if (!OF.is_open())
	{
		cout << "error in opening file" << endl;
		exit(1);
	}//文件打开时出错
	int i = 0;
	while (i<map.vexnum)
	{
		OF << map.vertices[i].vexname << ' ' << map.vertices[i].intro << ' ' << map.vertices[i].x << ' ' << map.vertices[i].y;//写入顶点信息
		OF <<' '<< map.vertices[i].outdegree;//写入该顶点的出度
		int j = 0;
		Edge* newEdge = map.vertices[i].firstedge;
		while (j++ < map.vertices[i].outdegree)
		{
			OF << ' ' << newEdge->adjvex <<' '<< newEdge->distance;
			newEdge = newEdge->nextEdge;
		}//遍历写入和该点关联的边
		i++;
		if (i < map.vexnum) OF << endl;
	}
	OF.close();
}
