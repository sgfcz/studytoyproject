#pragma once

#include <iostream>
#include <map>
#include <vector>
#include <variant>
#include <any>

enum JSONTYPE
{
	INT,
	FLOAT,
	DICT,
	BOOL,
	STRING,
	JSONOBJECT,
	NULLPTR
};

enum CURRENTSTATE
{
	PROGRAMBEGIN,
	PROGRAMEND,
	KEYBEGIN,
	KEYEND,
	VALUEBEGIN,
	VALUEEND,
	JSONBEGIN,
	JSONEND
};

struct JSONOBJECT
{
	string data;
};

struct JSONDATA
{
	any data;
	JSONTYPE type;
	int level;
};

struct TREEINDEX
{
	int _leftindex;
	int _rightindex;
	std::string _leftc;
	std::string _rightc;

	TREEINDEX(int leftindex, int rightindex, std::string leftc, std::string rightc) :
		_leftindex(leftindex), _rightindex(rightindex), _leftc(leftc), _rightc(rightc) {}

	TREEINDEX();
};

class parseMain
{
public:
	parseMain();
	parseMain(string jsontext);
	~parseMain();

	void setJsonText(string jsontext);

private:
	bool parseJsonData();								//开始分析json得入口
	void jugleJsonValueType(string value);				//分析value是什么类型
	bool jugleJsonPair();								//对json字符进行配对,并附带检查json得功能
	std::multimap<int, TREEINDEX> getLevelJsonData();	//根据pair符号，取得所有层级得数据
	bool jugleKeyValuePair();							//检查key和value中的""是否合理

private:
	std::string _currentJson = "";
	std::map<string, JSONDATA> _currentJsonData{};
	std::map<int, std::string> _currentPairLeft;		//左边符号，第几个和是什么字符
	std::map<int, std::string> _currentPairRight;		//右边符号

	std::string _currentKey = "";
	std::string _currentValue = "";

	CURRENTSTATE _currentState = PROGRAMBEGIN;
};