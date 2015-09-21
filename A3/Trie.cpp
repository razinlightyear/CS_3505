#include "Trie.h"
#include <string>
#include <vector>
#include <stddef.h>

	Trie::Trie()
	{
	}
	
	// Copy constructor
	Trie::Trie(const Trie& other)
	{
	}
	
	// Destructor
	Trie::~Trie()
	{
	}
	
	Trie& Trie::operator=(Trie other)
	{
		return *this;
	}
	
	void Trie::addWord(std::string word)
	{
	}
	
	bool Trie::isWord(std::string word)
	{
		return false;
	}
	
	// find count of words in the trie which has the given word as prefix.
	std::vector<std::string> Trie::allWordsWithPrefix(std::string word)	
	{
		return std::vector<std::string>();
	}
	
	void Trie::addWordHelper(std::string word)
	{
		
	}
	
	bool Trie::isWordHelper(std::string word)
	{
		return false;
	}
	