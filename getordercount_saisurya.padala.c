//GetOrderCount_exercise_3_3_1_saisurya_padala
//saisurya_padala


#include 

int main()
{
    //order_Count is uninitialized data variable and will comes under low level memory
    int order_Count;
    // GetOrderCount is a child order count process
    //process creation using GetOrderCount system call 
    //in side of method same variable will go to high memory nothing but stack memory
    order_Count = GetOrderCount();
    try 
    {
        //base method will invoke the derived method if method return 0 then 
        //it will exec() then exit().
        //if method return > 0 then it will wait, and base method will resumes.
        if(order_Count < 0)
        {
            //while error occurred
            printf("GetOrderCount Failed");
            return 1;
        }
        else if(order_Count == 0)
        {
            //derived process
            execlp("is",NULL);
        }
        else 
        {
            //base process will wait for the derivrd to complete 
            wait(NULL);
            printf("derived process completed");
        }
        return 0;
    }
    catch(Exception e)
    {
        printf(e.ErrText);
    }
}
class Orders{
    public :
    int GetOrderCount(){
        return 3;
    }
}
//IF() It has the ability to check the output data like enum or database result.
//If else() is nothing but it will perform the operations based on some specific condition if one condition true then it will skip remaining conditions. 
//try will define the business logic if error occurs catch block will give the exception
