#include <iostream>
using namespace std;

struct node{
    char info;
    node* next;
};

void concat(node* &l1, node* &l2) {
    //node* cursor = new node;
    node* cursor = l1;

    if(l1==NULL && l2!=NULL){
        delete l1;
        l1 = l2;
    }
    else {
        while (cursor->next != NULL) {
            cursor = cursor->next;
        }
        cursor->next = l2;
    }

}

void print(node* list) {

    //	ITERATIVA
    if(list == NULL)
        cout << "Lista vuota" << endl;
    else {
        while(list != NULL) {
            cout << list->info << " ";
            list = list->next; //avanzo la lista
        }
    }
}

int main() {

    node* l1 = NULL;
    node* l2 = NULL;

  //LISTA1
    node* nodo1_l1 = new node;
    nodo1_l1->info = 'd';
    nodo1_l1->next = l1;

    l1 = nodo1_l1;

    node* nodo2_l1 = new node;
    nodo2_l1->info = 'a';
    nodo2_l1->next = l1;

    l1 = nodo2_l1;


    //LISTA2
    node* nodo1_l2 = new node;
    nodo1_l2->info = 'l';
    nodo1_l2->next = l2;

    l2 = nodo1_l2;

    node* nodo2_l2 = new node;
    nodo2_l2->info = 'f';
    nodo2_l2->next = l2;

    l2 = nodo2_l2;

    node* nodo3_l2 = new node;
    nodo3_l2->info = 'g';
    nodo3_l2->next = l2;

    l2 = nodo3_l2;

    concat(l1, l2);

    print(l1);

    return 0;
}
