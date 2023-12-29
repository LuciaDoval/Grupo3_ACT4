//
// Created by doval on 26/12/2023.
//

#ifndef GRUPO3_ACT4_LISTAENLAZADA_H
#define GRUPO3_ACT4_LISTAENLAZADA_H
using namespace std;

template<class T>
class ListaEnlazada {
private:
    class Nodo {
    private:
        T dato;
        Nodo *enlace;
    public:

        /**
         * Constructor parametrizado
         * @param dato Dato del nodo
         * @param enlace Enlace del nodo
         */
        Nodo(T dato) : dato(dato), enlace(nullptr) {}

        // Getter para conseguir el dato del nodo
        T getDato() const {
            return dato;
        }

        // Getter para conseguir el enlace del nodo
        Nodo *getEnlace() const {
            return enlace;
        }

        // Setter para establecer el enlace del nodo
        void setEnlace(Nodo *enlace) {
            Nodo::enlace = enlace;
        }
    };

    Nodo *primero; // Puntero al primer elemento de la lista
public:
    /**
     * Constructor vacio
     */
    ListaEnlazada() {
        ListaEnlazada::primero = nullptr;
    }

    /**
     * Metodo para conseguir el ultimo Nodo de la lista
     * @return ultimo Nodo de la lista
     */
    Nodo *ultimoNodo() {
        Nodo *ultimo = primero;

        if (ultimo == nullptr) { // La lista esta vacia
            return nullptr;
        } else { // La lista tiene elementos
            while (ultimo->getEnlace() != nullptr) {
                ultimo = ultimo->getEnlace();
            }
            return ultimo;
        }
    }

    /**
     * Metodo para conseguir el size total de la lista
     * @return size total de la lista
     */
    int size() {
        int size = 0;
        Nodo *nodo = primero;
        while (nodo != nullptr) {
            nodo = nodo->getEnlace();
            size++;
        }
        return size;
    }

    /**
     * Metodo para conseguir un Nodo en una posicion concreta
     * @param pos Posicion del Nodo que quieres buscar
     * @return Nodo que quieres buscar
     */
    Nodo *at(int pos) {
        if (pos <= size() && pos >= 0) { // Posicion valida
            Nodo *at = primero;
            if (at == nullptr) { // Lista vacia
                return nullptr;
            } else { // Lista con elementos
                for (int i = 0; i < pos; i++) {
                    at = at->getEnlace();
                }
                return at;
            }
        } else {
            cout << "Posicion invalida" << endl;
            return nullptr;
        }
    }

    /**
     * Metodo para conseguir el Nodo anterior de un Nodo dado
     * @param nodo Nodo dado para buscar su anterior
     * @return Nodo anterior del Nodo dado
     */
    Nodo *nodoAnterior(Nodo *nodo) {
        Nodo *nodoAnterior = primero;
        if (primero == nullptr) { // No hay Nodos
            return nullptr;
        } else if (nodoAnterior == nodo) { // Solo hay un Nodo
            return nodo;
        }
        while (nodoAnterior->getEnlace() != nodo) {
            nodoAnterior = nodoAnterior->getEnlace();
        }
        return nodoAnterior;
    }

    /**
     * Metodo para insertar un Nodo al final ( Los Nodos no se pueden repetir)
     * @param dato Dato a insertar en el Nodo
     */
    void insertFinal(T dato) {
        Nodo *nodo = new Nodo(dato);
        Nodo *ultimo = ultimoNodo();

        for (int i = 0; i < size(); i++) {
            if (this->at(i)->getDato() == dato) {
                throw runtime_error("No se pueden insertar elementos duplicados");
            }
        }
        if (primero == nullptr) { // No hay elementos en la lista
            primero = nodo;
        } else { ultimo->setEnlace(nodo); }
    }

    /**
     * Metodo para eliminar un Nodo concreto
     * @param dato dato del Nodo a eliminar
     */
    void eliminarDato(T dato) {
        Nodo *anterior; // Nodo anterior al que se quiere eliminar
        for (int i = 0; i < size(); i++) { // Recorre la lista
            if (this->at(i)->getDato() == dato) { // Comprueba si el dato del Nodo iterado es = al dato buscado
                anterior = nodoAnterior(this->at(i)); // Guarda el Nodo anterior del que queremos eliminar
                anterior->setEnlace(this->at(i)->getEnlace()); // Settea el enlace del anterior Nodo
                cout << "Se ha eliminado: " << dato << endl;
            }
        }
    }

    /**
     * Print por pantalla de la lista
     */
    void print() {
        Nodo *nodo = primero;
        while (nodo != nullptr) {
            cout << nodo->getDato() << endl;
            nodo = nodo->getEnlace();
        }
    }

};


#endif //GRUPO3_ACT4_LISTAENLAZADA_H
