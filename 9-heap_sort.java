/*Implement the Heap sort algorithm implemented in Java demonstrating heap data structure 
    with modularity of programming language*/
import java.util.*;

class Main {
    static void heapify(int arr[], int n, int ind) {
        int largest = ind;
        int n1 = 2 * ind + 1;
        int n2 = 2 * ind + 2;

        if (n1 < n && arr[largest] < arr[n1]) {
            largest = n1;
        }
        if (n2 < n && arr[largest] < arr[n2]) {
            largest = n2;
        }
        if (ind != largest) {
            int temp = arr[ind];
            arr[ind] = arr[largest];
            arr[largest] = temp;

            heapify(arr, n, largest);
        }
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the size of array: ");
        int n = sc.nextInt();

        int[] arr = new int[n];
        System.out.println("Enter elements of array:");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        sc.close();

        // Build max heap
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }

        int ct = 1;
        for (int i = n - 1; i > 0; i--) {
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;

            heapify(arr, i, 0);

            System.out.print("Pass " + ct++ + ":- ");
            for (int j = 0; j < n; j++) {
                System.out.print(arr[j] + " ");
            }
            System.out.println();
        }

        System.out.print("Final Sorted Array: ");
        for (int j = 0; j < n; j++) {
            System.out.print(arr[j] + " ");
        } 
        System.out.println();
    }
}
