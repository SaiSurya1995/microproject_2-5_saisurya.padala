//AnonymousPipes_exercise_3_22_saisurya.padala.c
//saisurya.padala
//3.22 Anonymous Pipes 
//Anonymous pipes will provide communication between the process
//base creates device to pass pipe handle to derived
//derived uses handle to connect to the base pipe
#include
#include

#define BUFFER_SIZE 26

int main(void){
    HANDLE Readhandle;
    CHAR buffer[BUFFER_SIZE];
    DWORD read;
    //to get standed read handle of the pipe
    Readhandle = GetStdHandle(STD_INPUT_HANDLE);
    //derived reads from the pipes
    if(ReadFile(Readhandle,buffer,BUFFER_SIZE,&read,NULL)){
        printf("derived read %s ",buffer);
    }
    else{
        printf(stderr,"error read from pipes");
    }
    return 0;
}
