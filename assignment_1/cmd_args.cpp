#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	if(argc <= 1)
	{
		cout << "Filename: " << argv[0] << endl;
	}
	else
	{
		cout << "ECHO" << endl;
		for(int i = 1; i < argc; i++)
		{
			string str;
			for(int j = 0; j < i; j++)
			{
				str = str + argv[i] + " ";
			}
			cout << str << endl;
		}
	}
		return 0;
}
