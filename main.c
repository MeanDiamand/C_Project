//Mean Diamand
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

//All structure
typedef struct name
{
    char f_name[100];
    char s_name[100];
}name;

typedef struct date
{
    int year;
    int month;
    int day;
}date;

//Linked List
typedef struct list
{
    name n;
    name w;
    char category[100];
    char type[100];
    date d;
    struct list *nxt;
}list;

//All Function Prototypes
void read_the_file(char*);  //for reading the text file that wanted to be display
int introduction();    //introduction of the program which include the title of the program
void databases();      //option in the databases

list *data_entry(list*, int*);  //where the program take the informations of the user and store it into the text file
list *read_database(int*);   // where to read the information inside the text file
void save_database(list*, int);   // where the information will be save into the text file
list *insert_data(list *, list*);  // where the information will be insert into the list
list *push_front (list*, list*);  // where to add the new node to the head of the list
void printPerson(list*);  // where to print the line that contains the data of the person

void data_search(list*);  //option for the data search menu
void search_category(list*);    //where the users can search for the information by category
void search_day(list*);  //where the users can search for the information by day
void last_next(list*); //where the users can display the events that happens before and after the current month
void bubbleSort(list *); // for implementing the bubble sorting algorithm
void swap(list *, list *); // for swapping the two nodes that close to each other

list *data_delete(list*, int*); //where the user can input the firstname and surname of the person that want to delete
list *delete_person(list*, char*, char*); // where to delete the given node from the list
list *pop_front(list*); // where to delete the first node of the list

void print_databases(list *); // where to traversing through the list

int main()
{
    int opt=1;
    char *file;
    while(opt!=5)
    {
        opt=introduction();
        switch(opt)
        {
            case 1:
                databases();
                break;
            case 2:
                system("cls");
                file = "Help.txt";
                read_the_file(file);
                break;
            case 3:
                system("cls");
                file = "Credit.txt";
                read_the_file(file);
                break;
            case 4:
                system("cls");
                file = "History.txt";
                read_the_file(file);
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Please input the valid option!!!\n");
        }
    }
    return 0;
}

//for reading the text file
void read_the_file(char *file)
{
    char c;
    FILE *fp=fopen(file, "r");
    if(fp==NULL)
    {
        return;
    }

    //reading character one by one until it is successful
    while(fscanf(fp, "%c", &c)==1)
    {
        printf("%c", c);
    }

    fclose(fp); //close file
    printf("\nInput 6 to go back\n\n");
    int n=1;
    while(n!=6)
    {
        scanf("%d", &n);
        if(n!=6)
        {
            printf("Please input the valid option!!!\n");
        }
    }
}

int introduction()
{

    system("cls");
    char c;
    FILE *fp=fopen("Introduction.txt", "r"); // open the text file
    if(fp==NULL)
    {
        return 1;
    }

    // reading character one by one until it is successful
    while(fscanf(fp, "%c", &c)==1)
    {
        printf("%c", c);
    }

    fclose(fp); // close file
    int choice;
    printf("\n\nPlease input your option: ");
    scanf("%d", &choice);
    return choice;
}

//option in the databases
void databases()
{
    int numOfPeople = 0;
    list* head = read_database(&numOfPeople);
    int opd = 0;
    while(opd!=5)
    {
        system("cls");
        printf("____________________________________________________________________\n");
        printf("___  __ \\__    |__  __/__    |__  __ )__    |_  ___/__  ____/_  ___/\n");
        printf("__  / / /_  /| |_  /  __  /| |_  __  |_  /| |____ \\__  __/  _____ \\ \n");
        printf("_  /_/ /_  ___ |  /   _  ___ |  /_/ /_  ___ |___/ /_  /___  ____/ / \n");
        printf("/_____/ /_/  |_/_/    /_/  |_/_____/ /_/  |_/____/ /_____/  /____/  \n");
        printf("\n  1. Entering the data into the Databases\n");
        printf("  2. Searching for the data in the Databases\n");
        printf("  3. Deleting the data in the Databases\n");
        printf("  4. Printing the Databases\n");
        printf("  5. Back\n");
        scanf("%d", &opd);
        switch(opd)
        {
            case 1:
                head=data_entry(head, &numOfPeople);
                break;
            case 2:
                data_search(head);
                break;
            case 3:
                head=data_delete(head, &numOfPeople);
                break;
            case 4:
                print_databases(head);
                break;
            default:
                printf("Please choose the available options\n");
        }
    }
    save_database(head, numOfPeople);
}

