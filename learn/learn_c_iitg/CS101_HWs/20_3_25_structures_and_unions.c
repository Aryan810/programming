#include <stdio.h>
#include <string.h>
struct Student{
    char name[20];
    int age;
    int rollno;
};

int main(){
    struct Student st;
    struct Student *s = &st;
    scanf("%[^\n]", &(s->name));
    // gets(s->name);

    scanf("%d", &(s->age));
    scanf("%d", &(s->rollno));

    printf("Name: %s\n", s->name);
    printf("Age: %d\n", s->age);
    printf("Roll no.: %d\n", s->rollno);
    printf("size: %d\n", sizeof(s));
    printf("size: %d\n", sizeof(int));

    return 0;
}