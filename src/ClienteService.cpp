
#include "ClienteService.h"
#include "Cliente.h"
#include "Fecha.h"
#include "string.h"
#include "VentasService.h"


ClienteService::ClienteService(){}



Cliente ClienteService::cargarCliente(char* dni){
    std::cout << "CARGAR CLIENTE" <<std::endl;
    char Ndni[9];
    char nombre[25];
    char apellido[24];
    char telefono[15];
    char email[100];
    Fecha fecha;
    strcpy(Ndni,dni);
    std::cout<< "Ingrese Nombre: "<<std::endl;
    std::cin.getline(nombre,25);
    std::cout<< "Ingrese Apellido: "<<std::endl;
    std::cin.getline(apellido,24);
    std::cout<< "Ingrese Telefono: "<<std::endl;
    std::cin.getline(telefono,15);
    std::cout<< "Ingrese Email:" <<std::endl;
    std::cin.getline(email,100);
    std::cout<< "Ingrese fecha de nacimiento: "<<std::endl;
    Fecha fechaNacimiento = fecha.cargarFecha();
    Cliente c(Ndni,nombre,apellido,telefono,email,fechaNacimiento);
    return c;
}

//registrarCliente
void ClienteService::registrarCliente(Cliente cliente){
    FILE *archivo;
    int res=-1;
    archivo = fopen(ARCHIVO_CLIENTES,"ab");
    res=fwrite(&cliente,sizeof(Cliente),1,archivo);
    fclose(archivo);
        if(res==1){
        std::cout<<" "<<std::endl;
        std::cout<<"\tOK: El cliente se registro satisfactoriamente"<<std::endl;
        std::cout<<" "<<std::endl;
    } else {
        std::cout<<" "<<std::endl;
        std::cout<<"\tPor algun motivo no pudo registrarse el cliente."<<std::endl;
        std::cout<<" "<<std::endl;
    }
}

//extisteCliente
bool ClienteService::existeCliente(char* dni){
    FILE *archivo;
    Cliente c;
    bool existe = false;
    archivo = fopen(ARCHIVO_CLIENTES,"rb");
    while(fread(&c,sizeof(Cliente),1,archivo)==1){
        if(strcmp(c.getDni(),dni)==0){
            existe = true;
        }
    }
    fclose(archivo);
    return existe;
}

//mostrarCliente
void ClienteService::mostrarCliente(Cliente cliente){
    std::cout << " Dni: "<<cliente.getDni()<<std::endl;
    std::cout << " Nombre: "<<cliente.getNombre()<<std::endl;
    std::cout << " Apellido: "<<cliente.getApellido()<<std::endl;
    std::cout << " Telefono: "<<cliente.getTelefono()<<std::endl;
    std::cout << " Email: "<<cliente.getEmail()<<std::endl;
    std::cout << " Fecha Nacimiento: "<<cliente.getFecha().fechaFormateada()<<std::endl;
    std::cout << "  "<<std::endl;
}

//leerArchivoClientes
void ClienteService::leerArchivoClentes(){
FILE *archivo;
    Cliente cliente;
    archivo = fopen(ARCHIVO_CLIENTES,"rb");
    std::cout<<" "<< std::endl;
    std::cout<<"\tCLIENTES en ARCHIVO"<<std::endl;
    std::cout<<" "<<std::endl;
    while(fread(&cliente,sizeof(Cliente),1,archivo)==1){
        mostrarCliente(cliente);
    }
    std::cout<<" "<<std::endl;
    fclose(archivo);
}

//buscarClienteDni
Cliente ClienteService::buscarClientexDni(char* dni){
    FILE *archivo;
    Cliente cliente;
    Cliente clienteBuscado;
    archivo = fopen(ARCHIVO_CLIENTES,"rb");
    while(fread(&cliente,sizeof(Cliente),1,archivo)==1){
        if(strcmp(cliente.getDni(),dni)==0){
            clienteBuscado=cliente;
        }
    }
    std::cout<<" "<<std::endl;
    fclose(archivo);
    return clienteBuscado;
}

//listarClientes
int ClienteService::obtenerCantidadClientes(){
Cliente cliente;
int cantidad=0;
FILE *archivo;
    archivo = fopen(ARCHIVO_CLIENTES,"rb");
    while(fread(&cliente,sizeof(Cliente),1,archivo)==1){
          cantidad++;}
fclose(archivo);
    return cantidad;
}

void ClienteService::cargarRegistroClientes(Cliente *vectorClientes){
    Cliente cliente;
    int i=0;
    FILE *archivo;
    archivo = fopen(ARCHIVO_CLIENTES,"rb");
    while(fread(&cliente,sizeof(Cliente),1,archivo)==1){
          vectorClientes[i]=cliente;
          i++;}
fclose(archivo);
}

