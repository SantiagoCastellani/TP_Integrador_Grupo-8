#include "Genero.h"
#include "string.h"
#include <iostream>
#include <cstdio>

Genero::Genero(){
}
Genero::Genero(int idGenero,char* genero){
    _idGenero=idGenero;
    strcpy(_genero,genero);
    _activo=true;
}

/// GETTERS
int Genero::getIdGenero(){
    return _idGenero;
}
const char* Genero::getGenero(){
    return _genero;
}
bool Genero::getActivo(){
    return _activo;
}

/// SETTERS
void Genero::setIdGenero(int idGenero){
    _idGenero=idGenero;
}
void Genero::setGenero(const char* genero){
    strcpy(_genero,genero);
}
void Genero::setActivo(bool activo){
    _activo=activo;
}

/// FUNCIONES

// Cargar GENERO
Genero Genero::cargarGenero(){
    std::cout << "CARGAR GENERO" <<std::endl;
    std::cout << " " <<std::endl;
    int idGenero=proximoIdGenero();
    char nombre[30];
    std::cout << "Ingresar NOMBRE de GENERO: ";
    std::cin.getline(nombre,30);
    Genero g(idGenero,nombre);
    return g;
};

// REGISTRAR una Genero en ARCHIVO
void Genero::registrarGenero(Genero g){
    FILE *archivo;
    archivo = fopen(ARCHIVO_GENEROS,"ab");
    fwrite(&g,sizeof(Genero),1,archivo);
    fclose(archivo);
};

// Mostrar Genero
void Genero::mostrarGeneros(Genero genero){
    std::cout << "\tID: "<<genero.getIdGenero()<<std::endl;
    std::cout << "\tNombre: "<<genero.getGenero()<<std::endl;
    std::cout << "  "<<std::endl;
};

// LEER Archivo de Generos
void Genero::leerArchivoGenerosActivos2(){
    FILE *archivo;
    Genero g;
    archivo = fopen(ARCHIVO_GENEROS,"rb");
    while(fread(&g,sizeof(Genero),1,archivo)==1){
        if(g.getActivo()){
             std::cout << " "<<g.getIdGenero()<<" - "<<g.getGenero()<<std::endl;
        }
    }
    std::cout<<" "<<std::endl;
    fclose(archivo);
};

// LEER Archivo de Generos ACTIVOS
void Genero::leerArchivoGenerosActivos(){
    FILE *archivo;
    Genero g;
    archivo = fopen(ARCHIVO_GENEROS,"rb");
    while(fread(&g,sizeof(Genero),1,archivo)==1){
        if(g.getActivo()){
             mostrarGeneros(g);
        }
    }
    fclose(archivo);
};

// Devuelve el proximo Id a setear
int Genero::proximoIdGenero(){
    FILE *archivo;
    Genero g;
    int id=0;
    archivo = fopen(ARCHIVO_GENEROS,"rb");
    while(fread(&g,sizeof(Genero),1,archivo)==1){
        if(g.getIdGenero()>0){
            id=g.getIdGenero();
        }
    }
    fclose(archivo);
    return id+1;
};

// Devuelve Genero By ID
Genero Genero::buscarGeneroById(int idGenero){
    FILE *archivo;
    Genero g;
    Genero genero;
    archivo = fopen(ARCHIVO_GENEROS,"rb");
    while(fread(&g,sizeof(Genero),1,archivo)==1){
        if(g.getIdGenero()==idGenero){
            genero=g;
        }
    }
    fclose(archivo);
    return genero;
};

// Existe Genero?
bool Genero::existeGenero(int id){
    FILE *archivo;
    Genero g;
    bool existe=false;
    archivo = fopen(ARCHIVO_GENEROS,"rb");
    while(fread(&g,sizeof(Genero),1,archivo)==1){
        if(g.getIdGenero()==id){
            existe=true;
        }
    }
    fclose(archivo);
    return existe;
};

