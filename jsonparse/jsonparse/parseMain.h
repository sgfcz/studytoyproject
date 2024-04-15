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
	//表示json对象的值，可以作为json中arr的表示
	std::string data;
};

struct JSONDATA
{
	//json中value的数据
	std::any data;
	//json的类型
	JSONTYPE type;
	//json处于的层级
	int level;
};

struct TREEINDEX
{
	//左字符得索引
	int _leftindex;
	//右字符得索引
	int _rightindex;
	//左字符是什么
	std::string _leftc;
	//右字符是什么
	std::string _rightc;

	TREEINDEX(int leftindex, int rightindex, std::string leftc, std::string rightc) :
		_leftindex(leftindex), _rightindex(rightindex), _leftc(leftc), _rightc(rightc) {}

	TREEINDEX() {};
};

class parseMain
{
public:
	parseMain();
	parseMain(std::string jsontext);
	~parseMain();

	//设置json
	void setJsonText(std::string jsontext);

private:
	//开始分析json得入口
	bool parseJsonData();		
	//分析value是什么类型
	void jugleJsonValueType(std::string value);				
	//对json字符进行配对,并附带检查json得功能
	bool jugleJsonPair();		
	//根据pair符号，取得所有层级得数据
	std::multimap<int, TREEINDEX> getLevelJsonData();		
	//检查key和value中的""是否合理
	bool jugleKeyValuePair();								

private:
	//当前得json字符
	std::string _currentJson = "";
	//当前得json分层
	std::map<std::string, JSONDATA> _currentJsonData{};
	//左边符号，第几个和是什么字符
	std::map<int, std::string> _currentPairLeft;	
	//右边符号
	std::map<int, std::string> _currentPairRight;		

	//当前正在解析得key
	std::string _currentKey = "";
	//当前正在解析得value
	std::string _currentValue = "";

	//当前json解析到那一步了
	CURRENTSTATE _currentState = CURRENTSTATE::PROGRAMBEGIN;
};