#include "VentasService.h"
#include "ClienteService.h"
#include "LibroService.h"
#include "DetalleVenta.h"
#include <cstdio>
#include "string.h"
#include "../properties.h"
#include "Fecha.h"
#include "Genero.h"
#include "Editorial.h"
#include "menu.h"

#include "libxl.h"

using namespace libxl;

const char *ARCHIVO_EDITORIAL = "Editoriales.dat";
const char *ARCHIVO_GENEROS = "Generos.dat";

MedioDePago ms;
ClienteService cServ;
LibroService lServ;
Genero gSe;
Editorial eSe;
DetalleVenta detSer;

VentasService::VentasService(){};

/*****************************************************************************/

/// VENTAS

/// Devuelve una Venta segun un IdVenta
Venta VentasService::buscarVentaById(int id){
    Venta venta;
    FILE *archivo;
    Venta v;
    archivo = fopen(ARCHIVO_REGISTROVENTAS,"rb");
    while(fread(&v,sizeof(Venta),1,archivo)==1){
        if(v.getIdVenta()==id){
            venta = v;
        }
    }
    fclose(archivo);
    return venta;
};

/// Carga una Venta  (Metodo alternativo para cargar ventas)
Venta VentasService::cargarVenta(){
    std::cout << "CARGAR VENTA" <<std::endl;
    char dni[9];
    int idVenta = proximoIdVenta();
    int idLibro;
    double importeVenta;
    int idMedioDePago;
    Fecha fecha(11,8,2023);
    std::cin.ignore();
    std::cout << "Ingresar DNI CLIENTE" <<std::endl;
    std::cin.getline(dni,9);
    std::cout << "Ingresar ID LIBRO" <<std::endl;
    std::cin>>idLibro;
    std::cout << "Ingresar IMPORTE de VENTA" <<std::endl;
    std::cin>>importeVenta;
    std::cout << "Ingresar ID MEDIO de PAGO" <<std::endl;
    std::cin>>idMedioDePago;
    Venta v(idVenta,dni,idLibro,importeVenta,idMedioDePago,fecha);
    return v;
};

/// Guarda una Venta en el Archivo
void VentasService::registrarVenta(Venta venta){
    FILE *archivo;
    archivo = fopen(ARCHIVO_REGISTROVENTAS,"ab");
    fwrite(&venta,sizeof(Venta),1,archivo);
    fclose(archivo);
};

/// Muestra una Venta determinada
void VentasService::mostrarVenta(Venta v){
    std::cout << " Nro Venta: "<<v.getIdVenta()<<std::endl;
    std::cout << " Dni Cliente: "<<v.getDniCliente()<<std::endl;
    Libro libro = lServ.buscarLibroById(v.getIdLibro());
    std::cout << " LIBRO: "<<libro.getTitulo()<<std::endl;
    std::cout << " Importe: $"<<v.getImporteVenta()<<std::endl;
    MedioDePago medioDePago = buscarMedioDePagoById(v.getMedioDePago());
    std::cout << " Medio de Pago: "<<medioDePago.getNombre()<<std::endl;
    std::cout << " Fecha: "<<v.getFecha().fechaFormateada()<<std::endl;
    std::cout << "  "<<std::endl;
};

/// Leer Archivo de Ventas
void VentasService::leerArchivoVentas(){
    FILE *archivo;
    Venta v;
    archivo = fopen(ARCHIVO_REGISTROVENTAS,"rb");
    std::cout<<" "<< std::endl;
    std::cout<<"\tVentas en ARCHIVO"<<std::endl;
    std::cout<<" "<<std::endl;
    while(fread(&v,sizeof(Venta),1,archivo)==1){
        mostrarVenta(v);
    }
    std::cout<<" "<<std::endl;
    fclose(archivo);
};

/// Devuelve un DetalleVenta segun un IdVenta
DetalleVenta VentasService::detalleDeVenta(int idVenta){
    Venta v = buscarVentaById(idVenta);
    ///TODO: traer el cliente y el libro segun los id.
    Cliente c;
    Libro l;
    DetalleVenta d;
    return d;
};

/// Devuelve el proximo IdVenta (el mayor +1 )
int VentasService::proximoIdVenta(){
    FILE *archivo;
    Venta v;
    int id=0;
    archivo = fopen(ARCHIVO_REGISTROVENTAS,"rb");
    while(fread(&v,sizeof(Venta),1,archivo)==1){
        if(v.getIdVenta()>0){
            id=v.getIdVenta();
        }
    }
    fclose(archivo);
    return id+1;
};


/*****************************************************************************/

/// MEDIOS DE PAGO

/// Devuelve un MedioDePago ById
MedioDePago VentasService::buscarMedioDePagoById(int id){
    FILE *archivo;
    MedioDePago medio;
    archivo = fopen(ARCHIVO_MEDIOSDEPAGO,"rb");
    //if(existeMedioDePago(id)){
    if(true){
        while(fread(&medio,sizeof(MedioDePago),1,archivo)==1){
            if(medio.getId()==id){
                return medio;
            }
        }
        fclose(archivo);
    }
    fclose(archivo);
    return medio;
};

