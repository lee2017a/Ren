#include <iostream>
#include "Ren.h"
using namespace std;

int main()
{
	std::cout << "FangZhuZhiCheng!" << std::endl;
	
	Ren ren[10][100];

	cout << sizeof(ren[0][0]) << endl;//2000 ��С
	
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 100; j++)//������ʼ��300�� ���� ��� id ���� ��ż ����
		{
			ren[i][j].set(false,false, i*100+j, 0, 0, 0);
		}

	}
	//xs(ren);
	for (int i = 0; i < 2; i++)//��ʼ��10����
	{
		ren[0][i].isHuoRen = true;
	}
	//xs(ren);

	for (int t = 0; t < 100; t++)
	{

		std::cout << t << "�꿪ʼ" << std::endl;

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

		std::cout << t << "�����" << std::endl;
		std::cout << std::endl;

		if (ren[9][99].isHuoRen)
			return 0;


	}//end time
	
	return 0;
}