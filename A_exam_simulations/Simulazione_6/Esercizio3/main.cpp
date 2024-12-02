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



bool equals(node* l1, node* l2) {

    int lunghezza_1 = 0, lunghezza_2 = 0;

    if(l1==NULL && l2==NULL) {
        return true;
    } else if(l1==NULL || l2==NULL) {
        return false;
    } else {
        //due cursori per verificare le lunghezze
        //primo
        node* cursor_1 = l1;

        while(cursor_1 != NULL) {
            lunghezza_1++;
            cursor_1 = cursor_1->next;
        }

        //secondo
        node* cursor_2 = l2;

        while(cursor_2 != NULL) {
            lunghezza_2++;
            cursor_2 = cursor_2->next;
        }

        if(lunghezza_1 != lunghezza_2) {
            return false;
        } else {
            //sono lunghe uguali, finalmente confronto i loro dati
            while (l1 != NULL) {
                if(l1->data != l2->data) {
                    return false;
                } else {
                    l1 = l1->next;
                    l2 = l2->next;
                }
            }
            // se arrivo qui allora sono uguali
            return true;
        }

    }

}


int main() {

    node* l1 = NULL;

    // 17   22   42   7

    aggiungiInTesta(l1, 7);
    aggiungiInTesta(l1, 42);
    aggiungiInTesta(l1, 22);
    aggiungiInTesta(l1, 17);

    node* l2 = NULL;

    aggiungiInTesta(l2, 7);
    aggiungiInTesta(l2, 42);
    aggiungiInTesta(l2, 22);
    aggiungiInTesta(l2, 17);
    //ggiungiInTesta(l2, 17);

    cout << "True or False: " << equals(l1, l2);

    return 0;
}
