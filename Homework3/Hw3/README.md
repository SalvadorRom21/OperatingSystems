Salvador Romero

OS: Linux SalvadorR-HEARTLESS 4.17.0-kali1-amd64 #1 SMP Debian 4.17.8-1kali1 (2018-07-24) x86_64 GNU/Linux

GCC version: gcc (Debian 8.2.0-8) 8.2.0

	How to complie the code Hwpart1
	HwPart1.c is the program without the mutual exclusion.
	Command: gcc -pthread -o Hw3Part1 Hw3Part1.c -lm

	Make sure to include the -lm or the round fucntion in the program will not work.

	How to	compile the code Hwpart2
	HwPart2.c is the program with the mutual exlusion.
	Command: gcc -pthread -o Hw3part2 Hw3Part2.c -lm

Example output for HwPart1.c

	A Takes away $: 1000  
	B Takes away $: 750  
	C Takes away $: 563  
	B Takes away $: 422  
	A Takes away $: 422  
	C Takes away $: 211  
	A Takes away $: 158  
	B Takes away $: 119  
	C Takes away $: 89  
	B Takes away $: 67  
	A Takes away $: 67  
	C Takes away $: 33  
	B Takes away $: 25  
	A Takes away $: 19  
	C Takes away $: 14  
	B Takes away $: 11  
	C Takes away $: 8  
	A Takes away $: 6  
	B Takes away $: 4  
	C Takes away $: 4  
	A Takes away $: 3  
	C Takes away $: 3  
	B Takes away $: 3  
	A Takes away $: 3  
	B Takes away $: 2  
	C Takes away $: 2  
	A Takes away $: 2  
	C Takes away $: 1  
	B Takes away $: 1  
	A Takes away $: 1  
	C Takes away $: 1  
	B Takes away $: 1 

Notice that the 422 is shown twice near the start of the program. This means that thread B and Thread A had access to the same memory space at the same time. 

Example output for HwPart2.c
	
	A Takes away $: 1000  
	B Takes away $: 750  
	C Takes away $: 563  
	B Takes away $: 422  
	A Takes away $: 317  
	C Takes away $: 237  
	B Takes away $: 178  
	A Takes away $: 134  
	C Takes away $: 100  
	A Takes away $: 75  
	C Takes away $: 56  
	B Takes away $: 42  
	C Takes away $: 24  
	B Takes away $: 18  
	A Takes away $: 32  
	C Takes away $: 13  
	A Takes away $: 10  
	B Takes away $: 8  
	C Takes away $: 6  
	A Takes away $: 4  
	B Takes away $: 3  
	A Takes away $: 2  
	C Takes away $: 2  
	B Takes away $: 1  
	A Takes away $: 1  
	C Takes away $: 1  
	B Takes away $: 1

Notice that no numbers repeat up until it gets down to the lower numbers. Mutual exclusion is present making the shared global varialbe of 4000 lock everytime a thread reaches one section. 