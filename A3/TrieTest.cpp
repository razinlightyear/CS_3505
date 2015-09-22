#include "Trie.h"
#include <string>
#include <iostream>

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
	std::string s4 = "cattt";
	Trie t1 = Trie();
	t1.addWord(s);
	t1.addWord(s2);
	t1.addWord(s3);
	t1.addWord(s4);
	std::cout << t1.isWord(s3) << std::endl;
	std::cout << t1.isWord("ca") << std::endl;
	std::cout << t1.isWord("do") << std::endl;
	std::cout << t1.isWord("dog") << std::endl;
}