#include<stdio.h>
#include<stdlib.h>
#include "conta_bancaria.h"

ContaBancaria* inicializa(int numero, double valor){
    ContaBancaria* conta = (ContaBancaria*) malloc(sizeof(ContaBancaria));
    conta->numero = numero;
    conta->saldo = valor;
    return conta;
}

void deposito(ContaBancaria* conta, double valor){
    conta->saldo += valor;
}

void saque(ContaBancaria* conta, double valor){
    conta->saldo -= valor;
}

void imprime(ContaBancaria* conta){
    printf("\nBanco C\n\n");
    printf("Número da conta: %d\n", conta->numero);
    printf("Saldo: %.2f\n", conta->saldo);
}

