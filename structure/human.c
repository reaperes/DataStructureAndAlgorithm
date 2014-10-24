#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef struct {
	char name[10];
	int age;
	float salary;
} humanBeing_t;

int humansEqualByCallByValue(humanBeing_t person1, humanBeing_t person2);
int humansEqualByCallByReference(humanBeing_t *person1, humanBeing_t *person2);

int main(int argc, char *argv[]) {
	humanBeing_t p1, p2;
	strcpy(p1.name, "a");
	p1.age = 10;
	p1.salary = 10.0f;
	
	strcpy(p2.name, "a");
	p2.age = 10;
	p2.salary = 10.0f;
	
	int result = humansEqualByCallByValue(p1, p2);
	printf("%d", result);
	
	return 0;
}

int humansEqualByCallByValue(humanBeing_t person1, humanBeing_t person2)
{
	if (strcmp(person1.name, person2.name))
		return FALSE;
	if (person1.age != person2.age)
		return FALSE;
	if (person1.salary != person1.salary)
		return FALSE;
	return TRUE;
}

int humansEqualByCallByReference(humanBeing_t *person1, humanBeing_t *person2)
{
	if (strcmp(person1->name, person2->name))
		return FALSE;
	if (person1->age != person2->age)
		return FALSE;
	if (person1->salary != person2->salary)
		return FALSE;
	return TRUE;
}