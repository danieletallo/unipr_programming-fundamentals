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
        this->elements = new T[capacity];
    }

    // Costruttore di Copia
    MultiSet<T>(const MultiSet<T>& other) {
        this->dim = other.dim;
        this->capacity = other.capacity;
        this->elements = new T[this->capacity];

        for(int i=0; i<other.dim; i++) {
            this->elements[i] = other.elements[i];
        }
    }

    // Operatore di Assegnamento
    const MultiSet<T>& operator=(const MultiSet<T>& other) {
        if(this != &other) {
            this->dim = other.dim;
            this->capacity = other.capacity;

            delete[] this->elements;
            this->elements = new T[this->capacity];
            for(int i=0; i<this->dim; i++) {
                this->elements[i] = other.elements[i];
            }
        }
        return *this;
    }

    // Distruttore
    ~MultiSet<T>() {
        delete[] elements;
    }

    void augment(const int quantity) {
        this->capacity += quantity;
        T* temp = this->elements;

        this->elements = new T[this->capacity];
        for(int i=0; i<this->dim; i++) {
            this->elements[i] = temp[i];
        }

        delete[] temp;
    }

    void add(const T elem) {
        if(this->dim == this->capacity)
            augment(10);
        this->elements[this->dim] = elem;
        this->dim++;
    }

    bool contains(const T elem) const {
        for(int i=0; i<this->dim; i++) {
            if(this->elements[i] == elem)
                return true;
        }
        return false;
    }

    bool isEmpty() const {
        return this->dim == 0;
    }

    int occorrenze(const T& elem) const {
        int n_occorrenze = 0;
        for(int i=0; i<this->dim; i++) {
            if(this->elements[i] == elem)
                n_occorrenze++;
        }
        return n_occorrenze;
    }

    int getDim() const {
        return this->dim;
    }

    T getElementbyId(const int index) const {
        return this->elements[index];
    }

    bool operator==(const MultiSet<T>& other) {
        if(this->dim != other.dim)
            return false;
        if(this->isEmpty() || other.isEmpty())
            return false;
        for(int i=0; i<this->dim; i++) {
            if(this->occorrenze(this->elements[i]) != other.occorrenze(this->elements[i]))
                return false;
        }
        return true;
    }
};

template <typename T>
ostream& operator<<(ostream& fout, const MultiSet<T>& insieme) {
    for(int i=0; i<insieme.getDim(); i++) {
        fout << insieme.getElementbyId(i) << " ";
    }
    return fout;
}

int main() {
    // Creazione di due oggetti MultiSet
    MultiSet<int> set1;
    MultiSet<int> set2;

    // Aggiunta di elementi a set1
    set1.add(1);
    set1.add(2);
    set1.add(2);
    set1.add(3);

    // Stampa del contenuto di set1
    cout << "Set1: " << set1 << endl;

    // Copia di set1 in set2 utilizzando l'operatore di assegnamento
    set2 = set1;

    // Stampa del contenuto di set2
    cout << "Set2: " << set2 << endl;

    // Aggiunta di elementi a set2
    set2.add(4);
    set2.add(5);

    // Stampa del contenuto di set2 dopo l'aggiunta
    cout << "Set2 dopo l'aggiunta: " << set2 << endl;

    // Verifica della presenza di un elemento in set1
    int searchElement = 2;
    if (set1.contains(searchElement)) {
        cout << searchElement << " presente in set1" << endl;
    } else {
        cout << searchElement << " non presente in set1" << endl;
    }

    // Calcolo delle occorrenze di un elemento in set2
    int countElement = 2;
    int occurrences = set2.occorrenze(countElement);
    cout << "Numero di occorrenze di " << countElement << " in set2: " << occurrences << endl;

    set1.add(5);
    set1.add(4);

    cout << "Set1: " << set1 << endl;
    cout << "Set2: " << set2 << endl;
    // Verifica dell'uguaglianza tra set1 e set2
    if (set1 == set2) {
        cout << "Set1 e Set2 sono uguali." << endl;
    } else {
        cout << "Set1 e Set2 non sono uguali." << endl;
    }

    return 0;
}
