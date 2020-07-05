#pragma once
#include <unordered_set>
#include <unordered_map>
#include <string>
#include "MD5.h"

class FileManage
{
public:
	void ScannerDir(const std::string& Path);
	void GetMd5ToFile();
	void GetFileToMd5();
	void DeleteByName(const std::string& Name);
	void DeleteByMd5V1(const std::string& Md5);
	void DeleteByMd5V2(const std::string& Md5);
	void DeleteAllCopy();
	void DeleteByMatchName(const std::string& MatchName);

	void ShowByMd5();
	void ShowAllFile();

private:
	std::unordered_set<std::string> _File;
	std::unordered_multimap<std::string, std::string> _Md5ToFile;
	std::unordered_map<std::string, std::string> _FileToMd5;
	MD5 _md5;
};