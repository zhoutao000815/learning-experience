//35. 搜索插入位置
//给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
//
//你可以假设数组中无重复元素。
//
//示例 1:
//
//输入 : [1, 3, 5, 6], 5
//输出 : 2
//	 示例 2 :
//
// 输入 : [1, 3, 5, 6], 2
//  输出 : 1
//	   示例 3 :
//
//   输入 : [1, 3, 5, 6], 7
//	输出 : 4
//		 示例 4 :
//
//	 输入 : [1, 3, 5, 6], 0
//	  输出 : 0
//	   输入 : [1, 3, 5, 6], 0
//		输出 : 0
//
//	来源：力扣（LeetCode）
//	链接：https ://leetcode-cn.com/problems/search-insert-position
//	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

int searchInsert(int* nums, int numsSize, int target){
	if (target>nums[numsSize - 1])  //大于最后一个数字，必然没有相等的，直接返回numsize，插入后+1.所以不是numsize-1.
	{
		return numsSize;
	}
	int pr = 0;
	int insert = -1;              //-1是为了区别下标，好正确的表示插入下标。
	while (numsSize--)
	{
		if (nums[pr] == target)
		{
			return pr;
		}
		if (target<nums[pr] && insert == -1)   //找小于要找第一个小于的。
		{
			insert = pr;
		}
		pr++;
	}
	return insert;
}