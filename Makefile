main: main.o huffman_tree.o
	g++ -o $@ $^
main.o: main.cpp huffman_tree.h
	g++ -o $@ $<
huffman_tree.o: huffman_tree.cpp huffman_tree.h
	g++ -o $@ $<
