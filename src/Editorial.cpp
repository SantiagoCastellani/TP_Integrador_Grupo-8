#include "Editorial.h"
#include "string.h"
#include <iostream>

Editorial::Editorial(){
}

Editorial::Editorial(int idEditorial,char* nombre){
    _idEditorial=idEditorial;
    strcpy(_nombre,nombre);
}

/// GETTERS
int Editorial::getIdEditorial(){
    return _idEditorial;
}
const char* Editorial::getNombre(){
    return _nombre;
}

/// SETTERS
void Editorial::setIdEditorial(int idEditorial){
    _idEditorial=idEditorial;
}
void Editorial::setNombre(const char* nombre){
    strcpy(_nombre,nombre);
}


/// FUNCIONES

// Cargar EDITORIAL
Editorial Editorial::cargarEditorial(){
    std::cout << "CARGAR EDITORIAL" <<std::endl;
    int idEditorial=proximoIdEditorial();
    char nombre[30];
    std::cout << "Ingresar NOMBRE de EDITORIAL: ";
    std::cin.getline(nombre,30);
    Editorial e(idEditorial,nombre);
    return e;
};

// REGISTRAR una EDITORIAL en ARCHIVO
void Editorial::registrarEditorial(Editorial e){
    FILE *archivo;
    archivo = fopen(ARCHIVO_EDITORIAL,"ab");
    fwrite(&e,sizeof(Editorial),1,archivo);
    fclose(archivo);
};

// Mostrar EDITORIAL
void Editorial::mostrarEditorial(Editorial editorial){
    std::cout << "\tID: "<<editorial.getIdEditorial()<<std::endl;
    std::cout << "\tNombre: "<<editorial.getNombre()<<std::endl;
    std::cout << "  "<<std::endl;
};

// LEER Archivo de Editoriales
void Editorial::leerArchivoEditorial(){
    FILE *archivo;
    Editorial e;
    archivo = fopen(ARCHIVO_EDITORIAL,"rb");
    std::cout<<" "<< std::endl;
    std::cout<<"\tEDITORIAL en ARCHIVO"<<std::endl;
    std::cout<<" "<<std::endl;
    while(fread(&e,sizeof(Editorial),1,archivo)==1){
        mostrarEditorial(e);
    }
    std::cout<<" "<<std::endl;
    fclose(archivo);
};

void Editorial::leerArchivoEditorial2(){
    FILE *archivo;
    Editorial e;
    archivo = fopen(ARCHIVO_EDITORIAL,"rb");
    while(fread(&e,sizeof(Editorial),1,archivo)==1){
       std::cout << " "<<e.getIdEditorial()<<" - "<<e.getNombre()<<std::endl;
    }
    std::cout<<" "<<std::endl;
    fclose(archivo);
};

// Devuelve el proximo IdEditorial a setear
int Editorial::proximoIdEditorial(){
    FILE *archivo;
    Editorial e;
    int id=0;
    archivo = fopen(ARCHIVO_EDITORIAL,"rb");
    while(fread(&e,sizeof(Editorial),1,archivo)==1){
        if(e.getIdEditorial()>0){
            id=e.getIdEditorial();
        }
    }
    fclose(archivo);
    return id+1;
};

// Devuelve EDITORIAL By ID
Editorial Editorial::buscarEditorialById(int id){
    FILE *archivo;
    Editorial e;
    Editorial editorial;
    archivo = fopen(ARCHIVO_EDITORIAL,"rb");
    while(fread(&e,sizeof(Editorial),1,archivo)==1){
        if(e.getIdEditorial()==id){
            editorial=e;
        }
    }
    fclose(archivo);
    return editorial;
};

// Existe Editorial?
bool Editorial::existeEditorial(int id){
    FILE *archivo;
    Editorial e;
    bool existe = false;
    archivo = fopen(ARCHIVO_EDITORIAL,"rb");
    while(fread(&e,sizeof(Editorial),1,archivo)==1){
        if(e.getIdEditorial()==id){
            existe=true;
        }
    }
    fclose(archivo);
    return existe;
};

