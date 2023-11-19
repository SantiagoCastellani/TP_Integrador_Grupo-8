#include <iostream>
#include "menu.h"
#include"Libro.h"
#include"Genero.h"
#include"Editorial.h"
#include "Autor.h"
#include "LibroService.h"
#include "VentasService.h"
#include "ClienteService.h"
#include "Config.h"

ClienteService clienteService;
VentasService ventasService;
LibroService libroService;
Genero gServ;
Editorial eServ;
Autor aServ;
Config configService;


/*************************************************************************************/

/// MENU INICIAL

void menuInicio(){
    system("cls");
    int opcion;
    std::cout<<"*************************************************"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<" Sistema de Gestion de Ventas de Libros"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\tLibreria IOSTREAM"<<std::endl;
    std::cout<<" "<<std::endl;std::cout<<" "<<std::endl;
    std::cout<<"\t1 - LIBROS"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t2 - VENTAS"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t3 - CLIENTES"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t4 - ESTADISTICAS"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t5 - CONFIGURACIONES"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t0 - Salir"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"*************************************************"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<" \t Elija una opcion: ";
    std::cin>>opcion;
    std::cout<<" "<<std::endl;
    std::cout<<"*************************************************"<<std::endl;
    switch(opcion){
    case 1:
        menuLibros();
        break;
    case 2:
        menuVentas();
        break;
    case 3:
        menuClientes();
        break;
    case 4:
        menuEstadisticas();
        break;
    case 5:
        menuConfiguraciones();
        break;
    case 0:
        finalizar();
        break;
    default:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tOpcion Incorrecta, ingrese otra opcion."<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        system("pause");
        menuInicio();
        break;
    }
}

/****************************************************************************************/

/// MENU LIBROS

void menuLibros(){
    int opcion;
    system("cls");
    std::cout<<"*************************************************"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\tLibreria IOSTREAM"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\tMenu LIBROS"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t1 - BUSCAR LIBRO"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t2 - CARGAR LIBRO"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t3 - MODIFICAR LIBRO"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t4 - LISTADO DE LIBROS"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t5 - CONFIGURACION DE GENERO, EDITORIALES Y AUTORES"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t0 - Regresar al menu anterior"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"*************************************************"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<" \t Elija una opcion: ";
    std::cin>>opcion;
    switch(opcion){
    case 1:
        menuBuscarLibro();
        break;
    case 2:
        menuCargarLibro();
        break;
    case 3:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tMODIFICAR LIBRO"<<std::endl;
        std::cout<<" "<<std::endl;
        libroService.modificarLibro();
        system("pause");
        menuLibros();
        break;
    case 4:
        menuListadoLibros();
        break;
    case 5:
        menuConfiguracionesGEA();
        break;
    case 0:
        menuInicio();
        break;
    default:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tOpcion Incorrecta, ingrese otra opcion."<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        system("pause");
        menuLibros();
        break;
};
}

/// Menu BUSCAR LIBRO -----------------------------

void menuBuscarLibro(){
    int opcion;
    system("cls");
    std::cout<<"*************************************************"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\tLibreria IOSTREAM"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\tMenu BUSCAR LIBRO"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t1 - BUSQUEDA POR TITULO"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t2 - BUSQUEDA POR CODIGO de AUTOR"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t0 - Regresar al menu anterior"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"*************************************************"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<" \t Elija una opcion: ";
    std::cin>>opcion;
    switch(opcion){
    case 1:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tBUSCAR LIBRO por TITULO"<<std::endl;
        std::cout<<" "<<std::endl;
        libroService.buscarLibroTitulo();
        system("pause");
        menuBuscarLibro();
        break;
     case 2:
        system("cls");
        std::cin.ignore();
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tBUSCAR LIBRO por AUTOR"<<std::endl;
        std::cout<<"\t(Primeras 2 letras del nombre y primeras 2 letras del apellido)"<<std::endl;
        std::cout<<" "<<std::endl;
        libroService.buscarLibroCodAutor();
        system("pause");
        menuBuscarLibro();
        break;
    case 0:
        menuLibros();
        break;
    default:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tOpcion Incorrecta, ingrese otra opcion."<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        system("pause");
        menuBuscarLibro();
        break;
  };
}

/// Menu CARGAR LIBRO -----------------------------

