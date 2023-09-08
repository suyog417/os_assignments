
# OSSP Assignments

For all the lazy fellas 
## Note : All commands are for linux terminal only. 
### Assignment 1
Shell programming Write a program to implement an address book with options given below: a) Create address book. b) View address book. c) Insert a record. d) Delete a record. e) Modify a record. f) Exit.


### Usage

#### Change permission for the script. Make it executable.
```
chmod +x addressbook.sh
```
#### To run the code :
```
./addressbook.sh
```
### Assignment 2
The demonstration of FORK, EXECVE and WAIT system calls along with zombie and orphan states. Implement the C program in which main program accepts an integer array. Main program uses the FORK system call to create a new process called a child process.Parent process sorts an integer array and passes the sorted array to child process through the command line arguments of EXECVE system call. The child process uses EXECVE system call to load new program that uses.

#### Compile main file : 
```
gcc main.c
```
#### Compile second file : 
```
gcc -o child.out child.c
```
_-o is used to specify the name for ouput file_

#### To run the code : 
```
./a.out
```
