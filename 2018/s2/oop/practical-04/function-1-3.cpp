void cpyia(int old_array[],int new_array[],int length)
{
	int *ptr_old = &old_array[0], *ptr_new = &new_array[0];

	for (int i = 0; i < length; i++)
	{
		*(ptr_new + i) = *(ptr_old + i);
	}
}