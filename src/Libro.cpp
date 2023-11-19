#include "Libro.h"
#include "Fecha.h"
#include "Autor.h"
#include "Genero.h"
#include "Editorial.h"
#include"string.h"

Libro::Libro()
{

}
Libro::Libro(int idLibro,char* titulo,int idAutor,int idGenero,int idEditorial,Fecha fechaPublicacion,float precio,int stock)
{
_idLibro=idLibro;
strcpy(_titulo,titulo);
_idAutor=idAutor;
_idGenero=idGenero;
_idEditorial=idEditorial;
_fechaPublicacion=fechaPublicacion;
_precio=precio;
_stock=stock;
};

/// GETTERS
int Libro::getIdLibro(){
    return _idLibro;
}
char* Libro::getTitulo(){
    return _titulo;
}
int Libro::getIdAutor(){
    return _idAutor;
}
int Libro::getIdGenero(){
    return _idGenero;
}
int Libro::getIdEditorial(){
    return _idEditorial;
}
Fecha Libro::getFechaPublicacion(){
    return _fechaPublicacion;
}
float Libro::getPrecio(){
    return _precio;
}
int Libro::getStock(){
    return _stock;
}

/// SETTERS
void Libro::setIdLibro(int idLibro){
    _idLibro=idLibro;
}
void Libro::setTitulo(const char* titulo){
    strcpy(_titulo,titulo);
}
void Libro::setIdAutor(int idAutor){
    _idAutor=idAutor;
}
void Libro::setIdGenero(int idGenero){
    _idGenero=idGenero;
}
void Libro::setIdEditorial(int idEditorial){
    _idEditorial=idEditorial;
}
void Libro::setFechaPublicacion(Fecha fechaPublicacion){
    _fechaPublicacion=fechaPublicacion;
}
void Libro::setPrecio(float precio){
    _precio=precio;
}
void Libro::setStock(int stock){
    _stock=stock;
}
