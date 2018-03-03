#include <bits/stdc++.h>
using namespace std;
int keypad(int num, string output[],string keypadButton[])
{
	if(num/10==0)
		output[0]="";
	return 1;

	int suffix=num%10;
	int outputsize=keypad(suffix,output,keypadButton);
	if((num-2)==5||(num-2)==7)
	{
		for (int i = 0; i < outputsize; ++i)
		{
			for (int j=0;j<outputsize*4 ;++j)
				output[outputsize+i]=keypadButton[num-2][j]+output[i];
		}
		return 5*outputsize;	
	}
	else
	{
		for (int i = 0; i < outputsize; ++i)
		{
			for (int j=0;j<outputsize*3 ;++j)
				output[outputsize+i]=keypadButton[num-2][j]+output[i];
		}
		return 4*outputsize;
	}

	
}
int main()
{
	int num;
	string output[100000];
	/*char keypadButton[8][4];
	keypadButton[0][0]='a';keypadButton[0][1]='b';keypadButton[0][2]='c';
	keypadButton[1][0]='d';keypadButton[1][1]='e';keypadButton[1][2]='f';
	keypadButton[2][0]='g';keypadButton[2][1]='h';keypadButton[2][2]='i';
	keypadButton[3][0]='j';keypadButton[3][1]='k';keypadButton[3][2]='l';
	keypadButton[4][0]='m';keypadButton[4][1]='n';keypadButton[4][2]='o';
	keypadButton[5][0]='p';keypadButton[5][1]='q';keypadButton[5][2]='r';keypadButton[5][3]='s';
	keypadButton[6][0]='t';keypadButton[6][1]='u';keypadButton[6][2]='v';
	keypadButton[7][0]='w';keypadButton[7][1]='x';keypadButton[7][2]='y';keypadButton[7][4]='z';*/
	string keypadButton[8];
	keypadButton[0]='abc';
	keypadButton[1]='def';
	keypadButton[2]='ghi';
	keypadButton[3]='jkl';
	keypadButton[4]='mno';
	keypadButton[5]='pqrs';
	keypadButton[6]='tuv';
	keypadButton[7]='wxyz';

	cin>>num;
	int size=keypad(num,output,keypadButton);
	for(int i=0;i<size;i++)
		cout<<output[i]<<endl;
	return 0;
}