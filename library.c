#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int n, no, ch, foundb = 0, founds = 0, id, choice, rl, search, sr, disp;
char pass[10];
FILE *fp, *fp1, *fp2;

struct stud
{
    int idno;
    char name[30];
    char dept[30];
    int sem;
    char address[50];
    int alreadyissued; // max 4 books issued

} s, s1, f; // new

struct book // hello
{
    int bno;
    char name[30];
    char author[30];
    int quant;
    int cost;
    char status[20];

} b, b1, b2, b3, f1, u,b4;

struct dateentry
{
    char issuedate[20];
    char returndate[20];
};

void stuPortal();
void adminPortal();
void addstudent();
void deletestud();
void addbook();
void displaybook();

void main()
{

    do
    {
        printf("__Welcome to Library_");
        printf("\n1.Student Portal");
        printf("\n2.Admin Portal");
        printf("\n3.Exit");
        printf("\nEnter your Choice : ");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            stuPortal();
            break;

        case 2:
            adminPortal();
            break;

        case 3:
            exit(0);
            break;

        default:
            printf("Wrong Choice!!!");
        }
        printf("\nDo you want to Continue (Press 1)");
        scanf("%d", &ch);
    } while (ch == 1);
}

void stuPortal()
{

    printf("\n--Student Services--");
    printf("\n1.Isuue a Book");
    printf("\n2.Return a Book");
    printf("\n3.Search for Book");
    printf("\n4.Exit");
    printf("\nEnter your Choice : ");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        printf("---------------------");
        printf("\n--Issue a Book--");
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);

        fp = fopen("issueddata.dat", "ab+"); // file open
        if (fp == NULL)
            printf(">>>>error in opening file");

        printf("\n#Enter Book number :"); // Data entry
        scanf("%s", &no);
        while (fread(&b1, sizeof(struct book), 1, fp)) // if quantity of book is 0
        {
            if (no == b1.bno)
            {
                foundb = 1;
                if (b1.quant == 0)
                {
                    printf("#No Books available");
                }
                else
                {
                    b1.quant = b1.quant - 1;
                }
                break;
            }
        }

        if (foundb == 0)
        {
            printf("--book not found to issue--");
        }
        else
        {
            printf("\n#Enter Student idno :");
            scanf("%s", id);
            while (fread(&s1, sizeof(struct stud), 1, fp)) // check student exist
            {
                if (id == s1.idno)
                {
                    founds = 1;
                here:
                    printf("\n1.Issue date today  ");
                    printf("\n2.Issue date mannually enter");
                    printf("\n enter you preference");
                    scanf("%d", &choice);
                    switch (choice)
                    {
                    case 1:
                        printf("Date and time of book issued : %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
                        fwrite(&tm, sizeof(struct stud), 1, fp1);
                        break;
                    case 2:

                        break;
                    default:
                        printf("incorrect choice");
                        goto here;
                    }
                    fwrite(&t, sizeof(struct stud), 1, fp2);
                    break;
                }
            }
            if (founds == 0)
            {
                printf("Invalid student  id no");
            }

            printf("\n#Enter Semester :");
            scanf("%d", &s.sem);
            printf("\n#Enter Address :");
            scanf("%s", s.address);

            fwrite(&s, sizeof(struct stud), 1, fp);
            if (fwrite != 0)
                printf(">>>>Data Inserted Succesfully\n");
            else
                printf(">>>>error in writing\n");

            fclose(fp); // closing
        }
        break;
    case 2:
        printf("---------------------");
        printf("\n--Return a Book--");

        break;
    case 3:
        printf("---------------------");
        printf("\n--Search for a Book--");
        printf("Enter the idno to search for a book");
        scanf("%d", &search);
        foundb = 0;
        while (fread(&b2, sizeof(struct book), 1, fp)) // if quantity of book is 0
        {
            if (search == b2.bno)
            {
                foundb = 1;
                if (b2.quant == 0)
                {
                    printf("#No Books available");
                }
                break;
            }
        }

        if (foundb == 0)
        {
            printf("--book not found to issue--");
        }
        break;

    case 4:
        printf("---------------------");
        printf("\n--exiting --");
        exit(0);
        break;

    default:
        printf("\nWrong Choice!!!");
    }
}

void adminPortal()
{
    printf("Enter Password to enter as Admin(root):");
    scanf("%s", pass);
    if (strcmp(pass, "Tata@123") == 0)
    {
        printf("\n--Administrator View--");
        printf("\n1.Add Book");
        printf("\n2.Delete Book");
        printf("\n3.Display book");
        printf("\n4.Add Student");
        printf("\n5.Delete Student");
        printf("\n6.Exit");
        printf("\nEnter your Choice");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            addbook();
            break;
        case 2:
            printf("---------------------");
            printf("\n--Delete a Book--");
            printf("enter the book no to delete a book");
            scanf("%d", &b3.bno);

            break;
        case 3:
            displaybook();
            break;

        case 4:
            addstudent();
            break;

        case 5:
            deletestud();
            break;

        case 6:
            printf("---------------------");
            printf("\n--exiting --");
            exit(0);
            break;

        default:
            printf("Wrong Choice!!!");
        }
    }
    else
    {
        printf("wrong password ");
    }
}

