#include "heads.h"

using namespace std;

#define the_x 700
#define the_y 900
#define plane_move_speed 20
#define bullut_move_speed 20

struct The_plane {
	int ax, ay,bx,by,cx,cy,dx,dy;
	IMAGE plane_graph;
	int x, y;
};

struct The_bullut {
	int condition, x, y;
	int first_x, first_y;
};

struct The_boss {
	int ax, ay, bx, by, cx, cy, dx, dy,times;
	IMAGE boss_graph;
	int x, y;
};


void init_game();		//全局初始化
void control();
void print_plane();
void print_bullut();
void print_boss();
void print_graph();
void print_life();
void print_boss_life();

int x = 0;
The_plane plane;
The_boss boss;
The_bullut B[10], A;

int main()
{

	init_game();
	while (1)
	{
		control();
		print_graph();
		cout << "plane.x=" << plane.x << " plane.y=" << plane.y << "bullut.x=" << A.first_x << "  bullut.y=" << A.y << endl;
	}

	_getch();
	closegraph();
	return 0;
}

void init_game()
{
	initgraph(the_x, the_y, EW_SHOWCONSOLE);
	setbkcolor(RGB(52, 70, 79));
	cleardevice();
	plane.x = the_x / 2 - 25;
	plane.y = the_y - 100;
	plane.ax = the_x / 2 +200;
	plane.ay = the_y - 100;
	plane.bx = plane.ax + 100;
	plane.by = plane.ay;
	plane.cx = plane.bx;
	plane.cy = plane.by + 25;
	plane.dx = plane.ax;
	plane.dy = plane.cy;
	outtextxy(plane.ax, plane.ay + 30, L"飞机生命值");
	boss.ax = the_x / 2 + 200;
	boss.ay = the_y - 800;
	boss.bx = boss.ax + 100;
	boss.by = boss.ay;
	boss.cx = boss.bx;
	boss.cy = boss.by + 25;
	boss.dx = boss.ax;
	boss.dy = boss.cy;
	outtextxy(boss.ax, boss.ay + 30, L"敌人生命值");
	A.first_x = plane.x;
	A.first_y = plane.y;
	A.condition = 0;
	boss.x = 0;
	boss.y = 0;
	boss.times = 5;
	loadimage(&plane.plane_graph, L"X:\\图片\\航模 穿越机\\mmexport1663902485839.jpg", 50, 50);		//50 50为图片大小  飞机
	loadimage(&boss.boss_graph, L"X:\\图片\\其他\\杂\\12c68546cc3038f36d582595a944c98f.jpg", 100, 100);//boss 图片
	putimage(plane.x, plane.y, &plane.plane_graph);			//放飞机
	putimage(boss.x, boss.y, &boss.boss_graph);				//放boss
}

void control()
{
	if (_kbhit()) {
		switch (_getch()) {
		case 'W':
		case 'w':
		case 72:
			if (plane.y <= 0) {

			}
			else {
				plane.y -= plane_move_speed;
			}
			A.first_x = plane.x;
			A.first_y = plane.y;
			break;
		case 'S':
		case 's':
		case 80:
			if (plane.y + 60 >= the_y) {

			}
			else {
				plane.y += plane_move_speed;
			}
			A.first_x = plane.x;
			A.first_y = plane.y;
			break;
		case 'A':
		case 'a':
		case 75:
			if (plane.x - 5 <= 0) {

			}
			else {
				plane.x -= plane_move_speed;
			}
			A.first_x = plane.x;
			A.first_y = plane.y;
			break;
		case 'D':
		case 'd':
		case 77:
			if (plane.x + 55 >= the_x) {

			}
			else {
				plane.x += plane_move_speed;
			}
			A.first_x = plane.x;
			A.first_y = plane.y;
			break;
		case ' ':
			while (1) {
				if (_getch() == ' ')
					return;
			}
			break;
		}
	}

}

void print_plane()
{
	putimage(plane.x, plane.y, &plane.plane_graph);
	if (plane.x > boss.x && plane.x<boss.x + 100 && plane.y>boss.y && plane.y < boss.y + 100) {
		plane.cx=plane.bx -= 5;
	}
	if (plane.ax >= plane.bx) {
		outtextxy(the_x/2, the_y/2, L"游戏结束！！");
		plane.cx = plane.bx = plane.ax + 100;
	}
}

void print_bullut()
{
	if (A.condition == 0) {
		solidcircle(A.first_x+25, A.first_y, 5);
		A.x = A.first_x;
		A.y = A.first_y;
		A.condition = 1;
	}
	else {
		Sleep(1);
		A.y -= bullut_move_speed;
		if (A.x > boss.x && A.x < boss.x + 100 && A.y <= boss.y + 100&&A.y>=boss.y&&boss.times>0) {			//子弹碰撞到物体
			A.x = A.first_x;
			A.y = A.first_y;
			A.condition = 1;
			
			boss.times--;
			boss.bx = boss.cx -= 20;
			if (boss.ax >= boss.bx) {
				boss.x += 250;
				boss.y = -150;
				boss.times = 5;
				boss.cx = boss.bx = boss.ax + 100;
			}

				
			if (boss.x >= the_x)
				boss.x = 0;
			
		}
		solidcircle(A.x+25, A.y, 5);
		if (A.y <= 0) {
			A.condition = 0;
			A.first_x = plane.x;
			A.first_y = plane.y;
		}
	}
}

void print_boss()
{
	boss.y += 1;
	putimage(boss.x, boss.y, &boss.boss_graph);				//放boss
	if (boss.y >= the_y) {
		boss.y = -150;
		boss.y += 1;
		putimage(boss.x, boss.y, &boss.boss_graph);				//放boss
	}
}


void print_graph()
{
	//BeginBatchDraw();
	cleardevice();
	outtextxy(boss.ax, boss.ay + 30, L"敌人生命值");
	outtextxy(plane.ax, plane.ay + 30, L"飞机生命值");
	print_life();
	print_boss_life();
	print_plane();
	print_bullut();
	print_boss();

	//EndBatchDraw();
}

void print_life()
{
	line(plane.ax, plane.ay, plane.bx, plane.by);
	line(plane.bx, plane.by, plane.cx, plane.cy);
	line(plane.cx, plane.cy, plane.dx, plane.dy);
	line(plane.dx, plane.dy, plane.ax, plane.ay);
}

void print_boss_life()
{
	line(boss.ax, boss.ay, boss.bx, boss.by);
	line(boss.bx, boss.by, boss.cx, boss.cy);
	line(boss.cx, boss.cy, boss.dx, boss.dy);
	line(boss.dx, boss.dy, boss.ax, boss.ay);
}