void ClienteService::ordenarVectorPorNombres(Cliente *vectorClientes,int tam){
    int i,j;
    Cliente aux;
    for(i=0;i<tam;i++){
       for(j=1;j<tam;j++){
        if(strcmp(vectorClientes[j].getApellido(),vectorClientes[j-1].getApellido())<0){
            aux=vectorClientes[j-1];
            vectorClientes[j-1]=vectorClientes[j];
            vectorClientes[j]=aux;
        }
       }
    }
}

void ClienteService::ordenarVectorPorFecha(Cliente *vectorClientes,int tam){
    int i,j;
    Cliente aux;
    for(i=0;i<tam;i++){
       for(j=1;j<tam;j++){
        if(vectorClientes[j].getFecha().getAnio()<vectorClientes[j-1].getFecha().getAnio()){
            aux=vectorClientes[j-1];
            vectorClientes[j-1]=vectorClientes[j];
            vectorClientes[j]=aux;
        }else if(vectorClientes[j].getFecha().getAnio()==vectorClientes[j-1].getFecha().getAnio()){
            if(vectorClientes[j].getFecha().getMes()<vectorClientes[j-1].getFecha().getMes()){
                aux=vectorClientes[j-1];
                vectorClientes[j-1]=vectorClientes[j];
                vectorClientes[j]=aux;
            }else if(vectorClientes[j].getFecha().getMes()==vectorClientes[j-1].getFecha().getMes()){
                if(vectorClientes[j].getFecha().getDia()<vectorClientes[j-1].getFecha().getDia()){
                   aux=vectorClientes[j-1];
                   vectorClientes[j-1]=vectorClientes[j];
                   vectorClientes[j]=aux;
                }
             }
        }
       }
    }
}

void ClienteService::mostrarVectorOrdenadoPorApellido(Cliente *vectorClientes,int tam){
    Cliente cli;
    for(int i=0;i<tam;i++){
       cli=vectorClientes[i];
       mostrarCliente(cli);
    }
}

void ClienteService::mostrarVectorOrdenadoPorFecha(Cliente *vectorClientes,int tam){
    Cliente cli;
    for(int i=0;i<tam;i++){
       cli=vectorClientes[i];
       mostrarCliente(cli);
    }
}

void ClienteService::listarClientesByApellido(){
    int tam=obtenerCantidadClientes();
    Cliente *vectorClientes= new Cliente[tam];
    cargarRegistroClientes(vectorClientes);
    ordenarVectorPorNombres(vectorClientes,tam);
    mostrarVectorOrdenadoPorApellido(vectorClientes,tam);
    delete vectorClientes;
}

void ClienteService::listarClientesByFechaNacimiento(){
    int tam=obtenerCantidadClientes();
    Cliente *vectorClientes= new Cliente[tam];
    cargarRegistroClientes(vectorClientes);
    ordenarVectorPorFecha(vectorClientes,tam);
    mostrarVectorOrdenadoPorFecha(vectorClientes,tam);
    delete vectorClientes;
}

//modificarCliente
void ClienteService::modificarCliente(){
    std::cin.ignore();
    char dni[9];
    std::cout<<"\tIngrese DNI del Cliente a Modificar: "<<std::endl;
    std::cin.getline(dni,9);
    bool existe=existeCliente(dni);
    std::cout<<existe;
    if(existe){
        Cliente cliente=buscarClientexDni(dni);
        std::cout<<"\tCliente encontrado: "<<std::endl;
        mostrarCliente(cliente);
        std::cout<<" "<<std::endl;
        editarCliente(cliente);
        std::cout<<" "<<std::endl;
    }else {std::cout<<"No se ha encontrado un Cliente con ese DNI "<<std::endl;}
}

