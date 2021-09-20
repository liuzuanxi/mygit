#include <bits/stdc++.h>
#include <string>
#include <fstream> 
#include <stack>
using namespace std;
int if_cnt = 0;
int elseif_cnt = 0;
stack< string > stk;
bool flag = false;
int cnt1 = 0;
int cnt2 = 0;
string if_match[100];
string match[1000];
string if_key[3] = { "else if","if","else" };
string key[40] = { "auto","break","case","char","const","continue","default","double","else","enum","extern","float","for","goto","if","int","long","register","return","short","signed","sizeof","static","struct","switch","typedef","union","unsigned","void","volatile","while" };
int bruteforce(string t, string p) {									//按字符比对函数，参数分别为待比对字符串和模板字符串
	int lenT = t.size();
	int lenP = p.size();
	int i, j;

	for (i = 0; i <= lenT - lenP; ++i) {								//循环遍历每个字符，
		for (j = 0; j < lenP; ++j) {									//以模板字符串长度遍历
			if (t[i + j] != p[j]) {										//存在不匹配字符，跳出循环
				break;
			}
		}
		if (t[i + j] == '/' || t[i + j] == '"')
			return 0;
		if (j == lenP && ((t[i - 1] < 'a' || t[i - 1]>'z') || (t[i + j + 1] < 'a' && t[i + j + 1]>'z')))		//排除注释和引号内容
			return 1;
	}
	return 0;
}
void readbyline(char** argv)											//读入命令行参数
{
	char buffer[256];
	fstream fFile(argv[1], ios::in | ios::out);							//读取文件
	while (!fFile.eof())
	{
		fFile.getline(buffer, 256, '\n');								//按行读取字符串
		int lenth = strlen(buffer);
		for (int i = 0;i < 31;i++) {
			if (bruteforce(buffer, key[i])) {							//调用比对函数
				match[cnt1] = key[i];
				cnt1++;
			}
		}
	}
	fFile.close();
}
void level_2(string str[]);
void level_3and4(char** argv);
int main(int argc, char** argv) {
	readbyline(argv);
	cout << "total num:" << cnt1 << endl;
	char level = *argv[2];
	switch (level) {
	case '1':break;
	case '2': {
		level_2(match);
		break;
	}
	case '3': {
		level_3and4(&argv[1]);
		cout << "if-else num:";
		cout << if_cnt << endl;
		break;
	}
	case '4': {
		level_3and4(&argv[1]);
		cout << "if-else num:";
		cout << if_cnt << endl;
		cout << "else-if num:";
		cout << elseif_cnt << endl;
		break;
	}
	default:break;
	}
	return 0;
}
void level_2(string str[]) {		
	int temp1 = 0, temp2[100] = { 0 };
	int tmp = 0;
	for (int i = 0;i < cnt1;i++) {
		if (str[i] == "switch"){										//检测switch
			temp1++;													//switch数目
			tmp++;														//标志加1
		}

		else if (str[i] == "case")
			temp2[tmp]++;												//统计case
	}
}
void level_3and4(char** argv) {			
	level_2(match);
	int temp1 = 0, temp2 = 0;
	for (int i = 0;i < cnt2;i++) {
		if (if_match[i] == "if")
			stk.push(if_match[i]);										//为if则push进栈
		else if (if_match[i] == "else if" && stk.top() != "else if")	//栈顶为if时将elseif push进栈
			stk.push(if_match[i]);
		if (if_match[i] == "else" && stk.top() == "if") {
			stk.pop();													//检测到else时栈顶为if则pop一次
			if_cnt++;
		}
		else if (if_match[i] == "else" && stk.top() == "else if") {
			stk.pop();
			stk.pop();													//栈顶为elseif时pop两次
			elseif_cnt++;
		}
	}
}
