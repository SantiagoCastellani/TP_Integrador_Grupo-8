#include "Config.h"
#include "LibroService.h"
#include "VentasService.h"
#include "string.h"
#include "Autor.h"
#include "Genero.h"
#include "Editorial.h"

#include "libxl.h"

using namespace libxl;

Autor autorS;
Genero generoS;
Editorial editorialS;
LibroService libroS;

Config::Config(){}

/// ARCHIVOS de LECTURA
const char *ARCHIVO_LIBROS = "Libros.dat";
const char *ARCHIVO_VENTAS = "RegistrodeVentas.dat";
const char *ARCHIVO_CLIENTES = "Clientes.dat";

/// ARCHIVOS DE BACKUP

const char *BACKUP_LIBROS = "Backup-Libros.bak";
const char *BACKUP_VENTAS = "Backup-Ventas.bak";
const char *BACKUP_CLIENTES = "Backup-Clientes.bak";


// Realizar BACKUP LIBROS
void Config::backupLibros(){
    FILE *archivo;
    archivo=fopen(ARCHIVO_LIBROS,"rb");
    FILE *backup;
    backup=fopen(BACKUP_LIBROS,"ab+");
    Libro libro;
    while(fread(&libro,sizeof(Libro),1,archivo)==1){
        fwrite(&libro,sizeof(Libro),1,backup);
    }
    fclose(archivo);
    fclose(backup);
    std::cout<<" "<<std::endl;
    std::cout<<"\tBackup realizado: Backup-Libros.bak"<<std::endl;
    std::cout<<" "<<std::endl;
};

// Realizar BACKUP VENTAS
void Config::backupVentas(){
    FILE *archivo;
    archivo=fopen(ARCHIVO_VENTAS,"rb");
    FILE *backup;
    backup=fopen(BACKUP_VENTAS,"ab+");
    Venta venta;
    while(fread(&venta,sizeof(Venta),1,archivo)==1){
        fwrite(&venta,sizeof(Venta),1,backup);
    }
    fclose(archivo);
    fclose(backup);
    std::cout<<" "<<std::endl;
    std::cout<<"\tBackup realizado: Backup-Ventas.bak"<<std::endl;
    std::cout<<" "<<std::endl;
};

// Realizar BACKUP CLIENTES
void Config::backupClientes(){
    FILE *archivo;
    archivo=fopen(ARCHIVO_CLIENTES,"rb");
    FILE *backup;
    backup=fopen(BACKUP_CLIENTES,"ab+");
    Cliente cliente;
    while(fread(&cliente,sizeof(Cliente),1,archivo)==1){
        fwrite(&cliente,sizeof(Cliente),1,backup);
    }
    fclose(archivo);
    fclose(backup);
    std::cout<<" "<<std::endl;
    std::cout<<"\tBackup realizado: Backup-Clientes.bak"<<std::endl;
    std::cout<<" "<<std::endl;
};

// Restaurar Archivos LIBROS
void Config::restaurarArchivosLibros(){
    FILE *backup;
    backup=fopen(BACKUP_LIBROS,"rb");
    if(backup){
        FILE *archivo;
        archivo=fopen(ARCHIVO_LIBROS,"wb");
        Libro libro;
        while(fread(&libro,sizeof(Libro),1,backup)==1){
            fwrite(&libro,sizeof(Libro),1,archivo);
        }
        fclose(archivo);
        std::cout<<" "<<std::endl;
        std::cout<<"\tArchivos de Libros Restaurado."<<std::endl;
        std::cout<<" "<<std::endl;
    } else {
        std::cout<<" "<<std::endl;
        std::cout<<"\tERROR: Aun no hay ningun backup realizado!"<<std::endl;
        std::cout<<" "<<std::endl;
    }
    fclose(backup);
};

// Restaurar Archivos VENTAS
void Config::restaurarArchivosVentas(){
    FILE *backup;
    backup=fopen(BACKUP_VENTAS,"rb");
    if(backup){
        FILE *archivo;
        archivo=fopen(ARCHIVO_VENTAS,"wb");
        Venta venta;
        while(fread(&venta,sizeof(Venta),1,backup)==1){
            fwrite(&venta,sizeof(Venta),1,archivo);
        }
        fclose(archivo);
        std::cout<<" "<<std::endl;
        std::cout<<"\tArchivos de Ventas Restaurado."<<std::endl;
        std::cout<<" "<<std::endl;
    } else {
        std::cout<<" "<<std::endl;
        std::cout<<"\tERROR: Aun no hay ningun backup realizado!"<<std::endl;
        std::cout<<" "<<std::endl;
    }
    fclose(backup);
};

// Restaurar Archivos CLIENTES
void Config::restaurarArchivosClientes(){
    FILE *backup;
    backup=fopen(BACKUP_CLIENTES,"rb");
    if(backup){
        FILE *archivo;
        archivo=fopen(ARCHIVO_CLIENTES,"wb");
        Cliente cliente;
        while(fread(&cliente,sizeof(Cliente),1,backup)==1){
            fwrite(&cliente,sizeof(Cliente),1,archivo);
        }
        fclose(archivo);
        std::cout<<" "<<std::endl;
        std::cout<<"\tArchivos de Clientes Restaurado."<<std::endl;
        std::cout<<" "<<std::endl;
    } else {
        std::cout<<" "<<std::endl;
        std::cout<<"\tERROR: Aun no hay ningun backup realizado!"<<std::endl;
        std::cout<<" "<<std::endl;
    }
    fclose(backup);
};

/*************************************************************************************/

