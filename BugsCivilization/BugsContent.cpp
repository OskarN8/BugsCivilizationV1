#include "BugsContent.h"



BugsContent::BugsContent(int x, int y)
{
	if (!txt.loadFromFile("images/bug.png"))
	{
		cout << "cos nie tak";
	}
	pos = Vector2f(x,y);
	hunger = 100;
	sprite.setTexture(txt);
	sprite.setTextureRect(IntRect(0, 0, 50, 50));
	sprite.setPosition(pos);

}

BugsContent::~BugsContent()
{

	cout << "Robal usuniety" << endl;
}


//bool BugsContent::hungerBehaviour(MapGen &gen)
//{
//
//	hunger -= 1;
//	cout << hunger << endl;
//	if (hunger < 60)
//	{
//		return true;
//	}
//
//	if (hunger < 75)
//	{
//		int rowX = (pos.x+25) / 100;
//		int rowY = (pos.y+25) / 100;
//
//		(pos.x+25 > rowX * 100 + 50) ? rowX = rowX * 100 + 50 : rowX = rowX * 100;
//		(pos.y+25 > rowY * 100 + 50) ? rowY = rowY * 100 + 50 : rowY = rowY * 100;
//		if (gen.MapBlocks2D[(rowX / 50)][(rowY / 50)]->isFull == true)
//		{
//
//			gen.MapBlocks2D[(rowY / 50)][(rowX / 50)]->isFull = false;
//			gen.MapBlocks2D[(rowY / 50)][(rowX / 50)]->setSprite();
//			new thread(&MapBlock::renewTimer,gen.MapBlocks2D[(rowY / 50)][(rowX / 50)]);
//			hunger += 10;
//		}
//
//
//	}
//	return false;
//
//
//
//}

//void BugsContent::movingPath(RenderWindow& win)
//{
//	if (needNewEndPosition == true)
//	{
//		default_random_engine gen(time(NULL) + rand());
//		uniform_int_distribution<int> dirX(50, 950);
//		uniform_int_distribution<int> dirY(50, 950);
//
//		needNewEndPosition = false;
//
//		endPosition = Vector2f(int(dirX(gen)), int(dirY(gen)));
//	}
//	else if (pos != endPosition)
//	{
//
//			(pos.x < endPosition.x) ? pos.x += 1 : pos.x -= 1;
//
//			if (pos != endPosition)
//			{
//				(pos.y < endPosition.y) ? pos.y += 1 : pos.y -= 1;
//
//			}
//			sprite.setPosition(pos);
//			win.draw(sprite);
//		
//
//		
//
//	}
//	else if (pos == endPosition)
//	{
//		needNewEndPosition = true;
//	}
//}

