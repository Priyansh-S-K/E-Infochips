main()
{
    int c=10, d=20;

    printf("\nBefore swap, c=%d d=%d",c,d);
    swap(&c,&d);
    printf("\nAfter swap, c=%d d=%d",c,d);
}

swap(int *cc, int *dd)
{
    exchange(&cc,dd);
}

exchange(int **cc, int *dd)
{
    int t;

    t=**cc;
    **cc=*dd;
    *dd=t;
}