#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h> 

struct point {
    float x;
    float y;
    char name;
};
typedef struct point Point;
Point input_point();
void put_point(Point z);
double distance(Point a, Point b);
int check(double d1, double d2);
int writefile(char* fname, Point a, Point b, Point c, double d_ab, double d_bc);

int main() {
    setlocale(LC_CTYPE, "RUS");

    Point a, b, c;

    printf("--- Ввод точки 1 ---\n");
    a = input_point();
    printf("--- Ввод точки 2 ---\n");
    b = input_point();
    printf("--- Ввод точки 3 ---\n");
    c = input_point();

    printf("--- Введенные точки ---\n");
    put_point(a);
    put_point(b);
    put_point(c);

    double dist_ab = distance(a, b);
    double dist_bc = distance(b, c);

    printf("\n--- Результаты вычислений ---\n");
    printf("Расстояние между %c и %c: %.2f\n", a.name, b.name, dist_ab);
    printf("Расстояние между %c и %c: %.2f\n", b.name, c.name, dist_bc);

    if (check(dist_ab, dist_bc) == 1) {
        printf("Расстояние %c-%c больше, чем %c-%c\n", a.name, b.name, b.name, c.name);
    }
    else {
        printf("Расстояние %c-%c не больше, чем %c-%c\n", a.name, b.name, b.name, c.name);
    }

    if (writefile("result.txt", a, b, c, dist_ab, dist_bc) == 1) {
        printf("\nДанные успешно сохранены в файл result.txt\n");
    }
    else {
        printf("\nОшибка при сохранении в файл!\n");
    }

    return 0;
}

Point input_point() {
    Point p;
    printf("Введите имя точки: ");
    scanf(" %c", &p.name);
    printf("Введите координаты X и Y через пробел: ");
    scanf("%f %f", &p.x, &p.y);
    printf("\n");
    return p;
}

void put_point(Point z) {
    printf("point %c (%.1f, %.1f)\n", z.name, z.x, z.y);
}

double distance(Point a, Point b) {
    double d;
    d = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    return d;
}

int check(double d1, double d2) {
    if (d1 > d2) {
        return 1;
    }
    else {
        return 0;
    }
}

int writefile(char* fname, Point a, Point b, Point c, double d_ab, double d_bc) {
    FILE* f;
    f = fopen(fname, "wt");
    if (f == NULL) {
        printf("Ошибка открытия файла для записи!\n");
        return 0;
    }

    fprintf(f, "Точки на плоскости:\n");
    fprintf(f, "point %c (%.1f, %.1f)\n", a.name, a.x, a.y);
    fprintf(f, "point %c (%.1f, %.1f)\n", b.name, b.x, b.y);
    fprintf(f, "point %c (%.1f, %.1f)\n", c.name, c.x, c.y);

    fprintf(f, "\nРасстояния между точками:\n");
    fprintf(f, "Расстояние %c-%c = %.2f\n", a.name, b.name, d_ab);
    fprintf(f, "Расстояние %c-%c = %.2f\n", b.name, c.name, d_bc);

    if (check(d_ab, d_bc) == 1) {
        fprintf(f, "Расстояние %c-%c больше, чем %c-%c\n", a.name, b.name, b.name, c.name);
    }
    else {
        fprintf(f, "Расстояние %c-%c меньше или равно %c-%c\n", a.name, b.name, b.name, c.name);
    }

    fclose(f);
    return 1;
}
