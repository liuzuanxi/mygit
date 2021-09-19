#include <bits/stdc++.h>
#include <fstream> 
#include <stack>
using namespace std;

	int if_cnt=0;
	int elseif_cnt=0;
	stack< string > stk;
	bool flag = false;
	int cnt1=0;
	int cnt2=0;
	string if_match[100];
	string match[1000];
	string if_key[3]={"else if","if","else"};
	string key[40]={"auto","break","case","char","const","continue","default","double","else","enum","extern","float","for","goto","if","int","long","register","return","short","signed","sizeof","static","struct","switch","typedef","union","unsigned","void","volatile","while"};

int BruteForce(string t, string p){
	int lenT = t.size();
	int lenP = p.size();
	int i, j;

	for (i = 0; i <= lenT - lenP; ++i){
		for (j = 0; j < lenP; ++j){
			if (t[i + j] != p[j]){
				break;
			}
		}
		if(t[i+j]=='/'||t[i+j]=='"')
			return 0;
		if (j == lenP&&((t[i-1]<'a'||t[i-1]>'z')||(t[i+j+1]<'a'&&t[i+j+1]>'z')))
			return 1;
	}
	return 0;
}
void TextFileReadByLine(char** argv)
{
	char buffer[256];
//	ifstream in;
	fstream fFile(argv[1], ios::in | ios::out);
//	in.open("argv[1]",ios::in);
	while(!fFile.eof())
	{
		fFile.getline(buffer,256,'\n');
		int lenth = strlen(buffer);
		for(int i = 0;i<31;i++){
			if(BruteForce(buffer, key[i])){
				match[cnt1]=key[i];
				cnt1++;
			}
		}
		for(int i = 0;i<3;i++){
			if(BruteForce(buffer, if_key[i])&&if_key[i]!="else if"){
				if_match[cnt2]=if_key[i];
				cnt2++;
			}
			if(BruteForce(buffer, if_key[i])&&if_key[i]=="else if"){
				if_match[cnt2]=if_key[i];
				cnt2++;
				break;
			}
		}
		//cout<<buffer<<endl;
	}
	fFile.close();
}
void level_2(string str[]);
void level_3and4(char **argv);
int main(int argc, char **argv){
	TextFileReadByLine(argv);
	cout<<"total num:"<<cnt1<<endl;
	char level=*argv[2];
	switch (level){
		case '1':break;
		case '2':{
		level_2(match);
			break;
		}
		case '3': {
				level_3and4(&argv[1]);
				cout<<"if-else num:";
				cout<<if_cnt<<endl;
			break;
		}
		case '4': {
				level_3and4(&argv[1]);
				cout<<"if-else num:";
				cout<<if_cnt<<endl;
				cout<<"else-if num:";
				cout<<elseif_cnt<<endl;
			break;
		}
		default:break;
	}
	return 0;
	}
void level_2(string str[]){
	int temp1=0,temp2[100]={0};
	int tmp=0;
	for(int i=0;i<cnt1;i++){
		if (str[i]=="switch")
		temp1++;
		else if(str[i]=="case")
		temp2[tmp]++;
		else if(str[i]=="default")
		tmp++;
	}
	cout<<"switch num:"<<temp1<<endl;
	cout<<"case num:";
	for(int i=0;i<tmp;i++)
	cout<<temp2[i]<<" ";
	cout<<endl;
}
void level_3and4(char **argv){
	level_2(match);
	int temp1=0,temp2=0;
	for(int i=0;i<cnt2;i++){
		if(if_match[i]=="if")
		stk.push(if_match[i]);
		else if(if_match[i]=="else if"&&stk.top()!="else if")
		stk.push(if_match[i]);
		if(if_match[i]=="else"&&stk.top()=="if"){
			stk.pop();
			if_cnt++;
		}
		else if(if_match[i]=="else"&&stk.top()=="else if"){
			stk.pop();
			stk.pop();
			elseif_cnt++;
		}
	}
}
