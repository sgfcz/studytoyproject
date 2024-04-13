// jsonparse.cpp: 定义应用程序的入口点。
//

#include "parseMain.h"

using namespace std;

int main()
{
	parseMain* parsePtr = new parseMain();
	while (true)
	{
		string readjson;
		cout << "put json:" << endl;
		cin >> readjson;


	}

	parsePtr = nullptr;
	delete parsePtr;

	return 0;
}
