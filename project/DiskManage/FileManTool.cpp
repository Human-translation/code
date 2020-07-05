#include "FileManTool.h"

void FileManTool::Scanner()
{
	cout << "������Ҫɨ����ļ���:" << endl;
	std::string path;
	getline(cin, path);
	_fm.ScannerDir(path);
}

void FileManTool::DeleteByMd5()
{
	cout << "������Ҫɾ�����ļ�Md5ֵ:" << endl;
	std::string md5;
	cin >> md5;
	_fm.DeleteByMd5V1(md5);
}

void FileManTool::DeleteByName()
{
	cout << "������Ҫɾ�����ļ���:" << endl;
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
	cout << "������ƥ���ļ���:" << endl;
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