/// Existe Medio de Pago?
bool VentasService::existeMedio(int id){
    FILE *archivo;
    MedioDePago m;
    bool existe=false;
    archivo = fopen(ARCHIVO_MEDIOSDEPAGO,"rb");
    while(fread(&m,sizeof(MedioDePago),1,archivo)==1){
        if(m.getId()==id){
            existe=true;
        }
    }
    fclose(archivo);
    return existe;
};

/// Cargar un MedioDePago
MedioDePago VentasService::cargarMedioDePago(){
    char nombre[30];
    float recargo;
    int cantCuotas,id;
    std::cout << "Ingrese ID de Medio de Pago: ";
    std::cin>>id;
    std::cin.ignore();
    std::cout << "Ingrese NOMBRE de Medio de Pago: ";
    std::cin.getline(nombre,30);
    std::cout << "Ingrese Indice de RECARGO (Ejemplo: 1.21) ";
    std::cin>>recargo;
    std::cout << "Ingrese cantidad de CUOTAS: ";
    std::cin>>cantCuotas;
    MedioDePago m(id,nombre,recargo,cantCuotas);
    return m;
};


/// Registrar MedioDePago en Archivo.
void VentasService::registrarMedioDePago(MedioDePago medio){
    FILE *archivo;
    archivo = fopen(ARCHIVO_MEDIOSDEPAGO,"ab");
    fwrite(&medio,sizeof(MedioDePago),1,archivo);
    fclose(archivo);
};

/// Leer Archivo de Medios de Pago
void VentasService::leerArchivoMedioDePago(){
    FILE *archivo;
    MedioDePago m;
    archivo = fopen(ARCHIVO_MEDIOSDEPAGO,"rb");
    std::cout<<" "<< std::endl;
    std::cout<<"\tVentas en ARCHIVO"<<std::endl;
    std::cout<<" "<<std::endl;
    while(fread(&m,sizeof(MedioDePago),1,archivo)==1){
        mostrarMedioDePago(m);
    }
    std::cout<<" "<<std::endl;
    fclose(archivo);
};

/// Mostrar Medio de Pago
void VentasService::mostrarMedioDePago(MedioDePago m){
    std::cout<<"ID: "<< m.getId()<< std::endl;
    std::cout<<"NOMBRE: "<< m.getNombre()<< std::endl;
    std::cout<<"RECARGO: "<< m.getRecargo()<<std::endl;
    std::cout<<"Cant CUOTAS: "<< m.getCantCuotas()<< std::endl;
};

/// Mostrar Medio De Pago (para elegir medio)
void VentasService::mostrarMedioDePagoMenu(MedioDePago m){
    std::cout<<"ID: "<< m.getId()<<" - "<< m.getNombre()<<" - Cuotas: " << m.getCantCuotas()<< std::endl;
};

/// Mostrar Medio De Pago (1 linea)
void VentasService::mostrarMedioDePagoDetalle(MedioDePago m){
    std::cout<<"\t"<<m.getNombre()<<" - Cuotas: " << m.getCantCuotas()<<" - (Rec:"<<m.getRecargo()<<")"<<std::endl;
};


void VentasService::leerArchivoMedioDePagoMenu(){
    FILE *archivo;
    MedioDePago m;
    archivo = fopen(ARCHIVO_MEDIOSDEPAGO,"rb");
    std::cout<<" "<< std::endl;
    std::cout<<"\tMedios de Pago Disponibles"<<std::endl;
    std::cout<<" "<<std::endl;
    while(fread(&m,sizeof(MedioDePago),1,archivo)==1){
        mostrarMedioDePagoMenu(m);
    }
    std::cout<<" "<<std::endl;
    fclose(archivo);
};

/// Modificar MedioDePago
void VentasService::modificarMedioDePago(MedioDePago medio){
    FILE *archivo;
    int res=-1;
    MedioDePago m;
    archivo = fopen(ARCHIVO_MEDIOSDEPAGO,"rb+");
    while(fread(&m,sizeof(MedioDePago),1,archivo)==1){
        if(medio.getId()==m.getId()){
            std::cin.ignore();
            fseek(archivo,ftell(archivo)-sizeof(MedioDePago),0);
            std::cout<<"\tIngrese los datos del Medio de Pago a modificar"<<std::endl;
            std::cout<<" "<<std::endl;
            std::cout<<" Ingrese NOMBRE: ";
            char nombre[30];
            std::cin.getline(nombre,30);
            m.setNombre(nombre);
            std::cout<<" Ingrese RECARGO: ";
            float recargo;
            std::cin>>recargo;
            m.setRecargo(recargo);
            std::cout<<" Ingrese cant CUOTAS: ";
            int cantCuotas;
            std::cin>>cantCuotas;
            m.setCantCuotas(cantCuotas);
            res = fwrite(&m,sizeof(MedioDePago),1,archivo);
            fclose(archivo);
        }
    }
}

/// Devuelve el RECARGO segun el id elegido.
float VentasService::devolverRecargo(int id){
    MedioDePago medio = buscarMedioDePagoById(id);
    return medio.getRecargo();
}

/*****************************************************************************/

