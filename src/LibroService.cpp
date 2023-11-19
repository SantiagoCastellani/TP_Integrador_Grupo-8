#include "LibroService.h"
#include <cstdio>
#include "string.h"
#include "Autor.h"
#include "Genero.h"
#include "Editorial.h"
#include "Venta.h"

#include "libxl.h"

using namespace libxl;

LibroService::LibroService(){}

Autor autorService;
Genero generoService;
Editorial editorialService;

/// LIBROS

// Cargar un Libro
Libro LibroService::cargarLibro(){
    std::cout << " " <<std::endl;
    int idLibro;
    char titulo[100];
    int idAutor;
    int idGenero;
    int idEditorial;
    Fecha fechaPublicacion;
    float precio;
    int stock;
    std::cout << "Ingresar TITULO: ";
    std::cin.getline(titulo,100);
    idAutor=autorService.elegirAutor();
    std::cout << " "<<std::endl;
    std::cout << "Generos Disponibles: "<<std::endl;
    generoService.leerArchivoGenerosActivos2();
    std::cout << "Ingresar ID GENERO: ";
    std::cin>>idGenero;
    std::cout << " "<<std::endl;
    std::cout << "Editoriales Disponibles: "<<std::endl;
    editorialService.leerArchivoEditorial2();
    std::cout << "Ingresar ID EDITORIAL: ";
    std::cin>>idEditorial;
    std::cout << "Ingresar FECHA PUBLICACION: "<<std::endl;
    Fecha fecha = fecha.cargarFecha();
    std::cout << "Fecha cargada: "<<fecha.fechaFormateada()<<std::endl;
    std::cout << "Ingresar PRECIO unitario: ";
    std::cin>>precio;
    std::cout << "Ingresar STOCK: ";
    std::cin>>stock;
    idLibro = proximoIdLibro();
    Libro l(idLibro,titulo,idAutor,idGenero,idEditorial,fecha,precio,stock);
    return l;
};

// Mostrar un Libro
void LibroService::mostrarLibro(Libro l){
    Autor autor = autorService.buscarAutorById(l.getIdAutor());
    Genero genero = generoService.buscarGeneroById(l.getIdGenero());
    Editorial editorial = editorialService.buscarEditorialById(l.getIdEditorial());
    std::cout << " Id: "<<l.getIdLibro()<<std::endl;
    std::cout << " Titulo: "<<l.getTitulo()<<std::endl;
    std::cout << " Autor: "<<autor.getNombre()<<" "<<autor.getApellido()<<std::endl;
    std::cout << " Genero: "<<genero.getGenero()<<std::endl;
    std::cout << " Editorial: "<<editorial.getNombre()<<std::endl;
    std::cout << " Fecha Publicacion: "<<l.getFechaPublicacion().fechaFormateada()<<std::endl;
    std::cout << " Precio: $"<<l.getPrecio()<<std::endl;
    std::cout << " Stock: "<<l.getStock()<<std::endl;
    std::cout << "  "<<std::endl;
};

// Mostrar un Libro
void LibroService::mostrarLibro2(Libro l){
    Autor autor = autorService.buscarAutorById(l.getIdAutor());
    Genero genero = generoService.buscarGeneroById(l.getIdGenero());
    Editorial editorial = editorialService.buscarEditorialById(l.getIdEditorial());
    std::cout << "\tId: "<<l.getIdLibro()<<std::endl;
    std::cout << "\tTitulo: "<<l.getTitulo()<<std::endl;
    std::cout << "\tAutor: "<<autor.getNombre()<<" "<<autor.getApellido()<<std::endl;
    std::cout << "\tGenero: "<<genero.getGenero()<<std::endl;
    std::cout << "\tEditorial: "<<editorial.getNombre()<<std::endl;
    std::cout << "\tFecha Publicacion: "<<l.getFechaPublicacion().fechaFormateada()<<std::endl;
    std::cout << "\tPrecio: $"<<l.getPrecio()<<std::endl;
    std::cout << "\tStock: "<<l.getStock()<<std::endl;
    std::cout << "  "<<std::endl;
};