void menuCargarLibro(){
    int opcion;
    system("cls");
    std::cin.ignore();
    std::cout<<"*************************************************"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\tLibreria IOSTREAM"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\tCARGAR LIBRO"<<std::endl;
    Libro libro = libroService.cargarLibro();
    std::cout<<" "<<std::endl;
    std::cout<<"\tLIBRO CARGADO: "<<std::endl;
    libroService.mostrarLibro(libro);
    std::cout<<" "<<std::endl;
    std::cout<<"Desea registrarlo? (1=SI / 0=NO):   ";
    std::cin>>opcion;
    switch(opcion){
    case 1:
        libroService.registrarLibro(libro);
        std::cout<<" "<<std::endl;
        std::cout<<"El libro ha sido registrado."<<std::endl;
        std::cout<<" "<<std::endl;
        system("pause");
        menuLibros();
        break;
    case 0:
        std::cout<<" "<<std::endl;
        std::cout<<"El libro NO se ha registrado."<<std::endl;
        std::cout<<" "<<std::endl;
        system("pause");
        menuLibros();
        break;
    default:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tOpcion Incorrecta, ingrese otra opcion."<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        system("pause");
        menuCargarLibro();
        break;
    }
}

/// Menu LISTADO de LIBROS -----------------------------

void menuListadoLibros(){
    int opcion;
    system("cls");
    std::cin.ignore();
    std::cout<<"*************************************************"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\tLibreria IOSTREAM"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\tMenu LISTADO de LIBROS"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t1 - Listar por GENERO"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t2 - Listar por EDITORIAL"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t3 - Listar por TITULO de la A a la Z (Info basica)"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t4 - Listar TODOS"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t0 - Regresar al menu anterior"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"*************************************************"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<" \t Elija una opcion: ";
    std::cin>>opcion;
    switch(opcion){
    case 1:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tListado por GENERO"<<std::endl;
        std::cout<<" "<<std::endl;
        libroService.listarPorGenero();
        system("pause");
        menuListadoLibros();
        break;
    case 2:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tListado por EDITORIAL"<<std::endl;
        std::cout<<" "<<std::endl;
        libroService.listarPorEditorial();
        system("pause");
        menuListadoLibros();
    case 3:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tListado por TITULO de la A a la Z"<<std::endl;
        std::cout<<" "<<std::endl;
        libroService.listarPorTituloAZ();
        std::cout<<" "<<std::endl;
        system("pause");
        menuListadoLibros();
    case 4:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tListado TODOS"<<std::endl;
        std::cout<<" "<<std::endl;
        libroService.listarLibrosTodos();
        std::cout<<" "<<std::endl;
        system("pause");
        menuListadoLibros();
    case 0:
        menuLibros();
        break;
    default:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tOpcion Incorrecta, ingrese otra opcion."<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        system("pause");
        menuListadoLibros();
        break;
    }
}

/// MENU Configuraciones GEA -------------------------------------------

void menuConfiguracionesGEA(){
    int opcion;
    system("cls");
    std::cin.ignore();
    std::cout<<"*************************************************"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\tLibreria IOSTREAM"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\tMenu CONFIGURACIONES GEA"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t1 - Configuracion GENERO"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t2 - Configuracion AUTOR"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t3 - Configuracion EDITORIAL"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t0 - Regresar al menu anterior"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"*************************************************"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<" \t Elija una opcion: ";
    std::cin>>opcion;
    switch(opcion){
    case 1:
        menuConfiguracionGenero();
        break;
    case 2:
        menuConfiguracionAutor();
        break;
    case 3:
        menuConfiguracionEditorial();
        break;
    case 0:
        menuLibros();
        break;
    default:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tOpcion Incorrecta, ingrese otra opcion."<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        system("pause");
        menuConfiguracionesGEA();
        break;
  }
}

/// MENU Configuraciones GENERO -----------------------------------------

void menuConfiguracionGenero(){
    int opcion;
    system("cls");
    std::cout<<"*************************************************"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\tLibreria IOSTREAM"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\tConfiguracion de GENEROS"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t1 - Listar GENEROS"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t2 - Cargar GENERO"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t3 - Modificar GENERO"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t0 - Regresar al menu anterior"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"*************************************************"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<" \t Elija una opcion: ";
    std::cin>>opcion;
    std::cin.ignore();
    Genero genero;
    switch(opcion){
    case 1:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tListado de GENEROS ACTIVOS:"<<std::endl;
        std::cout<<" "<<std::endl;
        gServ.leerArchivoGenerosActivos();
        std::cout<<" "<<std::endl;
        gServ.leerArchivoGenerosInactivos();
        std::cout<<" "<<std::endl;
        system("pause");
        menuConfiguracionGenero();
        break;
    case 2:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tCargar nuevo GENERO:"<<std::endl;
        std::cout<<" "<<std::endl;
        genero = gServ.cargarGenero();
        gServ.registrarGenero(genero);
        std::cout<<" "<<std::endl;
        std::cout<<" El Genero ha sido registrado."<<std::endl;
        std::cout<<" "<<std::endl;
        system("pause");
        menuConfiguracionGenero();
        break;
    case 3:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tModificar GENERO:"<<std::endl;
        std::cout<<" "<<std::endl;
        gServ.modificarGenero();
        std::cout<<" "<<std::endl;
        menuConfiguracionGenero();
        break;
    case 0:
        menuLibros();
        break;
    default:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tOpcion Incorrecta, ingrese otra opcion."<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        system("pause");
        menuConfiguracionGenero();
        break;
  }
}

