main()
{
	int i=3;
	float f=3.50,*prod;
	 prod=multiply(i,f);
	 printf("\n prod=%u value at address =%f",prod,*prod);
}
multiply(int ii,float ff )
{
	float product;
	product=ii*ff;
	printf("\nproduct=%f address of product=%u",product,&product);
	return(&product);
}
