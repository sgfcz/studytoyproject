#include "parseMain.h"

parseMain::parseMain() {}

parseMain::parseMain(std::string jsontext)
{
	_currentJson = jsontext;
}

parseMain::~parseMain() {}

void parseMain::setJsonText(std::string jsontext)
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

void parseMain::jugleJsonValueType(std::string value)
{

}

bool parseMain::jugleJsonPair()
{
	//TODO check value has {}[]
	for (int i = 0; i < _currentJson.size(); i++) {
		auto cf = _currentJson[i];
		if (cf == 123 || cf == 91) {
			_currentPairLeft[i] = cf;
		}
		else if (cf == 125 || cf == 93) {			//ascii 123-{,91-[,125-},93-]
			_currentPairRight[i] = cf;
		}
	}

	if (_currentPairLeft.size() != _currentPairRight.size())
		return false;

	return true;
}

std::multimap<int, TREEINDEX> parseMain::getLevelJsonData()
{
	int perLeft = 0, perRight = _currentJson.size() - 1;
	int rootLevel = 0;
	std::multimap<int, TREEINDEX> treeroot;
	auto leftc = _currentPairLeft.begin();
	auto rightc = _currentPairRight.end();


	for (; leftc != _currentPairLeft.end(); --leftc, --rightc) {
		int leftcindexBegin = leftc->first;
		int rightcindexBegin = rightc->first;


		TREEINDEX treeindex(leftc->first, rightc->first, leftc->second, rightc->second);
		treeroot.emplace(rootLevel, treeindex);
	}
}

bool parseMain::jugleKeyValuePair()
{
	getLevelJsonData();

	CURRENTSTATE state = JSONBEGIN;

	for (int i = 0; i < _currentJson.size(); i++) {
		auto cf = _currentJson[i];
		if (cf == 92 && state == JSONBEGIN) {		//ascii 92-\

		}
	}

	if (_currentPairLeft.size() != _currentPairRight.size())
		return false;

	return true;
}
