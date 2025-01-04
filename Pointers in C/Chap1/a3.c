main()
{
    int c=10, d=20;
    
    printf("\nWe are in main()....");
    printf("\nAddress of c=%u Address of d=%u",&c,&d);
    printf("\nBefore swap(), c=%d d=%d",c,d);
    swap(c,d);
    printf("\nBack to main()....");
    printf("\nAfter swap(), c=%d d=%d",c,d);
}

swap(int c, int d)
{
    printf("\nWe are in swap()....");
    printf("\nAddress of c=%u Address of d=%u",&c,&d);
    printf("\nBefore change(), c=%d d=%d",c,d);
    change(c,d);
    printf("\nBack to swap()....");
    printf("\nAfter change(), c=%d d=%d",c,d);
}

change(int c, int d)
{
    int t;

    printf("\nWe are in change()....");
    printf("\nAddress of c=%u Address of d=%u",&c,&d);
    printf("\nBefore interchanging(), c=%d d=%d",c,d);
    t=c;
    c=d;
    d=t;
    printf("\nAfter interchanging(), c=%d d=%d",c,d);
}

