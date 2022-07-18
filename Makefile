pastaignore:
	g++ pastaignore.cpp -o pastaignore -Wall -Wextra -std=c++20 -g3
	strip pastaignore
install: pastaignore
	install -m 0755 pastaignore /usr/local/bin
