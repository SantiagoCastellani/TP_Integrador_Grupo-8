#include "Autor.h"
#include "string.h"
#include <iostream>

Autor::Autor(){
    _idAutor=0;
    strcpy(_nombre,"");
    strcpy(_apellido,"");
    strcpy(_codAutor,"0000");

}

Autor::Autor(int idAutor,char* nombre,char* apellido,char* codAutor){
    _idAutor=idAutor;
    strcpy(_nombre,nombre);
    strcpy(_apellido,apellido);
    strcpy(_codAutor,codAutor);
}

/// GETTERS
int Autor::getIdAutor(){
    return _idAutor;
}
const char* Autor::getNombre(){
    return _nombre;
}
const char* Autor::getApellido(){
    return _apellido;
}
const char* Autor::getCodAutor(){
    return _codAutor;
}
//std::string Autor::getNombreCompleto(){
//    return std::to_string(_dia) + "/" + std::to_string(_mes)+ "/" + std::to_string(_anio);
//    return nombre + " " + apellido;
//};

/// SETTERS
void Autor::setIdAutor(int idAutor){
    _idAutor=idAutor;
}
void Autor::setNombre(const char* nombre){
    strcpy(_nombre,nombre);
}
void Autor::setApellido(const char* apellido){
    strcpy(_apellido,apellido);
}
void Autor::setCodAutor(const char* codAutor){
    strcpy(_codAutor,codAutor);
}

/// FUNCIONES

// Cargar AUTOR
Autor Autor::cargarAutor(){
    int idAutor=proximoIdAutor();
    char nombre[25];
    char apellido[24];
    char codigo[5];
    std::cout << "\tIngresar PRIMER NOMBRE: ";
    std::cin.getline(nombre,25);
    std::cout << "\tIngresar APELLIDO: ";
    std::cin.getline(apellido,24);
    strncpy(codigo, nombre, 2);
    codigo[2] = '\0';
    strncat(codigo, apellido, 2);
    int i = 0;
    while (codigo[i]) {
        codigo[i] = std::toupper(codigo[i]);
        i++;
    }
//    i = 0;
//    while (codigo[i]) {
//        codigo[i] = std::tolower(codigo[i]);
//        i++;
//    }
    Autor autor(idAutor,nombre,apellido,codigo);
    return autor;
};

// REGISTRAR un AUTOR en ARCHIVO
void Autor::registrarAutor(Autor autor){
    FILE *archivo;
    archivo = fopen(ARCHIVO_AUTORES,"ab");
    fwrite(&autor,sizeof(Autor),1,archivo);
    fclose(archivo);
};

// Mostrar AUTOR
void Autor::mostrarAutor(Autor autor){
    std::cout << " ID: "<<autor.getIdAutor()<<std::endl;
    std::cout << " Nombre: "<<autor.getNombre()<<std::endl;
    std::cout << " Apellido: "<<autor.getApellido()<<std::endl;
    std::cout << " CODIGO: "<<autor.getCodAutor()<<std::endl;
    std::cout << "  "<<std::endl;
};

// LEER Archivo de AUTORES
void Autor::leerArchivoAutor(){
    FILE *archivo;
    Autor a;
    archivo = fopen(ARCHIVO_AUTORES,"rb");
    std::cout<<" "<< std::endl;
    std::cout<<"\tEDITORIAL en ARCHIVO"<<std::endl;
    std::cout<<" "<<std::endl;
    while(fread(&a,sizeof(Autor),1,archivo)==1){
        mostrarAutor(a);
    }
    std::cout<<" "<<std::endl;
    fclose(archivo);
};

// Devuelve el proximo Id a setear
int Autor::proximoIdAutor(){
    FILE *archivo;
    Autor a;
    int id=0;
    archivo = fopen(ARCHIVO_AUTORES,"rb");
    while(fread(&a,sizeof(Autor),1,archivo)==1){
        if(a.getIdAutor()>0){
            id=a.getIdAutor();
        }
    }
    fclose(archivo);
    return id+1;
};


// Devuelve AUTOR By ID
Autor Autor::buscarAutorById(int id){
    FILE *archivo;
    Autor a;
    Autor autor;
    archivo = fopen(ARCHIVO_AUTORES,"rb");
    while(fread(&a,sizeof(Autor),1,archivo)==1){
        if(a.getIdAutor()==id){
            autor=a;
        }
    }
    fclose(archivo);
    return autor;
};

// Devuelve cantidad de AUTORES By CodAutor
int Autor::cantidadAutoresByCodAutor(char* codigo){
    int cant=0;
    int i = 0;
    while (codigo[i]) {
        codigo[i] = std::toupper(codigo[i]);
        i++;
    }
    FILE *archivo;
    Autor a;
    archivo = fopen(ARCHIVO_AUTORES,"rb");
    while(fread(&a,sizeof(Autor),1,archivo)==1){
        if(strcmp(codigo,a.getCodAutor())==0){
            cant++;
        }
    }
    fclose(archivo);
    return cant;
};

// Elegir entre varios Autores
int Autor::elegirEntreVariosAutores(char* codigo){
    std::cout<<"\tSe han encontrado "<<cantidadAutoresByCodAutor(codigo)<<" con ese codigo."<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\tAutores:"<<std::endl;
    int idElegido=0;
    int i = 0;
    while (codigo[i]) {
        codigo[i] = std::toupper(codigo[i]);
        i++;
    }
    FILE *archivo;
    Autor a;
    archivo = fopen(ARCHIVO_AUTORES,"rb");
    while(fread(&a,sizeof(Autor),1,archivo)==1){
        if(strcmp(codigo,a.getCodAutor())==0){
            std::cout<<"\tAutor: "<<a.getNombre()<<" "<<a.getApellido()<<" ID: "<<a.getIdAutor()<<std::endl;
        }
    }
    fclose(archivo);
    std::cout<<" "<<std::endl;
    std::cout<<"\tPor favor, introduce el id del elegido o cero para salir."<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\tElige un ID de Autor: ";
    std::cin>>idElegido;
    std::cout<<" "<<std::endl;
    return idElegido;
};

