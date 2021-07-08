//链接：https://www.nowcoder.com/questionTerminal/2baa6aba39214d6ea91a2e03dff3fbeb?toCommentId=9439341
//来源：牛客网
//
//简单错误记录
//热度指数：241728时间限制：C / C++ 1秒，其他语言2秒空间限制：C / C++ 32M，其他语言64M
//算法知识视频讲解
//开发一个简单错误记录功能小模块，能够记录出错的代码所在的文件名称和行号。
//
//
//处理：
//
//
//1、 记录最多8条错误记录，循环记录，最后只用输出最后出现的八条错误记录。对相同的错误记录只记录一条，但是错误计数增加。最后一个斜杠后面的带后缀名的部分（保留最后16位）和行号完全匹配的记录才做算是”相同“的错误记录。
//2、 超过16个字符的文件名称，只记录文件的最后有效16个字符；
//3、 输入的文件可能带路径，记录文件名称不能带路径。
//4、循环记录时，只以第一次出现的顺序为准，后面重复的不会更新它的出现时间，仍以第一次为准
//
//
//输入描述 :
//每组只包含一个测试用例。一个测试用例包含一行或多行字符串。每行包括带路径文件名称，行号，以空格隔开。
//
//
//
//输出描述 :
//将所有的记录统计并将结果输出，格式：文件名 代码行数 数目，一个空格隔开，如：
//
//示例1
//
//输入
//D : \zwtymj\xccb\ljj\cqzlyaszjvlsjmkwoqijggmybr 645
//E:\je\rzuwnjvnuz 633
//C:\km\tgjwpb\gy\atl 637
//F:\weioj\hadd\connsh\rwyfvzsopsuiqjnr 647
//E:\ns\mfwj\wqkoki\eez 648
//D:\cfmwafhhgeyawnool 649
//E:\czt\opwip\osnll\c 637
//G:\nt\f 633
//F:\fop\ywzqaop 631
//F:\yay\jc\ywzqaop 631
//
//  输出
//  rzuwnjvnuz 633 1
//  atl 637 1
//  rwyfvzsopsuiqjnr 647 1
//  eez 648 1
//  fmwafhhgeyawnool 649 1
//  c 637 1
//  f 633 1
//  ywzqaop 631 2



//肯定有小伙伴和我一样在这个地方踩坑了。
//误区：如果一个错误A已经出现过，而且在这个错误之后又出现了8个及以上不重复的错误，此时A已经不在8个错误列表当中了。
//但是这个错误A此时又出现了，虽然A已经不在错误列表中了，但是不能放进去,因为题目第四条要求。即对于已经出现过的错误，以第一次出现时间为准，不更新出现时间。

#include<bits/stdc++.h>
using namespace std;
int main()
{
	list<string> ls;
	unordered_map<string, int> ms;
	string tmp;
	while (getline(cin, tmp))
	{
		int pos1 = tmp.find_last_of('\\');
		int pos2 = tmp.find_last_of(' ');
		if ((pos2 - pos1)>17)
			tmp = tmp.substr(pos2 - 16);
		else
			tmp = tmp.substr(pos1 + 1);

		bool have_error = false;
		for (auto &e : ms)      //误区：要在哈希表找出现记录噢，而不是8个错误列表中找
		{
			if (e.first == tmp)
			{
				ms[tmp]++;
				have_error = true;
			}
		}
		if (have_error)
			continue;

		if (ls.size() >= 8)
		{
			auto it = ls.front();
			//ms.erase(it);           //防止后面再出现相同错误，哈希表不能删除记录噢
			ls.pop_front();
		}
		ls.push_back(tmp);
		ms[tmp]++;
		tmp.clear();
	}
	for (auto &e : ls)
	{
		string post = " ";
		char count = '0' + ms[e];
		post += count;
		e += post;
		cout << e << endl;
	}
	return 0;
}