/*
 * Autor: Julian Andres Galvis Tocora
 * Fecha de creación: 6 de Mayo
 * Fecha última modificación: 6 de Mayo
 * Versión: 1.0
 * 
 * Archivo encabezado libreria TAD BigInteger
 * Representación Estructuras BigInteger
 */

#ifndef __BigInteger_H
#define __BigInteger_H  

#include <iostream>
#include "lista.h"
#include <string>

using namespace std;

/************************
* ESTRUCTURAS DE DATOS *
************************/

class BigInteger{
private:
    Lista listaBig;

public:

    /************************
    * OPERACIONES DEL TAD *
    ************************/

    /* Constructoras */
    crearBigInteger(string num);
    copiarBigInteger(BigInteger& num);


    /* Operadoras */

    void add(BigInteger& num);
    void product(BigInteger& num);
    void substract(BigInteger& num);
    void quotient(BigInteger& num);
    void remainder(BigInteger& num);
    void pow(BigInteger& num);
    string toString(BigInteger& num);

    /* Sobrecarga_Operadores */   

    BigInteger operator+(const BigInteger&);
    BigInteger operator-(const BigInteger&);
    BigInteger operator*(const BigInteger&);
    BigInteger operator/(const BigInteger&);
    BigInteger operator%(const BigInteger&);
    BigInteger operator==(const BigInteger&);
    BigInteger operator<(const BigInteger&);
    BigInteger operator<=(const BigInteger&);

    /* Operaciones_Estaticas */

    BigInteger sumarListaValores(Lista l); 
    BigInteger MultiplicarListaValores(Lista l);
};


#endif
















