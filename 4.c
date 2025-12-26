#include <stdio.h>

struct student {
    char name[50];
    int id;
    float grade;
};

void GetStudent(struct student child[][10], int *room) ;

int main() {
    struct student children[20][10];
    int group;
    GetStudent(children, &group);
    printf("\n\n=== Student Information ===\n");
    for(int i = 0; i < group; i++) {
        printf("\nRoom %d:\n", i + 1);
        for(int j = 0; j < 10; j++) {
            printf("Student %d: Name=%s, ID=%d, Grade=%.2f\n", 
                   j + 1, children[i][j].name, children[i][j].id, children[i][j].grade);
        }
    }
    
    return 0;
}
void GetStudent(struct student child[][10], int *room) {
    printf("Enter number of rooms (classrooms): ");
    scanf("%d", room);
    
    for(int i = 0; i < *room; i++) {
        printf("\n=== Room %d ===\n", i + 1);
        for(int j = 0; j < 10; j++) {
            printf("\nStudent %d in Room %d:\n", j + 1, i + 1);
            printf("Enter name: ");
            scanf("%s", child[i][j].name);
            printf("Enter ID: ");
            scanf("%d", &child[i][j].id);
            printf("Enter grade: ");
            scanf("%f", &child[i][j].grade);
        }
    }
}