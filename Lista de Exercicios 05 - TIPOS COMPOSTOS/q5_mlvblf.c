#include <stdio.h>

typedef struct {
    int x;
    int y;
} Ponto;

typedef struct {
    Ponto a;
    Ponto c;
} Ret;


int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        Ret r;
        Ponto robo;
        int bx, by, dx, dy;

        scanf("%d %d %d %d %d %d %d %d %d %d",
              &r.a.x, &r.a.y,
              &bx, &by,
              &r.c.x, &r.c.y,
              &dx, &dy,
              &robo.x, &robo.y);

        if (robo.x >= r.a.x && robo.x <= r.c.x &&
            robo.y >= r.a.y && robo.y <= r.c.y) {
            printf("1\n");
        } else {
            printf("0\n");
        }
    }

    return 0;
}
