#include <iostream>
#include <string>
#include <vector>

/*
Description of the Question
    题目：
	在微软亚洲研究院上班，大家早上来的第一件事是干啥呢？查看邮件？No，是去水房拿饮料：酸奶，豆浆，绿茶、王老吉、咖啡、可口可乐……（当然，还是有很多同事把拿饮料当做第二件事）。
    管理水房的阿姨们每天都会准备很多的饮料给大家，为了提高服务质量，她们会统计大家对每种饮料的满意度。一段时间后，阿姨们已经有了大批的数据。
	某天早上，当实习生小飞第一个冲进水房并一次拿了五瓶酸奶、四瓶王老吉、三瓶鲜橙多时，阿姨们逮住了他，要他帮忙。
    从阿姨们统计的数据中，小飞可以知道大家对每一种饮料的满意度。阿姨们还告诉小飞，STC（Smart Tea Corp.）负责给研究院供应饮料，每天总量为V。
	STC很神奇，他们提供的每种饮料之单个容量都是2的方幂，比如王老吉，都是23=8升的，可乐都是 25=32升的。当然STC的存货也是有限的，这会是每种饮料购买量的上限。
	统计数据中用饮料名字、容量、数量、满意度描述每一种饮料。
    那么，小飞如何完成这个任务，求出保证最大满意度的购买量呢？
*/

struct Drink
{
	char* name;
	int volume;
	int amount;
	int satification;
	int max_amount;
};

std::vector<Drink> InitiazeDrinks()
{
	Drink lvcha;
	lvcha.name = "lvcha";
	lvcha.volume = 1;
	lvcha.satification = 400;
	lvcha.max_amount = 2;

	Drink wanglaoji;
	wanglaoji.name = "wanglaoji";
	wanglaoji.volume = 3;
	wanglaoji.satification = 30;
	wanglaoji.max_amount = 2;

	Drink coca;
	coca.name = "kele";
	coca.volume = 1;
	coca.satification = 24;
	coca.max_amount = 1;

	Drink wahaha;
	wahaha.name = "wahaha";
	wahaha.volume = 1;
	wahaha.satification = 20;
	wahaha.max_amount = 2;

	Drink xuebi;
	xuebi.name = "xuebi";
	xuebi.volume = 2;
	xuebi.satification = 48;
	xuebi.max_amount = 1;

	Drink yefeng;
	yefeng.name = "yefeng";
	yefeng.volume = 1;
	yefeng.satification = 16;
	yefeng.max_amount = 2;

	Drink lulu;
	lulu.name = "lulu";
	lulu.volume = 2;
	lulu.satification = 24;
	lulu.max_amount = 1;

	Drink cofe;
	cofe.name = "cofe";
	cofe.volume = 2;
	cofe.satification = 32;
	cofe.max_amount = 2;

	std::vector<Drink> drinks;
	drinks.push_back(lvcha);
	drinks.push_back(coca);
	drinks.push_back(cofe);
	drinks.push_back(wahaha);
	drinks.push_back(wanglaoji);
	drinks.push_back(xuebi);
	drinks.push_back(yefeng);
	drinks.push_back(lulu);

	return drinks;
}

void GetMaxSatification(std::vector<Drink> drinks)
{
	const int VolumeLimit = 10;

	/*****
	// For better understanding, use separate arrays to store each property of the items

	int* V = new int[drinks.size()];  //Volume array
	int* S = new int[drinks.size()];  //Satification array
	int* N = new int[drinks.size()];  //Amount array

	for (int i = 0; i < drinks.size(); i++)
	{
		V[i] = drinks[i].volume;
		S[i] = drinks[i].satification;
		N[i] = drinks[i].max_amount;
	}
	*/

	// Give both drinks and volumes an additional space for boundaries
	int (*MS)[VolumeLimit + 1] = new int[drinks.size() + 1][VolumeLimit + 1]; 
	int (*path)[VolumeLimit + 1] = new int[drinks.size() + 1][VolumeLimit + 1];
	memset(MS, 0, (drinks.size() + 1) * (VolumeLimit + 1));
	memset(path, 0, (drinks.size() + 1) * (VolumeLimit + 1));

	// Because the max sitification depends on two variables:
	// 1. The Nth item
	// 2. The volumn
	// So the question is to get every Nth max satification depending on how many volumes we still have, N is increasing, V is decreasing
	// The transforming formula is 
	// MS[i][j] = max { MS[i-1][j] /*if i was not selected*/,    MS[i-1][j - k*V[i]] + k*S[i]}
	// It is MS[i][j] = max {MS[i-1][j - k*V[i]] + k*S[i]} if k is [0, N[i]]

	for (int i = 0; i <= drinks.size(); i++)
	{
		for (int j = VolumeLimit; j >= 0; j--)
		{
			if (i == 0 || j == 0) 
			{
				MS[i][j] = 0;
				break;
			}

			int max = 0;
			int recordK = 0;
			int currentDrink = i - 1;

			for (int k = 0; k <= drinks[currentDrink].max_amount; k++)
			{
				int tmp = 0;
				
				if (j < k * drinks[currentDrink].volume) break;
				else 
				{
					tmp = MS[i - 1][j - k * drinks[currentDrink].volume] + (k * drinks[currentDrink].satification);
					if (tmp > max) 
					{
						max = tmp;
						recordK = k;
					}
				}
			}

			MS[i][j] = max;
			path[i][j] = recordK;
		}
	}

	// Print max satification
	std::cout << "Max Satification: " << MS[drinks.size()][VolumeLimit] << std::endl;

	// Print MS
	for (int i = 0; i <= drinks.size(); i++)
	{
		for (int j=0; j <= VolumeLimit; j++)
		{
			std::cout << MS[i][j] << "  ";
		}
		std::cout << std::endl;
	}

	// Print the path
	int j = VolumeLimit;
	for(int i = drinks.size(); i >= 0; i--)
	{
		int currentDrink = i - 1;
		if (j >= 0 && currentDrink >= 0)
		{
			std::cout << drinks[currentDrink].name << ": " << path[i][j] << std::endl;
			j = j - path[i][j] * drinks[currentDrink].volume;
		}
	}

	// Dont forget to delete the space in heap
	delete []MS;
	delete []path;
}

int main()
{
	std::vector<Drink> drinks = InitiazeDrinks();
	GetMaxSatification(drinks);

	system("pause");
	return 0;
}