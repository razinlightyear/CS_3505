#include "Trie.h"
#include <string>
#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
	/*
	if(argc < 3)
	{
		std::string message = "ERROR: 2 filenames must be passed in: the first is the filename of dictionary words to add to the trie, the second is the filename of words to search the trie for.";
		std::cout << message << std::endl;
	}
	*/
	std::string s = "dog";
	std::string s2 = "dog";
	std::string s3 = "cat";
	std::string s4 = "cow";
	std::string s5 = "cattt";
	Trie t1 = Trie();
	t1.addWord(s);
	t1.addWord(s2);
	t1.addWord(s3);
	t1.addWord(s4);	
	t1.addWord(s5);
	std::cout << t1.isWord(s3) << std::endl;
	std::cout << t1.isWord("ca") << std::endl;
	std::cout << t1.isWord("do") << std::endl;
	std::cout << t1.isWord("dog") << std::endl;
	std::cout << t1.isWord(s4) << std::endl;
	std::vector<std::string> wl1 = t1.allWordsWithPrefix("");
	std::cout << wl1.size() << std::endl;
	for(int i=0; i<wl1.size(); i++)
	{
		std::cout << wl1[i] << ", ";
	}
	std::cout << std::endl;
	std::vector<std::string> wl2 = t1.allWordsWithPrefix("co");
	for(int i=0; i<wl2.size(); i++)
	{
		std::cout << wl2[i] << ", ";
	}
	std::cout << std::endl;
}