/// MENU Configuraciones AUTOR ---------------------------------------------------

void menuConfiguracionAutor(){
    int opcion;
    system("cls");
    std::cout<<"*************************************************"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\tLibreria IOSTREAM"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\tConfiguracion de AUTORES"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t1 - Listar AUTORES"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t2 - Cargar AUTOR"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t3 - Modificar AUTOR"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t0 - Regresar al menu anterior"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"*************************************************"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<" \t Elija una opcion: ";
    std::cin>>opcion;
    std::cin.ignore();
    Autor autor;
    switch(opcion){
    case 1:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tListado de AUTORES:"<<std::endl;
        std::cout<<" "<<std::endl;
        aServ.leerArchivoAutor();
        std::cout<<" "<<std::endl;
        system("pause");
        menuConfiguracionAutor();
        break;
    case 2:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tCargar Nuevo AUTOR:"<<std::endl;
        std::cout<<" "<<std::endl;
        autor = aServ.cargarAutor();
        aServ.registrarAutor(autor);
        std::cout<<" "<<std::endl;
        std::cout<<" El Autor ha sido registrado."<<std::endl;
        std::cout<<" "<<std::endl;
        system("pause");
        menuConfiguracionAutor();
        break;
    case 3:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tModificar AUTOR:"<<std::endl;
        std::cout<<" "<<std::endl;
        aServ.modificarAutor();
        std::cout<<" "<<std::endl;
        menuConfiguracionAutor();
        break;
    case 0:
        menuLibros();
        break;
    default:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tOpcion Incorrecta, ingrese otra opcion."<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        system("pause");
        menuConfiguracionAutor();
        break;
  }
}

/// MENU Configuraciones EDITORIAL -------------------------------------------------

void menuConfiguracionEditorial(){
    int opcion;
    system("cls");
    std::cout<<"*************************************************"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\tLibreria IOSTREAM"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\tConfiguracion de EDITORIALES"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t1 - Listar EDITORIALES"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t2 - Cargar EDITORIAL"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t3 - Modificar EDITORIAL"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t0 - Regresar al menu anterior"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"*************************************************"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<" \t Elija una opcion: ";
    std::cin>>opcion;
    std::cin.ignore();
    Editorial editorial;
    switch(opcion){
    case 1:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tListado de EDITORIALES ACTIVAS:"<<std::endl;
        std::cout<<" "<<std::endl;
        eServ.leerArchivoEditorial();
        std::cout<<" "<<std::endl;
        system("pause");
        menuConfiguracionEditorial();
        break;
    case 2:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tCargar nueva EDITORIAL:"<<std::endl;
        std::cout<<" "<<std::endl;
        editorial = eServ.cargarEditorial();
        eServ.registrarEditorial(editorial);
        std::cout<<" "<<std::endl;
        std::cout<<" La Editorial ha sido registrada."<<std::endl;
        std::cout<<" "<<std::endl;
        system("pause");
        menuConfiguracionEditorial();
        break;
    case 3:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tModificar EDITORIAL:"<<std::endl;
        std::cout<<" "<<std::endl;
        eServ.modificarEditorial();
        std::cout<<" "<<std::endl;
        menuConfiguracionEditorial();
        break;
    case 0:
        menuLibros();
        break;
    default:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tOpcion Incorrecta, ingrese otra opcion."<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        system("pause");
        menuConfiguracionEditorial();
        break;
    }
}


///*************************************************************************************

/// VENTAS

///Menu Ventas
void menuVentas(){
    int opcion;
    system("cls");
    std::cout<<"*************************************************"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\tLibreria IOSTREAM"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\tMenu VENTAS"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t1 - CARGAR UNA VENTA"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t2 - BUSCAR DETALLE DE VENTA"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t3 - LISTADO DE VENTAS"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t0 - Regresar al menu anterior"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"*************************************************"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<" \t Elija una opcion: ";
    std::cin>>opcion;
    switch(opcion){
    case 1:
        menuCargarVenta();
        break;
    case 2:
        menuDetalleVenta();
        break;
    case 3:
        menuListadoVentas();
        break;
    case 0:
        menuInicio();
        break;
    default:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tOpcion Incorrecta, ingrese otra opcion."<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        system("pause");
        menuVentas();
        break;
};
}

