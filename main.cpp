//#include "Player_1.h"
#include <QtWidgets/QApplication>
#include"LevelChoose.h"
#include"QGraphicsView"
#include"Top.h"
#include"Start.h"
#include"userfile.h"
Top * top;//top����ȫ���࣬�������һ��֮�ϵ�һ����
Userfile * userfile;//Ϊ���㣬userfile��Ҳ��Ϊȫ����
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Start* start = new Start;//����һ��Start��
	start->show();
	return a.exec();
}