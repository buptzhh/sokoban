#include "Block.h"



Block::Block()
{
	setRect(0, 0, blockSize, blockSize);
	QBrush brush_block(QImage("Resources/Block.png"));//�����ϰ�����ʽ
	setBrush(brush_block);
}

Block::~Block()
{

}
