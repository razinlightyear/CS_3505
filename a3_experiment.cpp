#include <iostream>
#include <string>
#include <vector>
#include <stddef.h>

#include <cstddef>

double doubleIt( double value ) {
    return value * 2.0;
}

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
	
	
	
    std::vector<int> values(3);
      values[0] = 5;
      values.push_back(10); 
      // here!
  	for(int z =0; z<values.size(); z++)
  	{
  		std::cout << values[z] << std::endl;
  	}
	double inputNumber = 1.0;
	    for (int counter = 0; counter < 10; counter++)
	    {
	        double result = doubleIt( inputNumber );
	        std::cout << inputNumber << " doubles to " << result << std::endl;
	        inputNumber += 0.5;
	    }
	int a = 10;
	int b = 30;
	std::swap(a, b);
	std::cout << "a " << a << " b " << b << std::endl;
		
      return 0;
}