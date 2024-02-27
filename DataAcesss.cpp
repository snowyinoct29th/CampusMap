#include"DataStructure.h"

//��ȡ�ļ�������ͼ��
void DataInFile(const char* FileName, Graph &map)
{
	ifstream IF(FileName);
	if (!IF.is_open())
	{
		cout << "error in opening file" << endl;
		exit(1);
	}//�ļ���ʱ����
	int i = 0;
	map.vexnum = 0;
	map.edgenum = 0;
	while (!IF.eof())
	{
		IF >> map.vertices[i].vexname >> map.vertices[i].intro >> map.vertices[i].x >> map.vertices[i].y;//���붥����Ϣ
		IF >> map.vertices[i].outdegree;//����ö���ĳ���
		int j = 0;
		while (j++<map.vertices[i].outdegree)
		{
			Edge* newEdge=(Edge*)malloc(sizeof(Edge));
			if (newEdge != NULL)//�ռ����ɹ�
			{
				IF >> newEdge->adjvex >> newEdge->distance;
				newEdge->nextEdge = map.vertices[i].firstedge;
				map.vertices[i].firstedge = newEdge;//ͷ�巨������
				map.edgenum++;
			}
		}
		i++;
	}
	IF.close();//�ر��ļ�
	map.vexnum = i;
	map.edgenum /= 2;
}

//��ͼ�����ݴ����ļ���
void DataOutFile(const char* FileName, Graph & map)
{
	ofstream OF(FileName);//Ĭ���Խض�ģʽ���ļ�����ԭ����
	if (!OF.is_open())
	{
		cout << "error in opening file" << endl;
		exit(1);
	}//�ļ���ʱ����
	int i = 0;
	while (i<map.vexnum)
	{
		OF << map.vertices[i].vexname << ' ' << map.vertices[i].intro << ' ' << map.vertices[i].x << ' ' << map.vertices[i].y;//д�붥����Ϣ
		OF <<' '<< map.vertices[i].outdegree;//д��ö���ĳ���
		int j = 0;
		Edge* newEdge = map.vertices[i].firstedge;
		while (j++ < map.vertices[i].outdegree)
		{
			OF << ' ' << newEdge->adjvex <<' '<< newEdge->distance;
			newEdge = newEdge->nextEdge;
		}//����д��͸õ�����ı�
		i++;
		if (i < map.vexnum) OF << endl;
	}
	OF.close();
}
