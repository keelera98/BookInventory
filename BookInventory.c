#include <stdio.h>
#include <malloc.h>

//function declarations
void Menu();
void List(double prices[], char **listOfBooks, int size);
double Total(double prices[], int size);
//constant for array sizes
int const NumberOfBooks = 10;

int main(){
	int answer = 4;
	double priceOfBooks[NumberOfBooks];
	//double pointer for the strings, points to pointers
	//this way we point the each string pointer
	char **listOfBooks;
	int i = 0;

	//allocate memory for the double pointer, this only allocates for the double pointer
	//not for the pointers it points to. We also use the if statement to verify it worked
	if(listOfBooks = malloc(sizeof(char*) * NumberOfBooks)){	
		//allocate memory for each pointer it points to, add 1 because they're strings
		for(int j = 0; j < NumberOfBooks; j++){
			listOfBooks[j] = malloc(sizeof(char) * (NumberOfBooks + 1));
		}

		while(answer && i <= NumberOfBooks){
			Menu();
			scanf("%d", &answer);	
			switch(answer){
				case 0:
					answer = 0;
					break;
				case 1:
					printf("\n");
					printf("Enter the name of the book: ");
					//fgetc makes scanf read the newline so fgets works
					fgetc(stdin);
					fgets(listOfBooks[i], 100, stdin);
					printf("\nEnter the price of the book: ");
					scanf("%lf", &priceOfBooks[i]);
					i++;
					break;
				case 2:
					printf("\n");
					List(priceOfBooks, listOfBooks, i);
					break;
				case 3:
					printf("\n");
					printf("Total: %.2lf", Total(priceOfBooks, i));
					break;
				default:
					answer = 4;
			}
		}

		//freedom

		//free the pointers being pointed to first
		for(int k = 0; k < NumberOfBooks; k++){
			free(listOfBooks[k]);
		}
		//then free the double pointer
		free(listOfBooks);
	}
}

void Menu(){
	printf("\n1. Enter book information\n");
	printf("2. List all books and prices\n");
	printf("3. List total value of inventory\n");
	printf("0. Exit\n");
	printf(">> ");
}

void List(double prices[], char **listOfBooks, int size){
	for(int i = 0; i < size; i++){
		//needed to use %lf or it wouldn't display the price
		printf("%d. Book Name: %s   Book Price: %.2lf\n\n", i + 1, listOfBooks[i], prices[i]);
	}
}

double Total(double prices[], int size){
	double bookTotal = 0;
	for(int i = 0; i < size; i++){
		bookTotal += prices[i];
	}
	return bookTotal;
}
