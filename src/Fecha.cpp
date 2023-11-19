#include "Fecha.h"

Fecha::Fecha()
{
    _dia=1;
    _mes=1;
    _anio=1900;
}

Fecha::Fecha(int dia,int mes,int anio){
    this->_dia=dia;
    this->_mes=mes;
    this->_anio=anio;
};

std::string Fecha::fechaFormateada(){
    return std::to_string(_dia) + "/" + std::to_string(_mes)+ "/" + std::to_string(_anio);
}

// Cargar Fecha
//Fecha Fecha::cargarFecha(){
//    int dia,mes,anio;
//    std::cout<<"Dia: ";
//    std::cin>>dia;
//    std::cout<<"Mes: ";
//    std::cin>>mes;
//    std::cout<<"Anio: ";
//    std::cin>>anio;
//    Fecha fecha(dia,mes,anio);
//    return fecha;
//};

// Cargar Fecha
Fecha Fecha::cargarFecha(){
    int dia,mes,anio;
    std::cout<<"Dia: ";
    std::cin>>dia;
    if(dia>31){
        std::cout<<""<<std::endl;
        std::cout<<"El dia ingresado no es correcto. Por favor ingrese otro: ";
        std::cin>>dia;
    }
    std::cout<<"Mes: ";
    std::cin>>mes;
    if(mes>12){
        std::cout<<""<<std::endl;
        std::cout<<"El mes ingresado no es correcto. Por favor ingrese otro: ";
        std::cin>>mes;
    }
    std::cout<<"Anio: ";
    std::cin>>anio;
    Fecha fecha(dia,mes,anio);
    return fecha;
};

/// Getters
int Fecha::getDia(){
    return _dia;
};
int Fecha::getMes(){
    return _mes;
};
int Fecha::getAnio(){
    return _anio;
};

/// Setters
void Fecha::setDia(int dia){
    this->_dia=dia;
};
void Fecha::setMes(int mes){
    this->_mes=mes;
};
void Fecha::setAnio(int anio){
    this->_anio=anio;
};


/// FUNCIONES

//ES ANTERIOR
bool Fecha::esAnteriorA(Fecha fecha){
    bool esAnterior=false;
    if(this->_anio<fecha.getAnio()){
        esAnterior=true;
    } else if(this->_anio==fecha.getAnio()){
        if(this->_mes<fecha.getMes()){
            esAnterior=true;
        } else if(this->_mes==fecha.getMes()){
            if(this->_dia<fecha.getDia()){
                esAnterior=true;
            }
        }
    }
}

// ES POSTERIOR
bool Fecha::esPosteriorA(Fecha fecha){
    bool esPosterior=false;
    if(this->_anio>fecha.getAnio()){
        esPosterior=true;
    } else if(this->_anio==fecha.getAnio()){
        if(this->_mes>fecha.getMes()){
            esPosterior=true;
        } else if(this->_mes==fecha.getMes()){
            if(this->_dia>fecha.getDia()){
                esPosterior=true;
            }
        }
    }
}
