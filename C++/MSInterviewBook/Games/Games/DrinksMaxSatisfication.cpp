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
	std::string name;
	int volume;
	int amount;
	int satification;
	int max_amount;
};

std::vector<Drink> InitiazeDrinks()
{
	Drink lvcha;
	lvcha.name = "绿茶";
	lvcha.volume = 8;
	lvcha.satification = 20;
	lvcha.max_amount = 10;

	Drink wanglaoji;
	wanglaoji.name = "王老吉";
	wanglaoji.volume = 16;
	wanglaoji.satification = 30;
	wanglaoji.max_amount = 20;

	Drink coca;
	coca.name = "可乐";
	coca.volume = 32;
	coca.satification = 24;
	coca.max_amount = 16;

	Drink wahaha;
	wahaha.name = "哇哈哈";
	wahaha.volume = 8;
	wahaha.satification = 20;
	wahaha.max_amount = 16;

	Drink xuebi;
	xuebi.name = "雪碧";
	xuebi.volume = 32;
	xuebi.satification = 48;
	xuebi.max_amount = 16;

	Drink yefeng;
	yefeng.name = "椰风";
	yefeng.volume = 8;
	yefeng.satification = 16;
	yefeng.max_amount = 32;

	Drink lulu;
	lulu.name = "露露";
	lulu.volume = 16;
	lulu.satification = 24;
	lulu.max_amount = 16;

	Drink cofe;
	cofe.name = "咖啡";
	cofe.volume = 16;
	cofe.satification = 32;
	cofe.max_amount = 48;

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

}

int main()
{
	std::vector<Drink> drinks = InitiazeDrinks();
	GetMaxSatification(drinks);

	system("pause");
	return 0;
}
