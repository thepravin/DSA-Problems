
void BubbleSort(int arr[], int size) 
{
    for (int pass = 1; pass < size; pass++) 
	{
        for (int currentIndex = 0; currentIndex < size - pass; currentIndex++) 
		{
            if (arr[currentIndex] > arr[currentIndex + 1])
			{
                int temp = arr[currentIndex + 1];
                arr[currentIndex + 1] = arr[currentIndex];
                arr[currentIndex] = temp;
            }
        }
    }
}
