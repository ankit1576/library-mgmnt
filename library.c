#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct stud
{
    int idno;
    char name[30];
    char dept[30];
    int sem;
    char address[50];
    int alreadyissued; // max 4 books issued

} s, s1;//new


struct book
{
    int bno;
    char name[30];
    char author[30];
    struct dateentry d;
} b, b1;

struct dateentry
{
    char issuedate[20];
    char returndate[20];
    int quant;
} d;

void main()
{
    int n, no, ch, foundb = 0, founds = 0, id, choice;
    char pass[10];

    do
    {
        printf("____________Welcome to Library_____________");
        printf("\n1.Student Portal");
        printf("\n2.Admin Portal");
        printf("\n3.Exit");
        printf("\nEnter your Choice : ");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
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
                fp = fopen("books.txt", "ab+"); // file open
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
                            struct date dt;

                            // This function is used to get
                            // system's current date
                            getdate(&dt);
                            printf("Issued date\n");
                            printf("%d/%d/%d",
                                   dt.da_day,
                                   dt.da_mon,
                                   dt.da_year);
                                

                            break;
                        case 2:

                            break;
                        default:
                            printf("incorrect choice");
                            goto here;
                        }

                        scanf("%s", t.DoB);
                        struct date dt;

                        // This function is used to get
                        // system's current date
                        getdate(&dt);

                        printf("System's current date\n");
                        printf("%d/%d/%d",
                               dt.da_day,
                               dt.da_mon,
                               dt.da_year);

                        t.age = agec(t.DoB);
                        fwrite(&t, sizeof(struct stud), 1, fp2);
                        break;
                    }
                }

                printf("\n#Enter Semester :");
                scanf("%d", &s.sem);
                printf("\n#Enter Address :");
                scanf("%s", s.add);
                strcpy(s.DoB, "not avlbl");
                s.age = 0;
                fwrite(&s, sizeof(struct stud), 1, fp);
                if (fwrite != 0)
                    printf(">>>>Data Inserted Succesfully\n");
                else
                    printf(">>>>error in writing\n");

                fclose(fp); // closing

                break;
            case 2:
                printf("---------------------");
                printf("\n--Return a Book--");

                break;
            case 3:
                printf("---------------------");
                printf("\n--Search for a Book--");

                break;
            case 4:
                printf("---------------------");
                printf("\n--exiting --");
                exit(0);

            default:
                printf("\nWrong Choice!!!");
            }
            break;
        case 2:

            printf("Enter Password to enter as Admin(root):");
            scanf("%s", pass);
            if (strcmp(pass, "Tata@123") == 0)
            {
                printf("\n--Administrator View--");
                printf("\n1.Add Book");
                printf("\n2.Delete Book");
                printf("\n3.Add Student");
                printf("\n4.Delete Student");
                printf("\n5.Exit");
                printf("\nEnter your Choice");
                scanf("%d", &n);
                switch (n)
                {
                case 1:
                    printf("---------------------");
                    printf("\n--Add a Book--");

                    break;
                case 2:
                    printf("---------------------");
                    printf("\n--Delete a Book--");

                    break;
                case 3:
                    printf("---------------------");
                    printf("\n--Add Student in system--");

                    break;
                case 4:
                    printf("---------------------");
                    printf("\n--Delete Student in system--");

                    break;
                case 5:
                    printf("---------------------");
                    printf("\n--exiting --");

                    exit(0);
                    break;
                default:
                    printf("Wrong Choice!!!");
                }
            }
            break;
        case 3:
            exit(0);
        default:
            printf("Wrong Choice!!!");
        }
        printf("\nDo you want to Continue (Press 1)");
        scanf("%d", &ch);
    } while (ch == 1);
}