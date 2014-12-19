#ifndef COORD_H
#define COORD_H


class coord
{
	public:
		coord();
		coord(int newx, int newy);
		~coord();
		int x;
		int y;
		bool operator < (const coord& c) const;
		bool operator == (const coord& c) const;
};

#endif // COORD_H
