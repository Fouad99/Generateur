# Auteur : Mohamed Fouad Serradj
# Makefile pour generateur test de TP3

#OPTIONS = -g O0 -Wall
OPTIONS = -O2 -Wall

all : test

test : main.cpp
				g++ ${OPTIONS} -o test main.cpp

clean:
				rm -rf test