/// Carga VENTA desde MENU
Venta VentasService::cargarVentaDesdeMenu(){
    Fecha fS;
    char dni[9];
    int idVenta = proximoIdVenta();
    int idLibro;
    double importeVenta;
    int idMedioDePago;
    std::cout << "\tIngresar ID LIBRO: ";
    std::cin>>idLibro;
    Libro libro;
    Cliente cliente;
    if(lServ.existeLibro(idLibro)){
        libro = lServ.buscarLibroById(idLibro);
        std::cout << " "<<std::endl;
        std::cout << "\tLibro: "<<std::endl;
        lServ.infoBasicaLibro(idLibro);
        std::cout << " "<<std::endl;
        if(libro.getStock()==0){
            std::cout << " "<<std::endl;
            std::cout << "\tLamentablemente NO hay Stock del libro elegido."<<std::endl;
            std::cout << " "<<std::endl;
            system("pause");
            menuVentas();
        }
    } else {
        std::cout << " "<<std::endl;
        std::cout << "\tId Incorrecto. Ese libro no esta registrado, por favor buscar nuevamente."<<std::endl;
        std::cout << " "<<std::endl;
        system("pause");
        menuBuscarLibro();
    }
    std::cin.ignore();
    std::cout << "\tIngresar DNI CLIENTE: ";
    std::cin.getline(dni,9);
    if(cServ.existeCliente(dni)){
        cliente = cServ.buscarClientexDni(dni);
        std::cout << " "<<std::endl;
        std::cout << "\tCliente: "<<std::endl;
        cServ.mostrarClienteRegistrado(cliente);
        std::cout << " "<<std::endl;
    } else {
        std::cout << " "<<std::endl;
        std::cout << "\tEse Cliente NO esta registrado. POr favor cargue los datos del cliente."<<std::endl;
        std::cout << " "<<std::endl;
        system("pause");
        menuClientes();
    }
    std::cout << "\tEl importe a pagar es: $"<<libro.getPrecio()<< " , de que forma desea abonarlo?"<<std::endl;;
    leerArchivoMedioDePagoMenu();
    std::cout << "Ingresar ID MEDIO de PAGO: ";
    std::cin>>idMedioDePago;
    bool existe=false;
    do{
        existe = existeMedio(idMedioDePago);
        if(!existe){
            std::cout<<"\tID invalido. Elija uno correcto."<<std::endl;
            std::cout << " ";
            std::cout << "Ingresar ID MEDIO de PAGO: ";
            int id;
            std::cin>>id;
            idMedioDePago=id;
        }
    }while(!existe);
    float recargo = devolverRecargo(idMedioDePago);
    double importeTotal = aplicarRecargo(libro.getPrecio(),recargo);
    std::cout << "Medio de pago elegido: "<<std::endl;
    MedioDePago m=buscarMedioDePagoById(idMedioDePago);
    mostrarMedioDePagoMenu(m);
    std::cout << "IMPORTE TOTAL: $"<<importeTotal<<std::endl;
    std::cout << " "<<std::endl;
    std::cout << "Ingresar Fecha:" <<std::endl;
    Fecha fecha = fS.cargarFecha();
    Venta v(idVenta,dni,idLibro,importeTotal,idMedioDePago,fecha);
    return v;
};

/// Buscar y  Mostrar Venta
void VentasService::buscarYMostrarVenta(int id){
    bool existe = existeVenta(id);
    if(existe){
        system("cls");
        generarComprobante(id);
    } else {
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tEl numero de venta NO esta registrado."<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
    }
}

/// Existe Venta?
bool VentasService::existeVenta(int id){
    bool existe = false;
    FILE *archivo;
    Venta v;
    archivo = fopen(ARCHIVO_REGISTROVENTAS,"rb");
    while(fread(&v,sizeof(Venta),1,archivo)==1){
        if(v.getIdVenta()==id){
            existe=true;
        }
    }
    fclose(archivo);
    return existe;
};

/// Generar Comprobante
void VentasService::generarComprobante(int id){
    FILE *archivo;
    Venta v;
    Venta venta;
    archivo = fopen(ARCHIVO_REGISTROVENTAS,"rb");
    while(fread(&v,sizeof(Venta),1,archivo)==1){
        if(v.getIdVenta()==id){
            venta=v;
        }
    }
    fclose(archivo);
    DetalleVenta dVS;
    dVS.imprimirDetalle(venta);
};

/// Listar VENTAS por DNI Cliente
void VentasService::ventasByCliente(){
    char dni[9];
    //std::cin.ignore();
    std::cout<<"\tIngrese el DNI del Cliente: ";
    std::cin.getline(dni,9);
    bool existe = cServ.existeCliente(dni);
    Cliente cliente = cServ.buscarClientexDni(dni);
    int tieneVenta=0;
    if(existe){
        std::cout<<" "<<std::endl;
        std::cout<<"\tCliente Registrado:"<<std::endl;
        std::cout<<" "<<std::endl;
        cServ.mostrarClienteRegistrado(cliente);
        if(existeVentaByDni(dni)){
            std::cout<<" "<<std::endl;
            std::cout<<"\tHa realizado las siguientes compras: "<<std::endl;
        }
        FILE *archivo;
        Venta v;
        archivo = fopen(ARCHIVO_REGISTROVENTAS,"rb");
        while(fread(&v,sizeof(Venta),1,archivo)==1){
            if(strcmp(v.getDniCliente(),dni)==0){
                tieneVenta++;
                DetalleVenta detalle(v);
                mostrarDetalleReducido(detalle);
            }
        }
        fclose(archivo);
        if(tieneVenta==0){
            std::cout<<" "<<std::endl;
            std::cout<<"\tEl cliente NO ha realizado ninguna compra."<<std::endl;
            std::cout<<" "<<std::endl;
        }
    } else {
        std::cout<<" "<<std::endl;
        std::cout<<"\tEl dni NO pertenece a ningun Cliente Registrado"<<std::endl;
        std::cout<<" "<<std::endl;
    }
}

