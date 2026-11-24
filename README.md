# Dylemat Więźnia
To repozytorium zawiera w sobie projekt na zajęcia z systemów operacyjnych.
Idea tego projektu znajduję się w pliku ["./Idea.md"](./Idea.md)

## Konfiguracja
Projekt przyjmuje niektóre wartości z plików, a niektóre z konsoli.
Wartościami przyjmowanymi z konsoli są:
 - int PRISONERS_LIMIT; <- Jest to Limit procesów sieci w każdym pokoleniu 
 - int GENERATIONS_LIMIT; <- Maksymalna liczba pokoleń 
 - int JUDGES_LIMIT; <- Maksymalna ilość równoległych gier ( każda posiada 2 więźniów )

Wartości przyjmowane z plików to:
 - Tabela wypłat w pliku [payout_table.txt](payout_table.txt) w formacie jak pokazano poniżej. 'C' Oznacza, że dany gracz współpracował (ang. Cooperate), 
a 'D' że zdradził (ang. Defect). Na miejsce liter trzeba wstawić wartości numeryczne odpowiadające ilości punktów otrzymanych przez danego gracza w danym scenariuszu. Muszą być rozdzielone średnikiem.
```txt
C;C
C;D
D;C
D;D
```
- [OPCJONALNE] starting_weights - TODO