// Devuelve el proximo IdLibro a setear
int LibroService::proximoIdLibro(){
    FILE *archivo;
    Libro l;
    int id=0;
    archivo = fopen(ARCHIVO_LIBROS,"rb");
    while(fread(&l,sizeof(Libro),1,archivo)==1){
        if(l.getIdLibro()>0){
            id=l.getIdLibro();
        }
    }
    fclose(archivo);
    return id+1;
};

// Registra un LIBRO en Archivo
void LibroService::registrarLibro(Libro libro){
    FILE *archivo;
    archivo = fopen(ARCHIVO_LIBROS,"ab");
    fwrite(&libro,sizeof(Libro),1,archivo);
    fclose(archivo);
};

// Leer Archivo de Libros
void LibroService::leerArchivoLibros(){
    FILE *archivo;
    Libro l;
    archivo = fopen(ARCHIVO_LIBROS,"rb");
    std::cout<<" "<< std::endl;
    std::cout<<"\tLIBROS en ARCHIVO"<<std::endl;
    std::cout<<" "<<std::endl;
    while(fread(&l,sizeof(Libro),1,archivo)==1){
        mostrarLibro(l);
    }
    std::cout<<" "<<std::endl;
    fclose(archivo);
};

// Buscar LIBRO By ID
Libro LibroService::buscarLibroById(int id){
    FILE *archivo;
    Libro l;
    Libro libro;
    archivo = fopen(ARCHIVO_LIBROS,"rb");
    while(fread(&l,sizeof(Libro),1,archivo)==1){
        if(l.getIdLibro()==id){
            libro=l;
        }
    }
    fclose(archivo);
    return libro;
};

// Existe LIBRO?
bool LibroService::existeLibro(int id){
    FILE *archivo;
    Libro l;
    bool existe = false;
    archivo = fopen(ARCHIVO_LIBROS,"rb");
    while(fread(&l,sizeof(Libro),1,archivo)==1){
        if(l.getIdLibro()==id){
            existe=true;
        }
    }
    fclose(archivo);
    return existe;
};

// Buscar LIBRO por TITULO (si no existe elige 1)
Libro LibroService::buscarLibroByTitulo(){
    Libro libro;
    char titulo[100];
    std::cout<<" Ingrese el titulo a buscar: ";
    std::cin>>titulo;
    if(existeTitulo(titulo)){
        libro=buscarLibroByTitulo(titulo);
    } else {
        std::cout<<" "<<std::endl;
        std::cout<<" No se ha encontrado exactamente ese titulo."<<std::endl;
        std::cout<<" Buscando los titulos con la misma letra inicial."<<std::endl;
        std::cout<<" "<<std::endl;
        int idElegido=elegirLibro(titulo);
        libro=buscarLibroById(idElegido);
    }
    return libro;
};

bool LibroService::existeTitulo(char* titulo){
    FILE *archivo;
    Libro l;
    bool existe = false;
    archivo = fopen(ARCHIVO_LIBROS,"rb");
    while(fread(&l,sizeof(Libro),1,archivo)==1){
        if(compararTitulos(titulo,l.getTitulo())==0){
            existe = true;
        }
//        if(strcmp(l.getTitulo(),titulo)==0){
//            existe=true;
//        }
    }
    fclose(archivo);
    return existe;
};


// Buscar Libro By Titulo
Libro LibroService::buscarLibroByTitulo(char* titulo){
    FILE *archivo;
    Libro l;
    Libro libro;
    archivo = fopen(ARCHIVO_LIBROS,"rb");
    while(fread(&l,sizeof(Libro),1,archivo)==1){
        if(compararTitulos(l.getTitulo(),titulo)==0){
            libro=l;
        }
    }
    fclose(archivo);
    return libro;
};

