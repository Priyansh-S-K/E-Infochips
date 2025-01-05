//passing entire array to function 
main()
{
	int num[]={24,34,23,34,34,34};
	display(&num[0],6);
}
display(int *j,int n)
{int i=1;
	while(i<=n)
	{
		printf("\nelement =%d",*j);
		i++;
		j++;
	}
}

