#include <iostream>
using namespace std;

struct nodo{
    int info;
    nodo* next;
};

//copiata dal file del prof
void aggiungiInTesta(nodo* &list, int e) {

    nodo* new_node = new nodo;
    new_node->info = e;
    new_node->next = list;

    list = new_node;

}

// STAMPA
void print(nodo* list) {

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


bool isDescending(nodo* &l){

    bool discendente = true;

    if(l==NULL){
        cout << "La lista e' vuota";
    }
    else if(l->next == NULL) {
        // ha un solo elemento
    }
    else {


        while(l->next != NULL) {
            if(l->next->info < l->info) {
                l = l->next;
            } else {
                discendente = false;
                break;
            }
        }

    }

    return discendente;
}

int main() {

    nodo* l = NULL;



    aggiungiInTesta(l, 44);
    aggiungiInTesta(l, 45);
    aggiungiInTesta(l, 47);


    print(l) ;
    cout << endl;

    cout << "La lista " << ((isDescending(l) == true) ? "e' " : " non e'")  << " discendente";

    return 0;
}
