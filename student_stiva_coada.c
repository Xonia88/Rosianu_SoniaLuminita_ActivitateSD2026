//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<malloc.h>
//#include<string.h>
//
//typedef struct Student Student;
//typedef struct Nod Nod;
//
//struct Student {
//	char* nume;
//	int varsta;
//	float medie;
//};
//
//struct Nod {
//	Student info;
//	Nod* next;
//};
//
//Student initStudent(const char* nume, int varsta, float medie) {
//	Student s;
//	s.varsta = varsta;
//	s.medie = medie;
//
//	if (nume != NULL) {
//		s.nume = (char*)malloc(sizeof(char) * (strlen(nume) + 1));
//		strcpy(s.nume, nume);
//
//	}
//	else {
//		s.nume = NULL;
//	}
//	return s;
//}
//
//void afisareStudent(Student s) {
//	printf("\nStudentul %s are varsta %d si media %.2f",
//		s.nume, s.varsta, s.medie);
//}
//void push(Nod** varf, Student s) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = s;
//	nou->next = *varf;
//	*varf = nou;
//}
//
//Student pop(Nod** varf) {
//	if (*varf == NULL) {
//		return initStudent(NULL, 0, 0);
//
//	}
//	Student s = (*varf)->info;
//	Nod* temp = *varf;
//	*varf = (*varf)->next;
//	free(temp);
//
//	return s;
//}
//
//void put(Nod** coada, Student s) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = s;
//	nou->next = NULL;
//
//	if (*coada == NULL) {
//		*coada = nou;
//	}
//	else {
//		Nod* temp = *coada;
//		while (temp->next != NULL) {
//			temp = temp->next;
//		}
//		temp->next = nou;
//	}
//
//}
//
//int main() {
//
//	Nod* stiva = NULL;
//
//	push(&stiva, initStudent("Ana", 21, 7.5));
//	push(&stiva, initStudent("Andreea", 19, 7.5));
//	push(&stiva, initStudent("Vica", 22, 8));
//
//
//	printf("\nTraversare stiva: ");
//
//	while (stiva != NULL) {
//		Student s = pop(&stiva);
//		afisareStudent(s);
//		free(s.nume);
//	}
//
//	Nod* coada = NULL;
//
//	put(&coada, initStudent("Ana", 21, 7.5));
//	put(&coada, initStudent("Andreea", 19, 7.5));
//	put(&coada, initStudent("Vica", 22, 8));
//
//
//	printf("\nTraversare coada: ");
//
//	while (coada != NULL) {
//		Student s = pop(&coada);
//		afisareStudent(s);
//		free(s.nume);
//	}
//
//	return 0;
//}
