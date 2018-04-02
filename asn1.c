#include <unistd.h>
#include <stdio.h>
#include <stdlib.h> 

void usage(){
	fprintf(stderr, "Usage: cstest EXPRESSION\n"); 
	exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
	int Nflag, ch; 
	Nflag = 0; 
	while (1) {
		while ((ch = getopt(argc, argv, "+Nf:")) != -1) { 
			switch (ch) {
        		case 'N':
	          		Nflag = 1;
	          		break;
				case 'f':
					printf("-f %s\n", optarg);
					break;
				case ':':
					fprintf(stderr, "option -%c requires an argument", optopt); usage();
					break;
        		case '?':
        		default:
					fprintf(stderr, "unrecognized option -%c\n", optopt);
					usage(); 
			}
		}
	if (optind >= argc)
		break;
		printf("argument %s\n", argv[optind]);
		++optind;
	}
	return 0; 
}