void VentasService::mostrarDetalleReducido(DetalleVenta detalle){
    std::cout<<"\tNro: "<<detalle.getIdVenta()<<" - Libro: "<<detalle.getTituloLibro()<<" - $"<<detalle.getImporteVenta()<<" - Fecha: "<<detalle.getFecha().fechaFormateada()<<std::endl;
}

bool VentasService::existeVentaByDni(char * dni){
    bool existe = false;
    FILE *archivo;
    Venta v;
    archivo = fopen(ARCHIVO_REGISTROVENTAS,"rb");
    while(fread(&v,sizeof(Venta),1,archivo)==1){
        if(strcmp(v.getDniCliente(),dni)==0){
            existe=true;
        }
    }
    fclose(archivo);
    return existe;
};

bool VentasService::existeVentaByIdGenero(int id){
    bool existe = false;
    FILE *archivo;
    Venta v;
    archivo = fopen(ARCHIVO_REGISTROVENTAS,"rb");
    while(fread(&v,sizeof(Venta),1,archivo)==1){
        Libro libro = lServ.buscarLibroById(v.getIdLibro());
        if(libro.getIdGenero()==id){
            existe=true;
        }
    }
    fclose(archivo);
    return existe;
};

bool VentasService::existeVentaByIdEditorial(int id){
    bool existe = false;
    FILE *archivo;
    Venta v;
    archivo = fopen(ARCHIVO_REGISTROVENTAS,"rb");
    while(fread(&v,sizeof(Venta),1,archivo)==1){
        Libro libro = lServ.buscarLibroById(v.getIdLibro());
        if(libro.getIdEditorial()==id){
            existe=true;
        }
    }
    fclose(archivo);
    return existe;
};

bool VentasService::existeVentaByIdMedio(int id){
    bool existe = false;
    FILE *archivo;
    Venta v;
    archivo = fopen(ARCHIVO_REGISTROVENTAS,"rb");
    while(fread(&v,sizeof(Venta),1,archivo)==1){
        if(v.getMedioDePago()==id){
            existe=true;
        }
    }
    fclose(archivo);
    return existe;
};

// Listar VENTAS por DNI Genero
void VentasService::ventasByGenero(){
    int idGenero;
    std::cin.ignore();
    std::cout<<" Generos Disponibles: "<<std::endl;
    gSe.leerArchivoGenerosActivos2();
    std::cout<<"\tIngrese el ID del Genero: ";
    std::cin>>idGenero;
    bool existeG = gSe.existeGenero(idGenero);
    int tieneVenta=0;
    if(existeG){
        if(existeVentaByIdGenero(idGenero)){
            std::cout<<" "<<std::endl;
            std::cout<<"\tSe han realizado las siguientes compras: "<<std::endl;
        }
        FILE *archivo;
        Venta v;
        archivo = fopen(ARCHIVO_REGISTROVENTAS,"rb");
        while(fread(&v,sizeof(Venta),1,archivo)==1){
            Libro libro = lServ.buscarLibroById(v.getIdLibro());
            if(libro.getIdGenero()==idGenero){
                tieneVenta++;
                DetalleVenta detalle(v);
                mostrarDetalleReducido(detalle);
            }
        }
        fclose(archivo);
        if(tieneVenta==0){
            std::cout<<" "<<std::endl;
            std::cout<<"\tEl Genero No tuvo ninguna Venta asociada."<<std::endl;
            std::cout<<" "<<std::endl;
        }
    } else {
        std::cout<<" "<<std::endl;
        std::cout<<"\tId de Genero Incorrecto"<<std::endl;
        std::cout<<" "<<std::endl;
    }
}

// Listar VENTAS por DNI Genero
void VentasService::ventasByEditorial(){
    int idEditorial;
    std::cin.ignore();
    std::cout<<" Editoriales Disponibles: "<<std::endl;
    eSe.leerArchivoEditorial2();
    std::cout<<"\tIngrese el ID de la Editorial: ";
    std::cin>>idEditorial;
    bool existeE = eSe.existeEditorial(idEditorial);
    int tieneVenta=0;
    if(existeE){
        if(existeVentaByIdEditorial(idEditorial)){
            std::cout<<" "<<std::endl;
            std::cout<<"\tSe han realizado las siguientes compras: "<<std::endl;
        }
        FILE *archivo;
        Venta v;
        archivo = fopen(ARCHIVO_REGISTROVENTAS,"rb");
        while(fread(&v,sizeof(Venta),1,archivo)==1){
            Libro libro = lServ.buscarLibroById(v.getIdLibro());
            if(libro.getIdEditorial()==idEditorial){
                tieneVenta++;
                DetalleVenta detalle(v);
                mostrarDetalleReducido(detalle);
            }
        }
        fclose(archivo);
        if(tieneVenta==0){
            std::cout<<" "<<std::endl;
            std::cout<<"\tLa editorial No tuvo ninguna Venta asociada."<<std::endl;
            std::cout<<" "<<std::endl;
        }
    } else {
        std::cout<<" "<<std::endl;
        std::cout<<"\tId de Editorial Incorrecto"<<std::endl;
        std::cout<<" "<<std::endl;
    }
}

