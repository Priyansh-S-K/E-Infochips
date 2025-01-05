//call by refrence 
main()
{
	int i;
	int marks[]={55,65,75,78,56,78,90};
	for(i=0;i<=6;i++)
		disp(&marks[i]);
}
disp(int *n)
{
	printf("\n%d",*n);
}
