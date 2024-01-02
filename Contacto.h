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
    Contacto(){
        email = "";
        info = "";
    }

    Contacto(string email, string info){
        Contacto::info = info;
        Contacto::email = email;
    }

     void verInfo(){
        cout << "Email: " << email << ", Info: " << info << endl;
    }

    const string &getEmail() const {
        return email;
    }

    void setEmail(const string &email) {
        Contacto::email = email;
    }

    const string &getInfo() const {
        return info;
    }

    void setInfo(const string &info) {
        Contacto::info = info;
    }

};



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

void eliminarContacto(string email, ListaEnlazada<Contacto> &contactos){
    for (int i = 0; i < contactos.size(); ++i){
        if (email == contactos.at(i)->getDato().getEmail()){
            contactos.at(i)->getDato().setInfo("");
            contactos.at(i)->getDato().setEmail("");
        }
    }
}

#endif //GRUPO3_ACT4_CONTACTO_H
