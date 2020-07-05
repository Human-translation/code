#include "FileManage.h"
#include "SweepDisk.h"

void FileManage::ScannerDir(const std::string& Path)
{
	_File.clear();
	SearchDir(Path, _File);
	GetMd5ToFile();
	GetFileToMd5();
}

void FileManage::GetMd5ToFile()
{
	_Md5ToFile.clear();
	for (const auto& f : _File)
	{
		_md5.Reset();
		_Md5ToFile.insert(make_pair(_md5.GetFileMd5(f.c_str()), f));
	}
}

void FileManage::GetFileToMd5()
{
	_FileToMd5.clear();
	auto it = _Md5ToFile.begin();
	while (it != _Md5ToFile.end())
	{
		if (_Md5ToFile.count(it->first) > 1)
		{
			auto PairIt = _Md5ToFile.equal_range(it->first);
			auto CurIt = PairIt.first;
			while (CurIt != PairIt.second)
			{
				_FileToMd5.insert(make_pair(CurIt->second, CurIt->first));
				++CurIt;
			}
			it = PairIt.second;
		}
		else
		{
			_File.erase(it->second);
			it = _Md5ToFile.erase(it);
		}
	}
}

void FileManage::DeleteByName(const std::string& Name)
{
	if (_FileToMd5.count(Name) == 0)
	{
		std::cout << "无此文件" << std::endl;
		return;
	}

	std::string CurMD5 = _FileToMd5[Name];
	std::cout << Name << "---->" << _Md5ToFile.count(CurMD5) << std::endl;
	auto PairIt = _Md5ToFile.equal_range(CurMD5);
	auto CurIt = PairIt.first;
	int count = 0;
	while (CurIt != PairIt.second)
	{
		if (CurIt->second != Name)
		{
			_File.erase(CurIt->second);
			_FileToMd5.erase(CurIt->second);
			DeleteFile(CurIt->second.c_str());
			++count;
		}
		++CurIt;
	}
	CurIt = PairIt.first;
	while (CurIt != PairIt.second)
	{
		if (CurIt->second != Name)
		{
			_Md5ToFile.erase(CurIt);
			PairIt = _Md5ToFile.equal_range(CurMD5);
			CurIt = PairIt.first;
		}
		++CurIt;
	}
	std::cout << "delete files number :" << count << std::endl;
}

void FileManage::DeleteByMd5V1(const std::string& Md5)
{
	if (_Md5ToFile.count(Md5) <= 1)
	{
		std::cout << "无此文件或唯一文件" << std::endl;
		return ;
	}
	int count = 0;
	auto PairIt = _Md5ToFile.equal_range(Md5);
	auto CurIt = PairIt.first;
	++CurIt;
	while (CurIt != PairIt.second)
	{
		_File.erase(CurIt->second);
		_FileToMd5.erase(CurIt->second);
		DeleteFile(CurIt->second.c_str());
		++CurIt;
		++count;
	}
	CurIt = PairIt.first;
	++CurIt;
	_Md5ToFile.erase(CurIt, PairIt.second);
	std::cout << "delete files number :" << count << std::endl;
}

void FileManage::DeleteByMd5V2(const std::string& Md5)
{
	if (_Md5ToFile.count(Md5) == 0)
	{
		std::cout << Md5 << "not exist!" << std::endl;
		return;
	}
	auto it = _Md5ToFile.find(Md5);
	DeleteByName(it->second);
}

void FileManage::DeleteAllCopy()
{
	std::unordered_set<std::string> Md5Set;
	for (const auto& p : _Md5ToFile)
	{
		Md5Set.insert(p.first);
	}
	for (const auto& md5 : Md5Set)
	{
		DeleteByMd5V1(md5);
	}
}

void FileManage::DeleteByMatchName(const std::string& MatchName)
{
	std::unordered_set<std::string> AllFile;
	for (const auto& f : _File)
	{
		if (f.find(MatchName) != std::string::npos)
		{
			AllFile.insert(f);
		}
	}
	for (const auto& f : AllFile)
	{
		if (_FileToMd5.count(f) != 0)
		{
			DeleteByName(f);
		}
	}
}

void FileManage::ShowByMd5()
{
	int count = 0;
	int total = _Md5ToFile.size();
	auto it = _Md5ToFile.begin();
	while (it != _Md5ToFile.end())
	{
		int idx = 1;
		auto PairIt = _Md5ToFile.equal_range(it->first);
		auto CurIt = PairIt.first;
		std::cout << "Cur Md5:" << it->first << std::endl;
		while (CurIt != PairIt.second)
		{
			std::cout << "第" << idx << "个文件是：\t" << CurIt->second << std::endl;
			++CurIt;
			++idx;
			++count;
		}
		it = PairIt.second;
	}
	std::cout << "file count:" << total << "\\" << count << std::endl;
}

void FileManage::ShowAllFile()
{
	for (const auto& f : _File)
	{
		std::cout << f << std::endl;
	}
	std::cout << "file count:" << _File.size() << std::endl;
}