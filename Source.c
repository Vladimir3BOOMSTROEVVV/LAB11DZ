#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include "functions.h" 

int main() {
    setlocale(LC_CTYPE, "RUS");
    Train t1, t2, t3;
    printf("--- Ввод первого поезда ---\n");
    t1 = input_train();
    printf("--- Ввод второго поезда ---\n");
    t2 = input_train();
    printf("--- Ввод третьего поезда ---\n");
    t3 = input_train();
    printf("Поезда в пути больше 7 часов 20 минут:\n");
    if (check(t1) == 1) {
        print_train(t1);
    }
    if (check(t2) == 1) {
        print_train(t2);
    }
    if (check(t3) == 1) {
        print_train(t3);
    }
    if (writefile("trains.txt", t1, t2, t3) == 1) {
        printf("\nДанные успешно записаны в файл trains.txt\n");
    }
    else {
        printf("\nОшибка записи в файл!\n");
    }
    return 0;
}
