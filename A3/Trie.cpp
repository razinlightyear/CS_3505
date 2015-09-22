#include "Trie.h"
#include <string>
#include <vector>
#include <stddef.h>
#include <iostream>
//#include <cstddef>


	Trie::Trie()
	{
		root = new Node();
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
		std::cout << word.length() << std::endl;
		//word == nullptr ||
		if(word.length() == 0)
		{
			return;
		}
		Node* current = root;
		std::cout << "current is root" << std::endl;
		std::cout << "root is word " << root->getCompleteWord() << std::endl;
		//std::vector<std::string> v;
		for(int charIndex = 0; charIndex < word.length(); charIndex++)
		{
			int nodeIndex = word[charIndex] - 97;
			if(current->getAlphabet()[nodeIndex] != NULL)
			{
				std::cout << "current&"<< &current << std::endl;
				//if(current->getAlphabet()[nodeIndex])
				//{
					Node* childNode = current->getAlphabet()[nodeIndex];
					current = childNode;
					//}
			}
			
			
			//root.setChar(word[charIndex]);
			else
			{
				std::cout << "current aplhabet is null" << std::endl;		
				current = current->setAlphabetIndex(nodeIndex);
				//current = newNode;
				std::cout << "current should now be the new child" << std::endl;
				std::cout << "&current"<< &current << std::endl;
			}
		}
		current->setCompleteWord(true);
	}
	
	bool Trie::isWord(std::string word)
	{
		std::cout << "********************** begin isWord ************************" << std::endl;
		std::cout << word.length() << std::endl;
		//word == nullptr ||
		if(word.length() == 0)
		{
			return false;
		}
		Node* current = root;
		std::cout << "current is root" << std::endl;
		std::cout << "root is word " << root->getCompleteWord() << std::endl;
		//std::vector<std::string> v;
		for(int charIndex = 0; charIndex < word.length() - 1; charIndex++)
		{
			int nodeIndex = word[charIndex] - 97;
			if(current->getAlphabet()[nodeIndex] != NULL)
			{
				std::cout << "current&"<< &current << std::endl;
				//if(current->getAlphabet()[nodeIndex])
				//{
					Node* childNode = current->getAlphabet()[nodeIndex];
					current = childNode;
					//}
			}
			//root.setChar(word[charIndex]);
			else
			{
				return false;
			}
		}
		int nodeIndex = word.back() - 97;
		if(current->getAlphabet()[nodeIndex] != NULL && current->getAlphabet()[nodeIndex]->getCompleteWord())
		{
			return true;
		}
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
	