#include <ctype.h>
#include <string.h>
#include <stdio.h>

char *equiv[26] = {"@",
                   "8",
                   "(",
                   "|)",
                   "3",
                   "#",
                   "6",
                   "[-]",
                   "|",
                   "_|",
                   "|<",
                   "1",
                   "[]\\/[]",
                   "[]\\[]",
                   "0",
                   "|D",
                   "(,)",
                   "|Z",
                   "$",
                   "\'][\'",
                   "|_|",
                   "\\/",
                   "\\/\\/",
                   "}{",
                   "`/",
                   "2"};

int main(int argc, char *argv) {
	char c = EOF;
	char out[8];
	c = getchar();
	while(c != EOF) {
		c = tolower(c);
		if(c > 0x60 && c < 0x7B) {
			strcpy(&out, equiv[c - 0x61]);
		} else {
			out[0] = c;
			out[1] = '\0';
		}
		printf("%s", &out);
		c = getchar();
	}
}
