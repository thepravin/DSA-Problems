void InsertionSort(int arr[], int size)
{
    for (int currentIndex = 1; currentIndex < size; currentIndex++)
	{
        int currentValue = arr[currentIndex];
        int sortedIndex = currentIndex - 1;
        while (sortedIndex >= 0 && arr[sortedIndex] > currentValue) 
		{
            arr[sortedIndex + 1] = arr[sortedIndex];
            sortedIndex--;
        }
        arr[sortedIndex + 1] = currentValue;
    }
}
