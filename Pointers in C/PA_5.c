//print address of each array element 
main()
{
	int num[]={24,34,12,4,5,5};
	int i=0;
	while(i<=5)
	{
		printf("\nelement no.%d",i);
		printf("address=%u",&num[i]);
		i++;
	}
}

