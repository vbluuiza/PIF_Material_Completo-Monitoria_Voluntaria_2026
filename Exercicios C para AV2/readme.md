🎯 DIFERENÇA ENTRE OS DOIS CÓDIGOS
| Código 1 (simples)       | Código 2 (dinâmico)          |
| ------------------------ | ---------------------------- |
| Curso tem **1** aula     | Curso tem **N aulas**        |
| Não usa malloc           | Usa malloc                   |
| Acesso: `pc->aula.campo` | Acesso: `pc->aulas[i].campo` |
| Struct direta            | Struct via ponteiro          |
| Sem vetor                | Vetor dinâmico de structs    |

---
DIAGONAL PRINCIPAL:
    i == j

DIAGONAL SECUNDÁRIA:
    i + j == N - 1

DISTÂNCIA DA PRINCIPAL:
    abs(i - j)

DISTÂNCIA DA SECUNDÁRIA:
    abs((i + j) - (N - 1))

ACIMA DA PRINCIPAL:
    i < j

ABAIXO DA PRINCIPAL:
    i > j

ACIMA DA SECUNDÁRIA:
    i + j < N - 1

ABAIXO DA SECUNDÁRIA:
    i + j > N - 1

---
