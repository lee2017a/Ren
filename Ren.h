#pragma once
#include<iostream>
using namespace std;

class Ren
{
public:
	bool isHuoRen;//�Ƿ����
	bool isJieHun;//�Ƿ���
	int ID;//���
	int NianLing;//����
	int PeiOu;//��ż
	int Hun;
		
	//bool isShenYu;
	//int HaiZhi;//����
	void set(bool, bool, int, int, int, int);
	int JieHun(Ren[10][100]);
	int SenHai(Ren[10][100]);
	void ChengZhang();
};

void xs(Ren ptr[10][100])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 100; j++)//������ʼ��300�� ���� ��� id ���� ��ż ����
		{
			if (ptr[i][j].isHuoRen)
			{
				std::cout << "is���ţ�" << ptr[i][j].isHuoRen << "=is��飺" << ptr[i][j].isJieHun << "=ID��" << ptr[i][j].ID << "=���䣺" << ptr[i][j].NianLing << "=��ż��" <<ptr[i][j].PeiOu <<std::endl;
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

int Ren::JieHun(Ren ptr[10][100])//���
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
					std::cout << "=���=" << ID << "��" << PeiOu << "�����" << "������" << NianLing << "ĸ����" << ptr[i][j].NianLing << std::endl;
					return 0;
				}
			}
		}
	}
	return 0;
}

int Ren::SenHai(Ren ptr[10][100])//������
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
					std::cout << "=���ӵ�id=" << ptr[i][j].ID << "=����id=" << ID << "=ĸ��id=" << PeiOu << "=sen hai!=" << std::endl;
					if (ptr[9][99].isHuoRen)
					{
						std::cout << "=���Ӵﵽ1000" << std::endl;
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


