#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
    struct studentNode *back;
};

void ShowAll(struct studentNode *walk);
struct studentNode* AddNode(struct studentNode **start, char n[], int a, char s, float g);
void InsNode(struct studentNode *now, char n[], int a, char s, float g);
void DelNode(struct studentNode **start, struct studentNode **now);
void GoBack(struct studentNode **now);

int main() {
    struct studentNode *start = NULL, *now = NULL;
    
    now = AddNode(&start, "one", 6, 'M', 3.11);
    ShowAll(start);
    now = AddNode(&start, "two", 8, 'F', 3.22);
    ShowAll(start);
    InsNode(now, "three", 10, 'M', 3.33);
    ShowAll(start);
    InsNode(now, "four", 12, 'F', 3.44);
    ShowAll(start);
    GoBack(&now);
    DelNode(&start, &now);
    ShowAll(start);
    DelNode(&start, &now);
    ShowAll(start);
    DelNode(&start, &now);
    ShowAll(start);
    return 0;
}

void ShowAll(struct studentNode *walk) {
    while(walk != NULL) {
        printf("%s ", walk->name);
        walk = walk->next;
    }
    printf("\n");
}

struct studentNode* AddNode(struct studentNode **start, char n[], int a, char s, float g) {
    struct studentNode *newNode, *walk;

    newNode = (struct studentNode*)malloc(sizeof(struct studentNode));
    strcpy(newNode->name, n);
    newNode->age = a;
    newNode->sex = s;
    newNode->gpa = g;
    newNode->next = NULL;
    newNode->back = NULL;
    
    if(*start == NULL) {
        *start = newNode;
    } else {
        walk = *start;
        while(walk->next != NULL) {
            walk = walk->next;
        }
        walk->next = newNode;
        newNode->back = walk;
    }
    
    return newNode;
}

void InsNode(struct studentNode *now, char n[], int a, char s, float g) {
    struct studentNode *newNode;
    
    if(now == NULL) return;

    newNode = (struct studentNode*)malloc(sizeof(struct studentNode));
    strcpy(newNode->name, n);
    newNode->age = a;
    newNode->sex = s;
    newNode->gpa = g;
    newNode->next = now->next;
    newNode->back = now;

    if(now->next != NULL) {
        now->next->back = newNode;
    }
    now->next = newNode;
}

void DelNode(struct studentNode **start, struct studentNode **now) {
    struct studentNode *temp;
    if(*now == NULL) return;
    temp = *now;
    if(*now == *start) {
        *start = (*now)->next;
        if(*start != NULL) {
            (*start)->back = NULL;
        }
        *now = *start;
    } 

    else if((*now)->next == NULL) {
        (*now)->back->next = NULL;
        *now = (*now)->back;
    }
    else {
        (*now)->back->next = (*now)->next;
        (*now)->next->back = (*now)->back;
        *now = (*now)->next;
    }
    
    free(temp);
}

void GoBack(struct studentNode **now) {
    if(*now != NULL && (*now)->back != NULL) {
        *now = (*now)->back;
    }
}