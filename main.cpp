#include"DataStructure.h"

using namespace std;


int main()
{
	Graph map;

	DataInFile("FileData.txt", map);
	Print(map);
	DataOutFile("FileData.txt", map);
	return 0;
}