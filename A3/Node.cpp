#include "Node.h"
#include <vector>
#include <cstddef>
	
	Node::Node()
	{
		alphabet = std::vector<Node*>(26, nullptr);
		completeWord = false;
	}
	
	/*bool Node::isPresent(char c)
	{
		if(alphabet[(int)c - 97])
		{
			return true;
		}
		return false;
	}*/
/*	
	void Node::setChar(char c)
	{
		alphabet[(int)c - 97] = true;
	}
*/	
	bool Node::isCompleteWord()
	{
		return completeWord;
	}
	
	bool Node::isCompleteWord(bool _isCompleteWord)
	{
		completeWord = _isCompleteWord;
		return completeWord;
	}
	
	std::vector<Node*> Node::getAlphabet()
	{
		return alphabet;
	}
	
	Node* Node::setAlphabetIndex(int index)
	{
		Node* child = new Node();
		alphabet[index] = child;
		return child;
	}
	/*
	Node* Node::getNode()
	{
		return &this;
	}*/