/// Menu Cargar VENTA
void menuCargarVenta(){
    Venta venta;
    int opcion;
    system("cls");
    std::cout<<"*************************************************"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\tLibreria IOSTREAM"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\tCARGAR VENTA de LIBRO:"<<std::endl;
    std::cout<<" "<<std::endl;
    venta = ventasService.cargarVentaDesdeMenu();
    std::cout<<"\tSe ha cargado la siguiente venta:"<<std::endl;
    ventasService.mostrarVenta(venta);
    std::cout<<" "<<std::endl;
    std::cout<<"\tDesea registrarla? (1=SI / 2=NO) "<<std::endl;
    std::cin>>opcion;
    std::cout<<" "<<std::endl;
    if(opcion==1){
        ventasService.registrarVenta(venta);
        libroService.reducirStock(venta.getIdLibro());
        std::cout<<"\tVENTA REGISTRADA - Nro: "<<venta.getIdVenta()<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tDesea Imprimir el Ticket? (1=SI / 0=NO) "<<std::endl;
        int imprimir;
        std::cin>>imprimir;
        std::cout<<" "<<std::endl;
        if(imprimir==1){
            ventasService.imprimirBoleta(venta.getIdVenta());
        } else {
            std::cout<<"\tVolver al menu."<<std::endl;
        }
    } else {
        std::cout<<"\tVolver al menu."<<std::endl;
    }
    system("pause");
    menuVentas();
}

/// Menu DETALLE VENTA
void menuDetalleVenta(){
    int opcion;
    system("cls");
    std::cout<<"*************************************************"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\tLibreria IOSTREAM"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\tBuscar DETALLE de VENTA"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t1 - Buscar por Numero de VENTA (id)"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t2 - Buscar por DNI Cliente"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t0 - Regresar al menu anterior"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"*************************************************"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<" \t Elija una opcion: ";
    std::cin>>opcion;
    std::cin.ignore();
    int id;
    char  dni[9];
    switch(opcion){
    case 1:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tDETALLE de VENTA por Numero de Factura (id)"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tIngrese el numero de Venta: ";
        std::cin>>id;
        ventasService.buscarYMostrarVenta(id);
        std::cout<<" "<<std::endl;
        std::cout<<"\tDesea Imprimir el Ticket? (1=SI / 0=NO) "<<std::endl;
        int imprimir;
        std::cin>>imprimir;
        std::cout<<" "<<std::endl;
        if(imprimir==1){
            ventasService.imprimirBoleta(id);
        } else {
            std::cout<<"\tVolver al menu."<<std::endl;
        }
        system("pause");
        menuVentas();
        break;
    case 2:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tDETALLE de VENTA por DNI del Cliente"<<std::endl;
        std::cout<<" "<<std::endl;
        ventasService.ventasByCliente();
        std::cout<<" "<<std::endl;
        system("pause");
        menuVentas();
        break;
    case 0:
        menuVentas();
        break;
    default:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tOpcion Incorrecta, ingrese otra opcion."<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        system("pause");
        menuDetalleVenta();
        break;
  }
}

/// Listar VENTAS
void menuListadoVentas(){
    int opcion;
    system("cls");
    std::cout<<"*************************************************"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\tLibreria IOSTREAM"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\tMenu LISTADO VENTAS"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t1 - Entre FECHAS"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t2 - VENTAS POR CLIENTE"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t3 - VENTAS POR GENERO"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t4 - VENTAS POR EDITORIAL"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t5 - VENTAS POR MEDIO DE PAGO"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t6 - TODAS las VENTAS"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t0 - Regresar al menu anterior"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"*************************************************"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\tElija una opcion: ";
    std::cin>>opcion;
    switch(opcion){
    case 1:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tVENTAS entre FECHAS"<<std::endl;
        std::cout<<" "<<std::endl;
        ventasService.ventasEntreFechas();
        std::cout<<" "<<std::endl;
        system("pause");
        menuVentas();
        break;
    case 2:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tVENTAS por CLIENTE"<<std::endl;
        std::cout<<" "<<std::endl;
        ventasService.ventasByCliente();
        std::cout<<" "<<std::endl;
        system("pause");
        menuVentas();
        break;
    case 3:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tVENTAS por GENERO"<<std::endl;
        std::cout<<" "<<std::endl;
        ventasService.ventasByGenero();
        std::cout<<" "<<std::endl;
        system("pause");
        menuVentas();
        break;
    case 4:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tVENTAS por EDITORIAL"<<std::endl;
        std::cout<<" "<<std::endl;
        ventasService.ventasByEditorial();
        std::cout<<" "<<std::endl;
        system("pause");
        menuVentas();
        break;
     case 5:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tVENTAS por MEDIO de PAGO"<<std::endl;
        std::cout<<" "<<std::endl;
        ventasService.ventasByMedioDePago();
        std::cout<<" "<<std::endl;
        system("pause");
        menuVentas();
        break;
    case 6:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tListado de VENTAS completo"<<std::endl;
        std::cout<<" "<<std::endl;
        ventasService.leerArchivoVentas();
        std::cout<<" "<<std::endl;
        system("pause");
        menuVentas();
        break;
    case 0:
        menuVentas();
        break;
    default:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tOpcion Incorrecta, ingrese otra opcion."<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        system("pause");
        menuListadoVentas();
        break;
    }
}

//menuAnularVenta
void menuAnularVenta(){

    system("pause");
    menuInicio();
}

