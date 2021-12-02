//DataStructuresProject-exercise_3_1_saisurya.padala.c
//Saisurya.padala
//we can use it like enum
//project 4 data structures
struct color{
    int red;
    int blue;
    int green;
    struct list_head list;
}
//In linked list non primitive datatype is dynamically allocated
//it's like sequence of the data structure connected through the likes
//it is the collection of objects

static LIST_HEAD(color_list);

//initialize instances of structure
struct color *violet;
violet=kamlloc(sizeof(*violet),GFP_KERNEL);
violet -> red=100;
violet ->blue =30;
violet ->green=160;
INIT_LIST_HEAD(&violet -> list);

//extracting of color_list should be like below
List_for_each_entry(item,&color_list,list){
//the item is iteration points
}

