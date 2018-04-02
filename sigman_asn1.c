#include <unistd.h>
#include <stdio.h>
#include <stdlib.h> 
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <getopt.h>

void usage(){
	fprintf(stderr, "Usage: cstest EXPRESSION\n"); 
	exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
	int Nflag, ch, valid, success, m, n, optind; 
	struct stat sb1, sb2;
	char optarg[50];
	
	Nflag = 0;
	valid = 1;
	m = 0;
	n = 0;

	while (1) {
		while ((ch = getopt(argc, argv, "+Nf:d:e:r:w:x::n:z:")) != -1) { 
			struct stat sb;
			success = stat(optarg, &sb);
			switch (ch) {
        		case 'N':
	          		Nflag = 1;
	          		break;
			case 'f':
				if(S_ISREG(sb.st_mode)){
					} else {
						valid = 0;
					}
				break;
			case 'd':
				if(S_ISDIR(sb.st_mode)){		
				} else {				
					valid = 0;
				}
				break;
        		case 'e':
				if(success == 0){		
				} else {			
					valid = 0;
				}
				break;
			case 'r':
				if((sb.st_mode & S_IRUSR)){		
				} else {		
					valid = 0;
				}
				break;
			case 'w':
				if((sb.st_mode & S_IWUSR)){		
				} else {		
					valid = 0;
				}
				break;
			case 'x':
				if((sb.st_mode & S_IXUSR)){
					
				} else {
						
					valid = 0;
				}
				break;
			case 'n':
				m += stat(argv[optind-1], &sb1);
				n += stat(argv[optind-3], &sb2);
				printf("first file: %ld\nsecond file: %ld\n", sb1.st_mtime, sb2.st_mtime);
				if((sb1.st_mtime) > (sb2.st_mtime)){
					
				} else {
						
					valid = 0;
				}
				break;

			case 'z':
				if(optarg == 0 || optarg == '\0'){
					valid = 0;
				} else {
						
				}
			}
		}	
		if (optind >= argc)
			break;
		++optind;
	}

	if(Nflag == 1){
		if(valid){
			valid = 0;
		} else {
			valid = 1;
		}
	}

	if(valid == 1){
		return 0;
	} else {
		return 1;
	}


	return 0;

}