///*************************************************************************************

///CLIENTES

/// Menu Clientes
void menuClientes(){
    int opcion;
    system("cls");
    std::cout<<"*************************************************"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\tLibreria IOSTREAM"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\tMenu CLIENTES"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t1 - CARGAR UN CLIENTE"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t2 - BUSCAR CLIENTE"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t3 - LISTADO DE CLIENTES"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t4 - MODIFICAR CLIENTE"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t0 - Regresar al menu anterior"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"*************************************************"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<" \t Elija una opcion: ";
    std::cin>>opcion;
    switch(opcion){
    case 1:
        cargarCliente();
        menuClientes();
        break;
    case 2:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tMenu BUSCAR CLIENTE"<<std::endl;
        std::cout<<" "<<std::endl;
        buscarCliente();
        system("pause");
        menuClientes();
        break;
    case 3:
        menuListadoClientes();
        break;
    case 4:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tMODIFICAR CLIENTE"<<std::endl;
        std::cout<<" "<<std::endl;
        clienteService.modificarCliente();
        system("pause");
        menuClientes();
        break;
    case 0:
        menuInicio();
        break;
    default:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tOpcion Incorrecta, ingrese otra opcion."<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        system("pause");
        menuClientes();
        break;
    }
}

/// Menu BUSCAR CLIENTE -----------------------------

void buscarCliente(){
    char dni[9];
    std::cin.ignore();
    std::cout << "\tIngrese DNI a Buscar: ";
    std::cin.getline(dni,9);
    bool existe=clienteService.existeCliente(dni);
    if(existe){
        std::cout<< " "<<std::endl;
        std::cout<< "\tCliente:"<<std::endl;
        Cliente cliente=clienteService.buscarClientexDni(dni);
        clienteService.mostrarCliente(cliente);
    } else {
        std::cout<< " "<<std::endl;
        std::cout<< "\tCliente NO Registrado"<<std::endl;
        std::cout<< " "<<std::endl;
    }
}

/// Menu CARGAR CLIENTE -----------------------------

void cargarCliente(){
    system("cls");
    std::cin.ignore();
    int opcion;
    char dni[9];
    std::cout<<"ingrese DNI: ";
    std::cin.getline(dni,9);
    bool existe=clienteService.existeCliente(dni);
    if(!existe){
        Cliente cliente = clienteService.cargarCliente(dni);
        std::cout<<"Cliente cargado exitosamente"<<std::endl;
        clienteService.mostrarCliente(cliente);
        std::cout<<" "<<std::endl;
        std::cout<<"Carga Finalizada. Desea registrarlo? (1=SI / 0=NO) "<<std::endl;
        std::cin>>opcion;
        switch(opcion){
            case 1:
             clienteService.registrarCliente(cliente);
             break;
            case 0:
             menuClientes();
             break;
            default:
             break;
        };
    }
    else{
        std::cout<<"Ya existe un cliente con ese dni"<<std::endl;
    };
    system("pause");
    menuInicio();

}

/// Menu LISTADO CLIENTES -----------------------------

void menuListadoClientes(){
    int opcion;
    system("cls");
    std::cout<<"*************************************************"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\tLibreria IOSTREAM"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\tMenu LISTADO CLIENTES"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t1 - ORDENADOS POR APELLIDO (A-Z)"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t2 - ORDENADOS POR FECHA DE NACIMIENTO"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t0 - Regresar al menu anterior"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"*************************************************"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<" \t Elija una opcion: ";
    std::cin>>opcion;
    switch(opcion){
    case 1:
       system("cls");
       clienteService.listarClientesByApellido();
       system("pause");
       menuClientes();
        break;
    case 2:
       system("cls");
       clienteService.listarClientesByFechaNacimiento();
       system("pause");
       menuClientes();
        break;
    case 0:
        menuClientes();
        break;
    default:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tOpcion Incorrecta, ingrese otra opcion."<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        system("pause");
        menuListadoClientes();
        break;
    }
}

///*************************************************************************************

/// ESTADISTICAS

/// Menu ESTADISTICAS -----------------------------

void menuEstadisticas(){
    int opcion;
    system("cls");
    std::cout<<"*************************************************"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\tLibreria IOSTREAM"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\tMenu ESTADISTICAS"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t1 - ESTADISTICAS DE LIBROS"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t2 - ESTADISTICAS DE RECAUDACION"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t3 - ESTADISTICAS CLIENTES"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t0 - Regresar al menu anterior"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"*************************************************"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<" \t Elija una opcion: ";
    std::cin>>opcion;
    switch(opcion){
    case 1:
        menuEstadisticasLibros();
        break;
    case 2:
        menuEstadisticasRecaudacion();
        break;
    case 3:
        menuEstadisticasCliente();
        break;
    case 0:
        menuInicio();
        break;
    default:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tOpcion Incorrecta, ingrese otra opcion."<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        system("pause");
        menuEstadisticas();
        break;
    }
}



