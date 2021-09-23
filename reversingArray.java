package DataStructures;
import java.util.*;
class MyArray
{
    void rotate(int myarray[], int d)
    {
        int size = myarray.length;
        this.reverse(myarray, 0, d-1);
        this.reverse(myarray, d, size-1);
        this.reverse(myarray, 0, size-1);
    }
    void reverse(int array[], int start, int end)
    {
        int temp;
        while(start < end)
        {
            temp = array[start];
            array[start] = array[end];
            array[end] = temp;
            start++;
            end--;
        }
    }
    void printArray(int myarray[])
    {
        int size = myarray.length;
        for(int i=0; i<size; i++)
        {
            System.out.print(myarray[i]+" ");
        }
    }
}
public class reversingArray 
{
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        System.out.println("Enter your array size: ");
        int size = input.nextInt();
        int arr[] = new int[size];
        for(int i=0; i<size; i++){
            arr[i] = input.nextInt();
        }
        MyArray m = new MyArray();
        int rotateCount = input.nextInt();
        m.rotate(arr, rotateCount);
        m.printArray(arr);
        input.close();
    }
}