list *data_entry(list* head, int* numOfPeople)
{
    system("cls");
    list* p = (list*)malloc(sizeof(list));
    printf("Input the data into the Databases:\n");
    int td=5;
    while(td>4 || td<1)
    {
        printf("Type of day:\n");
        printf("1. Birthday\n");
        printf("2. Anniversary\n");
        printf("3. Nameday\n");
        printf("4. Marriage\n");
        scanf("%d", &td);
        switch(td)
        {
            case 1:
                strcpy(p -> type, "Birthday");
                break;
            case 2:
                strcpy(p -> type, "Anniversary");
                break;
            case 3:
                strcpy(p -> type, "Nameday");
                break;
            case 4:
                strcpy(p -> type, "Marriage");
                break;
            default:
                printf("Please choose the available options\n");
                break;
        }
    }

    int ctr=5;
    while(ctr>4 || ctr<1)
    {
        printf("Category of the users:\n");
        printf("1. Friend\n");
        printf("2. Family\n");
        printf("3. Relative\n");
        printf("4. Colleague\n");
        scanf("%d", &ctr);
        switch(ctr)
        {
            case 1:
                strcpy(p -> category, "Friend");
                break;
            case 2:
                strcpy(p -> category, "Family");
                break;
            case 3:
                strcpy(p -> category, "Relative");
                break;
            case 4:
                strcpy(p -> category, "Colleague");
                break;
            default:
                printf("Please choose the available options\n");
                break;
        }
    }

    printf("Name(Firstname Surname): ");
    scanf("%s %s", p -> n.f_name, p -> n.s_name);
    if(td==2 || td==4)
    {
        printf("Partner's Name(Firstname Surname): ");
        scanf("%s %s", p->w.f_name, p->w.s_name);
    }
    else
    {
        strcpy(p->w.f_name, "None");
        strcpy(p->w.s_name, "None");
    }

    printf("Input the Date (Ex: 2000 01 01):\n");
    printf("Date(YYYY MM DD): ");
    scanf("%d %d %d", &(p -> d.year), &(p -> d.month), &(p -> d.day));
    p -> nxt = NULL;

    head = insert_data(head, p);
    (*numOfPeople) ++;

    // hold the output
    int b = 0;
    while (b != 4) {
        printf("\n\nEnter 4 to go back\n");
        scanf("%d", &b);
    }
    free(p);
    return head;
}

list* read_database(int* numOfPeople)
{
    list* head = NULL;
    FILE* fp = fopen("History.txt", "r");
    fscanf(fp, "%d\n", numOfPeople);
    for (int i=0; i<*numOfPeople; i+=1)
    {
        list*   p = (list*) malloc (sizeof(list));
        fscanf(fp, "%s %s | %s %s | %s | %s | %d/%d/%d\n", p->n.f_name, p->n.s_name, p->w.f_name, p->w.s_name, p->category, p->type, &(p->d.year), &(p->d.month), &(p->d.day));
        head = insert_data(head, p);
        free(p);
    }
    fclose(fp);
    return head;
}

void save_database(list* head, int numOfPeople)
{
    FILE* fp = fopen("History.txt", "w");
    if (fp == NULL)
    {
        printf("cannot open file to save\n");
        return;
    }
    fprintf(fp, "%d\n", numOfPeople);

    if(head == NULL)
    {
        return;
    }
    list* p = head;
    list* q = head -> nxt;

    for (int i = 0; i < numOfPeople; i+=1)
    {
        fprintf(fp, "%s %s | %s %s | %s | %s | %d/%d/%d\n", p->n.f_name, p->n.s_name, p->w.f_name, p->w.s_name, p->category, p->type, p->d.year, p->d.month, p->d.day);

        free(p);
        p = q;

        if (q != NULL) {
            q = q -> nxt;
        }

    }
    fclose(fp);
}

