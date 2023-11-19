#pragma once

#include "defines.h"
#include "structs.h"
#include <stdio.h>
#include <string.h>

void Menu(void) {
        puts("LISTA DE TAREFAS RADICAL");
        puts("------------------------");
        puts("1 - Adicionar nova tarefa");
        puts("2 - Listar tarefas");
        puts("3 - Remover tarefa");
        puts("4 - Marcar tarefa como concluida");
        puts("5 - Limpar tarefas concluidas");
        puts("0 - Sair\n");
}

void AdicionarTarefa(char descricao[], Tarefa tarefas[], int *qtdTarefas) {
        strncpy(tarefas[*qtdTarefas].descricao, descricao, strlen(descricao));
        tarefas[*qtdTarefas].descricao[strlen(descricao)] = '\0';
        tarefas[*qtdTarefas].isConcluido = FALSE;
        (*qtdTarefas)++;
}

void ListarTarefas(Tarefa tarefas[], int qtdTarefas) {
        for (int i = 0; i < qtdTarefas; i++) {
                printf("%3d | (%c) %s\n",
                        i + 1,
                        tarefas[i].isConcluido ? 'x' : ' ',
                        tarefas[i].descricao);
        }
}

void MarcarConcluida(Tarefa tarefas[], int index) {
        if (tarefas[index].isConcluido == FALSE) {
                tarefas[index].isConcluido = TRUE;
        } else if (tarefas[index].isConcluido == TRUE) {
                tarefas[index].isConcluido = FALSE;
        }
}

void RemoverTarefa(Tarefa tarefas[], int index, int *qtdTarefas) {
        (*qtdTarefas)--;
        for (; index < *qtdTarefas; index++) {
                tarefas[index] = tarefas[index + 1];
        }

}
