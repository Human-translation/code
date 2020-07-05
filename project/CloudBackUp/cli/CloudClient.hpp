#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>
#include<unordered_map>
#include <boost/filesystem.hpp>
#include<boost/algorithm/string.hpp>  //splitͷ�ļ�
#include"httplib.h"

class FileUtil
{
public:
	static bool Read(const std::string &Name, std::string* Body) //��ȡ�ļ�����
	{
		std::ifstream fin(Name, std::ios::binary);
		if (!fin.is_open())
		{
			std::cout << "open file " << Name << " failed\n";
			return false;
		}
		int64_t fsize = boost::filesystem::file_size(Name);
		Body->resize(fsize);
		fin.read(&(*Body)[0], fsize);
		if (fin.good() == false)
		{
			std::cout << "file" << Name << "read data failed!\n";
			return false;
		}
		fin.close();
		return true;
	}

	static bool Write(const std::string &Name, const std::string &Body) //���ļ�д������
	{
		std::ofstream fout(Name, std::ios::binary);  //ofstremĬ�ϴ��ļ�ʱ�����ԭ������
		if (!fout.is_open())  //��ʧ��
		{
			std::cout << "FileTool::Write : open file " << Name << " failed!" << std::endl;
			return false;
		}
		fout.write(&Body[0], Body.size());
		if (!fout.good())
		{
			std::cout << "FileTool::Write : file " << Name << " write data failed!" << std::endl;
			return false;
		}
		fout.close();
		return true;
	}
};


class DataManager
{
public:
	DataManager(const std::string &FileName)
		:BackFile_(FileName)
	{

	}

	bool Insert(const std::string &Key, const std::string &Val)
	{
		FileList_[Key] = Val;
		Storage();
		return true;
	}

	bool GetEtag(const std::string &Key, std::string *Val)
	{
		auto it = FileList_.find(Key);
		if (it == FileList_.end())
		{
			return false;
		}
		*Val = it->second;
		return true;
	}

	bool Storage()
	{
		std::stringstream tmp;
		auto it = FileList_.begin();
		for (; it != FileList_.end(); ++it)
		{
			tmp << it->first << " " << it->second << "\r\n";
		}
		FileUtil::Write(BackFile_, tmp.str());  //�־û��洢д��ʱ����Ҫ�����ڽ���
		return true;
	}

	bool InitLoad()
	{
		std::string body;
		if (!FileUtil::Read(BackFile_, &body))
		{
			return false;
		}
		std::vector<std::string> list;
		boost::split(list, body, boost::is_any_of("\r\n"), boost::token_compress_off);
		for (auto i : list)
		{
			size_t pos = i.find(" ");
			if (pos == std::string::npos)
			{
				continue;
			}
			std::string key = i.substr(0, pos);
			std::string val = i.substr(pos + 1);

			Insert(key, val);
		}
		return true;
	}

private:
	std::string BackFile_;
	std::unordered_map<std::string, std::string> FileList_;
};



class CloudClient
{
public:
	CloudClient(const std::string &FileName,const std::string &ListenDir, const std::string& SvrIp, uint16_t SvrPort)
		:ListenDir_(FileName)
		,data_manage(ListenDir)
		,SvrIp_(SvrIp)
		,SvrPort_(SvrPort)
	{

	}

	bool Start()
	{
		data_manage.InitLoad();
		while (1)  //ѭ������
		{
			std::vector<std::string> list;
			GetBackUpFileList(&list);
			for (int i = 0; i < list.size(); i++)
			{
				std::string file_name = list[i];
				std::string file_path = ListenDir_ + file_name;

				std::cout << file_path << " is need to backup!" << std::endl;

				std::string body;  
				FileUtil::Read(file_path, &body);
				httplib::Client client(SvrIp_, SvrPort_);
				std::string  req_path = "/" + file_name;
				auto rsp = client.Put(req_path.c_str(), body, "application/octet-stream");
				if (rsp == NULL || rsp->status != 200)
				{
					std::cout << file_path << " backup failed!" << std::endl;
					continue;  
				}
				std::string etag;
				GetEtag(file_path, &etag);
				data_manage.Insert(file_name, etag); 

				std::cout << file_path << " backup success!" << std::endl;
			}
			Sleep(1000); 
		}
		return true;
	}

	bool GetBackUpFileList(std::vector<std::string> *List)
	{
		if (!boost::filesystem::exists(ListenDir_))
		{
			boost::filesystem::create_directory(ListenDir_);
		}

		boost::filesystem::directory_iterator begin(ListenDir_);
		boost::filesystem::directory_iterator end;

		for (; begin != end; begin++)
		{
			if (boost::filesystem::is_directory(begin->status()))  
			{
				continue;  
			}
			std::string file_path = begin->path().string(); 
			std::string file_name = begin->path().filename().string();  
			
			std::string cur_etag, old_etag;
			GetEtag(file_path, &cur_etag);  
			data_manage.GetEtag(file_name, &old_etag);  
			if (cur_etag != old_etag)
			{
				List->push_back(file_name);  
			}
		}
		return true;
	}

	bool GetEtag(const std::string &PathName, std::string *Etag)
	{
		int64_t fsize = boost::filesystem::file_size(PathName);
		time_t mtime = boost::filesystem::last_write_time(PathName);
		*Etag = std::to_string(fsize) + "-" + std::to_string(mtime);
		return true;
	}
private:
	std::string SvrIp_;
	uint16_t SvrPort_;
	std::string ListenDir_;
	DataManager data_manage;

};
