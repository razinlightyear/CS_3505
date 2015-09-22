#include<vector>

class Node 
{
private:	
	//array of 26 nodes
	std::vector<Node*> alphabet;
	bool completeWord;
public:	
	Node();
	
	//Node(char c);
	
	bool isPresent(char c);
	
//	void setChar(char c);
	
	bool getCompleteWord();
	
	bool setCompleteWord(bool _completeWord);
	
	std::vector<Node*> getAlphabet();
	
	Node* setAlphabetIndex(int index);
	//Node* getNode();
};

/*
struct node
{
	bool is_end;
	int prefix_count;
	struct node* child[ALPHABET_SIZE];
}*head;
*/