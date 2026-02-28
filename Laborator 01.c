//vizionare 002 - Laborator 01 - functii utilizate si structura Telefon 

#include<stdio.h>
#include<stdlib.h>

struct Telefon {
	int id;
	int RAM;
	char* producator;
	float pret;
	char serie;
};

struct Telefon initializare(int id, int ram, const char* producator, float pret, char serie) {
	struct Telefon t;
	t.id = id;
	t.RAM = ram;
	t.producator = (char*)malloc(sizeof(char) * (strlen(producator) + 1));
	strcpy_s(t.producator, strlen(producator) + 1, producator);
	t.pret = pret;
	t.serie = serie;
	
	return t;
}

void afisare(struct Telefon t) {
	if (t.producator != NULL) {
	
	printf("%d. Telefonul %s seria %c are %d Gb RAM si costa %5.2f RON.\n", 
		t.id, t.producator, t.serie, t.RAM, t.pret);

}
	else {

	printf("%d. Telefonul are seria %c, %d Gb RAM si costa %5.2f RON.\n", 
		t.id, t.serie, t.RAM, t.pret);
	}
}

void modificaPret(struct Telefon* t, float noulPret) {
	if (noulPret > 0) {
		t->pret = noulPret;

	}
}

void dezalocare(struct Telefon* t) {
	if (t->producator != NULL) {
		free(t->producator);
		t->producator = NULL;
	}
}

int main() {
	struct Telefon t;
	t = initializare(1, 256, "Apple", 6000.5, 'A');
	afisare(t);
	modificaPret(&t, 9000);
	afisare(t);
	dezalocare(&t);
	afisare(t);
	return 0;
}