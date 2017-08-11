int RandomInRange(int start,int end)
{
	srand(time(0));
	return rand() % (end - start + 1) + start;
}
int Partition(int data[], int length, int start, int end)
{
	if (data == NULL || length <= 0 || start < 0 || end >= length)
		throw new std::exception("Invalid Paramiters");

	int index = RandomInRange(start,end);
	std::swap(data[index], data[end]);

	int small = start - 1;
	for (index = start; index < end; ++index)
	{
		if (data[index] < data[end])
		{
			++small;
			if (small != index)
				std::swap(data[index], data[small]);
		}
	}
	++small;
	std::swap(data[small], data[end]);
	return small;
}

void QuickSort(int data[], int length, int start, int end)
{
	if (start == end)
		return;
	int index = Partition(data, length, start, end);
	if (index > start)
		QuickSort(data, length, start, index - 1);
	if (index < end)
		QuickSort(data, length, index + 1, end);
}
