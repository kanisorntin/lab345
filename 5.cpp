#include <stdio.h>
#include <stdlib.h>

struct student {
    char name[20];
    int age;
};


struct student (*GetStudent(int *room))[10];

int main()
{
    int group;
    struct student (*children)[10];

    children = GetStudent(&group);

    printf("\nRoom %d\n", group);
    for (int i = 0; i < 10; i++) {
        printf("Name: %s Age: %d\n",
               (*children)[i].name,
               (*children)[i].age);
    }

    delete[] children;
    return 0;
}
struct student (*GetStudent(int *room))[10]
{
    struct student (*data)[10] = new student[1][10];

    printf("Enter room number: ");
    scanf("%d", room);

    for (int i = 0; i < 10; i++) {
        printf("Student %d name: ", i + 1);
        scanf("%19s", (*data)[i].name);

        printf("Student %d age: ", i + 1);
        scanf("%d", &(*data)[i].age);
    }

    return data;
}