// Setear Autor
int Autor::elegirAutor(){
    int idElegido=0;
    char codigo[5];
    std::cout<<"Ingrese el CODIGO de AUTOR: ";
    std::cin.getline(codigo,5);
    int cant = cantidadAutoresByCodAutor(codigo);
    if(cant==0){
        std::cout<<"\No se ha encontrado ese codigo de Autor."<<std::endl;
        std::cout<<"\Cargaremos un valor por defecto, y luego podras modificarlo."<<std::endl;
        std::cout<<"\Recuerda al finalizar el Id de LIBRO."<<std::endl;
    } else if (cant==1){
        Autor autorEncontrado = buscarAutorByCodAutor(codigo);
        idElegido=autorEncontrado.getIdAutor();
        std::cout<<"Autor: "<<autorEncontrado.getNombre()<<" "<<autorEncontrado.getApellido()<<std::endl;
    } else {
        idElegido=elegirEntreVariosAutores(codigo);
        if(idElegido!=0){
             Autor autor=buscarAutorById(idElegido);
             std::cout<<"\tAutor elegido: "<<autor.getNombre()<<" "<<autor.getApellido()<<std::endl;
        }
    }
    return idElegido;
};

Autor Autor::buscarAutorByCodAutor(char *codigo){
    FILE *archivo;
    Autor a;
    Autor autor;
    archivo = fopen(ARCHIVO_AUTORES,"rb");
    while(fread(&a,sizeof(Autor),1,archivo)==1){
        if(strcmp(a.getCodAutor(),codigo)==0){
            autor=a;
        }
    }
    fclose(archivo);
    return autor;
};

int Autor::elegirAutor2(){
    int idElegido=0;
    char codigo[5];
    std::cout<<"\tIngrese el CODIGO de AUTOR: ";
    std::cin.getline(codigo,5);
    int cant = cantidadAutoresByCodAutor(codigo);
    std::cout<<" "<<std::endl;
    if(cant==0){
        std::cout<<"\tNo se ha encontrado ese codigo de Autor."<<std::endl;
    } else if (cant==1){
        Autor autorEncontrado = buscarAutorByCodAutor(codigo);
        idElegido=autorEncontrado.getIdAutor();
        //std::cout<<"\tAutor encontrado: "<<autorEncontrado.getNombre()<<" "<<autorEncontrado.getApellido()<<std::endl;
    } else {
        idElegido=elegirEntreVariosAutores(codigo);
    }
    return idElegido;
};

// Modificar AUTOR
void Autor::modificarAutor(){
    int idElegido = elegirAutor2();
    if(idElegido!=0){
        int opcion=0;
//        std::cout<<" "<<std::endl;
        //std::cout<<"\tAutor a modificar: "<<std::endl;
        Autor autor=buscarAutorById(idElegido);
        //mostrarAutor(autor);
        std::cout<<"\tAutor a modificar: "<<autor.getNombre()<<" "<<autor.getApellido()<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tDesea modificar los datos del Autor? (SI = 1 | NO = 0 ): ";
        std::cin>>opcion;
        if(opcion==1){
            std::cout<<" "<<std::endl;
            updateAutor(autor);
        } else {
            std::cout<<" "<<std::endl;
            std::cout<<"\tVolver al menu."<<std::endl;
            std::cout<<" "<<std::endl;
        }
    }
    system("pause");
}



// GUARDAR AUTOR MODIFICADO en el Registro.
void Autor::updateAutor(Autor autor){
    FILE *archivo;
    int res=-1;
    Autor a;
    char nombre[25];
    char apellido[24];
    char codigo[5];
    archivo = fopen(ARCHIVO_AUTORES,"rb+");
    while(fread(&a,sizeof(Autor),1,archivo)==1){
        if(autor.getIdAutor()==a.getIdAutor()){
            std::cin.ignore();
            fseek(archivo,ftell(archivo)-sizeof(Autor),0);
            std::cout<<"\tIngrese el NOMBRE del Autor a Modificar: ";
            std::cin.getline(nombre,25);
            std::cout<<"\tIngrese el APELLIDO del Autor a Modificar: ";
            std::cin.getline(apellido,24);
            strncpy(codigo, nombre, 2);
            codigo[2] = '\0';
            strncat(codigo, apellido, 2);
            int i = 0;
            while (codigo[i]) {
                codigo[i] = std::toupper(codigo[i]);
                i++;
            }
            Autor a(autor.getIdAutor(),nombre,apellido,codigo);
            res = fwrite(&a,sizeof(Autor),1,archivo);
            fclose(archivo);
        }
    }
    fclose(archivo);
    if(res==1){
        std::cout<<" "<<std::endl;
        std::cout<<"\tOK: El Autor se modifico satisfactoriamente"<<std::endl;
        std::cout<<" "<<std::endl;
    } else {
        std::cout<<" "<<std::endl;
        std::cout<<"\tPor algun motivo no pudo modificarse los datos."<<std::endl;
        std::cout<<" "<<std::endl;
    }
};