// Devolver un Libro Elegido
int LibroService::elegirLibro(char*titulo){
    int band,idElegido=0;
    FILE *archivo;
    Libro l;
    Libro libro;
    archivo = fopen(ARCHIVO_LIBROS,"rb");
    while(fread(&l,sizeof(Libro),1,archivo)==1){
        if(l.getTitulo()[0]==titulo[0]){
            band++;
            Autor autor = autorService.buscarAutorById(l.getIdAutor());
            std::cout<<" ID: "<<l.getIdLibro()<<" "<<l.getTitulo()<<" ("<<autor.getNombre()<<" "<<autor.getApellido()<<")"<<std::endl;
        }
    }
    fclose(archivo);
    std::cout<<" "<<std::endl;
    if(band>0){
        std::cout<<" Elija el ID del LIBRO que esta buscando - (0 en caso de que no este en la lista)"<<std::endl;
        std::cout<<" Ingrese una opcion: ";
        std::cin>>idElegido;
    }
    return idElegido;
}

/// Funcion Busqueda de LIBRO por TITULO desde MENU
void LibroService::buscarLibroTitulo(){
    Libro libro = buscarLibroByTitulo();
    if(libro.getIdLibro()!=0){
        std::cout<<" "<<std::endl;
        std::cout<<" Libro encontrado: "<<std::endl;
        std::cout<<" "<<std::endl;
        mostrarLibro(libro);
    } else {
        std::cout<<" No pudimos encontrar ningun libro con ese titulo"<<std::endl;
        std::cout<<" "<<std::endl;
    }
}


/// Funcion Busqueda de LIBRO por Nombre y Apellido de AUTOR desde MENU
void LibroService::buscarLibroCodAutor(){
    int id=autorService.elegirAutor2();
    Autor autor = autorService.buscarAutorById(id);
    int cantLibros=tieneLibrosByIdAutor(id);
    if(cantLibros!=0){
        FILE *archivo;
        Libro l;
        archivo = fopen(ARCHIVO_LIBROS,"rb");
        std::cout<<" "<<std::endl;
        std::cout<<"\tLos Libros asociados a "<<autor.getNombre()<<" "<<autor.getApellido()<<" son:"<<std::endl;
        std::cout<<" "<<std::endl;
        while(fread(&l,sizeof(Libro),1,archivo)==1){
            if(l.getIdAutor()==autor.getIdAutor()){
                mostrarLibro(l);
            }
        }
        fclose(archivo);
    } else {
        std::cout<<" "<<std::endl;
        std::cout<<"\t"<<autor.getNombre()<<" "<<autor.getApellido()<<" No tiene libros asociados."<<std::endl;
        std::cout<<" "<<std::endl;
    }
}

// Comparar los titulos llevando ambos a uppercase
int LibroService::compararTitulos(char * tituloBuscado,char *tituloLibro){
   int result=-1;
   int i,j=0;
   while (tituloBuscado[i]){
       tituloBuscado[i] = std::toupper(tituloBuscado[i]);
        i++;
    }
    while (tituloLibro[j]){
        tituloLibro[j] = std::toupper(tituloLibro[j]);
        j++;
    }
    result=strcmp(tituloBuscado,tituloLibro);
    return result;
}


// Devuelce Cantidad de LIBROS By ID AUTOR
int LibroService::tieneLibrosByIdAutor(int idAutor){
    int cant=0;
    FILE *archivo;
    Libro l;
    archivo = fopen(ARCHIVO_LIBROS,"rb");
    while(fread(&l,sizeof(Libro),1,archivo)==1){
        if(l.getIdAutor()==idAutor){
            cant++;
        }
    }
    fclose(archivo);
    return cant;
}

/// LISTADOS de LIBROS

// Listado By Genero
void LibroService::listarPorGenero(){
    int idGenero;
    std::cout<<"\tGeneros disponibles:"<<std::endl;
    std::cout<<" "<<std::endl;
    generoService.leerArchivoGenerosActivos2();
    std::cout<<"\tIngrese un ID de Genero: ";
    std::cin>>idGenero;
    Genero g = generoService.buscarGeneroById(idGenero);
    std::cout<<" "<<std::endl;
    std::cout<<"\tGenero: "<<g.getGenero()<<std::endl;
    std::cout<<" "<<std::endl;
    FILE *archivo;
    Libro l;
    archivo = fopen(ARCHIVO_LIBROS,"rb");
    while(fread(&l,sizeof(Libro),1,archivo)==1){
        if(l.getIdGenero()==idGenero){
            mostrarLibro(l);
        }
    }
    fclose(archivo);
}

