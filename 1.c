#include <stdio.h>

struct student {
    char name[20];
    int age;
    char sex;
    float gpa;
};

void upgrade(struct student child);

int main() {
    struct student aboy;
    aboy.sex = 'M';
    aboy.gpa = 3.00;
    upgrade(aboy);
    printf("%.2f\n", aboy.gpa);
    return 0;
}
void upgrade(struct student child) {
    if (child.gpa < 2.00) {
        child.gpa = child.gpa * 1.10;
    } else {
        child.gpa = child.gpa * 1.20;
    }
}