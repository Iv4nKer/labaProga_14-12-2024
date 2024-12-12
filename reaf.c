#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "infa.h"
void create(tvr **arr, int *count){
	FILE *file = fopen("smeta.txt", "rb");
	*count = 5;
	*arr = realloc(*arr, (*count + 1) * sizeof(tvr));
	strcpy((*arr)[0].name, "Pen");
	strcpy((*arr)[0].color, "Red");
	(*arr)[0].cost = 15;
	strcpy((*arr)[1].name, "Book");
        strcpy((*arr)[1].color, "Black");
        (*arr)[1].cost = 25;
	strcpy((*arr)[2].name, "Lineika");
        strcpy((*arr)[2].color, "Wood");
        (*arr)[2].cost = 50;
	strcpy((*arr)[3].name, "Karandash");
        strcpy((*arr)[3].color, "Gray");
        (*arr)[3].cost = 25;
	strcpy((*arr)[4].name, "Reshebnik po mat analizu");
        strcpy((*arr)[4].color, "Gold");
        (*arr)[4].cost = 1500;
		return;
}
void load(tvr **arr, int *count) {
	FILE *file = fopen("smeta.txt", "rb");
	if (!file) {
                *count = 0;
                *arr = NULL;
		return;
	}
	fread(count, sizeof(int), 1, file);
	*arr = malloc((*count) * sizeof(tvr));
	fread(*arr, sizeof(tvr), *count, file);
	fclose(file);
}
void save(tvr *arr, int count) {
	FILE *file = fopen("smeta.txt", "wb");
	fwrite(&count, sizeof(int), 1, file);
	fwrite(arr, sizeof(tvr), count, file);
	fclose(file);
}
void add(tvr **arr, int *count) {
	*arr = realloc(*arr, (*count + 1) * sizeof(tvr));
	tvr *newtvr = &(*arr)[*count];
	printf("Vvedite nazvanie tovara: \n");
	scanf("%s", newtvr->name);
	printf("Vvedite color tovara: \n");
	scanf("%s", newtvr->color);
	printf("Vvedite ego cost: \n");
	scanf("%i", &newtvr->cost);
	(*count)++;
}
void del(tvr *arr, int *count) {
        char name[20];
        printf("Vvedite nazvanie tovara dla ydalenia: ");
        scanf("%s", name);
	char color[20];
	printf("Vvedite ego color: ");
	scanf("%s", color);
	int cost;
	printf("Vvedite ego cost: ");
        scanf("%i", &cost);
	for (int i=0; i < (*count); i++){
		if(strcmp(arr[i].name, name)==0, strcmp(arr[i].color, color)==0){
			arr[i]=arr[i+1];
			arr=realloc(arr,(*count)*sizeof(tvr));
			(*count)--;
			printf("Tovar ydalili\n");
			return;
		}
	}
	printf("Tovar ne nashli\n");
}
void edit(tvr *arr, int count) {
	int n;
	printf("Vvedite nomer tovara: ");
	scanf("%i", &n);
	if (n < 0, n >= (count+1)) {
		printf("Ne nashli! \n");
		return;
	}
		tvr *tvre = &arr[n-1];
		char name[20];
		printf("Vvedite novoe nazvanie: ");
	        scanf("%s", name);
		char color[20];
        	printf("Noviy color: ");
        	scanf("%s", color);
		int cost;
        	printf("Noviy cost: ");
        	scanf("%i", &cost);
		strcpy(tvre->name, name);
		strcpy(tvre->color, color);
		tvre->cost = cost;
}
void search(tvr *arr, int count) {
	char name[20];
	printf("Vvedite nazvanir tovara: ");
	scanf("%s", name);
	char color[20];
        printf("Vvedite color tovara: ");
        scanf("%s", color);
        for (int i=0; i<count; i++){
                if(strcmp(arr[i].name, name)==0, strcmp(arr[i].color, color)==0){
                        printf("Nashli tovar:[name: %s | color: %s | cost: %d] \n", arr[i].name, arr[i].color, arr[i].cost);
			return;
                }
        }
	printf("Ne nashli takogo \n");
}
void show(tvr *arr, int count) {
	for (int i = 0; i < count; i++) {
		printf("[%i. Name: %s | Color: %s | Cost: %d] \n",i + 1 , arr[i].name, arr[i].color, arr[i].cost);
	}
}