list *insert_data(list *head, list* personToAdd)
{
    list *u;
    if(head == NULL)
    {
        return push_front(head, personToAdd);
    }
    for(u=head; u->nxt!=NULL; u=u->nxt);

    u->nxt = (list*)malloc(sizeof(list));

    strcpy(u -> nxt -> n.f_name, personToAdd -> n.f_name);
    strcpy(u -> nxt -> n.s_name, personToAdd -> n.s_name);
    strcpy(u -> nxt -> w.f_name, personToAdd -> w.f_name);
    strcpy(u -> nxt -> w.s_name, personToAdd -> w.s_name);
    strcpy(u -> nxt -> category, personToAdd -> category);
    strcpy(u -> nxt -> type, personToAdd -> type);
    u -> nxt -> d.year = personToAdd -> d.year;
    u -> nxt -> d.month = personToAdd -> d.month;
    u -> nxt -> d.day = personToAdd -> d.day;
    u -> nxt -> nxt = NULL;

    return head;
}

list* push_front(list* head, list* personToAdd)
{
    list* p = (list*) malloc (sizeof(list));
    strcpy(p -> n.f_name, personToAdd -> n.f_name);
    strcpy(p -> n.s_name, personToAdd -> n.s_name);
    strcpy(p -> w.f_name, personToAdd -> w.f_name);
    strcpy(p -> w.s_name, personToAdd -> w.s_name);
    strcpy(p -> category, personToAdd -> category);
    strcpy(p -> type, personToAdd -> type);
    p -> d.year = personToAdd -> d.year;
    p -> d.month = personToAdd -> d.month;
    p -> d.day = personToAdd -> d.day;

    p -> nxt = head;
    head = p;
    return head;
}

void printPerson(list* p)
{
    if (p == NULL)
    {
        printf("head is NULL\n");
        return;
    }
    if (strcmp(p->w.f_name, "None")==0)
    {
        printf("%s %s | %s | %s | %d/%d/%d\n", p->n.f_name, p->n.s_name, p->type, p->category, p->d.day, p->d.month, p->d.year);
    }
    else
    {
        printf("%s %s and %s %s | %s | %s | %d/%d/%d\n", p->n.f_name, p->n.s_name, p->w.f_name, p->w.s_name, p->type, p->category, p->d.day, p->d.month, p->d.year);
    }
}

void data_search(list* head)
{
    int ops = 0;
    while(ops!=4)
    {
        system("cls");
        printf("_____________________________________________  __\n");
        printf("__  ___/__  ____/__    |__  __ \\_  ____/__  / / /\n");
        printf("_____ \\__  __/  __  /| |_  /_/ /  /    __  /_/ / \n");
        printf("____/ /_  /___  _  ___ |  _, _// /___  _  __  /  \n");
        printf("/____/ /_____/  /_/  |_/_/ |_| \\____/  /_/ /_/   \n");
        printf("\n  1. Search by Category\n");
        printf("  2. Search by Day\n");
        printf("  3. The events that occur in the last month and those that will occur in the next month\n");
        printf("  4. Back\n");
        scanf("%d", &ops);
        switch(ops)
        {
            case 1:
                search_category(head);
                break;
            case 2:
                search_day(head);
                break;
            case 3:
                last_next(head);
                break;
            default:
                printf("Please choose the available options\n");
        }
    }
}

void search_category(list* head)
{
    system("cls");
    printf("________________________________________________________  __\n");
    printf("__  ____/__    |__  __/__  ____/_  ____/_  __ \\__  __ \\ \\/ /\n");
    printf("_  /    __  /| |_  /  __  __/  _  / __ _  / / /_  /_/ /_  / \n");
    printf("/ /___  _  ___ |  /   _  /___  / /_/ / / /_/ /_  _, _/_  /  \n");
    printf("\\____/  /_/  |_/_/    /_____/  \\____/  \\____/ /_/ |_| /_/   \n");
    printf("\nSelect the Category of the users that you want to display:\n");
    int ctr=5;

    char str[100];
    while(ctr>4 || ctr<1)
    {
        printf("Category of the users:\n");
        printf("1. Friend\n");
        printf("2. Family\n");
        printf("3. Relative\n");
        printf("4. Colleague\n");
        scanf("%d", &ctr);
        switch(ctr)
        {
            case 1:
                strcpy(str, "Friend");
                break;
            case 2:
                strcpy(str, "Family");
                break;
            case 3:
                strcpy(str, "Relative");
                break;
            case 4:
                strcpy(str, "Colleague");
                break;
            default:
                printf("Please choose the available options\n");
                break;
        }
    }
    system("cls");
    printf("Result of the searching information:\n");
    list* p = head;
    while (p != NULL) {
        if (strcmp(p->category, str) == 0) {
            printPerson(p);
        }
        p = p -> nxt;
    }

    //hold the output
    int b = 0;
    while (b != 4) {
        printf("\n\nEnter 4 to go back\n");
        scanf("%d", &b);
    }
}

