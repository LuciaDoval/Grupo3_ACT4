//
// Created by doval on 26/12/2023.
//

#ifndef GRUPO3_ACT4_USUARIO_H
#define GRUPO3_ACT4_USUARIO_H

#include <vector>
#include "enums/Genero.h"
#include "ListaEnlazada.h"
#include "Contacto.h"

using namespace std;

class Usuario {
private:
    string email;
    string apodo;
    string contrasenha;
    string descripcion;
    int edad;
    Genero genero;
    ListaEnlazada<Contacto> contactos;

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

    void print() const {
        cout << "Email: " << getEmail()
         << ", Apodo: " << getApodo()
         << ", Descripcion: " << getDescripcion()
         << ", Edad: " << getEdad()
         << ", Genero: " << getGenero() << endl;
    }

    bool operator==(const Usuario& usuario) const {
        return (
                email == usuario.email &&
                apodo == usuario.apodo &&
                contrasenha == usuario.contrasenha &&
                descripcion == usuario.descripcion &&
                edad == usuario.edad &&
                genero == usuario.genero
        );
    }

};

//leer
void printUsuarios(ListaEnlazada<Usuario> usuarios) {
    cout << "Lista de Usuarios:" << endl;
    for (int i = 0; i < usuarios.size(); ++i) {
        usuarios.at(i)->getDato().print();
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
void actualizarUsuario(string email, string apodo, string contrasenha, string descripcion, int edad, Usuario &usuario, ListaEnlazada<Usuario> &usuarios){
    bool found = false;
    for (int i = 0; i < usuarios.size(); ++i) {
        if (usuario == usuarios.at(i)->getDato()) {
            usuarios.eliminarDato(usuario);
            if(email == ""){ email = usuario.getEmail();}
            if(apodo == ""){ email = usuario.getApodo();}
            if(contrasenha == ""){ email = usuario.getContrasenha();}
            if(descripcion == ""){ email = usuario.getDescripcion();}
            if(edad == 0){ email = usuario.getEdad();}
            auto *aux = new Usuario( email,  apodo, contrasenha, descripcion, edad, usuario.getGenero());
            usuarios.insertFinal(*aux);
            usuario.setEmail(email);
            usuario.setEdad(edad);
            usuario.setApodo(apodo);
            usuario.setContrasenha(contrasenha);
            usuario.setDescripcion(descripcion);
            found = true;
        }
    }
    if (!found) {
        cout << "No se ha encontrado" << endl;
    }
}

#endif //GRUPO3_ACT4_USUARIO_H
