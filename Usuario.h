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
    ListaEnlazada<Contacto>* contactos;

public:
    /**
     * Constructor parametrizado de usuario
     * @param email Email del usuario
     * @param apodo Apodo del usuario
     * @param contrasenha Contrasenha del usuario
     * @param descripcion Descripción personal sobre el usuario
     * @param edad Edad del usuario
     * @param genero Genero del usuario
     */
    Usuario(string email, string apodo, string contrasenha, string descripcion, int edad, Genero genero) :
            email(email),
            apodo(apodo),
            contrasenha(contrasenha),
            descripcion(descripcion),
            edad(edad),
            genero(genero) {

        contactos = new ListaEnlazada<Contacto>();
    }

    /**
     * Constructor vacío de usuario
     */
    Usuario (){}

    /**
     * Destructor de usuario
     */
    virtual ~Usuario() {
    }

    /**
     * getter de email
     * @return te devuelve el email
     */
    const string &getEmail() const {
        return email;
    }

    /**
     * set de email
     * @param email
     */
    void setEmail(const string &email) {
        Usuario::email = email;
    }

    /**
     * Metodo get de apodo
     * @return te devuelve el apodo
     */
    const string &getApodo() const {
        return apodo;
    }

    /**
     * Metodo set de apodo
     * @param apodo
     */
    void setApodo(const string &apodo) {
        Usuario::apodo = apodo;
    }

    /**
     * Metodo get de contrasenha
     * @return te devuelve la contrasenha
     */
    const string &getContrasenha() const {
        return contrasenha;
    }

    /**
     * metodo set de contrasenha
     * @param contrasenha
     */
    void setContrasenha(const string &contrasenha) {
        Usuario::contrasenha = contrasenha;
    }

    /**
     * Metodo get de descripcion
     * @return te devuelve la descripcion
     */
    const string &getDescripcion() const {
        return descripcion;
    }

    /**
     * Metodo get de la lista enlazada de contactos
     * @return te devuelve un puntero con la referencia de la lista enlazada de contactos
     */
    ListaEnlazada<Contacto> &getContactos() {
        return *contactos;
    }

    /**
     * Metodo set de contactos
     * @param contactos
     */
    void setContactos(ListaEnlazada<Contacto> *contactos) {
        Usuario::contactos = contactos;
    }

    /**
     * Metodo set de descripcion
     * @param descripcion
     */
    void setDescripcion(const string &descripcion) {
        Usuario::descripcion = descripcion;
    }

    /**
     * Metodo get de edad
     * @return te devuelve la edad
     */
    int getEdad() const {
        return edad;
    }

    /**
     * Metodo set de edad
     * @param edad
     */
    void setEdad(int edad) {
        Usuario::edad = edad;
    }

    /**
     * Metodo get de genero
     * @return te devuelve el genero
     */
    Genero getGenero() const {
        return genero;
    }

    //Sobrecarga del operador ==
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

    //Sobrecarga del operador <<
    friend std::ostream& operator<<(std::ostream&os, const Usuario&us) {
        string genero;
        switch (us.getGenero()) {
            case 0:
                genero = "Mujer";
                break;
            case 1:
                genero = "Hombre";
                break;
            case 2:
                genero= "Otro";
                break;
            default:
                genero = "No definido";
                break;
        }
        os << (us.getApodo() +"\n" + us.getEmail() +"\nEdad:" + to_string(us.getEdad()) + " Genero: " +genero + "\ndescripcion: " + us.getDescripcion());
        return os;
    }

};

/**
 * Funcion que busca un email en una lista de usuarios
 * @param email email que estamos buscando
 * @param usuarios lista de usuarios
 * @return Te devuelve el usuario que estas buscando, si no lo encuentra lanza un error
 */
Usuario &buscarEmail(string email, ListaEnlazada<Usuario> &usuarios) {

    for (int i = 0; i < usuarios.size(); i++) {
        if (email == usuarios.at(i)->getDato().getEmail()) {
            return usuarios.at(i)->getDato();
        }
    }
    throw std::runtime_error("No se encontro el email");

}

/**
 * Busca un email en la lista de usuarios y devuelve true si lo encuentra
 * @param email email que queremos encontrar
 * @param contactos lista de contactos
 * @return usuario encontrado -> true, else -> false
 */
bool buscarEmailBool(string email, ListaEnlazada<Contacto> &contactos) {

    for (int i = 0; i < contactos.size(); i++) {
        if (email == contactos.at(i)->getDato().getEmail()) {
            return true;
        }
    }
    return false;

}

