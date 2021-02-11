//383. 赎金信
//给定一个赎金信(ransom) 字符串和一个杂志(magazine)字符串，判断第一个字符串 ransom 能不能由第二个字符串 magazines 里面的字符构成。如果可以构成，返回 true ；否则返回 false。
//
//(题目说明：为了不暴露赎金信字迹，要从杂志上搜索各个需要的字母，组成单词来表达意思。杂志字符串中的每个字符只能在赎金信字符串中使用一次。)
//
//
//
//注意：
//
//你可以假设两个字符串均只含有小写字母。
//
//canConstruct("a", "b") -> false
//canConstruct("aa", "ab") -> false
//canConstruct("aa", "aab") -> true
//通过次数37, 947提交次数67, 639
//在真实的面试中遇到过这道题？
//贡献者
//LeetCode
//注意：
//
//你可以假设两个字符串均只含有小写字母。
//
//canConstruct("a", "b") -> false
//canConstruct("aa", "ab") -> false
//canConstruct("aa", "aab") -> true
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/ransom-note
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
bool canConstruct(char * ransomNote, char * magazine){
	//方法一：计数累计法(计数排序法的变形)
	//26个英文字母，我们ransomnote里的每个字母出现的次数记录下来，用magzine去减出现次数，为0的不减，不为0的减去。
	//最后计算数组总和为0 则可以，非0 则不可以。
	int arr[26]={0};
	while(*ransomNote!='\0')
	{
	printf("%d\n",*ransomNote);
	arr[*ransomNote-97]++;
	ransomNote++;
	}
	while(*magazine!='\0')
	{
	if(arr[*magazine-97]!=0)
	{
	arr[*magazine-97]--;
	magazine++;
	}
	else
	{
	magazine++;
	continue;
	}
	}
	int ret=0;
	for(int i=0;i<26;i++)
	{
	ret+=arr[i];
	}
	if(ret==0)
	{
	return true;
	}
	else
	{
	return false;
	}

	//方法二：暴力
	//int ransomNotelength = strlen(ransomNote);
	//int magazinelength = strlen(magazine);
	//int flag = ransomNotelength;
	//for (int i = 0; i < ransomNotelength; i++)
	//{
	//	for (int j = 0; j < magazinelength; j++)
	//	{
	//		// 在ransomNote中找到和magazine相同的字符
	//		if (magazine[j] == ransomNote[i])
	//		{
	//			magazine[j] = 'A'; // magazine删除这个字符
	//			flag--;
	//			break;
	//		}
	//	}
	//}
	//// 如果ransomNote为空，则说明magazine的字符可以组成ransomNote
	//if (flag == 0) {
	//	return true;
	//}
	//return false;

}