// Listar VENTAS por DNI MEDIO DE PAGO
void VentasService::ventasByMedioDePago(){
    int id;
    std::cin.ignore();
    std::cout<<" Medios de Pago Disponibles: "<<std::endl;
    leerArchivoMedioDePagoMenu();
    std::cout<<"\tIngrese el ID de Medio De Pago: ";
    std::cin>>id;
    bool existeM = existeMedio(id);
    int tieneVenta=0;
    if(existeM){
        if(existeVentaByIdMedio(id)){
            std::cout<<" "<<std::endl;
            std::cout<<"\tSe han realizado las siguientes compras: "<<std::endl;
        }
        FILE *archivo;
        Venta v;
        archivo = fopen(ARCHIVO_REGISTROVENTAS,"rb");
        while(fread(&v,sizeof(Venta),1,archivo)==1){
            if(v.getMedioDePago()==id){
                tieneVenta++;
                DetalleVenta detalle(v);
                mostrarDetalleReducido(detalle);
            }
        }
        fclose(archivo);
        if(tieneVenta==0){
            std::cout<<" "<<std::endl;
            std::cout<<"\tEl Medio de Pago No tuvo ninguna Venta asociada."<<std::endl;
            std::cout<<" "<<std::endl;
        }
    } else {
        std::cout<<" "<<std::endl;
        std::cout<<"\tId de Medio de Pago Incorrecto"<<std::endl;
        std::cout<<" "<<std::endl;
    }
}

// Contar Ventas entre FECHAS
int VentasService::contarVentasEntreFechas(Fecha fechaDesde,Fecha fechaHasta){
    int cant=0;
    FILE *archivo;
    Venta v;
    archivo = fopen(ARCHIVO_REGISTROVENTAS,"rb");
    while(fread(&v,sizeof(Venta),1,archivo)==1){
        if(v.getFecha().esAnteriorA(fechaHasta)&&v.getFecha().esPosteriorA(fechaDesde)){
            cant++;
        }
    }
    fclose(archivo);
    return cant;
}

// Listar Ventas entre FECHAS
void VentasService::ventasEntreFechas(){
    Fecha fS;
    std::cin.ignore();
    std::cout<<" Ingrese la FECHA DESDE: "<<std::endl;
    Fecha fechaDesde = fS.cargarFecha();
    std::cout<<" Ingrese la FECHA HASTA: "<<std::endl;
    Fecha fechaHasta = fS.cargarFecha();
    std::cin.ignore();
    int cantVentas = contarVentasEntreFechas(fechaDesde,fechaHasta);
    if(cantVentas>0){
        std::cout<<" "<<std::endl;
        std::cout<<"\tVentas entre el "<<fechaDesde.fechaFormateada()<<" y el "<<fechaHasta.fechaFormateada()<<std::endl;
        std::cout<<" "<<std::endl;
        FILE *archivo;
        Venta v;
        archivo = fopen(ARCHIVO_REGISTROVENTAS,"rb");
        while(fread(&v,sizeof(Venta),1,archivo)==1){
            if(v.getFecha().esAnteriorA(fechaHasta)&&v.getFecha().esPosteriorA(fechaDesde)){
                DetalleVenta detalle(v);
                mostrarDetalleReducido(detalle);
            }
        }
        fclose(archivo);
    } else {
        std::cout<<" "<<std::endl;
        std::cout<<"\tNo se realizaron Ventas entre las fechas dadas."<<std::endl;
        std::cout<<" "<<std::endl;
    }
}




// Aplicar recargo segun Medio de Pago
double VentasService::aplicarRecargo(double importe, float recargo){
    return importe*recargo;
}

/*****************************************************************************/

/// ESTADISTICAS

/// Recaudacion Total TOTAL
double VentasService::recaudacionTotal(){
    double recaudacionTotal=0;
    FILE *archivo;
    Venta v;
    archivo = fopen(ARCHIVO_REGISTROVENTAS,"rb");
    while(fread(&v,sizeof(Venta),1,archivo)==1){
        recaudacionTotal+=v.getImporteVenta();
    }
    fclose(archivo);
    return recaudacionTotal;
}

/// Recaudacion por MES por ANIO
void VentasService::recaudacionTotal(int anio){
    double recaudacionPorMes[12]={};
    FILE *archivo;
    Venta v;
    archivo = fopen(ARCHIVO_REGISTROVENTAS,"rb");
    while(fread(&v,sizeof(Venta),1,archivo)==1){
        if(v.getFecha().getAnio()==anio){
            int mes=v.getFecha().getMes();
            recaudacionPorMes[mes-1]+=v.getImporteVenta();
        }
    }
    fclose(archivo);
    for(int x=0;x<12;x++){
        if(recaudacionPorMes[x]!=0){
            std::cout<<"\tEn el mes "<<x+1<<" se recaudaron $"<<recaudacionPorMes[x]<<std::endl;
        }

    }
}

/// Recaudacion por ANIO
double VentasService::recaudacionTotalAnual(int anio){
    double recaudacionAnual=0;
    FILE *archivo;
    Venta v;
    archivo = fopen(ARCHIVO_REGISTROVENTAS,"rb");
    while(fread(&v,sizeof(Venta),1,archivo)==1){
        if(v.getFecha().getAnio()==anio){
            recaudacionAnual+=v.getImporteVenta();
        }
    }
    fclose(archivo);
    return recaudacionAnual;
}

