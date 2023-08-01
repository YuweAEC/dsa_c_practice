
void create()
{
    int x;
    char a;
    node *t, *h;
    do
    {
        printf("Enter the value: ");
        scanf("%d", &x);
        t=(node*)malloc(sizeof(node));
        t->n=x;
        t->next=NULL;
        if (head==NULL)
        {
            head=t;
            h=t;
        }
        else
        {
            h->next=t;
            h=t;
        }
        printf("Do you want to continue? (y/n): ");
        a=getchar();
    } while (a=='y' || a=='Y');
    
}
