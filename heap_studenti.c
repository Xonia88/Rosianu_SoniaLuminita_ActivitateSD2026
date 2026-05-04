#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student Student;
typedef struct Heap Heap;

struct Student {
	int id;
	int varsta;
	float medie;
	char* nume;
	char* facultate;
	unsigned char grupa;
};

struct Heap {
	int lungime;
	Student* studenti;
	int nrElemente;
};

Student citireStudentDinFisier(FILE* file) {
	char buffer[100];
	char sep[3] = ",\n";
	Student s;
	s.id = -1;
	s.nume = NULL;
	s.facultate = NULL;

	if (fgets(buffer, 100, file) == NULL) {
		return s;
	}

	char* aux;

	aux = strtok(buffer, sep);
	if (aux != NULL) s.id = atoi(aux);

	aux = strtok(NULL, sep);
	if (aux != NULL) s.varsta = atoi(aux);

	aux = strtok(NULL, sep);
	if (aux != NULL) s.medie = (float)atof(aux);

	aux = strtok(NULL, sep);
	if (aux != NULL) {
		s.nume = (char*)malloc(strlen(aux) + 1);
		strcpy(s.nume, aux);
	}

	aux = strtok(NULL, sep);
	if (aux != NULL) {
		s.facultate = (char*)malloc(strlen(aux) + 1);
		strcpy(s.facultate, aux);
	}

	aux = strtok(NULL, sep);
	if (aux != NULL) {
		s.grupa = aux[0];
	}

	return s;
}

void afisareStudent(Student s) {
	printf("\nId: %d", s.id);
	printf("\nVarsta: %d", s.varsta);
	printf("\nMedie: %.2f", s.medie);
	printf("\nNume: %s", s.nume ? s.nume : "-");
	printf("\nFacultate: %s", s.facultate ? s.facultate : "-");
	printf("\nGrupa: %c\n", s.grupa);
}

Heap initializareHeap(int lungime) {
	Heap heap;
	heap.lungime = lungime;
	heap.studenti = (Student*)malloc(sizeof(Student) * lungime);
	heap.nrElemente = 0;
	return heap;
}

void filtreazaHeap(Heap heap, int pozitieNod) {
	int st = 2 * pozitieNod + 1;
	int dr = 2 * pozitieNod + 2;
	int min = pozitieNod;

	if (st < heap.nrElemente && heap.studenti[min].medie > heap.studenti[st].medie) {
		min = st;
	}

	if (dr < heap.nrElemente && heap.studenti[min].medie > heap.studenti[dr].medie) {
		min = dr;
	}

	if (min != pozitieNod) {
		Student aux = heap.studenti[min];
		heap.studenti[min] = heap.studenti[pozitieNod];
		heap.studenti[pozitieNod] = aux;

		if (min < (heap.nrElemente - 2) / 2) {
			filtreazaHeap(heap, min);
		}
	}
}

Heap citireHeapDinFisier(const char* numeFisier) {
	Heap heap = initializareHeap(10);
	FILE* f = fopen(numeFisier, "r");

	if (f == NULL) {
		printf("Fisierul nu a fost gasit!\n");
		return heap;
	}

	while (1) {
		Student s = citireStudentDinFisier(f);
		if (s.id == -1) break;

		heap.studenti[heap.nrElemente++] = s;
	}

	fclose(f);

	for (int i = (heap.nrElemente - 2) / 2; i >= 0; i--) {
		filtreazaHeap(heap, i);
	}

	return heap;
}

void afisareHeap(Heap heap) {
	for (int i = 0; i < heap.nrElemente; i++) {
		afisareStudent(heap.studenti[i]);
	}
}

Student extrageStudent(Heap* heap) {
	Student s;
	s.id = -1;

	if (heap->nrElemente > 0) {
		s = heap->studenti[0];
		heap->studenti[0] = heap->studenti[heap->nrElemente - 1];
		heap->nrElemente--;

		for (int i = (heap->nrElemente - 2) / 2; i >= 0; i--) {
			filtreazaHeap(*heap, i);
		}
	}

	return s;
}

void dezalocareHeap(Heap* heap) {
	for (int i = 0; i < heap->nrElemente; i++) {
		if (heap->studenti[i].nume != NULL)
			free(heap->studenti[i].nume);

		if (heap->studenti[i].facultate != NULL)
			free(heap->studenti[i].facultate);
	}
	free(heap->studenti);
}

int main() {

	Heap heap = citireHeapDinFisier("studenti.txt");

	printf("\nHeap:");
	afisareHeap(heap);

	printf("\nExtrageri:");
	afisareStudent(extrageStudent(&heap));
	afisareStudent(extrageStudent(&heap));

	printf("\nHeap ramas:");
	afisareHeap(heap);

	dezalocareHeap(&heap);

	return 0;
}