/// BALANCE de VENTAS By EDITORIAL TOTAL
void VentasService::recaudacionByEditorial(){
    double editorialMayorVenta=0;
    int idMayorVenta;
    FILE *archivo;
    Editorial e;
    archivo = fopen(ARCHIVO_EDITORIAL,"rb");
    while(fread(&e,sizeof(Editorial),1,archivo)==1){
        double recaudacionEditorial=0;
        recaudacionEditorial = ventasPorEditorial(e.getIdEditorial());
        if(recaudacionEditorial!=0){
            std::cout<<"\tEditorial "<<e.getNombre()<<" recaudo $"<<recaudacionEditorial<<std::endl;
        }
        if(recaudacionEditorial>editorialMayorVenta){
            editorialMayorVenta=recaudacionEditorial;
            idMayorVenta=e.getIdEditorial();
        }
    }
    fclose(archivo);
    std::cout<<" "<<std::endl;
    Editorial edit = eSe.buscarEditorialById(idMayorVenta);
    std::cout<<"\tLa Editorial de mayor recaudacion es "<<edit.getNombre()<<std::endl;
    std::cout<<"\tHa recaudado $"<<editorialMayorVenta<<std::endl;
    std::cout<<" "<<std::endl;
};

double VentasService::ventasPorEditorial(int idEditorial){
    double recaudacionEditorial=0;
    FILE *archivo;
    Venta v;
    archivo = fopen(ARCHIVO_REGISTROVENTAS,"rb");
    while(fread(&v,sizeof(Venta),1,archivo)==1){
        Libro libro = lServ.buscarLibroById(v.getIdLibro());
        if(libro.getIdEditorial()==idEditorial){
            recaudacionEditorial+=v.getImporteVenta();
        }
    }
    fclose(archivo);
    return recaudacionEditorial;
}

/// BALANCE de VENTAS By EDITORIAL By ANIO
void VentasService::recaudacionByEditorial(int anio){
    double editorialMayorVenta=0;
    int idMayorVenta;
    FILE *archivo;
    Editorial e;
    archivo = fopen(ARCHIVO_EDITORIAL,"rb");
    while(fread(&e,sizeof(Editorial),1,archivo)==1){
        double recaudacionEditorial=ventasPorEditorial(e.getIdEditorial(),anio);
        if(recaudacionEditorial!=0){
            std::cout<<"\tEditorial "<<e.getNombre()<<" recaudo $"<<recaudacionEditorial<<std::endl;
        }
        if(recaudacionEditorial>editorialMayorVenta){
            editorialMayorVenta=recaudacionEditorial;
            idMayorVenta=e.getIdEditorial();
        }
    }
    fclose(archivo);
    if(editorialMayorVenta!=0){
        std::cout<<" "<<std::endl;
        Editorial edit = eSe.buscarEditorialById(idMayorVenta);
        std::cout<<"\tLa Editorial de mayor recaudacion es "<<edit.getNombre()<<std::endl;
        std::cout<<"\tHa recaudado $"<<editorialMayorVenta<<std::endl;
    } else {
        std::cout<<" "<<std::endl;
        std::cout<<"\tSnif Snif, no hubo ventas."<<std::endl;
        std::cout<<" "<<std::endl;
    }
};

double VentasService::ventasPorEditorial(int idEditorial,int anio){
    double recaudacionEditorial=0;
    FILE *archivo;
    Venta v;
    archivo = fopen(ARCHIVO_REGISTROVENTAS,"rb");
    while(fread(&v,sizeof(Venta),1,archivo)==1){
        if(v.getFecha().getAnio()==anio){
            Libro libro = lServ.buscarLibroById(v.getIdLibro());
            if(libro.getIdEditorial()==idEditorial){
                recaudacionEditorial+=v.getImporteVenta();
            }
        }
    }
    fclose(archivo);
    return recaudacionEditorial;
}


/// BALANCE de VENTAS By GENERO TOTAL
void VentasService::recaudacionByGenero(){
    double generoMayorVenta=0;
    int idMayorVenta;
    FILE *archivo;
    Genero g;
    archivo = fopen(ARCHIVO_GENEROS,"rb");
    while(fread(&g,sizeof(Genero),1,archivo)==1){
        double recaudacionGenero=ventasPorGenero(g.getIdGenero());
        if((recaudacionGenero!=0)&&(g.getActivo())){
            std::cout<<"\tGenero: "<<g.getGenero()<<" | Recaudacion: $"<<recaudacionGenero<<std::endl;
        }
        if(recaudacionGenero>generoMayorVenta){
            generoMayorVenta=recaudacionGenero;
            idMayorVenta=g.getIdGenero();
        }
    }
    fclose(archivo);
    std::cout<<" "<<std::endl;
    Genero genero = gSe.buscarGeneroById(idMayorVenta);
    std::cout<<"\tEl Genero de mayor recaudacion es "<<genero.getGenero()<<std::endl;
    std::cout<<"\tHa recaudado $"<<generoMayorVenta<<std::endl;
    std::cout<<" "<<std::endl;
};

