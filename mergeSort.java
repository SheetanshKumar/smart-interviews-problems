
public class mergeSort {

	static void merge(int arr[], int low, int mid, int high) {
		int temp[] = new int[high - low + 1];
		int pt1 = low, pt2 = mid + 1, idx = 0;
		while (pt1 <= mid && pt2 <= high) {
			if (arr[pt1] <= arr[pt2])
				temp[idx++] = arr[pt1++];
			else
				temp[idx++] = arr[pt2++];
		}
		while (pt1 <= mid)
			temp[idx++] = arr[pt1++];

		while (pt2 <= high)
			temp[idx++] = arr[pt2++];

		for (idx = low; idx <= high; idx++)
			arr[idx] = temp[idx - low];
	}

	static void mergeSort1(int arr[], int low, int high) {
		if (low < high) {
			int mid = (low + high) / 2;
			mergeSort1(arr, low, mid);
			mergeSort1(arr, mid + 1, high);
			merge(arr, low, mid, high);
		}

	}

	public static void main(String[] args) {
		int arr[] = {5,4,3,2,1 };
		int n = arr.length;
		for (int i = 0; i < n; i++)
			System.out.print(arr[i] + " ");
		System.out.println();
		mergeSort1(arr, 0, n-1);
		for (int i = 0; i < n; i++)
			System.out.print(arr[i] + " ");
	}
}
