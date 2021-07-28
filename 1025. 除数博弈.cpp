//1025. 除数博弈
//爱丽丝和鲍勃一起玩游戏，他们轮流行动。爱丽丝先手开局。
//
//最初，黑板上有一个数字 N 。在每个玩家的回合，玩家需要执行以下操作：
//
//选出任一 x，满足 0 < x < N 且 N % x == 0 。
//用 N - x 替换黑板上的数字 N 。
//如果玩家无法执行这些操作，就会输掉游戏。
//
//只有在爱丽丝在游戏中取得胜利时才返回 True，否则返回 False。假设两个玩家都以最佳状态参与游戏。
//
//
//
//示例 1：
//
//输入：2
//输出：true
//解释：爱丽丝选择 1，鲍勃无法进行操作。
//示例 2：
//
//输入：3
//输出：false
//解释：爱丽丝选择 1，鲍勃也选择 1，然后爱丽丝无法进行操作。
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/divisor-game
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

// 方法一：数学
// 思路与算法

// 博弈类的问题常常让我们摸不着头脑。当我们没有解题思路的时候，不妨试着写几项试试：

// n = 1n=1 的时候，区间 (0, 1)(0,1) 中没有整数是 nn 的因数，所以此时 \text{Alice}Alice 败。
// n = 2n=2 的时候，\text{Alice}Alice 只能拿 11，nn 变成 11，\text{Bob}Bob 无法继续操作，故 \text{Alice}Alice 胜。
// n = 3n=3 的时候，\text{Alice}Alice 只能拿 11，nn 变成 22，根据 n = 2n=2 的结论，我们知道此时 \text{Bob}Bob 会获胜，\text{Alice}Alice 败。
// n = 4n=4 的时候，\text{Alice}Alice 能拿 11 或 22，如果 \text{Alice}Alice 拿 11，根据 n = 3n=3 的结论，\text{Bob}Bob 会失败，\text{Alice}Alice 会获胜。
// n = 5n=5 的时候，\text{Alice}Alice 只能拿 11，根据 n = 4n=4 的结论，\text{Alice}Alice 会失败。
// ......
// 写到这里，也许你有了一些猜想。没关系，请大胆地猜想，在这种情况下大胆地猜想是 AC 的第一步。也许你会发现这样一个现象：nn 为奇数的时候 \text{Alice}Alice（先手）必败，nn 为偶数的时候 \text{Alice}Alice 必胜。 这个猜想是否正确呢？下面我们来想办法证明它。

// 证明

class Solution {
public:
	bool divisorGame(int n) {
		return n % 2 == 0;
	}
};