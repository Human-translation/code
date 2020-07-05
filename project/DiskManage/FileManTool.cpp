#include "FileManTool.h"

void FileManTool::Scanner()
{
	cout << "请输入要扫描的文件夹:" << endl;
	std::string path;
	getline(cin, path);
	_fm.ScannerDir(path);
}

void FileManTool::DeleteByMd5()
{
	cout << "请输入要删除的文件Md5值:" << endl;
	std::string md5;
	cin >> md5;
	_fm.DeleteByMd5V1(md5);
}

void FileManTool::DeleteByName()
{
	cout << "请输入要删除的文件名:" << endl;
	std::string filename;
	getline(cin, filename);
	_fm.DeleteByName(filename);
}

void FileManTool::DeleteAllCopy()
{
	_fm.DeleteAllCopy();
}

void FileManTool::DeleteFuzzyMatchCopy()
{
	cout << "请输入匹配文件名:" << endl;
	std::string match;
	getline(cin, match);
	_fm.DeleteByMatchName(match);
}

void FileManTool::ShowByMd5()
{
	_fm.ShowByMd5();
}

void FileManTool::ShowAllFile()
{
	_fm.ShowAllFile();
}