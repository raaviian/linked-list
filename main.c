//Name: Raviansyah Noorman
//Matric: AI210032
//University Tun Hussein Onn Malaysia

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main(){
    struct info{
        char name[40];
        char sur[40];
    };
    struct info rec;
    FILE *f1, *f2;
    int sel, ser, res;
    char cmp[40];
    char dummy;
    int cont=0;

    do{
        do{
            printf("\n1 - Add account\n");
            printf("2 - Search account\n");
            printf("3 - Modify account\n");
            printf("4 - Exit Application\n\n\n\n");
            printf("Select any choice --> ");
            scanf("%d", &sel);
            if(sel<1 || sel>4){
                printf("\n\nFailed: **The choice is not exist**\n");
            }
        }while(sel<1 || sel>4);

        getchar();
        switch(sel){
            case 1:
                printf("Insert new account\n");
                printf("Write FirstName: ");
                fgets(rec.name, sizeof(rec.name), stdin);
                printf("Write LastName: ");
                fgets(rec.sur, sizeof(rec.sur), stdin);
                f1=fopen("lis.txt","a+"); //<- open file for writing
                fputs(rec.name,f1);
                fputs(rec.sur,f1);
                fprintf(f1,"\n");
                fclose(f1); // close the file. this will flush the buffer.
                printf("Account Created!\n");
                break;
            case 2:
                printf("Find account\n");
                printf("Write LastName to find: ");
                fgets(cmp, sizeof(cmp), stdin);
                f1=fopen("lis.txt","r"); //<- open the file for reading
                while(!feof(f1)){
                      fgets(rec.name,sizeof(rec.name),f1); //<- read both the data. this will update the file pointer.
                      fgets(rec.sur,sizeof(rec.sur),f1);
                      fscanf(f1,"%c",&dummy); //<- this handles the additional newline
                    if(strcmp(cmp,rec.sur)==0){
                        printf("\n\nAccount Found !!!:\nFirstName:%sLastName:%s\n\n",rec.name,rec.sur);
                        break; //<- break if record is found
                    }
                }
                fclose(f1); //<- close the file after you are done.
                break;
    //      case 3:
    //          printf("Modify account\n");
    //          //modify function
    //          printf("Account modification succesed!\n");
    //          break;
            case 4:
                printf("Closing Application...\n");
                break;
            default:
                printf("ERROR!\n");
                break;
        }
    }while(sel!=4);
}