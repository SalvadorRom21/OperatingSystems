Salvador Romero


to run the program make sure to have the executables of sort.c and pre.c 
and the input.txt file in the same directory that youre executing the program
"shell" in. 

Enter the commands

shhh>ls 

shhh>ls -t -al

shhh>cat file.txt   (file.txt is an existing file)

shhh>ls -al > output.txt

And then open output.txt to see if the content is correct or not

shhh> ls | more | wc

shhh>./pre < input.txt | ./sort > output.txt

BUG ERROR:
IN the final command my output.txt file will have the wrong output and will be missing the first element TX. Was unable to figure out the root of this bug. 