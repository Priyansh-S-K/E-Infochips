//access array element and address using pointers 
main()
{
	int num[]={12,12,23,34,45,56};
	int i=0,*j;
	j=&num[0];

	while(i<=5)
	{
		printf("\nelement=%d",*j);
		printf("address=%u",&num[i]);
		i++;
		j++;
	}
}
