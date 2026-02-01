#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Definição de struct
typedef struct {
    char name[50];
    int age;
    float gpa;
    bool isFullTime;
} Student;

typedef struct {
    int hora;
    int minuto;
    int segundo;
} Horario;

void printStudent(Student student);

int main() {

    Horario hora1 = {0};
    hora1.hora = 12;
    hora1.minuto = 29;
    hora1.segundo = 41;
    printf("Horário: %d:%d:%d\n", hora1.hora, hora1.minuto, hora1.segundo);

    Student students[] = {
            {"Brenda", 47, 10.0, false},  
            {"Otley", 48, 93.5, true}, 
            {"Luiza", 19, 92.5, true}
        };

    int size = sizeof(students) / sizeof(students[0]);
    for (int i = 0; i < size; i++) {
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
    }

    return 0;
}

void printStudent(Student student) {
    printf("Name: %s\n", student.name);
    printf("Age: %d\n", student.age);
    printf("Grade Point Average: %.2f\n", student.gpa);
    printf("Is Full Time?: %s\n", (student.isFullTime) ? "Yes" : "No");
    printf("\n");
}