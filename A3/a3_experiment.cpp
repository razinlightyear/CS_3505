#include <iostream>
#include <string>
#include <vector>
#include <stddef.h>

#include <cstddef>

int main()
{
	std::string str = "Cora";
//	std::string *str_pointer = &str;
	std::cout << str << std::endl;
	std::cout << str[0] << std::endl;
	std::vector<char> v;
		for(int z =0; z<str.length(); z++)
		{
			//std::s tring s2 = str.substr(z,z);
			//std::cout << s2 << z << std::endl;
			v.push_back(str[z]);
		}
		for(int z =0; z<v.size(); z++)
		{
			std::cout << v[z];
		}
		std::cout << std::endl;
			//std::cout << v << std::endl;
	int index;
	if(!index)
	{
		index = 3;
		std::cout << index << std::endl;		
	}
	std::vector<std::string> wordList;
	wordList.push_back(str);
	for(int z =0; z<wordList.size(); z++)
	{
		std::cout << wordList[z] << std::endl;
	}
	str += '!';
	str += (char)97;
	std::cout << str << std::endl;
	//std::cout << str[index] << std::endl;
	
	/*
	int A(int* param1) {
						… }
	val = A(&mLocal);
	*/
}