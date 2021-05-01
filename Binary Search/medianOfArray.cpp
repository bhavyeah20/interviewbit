double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {

	int a = A.size();
	int b = B.size();

	if (a > b)
		return Solution::findMedianSortedArrays(B, A);

	int start = 0, end = a;

	while (start <= end) {
		int partitionX = start + (end - start) / 2;
		int partitionY = (a + b + 1) / 2 - partitionX;

		int leftX, rightX, leftY, rightY;

		leftX = (partitionX == 0) ? INT_MIN : A[partitionX - 1];
		rightX = (partitionX == a) ? INT_MAX : A[partitionX];
		leftY = (partitionY == 0) ? INT_MIN : B[partitionY - 1];
		rightY = (partitionY == b) ? INT_MAX : B[partitionY];

		if (leftX <= rightY && leftY <= rightX)
		{
			if ((a + b) % 2)
				return max(leftX, leftY);

			return (double) (max(leftX, leftY) + min(rightX, rightY)) / (double)2;
		}

		else if (leftX > rightY)
			end = partitionX - 1;

		else
			start = partitionX + 1;



	}
}
