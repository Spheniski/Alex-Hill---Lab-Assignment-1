# Alex-Hill---Lab-Assignment-1
Lab assignment 1 for Operating Systems

## About
This program is supposed to showcase shared memory and synchronization between 2 programs by printing when an item is produced and consumed, as well as how many are on the table. 

##Getting Started
No prior set up is necessary, just download or copy the files and compile them with this code in terminal:  
  `$ gcc producer.c -pthread -lrt -o producer`
  
  `$ gcc consumer.c -pthread -lrt -o consumer`
  
  `$ ./producer & ./consumer &`

Afterwards, just run the program and it should produce messages saying when the program produces items and consumes them, then exits after all items have been consumed!
