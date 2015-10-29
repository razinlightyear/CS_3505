#include "Trie.h"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>

std::vector<std::string> getWordsFromFile(std::string filename)
{
	//std::cout << "Get words from file." << std::endl;
	std::vector<std::string> wordList;
	std::string line;
	std::ifstream file(filename);
	if(file.is_open())
	{
		while(getline(file, line))
		{
			wordList.push_back(line);
			//std::cout << line << std::endl;
		}
		file.close();
	}
	return wordList;
}


int main(int argc, char *argv[])
{
	if(argc < 3)
	{
		std::string message = "ERROR: 2 filenames must be passed in: the first is the filename of dictionary words to add to the trie, the second is the filename of words to search the trie for.";
		std::cout << message << std::endl;
		return 1;
	}
	std::string dictionaryFile = argv[1];
	std::string queryFile = argv[2];
	//std::cout << "dictionaryFile " << dictionaryFile << " - queryFile " << queryFile << std::endl;
	std::vector<std::string> dictionary;
	std::vector<std::string> queries;	
	dictionary = getWordsFromFile(dictionaryFile);
	queries = getWordsFromFile(queryFile);
	if(dictionary.empty() || queries.empty())
	{
		std::cout << "ERROR: There was a problem reading the file or file was empty." << std::endl;
		return 1;
	}
	Trie t = Trie();
	for(int i=0; i<dictionary.size(); i++)
	{
		t.addWord(dictionary[i]);
	}
	for(int i=0; i<queries.size(); i++)
	{
		if(t.isWord(queries[i]))
		{
			std::cout << queries[i] << " is found" << std::endl;
		}
		else
		{
			std::cout << queries[i] << " is not found, did you mean:" << std::endl;
			std::vector<std::string> alternates = t.allWordsWithPrefix(queries[i]);
			for(int j=0; j<alternates.size(); j++)
			{
				std::cout << "   " << alternates[j] << std::endl;
			}
		}
	}	
	/*
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
	std::cout << "t1 isWord cow" << t1.isWord(s3) << std::endl;
	std::cout << "t1 isWord ca" << t1.isWord("ca") << std::endl;
	std::cout << "t1 isWord do" << t1.isWord("do") << std::endl;
	std::cout << "t1 isWord dog" << t1.isWord("dog") << std::endl;
	std::cout << "t1 isWord cattt" << t1.isWord(s4) << std::endl;
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
	
	Trie t3 = Trie(t1);
	std::cout << "t3 isWord cow" << t3.isWord(s3) << std::endl;
	std::cout << "t3 isWord ca" << t3.isWord("ca") << std::endl;
	std::cout << "t3 isWord do" << t3.isWord("do") << std::endl;
	std::cout << "t3 isWord dog" << t3.isWord("dog") << std::endl;
	std::cout << "t3 isWord cattt" << t3.isWord(s4) << std::endl;

	Trie t4 = t3;
*/
	return 0;
}