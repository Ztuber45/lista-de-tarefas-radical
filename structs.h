#pragma once

#include "defines.h"

typedef struct {
        char descricao[MAX_DESCRICAO + 1];
        int isConcluido;
} Tarefa;

typedef struct {
        Tarefa tarefas[MAX_TAREFAS];
        int qtdTarefas;
} ListaDeTarefas;