/// Menu Estadisticas Libros
void menuEstadisticasLibros(){
    int opcion;
    system("cls");
    std::cout<<"*************************************************"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\tLibreria IOSTREAM"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\tMenu ESTADISTICAS DE LIBROS"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t1 - LIBRO mas VENDIDO"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t2 - LIBRO mas VENDIDO del ANIO"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t3 - LIBRO mas VENDIDO del MES"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t0 - Regresar al menu anterior"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"*************************************************"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\tElija una opcion: ";
    std::cin>>opcion;
    Libro libro;
    int anio,mes;
    switch(opcion){
    case 1:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLIBRO mas VENDIDO"<<std::endl;
        std::cout<<" "<<std::endl;
        libro = libroService.libroMasVendido();
        if(libroService.copiasVendidas(libro.getIdLibro())!=0){
            libroService.mostrarLibro(libro);
            std::cout<<" "<<std::endl;
            std::cout<<"\tSe vendieron: "<<libroService.copiasVendidas(libro.getIdLibro())<<" copias."<<std::endl;
            std::cout<<" "<<std::endl;
        } else {
            std::cout<<" "<<std::endl;
            std::cout<<"\tSnif snif, aun no se han vendido libros:"<<std::endl;
            std::cout<<" "<<std::endl;
        }
        system("pause");
        menuEstadisticasLibros();
        break;
    case 2:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLIBRO mas VENDIDO del ANIO"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tIngrese el anio: ";
        std::cin>>anio;
        libro = libroService.libroMasVendido(anio);
        if(libroService.copiasVendidas(libro.getIdLibro(),anio)!=0){
            std::cout<<" "<<std::endl;
            std::cout<<"\tEl LIBRO mas vendido del anio "<<anio<<"es: "<<std::endl;
            std::cout<<" "<<std::endl;
            libroService.mostrarLibro(libro);
            std::cout<<" "<<std::endl;
            std::cout<<"\tSe vendieron: "<<libroService.copiasVendidas(libro.getIdLibro(),anio)<<" copias."<<std::endl;
            std::cout<<" "<<std::endl;
        } else {
            std::cout<<" "<<std::endl;
            std::cout<<"\tSnif snif, NO se ha vendido ningun libro ese anio."<<std::endl;
            std::cout<<" "<<std::endl;
        }
        system("pause");
        menuEstadisticasLibros();
        break;
    case 3:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLIBRO mas VENDIDO del MES"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tIngrese el anio: ";
        std::cin>>anio;
        std::cout<<"\tIngrese el Mes: ";
        std::cin>>mes;
        libro = libroService.libroMasVendido(anio,mes);
        if(libroService.copiasVendidas(libro.getIdLibro(),anio,mes)!=0){
            std::cout<<" "<<std::endl;
            std::cout<<"\tEl LIBRO mas vendido del Mes "<<mes<<" es:"<<std::endl;
            std::cout<<" "<<std::endl;
            libroService.mostrarLibro(libro);
            std::cout<<" "<<std::endl;
            std::cout<<"\tSe vendieron: "<<libroService.copiasVendidas(libro.getIdLibro(),anio,mes)<<" copias."<<std::endl;
            std::cout<<" "<<std::endl;
        } else {
            std::cout<<" "<<std::endl;
            std::cout<<"\tSnif snif, en ese mes NO se han vendido libros."<<std::endl;
            std::cout<<" "<<std::endl;
        }
        system("pause");
        menuEstadisticasLibros();
        break;
    case 0:
        menuEstadisticas();
        break;
    default:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tOpcion Incorrecta, ingrese otra opcion."<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        system("pause");
        menuEstadisticasLibros();
        break;
    }
}

