#include <bits/stdc++.h>
#include <fstream> 
using namespace std;
	int cnt = 0;
	
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
			cnt++;
			return 1;
		}
	}
	return 0;
}
void TextFileReadByLine(char** argv)
{
	char buffer[256];
//	ifstream in;
	fstream fFile("C:\\Users\\Administrator\\Desktop\\11.txt", ios::in | ios::out);
//	in.open("argv[1]",ios::in);
	while(!fFile.eof())
	{
		fFile.getline(buffer,256,'\n');
		
			int lenth = strlen(buffer);
		
		for(int i = 0;i < 31; i++){
		
			BruteForce(buffer, key[i]);
		}
		//cout<<buffer<<endl;
	}
	fFile.close();
}
int main(int argc, char **argv){
	
	TextFileReadByLine(argv);

	cout << "total num:" << cnt << endl;

	return 0;
	}
