//two dimensional array
main()
{
	int stud[5][2]={
		{1234,56},
		{1212,33},
		{2334,44},
		{2222,44},
		{3323,44}};
	int i,j;
	for(i=0;i<=4;i++)
	{
		printf("\n");
		for(j=0;j<=1;j++)
			printf("%d",stud[i][j]);
	}
}

