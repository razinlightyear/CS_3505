/*
* Andrew Emrazian CS3505 -  prototyping
*
*/
// include gaurds?
#include "Node.h"
#include <string>
#include <vector>
class Trie 
{	

private:
	// private data members
    Node* root;
	
public:
	// Initializer list, uses copy constructor
	//Point(int x, int y) : x(x), y(y) { }
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
	void addWordHelper(std::string word);
	
	bool isWordHelper(std::string word);
	
};