/**
 * Busca un email en la lista de usuarios y devuelve true si lo encuentra
 * @param email email que queremos encontrar
 * @param usuarios lista de usuarios
 * @return usuario encontrado -> true, else -> false
 */
bool buscarEmailBool1(string email, ListaEnlazada<Usuario> &usuarios) {

    for (int i = 0; i < usuarios.size(); i++) {
        if (email == usuarios.at(i)->getDato().getEmail()) {
            return true;
        }
    }
    return false;

}

/**
 * Funcion que busca un apodo en una lista, printeando por pantalla los usuarios que encuentra
 * @param apodo apodo que estamos buscando
 * @param usuarios lista de usuarios
 */
void buscarApodo(string apodo, ListaEnlazada<Usuario> &usuarios) {
    bool found = false;
    for (int i = 0; i < usuarios.size(); i++) {
        if (apodo == usuarios.at(i)->getDato().getApodo()) {
            found = true;
            cout << usuarios.at(i)->getDato() << endl;
        }
    }
    if (!found) {
        cout << "No se encontro ningun usuario con ese apodo" << endl;
    }
}

/**
 * Funcion que busca varios usuarios con una misma edad en una lista de usuarios y los imprime por pantalla
 * @param edad edad que estamos buscando
 * @param usuarios lista de usuarios
 */
void buscarEdad(int edad, ListaEnlazada<Usuario> &usuarios) {
    bool found = false;
    for (int i = 0; i < usuarios.size(); i++) {
        if (edad == usuarios.at(i)->getDato().getEdad()) {
            found = true;
            cout << usuarios.at(i)->getDato() << endl;
        }
    }
    if (!found) {
        cout << "No se encontro ninguna edad" << endl;
    }
}

/**
 * Funcion que busca el genero de varios usuarios en una lista de usuarios y los imprime por pantalla
 * @param genero genero que estamos buscando
 * @param usuarios lista de usuarios
 */
void buscarGenero(Genero genero, ListaEnlazada<Usuario> &usuarios) {
    bool found = false;
    for (int i = 0; i < usuarios.size(); i++) {
        if (genero == usuarios.at(i)->getDato().getGenero()) {
            found = true;
            cout << usuarios.at(i)->getDato() << endl;
        }
    }
    if (!found) {
        cout << "No se encontro ningun genero" << endl;
    }
}

/**
 * Funcion que sirve para actualizar un usuario en una lista de usuarios
 * si alguno de los elementos esta vacio, pone el dato que tenia el usuario anterior
 * @param email email que queremos modificar
 * @param apodo apodo que queremos modificar
 * @param contrasenha contrasenha que queremos modificar
 * @param descripcion descripcion que queremos modificar
 * @param edad edad que queremos modificar
 * @param usuario usuario que queremos modificar
 * @param usuarios lista de usuarios
 */
void actualizarUsuario(string email, string apodo, string contrasenha, string descripcion, int edad, Usuario &usuario, ListaEnlazada<Usuario> &usuarios){
    bool found = false;
    for (int i = 0; i < usuarios.size(); ++i) {
        if (usuario == usuarios.at(i)->getDato()) {
            usuarios.eliminarDato(usuario);
            if(email == ""){ email = usuario.getEmail();}
            if(apodo == ""){ apodo = usuario.getApodo();}
            if(contrasenha == ""){ contrasenha = usuario.getContrasenha();}
            if(descripcion == ""){ descripcion = usuario.getDescripcion();}
            if(edad == 0){ edad = usuario.getEdad();}
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

/**
 * Funcion que sirve para modificar la info de un contacto
 * @param usuario usuario del que queremos modificar el contacto
 * @param infoNueva informacion nueva que queremos cambiar
 * @param email email del contacto que queremos cambiar
 */
void modificarInfoDeContacto(Usuario& usuario, string infoNueva, string email){
    bool found = false;
    for (int i = 0; i < usuario.getContactos().size(); ++i) {
        if (email == usuario.getContactos().at(i)->getDato().getEmail()) {
            auto  aux = new Contacto(usuario.getContactos().at(i)->getDato().getEmail(), infoNueva);
            usuario.getContactos().eliminarDato(usuario.getContactos().at(i)->getDato());
            try {
                usuario.getContactos().insertFinal(*aux);
            } catch (...) {
                cerr << "No se ha podido insertar" << endl;
            }
            found = true;
        }
    }
    if (!found) {
        cout << "No se ha encontrado" << endl;
    }
}

#endif //GRUPO3_ACT4_USUARIO_H
