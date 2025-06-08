// Basic library management system with below functions
// 1.Add a new book
// 2.Display all books
// 3.Search book by ID
// 4.Delete book by ID
// 5.Update book info
// 6.Exit the program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "library.dat"

typedef struct {
    int id;
    char title[100];
    char author[100];
    int quantity;
} Book;

void addBook() {
    FILE *fp = fopen(FILE_NAME, "ab");
    Book b;
    printf("Enter Book ID: ");
    scanf("%d", &b.id);
    printf("Enter Title: ");
    getchar();  // consume newline
    fgets(b.title, 100, stdin);
    b.title[strcspn(b.title, "\n")] = '\0';  // remove newline
    printf("Enter Author: ");
    fgets(b.author, 100, stdin);
    b.author[strcspn(b.author, "\n")] = '\0';
    printf("Enter Quantity: ");
    scanf("%d", &b.quantity);

    fwrite(&b, sizeof(Book), 1, fp);
    fclose(fp);
    printf("Book added successfully!\n");
}

void displayBooks() {
    FILE *fp = fopen(FILE_NAME, "rb");
    Book b;
    printf("\n%-5s %-30s %-30s %-10s\n", "ID", "Title", "Author", "Qty");
    printf("--------------------------------------------------------------------------\n");
    while (fread(&b, sizeof(Book), 1, fp)) {
        printf("%-5d %-30s %-30s %-10d\n", b.id, b.title, b.author, b.quantity);
    }
    fclose(fp);
}

void searchBook() {
    int id, found = 0;
    Book b;
    printf("Enter Book ID to search: ");
    scanf("%d", &id);

    FILE *fp = fopen(FILE_NAME, "rb");
    while (fread(&b, sizeof(Book), 1, fp)) {
        if (b.id == id) {
            printf("Book found!\n");
            printf("ID: %d\nTitle: %s\nAuthor: %s\nQuantity: %d\n", b.id, b.title, b.author, b.quantity);
            found = 1;
            break;
        }
    }
    fclose(fp);
    if (!found) printf("Book not found!\n");
}

void deleteBook() {
    int id, found = 0;
    Book b;
    FILE *fp = fopen(FILE_NAME, "rb");
    FILE *temp = fopen("temp.dat", "wb");

    printf("Enter Book ID to delete: ");
    scanf("%d", &id);

    while (fread(&b, sizeof(Book), 1, fp)) {
        if (b.id != id) {
            fwrite(&b, sizeof(Book), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove(FILE_NAME);
    rename("temp.dat", FILE_NAME);

    if (found) printf("Book deleted successfully.\n");
    else printf("Book not found.\n");
}

void updateBook() {
    int id, found = 0;
    Book b;
    FILE *fp = fopen(FILE_NAME, "rb+");

    printf("Enter Book ID to update: ");
    scanf("%d", &id);

    while (fread(&b, sizeof(Book), 1, fp)) {
        if (b.id == id) {
            printf("Enter new Title: ");
            getchar(); // consume newline
            fgets(b.title, 100, stdin);
            b.title[strcspn(b.title, "\n")] = '\0';

            printf("Enter new Author: ");
            fgets(b.author, 100, stdin);
            b.author[strcspn(b.author, "\n")] = '\0';

            printf("Enter new Quantity: ");
            scanf("%d", &b.quantity);

            fseek(fp, -sizeof(Book), SEEK_CUR);
            fwrite(&b, sizeof(Book), 1, fp);
            printf("Book updated successfully.\n");
            found = 1;
            break;
        }
    }
    fclose(fp);
    if (!found) printf("Book not found.\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n===== Library Management System =====\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book by ID\n");
        printf("4. Delete Book\n");
        printf("5. Update Book\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: deleteBook(); break;
            case 5: updateBook(); break;
            case 6: exit(0);
            default: printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
