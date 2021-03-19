//387. 字符串中的第一个唯一字符
//给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 - 1。
//
//
//
//示例：
//
//s = "leetcode"
//返回 0
//
//s = "loveleetcode"
//返回 2
//
//
//提示：你可以假定该字符串只包含小写字母。
//示例：
//
//s = "leetcode"
//返回 0
//
//s = "loveleetcode"
//返回 2
//
//
//提示：你可以假定该字符串只包含小写字母。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/first-unique-character-in-a-string
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
class Solution {
public:
	int firstUniqChar(string s) {
		int arr[26] = { 0 };
		int size = s.size();
		for (int i = 0; i<size; i++)
		{
			arr[s[i] - 'a']++;
		}
		for (int i = 0; i<size; i++)
		{
			if (arr[s[i] - 'a'] == 1)
			{
				return i;
			}
		}
		return -1;
	}
};
//由于确定是小写字符，所以采用上面那种办法
// class Solution {
// public:
//     int firstUniqChar(string s) {
//     // 统计每个字符出现的次数
//     int count[256] = {0};
//     int size = s.size();
//     for(int i = 0; i < size; ++i)
//     count[s[i]] += 1;
//     // 按照字符次序从前往后找只出现一次的字符
//     for(int i = 0; i < size; ++i)
//     if(1 == count[s[i]])
//     return i;
//     return -1;
//     }
// };