void search_day(list* head)
{
    system("cls");
    printf("_________________  __\n");
    printf("___  __ \\__    | \\/ /\n");
    printf("__  / / /_  /| |_  / \n");
    printf("_  /_/ /_  ___ |  /  \n");
    printf("/_____/ /_/  |_/_/   \n");
    printf("\nSelect the Type of day that you want to display:\n");
    int td=5;
    char str[100];
    while(td>4 || td<1)
    {
        printf("Type of day:\n");
        printf("1. Birthday\n");
        printf("2. Anniversary\n");
        printf("3. Nameday\n");
        printf("4. Marriage\n");
        scanf("%d", &td);

        switch(td)
        {
            case 1:
                strcpy(str, "Birthday");
                break;
            case 2:
                strcpy(str, "Anniversary");
                break;
            case 3:
                strcpy(str, "Nameday");
                break;
            case 4:
                strcpy(str, "Marriage");
                break;
            default:
                printf("Please choose the available options\n");
                break;
        }
    }
    system("cls");
    printf("Result of the searching information:\n");
    list* p = head;
    while (p != NULL) {
        if (strcmp(p->type, str) == 0) {
            printPerson(p);
        }
        p = p -> nxt;
    }

    //hold the output
    int b = 0;
    while (b != 4) {
        printf("\n\nEnter 4 to go back\n");
        scanf("%d", &b);
    }
}

void last_next(list* head)
{
    system("cls");
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int month1=tm.tm_mon+1;
    if(month1==1)
    {
        month1=12;
    }
    else
    {
        month1-=1;
    }
    printf("The events that occurred last month:\n\n");
    list *lt= NULL;
    list* p = head;
    while(p!=NULL)
    {
        if(p->d.month==month1)
        {
            lt = insert_data(lt, p);
        }
        p=p->nxt;
    }
    bubbleSort(lt);
    list* i = lt;
    while(i!=NULL)
    {
        printPerson(i);
        i=i->nxt;
    }

    int month2=tm.tm_mon+1;
    printf("\n\nThe events that will occur next month:\n\n");
    if(month2==12)
    {
        month2=1;
    }
    else
    {
        month2+=1;
    }
    p=head;
    list *nt= NULL;
    while(p!=NULL)
    {
        if(p->d.month==month2)
        {
            nt = insert_data(nt, p);
        }
        p=p->nxt;
    }
    bubbleSort(nt);
    i = nt;
    while(i!=NULL)
    {
        printPerson(i);
        i=i->nxt;
    }

    // hold the output
    int b = 0;
    while (b != 4)
    {
        printf("\n\nEnter 4 to go back\n");
        scanf("%d", &b);
    }

    while(lt!=NULL)
    {
        list *tmp=lt;
        lt=lt->nxt;
        free(tmp);
    }
    while(nt!=NULL)
    {
        list *tmp=nt;
        nt=nt->nxt;
        free(tmp);
    }
}

// Bubble sorting Algorithm
void bubbleSort(list *start)
{
    int swapped;
    list *ptr1;
    list *lptr = NULL;

    /* Checking for empty list */
    if (start == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = start;

        while (ptr1->nxt != lptr)
        {
            if ((ptr1->d.day) > (ptr1->nxt->d.day))
            {
                swap(ptr1, ptr1->nxt);
                swapped = 1;
            }
            ptr1 = ptr1->nxt;
        }
        lptr = ptr1;
    }
    while (swapped);
}

