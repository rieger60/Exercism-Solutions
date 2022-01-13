#include "grade_school.h"

void init_roster(roster_t *actual)
{
	actual->count = 0;
}

bool add_student(roster_t *actual, char name[], int grade)
{
	if (actual->count >= MAX_STUDENTS)
		return false;

	for (size_t i = 0; i < actual->count; i++) {
		if (strcmp(actual->students[i].name, name) == 0) {
			return false;
		}
	}

	strcpy(actual->students[actual->count].name, name);
	actual->students[actual->count].grade = grade;
	actual->count++;
	qsort(actual->students, actual->count, sizeof(student_t), cmpfunc);

	return true;
}

roster_t get_grade(roster_t *actual, int desired_grade)
{
	roster_t desired;
	init_roster(&desired);

	for (size_t i = 0; i < actual->count; i++) {
		if (actual->students[i].grade == desired_grade) {
			add_student(&desired, actual->students[i].name, actual->students[i].grade);
		} 
	}
	return desired;
}

int cmpfunc(const void* a, const void* b)
{
	student_t *s1 = (student_t *)a;
	student_t *s2 = (student_t *)b;

	if (s1->grade > s2->grade)
		return 1;
	else if (s1->grade < s2->grade)
		return -1;

	if (strcmp(s1->name, s2->name) > 0)
		return 1;
	else if (strcmp(s1->name, s2->name) < 0)
		return -1;

	return 0;
}