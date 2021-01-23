#include <cstdio>

int main() {

	FILE *fin = fopen("input.txt", "r");
	if (!fin) {
		fprintf(stderr, "Can't open input file\n");
		return 1;
	}

	char order;
	int value;
	int i = 0, j = 0, angle = 0;

	while (fscanf(fin, " %c%d", &order, &value) == 2) {
		switch (order)
		{
		case 'L':
			angle = (angle + value)%360;
			break;
		case 'R':
			angle = (angle + 360 - value) % 360;
			break;
		case 'N':
			i += value;
			break;
		case 'E':
			j += value;
			break;
		case 'S':
			i -= value;
			break;
		case 'W':
			j -= value;
			break;
		case 'F':
			switch (angle)
			{
			case 0:
				j += value;
				break;
			case 90:
				i += value;
				break;
			case 180:
				j -= value;
				break;
			case 270:
				i -= value;
				break;
			default: puts("AHHHHHHHHHHH");
				break;
			}
			break;
		default: puts("AHHHHHHHHHHH");
			break;
		}
	}

	fclose(fin);

	int d = 0;
	d += (i < 0 ? -i : i);
	d += (j < 0 ? -j : j);

	printf("%d\n", d);

	return 0;
}