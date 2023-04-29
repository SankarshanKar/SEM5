#include <stdio.h>
#include <string.h>
 struct info 
{
    int roll_no;
    char name[50];
    float cgpa;
};
 void func(struct info *record)
{
    printf("Roll no is: %d \n", record->roll_no);
    printf("Name is: %s \n", record->name);
    printf("Percentage is: %f \n", record->cgpa);
} 
int main() 
{
    struct info record;

    record.roll_no=123;
    strcpy(record.name, "asd");
    record.cgpa = 7;
 
    func(&record);
    return 0;
}