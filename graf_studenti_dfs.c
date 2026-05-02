#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct NodPrincipal NodPrincipal;
typedef struct NodSecundar NodSecundar;
typedef struct Student Student;

typedef struct Nod Nod;
typedef struct ListaDubla ListaDubla;

struct Nod {
	int ID;
	Nod* next;
	Nod* prev;
};

struct ListaDubla {
	Nod* first;
	Nod* last;
};

struct Student {
	int id;
	char* nume;
	float medie;
};

struct NodPrincipal {
	Student info;
	NodPrincipal* next;
	NodSecundar* vecini;
};

struct NodSecundar {
	NodPrincipal* info;
	NodSecundar* next;
};

void push(ListaDubla* ld, int ID) {
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->next = ld->first;
	nou->prev = NULL;
	nou->ID = ID;

	if (ld->first == NULL) {
		ld->first = ld->last = nou;
	}
	else {
		ld->first->prev = nou;
		ld->first = nou;
	}
}

int pop(ListaDubla* ld) {
	int ID = -1;
	if (ld->first) {
		ID = ld->first->ID;
		Nod* aux = ld->first;
		ld->first = ld->first->next;
		if (ld->first == NULL) {
			ld->last = NULL;
		}
		free(aux);
	}
	return ID;
}

Student initStudent(int id, const char* nume, float medie) {
	Student s;
	s.id = id;
	s.medie = medie;

	s.nume = (char*)malloc(strlen(nume) + 1);
	strcpy(s.nume, nume);

	return s;
}

void inserareListaPrincipala(NodPrincipal** cap, Student s) {
	NodPrincipal* nou = (NodPrincipal*)malloc(sizeof(NodPrincipal));
	nou->info = s;
	nou->next = NULL;
	nou->vecini = NULL;

	if (*cap == NULL) {
		*cap = nou;
	}
	else {
		NodPrincipal* temp = *cap;
		while (temp->next) {
			temp = temp->next;
		}
		temp->next = nou;
	}
}

void inserareListaSecundara(NodSecundar** cap, NodPrincipal* info) {
	NodSecundar* nou = (NodSecundar*)malloc(sizeof(NodSecundar));
	nou->info = info;
	nou->next = NULL;

	if (*cap == NULL) {
		*cap = nou;
	}
	else {
		NodSecundar* temp = *cap;
		while (temp->next) {
			temp = temp->next;
		}
		temp->next = nou;
	}
}

NodPrincipal* cautare(NodPrincipal* graf, int id) {
	while (graf && graf->info.id != id) {
		graf = graf->next;
	}
	return graf;
}

void adaugaMuchie(NodPrincipal* graf, int id1, int id2) {
	NodPrincipal* n1 = cautare(graf, id1);
	NodPrincipal* n2 = cautare(graf, id2);

	if (n1 && n2) {
		inserareListaSecundara(&n1->vecini, n2);
		inserareListaSecundara(&n2->vecini, n1);
	}
}

void afisareStudent(Student s) {
	printf("\n%d %s %.2f", s.id, s.nume, s.medie);
}

void afisareGraf(NodPrincipal* graf) {
	while (graf) {
		afisareStudent(graf->info);
		NodSecundar* v = graf->vecini;
		printf(" -> ");
		while (v) {
			printf("%d ", v->info->info.id);
			v = v->next;
		}
		printf("\n");
		graf = graf->next;
	}
}

void DFS(NodPrincipal* graf, int start) {
	int viz[10] = { 0 };

	ListaDubla stiva = { NULL, NULL };
	push(&stiva, start);
	viz[start] = 1;

	while (stiva.first) {
		int id = pop(&stiva);
		NodPrincipal* nod = cautare(graf, id);
		afisareStudent(nod->info);

		NodSecundar* v = nod->vecini;
		while (v) {
			if (!viz[v->info->info.id]) {
				push(&stiva, v->info->info.id);
				viz[v->info->info.id] = 1;
			}
			v = v->next;
		}
	}
}

int main() {
	NodPrincipal* graf = NULL;

	inserareListaPrincipala(&graf, initStudent(1, "Ana", 8));
	inserareListaPrincipala(&graf, initStudent(2, "Ion", 7));
	inserareListaPrincipala(&graf, initStudent(3, "Maria", 9));

	adaugaMuchie(graf, 1, 2);
	adaugaMuchie(graf, 1, 3);

	afisareGraf(graf);

	printf("\nDFS:");
	DFS(graf, 1);

	return 0;
}