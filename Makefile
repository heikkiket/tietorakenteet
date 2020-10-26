queue:
	g++ teht2/queueMain.cpp teht2/Queue.cpp teht1/Node.cpp \
	-o bin

stack:
	g++ teht1/stackMain.cpp teht1/Stack.cpp teht1/Node.cpp \
	-o bin

run:
	./bin
