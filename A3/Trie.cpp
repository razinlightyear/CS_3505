#include "Trie.h"
#include <string>
#include <vector>
#include <stddef.h>
#include <iostream>


	Trie::Trie()
	{
		root = new Node();
	}
	
	
	// Copy constructor
	Trie::Trie(const Trie& other)
	{
		root = new Node;
		//std::cout << "root is " << root << std::endl;
		this->constructorHelper(other.root, this->root);
	}
	
	
	void Trie::constructorHelper(Node* otherNode, Node* newNode)
	{
		//std::cout << "newNode is coming in " << newNode << std::endl;
		for(int i=0; i<26; i++)
		{
			if(otherNode->getAlphabet()[i])
			{	
				newNode->isCompleteWord(otherNode->isCompleteWord());
				newNode->setAlphabetIndex(i);  // New Node is created				
				//std::cout << "Copying " << (char)(i + 97) << " to newNode " << newNode << std::endl;
				this->constructorHelper(otherNode->getAlphabet()[i], newNode->getAlphabet()[i]);
			}
		}

	}
	
	
	// Destructor
	Trie::~Trie()
	{
		//std::cout << "Destructor at root  " << root << std::endl;
		this->destructorHelper(root);
	}
	
	
	void Trie::destructorHelper(Node* subRoot)
	{
		for(int i=0; i<26; i++)
		{
			if(subRoot->getAlphabet()[i])
			{
				//std::cout << "Destroying " << subRoot << std::endl;
				this->destructorHelper(subRoot->getAlphabet()[i]);
			}
		}
		delete subRoot;
	}
	
	
	
	Trie& Trie::operator=(Trie other)
	{
		if(this == &other)
		{
			return *this;
		}
		std::swap(root,other.root);
		return *this;
	}
		
		
		
	void Trie::addWord(std::string word)
	{
		if(word.length() == 0)
		{
			return;
		}
		Node* current = root;
		//std::cout << "root is " << root << std::endl;
		for(int charIndex = 0; charIndex < word.length(); charIndex++)
		{
			int nodeIndex = word[charIndex] - 97;
			if(current->getAlphabet()[nodeIndex])
			{
				current = current->getAlphabet()[nodeIndex];
			}
			else
			{
				current = current->setAlphabetIndex(nodeIndex); // Creates a child node and returns it.
			}
			//std::cout << "current "<< current << std::endl;
		}
		current->isCompleteWord(true);
	}
	
	
	bool Trie::isWord(std::string word)
	{
		//std::cout << "********************** begin isWord ************************" << std::endl;
		if(word.length() == 0)
		{
			return false;
		}
		Node* current = root;
		//std::cout << "root is " << root << std::endl;
		for(int charIndex = 0; charIndex < word.length(); charIndex++)
		{
			int nodeIndex = word[charIndex] - 97;
			if(current->getAlphabet()[nodeIndex])
			{
				current = current->getAlphabet()[nodeIndex];
			}
			else
			{
				return false;
			}
			//std::cout << "current"<< current << std::endl;
			//std::cout << word[charIndex] << ": is word "<< current->isCompleteWord() << std::endl;
		}
		return current->isCompleteWord();
	}
	
	
	// find count of words in the trie which has the given word as prefix.
	std::vector<std::string> Trie::allWordsWithPrefix(std::string word)
	{
		//std::cout << "********************** begin allWprdsWithPrefix ************************" << std::endl;
		std::vector<std::string> wordList;
		Node* current = root;
		//std::cout << "root is " << root << std::endl;
		int charIndex;
		for(charIndex = 0; charIndex < word.length(); charIndex++)
		{
			int nodeIndex = word[charIndex] - 97;
			if(current->getAlphabet()[nodeIndex])
			{
					current = current->getAlphabet()[nodeIndex];
			}
			else
			{
				return std::vector<std::string>();
			}
			//std::cout << "current"<< current << std::endl;
		}
		//std::cout << "Prefix: word " << word << std::endl;
		this->allWordsWithPrefixHelper(word, current, &wordList);
		return wordList;
	}
	
	
	void Trie::allWordsWithPrefixHelper(std::string word, Node* current, std::vector<std::string>* wordList)
	{
		//std::cout << "PrefixHelper: word " << word << std::endl;
		for(int i=0; i<26; i++)
		{
			if(current->getAlphabet()[i])
			{
				//std::cout << "current"<< current << std::endl;
				word.push_back((char)(i + 97)); 
				//std::cout << " word << " << word << std::endl;
				if(current->getAlphabet()[i]->isCompleteWord())
				{
					wordList->push_back(word);
				}
				this->allWordsWithPrefixHelper(word, current->getAlphabet()[i], wordList);
				word.pop_back(); 
			}
		}
	}