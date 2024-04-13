#include "parseMain.h"
#include "parseMain.h"
#include "parseMain.h"
#include "parseMain.h"
#include "parseMain.h"
#include "parseMain.h"
#include "parseMain.h"

parseMain::parseMain() 
{

}

parseMain::parseMain(string jsontext) 
{
	_currentJson = jsontext;
}

parseMain::~parseMain() 
{

}

void parseMain::setJsonText(string jsontext) 
{
	_currentJson = jsontext;
}

bool parseMain::parseJsonData() 
{
	bool jsonCheck;
	//first get all pair({,[,},])
	jsonCheck = jugleJsonPair();
	if (!jsonCheck) {
		return jsonCheck;
	}
	//second get all key and value

}

void parseMain::jugleJsonValueType(string value) 
{

}

bool parseMain::jugleJsonPair()
{
	for (int i = 0; i < _currentJson.size(); i++) {
		auto cf = _currentJson[i];
		if (cf == "{" || cf == "[") {
			_currentPairLeft[i] = cf;
		}
		else if (cf == "}" || _currentJson == "]") {
			_currentPairRight[i] = cf;
		}
	}

	if (_currentPairLeft.size != _currentPairRight)
		return false;

	return true;
}

std::multimap<int, TREEINDEX> parseMain::getLevelJsonData()
{
	int perLeft = 0, perRight = _currentJson.size() - 1;
	int rootLevel = 0;

	for (int i = 1; i < _currentPairLeft.size(); i++) {
		std::map<int, std::string>::const_iterator leftc = _currentPairLeft.begin() + i;
		int leftcindexBegin = leftc->first;

		std::map<int, std::string>::const_iterator rightc = _currentPairRight.end() - i - 1;
		int rightcindexBegin = rightc->first;


		TREEINDEX treeindex(leftc->first, rightc->first, leftc->second, rightc->second);
		_treeIndex[rootLevel] = treeindex;
	}
}

bool parseMain::jugleKeyValuePair()
{
	getLevelJsonData();

	CURRENTSTATE state = JSONBEGIN;

	for (int i = 0; i < _currentJson.size(); i++) {
		auto cf = _currentJson[i];
		if (cf == "\"" && state == JSONBEGIN) {

		}
	}

	if (_currentPairLeft.size != _currentPairRight)
		return false;

	return true;
}
