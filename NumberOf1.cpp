int  NumberOf1(int n) {
	int cnt = 8 * sizeof(int);
	int tmp = 0;
	while (cnt != 0)
	{
		if (n & 1)
			tmp++;
		n = n >> 1;
		cnt--;
	}
	return tmp;
}
