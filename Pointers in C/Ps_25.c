main()
{
	char a[2][2][25]={
		{
			"jack and jill",
			"went up the hill"
		},
		{
			"jack fell down ",
			"and broke his crown"
		}
	};
	printf("\n%s%s%s%s",&a[0][0][9],&a[0][1][12],&a[1][0][10],&a[1][1][14]);
}
