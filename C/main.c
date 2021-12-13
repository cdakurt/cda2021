#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef enum bool {
    false,
    true
}bool;

typedef struct list {
    float value;
    struct list * next;
}list;

int length_list = 0;

bool is_empty_list(list * li){
    if(li == NULL)
        return true;
    return false;
}

list * new_list(float value){
    list * li = (list *) malloc(sizeof * li);
    if(!is_empty_list(li)){
        li->value = value;
        length_list++;
        li->next = NULL;
    } else {
        fprintf(stderr, "Erreur lors de la construction d\'un nouvel element de liste.\n");
        exit(EXIT_FAILURE);
    }
    return li;
}

int get_length_list(list * li){
    if(is_empty_list(li))
      return 0;
    return length_list;
}

void print_list(list * li){
    if(!is_empty_list(li) && li->next != NULL){
        printf("[%.2f]\n", li->value);
        print_list(li->next);
    }
    if(li->value)
        printf("[%.2f]\n", li->value);
}

list * clean_list(list ** li_ptr){
    list * li = * li_ptr;
    list * tmp = li;
    if(!is_empty_list(li) && li->next != NULL){
        li->next = NULL;
        free(li);
        clean_list(&tmp->next);
    }
    return NULL;
}   

list * push_list(list * li, float value){
    list * node = new_list(value);
    if(!is_empty_list(li)){
        list * tmp = li;
        while(tmp != NULL)
            tmp = tmp->next;
        li->next = node;
        length_list++;
    }
    return li;
}


int main(){
    list *notes = new_list(11.5);
    int i = 0;
    for(; i < 10; i++){
        notes = push_list(notes, 91.56);
    }
    int len = get_length_list(notes);
    printf("taille de la liste %d.\n", len);
    print_list(notes);
    notes = clean_list(&notes);
}