pastaignore:
	g++ pastaignore.cpp -o pastaignore -Wall -Wextra -std=c++20 -O2
	strip pastaignore
install: pastaignore
	install -m 0755 pastaignore /usr/local/bin
