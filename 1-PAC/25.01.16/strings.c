#include <stdio.h>
void misterio(char s[]){
    int i = 0;
    while(s[i]){
        if(s[i]>='A' && s[i]<='Z'){
            s[i] = s[i]-'A'+'a';
        }
        i++;
    }
}
void misterio2(char s[]){
    int m = 0;
    for(int i=0; i<strlen(s); i++){
        if(s[i]>= '0' && s[i]<='9'){
            m = m*10 + s[i] - '0';
        }
    }
}//isso é a função atoi("1234"), transforma de caracter para inteiro

void misterio3(char s[]){
    for(int i=strlen(s)-1; i>=0; i--){
        printf("printf")
    }
}

void misterio4(char *s){ //imprime string por recursão
    if(*s){
        printf("%c", *s);//se inverter fica de trás pra frente
        misterio4(s+1);
    }
}

void main(){
    char msg[6];
    /*
    char s[10];
    strcpy(s,"ABCdefGHI");
    misterio (s);
    */
    scanf("%s", msg);
    misterio(msg); // misterio muda a forma de msg
    printf("%s",msg);
    
}