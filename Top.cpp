#include "Top.h"
#include "userfile.h"
extern Userfile * userfile;
Top::Top()
{
	ch = new QGraphicsScene();
	c = new LevelChoose(ch,userfile->getLevel());
	//c->setScene(ch);
	c->show();
}


Top::~Top()
{
}
