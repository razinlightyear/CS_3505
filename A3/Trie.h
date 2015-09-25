/*
* Andrew Emrazian CS3505 
*
* This class represents a tree that is designed to store words
* so that they can be accessed very fast. It uses Nodes to store 
* data and reference to the letters to each other.
*/
#include "Node.h"
#include <string>
#include <vector>
class Trie 
{	

private:
	// private data members
    Node* root;
	
public:
	Trie();
	
	// Copy constructor
	Trie(const Trie& other);
	
	// Destructor
	~Trie();
	
	Trie& operator=(Trie other);
	
	void addWord(std::string word);
	
	bool isWord(std::string word);
	
	// find count of words in the trie which has the given word as prefix.
	std::vector<std::string> allWordsWithPrefix(std::string word);

private:
	
	void allWordsWithPrefixHelper(std::string word, Node* current, std::vector<std::string>* wordList);
		
	void destructorHelper(Node* newRoot);
	
	void constructorHelper(Node* otherNode, Node* newNode);
};