#include<stdio.h>

struct Data {
    int dia, mes, ano;

    void ler() {
        do {
            printf("Digite a data de nascimento (DD MM AAAA): ");
            if (scanf("%d %d %d%*c", &dia, &mes, &ano) == 3 && dia > 0 && dia <= 31 && mes > 0 && mes <= 12 && ano >= 1900 && ano <= 2023) {
                return;
            }
            printf("Data invalida. Use o formato (DD MM AAAA) e insira valores validos.\n");
            while (getchar() != '\n');
        } while (1);
    }

    void imprimir() {
        printf("%02d/%02d/%d", dia, mes, ano);
    }
};

struct Cliente {
    char nome[100], sexo;
    Data dataNascimento;
    int idade;

    void ler() {
        printf("Digite o nome do cliente: ");
        scanf("%[^\n]%*c", nome);
        do {
            printf("Digite o sexo do cliente (M/F): ");
            scanf("%c%*c", &sexo);
        } while (sexo != 'M' && sexo != 'F');
        dataNascimento.ler();
        idade = 2023 - dataNascimento.ano;
    }

    void imprimir() {
        printf("Nome: %s - Sexo: %c - Data de Nascimento: ", nome, sexo);
        dataNascimento.imprimir();
        printf(" - Idade: %d anos\n", idade);
    }
};

struct Sistema {
    Cliente clientes[50];
    int qtdClientes;

    Sistema() {
        qtdClientes = 0;
    }

    void cadastrarCliente() {
        if (qtdClientes >= 50) {
            printf("Limite de clientes atingido.\n");
            return;
        }
        clientes[qtdClientes].ler();
        qtdClientes++;
    }

    void listarClientes() {
        if (qtdClientes == 0) {
            printf("Nenhum cliente cadastrado.\n");
            return;
        }
        for (int i = 0; i < qtdClientes; i++) {
            clientes[i].imprimir();
        }
    }
};

int main() {
    Sistema s;
    int opcao;
    do {
        printf("1. Cadastrar cliente\n");
        printf("2. Listar clientes\n");
        printf("0. Sair\n");
        if (scanf("%d%*c", &opcao) != 1) {
            printf("Opcao invalida.\n");
            while (getchar() != '\n');
            continue;
        }
        switch (opcao) {
            case 1:
                s.cadastrarCliente();
                break;
            case 2:
                s.listarClientes();
                break;
        }
    } while (opcao != 0);

    return 0;
}
