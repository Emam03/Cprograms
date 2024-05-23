#include <stdio.h>
#include <string.h>

void addBook();
void issueBook();
void searchBook();
void update();
void displayBooks();
void deleteBook();

struct library
{
    int serialNumber;
    char isbn[20];
    char name[30];
    int edition;
    char authorName[30];
    char isReserved[10];
};

int main()
{
    printf("  ------------------------------\n");
    printf("| 📚Welcome to Library Manager📚 |\n");
    printf("  ------------------------------\n");

    int choice;
    int again = 0;

    do
    {
        if (again ==1)
        {
            printf(" ----------------\n");
            printf("|🤩 Hello Again🤩|\n");
            printf(" ----------------\n");
        }
        
        printf("🤔Which operation you want to perform?\n");

        printf("🔹Enter '1' to Add book\n🔹Enter '2' to issue Book\n🔹Enter '3' to search for book\n🔹Enter '4' to Update Book Name\n🔹Enter '5' to display all books in records\n🔹Enter '6' to Delete Book\nSeletion:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addBook();
            break;
        case 2:
            issueBook();
            break;
        case 3:
            searchBook();
            break;
        case 4:
            update();
            break;
        case 5:
            displayBooks();
            break;
        case 6:
            deleteBook();
            break;
        default:
            printf("💣Invalid Choice...💣\n");
            break;
        }

        printf("Do you want to use again? Enter '1' for Yes & '0' for No:");
        scanf("%d", &again);
    } while (again == 1);

    printf("\n  ----------------------------\n");
    printf("| 🤗🤗🤗Thanks for using🤗🤗🤗|\n");
    printf("  ----------------------------\n");
    return 0;
}
// ---------------addBook()
void addBook()
{
    printf("🛑🛑🛑In Add Books Menu🛑🛑🛑\n");
    struct library book[5];
    getchar();
    for (int i = 0; i < 5; i++)
    {
        printf("Enter Serial Number for Book %d (integer):", i + 1);
        scanf("%d", &book[i].serialNumber);

        getchar();
        printf("Enter isbn for book %d :", i + 1);
        scanf("%s", book[i].isbn);

        fflush(stdin);

        printf("Enter Name for book %d :", i + 1);
        scanf("%s", book[i].name);
        fflush(stdin);

        printf("Enter Edition for book %d (Integer):", i + 1);
        scanf("%d", &book[i].edition);

        getchar();
        printf("Enter Author name for book %d :", i + 1);
        scanf("%s", book[i].authorName);
        getchar();

        printf("Is the book reserved or not? Enter 'yes' or 'no':");
        scanf("%s", book[i].isReserved);

        fflush(stdin);
    }

    // saving records in file
    FILE *fp;
    fp = fopen("Record.txt", "w");

    for (int i = 0; i < 5; i++)
    {
        fprintf(fp, "%d\t%s\t%s\t%d\t%s\t%s\n", book[i].serialNumber, book[i].isbn, book[i].name, book[i].edition, book[i].authorName, book[i].isReserved);
    }
    fclose(fp);
    printf("✅✅✅Books Added successfully✅✅✅\n");
}


// -----------deleteBook()
void deleteBook()
{
    printf("🛑🛑🛑In Delete Book Menu🛑🛑🛑\n");

    struct library book[5];
// reading records from file
    FILE *fp;
    fp = fopen("Record.txt", "r");
    int i = 0;

    if (fp == NULL)
    {
        printf("👾👾👾Error occured in opening file👾👾👾\n");
    }
    else
    {
        while (fscanf(fp, "%d %s %s %d %s %s ", &book[i].serialNumber, book[i].isbn, book[i].name, &book[i].edition, book[i].authorName, book[i].isReserved) != EOF)
        {
            i++;
        }
    }
    fclose(fp);

    printf("Record has following Books:\n");
    for (int j = 0; j < i; j++)
    {
        printf("🔹%d:%s\n", j + 1, book[j].name);
    }

    char delBook[20];
    printf("Enter the name of book you want to delete:");
    scanf("%s", delBook);

    fp = fopen("Record.txt", "w");

    int a; // to confirm that either user entered book from record

    for (int j = 0; j < i; j++)
    {
        if (strcmp(book[j].name, delBook) == 0)
        {
            a = j;
            continue;
        }
        fprintf(fp, "%d\t%s\t%s\t%d\t%s\t%s\n", book[j].serialNumber, book[j].isbn, book[j].name, book[j].edition, book[j].authorName, book[j].isReserved);
    }
    if (strcmp(book[a].name, delBook) == 0)
    {
        printf("✅✅✅Book Deleted Successfully✅✅✅\n");
    }
    else
        printf("👾👾👾Invalid Book Name Entered👾👾👾\n");
    fclose(fp);
}

