#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

int n, no, ch, foundb = 0, founds = 0, id, choice, rl, search, sr, disp, bno;
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

} b, b1, b2, b3, f1, u, b4, ff;

struct issueData
{
    SYSTEMTIME t;
    struct book b;
    struct stud s;
} isuData;

void stuPortal();
int adminPortal();
void addstudent();
void deletestud();
void dispstud();
void addbook();
void displaybook();
void deletebook();
void issue();
void retur();
void searc();
void end();




void main()
{
    int x;
    while (1)
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
            x = adminPortal();
            if (x == 6)
                continue;
            break;

        case 3:
            exit(0);
            break;

        default:
            printf("Wrong Choice!!!");
        }
    }
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
        issue();
        break;
    case 2:
        retur();

        break;
    case 3:
        searc();
        break;

    case 4:
        end();
        break;

    default:
        printf("\nWrong Choice!!!");
    }
}

int adminPortal()
{
    //printf("Enter Password to enter as Admin(root):");
    //scanf("%s", pass);
    //strcmp(pass, "Tata@123" == 0)
    if (1)
    {
        while (1)
        {
            printf("\n--Administrator View--");
            printf("\n1.Add Book");
            printf("\n2.Delete Book");
            printf("\n3.Display book");
            printf("\n4.Add Student");
            printf("\n5.Delete Student");
            printf("\n6.Display Student");
            printf("\n7.Go Back");
            printf("\nEnter your Choice");
            scanf("%d", &n);
            switch (n)
            {
            case 1:

                addbook();
                break;
            case 2:
                deletebook();
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
                dispstud();
                break;
            case 7:
                return 6;
                break;

            default:
                printf("Wrong Choice!!!");
            }
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
    rewind(fp);
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
    printf("\n--Total id no in List :");
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
    fclose(fp1);
    fclose(fp);
    remove("student_record.dat");              // removing old file
    rename("temp1.dat", "student_record.dat"); // rename temprary file to student file
}
void addbook()
{
    printf("---------------------");
    printf("\n--Add a Book--");
    fp = fopen("book.dat", "ab+");
her:
    printf("\nenter the book no :");
    scanf("%d", &b3.bno);
    rewind(fp);
    while (fread(&b4, sizeof(struct book), 1, fp)) // if roll duplicate
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
    printf("\b \b");
    rewind(fp);
    printf("\n>>>>Enter the book.no to Display the book details : ");
    scanf("%d", &sr);

    while (fread(&u, sizeof(struct book), 1, fp))
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

void deletebook()
{
    printf("---------------------");
    printf("\n--Delete a Book--");
    founds == 0;
    fp = fopen("book.dat", "ab+");
    if (fp == NULL)
        printf(">>>>error in opening file");

    // DELETE RECORD
    printf("\n--Total book no in List :");
    while (fread(&ff, sizeof(struct book), 1, fp)) // Total available id nos
    {
        printf("%d ,", ff.bno);
    }
    printf("\b \b");
    rewind(fp);
    printf("\n>>>>Enter the book no to delete the book details : "); // enter id no to delete
    scanf("%d", &rl);
    fp1 = fopen("temp1.dat", "wb");

    while (fread(&ff, sizeof(struct book), 1, fp))
    {
        if (rl == ff.bno) // matching entry
        {
            founds = 1;
            printf("--record deleted--");
        }
        else
        {
            fwrite(&ff, sizeof(struct book), 1, fp1); // transfer All records to temporary file instead delted one
        }
    }
    if (founds == 0)
    {
        printf("--record not found to delete--");
    }
    fclose(fp1);
    fclose(fp);
    remove("book.dat");              // removing old file
    rename("temp1.dat", "book.dat"); // rename temprary file to student file
}

void issue()
{
    printf("---------------------");
    printf("\n--Issue a Book--");
    SYSTEMTIME today;

    fp = fopen("issueddata.dat", "ab+"); // issue data file open
    fp1 = fopen("book.dat", "rb+");
    fp2 = fopen("student_record.dat", "rb+");
    if (fp == NULL)
        printf(">>>>error in opening file");
    foundb = 0;
    printf("\n#Enter Book number :"); // Data entry
    scanf("%d", &no);
    while (fread(&b1, sizeof(struct book), 1, fp1)) // if quantity of book is 0
    {
        if (no == b1.bno)
        {
            if (b1.quant > 0)
            {
                foundb = 1;
                break;
            }
        }
    }

    if (foundb == 0)
    {
        printf("--book not found to issue--\n");
        return;
    }
    else
    {
        printf("\n#Enter Student idno :");
        scanf("%d", &id);
        founds = 0;
        while (fread(&s1, sizeof(struct stud), 1, fp2)) // check student exist
        {
            if (id == s1.idno)
            {

                founds = 1;

                if (s1.alreadyissued >= 4)
                {
                    printf("\nAlready Issued Max(4) allowed Number of books!\n");
                    return;
                }
                break;
            }
        }

        if (founds == 0)
            printf("\nInvalid student  id no\n");

        if (founds == 1)
        {
        here1:
            printf("\n1.Issue date today  ");
            printf("\n2.Issue date mannually enter");
            printf("\n enter you preference");
            scanf("%d", &choice);
            switch (choice)
            {
            case 2:
                printf("Enter Date (dd/mm/yyyy): ");
                scanf("%d/%d/%d", &today.wDay, &today.wMonth, &today.wYear);

            case 1:
                if (choice == 1)
                    GetSystemTime(&today);
                printf("Date of book issued : %d-%02d-%04d\n", today.wDay, today.wMonth, today.wYear);
                break;

            default:
                printf("incorrect choice");
                goto here1;
            }
            isuData.s = s1;
            isuData.b = b1;
            isuData.t = today;

            fwrite(&isuData, sizeof(struct issueData), 1, fp);
            if (fwrite != 0)
                printf(">>>>Book issued Succesfully\n");
            else
                printf(">>>>Not issued \n");

            s1.alreadyissued++; // updating student record
            fseek(fp2, -1 * sizeof(struct stud), SEEK_CUR);
            fwrite(&s1, sizeof(struct stud), 1, fp2);

            b1.quant--; // updating book record
            fseek(fp1, -1 * sizeof(struct book), SEEK_CUR);
            fwrite(&b1, sizeof(struct book), 1, fp1);

            fclose(fp); // closing
            fclose(fp1);
            fclose(fp2);
        }
    }
}

void retur()
{
    founds = 0;
    printf("---------------------");
    printf("\n--Return a Book--");
    fp = fopen("issueddata.dat", "rb+"); // issue data file open
    fp1 = fopen("book.dat", "rb+");
    fp2 = fopen("student_record.dat", "rb+");
    FILE *fp3 = fopen("temp.dat", "ab+");
    if (fp == NULL)
        printf(">>>>error in opening file");

    printf("\n#Enter Book number :"); // Data entry
    scanf("%d", &no);
    printf("\n#Enter Student id no :"); // Data entry
    scanf("%d", &sr);

    while (fread(&isuData, sizeof(struct issueData), 1, fp))
    {
        if (no == isuData.b.bno && sr == isuData.s.idno && founds == 0) // matching entry
        {
            founds = 1;
            printf("--book retuned successfully--\n");
        }
        else
        {
            fwrite(&isuData, sizeof(struct issueData), 1, fp3); // transfer All records to temporary file instead delted one
        }
    }
    if (founds == 0)
    {
        printf("\n--Wrong Book/Student Number--\n");
        return;
    }
    fclose(fp);
    fclose(fp3);
    remove("issueddata.dat");              // removing old file
    rename("temp.dat", "issueddata.dat"); // rename temprary file to student file

    // updating student record
    while (fread(&s, sizeof(struct stud), 1, fp2))
    {
        if(s.idno == sr)
            break;
    }
    if(s.alreadyissued <= 0)
    {
        printf("\n------Student doesn't have Issued any Book!-----\n");
        return;
    }
    s.alreadyissued--;
    fseek(fp2, -1 * sizeof(struct stud), SEEK_CUR);
    fwrite(&s, sizeof(struct stud), 1, fp2);

    // updating book record
    while(fread(&b,sizeof(struct book),1,fp1))
    {
        if(b.bno == no)
        break;
    }
    b.quant++;
    fseek(fp1, -1 * sizeof(struct book), SEEK_CUR);
    fwrite(&b, sizeof(struct book), 1, fp1);

    //fclose(fp); // closing
    fclose(fp1);
    fclose(fp2);
}

void searc()
{
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
}
void dispstud()
{
    fp = fopen("student_record.dat", "rb+");
    if (fp == NULL)
        printf("error in opening file"); // DISPLAY RECORD

    disp = 0;
    printf("--Total student idno in List :");
    while (fread(&s, sizeof(struct stud), 1, fp))
    {
        printf("%d ,", s.idno);
    }
    printf("\b \b");
    rewind(fp);
    printf("\n>>>>Enter the student id.no to Display the book details : ");
    scanf("%d", &sr);

    while (fread(&s, sizeof(struct stud), 1, fp))
    {
        if (s.idno == sr)
        {
            disp = 1;
            break;
        }
    }
    if (disp == 1)
    {
        printf("\n  --Student Details--    ");
        printf("\n# Student name      : %s", s.name);
        printf("\n# Student idno      : %d", s.idno);
        printf("\n# student department: %s", s.dept);
        printf("\n# semester          : %d", s.sem);
        printf("\n# student address   : %s", s.address);
        printf("\n# no of books issued: %d", s.alreadyissued);
    }
    else
    {
        printf(">>>>No matching studentt  idno\n");
    }
    fclose(fp);
}

void end()
{
    printf("---------------------");
    printf("\n--exiting --");
    exit(0);
}