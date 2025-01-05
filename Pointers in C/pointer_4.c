main()
{
	int c=10,d=20;
	printf("\nwe are in main()...");
	printf("\naddress pf c=%u address of d=%u",&c,&d);
	printf("\nBefore swap(), c=%d d=%d",c,d);
	swap(c,d);
	printf("\n Back to main()...");
	printf("\n After swap(), c=%d d=%d ", c,d);
}
swap(int c, int d)
{
	int c=10,d=20;
	        printf("\nwe are in swap()...");
		        printf("\naddress pf c=%u address of d=%u",&c,&d);
			        printf("\nBefore change(), c=%d d=%d",c,d);
				        change(c,d);
					        printf("\n Back to swap()...");
						        printf("\n After change (), c=%d d=%d ", c,d);
}
change(int c, int d)
{
	int t;
	printf("\n we are in change()...");
				        printf("\naddress pf c=%u address of d=%u",&c,&d);
					        printf("\nBefore interchanging(), c=%d d=%d",c,d);
						        t=c;
							c=d;
							d=t;
							
								        printf("\n After interchanging, c=%d d=%d ", c,d);
}
