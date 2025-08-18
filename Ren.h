#pragma once
#include<iostream>
using namespace std;

class Ren
{
public:
	bool isHuoRen;//是否活人
	bool isJieHun;//是否结婚
	int ID;//编号
	int NianLing;//年龄
	int PeiOu;//配偶
	int Hun;
		
	//bool isShenYu;
	//int HaiZhi;//孩子
	void set(bool, bool, int, int, int, int);
	int JieHun(Ren[10][100]);
	int SenHai(Ren[10][100]);
	void ChengZhang();
};

void xs(Ren ptr[10][100])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 100; j++)//基本初始化300人 活人 结婚 id 年龄 配偶 婚龄
		{
			if (ptr[i][j].isHuoRen)
			{
				std::cout << "is活着：" << ptr[i][j].isHuoRen << "=is结婚：" << ptr[i][j].isJieHun << "=ID：" << ptr[i][j].ID << "=年龄：" << ptr[i][j].NianLing << "=配偶：" <<ptr[i][j].PeiOu <<std::endl;
			}
		}
	}
}

void Ren::set(bool huo, bool jie,int id, int nian,int pei,int h)
{
	isHuoRen = huo;
	isJieHun = jie;
	ID = id;
	NianLing = nian;
	PeiOu = pei;
	Hun = h;
}

int Ren::JieHun(Ren ptr[10][100])//结婚
{
	if (isHuoRen && !isJieHun && NianLing >= 1 && ID % 2 == 0)
	{
		if (ptr[9][99].isHuoRen)
			return 0;
			
		for (int i = 0; i < 10; i++)
		{
			for (int j = 1; j < 100; j += 2)
			{
				if (ptr[i][j].isHuoRen && !ptr[i][j].isJieHun && ptr[i][j].NianLing >= 1)
				{
					isJieHun = true;
					PeiOu = i*100+j;
					ptr[i][j].isJieHun = true;
					ptr[i][j].PeiOu = ID;
					Hun = NianLing;
					std::cout << "=结婚=" << ID << "和" << PeiOu << "结婚了" << "父年龄" << NianLing << "母年龄" << ptr[i][j].NianLing << std::endl;
					return 0;
				}
			}
		}
	}
	return 0;
}

int Ren::SenHai(Ren ptr[10][100])//生孩子
{
	if (isHuoRen && isJieHun && ID % 2 == 0 && NianLing - Hun >= 1)
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				if (!ptr[i][j].isHuoRen)
				{
					ptr[i][j].isHuoRen = true;
					std::cout << "=孩子的id=" << ptr[i][j].ID << "=父亲id=" << ID << "=母亲id=" << PeiOu << "=sen hai!=" << std::endl;
					if (ptr[9][99].isHuoRen)
					{
						std::cout << "=孩子达到1000" << std::endl;
					}
					return 0;
				}
			}
		}
	}
	return 0;
}

void Ren::ChengZhang()
{
	if (isHuoRen)
	{
		NianLing++;
	}
}