/// Menu Estadisticas Recaudacion
void menuEstadisticasRecaudacion(){
    int opcion;
    double recaudacion;
    int anio,mes;
    system("cls");
    std::cout<<"*************************************************"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\tLibreria IOSTREAM"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\tMenu ESTADISTICAS DE RECAUDACION"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t1 - Recaudacion TOTAL por EDITORIAL"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t2 - Recaudacion TOTAL por GENERO"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t3 - Recaudacion TOTAL por MEDIO DE PAGO"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t4 - Recaudacion por TITULO"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t5 - RECAUDACION por MES por ANIO"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t6 - RECAUDACION TOTAL"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t0 - Regresar al menu anterior"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"*************************************************"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<" \t Elija una opcion: ";
    std::cin>>opcion;
    switch(opcion){
    case 1:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tRECAUDACION por EDITORIAL"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tIngrese el ANIO que desea conocer o bien 1 para la estadistica Total: ";
        std::cin>>anio;
        std::cout<<" "<<std::endl;
        if(anio==1){
            ventasService.recaudacionByEditorial();
        } else {
            ventasService.recaudacionByEditorial(anio);
        }
        system("pause");
        menuEstadisticasRecaudacion();
        break;
    case 2:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tRECAUDACION por EDITORIAL"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tIngrese el ANIO que desea conocer o bien 1 para la estadistica Total: ";
        std::cin>>anio;
        std::cout<<" "<<std::endl;
        if(anio==1){
            ventasService.recaudacionByGenero();
        } else {
            ventasService.recaudacionByGenero(anio);
        }
        system("pause");
        menuEstadisticasRecaudacion();
        break;
    case 3:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tRECAUDACION por MEDIO de PAGO"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tIngrese el ANIO que desea conocer, o bien 5 para la estadistica Total: ";
        std::cin>>anio;
        std::cout<<" "<<std::endl;
        if(anio==5){
            ventasService.recaudacionByMedio();
        } else {
            ventasService.recaudacionByMedio(anio);
        }
        system("pause");
        menuEstadisticasRecaudacion();
        break;
    case 4:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tRECAUDACION por TITULO"<<std::endl;
        std::cout<<" "<<std::endl;
        ventasService.recaudacionByTitulo();
        system("pause");
        menuEstadisticasRecaudacion();
        break;
        break;
    case 5:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tRECAUDACION por MES por ANIO"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tIngrese el anio: ";
        std::cin>>anio;
        recaudacion=ventasService.recaudacionTotalAnual(anio);
        if(recaudacion!=0){
            std::cout<<" "<<std::endl;
            std::cout<< "\tRecaudacion TOTAL: $"<<ventasService.recaudacionTotalAnual(anio)<<std::endl;
            std::cout<<" "<<std::endl;
            ventasService.recaudacionTotal(anio);
            std::cout<<" "<<std::endl;
        } else {
            std::cout<<" "<<std::endl;
            std::cout<<"\tSnif Snif, en ese anio NO se vendieron libros."<<std::endl;
            std::cout<<" "<<std::endl;
        }
        system("pause");
        menuEstadisticasRecaudacion();
        break;
    case 6:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tRECAUDACION TOTAL"<<std::endl;
        std::cout<<" "<<std::endl;
        recaudacion=ventasService.recaudacionTotal();
        std::cout<<"\tLa recaudacion hasta el momento es de $"<<recaudacion<<std::endl;
        std::cout<<" "<<std::endl;
        system("pause");
        menuEstadisticasRecaudacion();
        break;
    case 0:
        menuEstadisticas();
        break;
    default:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tOpcion Incorrecta, ingrese otra opcion."<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        system("pause");
        menuEstadisticasRecaudacion();
        break;
    }
}

/// Menu Estadisticas Cliente
void menuEstadisticasCliente(){
    int opcion;
    system("cls");
    std::cout<<"*************************************************"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\tMenu ESTADISTICAS CLIENTES"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t1 - CLIENTE DE MAYOR GASTO DEL MES"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t2 - CLIENTE DE MAYOR GASTO DEL ANIO"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t0 - Regresar al menu anterior"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"*************************************************"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<" \ Elija una opcion: ";
    std::cin>>opcion;
    switch(opcion){
    case 1:{
        system("cls");
        Cliente m=clienteService.clienteMayorGastoMes();
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tMenu ESTADISTICAS CLIENTES"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" El cliente que mas gasto en el mes elegido fue: "<<m.getApellido()<<" DNI: "<<m.getDni()<<std::endl;
        system("pause");
        menuEstadisticasCliente();
        break;}
    case 2:{
        system("cls");
        Cliente a=clienteService.clienteMayorGastoAnio();
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tMenu ESTADISTICAS CLIENTES"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" El cliente que mas gasto en el anio elegido fue: "<<a.getApellido()<<" DNI: "<<a.getDni()<<std::endl;
        system("pause");
        menuEstadisticasCliente();
        break;}
    case 0:
        menuEstadisticas();
        break;
    default:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tOpcion Incorrecta, ingrese otra opcion."<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        system("pause");
        menuEstadisticasCliente();
        break;
    }
}

/****************************************************************************************/

/// MENU CONFIGUARCIONES

/// Menu Configuraciones
void menuConfiguraciones(){
    int opcion;
    system("cls");
    std::cout<<"*************************************************"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\tLibreria IOSTREAM"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\tMenu CONFIGURACIONES"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t1 - REALIZAR BACKUP"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t2 - RESTAURAR ARCHIVOS"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t3 - DESCARGAR REGISTROS (xls)"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t0 - Regresar al menu anterior"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"*************************************************"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<" \t Elija una opcion: ";
    std::cin>>opcion;
    switch(opcion){
    case 1:
        menuRealizarBackup();
        break;
    case 2:
        menuRestaurarArchivos();
        break;
    case 3:
        menuDescargarRegistros();
        break;
    case 0:
        menuInicio();
        break;
    default:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tOpcion Incorrecta, ingrese otra opcion."<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        system("pause");
        menuConfiguraciones();
        break;
    }
}

