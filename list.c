#include<stdio.h>
#include<stdlib.h>

struct list
{
    int index;
    struct list* next;
    int elem;
};

void change_ind(struct list* arr, int index)
{
    if (arr)
    {
        arr->index = index++;
        change_ind(arr->next, index);
    }
}

struct list* del_elem(struct list* arr, int index)
{   
    if (!arr)
        return NULL;
    if (arr->index != index)
        arr->next = del_elem(arr->next, index);
    else
    {
        struct list *tmp = arr->next;
        change_ind(tmp, arr->index);
        free(arr);
        return tmp;
    }
    return arr;
}

struct list* add_elem(struct list* arr, int elem)
{
    static int index = 0;
    if (arr == NULL)
    {
        arr = (struct list*)malloc(sizeof(struct list));
        arr->index = index;
        arr->next = NULL;
        arr->elem = elem;
    }
    else
    {
        index = arr->index + 1;
        arr->next = add_elem(arr->next, elem);
    }
    return arr;
    
}

void print_list(struct list* arr)
{
    if (arr != NULL)
    {
        printf("%d - %d\n", arr->index, arr->elem);
        print_list(arr->next);
    }
}

void free_list(struct list* arr)
{
    if (arr){
        if(arr->next)
            free_list(arr->next);
        printf("Удалили index = %d\n", arr->index);
        free(arr);
    }
}


int main()
{   
    struct list *tmp = NULL;
    int elem;
    for (int i = 0; i < 4; i++)
    {
        scanf("%d", &elem);
        tmp = add_elem(tmp, elem);
    }
    print_list(tmp);
    tmp = del_elem(tmp, 0);
    tmp = add_elem(tmp, 65);
    tmp = add_elem(tmp, 65);
    tmp = add_elem(tmp, 65);
    print_list(tmp);
    free_list(tmp);
    
    
    return 0;
}
