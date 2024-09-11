#ifndef NEORAQUET_MATH_H
#define NEORAQUET_MATH_H

#include <math.h>
#include "NeoRaquet_Types.h"

float point_dir(float x1, float y1, float x2, float y2) {
    float dx = x2 - x1;
    float dy = y2 - y1;
    return atan2(dy, dx);
}

float lendir_x(float dist, float angle) {
    return dist * cos(angle);
}

float lendir_y(float dist, float angle) {
    return dist * sin(angle);
}

int collision_line(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    float check1 = (x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3);
    float check2 = (y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1);
    float check3 = (x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3);
    float check4 = (y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1);

    float line1 = (check2 != 0) ? (check1 / check2) : -1;
    float line2 = (check4 != 0) ? (check3 / check4) : -1;

    return (line1 >= 0 && line1 <= 1 && line2 >= 0 && line2 <= 1);
}

int collision_line_rect(int x1, int y1, int x2, int y2, Actor* act) {
    int rx = (act->x - act->origin.x) + act->bbox.x1;
    int ry = (act->y - act->origin.y) + act->bbox.y1;
    int rw = act->bbox.x2 - act->bbox.x1;
    int rh = act->bbox.y2 - act->bbox.y1;

    return collision_line(x1, y1, x2, y2, rx, ry, rx, ry + rh) ||
           collision_line(x1, y1, x2, y2, rx + rw, ry, rx + rw, ry + rh) ||
           collision_line(x1, y1, x2, y2, rx, ry, rx + rw, ry) ||
           collision_line(x1, y1, x2, y2, rx, ry + rh, rx + rw, ry + rh);
}

float lerp(float a, float b, float f) {
    return a + f * (b - a);
}

float point_distance(float x1, float y1, float x2, float y2) {
    float dx = x2 - x1;
    float dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}

float vector_magnitude(float x, float y) {
    return sqrt(x * x + y * y);
}

void normalize_vector(float* x, float* y) {
    float magnitude = vector_magnitude(*x, *y);
    if (magnitude != 0) {
        *x /= magnitude;
        *y /= magnitude;
    }
}

float degrees_to_radians(float degrees) {
    return degrees * (M_PI / 180.0);
}

float radians_to_degrees(float radians) {
    return radians * (180.0 / M_PI);
}

int point_in_rect(int px, int py, int rx, int ry, int rw, int rh) {
    return (px >= rx && px <= rx + rw && py >= ry && py <= ry + rh);
}

#endif 