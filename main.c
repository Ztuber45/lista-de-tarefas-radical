#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
#include "defines.h"
#include "structs.h"

void zflush() { while (getchar() != '\n'); }
void zgets(char str[], int maxLen) {
        int i;

        fgets(str, maxLen + 2, stdin);
        for (i = 0; str[i] != '\n' && str[i] != '\0'; i++);
        str[i] = '\0';
}

int main() {
        ListaDeTarefas lista = {
                .qtdTarefas = 0
        };
        int opcao;

        char descricao[MAX_DESCRICAO + 2];
        int tarefa;

        do {
                system("clear || cls");

                Menu();
                printf("Opcao: ");
                scanf("%d", &opcao);
                zflush();

                switch (opcao) {
                case ADICIONAR_TAREFA:
                        if (lista.qtdTarefas == MAX_TAREFAS) {
                                puts("<!> Nao tem espaco para mais tarefas!");
                                getchar();
                                break;
                        }

                        printf("Descricao: ");
                        zgets(descricao, MAX_DESCRICAO + 2);
                        if (strlen(descricao) > MAX_DESCRICAO) {
                                puts("<!> Passou do limite de caracteres!");
                                printf("<!> Limite: %d\n", MAX_DESCRICAO);
                                getchar();
                                break;
                        }

                        AdicionarTarefa(descricao, lista.tarefas, &lista.qtdTarefas);

                        puts("<!> Tarefa adicionada com sucesso!");
                        getchar();
                        break;

                case LISTAR_TAREFAS:
                        if (lista.qtdTarefas == 0) {
                                puts("<!> Ainda nao foi adicionado nenhuma tarefa!");
                                getchar();
                                break;
                        }

                        ListarTarefas(lista.tarefas, lista.qtdTarefas);
                        getchar();
                        break;

                case REMOVER_TAREFA:
                        if (lista.qtdTarefas == 0) {
                                puts("<!> Ainda nao foi adicionado nenhuma tarefa!");
                                getchar();
                                break;
                        }

                        ListarTarefas(lista.tarefas, lista.qtdTarefas);

                        printf("Tarefa: ");
                        scanf("%d", &tarefa);
                        zflush();

                        if (1 > tarefa || tarefa > lista.qtdTarefas) {
                                puts("<!> Essa tarefa nao existe!");
                                getchar();
                                break;
                        }

                        RemoverTarefa(lista.tarefas, tarefa - 1, &lista.qtdTarefas);

                        puts("<!> Tarefa removida com sucesso!");
                        getchar();
                        break;

                case MARCAR_CONCLUIDA:
                        if (lista.qtdTarefas == 0) {
                                puts("<!> Ainda nao foi adicionado nenhuma tarefa!");
                                getchar();
                                break;
                        }

                        ListarTarefas(lista.tarefas, lista.qtdTarefas);

                        printf("Tarefa: ");
                        scanf("%d", &tarefa);
                        zflush();

                        if (1 > tarefa || tarefa > lista.qtdTarefas) {
                                puts("<!> Essa tarefa nao existe!");
                                getchar();
                                break;
                        }

                        MarcarConcluida(lista.tarefas, tarefa - 1);

                        lista.tarefas[tarefa - 1].isConcluido == TRUE ?
                                puts("<!> Tarefa marcada como conluida com sucesso!")
                                : puts("<!> Tarefa desmarcada como conluida com sucesso!");
                        getchar();
                        break;

                case LIMPAR_CONLUIDAS:
                        if (lista.qtdTarefas == 0) {
                                puts("<!> Ainda nao foi adicionado nenhuma tarefa!");
                                getchar();
                                break;
                        }

                        for (int i = 0; i < lista.qtdTarefas; i++) {
                                if (lista.tarefas[i].isConcluido) {
                                        RemoverTarefa(lista.tarefas, i, &lista.qtdTarefas);
                                        i--;
                                }
                        }

                        puts("<!> Limpesa feita com sucesso!");
                        getchar();
                        break;

                case SAIR:
                        puts("<!> Bye Bye! :)");
                        break;

                default:
                        puts("<!> Opcao invalida!");
                        getchar();
                        break;
                }
        } while (opcao != SAIR);

        return 0;
}
