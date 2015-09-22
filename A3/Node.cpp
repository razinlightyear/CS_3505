#include "Node.h"
#include <vector>
	
	Node::Node()
	{
		alphabet = std::vector<Node*>(26);
		completeWord = false;
	}
	
	bool Node::isPresent(char c)
	{
		if(alphabet[(int)c - 97])
		{
			return true;
		}
		return false;
	}
/*	
	void Node::setChar(char c)
	{
		alphabet[(int)c - 97] = true;
	}
*/	
	bool Node::getCompleteWord()
	{
		return completeWord;
	}
	
	bool Node::setCompleteWord(bool _completeWord)
	{
		completeWord = _completeWord;
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