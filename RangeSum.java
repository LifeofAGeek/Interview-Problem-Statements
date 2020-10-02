class RangeSum {
	
	int[] arr;

	RangeSum(int[] arr) {
		this.arr = arr;
		preSum(arr);
	}
	
	private void preSum(int[] arr) {
		
		for(int i = 1; i<arr.length; i++)
			arr[i] += arr[i-1];
	}
	
	public int getSum(int i, int j) {
		
		return arr[j-1] - arr[i-1];
	}

}
