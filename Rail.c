Rail #include <stdio.h>
#include<string.h>
char enc[50];
const char *encryptmsg(char msg[],int key)
{
    int msglen=strlen(msg),i,j,m,k=-1,row=0,col=0,u=0;
    char *e;
    char railmatrix[key][msglen];
    for(i=0;i<key;++i)
    for(j=0;j<msglen;++j)
    railmatrix[i][j]='\n';
    for(i=0;i<msglen;++i)
    {
        railmatrix[row][col++]=msg[i];
        if(row==0||row==key-1)
        k=k*(-1);
        row=row+k;
    }
    printf("\n Encrypted message:");
    for(i=0;i<key;++i)
    for(j=0;j<msglen;++j)
    if(railmatrix[i][j]!='\n')
    {
        enc[u++]=railmatrix[i][j];
        printf("%c",railmatrix[i][j]);
    }
    return enc;
}
void decryptmsg(char enmsg[],int key)
{
    int msglen=strlen(enmsg),i,j,m=0,k=-1,row=0,col=0;
    char railmatrix[key][msglen];
    for(i=0;i<key;++i)
    for(j=0;j<msglen;++j)
    railmatrix[i][j]='\n';
    for(i=0;i<msglen;++i)
    {
        railmatrix[row][col++]='*';
        if(row==0||row==key-1)
          k=k*(-1);
          row=row+k;
    }
    for(i=0;i<key;++i)
    for(j=0;j<msglen;++j)
    if(railmatrix[i][j]=enmsg[m++])
    row=col=0;
    k=-1;
    printf("\n Decrypted message:");
    for(i=0;i<msglen;++i)
    {
        printf("%c",railmatrix[row][col++]);
        if(row==0||row==key-1)
        k=k*(-1);
        row=row+k;
    }
}
int main()
{
    char msg[20];
    char enmsg[30];
    int key;
    printf("Enter message:\n");
    gets(msg);
    printf("Enter rails\n");
    scanf("%d",&key);
    printf("Original message:%s\n",msg);
    strcpy(enmsg,encryptmsg(msg,key));
    decryptmsg(enmsg,key);
    return 0;
}