double VentasService::ventasPorGenero(int idGenero){
    double recaudacionGenero=0;
    FILE *archivo;
    Venta v;
    archivo = fopen(ARCHIVO_REGISTROVENTAS,"rb");
    while(fread(&v,sizeof(Venta),1,archivo)==1){
            Genero genero = gSe.buscarGeneroById(idGenero);
        Libro libro = lServ.buscarLibroById(v.getIdLibro());
        if((libro.getIdGenero()==idGenero)&&(genero.getActivo())){
            recaudacionGenero+=v.getImporteVenta();
        }
    }
    fclose(archivo);
    return recaudacionGenero;
}


/// BALANCE de VENTAS By GENERO By ANIO
void VentasService::recaudacionByGenero(int anio){
    double generoMayorVenta=0;
    int idMayorVenta;
    FILE *archivo;
    Genero g;
    archivo = fopen(ARCHIVO_GENEROS,"rb");
    while(fread(&g,sizeof(Genero),1,archivo)==1){
        double recaudacionGenero=ventasPorGenero(g.getIdGenero(),anio);
        if((recaudacionGenero!=0)&&(g.getActivo())){
            std::cout<<"\tGenero: "<<g.getGenero()<<" | Recaudacion: $"<<recaudacionGenero<<std::endl;
        }
        if(recaudacionGenero>generoMayorVenta){
            generoMayorVenta=recaudacionGenero;
            idMayorVenta=g.getIdGenero();
        }
    }
    fclose(archivo);
    std::cout<<" "<<std::endl;
    Genero genero = gSe.buscarGeneroById(idMayorVenta);
    std::cout<<"\tEl Genero de mayor recaudacion es "<<genero.getGenero()<<std::endl;
    std::cout<<"\tHa recaudado $"<<generoMayorVenta<<std::endl;
    std::cout<<" "<<std::endl;
};

double VentasService::ventasPorGenero(int idGenero,int anio){
    double recaudacionGenero=0;
    FILE *archivo;
    Venta v;
    archivo = fopen(ARCHIVO_REGISTROVENTAS,"rb");
    while(fread(&v,sizeof(Venta),1,archivo)==1){
        Genero genero = gSe.buscarGeneroById(idGenero);
        Libro libro = lServ.buscarLibroById(v.getIdLibro());
        if((libro.getIdGenero()==idGenero)&&(genero.getActivo())&&(v.getFecha().getAnio()==anio)){
            recaudacionGenero+=v.getImporteVenta();
        }
    }
    fclose(archivo);
    return recaudacionGenero;
}


/// BALANCE de VENTAS By MEDIO DE PAGO
void VentasService::recaudacionByMedio(){
    double medioMayorVenta=0;
    int idMayorVenta;
    FILE *archivo;
    MedioDePago m;
    archivo = fopen(ARCHIVO_MEDIOSDEPAGO,"rb");
    while(fread(&m,sizeof(MedioDePago),1,archivo)==1){
        double recaudacionMedio=ventasPorMedioDePago(m.getId());
        if((recaudacionMedio!=0)){
            std::cout<<"\tMedio de Pago: "<<m.getNombre()<<" | Recaudacion: $"<<recaudacionMedio<<std::endl;
        }
        if(recaudacionMedio>medioMayorVenta){
            medioMayorVenta=recaudacionMedio;
            idMayorVenta=m.getId();
        }
    }
    fclose(archivo);
    std::cout<<" "<<std::endl;
    MedioDePago medio = buscarMedioDePagoById(idMayorVenta);
    std::cout<<"\tEl Medio de Pago de mayor recaudacion es "<<medio.getNombre()<<std::endl;
    std::cout<<"\tHa recaudado $"<<medioMayorVenta<<std::endl;
    std::cout<<" "<<std::endl;
};

double VentasService::ventasPorMedioDePago(int idMedio){
    double recaudacionMedio=0;
    FILE *archivo;
    Venta v;
    archivo = fopen(ARCHIVO_REGISTROVENTAS,"rb");
    while(fread(&v,sizeof(Venta),1,archivo)==1){
        if(v.getMedioDePago()==idMedio){
            recaudacionMedio+=v.getImporteVenta();
        }
    }
    fclose(archivo);
    return recaudacionMedio;
}

/// BALANCE de VENTAS By MEDIO DE PAGO BY ANIO
void VentasService::recaudacionByMedio(int anio){
    double medioMayorVenta=0;
    int idMayorVenta;
    FILE *archivo;
    MedioDePago m;
    archivo = fopen(ARCHIVO_MEDIOSDEPAGO,"rb");
    while(fread(&m,sizeof(MedioDePago),1,archivo)==1){
        double recaudacionMedio=ventasPorMedioDePago(m.getId(),anio);
        if((recaudacionMedio!=0)){
            std::cout<<"\tMedio de Pago: "<<m.getNombre()<<" | Recaudacion: $"<<recaudacionMedio<<std::endl;
        }
        if(recaudacionMedio>medioMayorVenta){
            medioMayorVenta=recaudacionMedio;
            idMayorVenta=m.getId();
        }
    }
    fclose(archivo);
    std::cout<<" "<<std::endl;
    MedioDePago medio = buscarMedioDePagoById(idMayorVenta);
    std::cout<<"\tEl Medio de Pago de mayor recaudacion es "<<medio.getNombre()<<std::endl;
    std::cout<<"\tHa recaudado $"<<medioMayorVenta<<std::endl;
    std::cout<<" "<<std::endl;
};

