#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
};

class LinkedList {
    protected:
        struct studentNode *start, *now;

    public:
            LinkedList() ;
            ~LinkedList() ;
            void InsNode(char n[], int a, char s, float g) ;
            void DelNode() ;
            void GoNext() ;
            void GoFirst() ;
            void GoLast() ;
            void ShowAll() ;
            int FindNode(char n[]) ;
            struct studentNode *NowNode() ;
            void EditNode(char n[], int a, char s, float g) ;
        
};
void EditData( LinkedList *l1 );
void AddData( LinkedList *l1 );
void FindData( LinkedList *l1 );
void readfile( LinkedList *l1 );
void writefile( LinkedList *l1 );

int main() {
    LinkedList listA;
    int menu;
    readfile( &listA );
    printf( "        Menu - (1) Add (2) Edit (3) Delete (4) Find (5) Show (0) Edit : " );

    scanf( "%d", &menu );
    while( menu != 0 ) {
        switch( menu ) {
            case 1 : AddData( &listA ) ; break ;
            case 2 : EditData( &listA ) ; break ;
            case 3 : listA.DelNode() ; break ;
            case 4 : FindData( &listA ) ; break ;
            case 5 : listA.ShowAll() ; break ;
        }

        printf( "        Menu - (1) Add (2) Edit (3) Delete (4) Find (5) Show (0) Edit : " );
        scanf( "%d", &menu );
    }

    writefile( &listA );
    return 0;
}
            