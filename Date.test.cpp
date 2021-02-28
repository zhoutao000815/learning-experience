#include"Date.h"
int main()
{
	Date d1(2000, 8, 15);
	Date d2(2000, 10, 8);

	//d1 += 54;
	//d2.Print();
	//(d1 + 54).Print();
	//(d1 - 54).Print();

	//d1++.Print();
	//(++d1).Print();

	//d2--.Print();
	//(--d2).Print();

	//if (d1 > d2)  //到底是过去的日子大，还是将来的日子大? 这个比较大小重载写的是将来大，
	//{
	//	Date dtemp(d1);
	//	dtemp.Print();
	//}
	//else
	//{
	//	Date dtemp(d2);
	//	dtemp.Print();
	//}
	
	int sum = d2 - d1;
	
	system("pause");
}