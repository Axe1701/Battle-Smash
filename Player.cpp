#include "Player.h"

Player::Player(int healt, float moveSpeed, int interval, bool done, bool draw, bool active, float x, float y, int dir, int prevDir, int index)
{
	this->health = healt;
	this->moveSpeed = moveSpeed;
	this->interval = interval;
	this->done = done;
	this->draw = draw;
	this->active = active;
	this->x = x;
	this->y = y;
	this->dir = dir;
	this->prevDir = prevDir;
	this->index = index;
	

}
void Player::load() {
	for (int i = 0; i <= 20; i++) {
		stringstream str;
		str << "Sprites/" << i + 1 << ".jpg";
		playerwalk[i] = al_load_bitmap(str.str().c_str());
	}
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_start_timer(timer);
}

Player::~Player()
{
}

void Player::doLogic(Keyboard keyboard)
{
	if (keyboard.key[UP])
		y -= moveSpeed;
	else if (keyboard.key[DOWN])
		y += moveSpeed;
	if (keyboard.key[LEFT])
		x -= moveSpeed;
	else if (keyboard.key[RIGHT])
		x += moveSpeed;
}