#include<stdio.h>
#include<Windows.h>
#define Not_found -1
//返回值：success：数组下标，failed：-1
//升序
int binsearch(int arr[],int num ,int total)
{
	int start = 0, end = num - 1;
	while (start <= end){
		int mid = (start + end) / 2;
		if (total < arr[mid]){
			end = mid - 1;
		}
		else if (total>arr[mid]){
			start = mid + 1;
		}
		else {
			return mid;
		}
		}
	return Not_found;
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 156 };
	int total = 156;
	int num = sizeof(arr) / sizeof(arr[0]);
	int result = binsearch(arr,num,total);
	printf("%d", result);
	system("pause");
}