double VentasService::ventasPorMedioDePago(int idMedio,int anio){
    double recaudacionMedio=0;
    FILE *archivo;
    Venta v;
    archivo = fopen(ARCHIVO_REGISTROVENTAS,"rb");
    while(fread(&v,sizeof(Venta),1,archivo)==1){
        if((v.getMedioDePago()==idMedio)&&(v.getFecha().getAnio()==anio)){
            recaudacionMedio+=v.getImporteVenta();
        }
    }
    fclose(archivo);
    return recaudacionMedio;
}

void VentasService::recaudacionByTitulo(){
    Libro libro = lServ.buscarLibroByTitulo();
    double recaudacion = ventasPorTitulo(libro.getIdLibro());
    if(recaudacion!=0){
        std::cout<<" "<<std::endl;
        std::cout<<"\tTitulo: "<<libro.getTitulo()<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"\tHa recaudado: $"<<recaudacion<<std::endl;
        std::cout<<" "<<std::endl;
    }

}

double VentasService::ventasPorTitulo(int idLibro){
    double recaudacionTitulo=0;
    FILE *archivo;
    Venta v;
    archivo = fopen(ARCHIVO_REGISTROVENTAS,"rb");
    while(fread(&v,sizeof(Venta),1,archivo)==1){
        if(v.getIdLibro()==idLibro){
            recaudacionTitulo+=v.getImporteVenta();
        }
    }
    fclose(archivo);
    return recaudacionTitulo;
}

/// IMPRIMIR BOLETA de VENTA
void VentasService::imprimirBoleta(int idVenta){
    Venta venta = buscarVentaById(idVenta);
    Libro libro = lServ.buscarLibroById(venta.getIdLibro());
    DetalleVenta detalle = DetalleVenta(venta);
    Book* book = xlCreateBook();
    if (book){
        Sheet* hoja = book->addSheet("Recibo de Venta");
        if (hoja){
            Format* campos = book->addFormat();
            Font* font = book->addFont();
            font->setSize(12);
            font->setBold(true);
            campos->setFont(font);
            campos->setFillPattern(FILLPATTERN_SOLID);
            campos->setPatternForegroundColor(COLOR_GRAY25);
            campos->setBorder(BORDERSTYLE_THIN);
            campos->setAlignH(ALIGNH_CENTER);
            campos->setAlignV(ALIGNV_CENTER);
            Format* datos = book->addFormat();
            datos->setBorder(BORDERSTYLE_THIN);
            datos->setAlignH(ALIGNH_CENTER);
            datos->setAlignV(ALIGNV_CENTER);
            hoja->setCol(0, 0, 10);
            hoja->setCol(1, 1, 800);
            hoja->setCol(2, 2, 50);
            hoja->writeStr(1, 1, "LIBRERIA IOSTREAM:",campos);
            hoja->writeStr(3, 1, "Venta Nro:",campos);
            hoja->writeStr(5, 1, "Libro:",campos);
            hoja->writeStr(6, 1, "Autor:",campos);
            hoja->writeStr(7, 1, "Editorial:",campos);
            hoja->writeStr(8, 1, "Precio Unitario:",campos);
            hoja->writeStr(10, 1, "Medio De Pago:",campos);
            hoja->writeStr(11, 1, "Precio Final:",campos);
            hoja->writeStr(13, 1, "Cliente:",campos);
            hoja->writeStr(14, 1, "Dni Cliente:",campos);
            hoja->writeStr(15, 1, "Email:",campos);
            hoja->writeStr(16, 1, "Telefono:",campos);
            /// DATOS VENTA
            hoja->writeNum(3, 2, detalle.getIdVenta(),datos);
            hoja->writeStr(5, 2, detalle.getTituloLibro(),datos);
            char autors[80]={};
            strcat(autors,detalle.getNombreAutor());
            strcat(autors," ");
            strcat(autors,detalle.getApellidoAutor());
            hoja->writeStr(6, 2, autors,datos);
            hoja->writeStr(7, 2, detalle.getEditorialLibro(),datos);
            hoja->writeNum(8, 2,libro.getPrecio(),datos);
            MedioDePago medio = buscarMedioDePagoById(detalle.getMedioDePago());
            hoja->writeStr(10, 2, medio.getNombre(),datos);
            hoja->writeNum(11, 2, venta.getImporteVenta(),datos);
            char cliente[80]={};
            strcat(cliente,detalle.getNombreCliente());
            strcat(cliente," ");
            strcat(cliente,detalle.getApellidoCliente());
            hoja->writeStr(13, 2, cliente,datos);
            hoja->writeStr(14, 2, detalle.getDniCliente(),datos);
            hoja->writeStr(15, 2, detalle.getEmailCliente(),datos);
            hoja->writeStr(16, 2, detalle.getTelefonoCliente(),datos);
        }
        char boleta[30]={};
        char numeroVenta[10]={};
        sprintf(numeroVenta, "%d", idVenta);
        strcat(boleta,"Venta-Nro-");
        strcat(boleta,numeroVenta);
        strcat(boleta,".xls");
        book->save(boleta);
        std::cout<<" "<<std::endl;
        std::cout<<"\tArchivo descargado: "<<boleta<<std::endl;
        std::cout<<" "<<std::endl;
        book->release();
    }
}

