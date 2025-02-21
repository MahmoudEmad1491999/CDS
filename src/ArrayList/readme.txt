This Data Structure is used to store dynamically allocated objects in a list by pointer
for example 

int* x = malloc(sizeof(int));
char* y = malloc(sizeof(char));

ArrayList* arraylist = create_array_list();
arraylist.append(x);
arraylist.append(y);
