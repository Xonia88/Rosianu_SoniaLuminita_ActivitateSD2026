//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<malloc.h>
//#include<string.h>
//
//typedef struct Angajat {
//	int id;
//	char* nume;
//	float salariu;
//} Angajat;
//
//typedef struct Nod {
//	Angajat info;
//	struct Nod* next;
//} Nod;
//
//Angajat initAngajat(int id, const char* nume, float salariu) {
//	Angajat a;
//	a.id = id;
//	a.salariu = salariu;
//	a.nume = (char*)malloc(sizeof(char) * (strlen(nume) + 1));
//	strcpy(a.nume, nume);
//	return a;
//}
//
//void afisareAngajat(Angajat a) {
//	printf("\nAngajatul %s (ID: %d) are salariul %.2f", a.nume, a.id, a.salariu);
//}
//
//void push(Nod** varf, Angajat a) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = a;
//	nou->next = *varf;
//	*varf = nou;
//}
//
//Angajat pop(Nod** varf) {
//	Angajat a;
//	if (*varf == NULL) {
//		a.id = 0;
//		a.nume = NULL;
//		a.salariu = 0;
//		return a;
//	}
//	a = (*varf)->info;
//	Nod* temp = *varf;
//	*varf = (*varf)->next;
//	free(temp);
//	return a;
//}
//
//void put(Nod** coada, Angajat a) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->info = a;
//	nou->next = NULL;
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
//}
//
//int main() {
//	Nod* stiva = NULL;
//	push(&stiva, initAngajat(1, "Ana", 3500));
//	push(&stiva, initAngajat(2, "Ion", 4200));
//	push(&stiva, initAngajat(3, "Maria", 3900));
//
//	printf("\nTraversare stiva:");
//	while (stiva != NULL) {
//		Angajat a = pop(&stiva);
//		afisareAngajat(a);
//		free(a.nume);
//	}
//
//	Nod* coada = NULL;
//	put(&coada, initAngajat(1, "Ana", 3500));
//	put(&coada, initAngajat(2, "Ion", 4200));
//	put(&coada, initAngajat(3, "Maria", 3900));
//
//	printf("\n\nTraversare coada:");
//	while (coada != NULL) {
//		Angajat a = pop(&coada);
//		afisareAngajat(a);
//		free(a.nume);
//	}
//
//	return 0;
//}