#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define Max 1024
#include <string.h>
void remove_back_slash(char *address);


int main(){
	system("rm without_back_slash.txt with_back_slash.txt");

printf("\ncmd[figlet]>> ");
char command[Max]={0};
fgets(command,Max,stdin);
strcat(command," >> without_back_slash.txt");
remove_back_slash(command);
system(command);
FILE *fp_0;
FILE *fp_1;
char c='\\';
fp_0=fopen("without_back_slash.txt","r");	
fp_1=fopen("with_back_slash.txt","a");
char data=fgetc(fp_0);
//fprintf(fp_1,"printf(");
while(1){
	printf("%c",data);
	if(data=='\n'){
		fputc(c,fp_1);
		fputc('n',fp_1);
		fputc('"',fp_1);
		fputc(')',fp_1);
		fputc(';',fp_1);
	//	fprintf(fp_1,"\");
   //fprintf(fp_1,"printf(");
		}

	fputc(data,fp_1);
	if(data==c){
		fputc(c,fp_1);
		}
	data=fgetc(fp_0);
	
	if(feof(fp_0)){break;}
	
     

}
fclose(fp_0);
fclose(fp_1);

char cat;
printf("\n\n[*] Out put has redirect @twith_back_slash.txt\n");
printf("Do You Want To Open File [y/n]:");
scanf("%c",&cat);
//printf("%c",cat);
if(cat=='y'){
	int pid=fork();
	if (pid==0){
	char *exec[]={"cat","with_back_slash.txt",NULL};
	execvp(exec[0],exec);
	}
	else{
		wait(NULL);
	}
	}	

else{
	exit(EXIT_SUCCESS);	
}								


}


void remove_back_slash(char *address){
int i=1;
char c=*(address+0);
while(1){
	//printf("%c",c);
	c=*(address+i);
	if(c=='\n'){
		*(address+i)=' ';
	}
	if(c=='\0'){break;}

	i++;
	
		}	
	
}