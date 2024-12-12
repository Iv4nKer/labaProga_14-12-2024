#include <stdio.h>
#include <stdlib.h>
#include "infa.h"
int main() {
	tvr *arr = NULL;
	int count = 0;
	load(&arr, &count);
	int n;
	do {
		printf("---------------------------------------\n");
		printf("Menu smetana:\n");
		printf("1. Skachat smetu bez sms i registracii \n");
		printf("2. Pokazat smetu\n");
		printf("3. Dobavit tovar\n");
		printf("4. Ydalit tovar\n");
		printf("5. Redaktirovat tovar\n");
		printf("6. Naiti tovar\n");
		printf("0. Exit\n");
		printf("---------------------------------------\n");
		scanf("%i", &n);
		switch (n) {
			case 1:
				create(&arr, &count);
				break;
			case 2:
				show(arr, count);
				break;
			case 3:
				add(&arr, &count);
				break;
			case 4:
				del(arr, &count);
				break;
			case 5:
				edit(arr, count);
				break;
			case 6:
				search(arr, count);
				break;
			case 0:
				printf("⚠️ Bye-Bye⚠️ \n");
				save(arr, count);
				free(arr);
				break;
			default:
				printf("Ne ponimau \n");
		}
	}
	while (n != 0);
	return 0;
}
