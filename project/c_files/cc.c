#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//file switch
void fileCopy(FILE *file,FILE *f);

 int main(int argc, char *argv[]){

	
	  FILE *file;
	  file= fopen(argv[1], "r"); //Used to open a file. The opening mode and name of the file are indicated.


	  FILE *f;
          f = fopen("temp.txt", "w");  //Reads the first file entered and prints it to a temporary file
	  
	  if (file == NULL) {
	  printf("Cannot open %s\n", argv[1]);
	  exit(8);
          }
    	  fileCopy(file,f);
          remove(argv[1]); 
	  fclose(file);    //Used to close the file. If we do not close the file and the buffer is not filled, the last entered data will not be entered.
	  fclose(f);
	  
	  FILE *file2;
	  file2 = fopen(argv[1], "w"); //Reads the second entered file and prints it to the first entered file.
	  FILE *f2;
	  f2= fopen(argv[2],"r");
	  if (f2 == NULL) {
	  printf("Cannot open %s\n", argv[1]);
	  exit(8);
          }
	  fileCopy(f2,file2);
	  remove(argv[2]);  
          remove(argv[1]); 
	  fclose(file2);
	  fclose(f2);
	  
	  FILE *file3;  //Reads the temporary file and prints it to the second file.
	  file3 = fopen(argv[2], "w");
	  FILE *f3;
	  f3= fopen("temp.txt","r");
	  if (f3 == NULL) {
	  printf("Cannot open %s\n", argv[1]);
	  exit(8);
          }
	  fileCopy(f3,file3);
	  remove("temp.txt");
	  fclose(file3);
	  fclose(f3);
	  return 1;

}
 void fileCopy(FILE *file,FILE *f){
	  int ch;
	  while (1) {
     
          ch = fgetc(file); //Used to read information of one character. Used by transferring to a variable.
          
          if (ch == EOF) //end of file
          { break;}

          fprintf(f, "%c",ch); //fprintf is used to print the string content in file but not on stdout console (%c accepts the variable, not its address)
          }
}
 
