# Operating-System-LAB
4th semester OS LAB assignments

1qn) Write a program in C/C++ that will take a positive integer (N) as user input.
Now create two threads using pthread. First thread will print odd numbers between 1 and N and second thread will print even numbers between 1 and N.

2qn) Use fork() and clone() calls and try to show how they behave with simple program that creates and kills thread(s).

3qn) Write a program to show synchronization among threads using mutex and pthread_join.
Your code should have two sections, 1st section will show the output without using mutex and 2nd section will show the output after using mutex.
Use shared variable to show problems occured when multiple variable update same variable. Solve the problem using mutex.

4qn) Write an IPC program where Process-1 will generate a random number between 1 and 500 and will write to shared memory, Process-2 will read the data from shared memory and compute square of the number and write the result back to shared memory. Process-1 reads the result and prints it. Repeat for 5 numbers.

5qn) Rewrite last week's program to better control and display. Use ftok to set key. Show memory addresses and sizes.
Can you try writing the same sequence for any message passing scheme as another function?
