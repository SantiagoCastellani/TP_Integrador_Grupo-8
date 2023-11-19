#include "Venta.h"
#include "string.h"

Venta::Venta()
{
    _idVenta=0;
    strcpy(_dniCliente,"000000000");
    _idLibro=0;
    _importeVenta=0;
    _idMedioDePago=0;
    _fecha=Fecha();
};

Venta::Venta(int id, char* dniCli, int idLibro, double importeVenta, int medioDePago, Fecha fecha){
    this->_idVenta=id;
    strcpy(_dniCliente,dniCli);
    this->_idLibro=idLibro;
    this->_importeVenta=importeVenta;
    this->_idMedioDePago=medioDePago;
    this->_fecha=fecha;
};

/// GETTERS
int Venta::getIdVenta(){
    return _idVenta;
};
const char* Venta::getDniCliente(){
    return _dniCliente;
};
int Venta::getIdLibro(){
    return _idLibro;
};
double Venta::getImporteVenta(){
    return _importeVenta;
};
int Venta::getMedioDePago(){
    return _idMedioDePago;
};
Fecha Venta::getFecha(){
    return _fecha;
};

/// SETTERS
void Venta::setIdVenta(int id){
    this->_idVenta=id;
};
void Venta::setDniCliente(const char* dniCli){
    strcpy(_dniCliente,dniCli);
};
void Venta::setIdLibro(int idLibro){
    this->_idLibro=idLibro;
};
void Venta::setImporteVenta(double importeVenta){
    this->_importeVenta=importeVenta;
};
void Venta::setMedioDePago(int medioDePago){
    this->_idMedioDePago=medioDePago;
};
void Venta::setFecha(Fecha fecha){
    this->_fecha=fecha;
};


