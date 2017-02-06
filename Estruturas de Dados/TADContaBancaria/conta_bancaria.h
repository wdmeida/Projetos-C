#ifndef CONTA_BANCARIA_H_INCLUDED
#define CONTA_BANCARIA_H_INCLUDED

typedef struct{
    int numero;
    double saldo;
} ContaBancaria;

ContaBancaria* inicializa(int, double);
void deposito(ContaBancaria*, double);
void saque(ContaBancaria*, double);
void imprime(ContaBancaria*);

#endif // CONTA_BANCARIA_H_INCLUDED
