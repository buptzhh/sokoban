#include "Boxes.h"
#include"Top.h"
#include"Userfile.h"
#include"qsound.h"
extern Userfile * userfile;
extern Top * top;
int Boxes::count = 0;//count�Ǿ�̬����
int Boxes::boxNum = 0;
Boxes::Boxes()
{
	setRect(0, 0, boxSize, boxSize);//�������Ӵ�С��ͼƬ
	QBrush brush_box(QImage("Resources/box.png"));
	setBrush(brush_box);
}

void Boxes::isArrival()
{
	flag2 = flag1;//flag2���ڴ��֮ǰһ����flag,flag1������ʾ������һ����flag
	flag1 = 0;
	QList<QGraphicsItem *> colliding_items = collidingItems(Qt::ContainsItemBoundingRect);            //���Ƿ��غ��ж��Ƿ񵽴�

	for (int i = 0, n = colliding_items.size(); i < n; ++i)
	{
		if (typeid(*(colliding_items[i])) == typeid(Spot))//���������յ��غ�ʱ
		{
			//�����Ի���ѯ���Ƿ������һ��
			QBrush brush_Box(QImage("Resources/boxF.png"));
			this->setBrush(brush_Box);
			colliding_items[i]->stackBefore(this);
			flag1 = 1;//���յ㣬falg��Ϊ1
		}
	}
	if (flag2 == 1 && flag1 == 0 ) {//������1��Ϊ0ʱ��count--  
		QBrush brush_Box(QImage("Resources/box.png"));
		this->setBrush(brush_Box);
		count--;
	}
	else if (flag2 == 0 && flag1 == 1)//������0��Ϊ1ʱ��count++
		count++;
	if (count == boxNum)//��boxNum��Ϊ���ӵ����ԣ���̬�ģ��ú��ڵ�ͼ��ʼ��ʱ��������
	{
		QSound::play("Resources/victory.wav");//����ʤ����Ч
		if (top->view1 != nullptr)//�÷ǿ�ָ�����жϵ�ǰ��
			userfile->saveScore(1, top->map1->step->getStep());//����Ϸ���ݴ�����,����Ϸ��һ����Ҫ��������
		if (top->view2 != nullptr)
			userfile->saveScore(2, top->map2->step->getStep());//ǰ�����level���ԣ����Դ�����
		if (top->view3 != nullptr)
			userfile->saveScore(3, top->map3->step->getStep());
		if (top->view4 != nullptr)
			userfile->saveScore(4, top->map4->step->getStep());
	}
}

bool Boxes::getFlag()
{
	return flag1;
}

void Boxes::reStart() {
	flag1 = 0;
	flag2 = 0;
	count = 0;
}

Boxes::~Boxes()
{
}