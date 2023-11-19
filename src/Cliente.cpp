#include "Cliente.h"
#include "string.h"
#include "Fecha.h"

Cliente::Cliente()
{
    strcpy(_dni,"00000000");
    strcpy(_nombre,"0000");
    strcpy(_apellido,"getr");
    strcpy(_telefono,"00000000");
    strcpy(_email,"00000000");
    _fechaNac=Fecha();
}

Cliente::Cliente(char* dniP,char* nombreP,char* apellidoP,char* telefonoP,char* emailP,Fecha fecha){
    strcpy(_dni,dniP);
    strcpy(_nombre,nombreP);
    strcpy(_apellido,apellidoP);
    strcpy(_telefono,telefonoP);
    strcpy(_email,emailP);
    this->_fechaNac=fecha;
};

/// GETTERS
const char* Cliente::getDni(){
    return _dni;
};
const char* Cliente::getNombre(){
    return _nombre;
};
const char* Cliente::getApellido(){
    return _apellido;
};
const char* Cliente::getTelefono(){
    return _telefono;
};
const char* Cliente::getEmail(){
    return _email;
};
Fecha Cliente::getFecha(){
    return _fechaNac;
};

/// SETTERS
void Cliente::setDni(const char* dniP){
    strcpy(_dni,dniP);
};
void Cliente::setNombre(const char* nombreP){
    strcpy(_nombre,nombreP);
};
void Cliente::setApellido(const char* apellidoP){
    strcpy(_apellido,apellidoP);
};
void Cliente::setTelefono(const char* telefonoP){
    strcpy(_telefono,telefonoP);
};
void Cliente::setEmail(const char* emailP){
    strcpy(_email,emailP);
};
void Cliente::setFecha(Fecha fecha){
    this->_fechaNac=fecha;
};


/// FUNCIONES
std::string Cliente::nombreCompleto(){
    return strcat(_nombre,_apellido);
}
