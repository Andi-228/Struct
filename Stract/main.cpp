#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<cmath>

struct Book
{
	char title[100];
	char author[150];
	int pageNumber;
	float price;
};

int writeFile(char fname[], Book books[], int size);
int readFile(char fname[], std::vector<Book>& books);
void printBooks(std::vector<Book>& books);


int main() {

	char fileName[] = "books.txt";

	const int size = 4;

	Book  books[] = {
		{"Harry Poter","Joanne Rowling", 534, 450},
		{"Book thief","Marcus Zukas",506,300},
		{"Project Venus", "Jacque Fresco", 503, 250},
		{"The Witcher","Anjei Sapkovsky", 302, 540},
	};

	printf("Writing data to the file %s . . .\n", fileName);
	writeFile(fileName, books, size);

	std::vector<Book> newBooks;

	printf("Writing data from the file %s . . .\n", fileName);
	readFile(fileName, newBooks);

	printBooks(newBooks);

	system("pause");
	return 0;
}


//2 
/*int main() {
	int a;
	double b;
	char str[] = "Hello World!";
	printf("PI = %.5lf\n", M_PI);
	printf("int = %h\n", 10);
	printf("oct = %o\n", 10);
	printf("hex = %x\n", 10);
	printf("str = %s\n", str);

	scanf("%i", &a);
	printf("a = %d\n", a);
	scanf("%lf", &b);
	printf("b = %.3lf\n", b);
	return 0;
}*/
//2

int writeFile(char fname[], Book books[], int size)
{
	FILE* f;

	f = fopen(fname, "w");

	for (int i = 0; i < size; i++) {
		fprintf(f, "%s | %s | %d | %f\n", books[i].title, books[i].author, books[i].pageNumber, books[i].price);
	}

	fclose(f);

	return 0;
}

int readFile(char fname[], std::vector<Book>& books)
{
	FILE* f;

	f = fopen(fname, "r");

	char buff[256];


	while (fgets(buff, 256, f) != NULL) {
		Book b;
		printf("%s", buff);
		//title
		char* subStr = strtok(buff, "|\n");
		strcpy(b.title, subStr);
		//author
		subStr = strtok(NULL, "|\n");
		strcpy(b.author, subStr);
		//page number
		subStr = strtok(NULL, "|\n");
		int pageNumber = atoi(subStr);
		b.pageNumber = pageNumber;
		//price
		subStr = strtok(NULL, "|\n");
		float price = atof(subStr);
		b.price = price;

		books.push_back(b);
	}
	fclose(f);
	return 0;
}

void printBooks(std::vector<Book>& books)
{
	for (int i = 0; i < books.size(); i++) {
		printf("Title: %s, Author: %s, page number: %d, price: %f", books[i].title, books[i].author, books[i].pageNumber, books[i].price);
	}
}
