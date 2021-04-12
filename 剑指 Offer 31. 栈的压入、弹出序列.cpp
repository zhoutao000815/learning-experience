//剑指 Offer 31. 栈的压入、弹出序列
//输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如，序列{ 1, 2, 3, 4, 5 } 是某栈的压栈序列，序列{ 4, 5, 3, 2, 1 } 是该压栈序列对应的一个弹出序列，但{ 4, 3, 5, 1, 2 } 就不可能是该压栈序列的弹出序列。
//
//
//
//示例 1：
//
//输入：pushed = [1, 2, 3, 4, 5], popped = [4, 5, 3, 2, 1]
//输出：true
//解释：我们可以按以下顺序执行：
//push(1), push(2), push(3), push(4), pop() -> 4,
//push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
//示例 2：
//
//输入：pushed = [1, 2, 3, 4, 5], popped = [4, 3, 5, 1, 2]
//输出：false
//解释：1 不能在 2 之前弹出。
//
//
//提示：
//
//0 <= pushed.length == popped.length <= 1000
//0 <= pushed[i], popped[i] < 1000
//pushed 是 popped 的排列。

//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof/
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		if (pushed.size() != popped.size())
		{
			return false;
		}

		stack<int> st;
		//用一个栈去模拟实现入栈出栈的动作。如何模拟？
		//两个指针分别放在push （i）和pop （j）数组起始；
		//从push数组开始判断，不等于pop则入栈，i++；等于说明即入即出，j++；接下来判断栈顶元素和pop【j】，在栈不为空的前提下，相等则出栈。
		//到最后，如果是正确的两个序列，必定是双指针都走完的，判断得出结果。

		int pushedsize = pushed.size();
		int poppedsize = popped.size();
		int i = 0, j = 0;
		while (i<pushedsize)
		{
			if (pushed[i] != popped[j])
			{
				st.push(pushed[i]);
			}
			else
			{
				j++;                             //等于时，即入即出，没必要再模拟，直接j++。
				while (!st.empty() && st.top() == popped[j])
				{
					st.pop();
					j++;
				}
			}
			i++;
		}
		if (i == pushedsize && j == poppedsize)
			return true;

		return false;
	}
};