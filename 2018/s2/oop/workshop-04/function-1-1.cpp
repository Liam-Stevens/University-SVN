int size_of_variable_star_t()
{
	int a, *p;
	p = &a;
	int *t = new int;

	int size = sizeof(t);
	return size;
}