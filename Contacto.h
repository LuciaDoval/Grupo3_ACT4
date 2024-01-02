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
    vector<Contacto> contactos;
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
     * Metodo para ver todos los datos de un contacto
     */
     void verInfo(){
        cout << "Email: " << email << ", Info: " << info << endl;
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

};


/**
 * Funcion para poder modificar la informacion del contacto
 * @param email
 * @param contactos
 */
void modificarInfoDelContacto(string email, ListaEnlazada<Contacto> &contactos){
    bool found = false;
    for (int i = 0; i < contactos.size(); ++i) {
        if (email == contactos.at(i)->getDato().getEmail()){
            string infoNueva;
            cout << "Ingrese la nuea informacion: " << endl;
            cin >> infoNueva;
            contactos.at(i)->getDato().setInfo(infoNueva);
            found = true;
        }
    }
    if (!found ){
        cout << "No se ha encontrado" << endl;
    }
}
/**
 * Funcion que te permite buscar tu contacto mediante el email
 * @param email
 * @param contactos
 */
void busquedaDeContacto(string email, ListaEnlazada<Contacto> &contactos){
    bool found = false;
    for (int i = 0; i < contactos.size(); ++i){
        if (email == contactos.at(i)->getDato().getEmail()){
            contactos.at(i)->getDato().verInfo();
            found = true;
        }
    }
    if (!found ){
        cout << "No se ha encontrado" << endl;
    }
}
/**
 * Funcion para eliminar contactor
 * @param email
 * @param contactos
 */
void eliminarContacto(string email, ListaEnlazada<Contacto> &contactos){
    for (int i = 0; i < contactos.size(); ++i){
        if (email == contactos.at(i)->getDato().getEmail()){
            contactos.at(i)->getDato().setInfo("");
            contactos.at(i)->getDato().setEmail("");
        }
    }
}

#endif //GRUPO3_ACT4_CONTACTO_H
