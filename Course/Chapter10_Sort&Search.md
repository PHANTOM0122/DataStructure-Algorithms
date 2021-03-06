Sort & Search
====================

# simple sort
1) straight selection sort
2) Bubble sort
3) Insertion sort

# Complex sort
1) Quick sort
2) Merge sort
3) Heap sort


# 1) Selection Sort
- **Array에서 가장 min element를 찾은 후에(O(N)), array의 가장 앞으로 swap한다. 이 과정을 numElement(O(N))만큼 반복한다**
- **앞에서부터 차근차근 list정렬**
- Time complexity : (N-1) + (N-2) + ... + 2 + 1 = O(N*N)
<pre><code>
// 1. Selection sort

// list에서 가장 작은 element의 index를 반환한다
template <class ItemType>
int MinIndex(ItemType list[], int start, int end) {
	
	// Default minIndex
	int indexOfMin = start;

	for (int index = start + 1; index <= end; index++) {
		if (list[index] < list[indexOfMin])
			indexOfMin = index;
	}

	return indexOfMin;
}

template <class ItemType>
void SelectionSort(ItemType list[], int numElements) {

	int endIndex = numElements - 1;
	
	// list [0]번부터 [n-1]까지 순서대로 sort!
	for (int current = 0; current < endIndex; current++) {
		swap(list[current], list[MinIndex(list, cuurent, endIndex)]);
	}
}</code></pre>

# 2) Bubble Sort
- **array의 마지막에서부터 sort하기 시작한다**
- **neighboring elements와 비교를 하며 list의 처음까지 올라간다**
- Time complexity = (N-1) + (N-2) + ... + 1 = O(N*N)
<pre><code>
// 2. Bubble sort

// 밑에서부터 sort 시작
template <class ItemType>
void BubbleUp(ItemType list[], int start, int end) {
	
	for (int index = end; index > start; index--)
		if (list[index] < list[index - 1])
			swap(list[index], list[index - 1]);
}

