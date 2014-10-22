#include <stdio.h>

const char *my_array[] = {
	"string1",
	"str2",
	"foobar"
};

int main(int argc, const char *argv[])
{
	/* Directly passing my_array[1] works but shows a warning */
	printf("%s\n", my_array[1]);
	return 0;
}