/// Generar EXCEL LIBROS
void Config::crearExcelLibros(){
    Book* book = xlCreateBook();
    if (book){
        Sheet* hoja = book->addSheet("LIBROS REGISTRADOS");
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
            hoja->setCol(0, 0, 2);
            hoja->setCol(1, 1, 12);
            hoja->setCol(2, 2, 30);
            hoja->setCol(3, 3, 20);
            hoja->setCol(4, 4, 35);
            hoja->setCol(5, 5, 15);
            hoja->setCol(6, 6, 15);
            hoja->writeStr(1, 1, "ID",campos);
            hoja->writeStr(1, 2, "TITULO",campos);
            hoja->writeStr(1, 3, "AUTOR",campos);
            hoja->writeStr(1, 4, "Editorial",campos);
            hoja->writeStr(1, 5, "Genero",campos);
            hoja->writeStr(1, 6, "Precio $",campos);
            FILE *archivo;
            Libro libro;
            archivo = fopen(ARCHIVO_LIBROS,"rb");
            int f=2;
            while(fread(&libro,sizeof(Libro),1,archivo)==1){
                char autors[80]={};
                Autor autor = autorS.buscarAutorById(libro.getIdAutor());
                Editorial editorial = editorialS.buscarEditorialById(libro.getIdEditorial());
                Genero genero = generoS.buscarGeneroById(libro.getIdGenero());
                hoja->writeNum(f, 1, libro.getIdLibro(),datos);
                hoja->writeStr(f, 2,libro.getTitulo(),datos);
                strcat(autors,autor.getNombre());
                strcat(autors," ");
                strcat(autors,autor.getApellido());
                hoja->writeStr(f, 3, autors,datos);
                hoja->writeStr(f, 4, editorial.getNombre(),datos);
                hoja->writeStr(f, 5, genero.getGenero(),datos);
                hoja->writeNum(f, 6, libro.getPrecio(),datos);
                f++;
            }
            fclose(archivo);
        }
        book->save("Registro_LIBROS.xls");
        std::cout<<" "<<std::endl;
        std::cout<<"\tArchivo descargado: Registro_LIBROS.xls"<<std::endl;
        std::cout<<" "<<std::endl;
        book->release();
    }
};

/// Generar Excel CLIENTES
void Config::crearExcelClientes(){
    Book* book = xlCreateBook();
    if (book){
        Sheet* hoja = book->addSheet("CLIENTES REGISTRADOS");
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
            hoja->setCol(0, 0, 2);
            hoja->setCol(1, 1, 12);
            hoja->setCol(2, 2, 30);
            hoja->setCol(3, 3, 20);
            hoja->setCol(4, 4, 35);
            hoja->setCol(5, 5, 15);
            hoja->writeStr(1, 1, "DNI",campos);
            hoja->writeStr(1, 2, "Apellido",campos);
            hoja->writeStr(1, 3, "Nombre",campos);
            hoja->writeStr(1, 4, "Email",campos);
            hoja->writeStr(1, 5, "Telefono",campos);
            FILE *archivo;
            Cliente cliente;
            archivo = fopen(ARCHIVO_CLIENTES,"rb");
            int f=2;
            while(fread(&cliente,sizeof(Cliente),1,archivo)==1){
                hoja->writeStr(f, 1, cliente.getDni(),datos);
                hoja->writeStr(f, 2, cliente.getApellido(),datos);
                hoja->writeStr(f, 3, cliente.getNombre(),datos);
                hoja->writeStr(f, 4, cliente.getEmail(),datos);
                hoja->writeStr(f, 5, cliente.getTelefono(),datos);
                f++;
            }
            fclose(archivo);
        }
        book->save("Registro_CLIENTES.xls");
        std::cout<<" "<<std::endl;
        std::cout<<"\tArchivo descargado: Registro_CLIENTES.xls"<<std::endl;
        std::cout<<" "<<std::endl;
        book->release();
    }
};

/// Generar Excel VENTAS
void Config::crearExcelVentas(){
    Book* book = xlCreateBook();
    if (book){
        Sheet* hoja = book->addSheet("VENTAS REGISTRADAS");
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
            hoja->setCol(0, 0, 2);
            hoja->setCol(1, 1, 12);
            hoja->setCol(2, 2, 30);
            hoja->setCol(3, 3, 20);
            hoja->setCol(4, 4, 35);
            hoja->setCol(5, 5, 15);
            hoja->writeStr(1, 1, "ID Venta",campos);
            hoja->writeStr(1, 2, "LIBRO",campos);
            hoja->writeStr(1, 3, "Editorial",campos);
            hoja->writeStr(1, 4, "Importe $",campos);
            hoja->writeStr(1, 5, "Dni Cliente",campos);
            FILE *archivo;
            Venta venta;
            archivo = fopen(ARCHIVO_VENTAS,"rb");
            int f=2;
            while(fread(&venta,sizeof(Venta),1,archivo)==1){
                Libro libro = libroS.buscarLibroById(venta.getIdLibro());
                Editorial editorial = editorialS.buscarEditorialById(libro.getIdEditorial());
                hoja->writeNum(f, 1, venta.getIdVenta(),datos);
                hoja->writeStr(f, 2, libro.getTitulo(),datos);
                hoja->writeStr(f, 3, editorial.getNombre(),datos);
                hoja->writeNum(f, 4, venta.getImporteVenta(),datos);
                hoja->writeStr(f, 5, venta.getDniCliente(),datos);
                f++;
            }
            fclose(archivo);
        }
        book->save("Registro_VENTAS.xls");
        std::cout<<" "<<std::endl;
        std::cout<<"\tArchivo descargado: Registro_VENTAS.xls"<<std::endl;
        std::cout<<" "<<std::endl;
        book->release();
    }
};
