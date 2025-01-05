char* user_strchr(char*p,char ch);
main()
{
	char*p;
	char s[10],ch;
	printf("string start add:%\n",s);
	printf("enter string...\n");
	scanf("%s",s);
	printf("enter char..\n");
	scanf("%c",ch);
}
char *user_strchr(char*p,char ch)
{
	int i ;
	for (i=0;p[i];i++)
		for(i=i-1;i>=0;i--)
		{
			if (p[i]==ch)
				return p+i;
		}
	return 0;
}