template <class ItemType>
void BubbleSort(ItemType list[], int numElements) {
	
	int current = 0;
	// Current를 증가시키면서 밑에서부터 current까지 bubbleUp이 된다
	while (current < numElements - 1) {
		BubbleUp(list, current, numElements - 1);
		current++;
	}
}</code></pre>
![image](https://user-images.githubusercontent.com/50229148/120187939-702b7300-c250-11eb-83de-d3e0d2912a55.png)

# 3) Insertion Sort
- **Array를 분할 후, 앞 부분을 배열해놓은 상태에서 new element를 알맞은 순서에 Insert하는 것이다**
- Time complexity = 1 + 2 + 3 + ... + N = O(N*N)
<pre><code>
// 3. Insertion sort

// list의 end index 원소를 정렬시킨다!
template <class ItemType>
void InsertItem(ItemType list[], int start, int end) {
	
	bool finished = false;
	int current = end;
	bool moreToSearch = (current != start);

	while (moreToSearch && !finished) {
		
		if (list[current] < list[current - 1]) {
			swap(list[current], list[current - 1]);
			current--;
			moreToSearch = (current != start);
		}
		else
			finished = false;
	}
}

template <class ItemType>
void InsertionSort(ItemType list[], int numElements)
{
	for (int count = 0; count < numElements; count++) {
		InsertItem(list, 0, count); // Count의 값이 자기의 자리를 찾아라!
	}
}
</code></pre>
![image](https://user-images.githubusercontent.com/50229148/120187961-76215400-c250-11eb-9eaf-85d40497f513.png)

# 4) Heap Sort
- **list의 Maximum element는 항상 Heap의 root에서 발견된다는 점을 이용한다 -> root를 list의 마지막으로 옮긴다 -> Heap 재정렬 -> 다시 root를 list 마지막 이전으로 옮긴다 -> ...
이 과정을 계속 반복!**
- **HEAP : complete binary tree의 Shape이면서, parent >= child인 order를 가지고 있는 tree**
- Time complexity = (N/2)(log N) [ create heap from array ] + (N-1)(log N) [ compares for sorting loop ] = O (N * log N)
<pre><code>
// 4. Heap Sort
template <class ItemType>
void ReheapDown(ItemType list[], int root, int bottom) {

	int maxChild;
	int rightChild = root * 2 + 2;
	int leftChild; = root * 2 + 1;

	// leftchild가 array 벗어나면 no!
	if (leftChild <= bottom) {

		// Find maxchild!
		// one child case
		if (leftChild == bottom)
			maxChild = leftChild;
		// two children case
		else
		{
			if (list[leftChild] >= list[rightChild])
				maxChild = leftChild;
			else
				maxChild = rightChild;
		}

		// Swap maxchild and root
		if (list[root] < list[maxChild]) {
			swap(list[root], list[maxChild]);
			ReheapDown(maxChild, bottom);
		}
	}
}

template <class ItemType>
void HeapSort(ItemType list[], int numElements) {

	int index;

	// Convert array to Heap
	for (int index = numElements / 2 - 1; index >= 0; index--) { // non-leaf node들에 대해서
		// ReheapDown(ItemType list[], int root, int bottom)
		// 가장 아래의 단말이 아닌 노드부터 heap정렬을 시작한다
		ReheapDown(list, index, numElements - 1);
	}

	// Sort the array
	for (int index = numElements - 1; index >= 1; index--) { // index==0인 경우는 1개밖에 없으므로 할 필요가 없다
		// Heap의 root와 list의 unsorted된 마지막 원소와 swap
		swap(list[0], list[index]);
		ReheapDown(values, 0, index - 1); // Heap을 다시 정렬시켜 root가 max하게 만든다!
	}
}
</code></pre>
![image](https://user-images.githubusercontent.com/50229148/120192190-d5359780-c255-11eb-84a5-84864e3adda8.png)

# 5) Quick Sort
- **splitpoint를 기준으로 앞뒤로 array를 divide 한 후, 다시 subarray를 split하여 sort 한다**
- **Left subarray는 splitval보다 작아야 하며, Right subarray는 splitval보다 커야 한다**
<pre><code>
// 5. Quick sort
template <class ItemType>
void Split(ItemType list[], int first, int last) {
	// Pivot을 first element라 가정
	int left = first + 1;
	int right = last;
	if (left < right) {
		while (list[left] < list[0]) { // left는 pivot보다 큰 값을 찾으면 stop!
			left++;
		}
		while (list[right] > list[0]) { // left는 pivot보다 큰 값을 찾으면 stop!
			right--;
		}
	}
	// Swap pivot and right 
	swap(list[0], list[right]);
}

// Pre : first < last
// Post : Sorts array values [first, last] into 오름차순
template <class ItemType>
void QuickSort(ItemType list[], int first, int last) {
	if (first < last) {

		int splitPoint; 
		Split(values, first, last, splitPoint); // Split  function은 splitpoint를 받아온다!
		// Divide & Conquer
		QuickSort(list, first, splitPoint - 1);
		QuickSort(list, splitPoint + 1, last);
	}
}
</code></pre>
![image](https://user-images.githubusercontent.com/50229148/120507427-c4c22000-c401-11eb-8567-007c2520c7f7.png)

# 6) Merge Sort
- **Array를 최대한 절반씩으로 나눈 후에, sort 시키고 다시 merge한다.**
<pre><code>
template <class ItemType>
void MergeSort(ItemType list[], int first1, int last1, int first2, int last2) {
	
	int SIZE = last2 - first1 + 1;
	ItemType temp[SIZE];

	// Merge first and second array!
	int current1 = first1;
	int current2 = first2;

	// Merge된 list의 index
	int current = 0;

	while (current != last2) {
		if (list[current1] <= list[current2]) {
			temp[current] = temp[current1];
			current1++; current++;
		}
		else {
			list[current] = list[crrent2];
			temp[current] = temp[current2];
			current2++; current++;
		}
	}

	// Reassign to original
	for (current = 0; current < size; current++) {
		list[first1 + current] = temp[current];
	}
}

// 무조건 절반으로 최대한 divide한 이후에, sort한 이후 다시 merge!
template <class ItemType>
void MergeSort(ItemType list[], int first, int last) {
	if (first < last) {
		int middle = (first + last) / 2;
		// Divide
		MergeSort(list, first, middle);
		MergeSort(list, middle + 1, last);

		Merge(list, first, middle, middle + 1, last);
	}
}
</code></pre>
![image](https://user-images.githubusercontent.com/50229148/120508182-782b1480-c402-11eb-8468-627e6933b493.png)

# 7) Radix Sort
- **Radix : 진수를 의미. Ex) 2진수, 4진수, 10진수 ....**
- Queue를 사용하여 임시저장후 다시 sort!
- 일의 자리부터 sort하여 숫자의 최대 자리수까지 sort!
<pre><code>
template<class ItemType>
void RadixSort(ItemType values, int numValues, int numPositions, int radix)
	// Post: Elements in values are in order by key.
{
	QueType<int> queues[10]; // 0~9까지 labeling
	// With default constructor, each queue size is 500
	int whichQueue;

	for (int position = 1; position <= numPositions; position++) // Position : 최대 자리수
	{
		for (int counter = 0; counter < numValues; counter++)
		{
			whichQueue = values[counter].SubKey(position);
			queues[whichQueue].Enqueue(values[counter]);
		}
		CollectQueues(values, queues, radix);
	}
}

template<class ItemType>
void CollectQueues(ItemType values[], QueType<ItemType> queues[], int radix)
	// Post: queues are concatanated with queue[0]'s on top and 
	//       queue[9]'s on the bottom and copied into values.
{
	int index = 0;
	ItemType item;

	for (int counter = 0; counter < radix; counter++)
	{
		while (!queues[counter].IsEmpty())
		{
			queues[counter].Dequeue(item);
			values[index] = item;
			index++;
		}

	}
}
</code></pre>

# Search
1) Linear Searching
2) High-Probablity Ordering
3) Key Ordering

# Hashing
- **searching을 O(1)을 목표로 한다**
- **Collision이 발생한다는 Issue!**

## Resolving collsion 1- Rehashing
1) Linear probing : (HashValue + 1) % 100, (HashValue + constant ) % array size
- **기존의 hash key가 꽉 찬 경우, 인접한(바로 아래)의 노드에 저장. Search역시 마찬가지로 원래 key로 간다음 없으면 아래로 내려가고, empty가 될때까지 search 한다**
2) Quadratic probing : (HashValue + I*I ) % array size
3) Random probing : HashValue + random number ) % array size
- **Linear Probing의 경우 delete할 때, empty가 발생하여 인접한 바로 아래의 element들을 다시 위로 보내야 한다 -> O(N)**
![image](https://user-images.githubusercontent.com/50229148/120510926-dd800500-c404-11eb-8ffd-d7931e4fa2ec.png)

## Resolving collsion 2 - Buckets and Chaining
1) Bucket : matrix를 이용하여 해당 key에 collision을 방지!
![image](https://user-images.githubusercontent.com/50229148/120510441-65194400-c404-11eb-8820-c323aa5b96dc.png)
2) Chain : linked list를 이용하여 same hash location을 계속 잇는다
![image](https://user-images.githubusercontent.com/50229148/120510429-60ed2680-c404-11eb-9f28-a915f1cfa7fb.png)
