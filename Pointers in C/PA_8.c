//accessing array elements in different ways 
main()
{
	int num[]={21,23,34,4,5,45};
	int i=0;
	 
	while (i<=5)
	{
            printf("\n address =%u",&num[i]);
	    printf("element =%d",num[i]);
	    printf("%d",*(num+i));
	    printf("%d",*(i+num));
	    printf("%d",i[num]);
	    i++;
	}
}
