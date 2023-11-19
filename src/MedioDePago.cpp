#include "MedioDePago.h"
#include "string.h"
#include <cstdio>

MedioDePago::MedioDePago()
{
    _id=0;
    strcpy(_nombre,"000");
    _recargo=0;
    _cantCuotas=0;
}

MedioDePago::MedioDePago(int idP,char* nombreP,float recargoP,int cantCuotasP)
{
    this->_id=idP;
    strcpy(_nombre,nombreP);
    this->_recargo=recargoP;
    this->_cantCuotas=cantCuotasP;
}

/// GETTERS
int MedioDePago::getId(){
    return _id;
};
const char* MedioDePago::getNombre(){
    return _nombre;
};
float MedioDePago::getRecargo(){
    return _recargo;
};
int MedioDePago::getCantCuotas(){
    return _cantCuotas;
};

/// SETTERS
void MedioDePago::setId(int id){
    this->_id=id;
};
void MedioDePago::setNombre(const char* nombreP){
    strcpy(_nombre,nombreP);
};
void MedioDePago::setRecargo(float recargoP){
    this->_recargo=recargoP;
};
void MedioDePago::setCantCuotas(int cantCuotasP){
    this->_cantCuotas=cantCuotasP;
};





