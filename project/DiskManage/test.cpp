#include "FileManTool.h"
using std::cout;
using std::endl;

void menu()
{
	cout << "*********************************************" << endl;
	cout << "1:scanner        2:show all      3:show copy" << endl;
	cout << "4:delete name    5:delete md5    6:delete all" << endl;
	cout << "7:delete match   0:exit" << endl;
	cout << "*********************************************" << endl;
}

void testFileManagerTool()
{
	FileManTool fmt;
	int input;
	do
	{
		menu();
		std::string garbage;
		cout << "ÇëÊäÈëÑ¡Ïî:" << endl;
		cin >> input;
		getline(cin, garbage);
		switch (input)
		{
		case 1:
			fmt.Scanner();
			break;
		case 2:
			fmt.ShowAllFile();
			break;
		case 3:
			fmt.ShowByMd5();
			break;
		case 4:
			fmt.DeleteByName();
			break;
		case 5:
			fmt.DeleteByMd5();
			break;
		case 6:
			fmt.DeleteAllCopy();
			break;
		case 7:
			fmt.DeleteFuzzyMatchCopy();
			break;
		case 0:
		default:
			break;
		}
	} while (input != 0);
}

int main()
{
	testFileManagerTool();
	return 0;
}