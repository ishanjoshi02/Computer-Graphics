//This is a practice assignment
#include <graphics.h>
int main() {
	int gd = DETECT,gm;
	initgraph(&gd,&gm, "BAtman");
	line(50,0,300,0);
	line(50,0,0,150);
	line(300,0,350,150);
	line(0,150,350,150);
	setcolor(CYAN);
	bar(0,150,350,350);
	setcolor(RED);
	rectangle(275,175,325,225);
	setcolor(WHITE);
	circle(50,375,25);
	circle(250,375,25);	
	delay(50000);
	closegraph();
}
