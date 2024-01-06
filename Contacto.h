//
// Created by doval on 26/12/2023.
//

#ifndef GRUPO3_ACT4_CONTACTO_H
#define GRUPO3_ACT4_CONTACTO_H

#include <string>
#include "ListaEnlazada.h"

using namespace std;

class Contacto{
private:
    string email;
    string info;
public:
    /**
     * Constructor a vacio de Contacto
     */
    Contacto(){
        email = "";
        info = "";
    }
    /**
     * Constructor parametrizado de contacto
     * @param email email del contacto
     * @param info informacion del contacto
     */
    Contacto(string email, string info){
        Contacto::info = info;
        Contacto::email = email;
    }

    /**
     * Destructor de la clase contacto
     */
    ~Contacto() {

    }

    /**
     * Metodo para ver todos los datos de un contacto
     */
     string to_string(){
        return  "Email: " + email + ", Info: " + info;
    }

    /**
     * Getter del email del contacto
     * @return email
     */
    const string &getEmail() const {
        return email;
    }
    /**
     * Setter del email del contacto
     * @param email
     */
    void setEmail(const string &email) {
        Contacto::email = email;
    }
    /**
     * Getter de la informacion del contacto
     * @return info
     */
    const string &getInfo() const {
        return info;
    }
    /**
     * Setter de la informacion del contacto
     * @param info
     */
    void setInfo(const string &info) {
        Contacto::info = info;
    }

    // Sobrecarga del operador ==
    bool operator==(const Contacto& otro) const {
        return (email == otro.email) && (info == otro.info);
    }

    friend std::ostream& operator<<(std::ostream&os, const Contacto&c) {
        os << ("Contacto: " +c.getEmail() +", descripcion: "+ c.getInfo());
        return os;
    }
};



/**
 * Funcion que te permite modificar un contacto
 * @param infoNueva informacion por la que vas a cambiar
 * @param contacto Contacto a modificar
 * @param contactos La lista de contactos
 */
void modificarInfoDelContacto(string infoNueva, Contacto &contacto, ListaEnlazada<Contacto> &contactos){
    bool found = false;
    for (int i = 0; i < contactos.size(); ++i) {
        if (contacto == contactos.at(i)->getDato()) {
            contactos.eliminarDato(contacto);
            auto  aux = new Contacto(contacto.getEmail(), infoNueva);
            try {
                contactos.insertFinal(*aux);
            } catch (...) {
                cerr << "No se ha podido insertar" << endl;
            }
            contacto.setInfo(infoNueva);
            found = true;
        }
    }
    if (!found) {
        cout << "No se ha encontrado" << endl;
    }
}
/**
 * Funcion que te permite buscar tu contacto mediante el email
 * @param email
 * @param contactos
 */
int busquedaDeContacto(string email, ListaEnlazada<Contacto>& contactos) {
    bool found = false;
    for (int i = 0; i < contactos.size(); ++i) {
        if (email == contactos.at(i)->getDato().getEmail()) {
            found = true;
            return i;
        }
    }
    if (!found) {
        return -1;
    }
}

#endif //GRUPO3_ACT4_CONTACTO_H
