#include <iostream>
using namespace std;

template <typename T>
class MultiSet {

private:
    int dim;
    int capacity;
    T* elements;

public:

    MultiSet<T>() {
        this->dim = 0;
        this->capacity = 10;
        this->elements = new T[this->capacity];
    }

    // Costruttore di Copia
    MultiSet<T>(const MultiSet<T>& other) {
        this->dim = other.dim;
        this->capacity = other.capacity;
        this->elements = new T[this->capacity];

        for(int i=0; i<this->dim; i++) {
            this->elements[i] = other.elements[i];
        }
    }

    // Operatore di Assegnamento
    const MultiSet<T>& operator=(const MultiSet<T>& other) {
        if(this != &other) {
            this->dim = other.dim;
            this->capacity = other.capacity;

            T* temp = new T[this->capacity];
            for(int i=0; i<this->dim; i++) {
                temp[i] = other.elements[i];
            }
            delete[] this->elements;
            this->elements = temp;
        }

        return *this;
    }

    // Distruttore
    ~MultiSet<T>() {
        delete[] this->elements;
    }

    void augment(const int to_add) {
        this->capacity += to_add;
        T* tmp = this->elements;
        this->elements = new T[this->capacity];

        for(int i=0; i<this->dim; i++)
            this->elements[i] = tmp[i];

        delete[] tmp;

    }

    void add(const T elem) {
        if(this->dim == this->capacity)
            augment(10);
        this->elements[this->dim] = elem;
        this->dim++;
    }

    bool isEmpty() const {
        if(this->dim == 0)
            return true;
        return false;
    }

    void remove(const T elem) {
        if(this->isEmpty())
            throw new runtime_error("This multiset is empty, svegliati!");
        for(int i=0; i<this->dim; i++) {
            if(this->elements[i] == elem) {
                for(int j=i; j<this->dim-1; j++) {
                    this->elements[j] = this->elements[j+1];
                }
                this->dim--;
            }
            i--;
        }
    }

    int cardinality(const T elem) const {
        int cardinality_n = 0;
        for(int i=0; i<this->dim; i++) {
            if(this->elements[i] == elem)
                cardinality_n++;
        }
        return cardinality_n;
    }

    int getDim() const {
        return this->dim;
    }

    T getElementbyId(const int index) const {
        return this->elements[index];
    }
};

template <typename T>
ostream& operator<<(ostream& fout, const MultiSet<T>& elements) {
    for(int i=0; i<elements.getDim(); i++) {
        fout << elements.getElementbyId(i) << " ";
    }
    return fout;
}

int main() {
    // Esempio di utilizzo di MultiSet con interi
    MultiSet<int> mySet;

    // Aggiungi elementi al multiset
    mySet.add(10);
    mySet.add(20);
    mySet.add(30);
    mySet.add(20);

    // Stampa il multiset
    cout << "Contenuto del multiset: " << mySet << endl;

    // Verifica se il multiset è vuoto
    if (mySet.isEmpty()) {
        cout << "Il multiset è vuoto" << endl;
    } else {
        cout << "Il multiset non è vuoto" << endl;
    }

    // Calcola la cardinalità di un elemento nel multiset
    int element = 20;
    int count = mySet.cardinality(element);
    cout << "La cardinalità di " << element << " è " << count << endl;

    // Rimuovi un elemento dal multiset
    mySet.remove(20);

    // Stampa il multiset aggiornato
    cout << "Contenuto del multiset dopo la rimozione: " << mySet << endl;

    cout << mySet << endl;

    return 0;
}
