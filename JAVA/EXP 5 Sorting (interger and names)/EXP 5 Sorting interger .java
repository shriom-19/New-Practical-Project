package Experiment_5A;

import java.util.Arrays;
import java.util.Collections;
import java.util.ArrayList;

public class SortIntegers {
    public static void main(String[] args) {
        int[] intArray = {5, 2, 8, 1, 9};
        System.out.println("Original int array: " + Arrays.toString(intArray));
        Arrays.sort(intArray);
        System.out.println("Sorted int array (ascending): " + Arrays.toString(intArray));

        ArrayList<Integer> integerList = new ArrayList<>();
        integerList.add(7);
        integerList.add(3);
        integerList.add(10);
        integerList.add(4);
        System.out.println("\nOriginal Integer List: " + integerList);
        Collections.sort(integerList);
        System.out.println("Sorted Integer List (ascending): " + integerList);
    }
}

