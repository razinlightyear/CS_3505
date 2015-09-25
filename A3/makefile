# use variables to define compilation properties
CC = g++
CFLAGS = -Wall -std=c++0x

TrieTest: TrieTest.o Trie.o Node.o
	$(CC) $(CFLAGS) -o TrieTest TrieTest.o Trie.o Node.o
	
TrieTest.o: TrieTest.cpp Trie.h
	$(CC) $(CFLAGS) -c TrieTest.cpp
	
Trie.o: Trie.cpp Node.h
	$(CC) $(CFLAGS) -c Trie.cpp			

Node.o: Node.cpp
	$(CC) $(CFLAGS) -c Node.cpp		
	
clean:
	rm -f TrieTest *.o
	