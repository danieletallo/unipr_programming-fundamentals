/*
Definire una classe templatica Insieme<T> che realizza il tipo di dato astratto insieme
di elementi di tipo T. La classe deve definire un costruttore senza argomenti che crea un insieme vuoto. Il metodo add
aggiunge un elemento di tipo T all’insieme. Se l’elemento `e gi`a presente, il metodo deve lanciare un’eccezione. Il metodo
contains verifica se un elemento appartiene all’insieme. Il metodo size ritorna la cardinalit`a dell’insieme. Si sovraccarichi
l’operatore + in modo tale che restituisca un nuovo insieme ottenuto dall’unione dell’insieme su cui `e chiamato il metodo e
l’insieme passato come parametro. Si sovraccarichi l’operatore << in modo tale che stampi gli elementi dell’insieme su uno
stream di output fout nel formato {e1, e1, . . . , en}. Non `e consentito utilizzare classi della STL. Se necessario, ridefinire
gli opportuni metodi, costruttori e/o operatori. Specificare opportunamente eventuali metodi costanti.
 */


#include <iostream>
using namespace std;

template <typename T>
class Insieme{

private:
    T* elements;
    int dim;
    int capacity;

public:

    Insieme() {
        this->dim = 0;
        this->capacity = 10;
        this->elements = new T[this->capacity];
    }

    Insieme(const int dim, const int capacity, const T& elementi) {
        this->dim = dim;
        this->capacity = capacity;
        this->elements = new T[this->capacity];

        for(int i=0; i<capacity; i++) {
            this->elements[i] = elementi[i];
        }
    }

    // Costruttore di Copia
    Insieme(const Insieme& other) {
        this->dim = other.dim;
        this->capacity = other.capacity;
        this->elements = new T[capacity];

        for(int i=0; i<this->dim; i++) {
            this->elements[i] = other.elements[i];
        }
    }

    // Operatore di Assegnamento
    const Insieme& operator=(const Insieme& other) {
        if(this != &other) {
            this->dim = other.dim;
            this->capacity = other.capacity;

            T* new_buffer = new T[this->capacity];
            for(int i=0; i<this->dim; i++) {
                new_buffer[i] = other.elements[i];
            }
            delete[] this->elements;
            this->elements = new_buffer;
        }

        return *this;
    }

    //Distruttore
    ~Insieme() {
        delete[] this->elements;
    }

    void augment(int more_dim) {
        capacity += more_dim;
        T* B = this->elements;
        this->elements = new T[capacity];
        for(int i = 0; i < dim; i++) {
            this->elements[i] = B[i];
        }
        delete[] B;
    }

    void add(const T& element) {
        if(this->dim == this->capacity)
            this->augment(10);

        if(this->contains(element))
            throw runtime_error("L'elemento e' gia' presente nell'insieme!");
        else {
            this->elements[dim] = element;
            this->dim++;
        }
    }

    bool contains(const T& element) {
        for(int i=0; i<this->dim; i++) {
            if(this->elements[i] == element)
                return true;
        }
        return false;
    }

    int size() const {
        return this->dim;
    }

    T getElement_byIndex(const int index) const {
        return this->elements[index];
    }

    Insieme<T> operator+(const Insieme& other) {
        for(int i=0; i<other.dim; i++) {
            this->add(other.elements[i]);
        }
        return *this;
    }
};

template <typename T>
ostream& operator<<(ostream& fout, const Insieme<T>& ins) {
    for(int i=0; i<ins.size(); i++) {
        fout << ins.getElement_byIndex(i) << ", ";
    }

    return fout;
}

int main() {
    // Test del costruttore di default
    Insieme<int> insieme1;

    // Test del metodo add
    insieme1.add(10);
    insieme1.add(20);
    insieme1.add(30);

    // Test del metodo contains
    cout << "L'insieme1 contiene il valore 20? " << (insieme1.contains(20) ? "Si" : "No") << endl;
    cout << "L'insieme1 contiene il valore 40? " << (insieme1.contains(40) ? "Si" : "No") << endl;

    // Test del metodo size
    cout << "La dimensione di insieme1 e': " << insieme1.size() << endl;

    // Test dell'operatore di indice
    cout << "Elemento all'indice 0 di insieme1: " << insieme1.getElement_byIndex(0) << endl;

    // Test dell'operatore di output
    cout << "Contenuto di insieme1: " << insieme1 << endl;

    // Test del costruttore di copia
    Insieme<int> insieme2 = insieme1;
    cout << "Contenuto di insieme2 (copia di insieme1): " << insieme2 << endl;

    // Test dell'operatore di assegnamento
    Insieme<int> insieme3;
    insieme3 = insieme1;
    cout << "Contenuto di insieme3 (assegnamento da insieme1): " << insieme3 << endl;

    // Test dell'operatore di concatenazione
    Insieme<int> insieme4;
    insieme4.add(40);
    insieme4.add(50);
    Insieme<int> insieme5 = insieme1 + insieme4;
    cout << "Contenuto di insieme5 (insieme1 + insieme4): " << insieme5 << endl;

    cout << insieme5 ;

    return 0;
}
