#include<iostream>
using namespace std;

int main()
{
	int ans;
	char Buffer[100];
	
	do
	{
		cout << "请输入数据" << endl;
		cin >> ans;

		cout << "输出其状态值" << cin.rdstate() << endl;
		if (cin.good())
		{
			cout << "输入数据类型正确，没有错误产生" << endl;
			return 0;
		}
		if (cin.fail())
		{
			cout << "发生非致命错误，清空缓冲区之后仍能使用" << endl;
			cin.clear();
			cin.getline(Buffer, 100);
		}
	} while (true);

	return 0;
}
