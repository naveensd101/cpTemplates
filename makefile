all:
	g++ -static -DONLINE_JUDGE -Wl,--stack=268435456 -O2 -std=c++17 soln.cpp
fast:
	g++ soln.cpp -std=c++17 -Wshadow -Wall -O2 -Wno-unused-result -I .
slow:
	g++ soln.cpp -std=c++17 -Wshadow -Wall -g -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -I .
r:
	./a.out < in.txt
clean:
	rm a.out makefile in.txt
