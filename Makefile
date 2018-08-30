dict1: main.c dict1.c list.c athlete.c util.c
	gcc -o dict1 main.c dict1.c list.c athlete.c util.c -D STAGE1
	cp dict1 /usr/local/bin

dict2: main.c dict2.c list.c athlete.c util.c
	gcc -o dict2 main.c dict2.c list.c athlete.c util.c 
	cp dict2 /usr/local/bin
