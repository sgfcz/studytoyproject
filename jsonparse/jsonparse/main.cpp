// jsonparse.cpp: 定义应用程序的入口点。
//
#include "parseMain.h"
#include <memory>

using namespace std;

int main()
{
	std::shared_ptr<parseMain> parsePtr = std::make_shared<parseMain>();

	while (true)
	{
		string readjson;
		cout << "put json:" << endl;
		cin >> readjson;
	}

	return 0;
}
