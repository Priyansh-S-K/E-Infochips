main()
{
	static char str1[]="good";
	static char str2[20];
	static char str3[20]="day";
	int l;
	l=strcmp(strcat(str3,strcpy(str2,str1)),strcat(str3,"good"));
	printf("%d",l);
}

