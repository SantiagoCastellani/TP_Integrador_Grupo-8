#include "DetalleVenta.h"
#include "string.h"
#include "VentasService.h"
#include "ClienteService.h"
#include "Cliente.h"
#include "LibroService.h"
#include "MedioDePago.h"
#include "Editorial.h"
#include "Genero.h"
#include "Autor.h"

ClienteService cS;
LibroService lS;
VentasService vS;
MedioDePago mS;
Editorial eS;
Genero gS;
Autor aS;

DetalleVenta::DetalleVenta()
{
    _idVenta=0;
    _dniCliente;
    strcpy(_dniCliente,"00000000");
    strcpy(_nombreCliente,"0000");
    strcpy(_apellidoCliente,"0000");
    strcpy(_telefonoCliente,"0000");
    strcpy(_emailCliente,"0000");
    strcpy(_tituloLibro,"0000");
    strcpy(_nombreAutor,"0000");
    strcpy(_apellidoAutor,"0000");
    strcpy(_editorialLibro,"0000");
    _importeVenta=0.00;
    _medioDePago=0;
    _fecha=Fecha();
}

// Detalle Venta Completo
DetalleVenta::DetalleVenta(
             int idVenta,
             char dniCli[9],
             char nombreCli[25],
             char apellidoCli[24],
             char telefonoCli[15],
             char emailCli[100],
             char tituloLi[100],
             char nombreAutor[25],
             char apellidoAutor[24],
             char editorialLi[30],
             double importeVenta,
             int medioPago,
             Fecha fecha )
{
    this->_idVenta=idVenta;
    strcpy(_dniCliente,dniCli);
    strcpy(_nombreCliente,nombreCli);
    strcpy(_telefonoCliente,telefonoCli);
    strcpy(_emailCliente,emailCli);
    strcpy(_tituloLibro,tituloLi);
    strcpy(_nombreAutor,nombreAutor);
    strcpy(_apellidoAutor,apellidoAutor);
    strcpy(_editorialLibro,editorialLi);
    this->_importeVenta=importeVenta;
    this->_medioDePago=medioPago;
    this->_fecha=fecha;
}


// Detalle Venta By Venta
DetalleVenta::DetalleVenta(Venta venta){
    char dni[9];
    strcpy(dni,venta.getDniCliente());
    Cliente cliente = cS.buscarClientexDni(dni);
    Libro libro = lS.buscarLibroById(venta.getIdLibro());
    Genero genero = gS.buscarGeneroById(libro.getIdGenero());
    Editorial editorial = eS.buscarEditorialById(libro.getIdEditorial());
    Autor autor = aS.buscarAutorById(libro.getIdAutor());
    this->_idVenta=venta.getIdVenta();
    strcpy(_dniCliente,cliente.getDni());
    strcpy(_nombreCliente,cliente.getNombre());
    strcpy(_apellidoCliente,cliente.getApellido());
    strcpy(_telefonoCliente,cliente.getTelefono());
    strcpy(_emailCliente,cliente.getEmail());
    strcpy(_tituloLibro,libro.getTitulo());
    strcpy(_nombreAutor,autor.getNombre());
    strcpy(_apellidoAutor,autor.getApellido());
    strcpy(_editorialLibro,editorial.getNombre());
    this->_importeVenta=venta.getImporteVenta();
    this->_medioDePago=venta.getMedioDePago();
    this->_fecha=venta.getFecha();
}



/// GETTERS
int DetalleVenta::getIdVenta(){
    return _idVenta;
};
const char* DetalleVenta::getDniCliente(){
    return _dniCliente;
};
const char* DetalleVenta::getNombreCliente(){
    return _nombreCliente;
};
const char* DetalleVenta::getApellidoCliente(){
    return _apellidoCliente;
};
const char* DetalleVenta::getTelefonoCliente(){
    return _telefonoCliente;
};
const char* DetalleVenta::getEmailCliente(){
    return _emailCliente;
};
const char* DetalleVenta::getTituloLibro(){
    return _tituloLibro;
};
const char* DetalleVenta::getNombreAutor(){
    return _nombreAutor;
};
const char* DetalleVenta::getApellidoAutor(){
    return _apellidoAutor;
};
const char* DetalleVenta::getEditorialLibro(){
    return _editorialLibro;
};
double DetalleVenta::getImporteVenta(){
    return _importeVenta;
};
int DetalleVenta::getMedioDePago(){
    return _medioDePago;
};
Fecha DetalleVenta::getFecha(){
    return _fecha;
};

/// SETTERS
void DetalleVenta::setIdVenta(int idVenta){
    this->_idVenta=idVenta;
};
void DetalleVenta::setDniCliente(const char* dniCli){
    strcpy(_dniCliente,dniCli);
};
void DetalleVenta::setNombreCliente(const char* nombreCli){
    strcpy(_nombreCliente,nombreCli);
};
void DetalleVenta::setApellidoCliente(const char* apellidoCli){
    strcpy(_apellidoCliente,apellidoCli);
};
void DetalleVenta::setTelefonoCliente(const char* telefonoCli){
    strcpy(_telefonoCliente,telefonoCli);
};
void DetalleVenta::setEmailCliente(const char* emailCli){
    strcpy(_emailCliente,emailCli);
};
void DetalleVenta::setTituloLibro(const char* tituloLi){
    strcpy(_tituloLibro,tituloLi);
};
void DetalleVenta::setNombreAutor(const char* nombreAutor){
    strcpy(_nombreAutor,nombreAutor);
};
void DetalleVenta::setApellidoAutor(const char* apellidoAutor){
    strcpy(_apellidoAutor,apellidoAutor);
};
void DetalleVenta::setEditorialLibro(const char* editorialLi){
    strcpy(_editorialLibro,editorialLi);
};
void DetalleVenta::setImporteVenta(double importeVenta){
    this->_importeVenta=importeVenta;
};
void DetalleVenta::setMedioDePago(int medioPago){
    this->_medioDePago=medioPago;
};
void DetalleVenta::setFecha(Fecha fecha){
    this->_fecha=fecha;
};

/// FUNCIONES

// Imprimir DETALLE
void DetalleVenta::imprimirDetalle(Venta venta){
    DetalleVenta detalle(venta);
    MedioDePago medio = vS.buscarMedioDePagoById(detalle.getMedioDePago());
    std::cout<<" "<<std::endl;
    std::cout<<"..............................................."<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\tLibreria IOSTREAM  -  Recibo de VENTA"<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\tNumero de FACTURA: "<<detalle.getIdVenta()<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\tLIBRO: "<<detalle.getTituloLibro()<<" ("<<detalle.getNombreAutor()<<" "<<detalle.getApellidoAutor()<<")"<<std::endl;
    std::cout<<"\tEditorial: "<<detalle.getEditorialLibro()<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\tDNI de Cliente: "<<detalle.getDniCliente()<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\tCliente: "<<detalle.getNombreCliente()<<" "<<detalle.getApellidoCliente()<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\tTelefono: "<<detalle.getTelefonoCliente()<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\tEmail: "<<detalle.getEmailCliente()<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\tIMPORTE: "<<detalle.getImporteVenta()<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"\tMedio de Pago:"<<std::endl;
    vS.mostrarMedioDePagoDetalle(medio);
    std::cout<<" "<<std::endl;
    std::cout<<"\tFecha de la Venta: "<<detalle.getFecha().fechaFormateada()<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"..............................................."<<std::endl;
    std::cout<<" "<<std::endl;
}


