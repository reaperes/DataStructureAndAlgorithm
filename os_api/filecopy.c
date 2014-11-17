#include <unistd.h>
#include <stdio.h>

#define NAME_LENGTH 25

int main(void)
{
	char in_file[NAME_LENGTH], out_file[NAME_LENGTH];
	FILE *in, *out;	
	int c;

	printf("Enter source file name: ");
	scanf("%s", in_file);
	printf("Enter destination file name: ");
	scanf("%s", out_file);

	if ( (in = fopen(in_file,"r")) == NULL) {
		fprintf(stderr, "Cannot open %s for reading\n", in_file);
		return -1;
	}
	if ( (out = fopen(out_file,"w")) == NULL) {
		fprintf(stderr, "Cannot open %s for writing\n", out_file);
		return -1;
	}

	while ( (c = getc(in)) != EOF)
		putc(c, out);

	fclose(in);
	fclose(out);
}
