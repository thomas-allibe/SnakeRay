#ifndef SNAKERAY_SNAKE_H
#define SNAKERAY_SNAKE_H

#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <raylib.h>

typedef struct Snake{
    Vector2 direction;
    Rectangle head;
    Rectangle *body; // Array for each segment, new segment (closest to head) are appended at the end
    size_t body_size;
    size_t max_size;
    Color head_color;
    Color body_color;
}Snake_st;

Snake_st* Snake_ctor(Rectangle size_n_pos, Color h_color, Color b_color);
void Snake_dtor(Snake_st *me);
void Snake_update(Snake_st *me, Vector2 direction, bool grow);
void Snake_draw(Snake_st *me);

bool Snake_is_on_snake(Snake_st *me, Vector2 fruit);
Vector2 Snake_get_head_pos(Snake_st *me);
bool Snake_bite_itself(Snake_st *me);
bool Snake_is_oob(Snake_st *me, Rectangle bounds);

#endif //SNAKERAY_SNAKE_H