void addstudent()
{
    printf("---------------------");
    printf("\n--Add Student in system--");
    fp = fopen("student_record.dat", "ab+"); // file open
    if (fp == NULL)
        printf(">>>>error in opening file");

    printf("\n#Enter Student name :"); // Data entry
    scanf("%s", s.name);
    fflush(stdin);

here:
    printf("\n#Enter id.no :");
    scanf("%d", &s.idno);
    while (fread(&s1, sizeof(struct stud), 1, fp)) // if roll duplicate
    {
        if (s.idno == s1.idno)
        {
            printf("#Duplicate Id Number");
            goto here;
            break;
        }
    }
    printf("\n#Enter Department :");
    scanf("%s", s.dept);
    printf("\n#Enter Semester :");
    scanf("%d", &s.sem);
    printf("\n#Enter Address :");
    scanf("%s", s.address);
    s.alreadyissued = 0;
    fwrite(&s, sizeof(struct stud), 1, fp);
    if (fwrite != 0)
        printf(">>>>Data Inserted Succesfully\n");
    else
        printf(">>>>error in writing\n");

    fclose(fp); // closing
}

void deletestud()
{
    printf("---------------------");
    printf("\n--Delete Student in system--");
    founds == 0;
    fp = fopen("student_record.dat", "ab+");
    if (fp == NULL)
        printf(">>>>error in opening file");

    // DELETE RECORD
    printf("--Total id no in List :");
    while (fread(&f, sizeof(struct stud), 1, fp)) // Total available id nos
    {
        printf("%d ,", f.idno);
    }
    rewind(fp);
    printf("\n>>>>Enter the id no to delete the record : "); // enter id no to delete
    scanf("%d", &rl);
    fp1 = fopen("temp1.dat", "wb");

    while (fread(&s, sizeof(struct stud), 1, fp))
    {
        if (rl == s.idno) // matching entry
        {
            founds = 1;
            printf("--record deleted--");
        }
        else
        {
            fwrite(&s, sizeof(struct stud), 1, fp1); // transfer All records to temporary file instead delted one
        }
    }
    if (founds == 0)
    {
        printf("--record not found to delete--");
    }
    remove("student_record.dat");              // removing old file
    rename("temp1.dat", "student_record.dat"); // rename temprary file to student file
    fclose(fp1);
    fclose(fp);
}
void addbook()
{
    printf("---------------------");
    printf("\n--Add a Book--");
    fp = fopen("book.dat", "ab+");
    her :
    printf("\nenter the book no :");
    scanf("%d", &b3.bno);
    rewind(fp);
    while (fread(&b4, sizeof(struct stud), 1, fp)) // if roll duplicate
    {
        if (b3.bno == b4.bno)
        {
            printf("#Duplicate book Number");
            goto her;
            break;
        }
    }
    printf("\nenter book name :");
    scanf("%s", b3.name);
    printf("\nenter the author name :");
    scanf("%s", b3.author);
    printf("enter the cost of book");
    scanf("%d", &b3.cost);
    printf("\nenter the quantity");
    scanf("%d", &b3.quant);
    strcpy(b3.status, "not issued");

    fwrite(&b3, sizeof(struct book), 1, fp);
    if (fwrite != 0)
        printf(">>>>Book Inserted Succesfully\n");
    else
        printf(">>>>error in inserting book\n");

    fclose(fp);

}

void displaybook()
{
    fp = fopen("book.dat", "rb+");
    if (fp == NULL)
        printf("error in opening file"); // DISPLAY RECORD

    disp = 0;
    printf("--Total book no in List :");
    while (fread(&f1, sizeof(struct book), 1, fp))
    {
        printf("%d ,", f1.bno);
    }
    rewind(fp);
    printf("\n>>>>Enter the book.no to Display the book details : ");
    scanf("%d", &sr);

    while (fread(&u, sizeof(struct stud), 1, fp))
    {
        if (u.bno == sr)
        {
            disp = 1;
            break;
        }
    }
    if (disp == 1)
    {
        printf("\n  --Book Details--    ");
        printf("\n# Book name    : %s", u.name);
        printf("\n# Book no      : %d", u.bno);
        printf("\n# Author       : %s", u.author);
        printf("\n# quantiy      : %d", u.quant);
        printf("\n# price        : %d", u.cost);
        printf("\n# status       : %s", u.status);
    }
    else
    {
        printf(">>>>No matching BOOK no\n");
    }
    fclose(fp);
}