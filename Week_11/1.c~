#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
	FILE *fp, *fp_;
	char s[2000], buf[2000];
	fp=popen("ls -ls", "r");
	fp_=popen("grep .*", "w");
	while(fscanf(fp, "%s", s)!=EOF)		
		fprintf(fp_, "%s", s);
	pclose(fp);
	pclose(fp_);
	return 0;
}
