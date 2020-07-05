#pragma once
#include "FileManage.h"
#include <iostream>

using std::endl;
using std::cout;
using std::cin;

class FileManTool
{
public:
	void Scanner();

	void DeleteByMd5();

	void DeleteByName();

	void DeleteAllCopy();

	void DeleteFuzzyMatchCopy();

	void ShowByMd5();

	void ShowAllFile();

private:
	FileManage _fm;
};