//swapping two node next to each other
void swap(list *a, list *b)
{
    list* temp = (list*) malloc (sizeof(list));
    // temp = a
    strcpy(temp->n.f_name, a->n.f_name);
    strcpy(temp->n.s_name, a->n.s_name);
    strcpy(temp->w.f_name, a->w.f_name);
    strcpy(temp->w.s_name, a->w.s_name);
    strcpy(temp->category, a->category);
    strcpy(temp->type, a->type);
    temp->d.year = a->d.year;
    temp->d.month = a->d.month;
    temp->d.day = a->d.day;

    // a = b
    strcpy(a->n.f_name, b->n.f_name);
    strcpy(a->n.s_name, b->n.s_name);
    strcpy(a->w.f_name, b->w.f_name);
    strcpy(a->w.s_name, b->w.s_name);
    strcpy(a->category, b->category);
    strcpy(a->type, b->type);
    a->d.year = b->d.year;
    a->d.month = b->d.month;
    a->d.day = b->d.day;

    // b = temp
    strcpy(b->n.f_name, temp->n.f_name);
    strcpy(b->n.s_name, temp->n.s_name);
    strcpy(b->w.f_name, temp->w.f_name);
    strcpy(b->w.s_name, temp->w.s_name);
    strcpy(b->category, temp->category);
    strcpy(b->type, temp->type);
    b->d.year = temp->d.year;
    b->d.month = temp->d.month;
    b->d.day = temp->d.day;

    free(temp);
}

list *data_delete(list* head, int *numOfPeople)
{
    system("cls");
    printf("_________________________________________________\n");
    printf("___  __ \\__  ____/__  /___  ____/__  __/__  ____/\n");
    printf("__  / / /_  __/  __  / __  __/  __  /  __  __/   \n");
    printf("_  /_/ /_  /___  _  /___  /___  _  /   _  /___   \n");
    printf("/_____/ /_____/  /_____/_____/  /_/    /_____/   \n\n");
    list* p = head;
    while (p != NULL)
    {
        printPerson(p);
        p = p->nxt;
    }
    char f_name[20];
    char s_name[20];
    printf("\nInput the name of the person that you want to delete:\n");
    printf("Name(Firstname Surname): ");
    scanf("%s %s", f_name, s_name);
    head=delete_person(head, f_name, s_name);
    (*numOfPeople)--;
    printf("\nResult after deleting the data:\n");
    p=head;
    while(p!=NULL)
    {
        printPerson(p);
        p=p->nxt;
    }

    // hold the output
    int b = 0;
    while (b != 4)
    {
        printf("\n\nEnter 4 to go back\n");
        scanf("%d", &b);
    }
    return head;
}

list *delete_person(list *head, char* f, char* s)
{
    list *p = head;
    if(head == NULL)
    {
        return head;
    }
    if(strcmp(head->n.f_name, f)==0 && strcmp(head->n.s_name, s)==0)
    {
        return pop_front(head);
    }
    while(p->nxt != NULL && (strcmp(p->nxt->n.f_name, f)!=0 || strcmp(p->nxt->n.s_name, s)!=0))
    {
        p=p->nxt;
    }
    if(p->nxt!=NULL)
    {
        list *q=p->nxt;
        p->nxt=q->nxt;
        free(q);
    }
    return head;
}

list *pop_front(list *head)
{
    if(head!=NULL)
    {
        list *p=head;
        head=head->nxt;
        free(p);
    }
    return head;
}

void print_databases(list *head)
{
    system("cls");
    printf("____________________________________________________________________\n");
    printf("___  __ \\__    |__  __/__    |__  __ )__    |_  ___/__  ____/_  ___/\n");
    printf("__  / / /_  /| |_  /  __  /| |_  __  |_  /| |____ \\__  __/  _____ \\ \n");
    printf("_  /_/ /_  ___ |  /   _  ___ |  /_/ /_  ___ |___/ /_  /___  ____/ / \n");
    printf("/_____/ /_/  |_/_/    /_/  |_/_____/ /_/  |_/____/ /_____/  /____/  \n\n");
    list* p = head;
    while (p != NULL)
    {
        printPerson(p);
        p = p->nxt;
    }

    // hold the output
    int b = 0;
    while (b != 4)
    {
        printf("\n\nEnter 4 to go back\n");
        scanf("%d", &b);
    }
}