// Listado By Editorial
void LibroService::listarPorEditorial(){
    int idEditorial;
    std::cout<<"\tEditoriales disponibles:"<<std::endl;
    std::cout<<" "<<std::endl;
    editorialService.leerArchivoEditorial();
    std::cout<<"\tIngrese un ID de Editorial: ";
    std::cin>>idEditorial;
    Editorial e = editorialService.buscarEditorialById(idEditorial);
    std::cout<<" "<<std::endl;
    std::cout<<"\tEditorial: "<<e.getNombre()<<std::endl;
    FILE *archivo;
    Libro l;
    archivo = fopen(ARCHIVO_LIBROS,"rb");
    while(fread(&l,sizeof(Libro),1,archivo)==1){
        if(l.getIdEditorial()==idEditorial){
            mostrarLibro(l);
        }
    }
    fclose(archivo);
}



// Listado By Titulo de la A a la Z
void LibroService::listarPorTituloAZ(){
    int cantLibros = proximoIdLibro()-1;
    Libro *vectorLibros = new Libro[cantLibros];
    if(vectorLibros == NULL){
        exit(1);
    }
    // Cargar Vector con los Libros del Registro
    leerLibrosCargarVector(vectorLibros);
    // Ordenar Alfabeticamente el Vector
    ordenarAlfabeticamente(vectorLibros,cantLibros);
    // Lista el vector Ordenado
    listarOrdenado(vectorLibros,cantLibros);

    // Libera la memoria
    delete vectorLibros;
}

// Cargar el Vector con los Libros del Registro
void LibroService::leerLibrosCargarVector(Libro *vectorLibros){
    Libro libro;
    int i = 0;
    FILE *archivo;
    archivo = fopen(ARCHIVO_LIBROS,"rb");
    if(archivo == NULL){
        exit(1);
    }
    while(fread(&libro, sizeof (Libro), 1, archivo)){
        vectorLibros[i] = libro;
        i++;
    }
    fclose(archivo);
}

// Ordenar Alfabeticamente los libros por su titulo
void LibroService::ordenarAlfabeticamente(Libro *vectorLibros, int cantLibros){
    int i, j;
    Libro aux;
    for(i = 0; i < cantLibros; i++){
        for(j = 1; j < cantLibros; j++){
            if(strcmp(vectorLibros[j].getTitulo(), vectorLibros[j-1].getTitulo()) < 0){
                aux = vectorLibros[j-1];
                vectorLibros[j-1] = vectorLibros[j];
                vectorLibros[j] = aux;
            }
        }
    }
}

// Listar Vector Ordenado
void LibroService::listarOrdenado(Libro *vectorLibros, int cantLibros){
    for(int i = 0; i < cantLibros; i++){
        Autor autor = autorService.buscarAutorById(vectorLibros[i].getIdAutor());
        vectorLibros[i];
        std::cout<<"\tID: "<<vectorLibros[i].getIdLibro()<<" - "<< vectorLibros[i].getTitulo()<<"  ("<<autor.getNombre()<<" "<<autor.getApellido()<<") "<<std::endl;
    }
}

/// MODIFICACION de LIBROS

