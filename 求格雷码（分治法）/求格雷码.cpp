#include<iostream>
#include<vector>
using namespace std;
void generategray(int n, vector<string>&gray)
{
	if (n == 1)
	{
		gray.push_back("0");
		gray.push_back("1");
		return;
	}
	generategray(n - 1, gray);
	int size = gray.size();//保存n-1位Gary码的位数
	vector<string>temp = gray;
	//前半部分，将n-1位的每个gray码前面都添加“0”，升级为n位
	for (int i = 0; i < size; i++)
	{
		gray[i] = "0" + gray[i];
	}
	// 后半部分：逆序遍历 n - 1 位的 Gray 码，每个前加 '1'
	for (int i = size - 1; i >= 0; i--)
	{
		gray.push_back("1" + temp[i]);
	}
}
int main()
{
	int n;
	cin >> n;//输入要生成的gray码位数n
	vector<string>graycode;//存储生成的格雷码
	generategray(n, graycode);
	for (const auto& code : graycode)
	{
		cout << code << endl;
	}


}