void ClienteService::editarCliente(Cliente cliente){
    char dni[9];
    char nombre[25];
    char apellido[24];
    char telefono[15];
    char email[100];
    Fecha fecha;
    int idGeneroFavorito;
    FILE *archivo;
    int res=-1;
    Cliente c;
    Cliente clienteEditado;
    archivo = fopen(ARCHIVO_CLIENTES,"rb+");
    while(fread(&c,sizeof(Cliente),1,archivo)==1){
        if(strcmp(c.getDni(),cliente.getDni())==0){
            std::cin.ignore();
            fseek(archivo,ftell(archivo)-sizeof(Cliente),0);
            std::cout<<"\tIngrese los datos del cliente a modificar"<<std::endl;
            std::cout<<" "<<std::endl;
            std::cout<< "Ingrese DNI Cliente: "<<std::endl;
            std::cin.getline(dni,9);
            std::cout<< "Ingrese Nombre: "<<std::endl;
            std::cin.getline(nombre,25);
            std::cout<< "Ingrese Apellido: "<<std::endl;
            std::cin.getline(apellido,24);
            std::cout<< "Ingrese Telefono: "<<std::endl;
            std::cin.getline(telefono,15);
            std::cout<< "Ingrese Email:" <<std::endl;
            std::cin.getline(email,100);
            std::cout<< "Ingrese fecha de nacimiento: "<<std::endl;
            Fecha fechaNacimiento = fecha.cargarFecha();
            Cliente clienteEditado(dni,nombre,apellido,telefono,email,fechaNacimiento);
            res = fwrite(&clienteEditado,sizeof(Cliente),1,archivo);
            fclose(archivo);
        }
    }
    fclose(archivo);
    if(res==1){
        std::cout<<" "<<std::endl;
        std::cout<<"\tOK: El cliente se modifico satisfactoriamente"<<std::endl;
        std::cout<<" "<<std::endl;
    } else {
        std::cout<<" "<<std::endl;
        std::cout<<"\tPor algun motivo no pudo modificarse los datos."<<std::endl;
        std::cout<<" "<<std::endl;
    }
}

// Mostrar CLIENTE REGISTRADO
void ClienteService::mostrarClienteRegistrado(Cliente cliente){
    std::cout<<"\t"<<cliente.getNombre()<<" "<<cliente.getApellido()<<" - email: "<<cliente.getEmail()<<std::endl;
};


/// ESTADISTICAS

float ClienteService::ventasXclienteAnio(char* dni,int anio){
    Venta venta;
    double importe=0;
    FILE *archivo;
    archivo = fopen(ARCHIVO_REGISTROVENTAS,"rb");
    while(fread(&venta,sizeof(Venta),1,archivo)==1){
      if(anio==venta.getFecha().getAnio()){
       if(strcmp(dni,venta.getDniCliente())==0){
        importe+=venta.getImporteVenta();
       }
      }}

    fclose(archivo);
    return importe;
}

float ClienteService::ventasXclienteMes(char* dni,int anio,int mes){
    Venta venta;
    double importe=0;
    FILE *archivo;
    archivo = fopen(ARCHIVO_REGISTROVENTAS,"rb");
    while(fread(&venta,sizeof(Venta),1,archivo)==1){
        if(anio==venta.getFecha().getAnio()){
        if(mes==venta.getFecha().getMes()){
         if(strcmp(dni,venta.getDniCliente())==0){
        importe+=venta.getImporteVenta();
         }
        }
      }
    }
    fclose(archivo);
    return importe;
}

Cliente ClienteService::clienteMayorGastoAnio(){
    Cliente cliente;
    Cliente clienteDeMayorGasto;
    double mayorGasto=0;
    int anio;
    std::cout<<"*************************************************"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\tMenu ESTADISTICAS CLIENTES"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\tIngrese anio buscado: ";
    std::cin>>anio;
    system("cls");
    FILE *archivo;
    archivo = fopen(ARCHIVO_CLIENTES,"rb");
    while(fread(&cliente,sizeof(Cliente),1,archivo)==1){
        double acuGasto=0;
        char dniCliente[9];
        strcpy(dniCliente,cliente.getDni());
        acuGasto=ventasXclienteAnio(dniCliente,anio);
        if(acuGasto>mayorGasto){
            mayorGasto=acuGasto;
            clienteDeMayorGasto=cliente;
        }
    }
    fclose(archivo);
    return clienteDeMayorGasto;
}

Cliente ClienteService::clienteMayorGastoMes(){
    Cliente cliente;
    Cliente clienteDeMayorGasto;
    double mayorGasto=0;
    int anio;
    int mes;
    std::cout<<"*************************************************"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\tMenu ESTADISTICAS CLIENTES"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\tIngrese anio buscado: ";
    std::cin>>anio;
    std::cout<<"\tIngrese mes buscado: ";
    std::cin>>mes;
    system("cls");
    FILE *archivo;
    archivo = fopen(ARCHIVO_CLIENTES,"rb");
    while(fread(&cliente,sizeof(Cliente),1,archivo)==1){
        double acuGasto=0;
        char dniCliente[9];
        strcpy(dniCliente,cliente.getDni());
        acuGasto=ventasXclienteMes(dniCliente,anio,mes);
        if(acuGasto>mayorGasto){
            mayorGasto=acuGasto;
            clienteDeMayorGasto=cliente;
        }
    }
    fclose(archivo);
    return clienteDeMayorGasto;
}
