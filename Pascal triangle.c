#include <stdio.h>
#include "string.h"
#include "math.h"
#include "unistd.h"

unsigned long long comb(unsigned long long n,unsigned long long r){
    return tgamma(n+1)/(tgamma(n-r+1)*tgamma(r+1));
}

int main(){
    unsigned long long n,u=0,C;
    int no_of_space=0;
    char space[100],test_space[50],name[30],save[4];
    
    printf("Enter your name:");
    gets(name);
    sleep(1);
    printf("Welcome %s!!!\n",name);
    sleep(2);
    printf("Have you saved this program on your device? Because for saving file a location is required (y/n)");
    gets(save);
    (save[0]=='n' || save[0]=='N') ? printf("Then you must save it first otherwise even if you execute the program, you will not able to find your file.\n") : printf("Alright ");
    sleep((save[0]=='n' || save[0]=='N')? 5:1);
    printf("Pascal triangle program is getting ready.\n");
    sleep(3);
    printf("Until that you need to know what this program does.\n");
    sleep(4);
    printf("This program will create a txt file which cantains Pascal triangle printed on it.\n");
    sleep(4);
    printf("You can specify number of rows of pascal triangle to be printed in the file.\n");
    sleep(4);
    printf("Warning : Don't give a large number as input. Then triangle will go out of your screen device.\n");
    sleep(4);
    printf("ENJOY %s\n\n",name);
    sleep(1);
    printf("Enter number of rows:");
    scanf("%llu",&n);
    
    sprintf(test_space,"%llu",comb(n-1,(n%2)? (n/2) : n/2-1));
    for (int i=1; i<=strlen(test_space)+1; i++){
        no_of_space++;
    }
    
    FILE *fi=fopen("Pascal triangle.txt","w");
    for (unsigned long long i=1; i<=n; i++){
        for (int j=1;j<=n-i; j++){
            for (int u=1; u<=(no_of_space+1)/2;u++){
                fprintf(fi," ");
            }
        }
        for (int j=1;j<=i;j++){
            C=comb(i-1,u++);
            fprintf(fi,"%llu",C);
            sprintf(space,"%llu",C);
            for (int k=1;k<=no_of_space-strlen(space); k++) fprintf(fi," ");
        }
        fprintf(fi,"\n");
        u=0;
    }
    fclose(fi);
    printf("File has been successfully created.\n");
    sleep(2);
    printf("You will find your file where you have saved this C program with a name \"Pascal triangle.txt\".\n");
    sleep(4);
    printf("Thanks for using this program %s.\n",name);
    sleep(2);
    printf("For more programs check it out:-\n");
    sleep(2);
    printf("https://www.linkedin.com/in/aayush-kukreja-b5885324a");
}