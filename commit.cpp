#include <bits/stdc++.h>
#include <fstream> 
using namespace std;
	int cnt1 = 0;
	string match[1000];
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
		if (j == lenP){
			cnt1++;
			return 1;
		}
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
		
		for(int i = 0;i < 31; i++){
		
			if(BruteForce(buffer, key[i]))
			match[cnt1]=key[i];
		}
		//cout<<buffer<<endl;
	}
	fFile.close();
}
void level_2(string str[]);
int main(int argc, char **argv){
	
	TextFileReadByLine(argv);
	
		char level=*argv[2];
		
		switch (level){
			
		case '1':break;
		
		case '2':{
		level_2(match);break;
		}

	cout << "total num:" << cnt1 << endl;

	return 0;
	}
}
void level_2(string str[]){
	
	int temp1 = 0,temp2[100] = {0};
	int tmp = 0;
	
	for(int i = 0 ; i < cnt1 ; i++){
		
		if (str[i] == "switch")
		
			temp1++;
		
		else if(str[i] == "case")
		
			temp2[tmp]++;
		
		else if(str[i] == "default")
		
			tmp++;
	}
	cout<<"switch num:"<<temp1<<endl;
	
	cout<<"case num:";
	
	for(int i = 0;i < tmp ; i++)
	
	cout<<temp2[i]<<" ";
	
	cout<<endl;
}
