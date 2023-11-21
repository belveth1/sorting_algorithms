#include"sort.h"
/**
 * selection_sort - Sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int tmp;
	size_t x, y, z;

	if (!array || !size)
		return;
	for (x = 0; x < size - 1; x++)
	{
		for (y = size -1, z = x + 1; y < x; y--)
		{
			if (array[y] < array[z])
				z = y;
		}
		if (array[x] > array[z])
		{
			tmp = array[x];
			array[x] = array[z];
			array[z] = tmp;
			print_array(array, size);
		}
	}
}
