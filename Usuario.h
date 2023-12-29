//
// Created by doval on 26/12/2023.
//

#ifndef GRUPO3_ACT4_USUARIO_H
#define GRUPO3_ACT4_USUARIO_H

#include <vector>
#include "enums/Genero.h"
#include "ListaEnlazada.h"

using namespace std;

class Usuario {
private:
    string email;
    string apodo;
    string contrasenha;
    string descripcion;
    int edad;
    Genero genero;
    //ListaEnlazada contactos;
    vector<Usuario> usuarios;

public:
    Usuario(string email, string apodo, string contrasenha, string descripcion, int edad, Genero genero) :
            email(email),
            apodo(apodo),
            contrasenha(contrasenha),
            descripcion(descripcion),
            edad(edad),
            genero(genero) {
    }

    const string &getEmail() const {
        return email;
    }

    void setEmail(const string &email) {
        Usuario::email = email;
    }

    const string &getApodo() const {
        return apodo;
    }

    void setApodo(const string &apodo) {
        Usuario::apodo = apodo;
    }

    const string &getContrasenha() const {
        return contrasenha;
    }

    void setContrasenha(const string &contrasenha) {
        Usuario::contrasenha = contrasenha;
    }

    const string &getDescripcion() const {
        return descripcion;
    }

    void setDescripcion(const string &descripcion) {
        Usuario::descripcion = descripcion;
    }

    int getEdad() const {
        return edad;
    }

    void setEdad(int edad) {
        Usuario::edad = edad;
    }

    Genero getGenero() const {
        return genero;
    }

    void setGenero(Genero genero) {
        Usuario::genero = genero;
    }

    void mostrar() const {
        cout << "Email: " << getEmail() << endl;
        cout << "Apodo: " << getApodo() << endl;
        cout << "Descripcion: " << getDescripcion() << endl;
        cout << "Edad: " << getEdad() << endl;
        cout << "Genero: " << getGenero() << endl;
    }

    //añadir
    void anhadirUsuario(const Usuario& nuevoUsuario) {
    usuarios.push_back(nuevoUsuario);
    cout << "Usuario creado" << endl;
    }

    //leer
    void leerUsuario() {
        cout << "Lista de Usuarios:" << endl;
        for (const auto& usuario : usuarios) {
            return usuario.mostrar();
        }
    }

    void buscarEmail(string email, ListaEnlazada<Usuario> &usuarios) {
        bool found = false;
        for (int i = 0; i < usuarios.size(); i++) {
            if (email == usuarios.at(i)->getDato().getEmail()) {
                found = true;
                cout << "El email buscado es el: " << usuarios.at(i)->getDato().getEmail() << endl;
            }
        }
        if (!found) {
            cout << "No se encontro ningun email" << endl;
        }
    }
    void buscarApodo(string apodo, ListaEnlazada<Usuario> &usuarios) {
        bool found = false;
        for (int i = 0; i < usuarios.size(); i++) {
            if (apodo == usuarios.at(i)->getDato().getApodo()) {
                found = true;
                cout << usuarios.at(i) << endl;
            }
        }
        if (!found) {
            cout << "No se encontro ningun apodo" << endl;
        }
    }
    void buscarEdad(int edad, ListaEnlazada<Usuario> &usuarios) {
        bool found = false;
        for (int i = 0; i < usuarios.size(); i++) {
            if (edad == usuarios.at(i)->getDato().getEdad()) {
                found = true;
                cout << usuarios.at(i) << endl;
            }
        }
        if (!found) {
            cout << "No se encontro ninguna edad" << endl;
        }
    }
    void buscarGenero(Genero genero, ListaEnlazada<Usuario> &usuarios) {
        bool found = false;
        for (int i = 0; i < usuarios.size(); i++) {
            if (genero == usuarios.at(i)->getDato().getGenero()) {
                found = true;
                cout << usuarios.at(i) << endl;
            }
        }
        if (!found) {
            cout << "No se encontro ningun genero" << endl;
        }
    }

    //actualizar
    void actualizarUsuario(const string &email, const Usuario &nuevosDatos) {
        for (auto &i : usuarios) { //itera a traves de cada elemento de la lista de usuarios y para cada elemento, se hace referencia mediante "i"
            if (i.getEmail() == email) { //verifica si el email actual coincide con el email introducido
                i = nuevosDatos; //si se encuentra un usuario con ese email se actualizan los datos
                cout << "Usuario actualizado" << endl;
            }
        }
        cout << "Usuario no encontrado" << endl;
    }

    //eliminar
    void eliminarUsuario(const string &email) {//referencia const a un string
        for (auto it = usuarios.begin(); it != usuarios.end(); ++it) {//itera, con it, a traves de usuarios desde el inicio hasta el final
            if (it->getEmail() == email) { //se compara si eñ email introducido coincide con el introducido
                usuarios.erase(it); //si coincide, se elimina de la posisicion encontrada
                cout << "Usuario eliminado" << endl;
            }
        }
        cout << "Usuario no encontrado" << endl;
    }
};


#endif //GRUPO3_ACT4_USUARIO_H