// Modificar LIBRO
void LibroService::modificarLibro(){
    int id;
    std::cout<<"\tIngrese el ID del LIBRO a Modificar: ";
    std::cin>>id;
    bool existe=false;
    existe=existeLibro(id);
    if(existe){
        int opcion=0;
        std::cout<<" "<<std::endl;
        std::cout<<"\tLibro encontrado: "<<std::endl;
        Libro libro=buscarLibroById(id);
        mostrarLibro2(libro);
        std::cout<<" "<<std::endl;
        std::cout<<"\tDesea modificar los datos cargados del Libro? (SI = 1 | NO = 0 ): ";
        std::cin>>opcion;
        if(opcion==1){
            updateLibro(libro);
        } else {
            std::cout<<" "<<std::endl;
            std::cout<<"\tVolver al menu."<<std::endl;
            std::cout<<" "<<std::endl;
        }
    } else {
        std::cout<<" "<<std::endl;
        std::cout<<"\tCodigo incorrecto. Ese Id de Libro NO esta registrado."<<std::endl;
        std::cout<<" "<<std::endl;
    }
}




// GUARDAR LIBRO MODIFICADO en el Registro.
void LibroService::updateLibro(Libro libro){
    FILE *archivo;
    int res=-1;
    Libro l;
    archivo = fopen(ARCHIVO_LIBROS,"rb+");
    while(fread(&l,sizeof(Libro),1,archivo)==1){
        if(libro.getIdLibro()==l.getIdLibro()){
            std::cin.ignore();
            fseek(archivo,ftell(archivo)-sizeof(Libro),0);
            char titulo[100];
            int idAutor;
            int idGenero;
            int idEditorial;
            Fecha fechaPublicacion;
            float precio;
            int stock;
            std::cout << " Ingresar TITULO: ";
            std::cin.getline(titulo,100);
            idAutor=autorService.elegirAutor();
            std::cout << " Autor id: "<<idAutor<<std::endl;
            std::cout << " "<<std::endl;
            std::cout << " Generos Disponibles: "<<std::endl;
            generoService.leerArchivoGenerosActivos2();
            std::cout << " Ingresar ID GENERO: ";
            std::cin>>idGenero;
            std::cout << " "<<std::endl;
            std::cout << " Editoriales Disponibles: "<<std::endl;
            editorialService.leerArchivoEditorial2();
            std::cout << " Ingresar ID EDITORIAL: ";
            std::cin>>idEditorial;
            std::cout << " Ingresar FECHA PUBLICACION: "<<std::endl;
            Fecha fecha = fecha.cargarFecha();
            std::cout << " Fecha cargada: "<<fecha.fechaFormateada()<<std::endl;
            std::cout << " Ingresar PRECIO unitario: ";
            std::cin>>precio;
            std::cout << " Ingresar STOCK: ";
            std::cin>>stock;
            Libro libroM(libro.getIdLibro(),titulo,idAutor,idGenero,idEditorial,fecha,precio,stock);
            res = fwrite(&libroM,sizeof(Libro),1,archivo);
            fclose(archivo);
        }
    }
    fclose(archivo);
    if(res==1){
        std::cout<<" "<<std::endl;
        std::cout<<"\tOK: El Libro se modifico satisfactoriamente"<<std::endl;
        std::cout<<" "<<std::endl;
    } else {
        std::cout<<" "<<std::endl;
        std::cout<<"\tPor algun motivo no pudieron modificarse los datos."<<std::endl;
        std::cout<<" "<<std::endl;
    }
};

/// Hay STOCK
bool LibroService::hayStock(int id){
    bool stock = false;
    Libro libro = buscarLibroById(id);
    if(libro.getStock()>0){
        stock=true;
    }
    return stock;
}

/// Reducir STOCK en VENTA.
void LibroService::reducirStock(int id){
    if(hayStock(id)){
        Libro libro = buscarLibroById(id);
        libro.setStock(libro.getStock()-1);
        updatearLibroPosVenta(libro);
    }

};

/// UPDATEAR STOCK en LIBRO Registro.
void LibroService::updatearLibroPosVenta(Libro libro){
    FILE *archivo;
    int res=-1;
    Libro l;
    archivo = fopen(ARCHIVO_LIBROS,"rb+");
    while(fread(&l,sizeof(Libro),1,archivo)==1){
        if(libro.getIdLibro()==l.getIdLibro()){
            fseek(archivo,ftell(archivo)-sizeof(Libro),0);
            res = fwrite(&libro,sizeof(Libro),1,archivo);
            fclose(archivo);
        }
    }
    fclose(archivo);
};

