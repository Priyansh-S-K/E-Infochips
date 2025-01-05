main()
{
	int a=5,*aa;
	aa=&a;
	a=power(&aa);
	printf("\na=%d aa=%u",a,aa);
}
power(int **ptr)
{
	int b;
	b=**ptr***ptr;
	return(b);
}