// Modificar Genero
void Genero::modificarGenero(){
    int id;
    std::cout<<"\tIngrese el ID del Genero a Modificar: ";
    std::cin>>id;
    bool existe=false;
    existe=existeGenero(id);
    if(existe){
        int opcion=0;
        std::cout<<" "<<std::endl;
        std::cout<<"\tGenero Encontrado: "<<std::endl;
        Genero genero=buscarGeneroById(id);
        mostrarGeneros(genero);
        std::cout<<" "<<std::endl;
        std::cout<<"\tDesea modificar el Genero? (SI = 1 | NO = 0 ): ";
        std::cout<<" "<<std::endl;
        std::cin>>opcion;
        if(opcion==1){
            updateGenero(genero);
        } else {
            std::cout<<" "<<std::endl;
            std::cout<<"\tVolver al menu."<<std::endl;
            std::cout<<" "<<std::endl;
        }
    } else {
        std::cout<<" "<<std::endl;
        std::cout<<"\tCodigo incorrecto. Ese Id de genero NO esta registrado."<<std::endl;
        std::cout<<" "<<std::endl;
    }
    system("pause");
}



// GUARDAR GENERO MODIFICADO en el Registro.
void Genero::updateGenero(Genero genero){
    FILE *archivo;
    int res=-1;
    Genero g;
    char nombreGenero[30];
    int activo;
    archivo = fopen(ARCHIVO_GENEROS,"rb+");
    while(fread(&g,sizeof(Genero),1,archivo)==1){
        if(genero.getIdGenero()==g.getIdGenero()){
            std::cin.ignore();
            fseek(archivo,ftell(archivo)-sizeof(Genero),0);
            std::cout<<"\tIngrese el NOMBRE del GENERO a Modificar: ";
            std::cin.getline(nombreGenero,30);
            std::cout<<"\tIngrese si desea visualizar el Genero (Activo=1 , Inactivo=0): ";
            std::cin>>activo;
            g.setActivo(activo);
            g.setGenero(nombreGenero);
            res = fwrite(&g,sizeof(Genero),1,archivo);
            fclose(archivo);
        }
    }
    fclose(archivo);
    if(res==1){
        std::cout<<" "<<std::endl;
        std::cout<<"\tOK: El Genero se modifico satisfactoriamente"<<std::endl;
        std::cout<<" "<<std::endl;
    } else {
        std::cout<<" "<<std::endl;
        std::cout<<"\tPor algun motivo no pudo modificarse los datos."<<std::endl;
        std::cout<<" "<<std::endl;
    }
};

// LEER Archivo de Generos ACTIVOS
void Genero::leerArchivoGenerosTodos(){
    FILE *archivo;
    Genero g;
    archivo = fopen(ARCHIVO_GENEROS,"rb");
    while(fread(&g,sizeof(Genero),1,archivo)==1){
        mostrarGeneros(g);
    }
    fclose(archivo);
};

// LEER Archivo de Generos INACTIVOS
void Genero::leerArchivoGenerosInactivos(){
    if(cantGenerosInactivos()!=0){
        std::cout<<"Generos INACTIVOS: "<<std::endl;
        FILE *archivo;
        Genero g;
        archivo = fopen(ARCHIVO_GENEROS,"rb");
        while(fread(&g,sizeof(Genero),1,archivo)==1){
            if(!g.getActivo()){
                std::cout << " "<<g.getIdGenero()<<" - "<<g.getGenero()<<std::endl;
            }
        }
        fclose(archivo);
    }
};

int Genero::cantGenerosInactivos(){
    int cant=0;
    FILE *archivo;
    Genero g;
    archivo = fopen(ARCHIVO_GENEROS,"rb");
    while(fread(&g,sizeof(Genero),1,archivo)==1){
        if(!g.getActivo()){
           cant++;
        }
    }
    fclose(archivo);
    return cant;
}