// Modificar Editorial
void Editorial::modificarEditorial(){
    int id;
    std::cout<<"\tIngrese el ID de Editorial a Modificar: ";
    std::cin>>id;
    bool existe=false;
    existe=existeEditorial(id);
    if(existe){
        int opcion=0;
        std::cout<<" "<<std::endl;
        std::cout<<"\tEditorial encontrada: "<<std::endl;
        Editorial editorial=buscarEditorialById(id);
        mostrarEditorial(editorial);
        std::cout<<" "<<std::endl;
        std::cout<<"\tDesea modificar la Editorial? (SI = 1 | NO = 0 ): ";
        std::cin>>opcion;
        if(opcion==1){
            updateEditorial(editorial);
        } else {
            std::cout<<" "<<std::endl;
            std::cout<<"\tVolver al menu."<<std::endl;
            std::cout<<" "<<std::endl;
        }
    } else {
        std::cout<<" "<<std::endl;
        std::cout<<"\tCodigo incorrecto. Ese Id de editorial NO esta registrado."<<std::endl;
        std::cout<<" "<<std::endl;
    }
    system("pause");
}



// GUARDAR EDITORIAL MODIFICADA en el Registro.
void Editorial::updateEditorial(Editorial editorial){
    FILE *archivo;
    int res=-1;
    Editorial e;
    char nombreEditorial[30];
    archivo = fopen(ARCHIVO_EDITORIAL,"rb+");
    while(fread(&e,sizeof(Editorial),1,archivo)==1){
        if(editorial.getIdEditorial()==e.getIdEditorial()){
            std::cin.ignore();
            fseek(archivo,ftell(archivo)-sizeof(Editorial),0);
            std::cout<<"\tIngrese el NOMBRE de la EDITORIAL a Modificar: ";
            std::cin.getline(nombreEditorial,30);
            e.setNombre(nombreEditorial);
            res = fwrite(&e,sizeof(Editorial),1,archivo);
            fclose(archivo);
        }
    }
    fclose(archivo);
    if(res==1){
        std::cout<<" "<<std::endl;
        std::cout<<"\tOK: La Editorial se modifico satisfactoriamente"<<std::endl;
        std::cout<<" "<<std::endl;
    } else {
        std::cout<<" "<<std::endl;
        std::cout<<"\tPor algun motivo no pudo modificarse los datos."<<std::endl;
        std::cout<<" "<<std::endl;
    }
};

// LEER Archivo de Generos ACTIVOS
//void Genero::leerArchivoGenerosTodos(){
//    FILE *archivo;
//    Genero g;
//    archivo = fopen(ARCHIVO_GENEROS,"rb");
//    while(fread(&g,sizeof(Genero),1,archivo)==1){
//        mostrarGeneros(g);
//    }
//    fclose(archivo);
//};

// LEER Archivo de Generos INACTIVOS
//void Genero::leerArchivoGenerosInactivos(){
//    if(cantGenerosInactivos()!=0){
//        std::cout<<"Generos INACTIVOS: "<<std::endl;
//        FILE *archivo;
//        Genero g;
//        archivo = fopen(ARCHIVO_GENEROS,"rb");
//        while(fread(&g,sizeof(Genero),1,archivo)==1){
//            if(!g.getActivo()){
//                std::cout << " "<<g.getIdGenero()<<" - "<<g.getGenero()<<std::endl;
//            }
//        }
//        fclose(archivo);
//    }
//};

//int Genero::cantGenerosInactivos(){
//    int cant=0;
//    FILE *archivo;
//    Genero g;
//    archivo = fopen(ARCHIVO_GENEROS,"rb");
//    while(fread(&g,sizeof(Genero),1,archivo)==1){
//        if(!g.getActivo()){
//           cant++;
//        }
//    }
//    fclose(archivo);
//    return cant;
//}
