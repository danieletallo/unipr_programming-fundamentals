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





int sum(node* list, int m) {

    int somma = 0;

    if(list != NULL){

        while(list->next != NULL) {
            if(list->data % m == 0) {
                somma += list->data;
            }
            list = list->next;
        }

        //considero l'ultimo
        if(list->data % m == 0) {
            somma += list->data;
        }
    }

    return somma;
}





int main() {

    node* list = NULL;

    aggiungiInTesta(list, 12);
    aggiungiInTesta(list, 1);
    aggiungiInTesta(list, 9);

    print(list);
    cout << endl << "Somma: " << sum(list, 3) << endl;

    print(list);


    return 0;
}
