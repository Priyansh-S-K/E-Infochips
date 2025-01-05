main()
{
	int i =3,*x;
	float j =1.5, *y;
	char k='c',*z;
	printf("\n value of i=%d",i);
	 printf("\n value of j=%f",j);
	 printf("\n value of k =%c",k);

	 x=&i;
	 y=&j;
	 z=&k;
	 printf("\n value in x=%u",x);
	 printf("\n value in y=%u",y);
          printf("\n value in z=%u",z);

	  x++;
	  y++;
	  z++;

	  printf("\n\nnew value in x=%u",x);
	   printf("\n new value in y=%u",y);
	    printf("\n new value in z=%u",z);
}

