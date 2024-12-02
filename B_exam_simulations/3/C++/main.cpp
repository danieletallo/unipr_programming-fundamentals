/*
 * Definire una classe templatica Stack<T> che realizza il tipo di dato astratto pila di elementi
di tipo T (LIFO: Last In First Out). La classe deve definire un costruttore senza argomenti che crea una pila vuota. La
classe deve definire un metodo push che aggiunge un elemento di tipo T alla pila. La classe deve definire un metodo pop
che rimuove dalla pila l’ultimo elemento inserito e lo ritorna come risultato. Il metodo deve lanciare un’eccezione se la pila
`e vuota. La classe deve definire un metodo isEmpty che controlla se la pila `e vuota. La classe deve definire un metodo
size che ritorna il numero di elementi memorizzati nella pila. Si sovraccarichi l’operatore << in modo tale che stampi gli
elementi della pila su uno stream di output fout nel formato [e1, e1, . . . , en]. Non `e consentito utilizzare classi della STL.
Se necessario, ridefinire gli opportuni metodi, costruttori e/o operatori. Specificare opportunamente eventuali metodi e
parametri costanti. Massimizzare incapsulamento e information hiding.

 */

#include <iostream>
using namespace std;

template <typename T>
class Stack {

private:
    T* elements;
    int dim;
    int capacity;

public:

    Stack() {
        this->dim = 0;
        this->capacity = 10;
        this->elements = new T[10];
    }

    Stack(const int dim, const int capacity, const T& elements_par) {
        this->dim = dim;
        this->capacity = capacity;
        for(int i=0; i<this->dim; i++) {
            this->elements[i] = elements_par[i];
        }
    }

    // Costruttore di Copia
    Stack(const Stack& other) {
        this->dim = other.dim;
        this->capacity = other.capacity;
        this->elements = new T[this->capacity];

        for(int i=0; i<this->dim; i++) {
            this->elements[i] = other.elements[i];
        }
    }


    // Operatore di Assegnamento
    const Stack& operator=(const Stack& other) {
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
    ~Stack() {
        delete[] this->elements;
    }

    // Augment
    void augment(const int quantity) {
        this->capacity += quantity;
        T* temp = this->elements;
        this->elements = new T[this->capacity];
        for(int i=0; i<this->dim; i++) {
            this->elements[i] = temp[i];
        }
        delete[] temp;
    }

    void push(const T& element) {
        if(this->dim == this->capacity)
            augment(10);
        this->elements[this->dim] = element;
        this->dim++;
    }

    T pop() {
        if(isEmpty())
            throw new runtime_error("La pila e' gia' vuota!");
        this->dim--;
        return this->elements[this->dim];
    }

    bool isEmpty() const {
        if(this->dim == 0)
            return true;
        return false;
    }

    int size() const {
        return this->dim;
    }

    T getElement_byIndex(const int index) const {
        return this->elements[index];
    }

};

template <typename T>
ostream& operator<<(ostream& fout, const Stack<T>& elements) {
    for(int i=0; i<elements.size(); i++) {
        fout << elements.getElement_byIndex(i) << ", ";
    }

    return fout;
}

int main() {
    // Crea un oggetto Stack di interi
    Stack<int> stack;

    // Push di alcuni elementi nello stack
    stack.push(5);
    stack.push(10);
    stack.push(15);

    // Stampa il contenuto dello stack
    cout << "Contenuto dello stack: " << stack << endl;

    // Pop di un elemento dallo stack
    int poppedElement = stack.pop();
    cout << "Elemento pop dallo stack: " << poppedElement << endl;

    // Aggiunta di elementi dopo la pop
    stack.push(20);
    stack.push(25);

    // Stampa il contenuto aggiornato dello stack
    cout << "Contenuto dello stack dopo l'aggiunta di elementi: " << stack << endl;

    // Stampa la dimensione dello stack
    cout << "Dimensione dello stack: " << stack.size() << endl;

    // Verifica se lo stack è vuoto
    if (stack.isEmpty()) {
        cout << "Lo stack è vuoto." << endl;
    } else {
        cout << "Lo stack non è vuoto." << endl;
    }

    return 0;
}
