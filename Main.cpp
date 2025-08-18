#include <iostream>
#include "Ren.h"
using namespace std;

int main()
{
	std::cout << "FangZhuZhiCheng!" << std::endl;
	
	Ren ren[10][100];

	cout << sizeof(ren[0][0]) << endl;//2000 大小
	
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 100; j++)//基本初始化300人 活人 结婚 id 年龄 配偶 婚龄
		{
			ren[i][j].set(false,false, i*100+j, 0, 0, 0);
		}

	}
	//xs(ren);
	for (int i = 0; i < 2; i++)//初始化10个人
	{
		ren[0][i].isHuoRen = true;
	}
	//xs(ren);

	for (int t = 0; t < 100; t++)
	{

		std::cout << t << "年开始" << std::endl;

		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				if (ren[i][j].isHuoRen)
				{
					ren[i][j].JieHun(ren);
				}

			}
		}
		//xs(ren);

		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				if (ren[i][j].isHuoRen)
				{
					ren[i][j].SenHai(ren);
				}


			}
		}
		//xs(ren);
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				if (ren[i][j].isHuoRen)
				{
					ren[i][j].ChengZhang();
				}


			}
		}
		//xs(ren);

		std::cout << t << "年结束" << std::endl;
		std::cout << std::endl;

		if (ren[9][99].isHuoRen)
			return 0;


	}//end time
	
	return 0;
}