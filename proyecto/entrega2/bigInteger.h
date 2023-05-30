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
#include <string>
#include <sstream>
#include <vector>
#include <list>

using namespace std;   

/************************
* ESTRUCTURAS DE DATOS *
************************/

class BigInteger{
private:
    vector<int> listaBig;

    /* Auxiliares*/


public:

    bool signo;

    /************************
    * OPERACIONES DEL TAD *
    ************************/

    /* Constructoras */
    BigInteger(const string& num);
    BigInteger(const BigInteger& num);


    /* Operadoras */

    void add(BigInteger& num);
    void product(BigInteger& num);
    void substract(BigInteger& num);
    void quotient(BigInteger& num);
    void remainder(BigInteger& num);
    void pow(const int& num);
    string toString();

    /* Sobrecarga_Operadores */   

    BigInteger operator+(BigInteger&);
    BigInteger operator-(BigInteger&);
    BigInteger operator*(BigInteger&);
    BigInteger operator/(BigInteger&);
    BigInteger operator%(BigInteger&);
    bool operator==(const BigInteger&);
    bool operator<(const BigInteger&);
    bool operator<=(const BigInteger&);

    /* Operaciones_Estaticas */

    static BigInteger sumarListaValores(list<BigInteger>& l); 
    static BigInteger multiplicarListaValores(list<BigInteger>& l);
};

#endif
















