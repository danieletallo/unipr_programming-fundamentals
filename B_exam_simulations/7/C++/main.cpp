#include <iostream>
using namespace std;

template <typename T>
class Queue {

private:
    int dim;
    int capacity;
    T* coda;

    void augment(const int quantity) {
        this->capacity += quantity;
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
        this->coda = new T[this->capacity];
    }

    // Costruttore di Copia
    Queue<T>(const Queue<T>& other) {
        this->dim = other.dim;
        this->capacity = other.capacity;
        this->coda = new T[this->capacity];

        for(int i=0; i<this->dim; i++) {
            this->coda[i] = other.coda[i];
        }
    }

    // Operatore di Assegnamento
    Queue<T>& operator=(const Queue<T>& other) {
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

    void enqueue(T elem) {
        if(this->dim == this->capacity)
            this->augment(10);

        this->coda[dim] = elem;
        this->dim++;
    }

    T dequeue() {
        if(this->isEmpty())
            throw string("Coda vuota!");

        T elem_to_return = this->coda[0];

        this->dim--;
        for(int i=0; i<this->dim; i++) {
            this->coda[i] = this->coda[i+1];
        }

        return elem_to_return;
    }

    bool isEmpty() const {
        return this->dim == 0;
    }

    void stampa(ostream& fout) const {
        fout << "[";
        for(int i=0; i<this->dim; i++) {
            fout << this->coda[i];
            if(i != this->dim-1)
                fout << ", ";
        }
        fout << "]";
    }
};

template <typename T>
ostream& operator<<(ostream& fout, const Queue<T>& codone) {
    codone.stampa(fout);
    return fout;
}

int main() {
    Queue<int> queue;

    // Aggiungiamo alcuni elementi alla coda
    queue.enqueue(5);
    queue.enqueue(10);
    queue.enqueue(15);

    // Stampa la coda
    cout << "Coda: " << queue << endl;

    // Rimuove un elemento dalla coda
    int front = queue.dequeue();
    cout << "Elemento rimosso dalla coda: " << front << endl;

    // Stampa la coda aggiornata
    cout << "Coda aggiornata: " << queue << endl;

    return 0;
}
