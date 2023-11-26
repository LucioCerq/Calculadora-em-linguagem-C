#include <iostream>

class ContaBancaria {
protected:
    double saldo;

public:
    ContaBancaria(double saldoInicial) : saldo(saldoInicial) {}

    double getSaldo() const {
        return saldo;
    }

    void sacar(double valor) {
        if (valor > 0 && valor <= saldo) {
            saldo -= valor;
            std::cout << "Saque de " << valor << " realizado com sucesso." << std::endl;
        } else {
            std::cout << "Saldo insuficiente para realizar o saque de " << valor << std::endl;
        }
    }
};

class ContaCorrente : public ContaBancaria {
public:
    ContaCorrente(double saldoInicial) : ContaBancaria(saldoInicial) {}
};

class ContaSalario : public ContaBancaria {
public:
    ContaSalario(double saldoInicial) : ContaBancaria(saldoInicial) {}
};

class ContaPoupanca : public ContaBancaria {
public:
    ContaPoupanca(double saldoInicial) : ContaBancaria(saldoInicial) {}
};

class ContaInvestimento : public ContaBancaria {
public:
    ContaInvestimento(double saldoInicial) : ContaBancaria(saldoInicial) {}
};

int main() {
    ContaCorrente contaCorrente(1000);
    ContaSalario contaSalario(500);
    ContaPoupanca contaPoupanca(2000);
    ContaInvestimento contaInvestimento(5000);

    // Tentativa de saque
    contaCorrente.sacar(200);
    contaSalario.sacar(600); // Deverá gerar uma mensagem de saldo insuficiente
    contaPoupanca.sacar(1500); // Deverá gerar uma mensagem de saldo insuficiente
    contaInvestimento.sacar(3000); // Deverá gerar uma mensagem de saldo insuficiente

    return 0;
}

