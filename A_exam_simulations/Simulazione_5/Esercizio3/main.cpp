#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

node* firstEven(node* listabro) {

    if(listabro == NULL) {
        return NULL;
    } else {
        node* cursor = listabro;

        while(cursor != NULL) {
            if(cursor->data % 2 == 0) {
                return cursor;
            } else {
                cursor = cursor->next;
            }
        }
    }
}


// AGGIUNGI IN TESTA
void aggiungiInTesta(node* &list, int e) {

    node* new_node = new node;
    new_node->data = e;
    new_node->next = list;

    list = new_node;

}

// STAMPA
void print(node* list) {

    //	ITERATIVA
    if(list == NULL)
        cout << "Lista vuota" << endl;
    else {
        while(list != NULL) {
            cout << list->data << " ";
            list = list->next; //avanzo la lista
        }
    }
}

int main() {

    node* listone = NULL;

    aggiungiInTesta(listone, 17);
    aggiungiInTesta(listone, 7);
    aggiungiInTesta(listone, 8);



    if((firstEven(listone)) != NULL) {
        cout << (firstEven(listone))->data;
    }



    return 0;
}
