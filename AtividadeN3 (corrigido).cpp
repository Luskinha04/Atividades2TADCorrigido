#include<stdio.h>

struct Conjunto {
    int elementos[20];
    int tamanho;

    Conjunto() {
        tamanho = 0;
    }

    bool lerInteiro(int *valor) {
        if(scanf("%d", valor) != 1) {
            while(fgetc(stdin) != '\n');
            return false;
        }
        return true;
    }

    void criar() {
        tamanho = 0;
    }

    void ler() {
        criar();
        do {
            printf("Informe a quantidade de elementos do conjunto (maximo 20): ");
        } while (!lerInteiro(&tamanho) || tamanho < 0 || tamanho > 20);

        for (int i = 0; i < tamanho; i++) {
            do {
                printf("Elemento %d: ", i+1);
            } while (!lerInteiro(&elementos[i]));
        }
    }

    Conjunto uniao(Conjunto outro) {
        Conjunto uni;
        for(int i = 0; i < tamanho; i++) {
            uni.elementos[i] = elementos[i];
        }
        uni.tamanho = tamanho;

        for(int i = 0; i < outro.tamanho; i++) {
            bool existe = false;
            for(int j = 0; j < tamanho; j++) {
                if(outro.elementos[i] == elementos[j]) {
                    existe = true;
                    break;
                }
            }
            if(!existe) {
                uni.elementos[uni.tamanho++] = outro.elementos[i];
            }
        }

        return uni;
    }

    Conjunto intersecao(Conjunto outro) {
        Conjunto inter;
        for(int i = 0; i < tamanho; i++) {
            for(int j = 0; j < outro.tamanho; j++) {
                if(elementos[i] == outro.elementos[j]) {
                    inter.elementos[inter.tamanho++] = elementos[i];
                    break;
                }
            }
        }
        return inter;
    }

    bool igual(Conjunto outro) {
        if(tamanho != outro.tamanho) {
            return false;
        }
        for(int i = 0; i < tamanho; i++) {
            if(elementos[i] != outro.elementos[i]) {
                return false;
            }
        }
        return true;
    }

    void imprimir() {
        printf("{ ");
        for(int i = 0; i < tamanho; i++) {
            printf("%d ", elementos[i]);
        }
        printf("}\n");
    }

};

int main() {

    Conjunto A, B, resultado;
    int opcao;

    do {
        printf("1. Ler conjunto A\n");
        printf("2. Ler conjunto B\n");
        printf("3. Imprimir conjunto A\n");
        printf("4. Imprimir conjunto B\n");
        printf("5. Uniao A e B\n");
        printf("6. Intersecao A e B\n");
        printf("7. Verificar se A = B\n");
        printf("0. Sair\n");

        do {
            printf("Opcao: ");
        } while (!A.lerInteiro(&opcao));

        switch (opcao) {
            case 1:
                A.ler();
                break;
            case 2:
                B.ler();
                break;
            case 3:
                A.imprimir();
                break;
            case 4:
                B.imprimir();
                break;
            case 5:
                resultado = A.uniao(B);
                resultado.imprimir();
                break;
            case 6:
                resultado = A.intersecao(B);
                resultado.imprimir();
                break;
            case 7:
                if(A.igual(B)) {
                    printf("Conjunto A e igual ao conjunto B\n");
                } else {
                    printf("Conjunto A e diferente do conjunto B\n");
                }
                break;
        }
    } while (opcao != 0);

    return 0;
}
