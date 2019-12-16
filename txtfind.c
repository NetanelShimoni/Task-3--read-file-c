#define Line 256
#include <stdio.h>
#include <string.h>
#define WORD 30


int substring(char *str1, char *str2);
int similar (char *s, char *t, int n);
int main() {
    char buf;
    int i=0;
    char func;
    char search[WORD];
    char w[WORD];
    char line[Line];


    //////////find a string search//////////////////
    while((buf=getc(stdin))!= ' ')
    {
        search[i]=buf;
        i++;
    }
    search[i]='\0';

    ////////////find func a or b////////
    i=0;
    while ((buf=getc(stdin))!= '\n' ){
        line[i]=buf;
        i++;
        if (buf=='a' || buf=='b'){
             func =buf;
        }
    }
    line[i]='\0';


    i=0;
    if (func=='a')
    {
        while ((buf=getc(stdin))!= EOF){
            line[0]=buf;
            i++;
        while ((buf=getc(stdin))!= '\n' ) {
            line[i]=buf;
            i++;
        }
        line[i]='\0';
        int contains= substring(line,search);
        if (contains){
          puts(line);
            contains=0;
        }
        i=0;
        }
    }
    if (func=='b')
    {
        i=0;
        while ((buf=getc(stdin))!= EOF){
            if(buf=='\n' || buf=='\t' ||buf== ' ') {
                w[i] ='\0';
                i=0;
                int is_similar_one= similar(w,search,1);
                int is_similar_zero= similar(w,search,0);
                if (is_similar_one || is_similar_zero){
                    puts(w);
                    is_similar_one=0;
                    is_similar_zero=0;
            }


            }else{
             w[i]=buf;
             i++;
            }
        }
        }
    return 0;
}
int similar(char *s, char *t, int n)
{
    int j_s=0;
    if (strlen(s)<strlen(t)){
        return 0;
    }
    for (int i = 0; i <strlen(t) ; i++) {
        if (*(t+i)!=*(s+j_s)){
            n--;
            j_s++;
            i--;
        }else {
            j_s++;
        }
        if (n<0){
            return 0;
        }
    }
    int w= strlen(s)-j_s;
    n=n-w;
    if (n==0) {
        return 1;
    } else{
        return 0;
    }
}


int substring(char *str1, char *str2)
{
    int count = 0, j = 0, i = 0;
    while (i < strlen(str1) && j < strlen(str2))
    {
        if (str1[i] == str2[j])
        {
            count++;
            i++;
            j++;
        }
        else{
            j=0;
            i++;
            count=0;
        }


    }
    if (count==strlen(str2))
    {
        return 1;
    }
    else {
        return 0;
    }}
