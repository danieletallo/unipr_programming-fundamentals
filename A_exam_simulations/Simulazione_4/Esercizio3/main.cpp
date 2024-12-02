#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

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



void concat(node* &l1, node* l2) {

    node* cursor = new node;

    if(l1 == NULL) {
        l1 = l2;
    } else {
        cursor = l1;
        while(cursor->next != NULL) {
            cursor = cursor->next;
        }
        if(l2 != NULL) {
            cursor->next = l2;
        }
    }

}

int main() {

    node* l1 = NULL;

    // 1           12
    aggiungiInTesta(l1, 7);
    aggiungiInTesta(l1, 1);

    print(l1);

    cout << endl;

    node* l2 = NULL;

    // 5           9           12
    aggiungiInTesta(l2, 12);
    aggiungiInTesta(l2, 9);
    aggiungiInTesta(l2, 5);

    print(l2);


    cout << endl << "La nuova stringa e' " << endl;

    concat(l1, l2);

    print(l1);


    return 0;
}
