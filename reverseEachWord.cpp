#include<bits/stdc++.h>
using namespace std;
void remove(char input[],int s, int e)
{
    char ch;
    for(int i=s;i<e;i++,e--)
    {
        ch = input[i];
        input[i]=input[e];
        input[e]=ch;

    }

}
void reverseEachWord(char input[])
{
    int e=0,s=0,i=0,l=0;
    while(input[i]!='\0')
    {
        i++;
        l++;
    }
    for(int i=0;i<=l;i++)
    {
        if(input[i]==' '||input[i]=='\0')
        {
            e=i-1;
            remove(input,s,e);
            s=i+1;
        }
    }
}
int main()
{
    char input[1005];
    cin.getline(input,1005);
    reverseEachWord(input);
    cout<<input;
return 0;
}
