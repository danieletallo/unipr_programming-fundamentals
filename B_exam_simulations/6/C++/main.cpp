#include <iostream>
using namespace std;

template <typename T>
class Queue {

private:
    int dim;
    int capacity;
    T* coda;

    void augment(const int quantity_toadd) {
        this->capacity += quantity_toadd;
        T* temp = this->coda;
        this->coda = new T[this->capacity];

        for(int i=0; i<this->dim; i++) {
            this->coda[i] = temp[i];
        }
        delete[] temp;
    }

public:
    Queue<T>() {
        this->dim = 0;
        this->capacity = 10;
        coda = new T[this->capacity];
    }

    // Costruttore di Copia
    Queue<T>(const Queue<T>& other) {
        this->dim = other.dim;
        this->capacity = other.capacity;
        this->coda = new T[this->capacity];

        for(int i=0; i<other.dim; i++) {
            this->coda[i] = other.coda[i];
        }
    }

    // Operatore di Assegnamento
    const Queue<T>& operator=(const Queue<T>& other) {
        if(this != &other) {
            this->dim = other.dim;
            this->capacity = other.capacity;

            delete[] this->coda;
            this->coda = new T[this->capacity];
            for(int i=0; i<this->dim; i++) {
                this->coda[i] = other.coda[i];
            }
        }
        return *this;
    }

    // Distruttore
    ~Queue<T>() {
        delete[] this->coda;
    }

    void enqueue(const T elem) {
        if(this->dim == this->capacity)
            this->augment(10);
        this->coda[this->dim] = elem;
        this->dim++;
    }

    int isEmpty() const {
        return this->dim == 0;
    }

    T dequeue() {
        if(this->isEmpty())
            throw new runtime_error("La coda e' vuota!");

        T to_return = this->coda[0];
        for(int i=0; i<this->dim-1; i++) {
            this->coda[i] = this->coda[i+1];
        }
        this->dim--;

        return to_return;
    }

    int getDim() const {
        return this->dim;
    }

    T getElementById(const int index) const {
        return this->coda[index];
    }



};

template <typename T>
ostream& operator<<(ostream& fout, const Queue<T>& coda) {
    for(int i=0; i<coda.getDim(); i++) {
        fout << coda.getElementById(i) << " ";
    }
    return fout;
}

int main() {
    Queue<int> queue;

    // Aggiungiamo alcuni elementi alla coda
    queue.enqueue(5);
    queue.enqueue(10);
    queue.enqueue(15);

    // Stampa la dimensione della coda
    cout << "Dimensione della coda: " << queue.getDim() << endl;

    // Stampa la coda
    cout << "Contenuto della coda: " << queue << endl;

    // Rimuoviamo un elemento dalla coda
    int dequeuedElement = queue.dequeue();
    cout << "Elemento rimosso dalla coda: " << dequeuedElement << endl;

    // Stampa la dimensione della coda dopo la rimozione
    cout << "Dimensione della coda dopo la rimozione: " << queue.getDim() << endl;

    // Stampa la coda aggiornata
    cout << "Contenuto della coda dopo la rimozione: " << queue << endl;

    Queue<int> queue2;
    queue2 = queue;
    cout << "Queue2: " << queue2 << endl;

    return 0;
}
