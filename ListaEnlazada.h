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

    Nodo *primero; // Punteor al primer elemento de la lista
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
     * Metodo para conseguir el tamanho total de la lista
     * @return tamanho total de la lista
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
     * Metodo para insertar un Nodo al final
     * @param dato Dato a insertar en el Nodo
     */
    void insertFinal(T dato) {
        Nodo *nodo = new Nodo(dato);
        Nodo *ultimo = ultimoNodo();

        if (primero == nullptr) { // No hay elementos en la lista
            primero = nodo;
        } else {
            ultimo->setEnlace(nodo);
        }
    }

    /**
     * Metodo para insertar un Nodo al principio
     * @param dato Dato a insertar en el Nodo
     */
    void insertInicio(T dato) {
        Nodo *nodo = new Nodo(dato);
        if (primero == nullptr) {
            primero = nodo;
        } else {
            nodo->setEnlace(primero);
            primero = nodo;
        }
    }

    /**
     * Metodo para insertar un Nodo en una posicion concreta
     * @param pos Posicion en la cual insertar el nuevo Nodo
     * @param dato Dato a insertar en el Nodo
     */
    void insertPosicion(int pos, T dato) {
        if (pos <= size() && pos >= 0) {
            Nodo *nodo = new Nodo(dato);

            if (primero == nullptr) { // No hay elementos en la lista
                primero = nodo;
            } else {
                nodo->setEnlace(at(pos)); // Enlace del nuevo nodo al antiguo de su posicion
                at(pos - 1)->setEnlace(nodo); // Enlace del nodo anterior al nuevo
            }
        } else {
            cout << "Posicion invalida" << endl;
        }
    }

    /**
     * Metodo para insertar un Nodo en el medio de la lista
     * @param dato
     */
    void insertarCentro(T dato) { (size() == 1) ? insertFinal(dato) : insertPosicion(size()/2, dato); }


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
