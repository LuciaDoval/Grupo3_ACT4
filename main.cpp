#include <iostream>
#include "Usuario.h"
#include "Contacto.h"
#include "ListaEnlazada.h"

int main() {
    //std::cout << "Hello, World!" << std::endl;
    //return 0;

    ListaEnlazada<Usuario> usuarios;
    Usuario *usuario1 = new Usuario("a", "jef", "123c", "hola", 2, Femenino);
    usuario1->anhadirUsuario(*usuario1);
    usuarios.insertFinal(*usuario1);

    Usuario *usuario2 = new Usuario("s", "bob", "321c", "adios", 4, Masculino);
    usuario2->anhadirUsuario(*usuario2);
    usuarios.insertFinal(*usuario2);
    cout << "-----------------" << endl;
    usuario1->leerUsuario();
    cout << "-----------------" << endl;
    usuario2->leerUsuario();
    cout << "-----------------" << endl;

    usuario1->buscarEmail("a", usuarios);
    cout << "-----------------" << endl;
    usuario1->actualizarUsuario("a", Usuario("d", "jef", "123c", "holi", 2, Femenino));
    usuario1->leerUsuario();
    cout << "-----------------" << endl;
    usuario2->eliminarUsuario("s");
    usuario2->leerUsuario();




}
