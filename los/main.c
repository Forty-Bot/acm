#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

/*
                   p3
                     +
                    / \
                   /   \
                  /     \
              p4 /       \ p5
  +-------------+---------+-------------+
  |            /...........\            |
  |           /.............\           |
  |          /...area_dark...\          |
  |         /.................\         |
  |      p1+-------------------+p2      |
h1|       /|                   |\       |
  |      / |h2                 | \      |
  |  x  /  |        w2         |  \     |
  +----/-->--------------------+   \    |
  |   /    ^                        \   |
  |  /     |                         \  |
  | /      |y                         \ |
  |/       |                           \|
  +--------+----------------------------+
                    w1
 */

int main(int argc, char **argv) {
	float area_dark, area_whole, pct;
	float s1, s2, p_y, p2_y, p3_y, p4_x, p5_x;
	float w1, h1, w2, h2, x, y;
	while(scanf("%f%f%f%f%f%f", &w1, &h1, &w2, &h2, &x, &y) != EOF) {
		if(w1 == 0) {
			break;
		}
		// Height of the top line segment (p1 or p2)
		p_y = h2 + y;
		// Slope from the origin to p1
		s1 = p_y/x;
		// Slope from the bottom right corner to p2
		s2 = -p_y/(w1 - (x + w2));
		p3_y = (s1 * s2 * w1)/(s2 - s1);
		if(p3_y <= h1) {
			// It's a triangle
			// A = (1/2)hw
			area_dark = 0.5f * (p3_y - p_y) * (w2);
		} else {
			// It's a trapezoid
			p4_x = h1 / s1;
			p5_x = (h1 / s2) + w1;
			// A = (1/2)h(w1 - w2)
			area_dark = 0.5f * (h1 - p_y) * (p5_x - p4_x);
		}
		area_whole = (w1 * h1) - (w2 * h2);
		pct = 100 * (area_dark / area_whole);
		printf("%.1f\n", pct);
	}
}
