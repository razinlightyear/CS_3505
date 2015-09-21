class Node 
{
	//array of 26 nodes
	Node* children[26];
	bool completeWord;
public:	
	Node();
};

/*
struct node
{
	bool is_end;
	int prefix_count;
	struct node* child[ALPHABET_SIZE];
}*head;
*/