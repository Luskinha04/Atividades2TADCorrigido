#include <stdio.h>

struct Funcionario {
    char nome[100];
    char cargo[100];
    double salarioBase, beneficios, descontos;

    void ler() {
        printf("Nome: ");
        scanf("%[^\n]%*c", nome);
        printf("Cargo: ");
        scanf("%[^\n]%*c", cargo);
        while (1) {
            printf("Salario base: ");
            if (scanf("%lf%*c", &salarioBase) == 1) break;
            else {
                printf("Valor invalido. Insira novamente.\n");
                while (getchar() != '\n');
            }
        }
        while (1) {
            printf("Beneficios: ");
            if (scanf("%lf%*c", &beneficios) == 1) break;
            else {
                printf("Valor invalido. Insira novamente.\n");
                while (getchar() != '\n');
            }
        }
        while (1) {
            printf("Descontos: ");
            if (scanf("%lf%*c", &descontos) == 1) break;
            else {
                printf("Valor invalido. Insira novamente.\n");
                while (getchar() != '\n');
            }
        }
    }

    void imprimir() {
        printf("%s - %s - Salario liquido: %.2lf\n", nome, cargo, salarioBase + beneficios - descontos);
    }

    double salarioLiquido() {
        return salarioBase + beneficios - descontos;
    }
};

struct Loja {
    Funcionario funcionarios[10];
    int qtdFuncionarios = 0;

    void cadastrarFuncionario() {
        if (qtdFuncionarios < 10) {
            funcionarios[qtdFuncionarios].ler();
            qtdFuncionarios++;
        } else printf("Limite de funcionarios atingido.\n");
    }

    void listarFuncionarios() {
        if(qtdFuncionarios == 0) {
            printf("Nao existem funcionarios listados ainda.\n");
            return;
        }
        for (int i = 0; i < qtdFuncionarios; i++) {
            funcionarios[i].imprimir();
        }
    }

    void mediaSalarial() {
        double total = 0;
        for (int i = 0; i < qtdFuncionarios; i++) {
            total += funcionarios[i].salarioLiquido();
        }
        printf("Media salarial: %.2lf\n", total/qtdFuncionarios);
    }

    void maiorSalario() {
        int indiceMaior = 0;
        for (int i = 1; i < qtdFuncionarios; i++) {
            if (funcionarios[i].salarioLiquido() > funcionarios[indiceMaior].salarioLiquido()) {
                indiceMaior = i;
            }
        }
        funcionarios[indiceMaior].imprimir();
    }
};

int main() {
    Loja loja;
    int opcao;
    do {
        printf("1. Cadastrar funcionario\n");
        printf("2. Listar funcionarios\n");
        printf("3. Media salarial da loja\n");
        printf("4. Funcionario com maior salario\n");
        printf("0. Sair\n");

        if (scanf("%d%*c", &opcao) != 1) {
            printf("Opcao invalida. Insira um numero.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (opcao) {
            case 1:
                loja.cadastrarFuncionario();
                break;
            case 2:
                loja.listarFuncionarios();
                break;
            case 3:
                loja.mediaSalarial();
                break;
            case 4:
                loja.maiorSalario();
                break;
        }
    } while (opcao != 0);

    return 0;
}