// ------------searchBook()
void searchBook()
{
    printf("🔍🔍🔍In SEARCH BOOK menu🔍🔍🔍\n");
    struct library book[5];

    FILE *fp;
    fp = fopen("Record.txt", "r");
    int flag = 0; // 0 not found ,1 found
    int i = 0;
    while (fscanf(fp, "%d %s %s %d %s %s ", &book[i].serialNumber, book[i].isbn, book[i].name, &book[i].edition, book[i].authorName, book[i].isReserved) != EOF)
    {
        i++;
    }
    fclose(fp);

    char search[30];
    printf("Enter the book name:");
    scanf("%s", search);

    for (int j = 0; j < i; j++)
    {
        if (strcmp(book[j].name, search) == 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        printf("✅✅✅Book found Successfully✅✅✅\n");
    }
    else
        printf("❌❌❌Book not found❌❌❌\n");
}

// -------------------UpdateBook()
void update()
{
    printf("🛑🛑🛑In Update Book Name menu🛑🛑🛑\n");

    struct library book[5];
    // reading records
    FILE *fp;
    fp = fopen("Record.txt", "r");

    int i = 0;
    
    if (fp == NULL)
    {
        printf("👾👾👾Error occured in opening file👾👾👾\n");
    }
    else
    {
        while (fscanf(fp, "%d %s %s %d %s %s ", &book[i].serialNumber, book[i].isbn, book[i].name, &book[i].edition, book[i].authorName, book[i].isReserved) != EOF)
        {
            i++;
        }
    }
    fclose(fp);

    printf("The record has following Books:\n");
    for (int j = 0; j < i; j++)
    {
        printf("🔹%d : %s\n", j + 1, book[j].name);
    }

    char oldBook[20];
    printf("Write name of book you want to update:");
    scanf("%s", oldBook);

    char newBook[20];
    printf("Enter new name for book:");
    scanf("%s", newBook);

    for (int j = 0; j < i; j++)
    {
        if (strcmp(book[j].name, oldBook) == 0)
        {
            strcpy(book[j].name, newBook);
            printf("✅✅✅Name updated successfully✅✅✅\n");
            break;
        }
    }

    // saving records in file
    fp = fopen("Record.txt", "w");

    for (int j = 0; j < i; j++)
    {
        fprintf(fp, "%d\t%s\t%s\t%d\t%s\t%s\n", book[j].serialNumber, book[j].isbn, book[j].name, book[j].edition, book[j].authorName, book[j].isReserved);
    }
    fclose(fp);
}

// -----------------display books
void displayBooks()
{
    printf("🛑🛑🛑In dispaly Books Menu🛑🛑🛑\n");

    struct library book[5];
    // reading records
    int i = 0;

    FILE *fp;
    fp = fopen("Record.txt", "r");
    if (fp == NULL)
    {
        printf("👾👾👾Error occured in opening file👾👾👾\n");
    }
    else
    {
        while (fscanf(fp, "%d %s %s %d %s %s ", &book[i].serialNumber, book[i].isbn, book[i].name, &book[i].edition, book[i].authorName, book[i].isReserved) != EOF)
        {
            i++;
        }
    }

    for (int j = 0; j < i; j++)
    {
        printf("Record no %d\n", j + 1);

        printf("\t🔹Serial no:%d\n", book[j].serialNumber);
        printf("\t🔹ISBN:%s\n", book[j].isbn);
        printf("\t🔹Book Name:%s\n", book[j].name);
        printf("\t🔹Book Edition:%d\n", book[j].edition);
        printf("\t🔹Author:%s\n", book[j].authorName);
        printf("\t🔹Reservation Status:%s\n", book[j].isReserved);
    }
}


// -------------issueBook()
void issueBook()
{

    printf("🛑🛑🛑In Issue Book Menu🛑🛑🛑\n");
    struct library book[5];

    // reading records
    int i = 0;
    FILE *fp;
    
    fp = fopen("Record.txt", "r");
    if (fp == NULL)
    {
        printf("👾👾👾Error occured in opening file👾👾👾\n");
    }
    else
    {
        while (fscanf(fp, "%d %s %s %d %s %s ", &book[i].serialNumber, book[i].isbn, book[i].name, &book[i].edition, book[i].authorName, book[i].isReserved) != EOF)
        {
            i++;
        }
    }

    printf("-----------------------------\n");
    printf("Book Name\tIssue Status\n");
    printf("-----------------------------\n");
    for (int j = 0; j < i; j++)
    {
        printf("%d: %s\t\t%s\n", j + 1, book[j].name, book[j].isReserved);
    }

    char bookissue[20];
    printf("Enter the name of book you want to issue:");
    scanf("%s", bookissue);

int j;
    for (j = 0; j < i; j++)
    {
        if (strcmp(book[j].name, bookissue) == 0)
        {
            if (strcmp(book[j].isReserved,"yes") == 0)
            {
                printf("%s Already Issued...\n", book[j].name);

                int choice;
                printf("Do you to clear issuance of %s (Enter in '1' to do so, Enter '0' to not change its issuance):", book[j].name);
                scanf("%d", &choice);
                if (choice == 1)
                {
                    strcpy(book[j].isReserved, "no");
                    printf("✅Book Issuence is cleared✅\n");
                }
            }
            else
            {
                strcpy(book[j].isReserved, "yes");
                printf("✅✅✅Book issued successfully✅✅✅\n");
            }
            break;
        }
    }
    if (j>=i)
    {
        printf("👾👾👾Invalid Book Name Entered👾👾👾\n");
    }
    

    // saving records in file
    fp = fopen("Record.txt", "w");

    for (int j = 0; j < i; j++)
    {   
        fprintf(fp, "%d\t%s\t%s\t%d\t%s\t%s\n", book[j].serialNumber, book[j].isbn, book[j].name, book[j].edition, book[j].authorName, book[j].isReserved);
    }
    fclose(fp);
}

