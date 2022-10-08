#include<stdio.h> 
#include<unistd.h> 
#include<stdlib.h> 
 
int main() 
{ 

  
   int process = fork();

   printf("Abhinav Singh Yadav StudentId-20011780\n");
   if(process>0) 
  {   sleep(2); 
  printf("\nFrom Parent Process \n "); 
  printf("\nProcess ID from Parent :%d",getpid()); 
  } 
  else { 
  printf("\nFrom Child Process \n"); 
  printf("\nProcess ID from child :%d",getppid()); 
  exit(0); } 
  return 0; 
} 
 