// INFO Basica LIBRO
void LibroService::infoBasicaLibro(int id){
    Libro libro = buscarLibroById(id);
    Autor autor = autorService.buscarAutorById(libro.getIdAutor());
    std::cout<<"\t"<<libro.getTitulo()<<" ("<<autor.getNombre()<<" "<<autor.getApellido()<<")"<<std::endl;
}


/// ESTADISTICAS

// El LIBRO mas VENDIDO
Libro LibroService::libroMasVendido(){
    int cantVentas=0;
    Libro masVendido;
    FILE *archivo;
    Libro l;
    archivo = fopen(ARCHIVO_LIBROS,"rb");
    while(fread(&l,sizeof(Libro),1,archivo)==1){
        int copias=copiasVendidas(l.getIdLibro());
        if(copias>cantVentas){
            cantVentas=copias;
            masVendido=l;
        }
    }
    fclose(archivo);
    return masVendido;
}

int LibroService::copiasVendidas(int idLibro){
    int copias=0;
    FILE *archivo;
    Venta v;
    archivo = fopen(ARCHIVO_REGISTROVENTAS,"rb");
    while(fread(&v,sizeof(Venta),1,archivo)==1){
        if(v.getIdLibro()==idLibro){
            copias++;
        }
    }
    fclose(archivo);
    return copias;
}

// El LIBRO mas VENDIDO del ANIO
Libro LibroService::libroMasVendido(int anio){
    int cantVentas=0;
    Libro masVendido;
    FILE *archivo;
    Libro l;
    archivo = fopen(ARCHIVO_LIBROS,"rb");
    while(fread(&l,sizeof(Libro),1,archivo)==1){
        int copias=copiasVendidas(l.getIdLibro(),anio);
        if(copias>cantVentas){
            cantVentas=copias;
            masVendido=l;
        }
    }
    fclose(archivo);
    return masVendido;
}

int LibroService::copiasVendidas(int idLibro,int anio){
    int copias=0;
    FILE *archivo;
    Venta v;
    archivo = fopen(ARCHIVO_REGISTROVENTAS,"rb");
    while(fread(&v,sizeof(Venta),1,archivo)==1){
        if((v.getIdLibro()==idLibro)&&(v.getFecha().getAnio()==anio)){
            copias++;
        }
    }
    fclose(archivo);
    return copias;
}

// El LIBRO mas VENDIDO del MES
Libro LibroService::libroMasVendido(int anio,int mes){
    int cantVentas=0;
    Libro masVendido;
    FILE *archivo;
    Libro l;
    archivo = fopen(ARCHIVO_LIBROS,"rb");
    while(fread(&l,sizeof(Libro),1,archivo)==1){
        int copias=copiasVendidas(l.getIdLibro(),anio,mes);
        if(copias>cantVentas){
            cantVentas=copias;
            masVendido=l;
        }
    }
    fclose(archivo);
    return masVendido;
}

int LibroService::copiasVendidas(int idLibro,int anio,int mes){
    int copias=0;
    FILE *archivo;
    Venta v;
    archivo = fopen(ARCHIVO_REGISTROVENTAS,"rb");
    while(fread(&v,sizeof(Venta),1,archivo)==1){
        if((v.getIdLibro()==idLibro)&&(v.getFecha().getAnio()==anio)&&(v.getFecha().getMes()==mes)){
            copias++;
        }
    }
    fclose(archivo);
    return copias;
}

/// Listar TODOS los LIBROS
void LibroService::listarLibrosTodos(){
    FILE *archivo;
    Libro l;
    archivo = fopen(ARCHIVO_LIBROS,"rb");
    std::cout<<" "<< std::endl;
    while(fread(&l,sizeof(Libro),1,archivo)==1){
        mostrarLibro(l);
    }
    std::cout<<" "<<std::endl;
    fclose(archivo);
}






