/*
* Andrew Emrazian CS3505 
*
* This class represents a letter to be represented in a Trie.
* It points to a potentional Node for each subsequent letter in
* the alphabet. It also stores whether this character completes a 
* word.
*/
#include<vector>

class Node 
{
private:	
	//array of 26 nodes
	std::vector<Node*> alphabet;
	bool completeWord;
public:	
	Node();
	
	bool isCompleteWord();
	
	bool isCompleteWord(bool _isCompleteWord);
	
	std::vector<Node*> getAlphabet();
	
	// Sets the current Nodes' reference to 
	//a child Node and returns the child.
	Node* setAlphabetIndex(int index);
};