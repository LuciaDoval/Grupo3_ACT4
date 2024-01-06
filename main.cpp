#include <iostream>
#include "Usuario.h"
#include "Contacto.h"
#include "ListaEnlazada.h"
#include <limits> // para el correcto funcionamiento del try catch
#include <stdexcept>

using namespace std;
/**
 * Funcion que importa y exporta los contactos de un usuarioAc a otro
 * @param usuarios lista de usuarios
 * @param usuarioAc usuarioAc que realiza la operacion
*/
void importarYExportar(ListaEnlazada<Usuario>& usuarios, Usuario& usuario) {
    bool seguir = true;
    Usuario usuarioEx;
    Usuario usuarioIm;
    Usuario usuarioAc = usuario;

    while (seguir) {
        try {
            int seleccion;
            string email;
            cout << "Quieres Importar o exportar? \n1. importar \n2. exportar \n3. Salir" << endl;

            if (!(cin >> seleccion)) {
                throw runtime_error("Escribe un numero del 1 al 3");
            }

            switch (seleccion) {
                case 1:
                    cout << "De que usuario quieres importar contactos?" << endl;
                    if (!(cin >> email)) {
                        throw runtime_error("El email no se ha guardado adecuadamente");
                    }
                    usuarioEx = buscarEmail(email, usuarios);

                    for (int i = 0; i < usuarioEx.getContactos().size(); ++i) {
                        if (!buscarEmailBool(usuarioEx.getContactos().at(i)->getDato().getEmail(), usuarioAc.getContactos())) {
                            Contacto nuevoContacto = usuarioEx.getContactos().at(i)->getDato();
                            usuarioAc.getContactos().insertFinal(nuevoContacto);
                        }
                    }
                    cout <<"Se han importado correctamente" <<endl;
                    break;

                case 2:
                    cout << "A que usuario quieres exportar tus contactos?" << endl;
                    if (!(cin >> email)) {
                        throw runtime_error("El email no se ha guardado adecuadamente");
                    }
                    usuarioIm = buscarEmail(email, usuarios);

                    for (int i = 0; i < usuarioAc.getContactos().size(); ++i) {
                        if (!buscarEmailBool(usuarioAc.getContactos().at(i)->getDato().getEmail(), usuarioIm.getContactos())) {
                            Contacto nuevoContacto = usuarioAc.getContactos().at(i)->getDato();
                            usuarioIm.getContactos().insertFinal(nuevoContacto);
                        }
                    }
                    cout <<"Se han exportado correctamente" <<endl;
                    break;

                case 3:
                    cout << "Volviendo al menu anterior..." <<endl;
                    seguir = false;
                    break;

                default:
                    throw runtime_error("Escribe un numero del 1 al 3");
            }
        } catch (const runtime_error &e) {
            cerr << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    }

}

int main() {
    bool noAcept = true, contra = true;
    int opcion, edad, genero, intentos = 0;
    string email, cont, apodo, desc, info, contacto;
    Usuario *nuevoUsuario;
    Contacto *contacto123;


    //Usuarios pre-Guardados

    Usuario *usuario1 = new Usuario("luciadoval1@gmail.com", "Lu", "wubbaLubbaDubDub",
                                    "Tengo 19 anhos, me gusta el anime, jugar videojuegos y la inforamtica", 19,
                                    Genero::Femenino);
    Usuario *usuario2 = new Usuario("sergiomazahg@gmail.com", "Mazita", "69",
                                    "Me gustan las motos y los videojuegos, me gusta emplear mi tiempo libre en aprender cosas nuevas como por ejemplo como programar aplicaciones web",
                                    19, Genero::Masculino);
    Usuario *usuario3 = new Usuario("vidhi@gmail.com", "vidhi", "soyvidhi1234", "Me gusta leer y el lol", 19,
                                    Genero::Femenino);
    Usuario *usuario4 = new Usuario("victor@gmail.com", "victor", "soyvictor1234", "Me gusta el baloncesto y el lol",
                                    19,
                                    Genero::Masculino);
    Usuario *usuario5 = new Usuario("clau@gmail.com", "clau", "1234", "Me gustan los gatos", 19, Genero::Otros);
    Usuario *usuario6 = new Usuario("NoSoyUnBot@gmail.com", "NoSoyUnBot", "NoSoyUnBot",
                                    "Me interesan todas las cosas tipicas", 25,
                                    Genero::Otros);
    Usuario *usuario7 = new Usuario("ricksanchez@gmail.com", "Rick", "6969", "Soy un cientifico borracho", 65,
                                    Genero::Masculino);
    Usuario *usuario8 = new Usuario("CoolDude@gmail.com", "CoolDude", "QueEsContrasenha",
                                    "Me llamo papyrus, soy un gran cocinero, miembro de la guardia real y soy un tio muy guay",
                                    0,
                                    Genero::Otros);
    Usuario *usuario9 = new Usuario("Fabian@gmail.com", "Fabian", "1234", "Busco chicas que respiren(opcional)", 19,
                                    Genero::Masculino);
    Usuario *usuario10 = new Usuario("kimPosible@gmail.com", "Kim", "1234", "Llama, grita, si me necesitas", 16,
                                     Genero::Femenino);

    Contacto *c1 = new Contacto("sergiomazahg@gmail.com", "Mi amigo Sergio de la uni");
    Contacto *c2 = new Contacto("vidhi@gmail.com", "Mi amiga de la uni");
    Contacto *c3 = new Contacto("victor@gmail.com", "Mi amigo victor de la uni");
    Contacto *c4 = new Contacto("clau@gmail.com", "mi prima");
    Contacto *c5 = new Contacto("Fabian@gmail.com", "Fabian de la uni");
    Contacto *c6 = new Contacto("ricksanchez@gmail.com", "Rick Sanchez");

    ListaEnlazada<Contacto> *lista1 = new ListaEnlazada<Contacto>();
    lista1->insertFinal(*c1);
    lista1->insertFinal(*c2);
    lista1->insertFinal(*c3);
    lista1->insertFinal(*c4);
    lista1->insertFinal(*c5);
    lista1->insertFinal(*c6);

    usuario1->setContactos(lista1);

    Contacto *co1 = new Contacto("luciadoval1@gmail.com", "Mi amiga de la uni");
    Contacto *co2 = new Contacto("vidhi@gmail.com", "Vidhi de la uni");
    Contacto *co3 = new Contacto("victor@gmail.com", "victor de rivas");
    Contacto *co4 = new Contacto("clau@gmail.com", "la prima de lu");
    Contacto *co5 = new Contacto("Fabian@gmail.com", "Fabian de la uni");
    Contacto *co6 = new Contacto("CoolDude@gmail.com", "Papyrus de snowdin");
    Contacto *co7 = new Contacto("ricksanchez@gmail.com", "rick sanchez de la c-137");

    ListaEnlazada<Contacto> *lista2 = new ListaEnlazada<Contacto>();
    lista2->insertFinal(*co1);
    lista2->insertFinal(*co2);
    lista2->insertFinal(*co3);
    lista2->insertFinal(*co4);
    lista2->insertFinal(*co5);
    lista2->insertFinal(*co6);
    lista2->insertFinal(*co7);

    usuario2->setContactos(lista2);

    Contacto *con1 = new Contacto("luciadoval1@gmail.com", "Mi amiga de la uni");
    Contacto *con2 = new Contacto("sergiomazahg@gmail.com", "Sergio de la uni");
    Contacto *con3 = new Contacto("victor@gmail.com", "companhero de clase");
    Contacto *con4 = new Contacto("clau@gmail.com", "la prima de lu");
    Contacto *con5 = new Contacto("Fabian@gmail.com", "Fabian de la uni");

    ListaEnlazada<Contacto> *lista3 = new ListaEnlazada<Contacto>();
    lista3->insertFinal(*con1);
    lista3->insertFinal(*con2);
    lista3->insertFinal(*con3);
    lista3->insertFinal(*con4);
    lista3->insertFinal(*con5);

    usuario3->setContactos(lista3);

    Contacto *cont1 = new Contacto("luciadoval1@gmail.com", "Mi amiga de la uni");
    Contacto *cont2 = new Contacto("sergiomazahg@gmail.com", "Sergio de rivas");
    Contacto *cont3 = new Contacto("vidhi@gmail.com", "Companhera de clase");
    Contacto *cont5 = new Contacto("Fabian@gmail.com", "Fabian de la uni");

    ListaEnlazada<Contacto> *lista4 = new ListaEnlazada<Contacto>();
    lista4->insertFinal(*cont1);
    lista4->insertFinal(*cont2);
    lista4->insertFinal(*cont3);
    lista4->insertFinal(*cont5);

    usuario4->setContactos(lista4);

    ListaEnlazada<Usuario> *listaDeUsuarios = new ListaEnlazada<Usuario>();
    listaDeUsuarios->insertFinal(*usuario1);
    listaDeUsuarios->insertFinal(*usuario2);
    listaDeUsuarios->insertFinal(*usuario3);
    listaDeUsuarios->insertFinal(*usuario4);
    listaDeUsuarios->insertFinal(*usuario5);
    listaDeUsuarios->insertFinal(*usuario6);
    listaDeUsuarios->insertFinal(*usuario7);
    listaDeUsuarios->insertFinal(*usuario8);
    listaDeUsuarios->insertFinal(*usuario9);
    listaDeUsuarios->insertFinal(*usuario10);


    cout << "------------------------------" << endl;
    cout << "         Bienvenido a " << endl;
    cout << "             Tinder" << endl;
    cout << "------------------------------" << endl;

    cout << endl;
    cout << endl;
    while (noAcept) {
        try {
            cout << "Aceptas la politica de privacidad? \n1. Si \n2. Si" << endl;
            if (!(cin >> opcion)) {
                throw runtime_error("Tienes que escribir un numero del 1 al 2");
            }
            if (opcion != 1 && opcion != 2) {
                throw runtime_error("Por favor acepta la politica de privacidad");
            } else { noAcept = false; }

        } catch (const runtime_error &e) {
            cerr << e.what() << endl;
            cin.clear(); // Restablece el valor del cin
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar el buffer
        }
    }


    cin.clear();
    noAcept = true;

    cout << endl;
    cout << endl;

    cout << "Gracias por aceptar la politica de privacidad! :D" << endl;

    cout << endl;
    cout << endl;
    while (noAcept) {
        try {
            cout << "-------------------" << endl;
            cout << "       Login" << endl;
            cout << "-------------------" << endl;
            cout << endl;
            intentos = 0;
            cout << "Por favor escribe tu email: (si no tienes email escribe 1) " << endl;
            if (!(cin >> email)) {
                throw runtime_error("Lo siento, tu email no se ha guardado adecuadamente");
            }

            if (email == "1") {
                cout << "-------------------" << endl;
                cout << "     Register" << endl;
                cout << "-------------------" << endl;

                cout << "Por favor escribe tu email: " << endl;
                if (!(cin >> email)) {
                    throw runtime_error("Lo siento, tu email no se ha guardado adecuadamente");
                }
                if (buscarEmailBool1(email, *listaDeUsuarios)){
                    throw runtime_error("Este email no esta disponible");
                }

                cout << "Por favor escribe una contrasenha: " << endl;
                if (!(cin >> cont)) {
                    throw runtime_error("Lo siento, tu contrasenha no se ha guardado adecuadamente");
                }

                cout << "Por favor escribe un apodo: " << endl;
                if (!(cin >> apodo)) {
                    throw runtime_error("Lo siento, tu apodo no se ha guardado adecuadamente");
                }

                cout << "Por favor escribe una descripcion:" << endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                getline(cin, desc);

                cout << "Por favor escribe una edad: " << endl;
                if (!(cin >> edad)) {
                    throw runtime_error("Lo siento, tu edad no se ha guardado adecuadamente, escribe un numero");
                }
                if (edad < 0 || edad > 100) {
                    throw runtime_error("Tienes que ingresar una edad valida");
                }

                cout << "Cual es tu genero? 1.Mujer 2.Hombre 3.Otro" << endl;
                if (!(cin >> genero)) {
                    throw runtime_error(
                            "Lo siento, tu genero no se ha guardado adecuadamente, escribe un numero del 1 al 3");
                }

                switch (genero) {
                    case 1:
                        nuevoUsuario = new Usuario(email, apodo, cont, desc, edad, Genero::Femenino);
                        listaDeUsuarios->insertFinal(*nuevoUsuario);
                        break;
                    case 2:
                        nuevoUsuario = new Usuario(email, apodo, cont, desc, edad, Genero::Masculino);
                        listaDeUsuarios->insertFinal(*nuevoUsuario);
                        break;
                    case 3:
                        nuevoUsuario = new Usuario(email, apodo, cont, desc, edad, Genero::Otros);
                        listaDeUsuarios->insertFinal(*nuevoUsuario);
                        break;
                    default:
                        throw runtime_error(
                                "Lo siento, tu genero no se ha guardado adecuadamente, escribe un numero del 1 al 3");
                }

            } else {
                Usuario actual = buscarEmail(email, *listaDeUsuarios);

                while (contra) {
                    if (intentos >= 3) {
                        throw runtime_error("Lo siento, te has quedado sin intentos");
                    }
                    cout << "Por favor escribe tu contrasenha: " << endl;
                    if (!(cin >> cont)) {
                        throw runtime_error("Lo siento, tu contrasenha no se ha guardado adecuadamente");
                    }
                    if (cont == actual.getContrasenha()) {
                        cout << "Bienvenido de nuevo " << actual.getApodo() << endl;
                        noAcept = false;
                        contra = false;

                    } else {
                        intentos++;
                        cout << "Contrasenha incorrecta" << endl;
                    }
                }


            }


        } catch (const runtime_error &e) {
            cerr << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        };
    }

    Usuario &referencia = buscarEmail(email, *listaDeUsuarios);

    Usuario *actual1 = &referencia;

    cout << endl;
    cout << endl;

    cout << "------------------------------------------------" << endl;
    cout << actual1->getApodo() << endl;
    cout << "------------------------------------------------" << endl;

    contra = true;
    cout << endl;
    cout << endl;

    while (contra) {
        try {
            cout << endl;
            cout << "--------------" << endl;
            cout
                    << "Que quieres hacer? \n1. Ver mi perfil \n2. Modificar mi perfil \n3. Ver mis contactos \n4. Modificar informacion de contacto \n5. Ver todos los usuarios \n6. Buscar nuevos contactos \n7. Agregar nuevos contactos \n8. Eliminar Contactos \n9. Exportar e importar contactos \n10. Salir"
                    << endl;
            if (!(cin >> opcion)) {
                throw runtime_error("Tienes que escribir un numero del 1 al 10");
            }

            switch (opcion) {
                case 1:
                    cout << *actual1 << endl;
                    break;
                case 2:
                    cout << endl;
                    cout << "--------------" << endl;
                    cout
                            << "Que quieres actualizar? \n1. Apodo \n2. Email \n3. Contrasenha \n4. Descripcion \n5. Edad \n6. Salir"
                            << endl;
                    if (!(cin >> opcion)) {
                        throw runtime_error("Tienes que escribir un numero del 1 al 7");
                    }

                    switch (opcion) {
                        case 1:
                            cout << "Escribe tu nuevo apodo" << endl;
                            if (!(cin >> apodo)) {
                                throw runtime_error("Tu apodo no se ha guardado adecuadamente");
                            }
                            if (apodo == actual1->getApodo()) {
                                throw runtime_error("Escribe un apodo distinto al actual1");
                            }
                            actualizarUsuario("", apodo, "", "", 0, *actual1, *listaDeUsuarios);
                            break;
                        case 2:
                            cout << "Escribe tu nuevo email" << endl;
                            if (!(cin >> email)) {
                                throw runtime_error("Tu email no se ha guardado adecuadamente");
                            }
                            if (email == actual1->getEmail()) {
                                throw runtime_error("Escribe un email distinto al actual1");
                            }
                            if (buscarEmailBool1(email, *listaDeUsuarios)){
                                throw runtime_error("Este email no esta disponible");
                            }
                            actualizarUsuario(email, "", "", "", 0, *actual1, *listaDeUsuarios);
                            break;
                        case 3:
                            cout << "Escribe tu nueva contrasenha" << endl;
                            if (!(cin >> cont)) {
                                throw runtime_error("No se ha podido guardar la contrasenha");
                            }
                            if (cont == actual1->getContrasenha()) {
                                throw runtime_error("Escribe una contrasenha distinta a la actual1 actual1");
                            }
                            actualizarUsuario("", "", cont, "", 0, *actual1, *listaDeUsuarios);
                            break;
                        case 4:
                            cout << "Escribe tu nueva descripcion" << endl;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            getline(cin, desc);
                            if (desc == actual1->getDescripcion()) {
                                throw runtime_error("Escribe una descripcion distinta a la actual1");
                            }
                            actualizarUsuario("", "", "", desc, 0, *actual1, *listaDeUsuarios);
                            break;
                        case 5:
                            cout << "Escribe tu nueva edad" << endl;
                            if (!(cin >> edad)) {
                                throw runtime_error(
                                        "Tu edad no se ha guardado adeccuadamente, por favor escribe un numero");
                            }
                            if (edad == actual1->getEdad()) {
                                throw runtime_error("Escribe una edad distinto al actual1");
                            }
                            actualizarUsuario("", "", "", "", edad, *actual1, *listaDeUsuarios);
                            break;
                        case 6:
                            cout << "Volviendo al menu anterior..." << endl;
                            break;
                        default:
                            throw runtime_error("Tienes que escribir un numero del 1 al 7");
                    }

                    break;
                case 3:
                    actual1->getContactos().print();
                    break;
                case 4:
                    //Este codigo tiene un bad alloc
                    cout << endl;
                    cout << "--------------" << endl;
                    cout << "Escribe el email del contacto que quieres modificar:" << endl;
                    if (!(cin >> contacto)) {
                        throw runtime_error("El email del contacto no se ha guardado adecuadamente");
                    }
                    if (busquedaDeContacto(contacto, actual1->getContactos()) == -1) {
                        throw runtime_error("Ese email no existe entre tus contactos");
                    } else {
                        cout << "Su informacion actual es: " << actual1->getContactos().at(
                                busquedaDeContacto(contacto, actual1->getContactos()))->getDato() << endl;
                        cout << "Escribe su nueva informacion: " << endl;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        getline(cin, info);
                        if (info == actual1->getContactos().at(
                                busquedaDeContacto(contacto, actual1->getContactos()))->getDato().getInfo()) {
                            throw runtime_error("Escribe su nueva informacion distinta a la anterior");
                        }
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        modificarInfoDeContacto(*actual1, info, contacto);
                    }

                    break;
                case 5:
                    listaDeUsuarios->print();
                    break;
                case 6:
                    cout << endl;
                    cout << "--------------" << endl;
                    cout << "Como quieres buscar? \n1. Por Email \n2. Por apodo \n3. Por Edad \n4. Por genero \n5. Salir"
                         << endl;
                    if (!(cin >> opcion)) {
                        throw runtime_error("Tienes que escribir un numero del 1 al 5");
                    }
                    switch (opcion) {
                        case 1:
                            cout << "Escribe el email que quieres buscar:" << endl;
                            if (!(cin >> email)) {
                                throw runtime_error("No se ha guardado bien el email");
                            }
                            cout << buscarEmail(email, *listaDeUsuarios) << endl;

                            break;
                        case 2:
                            cout << "Escribe el apodo que quieres buscar: " << endl;
                            if (!(cin >> apodo)) {
                                throw runtime_error("No se ha guardado bien el apodo");
                            }
                            buscarApodo(apodo, *listaDeUsuarios);
                            break;
                        case 3:
                            cout << "Escribe la edad que quieres buscar: " << endl;
                            if (!(cin >> edad)) {
                                throw runtime_error("No se ha guardado la edad correctamente");
                            }
                            if (edad < 0 || edad > 100) {
                                throw runtime_error("Tienes que ingresar una edad valida");
                            }
                            buscarEdad(edad, *listaDeUsuarios);
                            break;
                        case 4:
                            cout << "Que genero quieres buscar? \n1. Mujer \n2. Hombre \n3. Otro" << endl;
                            if (!(cin >> opcion)) {
                                throw runtime_error("Tienes que escribir un numero del 1 al 3");
                            }
                            switch (opcion) {
                                case 1:
                                    buscarGenero(Genero::Femenino, *listaDeUsuarios);
                                    break;
                                case 2:
                                    buscarGenero(Genero::Masculino, *listaDeUsuarios);
                                    break;
                                case 3:
                                    buscarGenero(Genero::Otros, *listaDeUsuarios);
                                    break;
                                default:
                                    throw runtime_error("Tienes que escribir un numero del 1 al 3");
                            }
                            break;
                        case 5:
                            cout << "Volviendo al menu anterior..." << endl;
                            break;
                        default:
                            throw runtime_error("Tienes que escribir un numero del 1 al 5");

                    }
                    break;
                case 7:
                    cout << endl;
                    cout << "--------------" << endl;
                    cout << "Escribe el email del contacto que quieres agregar:" << endl;
                    if (!(cin >> contacto)) {
                        throw runtime_error("El email del contacto no se ha guardado adecuadamente");
                    }
                    buscarEmail(contacto, *listaDeUsuarios);
                    cout << "Escribe la info del contacto que quieres agregar: " << endl;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    getline(cin, info);
                    contacto123 = new Contacto(contacto, info);
                    actual1->getContactos().insertFinal(*contacto123);
                    break;
                case 8:
                    cout << endl;
                    cout << "--------------" << endl;
                    cout << "Escribe el email del contacto que quieres eliminar:" << endl;
                    if (!(cin >> contacto)) {
                        throw runtime_error("El email del contacto no se ha guardado adecuadamente");
                    }
                    if (busquedaDeContacto(contacto, actual1->getContactos()) == -1) {
                        throw runtime_error("Este usuario no esta en tu lista de contactos");
                    } else {
                        actual1->getContactos().eliminarDato(actual1->getContactos().at(
                                busquedaDeContacto(contacto, actual1->getContactos()))->getDato());
                    }

                    break;
                case 9:
                    importarYExportar(*listaDeUsuarios, *actual1);
                    break;
                case 10:
                    delete usuario1;
                    delete usuario2;
                    delete usuario3;
                    delete usuario4;
                    delete usuario5;
                    delete usuario6;
                    delete usuario7;
                    delete usuario8;
                    delete usuario9;
                    delete usuario10;

                    delete c1;
                    delete c2;
                    delete c3;
                    delete c4;
                    delete c5;
                    delete c6;

                    delete lista1;
                    delete lista2;
                    delete lista3;
                    delete lista4;

                    delete listaDeUsuarios;

                    cout << "Hasta la proxima!" << endl;
                    contra = false;
                    break;
                default:
                    throw runtime_error("Tienes que escribir un numero del 1 al 9");
            }
        } catch (const runtime_error &e) {
            cerr << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        };
    }

    return 0;
};
