#include <stdio.h>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
};

class LinkedList {
    protected:
        studentNode *start, **now;

    public:
        LinkedList();
        ~LinkedList();
        void InsNode(char n[], int a, char s, float g);
        void DelNode();
        GoNext();
        virtual void ShowNode();
};

class NewList : public LinkedList {
    public:
        GoFirst();
        virtual void ShowNode();
};

int main() {

    LinkedList listA;
    NewList listB;
    LinkedList *listC;

    listA.InsNode("one", 1, 'A', 1.1);
    listA.InsNode("two", 2, 'B', 2.2);
    listA.InsNode("three", 3, 'C', 3.3);
    listA.GoNext();
    listA.ShowNode();

    listB.InsNode("four", 4, 'D', 4.4);
    listB.InsNode("five", 5, 'E', 5.5);
    listB.InsNode("six", 6, 'F', 6.6);
    listB.GoNext();
    listB.DelNode();
    listB.ShowNode();

    listC = &listA;
    listC->GoNext();
    listC->ShowNode();

    listC = &listB;
    listC->ShowNode();

    return 0;
} 