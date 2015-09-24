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
		std::cout << "root is " << root << std::endl;
		//std::vector<std::string> v;
		for(int charIndex = 0; charIndex < word.length(); charIndex++)
		{
			int nodeIndex = word[charIndex] - 97;
			if(current->getAlphabet()[nodeIndex] != nullptr)
			{
				//if(current->getAlphabet()[nodeIndex])
				//{
					Node* childNode = current->getAlphabet()[nodeIndex];
					current = childNode;
					//}
			}
			
			
			//root.setChar(word[charIndex]);
			else
			{
				std::cout << "current aplhabet index is null" << std::endl;		
				current = current->setAlphabetIndex(nodeIndex); // Creates a child node and returns it.
				//current = newNode;
				//if(nodeIndex == word.length()-1)
				//{
				//	current->isCompleteWord(true);				
				//}
				std::cout << "current should now be the new child" << std::endl;
			}
			std::cout << "current"<< current << std::endl;
		}
		current->isCompleteWord(true);
	}
	
	bool Trie::isWord(std::string word)
	{
		// isCompleteWord && Node at index == nullptr
		std::cout << "********************** begin isWord ************************" << std::endl;
		std::cout << word.length() << std::endl;
		//word == nullptr ||
		if(word.length() == 0)
		{
			return false;
		}
		Node* current = root;
		std::cout << "current is root" << std::endl;
		std::cout << "root is " << root << std::endl;
		//std::vector<std::string> v;
		for(int charIndex = 0; charIndex < word.length(); charIndex++)
		{
			int nodeIndex = word[charIndex] - 97;
			if(current->getAlphabet()[nodeIndex] != nullptr)
			{
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
			std::cout << "current"<< current << std::endl;
			std::cout << word[charIndex] << ": is word "<< current->isCompleteWord() << std::endl;
		}
//		int nodeIndex = word.back() - 97;
//		if(current->getAlphabet()[nodeIndex] != NULL && current->getAlphabet()[nodeIndex]->isCompleteWord())
		return current->isCompleteWord();
	}
	
	// find count of words in the trie which has the given word as prefix.
	std::vector<std::string> Trie::allWordsWithPrefix(std::string word)	
	{
		std::cout << "********************** begin allWprdsWithPrefix ************************" << std::endl;
		std::cout << word.length() << std::endl;
		//word == nullptr ||
		std::vector<std::string> wordList;
/*		
		if(word.length() == 0)
		{
			return wordList; // change
		}
		Node* current = root;
		std::cout << "current is root" << std::endl;
		std::cout << "root is word " << root->isCompleteWord() << std::endl;
		//std::vector<std::string> v;
		for(int charIndex = 0; charIndex < word.length() - 1; charIndex++)
		{
			int nodeIndex = word[charIndex] - 97;
			if(current->getAlphabet()[nodeIndex] != NULL)
			{
				std::cout << "current&"<< current << std::endl;
				//if(current->getAlphabet()[nodeIndex])
				//{
				Node* childNode = current->getAlphabet()[nodeIndex];
				current = childNode;
					//}
			}
			//root.setChar(word[charIndex]);
			else
			{
				return std::vector<std::string>();  // Change this
			}
		}
		int nodeIndex = word.back() - 97;
		if(current->getAlphabet()[nodeIndex] != NULL && current->getAlphabet()[nodeIndex]->isCompleteWord())
		{
			return std::vector<std::string>();  // Change this			return true;
		}
		
		return std::vector<std::string>();
		
		
		for(int i=0; i<word.size(); i++)
		{
			
			if(this.isWord(word))
			{
				wordList.push_back(word.substr(0,i));		
			}
		}
*/	
		Node* current = root;
		std::cout << "root is " << root << std::endl;
		//std::vector<std::string> v;
		int charIndex;
		for(charIndex = 0; charIndex < word.length(); charIndex++)
		{
			int nodeIndex = word[charIndex] - 97;
			if(current->getAlphabet()[nodeIndex] != nullptr)
			{
				//if(current->getAlphabet()[nodeIndex])
				//{
					Node* childNode = current->getAlphabet()[nodeIndex];
					current = childNode;
					//}
			}
			
			
			//root.setChar(word[charIndex]);
			else
			{
				return std::vector<std::string>();
				std::cout << "current should now be the new child" << std::endl;
			}
			std::cout << "current"<< current << std::endl;
		}
		word = word.substr(0, charIndex);
		std::cout << "Prefix: word " << word << std::endl;
		for(int i=0; i<26; i++)
		{
			if(current->getAlphabet()[i] != nullptr)
			{
				this->allWordsWithPrefixHelper(word, current->getAlphabet()[i], &wordList);
			}
		}
		return wordList;
	}
	
	void Trie::allWordsWithPrefixHelper(std::string word, Node* current, std::vector<std::string>* wordList)
	{
		std::cout << "PrefixHelper: word " << word << std::endl;
		for(int i=0; i<26; i++)
		{
			if(current->getAlphabet()[i] != nullptr)
			{
				std::cout << "current"<< current << std::endl;
				word += (char)(i + 97); 
				std::cout << " word << " << word << std::endl;
				if(current->getAlphabet()[i]->isCompleteWord())
				{
					wordList->push_back(word);
				}
				this->allWordsWithPrefixHelper(word, current->getAlphabet()[i], wordList);
			}
		}
	}
	
	void Trie::addWordHelper(std::string word)
	{
		
	}
	
	bool Trie::isWordHelper(std::string word)
	{
		return false;
	}
	
	/*
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
		std::cout << "root is word " << root->isCompleteWord() << std::endl;
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
		current->isCompleteWord(true);
	}
	*/