/// Menu Realizar Backup
void menuRealizarBackup(){
    int opcion;
    system("cls");
    std::cout<<"*************************************************"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\tLibreria IOSTREAM"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\tMenu BACKUP"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t1 - REALIZAR BACKUP ARCHIVO DE LIBROS"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t2 - REALIZAR BACKUP ARCHIVO DE VENTAS"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t3 - REALIZAR BACKUP ARCHIVO DE CLIENTES"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t0 - Regresar al menu anterior"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"*************************************************"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<" \t Elija una opcion: ";
    std::cin>>opcion;
    switch(opcion){
    case 1:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tBACKUP de LIBROS"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        configService.backupLibros();
        std::cout<<" "<<std::endl;
        std::cout<<"*************************************************"<<std::endl;
        system("pause");
        menuInicio();
        break;
    case 2:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tBACKUP de VENTAS"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        configService.backupVentas();
        std::cout<<" "<<std::endl;
        std::cout<<"*************************************************"<<std::endl;
        system("pause");
        menuInicio();
        break;
    case 3:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tBACKUP de CLIENTES"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        configService.backupClientes();
        std::cout<<" "<<std::endl;
        std::cout<<"*************************************************"<<std::endl;
        system("pause");
        menuInicio();
        break;
    case 0:
        menuConfiguraciones();
        break;
    default:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tOpcion Incorrecta, ingrese otra opcion."<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        system("pause");
        menuRealizarBackup();
        break;
    }
}

///  Menu Restaurar Archivos
void  menuRestaurarArchivos(){
    int opcion;
    system("cls");
    std::cout<<"*************************************************"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\tLibreria IOSTREAM"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\tMenu RESTAURAR ARCHIVOS"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t1 - RESTAURAR ARCHIVO DE LIBROS"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t2 - RESTAURAR ARCHIVO DE VENTAS"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t3 - RESTAURAR ARCHIVO DE CLIENTES"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t0 - Regresar al menu anterior"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"*************************************************"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<" \t Elija una opcion: ";
    std::cin>>opcion;
    switch(opcion){
    case 1:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tRESTAURAR ARCHIVO de  LIBROS"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        configService.restaurarArchivosLibros();
        std::cout<<" "<<std::endl;
        std::cout<<"*************************************************"<<std::endl;
        system("pause");
        menuInicio();
        break;
    case 2:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tRESTAURAR ARCHIVO de VENTAS"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        configService.restaurarArchivosVentas();
        std::cout<<" "<<std::endl;
        std::cout<<"*************************************************"<<std::endl;
        system("pause");
        menuInicio();
        break;
    case 3:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tRESTAURAR ARCHIVO de CLIENTES"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        configService.restaurarArchivosClientes();
        std::cout<<" "<<std::endl;
        std::cout<<"*************************************************"<<std::endl;
        system("pause");
        menuInicio();
        break;
    case 0:
        menuConfiguraciones();
        break;
    default:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tOpcion Incorrecta, ingrese otra opcion."<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        system("pause");
        menuDescargarRegistros();
        break;
    }
}

/// Menu Descargar Registros
void menuDescargarRegistros(){
    int opcion;
    system("cls");
    std::cout<<"*************************************************"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\tLibreria IOSTREAM"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\tMenu DESCARGAR REGISTROS"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t1 - Descargar Registro de LIBROS"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t2 - Descargar Registro de CLIENTES"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t3 - Descargar Registro de VENTAS"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\t0 - Regresar al menu anterior"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"*************************************************"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<" \t Elija una opcion: ";
    std::cin>>opcion;
    switch(opcion){
    case 1:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tDescarga de Registro de LIBROS"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        configService.crearExcelLibros();
        std::cout<<" "<<std::endl;
        std::cout<<"*************************************************"<<std::endl;
        system("pause");
        menuInicio();
        break;
    case 2:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tDescarga de Registro de CLIENTES"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        configService.crearExcelClientes();
        std::cout<<" "<<std::endl;
        std::cout<<"*************************************************"<<std::endl;
        system("pause");
        menuInicio();
        break;
    case 3:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tDescarga de Registro de VENTAS"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        configService.crearExcelVentas();
        std::cout<<" "<<std::endl;
        std::cout<<"*************************************************"<<std::endl;
        system("pause");
        menuInicio();
        break;
    case 0:
        menuConfiguraciones();
        break;
    default:
        system("cls");
        std::cout<<"*************************************************"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibreria IOSTREAM"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tOpcion Incorrecta, ingrese otra opcion."<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        system("pause");
        menuDescargarRegistros();
        break;
    }
}

/// Finalizar
void finalizar(){
    system("cls");
    std::cout<<" "<<std::endl;
    std::cout<<"\tCerrando LIBRERIA IOSTREAM"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<" Gracias por usar nuestro sistema"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<" "<<std::endl;
    system("pause");
};
