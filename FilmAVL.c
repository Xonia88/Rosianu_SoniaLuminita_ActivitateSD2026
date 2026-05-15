#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Film {

	int id;
	char* titlu;

}Film;

typedef struct Nod {

	Film info;

	struct Nod* st;
	struct Nod* dr;

}Nod;

Film creareFilm(int id, const char* titlu) {

	Film f;

	f.id = id;

	f.titlu = (char*)malloc(strlen(titlu) + 1);

	strcpy(f.titlu, titlu);

	return f;
}

int maxim(int a, int b) {

	return a > b ? a : b;
}

int inaltime(Nod* rad) {

	if (rad == NULL)
		return 0;

	return 1 + maxim(
		inaltime(rad->st),
		inaltime(rad->dr));
}

int diferenta(Nod* rad) {

	if (rad == NULL)
		return 0;

	return inaltime(rad->st) -
		inaltime(rad->dr);
}

void rotireDreapta(Nod** rad) {

	Nod* aux = (*rad)->st;

	(*rad)->st = aux->dr;

	aux->dr = *rad;

	*rad = aux;
}

void rotireStanga(Nod** rad) {

	Nod* aux = (*rad)->dr;

	(*rad)->dr = aux->st;

	aux->st = *rad;

	*rad = aux;
}

void inserareAVL(Nod** rad, Film f) {

	if (*rad == NULL) {

		Nod* nou = (Nod*)malloc(sizeof(Nod));

		nou->info = f;

		nou->st = NULL;
		nou->dr = NULL;

		*rad = nou;
	}
	else {

		if (f.id < (*rad)->info.id) {

			inserareAVL(&((*rad)->st), f);
		}
		else {

			inserareAVL(&((*rad)->dr), f);
		}
	}

	int diff = diferenta(*rad);

	if (diff > 1) {

		rotireDreapta(rad);
	}

	if (diff < -1) {

		rotireStanga(rad);
	}
}

void afisare(Nod* rad) {

	if (rad != NULL) {

		afisare(rad->st);

		printf("\n%d %s",
			rad->info.id,
			rad->info.titlu);

		afisare(rad->dr);
	}
}

int main() {

	Nod* rad = NULL;

	inserareAVL(&rad, creareFilm(2, "Titanic"));
	inserareAVL(&rad, creareFilm(3, "Avatar"));
	inserareAVL(&rad, creareFilm(1, "Joker"));

	afisare(rad);

	return 0;
}