//Pipes_exercise_3_7_4_saisurya.padala.c
//saisurya.padala
//Ordinary Pipes
//3.21 ordinary pipes unix
//fork() and pipe()
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>
  
int main()
{
    // 1st pipe to send input data string from derived
    // 2nd pipe to send concatenated string from derived
    int ar1[2];  // Used to store 2 ends of 1st the pipes
    int ar2[2];  // Used to store 2 ends of 2nd pipes
  
    char fixed_str[] = "Ordinary Pipes";
    char input_str[100];
    pid_t p;
  
   //create the pipe
    if (pipe(ar1)==-1)
    {
        fprintf(stderr, "Pipe Failed" );
        return 1;
    }
    if (pipe(ar2)==-1)
    {
        fprintf(stderr, "Pipe Failed" );
        return 1;
    }
  
    scanf("%s", input_str);
    p = fork();
    //error occrred
    if (p < 0)
    {
        fprintf(stderr, "fork Failed" );
        return 1;
    }
  
    // derived process
    else if (p > 0)
    {
        char concat_str[100];
  
       // Close reading end of 1st pipe
       // close(fd[READ_end]);
       close(ar1[0]);  
       //write to the pipe
       write(ar1[WRITE_END],fixed_str,strlen(fixed_str)+1);
        // Write input string and close writing end of 1st
        // pipe.
        write(ar1[1], input_str, strlen(input_str)+1);
        close(ar1[1]);
  
        // Wait for derived to send a string
        wait(NULL);
  
        // Close writing end of 2nd pipe
        close(ar2[1]);
        // Read string from derived, print it and close
        // reading end.
        read(ar2[0], concat_str, 100);
        printf("Concatenated string %s\n", concat_str);
        //close the write end of the pipe
        close(ar2[0]);
    }
  
    // derived process
    else
    {
        // Close writing end of 1st pipe
        close(ar1[1]);  
        // Read a string using 1st pipe
        char concat_str[100];
        read(ar1[0], concat_str, 100);
  
        // Concatenate a fixed string with it
        int k = strlen(concat_str);
        int i;
        for (i=0; i<strlen(fixed_str); i++)
            concat_str[k++] = fixed_str[i];
  
        concat_str[k] = '\0';   // string ends with '\0'
  
        // Close both reading ends
        close(ar1[0]);
        close(ar2[0]);
  
        // Write concatenated string and close writing end
        write(ar2[1], concat_str, strlen(concat_str)+1);
        close(ar2[1]);
  
        exit(0);
    }
}



