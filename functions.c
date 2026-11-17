#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "functions.h"

Train input_train() {
    Train t;
    printf("Номер поезда: ");
    scanf("%d", &t.num);
    printf("Пункт отбытия: ");
    scanf("%s", t.punkt_otb);
    printf("Время отбытия (часы минуты): ");
    scanf("%d %d", &t.h_otb, &t.m_otb);
    printf("Пункт прибытия: ");
    scanf("%s", t.punkt_prib);
    printf("Время прибытия (часы минуты): ");
    scanf("%d %d", &t.h_prib, &t.m_prib);
    printf("\n");
    return t;
}

void print_train(Train t) {
    printf("Поезд %d: %s (%d:%d) -> %s (%d:%d)\n", t.num, t.punkt_otb, t.h_otb, t.m_otb, t.punkt_prib, t.h_prib, t.m_prib);
}

int check(Train t) {
    int t_otb = t.h_otb * 60 + t.m_otb;
    int t_prib = t.h_prib * 60 + t.m_prib;
    if (t_prib < t_otb) {
        t_prib = t_prib + 24 * 60;
    }
    int diff = t_prib - t_otb;
    if (diff > 440) {
        return 1;
    }
    else {
        return 0;
    }
}

int writefile(char* fname, Train t1, Train t2, Train t3) {
    FILE* f;
    f = fopen(fname, "wt");
    if (f == NULL) {
        printf("Ошибка открытия файла для записи\n");
        return 0;
    }
    if (check(t1) == 1) {
        fprintf(f, "Поезд %d: %s (%d:%d) -> %s (%d:%d)\n", t1.num, t1.punkt_otb, t1.h_otb, t1.m_otb, t1.punkt_prib, t1.h_prib, t1.m_prib);
    }
    if (check(t2) == 1) {
        fprintf(f, "Поезд %d: %s (%d:%d) -> %s (%d:%d)\n",t2.num, t2.punkt_otb, t2.h_otb, t2.m_otb, t2.punkt_prib, t2.h_prib, t2.m_prib);
    }
    if (check(t3) == 1) {
        fprintf(f, "Поезд %d: %s (%d:%d) -> %s (%d:%d)\n",t3.num, t3.punkt_otb, t3.h_otb, t3.m_otb, t3.punkt_prib, t3.h_prib, t3.m_prib);
    }

    fclose(f);
    return 1;
}
